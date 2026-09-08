/*
 * Self-extracting stub for the BT3-Recomp Linux launcher.
 *
 * Layout of the final executable (assembled by build_and_deploy.sh):
 *     [stub ELF][zstd-compressed ustar payload][footer]
 *   footer = "BT3SELFX" + uint64le(len(stub)) + uint64le(len(payload)) + uint64le(seed)
 *   payload = tar("ps2EntryRunner" + "lib/...")
 *
 * On run: extract the payload to /tmp/bt3-sel-<seed>, then exec the runner with
 * LD_LIBRARY_PATH pointing at the extracted lib/ directory. The seed is used as
 * a deterministic temp-dir suffix so successive runs replace the previous copy.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#include "zstd.h"

#define MAGIC "BT3SELFX"
#define FOOTER_LEN (8 + 3 * 8)

typedef struct
{
    uint64_t stubLen;
    uint64_t payloadLen;
    uint64_t seed;
} Footer;

typedef struct
{
    uint8_t *data;
    size_t   len;
    size_t   cap;
} Buffer;

static void die(const char *msg)
{
    fprintf(stderr, "BT3 sel-extractor: %s\n", msg);
    _exit(1);
}

static void buf_reserve(Buffer *b, size_t need)
{
    if (need <= b->cap)
        return;
    size_t cap = b->cap ? b->cap : (1u << 20);
    while (cap < need)
        cap <<= 1;
    void *p = realloc(b->data, cap);
    if (!p)
        die("out of memory");
    b->data = (uint8_t *)p;
    b->cap = cap;
}

static int rd_u64le(const uint8_t *p, uint64_t *out)
{
    *out = 0;
    for (int i = 7; i >= 0; --i)
        *out = (*out << 8) | p[i];
    return 0;
}

/* Decompress the whole zstd payload into an in-memory buffer. */
static Buffer decompress(const uint8_t *src, size_t srcLen)
{
    Buffer out = {0};
    ZSTD_DStream *ds = ZSTD_createDStream();
    if (!ds)
        die("ZSTD_createDStream failed");
    if (ZSTD_initDStream(ds) == 0)
        die("ZSTD_initDStream failed");

    ZSTD_inBuffer in = {src, srcLen, 0};
    size_t lastRet = 0;
    for (;;)
    {
        buf_reserve(&out, out.len + ZSTD_DStreamOutSize());
        ZSTD_outBuffer ob = {out.data + out.len, ZSTD_DStreamOutSize(), 0};
        size_t ret = ZSTD_decompressStream(ds, &ob, &in);
        if (ZSTD_isError(ret))
            die(ZSTD_getErrorName(ret));
        out.len += ob.pos;
        lastRet = ret;
        if (ret == 0 || in.pos == in.size)
            break;
    }
    if (lastRet != 0 && in.pos == in.size)
        die("truncated zstd stream");
    ZSTD_freeDStream(ds);
    return out;
}

static void extract_tar(const Buffer *tar, const char *dir)
{
    size_t pos = 0;
    char name[256];
    while (pos + 512 <= tar->len)
    {
        const uint8_t *h = tar->data + pos;
        if (h[0] == 0) /* end-of-archive */
            break;

        char sizeBuf[13] = {0};
        size_t nameLen = h[124];
        if (nameLen > 99)
            nameLen = 99;
        memcpy(name, h, nameLen);
        name[nameLen] = 0;
        memcpy(sizeBuf, h + 124, 12);
        unsigned long size = strtoul(sizeBuf, NULL, 8);
        char modeBuf[9] = {0};
        memcpy(modeBuf, h + 100, 8);
        unsigned long mode = strtoul(modeBuf, NULL, 8) & 07777;
        char typeflag = h[156];

        pos += 512;
        size_t dataLen = ((size + 511) / 512) * 512;
        if (pos + dataLen > tar->len)
            die("truncated tar data");

        char path[512];
        snprintf(path, sizeof(path), "%s/%s", dir, name);

        if (typeflag == '5')
        {
            mkdir(path, 0755);
        }
        else if (typeflag == '0' || typeflag == '7' || typeflag == 0)
        {
            char dirBuf[512];
            snprintf(dirBuf, sizeof(dirBuf), "%s", path);
            char *slash = strrchr(dirBuf, '/');
            if (slash && slash != dirBuf)
            {
                *slash = 0;
                mkdir(dirBuf, 0755);
            }
            FILE *f = fopen(path, "wb");
            if (!f)
                die("cannot create extracted file");
            fwrite(tar->data + pos, 1, size, f);
            fclose(f);
            if (mode)
                chmod(path, mode);
            else
                chmod(path, typeflag == '7' ? 0755 : 0644);
        }
        /* skip pax/global headers and unknown -> just advance */
        pos += dataLen;
    }
}

