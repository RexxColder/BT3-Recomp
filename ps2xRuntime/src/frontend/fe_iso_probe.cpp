#include "frontend/fe_iso9660.h"
#include "frontend/fe_hash.h"

#include <cstdio>
#include <string>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::printf("uso: fe_iso_probe <iso>\n");
        return 2;
    }

    Iso9660 iso;
    if (!iso.open(argv[1]))
    {
        std::printf("FALLO open: %s\n", iso.error().c_str());
        return 1;
    }
    std::printf("abierto: %u entradas\n", (unsigned)iso.files().size());
    for (const Iso9660::File &f : iso.files())
        std::printf("  %-24s dir=%d  %llu bytes  extents=%u\n", f.path.c_str(), f.dir ? 1 : 0,
                    (unsigned long long)f.size(), (unsigned)f.extents.size());

    const Iso9660::File *slus = iso.find("slus_216.78");
    if (!slus)
    {
        std::printf("FALLO: no se encontro SLUS_216.78\n");
        return 1;
    }
    std::printf("encontrado (case-insensitive): %s, %llu bytes\n", slus->path.c_str(),
                (unsigned long long)slus->size());

    fe::Sha256 h;
    std::string content;
    const std::int64_t got = iso.readFile(*slus, [&](const char *d, std::size_t n)
    {
        h.update(d, n);
        content.append(d, n);
    });
    std::printf("leidos: %lld bytes, contenido='%s'\n", (long long)got, content.c_str());
    std::printf("sha256(SLUS): %s\n", h.finalHex().c_str());

    const Iso9660::File *notes = iso.find("SUB/NOTES.TXT");
    if (!notes)
    {
        std::printf("FALLO: no se encontro SUB/NOTES.TXT\n");
        return 1;
    }
    std::string sub;
    iso.readFile(*notes, [&](const char *d, std::size_t n) { sub.append(d, n); });
    std::printf("subdirectorio: '%s'\n", sub.c_str());

    const bool verified = DiscVerify::verifySlusFromIso(argv[1]);
    std::printf("verifySlusFromIso (contra el hash real del juego): %s  [esperado false con un ISO sintetico]\n",
                verified ? "true" : "false");
    std::printf("PROBE OK\n");
    return 0;
}