int main(int argc, char **argv)
{
    (void)argc;

    char own[4096];
    ssize_t ownLen = readlink("/proc/self/exe", own, sizeof(own) - 1);
    if (ownLen <= 0)
        die("cannot locate own executable");
    own[ownLen] = 0;

    FILE *f = fopen(own, "rb");
    if (!f)
        die("cannot open own executable");
    fseek(f, 0, SEEK_END);
    long fileLen = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (fileLen <= 0 || fileLen <= (long)FOOTER_LEN)
        die("file too small");

    uint8_t footer[FOOTER_LEN];
    fseek(f, fileLen - FOOTER_LEN, SEEK_SET);
    if (fread(footer, 1, FOOTER_LEN, f) != FOOTER_LEN)
        die("cannot read footer");

    Footer ft;
    if (memcmp(footer, MAGIC, 8) != 0)
        die("not a BT3SELFX self-extracting binary");
    rd_u64le(footer + 8, &ft.stubLen);
    rd_u64le(footer + 16, &ft.payloadLen);
    rd_u64le(footer + 24, &ft.seed);
    if (ft.stubLen + ft.payloadLen + FOOTER_LEN != (uint64_t)fileLen)
        die("size mismatch in footer");

    uint8_t *payload = malloc(ft.payloadLen);
    if (!payload)
        die("out of memory");
    fseek(f, (long)ft.stubLen, SEEK_SET);
    if (fread(payload, 1, ft.payloadLen, f) != ft.payloadLen)
        die("cannot read payload");
    fclose(f);

    Buffer tar = decompress(payload, ft.payloadLen);
    free(payload);

    char dir[256];
    snprintf(dir, sizeof(dir), "/tmp/bt3-sel-%08llx", (unsigned long long)ft.seed);
    /* start clean: remove leftovers from a previous run, then recreate */
    if (rmdir(dir) == 0)
        ; /* empty */
    else
        system("rm -rf '/tmp/bt3-sel-'*");
    snprintf(dir, sizeof(dir), "/tmp/bt3-sel-%08llx", (unsigned long long)ft.seed);
    mkdir(dir, 0755);

    extract_tar(&tar, dir);
    free(tar.data);

    /* The runner resolves savedata/, assets/ and data/ from PS2X_EXEDIR (see
     * getExecutableDirectory) -- those portable files stay NEXT to this
     * launcher, while the payload is extracted to the temp cache below. */
    char launchDir[4096];
    snprintf(launchDir, sizeof(launchDir), "%s", own);
    char *slash = strrchr(launchDir, '/');
    if (slash && slash != launchDir)
        *slash = 0;
    else if (slash == launchDir)
        launchDir[1] = 0;
    setenv("PS2X_EXEDIR", launchDir, 1);

    chdir(dir);
    setenv("LD_LIBRARY_PATH", "lib", 1);

    /* The runner needs the guest boot ELF as argv[1]. */
    char bootElf[4096];
    snprintf(bootElf, sizeof(bootElf), "%s/data/SLUS_216.78", launchDir);
    char *runnerArgv[] = {"./ps2EntryRunner", bootElf, NULL};
    execv("./ps2EntryRunner", runnerArgv);
    perror("execv");
    return 1;
}