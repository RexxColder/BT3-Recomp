#include <stdexcept>
#include "ps2_recompiled_functions.h"

#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_stubs.h"
#include "ps2_syscalls.h"
#include "ps2_stubs.h"
#ifdef _DEBUG
#include "ps2_log.h"
#endif

// Function: libsd_000000b0
// Address: 0xb0 - 0x4774
void libsd_000000b0_0xb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_000000b0_0xb0");
#endif

    switch (ctx->pc) {
        case 0xb0u: goto label_b0;
        case 0xb4u: goto label_b4;
        case 0xb8u: goto label_b8;
        case 0xbcu: goto label_bc;
        case 0xc0u: goto label_c0;
        case 0xc4u: goto label_c4;
        case 0xc8u: goto label_c8;
        case 0xccu: goto label_cc;
        case 0xd0u: goto label_d0;
        case 0xd4u: goto label_d4;
        case 0xd8u: goto label_d8;
        case 0xdcu: goto label_dc;
        case 0xe0u: goto label_e0;
        case 0xe4u: goto label_e4;
        case 0xe8u: goto label_e8;
        case 0xecu: goto label_ec;
        case 0xf0u: goto label_f0;
        case 0xf4u: goto label_f4;
        case 0xf8u: goto label_f8;
        case 0xfcu: goto label_fc;
        case 0x100u: goto label_100;
        case 0x104u: goto label_104;
        case 0x108u: goto label_108;
        case 0x10cu: goto label_10c;
        case 0x110u: goto label_110;
        case 0x114u: goto label_114;
        case 0x118u: goto label_118;
        case 0x11cu: goto label_11c;
        case 0x120u: goto label_120;
        case 0x124u: goto label_124;
        case 0x128u: goto label_128;
        case 0x12cu: goto label_12c;
        case 0x130u: goto label_130;
        case 0x134u: goto label_134;
        case 0x138u: goto label_138;
        case 0x13cu: goto label_13c;
        case 0x140u: goto label_140;
        case 0x144u: goto label_144;
        case 0x148u: goto label_148;
        case 0x14cu: goto label_14c;
        case 0x150u: goto label_150;
        case 0x154u: goto label_154;
        case 0x158u: goto label_158;
        case 0x15cu: goto label_15c;
        case 0x160u: goto label_160;
        case 0x164u: goto label_164;
        case 0x168u: goto label_168;
        case 0x16cu: goto label_16c;
        case 0x170u: goto label_170;
        case 0x174u: goto label_174;
        case 0x178u: goto label_178;
        case 0x17cu: goto label_17c;
        case 0x180u: goto label_180;
        case 0x184u: goto label_184;
        case 0x188u: goto label_188;
        case 0x18cu: goto label_18c;
        case 0x190u: goto label_190;
        case 0x194u: goto label_194;
        case 0x198u: goto label_198;
        case 0x19cu: goto label_19c;
        case 0x1a0u: goto label_1a0;
        case 0x1a4u: goto label_1a4;
        case 0x1a8u: goto label_1a8;
        case 0x1acu: goto label_1ac;
        case 0x1b0u: goto label_1b0;
        case 0x1b4u: goto label_1b4;
        case 0x1b8u: goto label_1b8;
        case 0x1bcu: goto label_1bc;
        case 0x1c0u: goto label_1c0;
        case 0x1c4u: goto label_1c4;
        case 0x1c8u: goto label_1c8;
        case 0x1ccu: goto label_1cc;
        case 0x1d0u: goto label_1d0;
        case 0x1d4u: goto label_1d4;
        case 0x1d8u: goto label_1d8;
        case 0x1dcu: goto label_1dc;
        case 0x1e0u: goto label_1e0;
        case 0x1e4u: goto label_1e4;
        case 0x1e8u: goto label_1e8;
        case 0x1ecu: goto label_1ec;
        case 0x1f0u: goto label_1f0;
        case 0x1f4u: goto label_1f4;
        case 0x1f8u: goto label_1f8;
        case 0x1fcu: goto label_1fc;
        case 0x200u: goto label_200;
        case 0x204u: goto label_204;
        case 0x208u: goto label_208;
        case 0x20cu: goto label_20c;
        case 0x210u: goto label_210;
        case 0x214u: goto label_214;
        case 0x218u: goto label_218;
        case 0x21cu: goto label_21c;
        case 0x220u: goto label_220;
        case 0x224u: goto label_224;
        case 0x228u: goto label_228;
        case 0x22cu: goto label_22c;
        case 0x230u: goto label_230;
        case 0x234u: goto label_234;
        case 0x238u: goto label_238;
        case 0x23cu: goto label_23c;
        case 0x240u: goto label_240;
        case 0x244u: goto label_244;
        case 0x248u: goto label_248;
        case 0x24cu: goto label_24c;
        case 0x250u: goto label_250;
        case 0x254u: goto label_254;
        case 0x258u: goto label_258;
        case 0x25cu: goto label_25c;
        case 0x260u: goto label_260;
        case 0x264u: goto label_264;
        case 0x268u: goto label_268;
        case 0x26cu: goto label_26c;
        case 0x270u: goto label_270;
        case 0x274u: goto label_274;
        case 0x278u: goto label_278;
        case 0x27cu: goto label_27c;
        case 0x280u: goto label_280;
        case 0x284u: goto label_284;
        case 0x288u: goto label_288;
        case 0x28cu: goto label_28c;
        case 0x290u: goto label_290;
        case 0x294u: goto label_294;
        case 0x298u: goto label_298;
        case 0x29cu: goto label_29c;
        case 0x2a0u: goto label_2a0;
        case 0x2a4u: goto label_2a4;
        case 0x2a8u: goto label_2a8;
        case 0x2acu: goto label_2ac;
        case 0x2b0u: goto label_2b0;
        case 0x2b4u: goto label_2b4;
        case 0x2b8u: goto label_2b8;
        case 0x2bcu: goto label_2bc;
        case 0x2c0u: goto label_2c0;
        case 0x2c4u: goto label_2c4;
        case 0x2c8u: goto label_2c8;
        case 0x2ccu: goto label_2cc;
        case 0x2d0u: goto label_2d0;
        case 0x2d4u: goto label_2d4;
        case 0x2d8u: goto label_2d8;
        case 0x2dcu: goto label_2dc;
        case 0x2e0u: goto label_2e0;
        case 0x2e4u: goto label_2e4;
        case 0x2e8u: goto label_2e8;
        case 0x2ecu: goto label_2ec;
        case 0x2f0u: goto label_2f0;
        case 0x2f4u: goto label_2f4;
        case 0x2f8u: goto label_2f8;
        case 0x2fcu: goto label_2fc;
        case 0x300u: goto label_300;
        case 0x304u: goto label_304;
        case 0x308u: goto label_308;
        case 0x30cu: goto label_30c;
        case 0x310u: goto label_310;
        case 0x314u: goto label_314;
        case 0x318u: goto label_318;
        case 0x31cu: goto label_31c;
        case 0x320u: goto label_320;
        case 0x324u: goto label_324;
        case 0x328u: goto label_328;
        case 0x32cu: goto label_32c;
        case 0x330u: goto label_330;
        case 0x334u: goto label_334;
        case 0x338u: goto label_338;
        case 0x33cu: goto label_33c;
        case 0x340u: goto label_340;
        case 0x344u: goto label_344;
        case 0x348u: goto label_348;
        case 0x34cu: goto label_34c;
        case 0x350u: goto label_350;
        case 0x354u: goto label_354;
        case 0x358u: goto label_358;
        case 0x35cu: goto label_35c;
        case 0x360u: goto label_360;
        case 0x364u: goto label_364;
        case 0x368u: goto label_368;
        case 0x36cu: goto label_36c;
        case 0x370u: goto label_370;
        case 0x374u: goto label_374;
        case 0x378u: goto label_378;
        case 0x37cu: goto label_37c;
        case 0x380u: goto label_380;
        case 0x384u: goto label_384;
        case 0x388u: goto label_388;
        case 0x38cu: goto label_38c;
        case 0x390u: goto label_390;
        case 0x394u: goto label_394;
        case 0x398u: goto label_398;
        case 0x39cu: goto label_39c;
        case 0x3a0u: goto label_3a0;
        case 0x3a4u: goto label_3a4;
        case 0x3a8u: goto label_3a8;
        case 0x3acu: goto label_3ac;
        case 0x3b0u: goto label_3b0;
        case 0x3b4u: goto label_3b4;
        case 0x3b8u: goto label_3b8;
        case 0x3bcu: goto label_3bc;
        case 0x3c0u: goto label_3c0;
        case 0x3c4u: goto label_3c4;
        case 0x3c8u: goto label_3c8;
        case 0x3ccu: goto label_3cc;
        case 0x3d0u: goto label_3d0;
        case 0x3d4u: goto label_3d4;
        case 0x3d8u: goto label_3d8;
        case 0x3dcu: goto label_3dc;
        case 0x3e0u: goto label_3e0;
        case 0x3e4u: goto label_3e4;
        case 0x3e8u: goto label_3e8;
        case 0x3ecu: goto label_3ec;
        case 0x3f0u: goto label_3f0;
        case 0x3f4u: goto label_3f4;
        case 0x3f8u: goto label_3f8;
        case 0x3fcu: goto label_3fc;
        case 0x400u: goto label_400;
        case 0x404u: goto label_404;
        case 0x408u: goto label_408;
        case 0x40cu: goto label_40c;
        case 0x410u: goto label_410;
        case 0x414u: goto label_414;
        case 0x418u: goto label_418;
        case 0x41cu: goto label_41c;
        case 0x420u: goto label_420;
        case 0x424u: goto label_424;
        case 0x428u: goto label_428;
        case 0x42cu: goto label_42c;
        case 0x430u: goto label_430;
        case 0x434u: goto label_434;
        case 0x438u: goto label_438;
        case 0x43cu: goto label_43c;
        case 0x440u: goto label_440;
        case 0x444u: goto label_444;
        case 0x448u: goto label_448;
        case 0x44cu: goto label_44c;
        case 0x450u: goto label_450;
        case 0x454u: goto label_454;
        case 0x458u: goto label_458;
        case 0x45cu: goto label_45c;
        case 0x460u: goto label_460;
        case 0x464u: goto label_464;
        case 0x468u: goto label_468;
        case 0x46cu: goto label_46c;
        case 0x470u: goto label_470;
        case 0x474u: goto label_474;
        case 0x478u: goto label_478;
        case 0x47cu: goto label_47c;
        case 0x480u: goto label_480;
        case 0x484u: goto label_484;
        case 0x488u: goto label_488;
        case 0x48cu: goto label_48c;
        case 0x490u: goto label_490;
        case 0x494u: goto label_494;
        case 0x498u: goto label_498;
        case 0x49cu: goto label_49c;
        case 0x4a0u: goto label_4a0;
        case 0x4a4u: goto label_4a4;
        case 0x4a8u: goto label_4a8;
        case 0x4acu: goto label_4ac;
        case 0x4b0u: goto label_4b0;
        case 0x4b4u: goto label_4b4;
        case 0x4b8u: goto label_4b8;
        case 0x4bcu: goto label_4bc;
        case 0x4c0u: goto label_4c0;
        case 0x4c4u: goto label_4c4;
        case 0x4c8u: goto label_4c8;
        case 0x4ccu: goto label_4cc;
        case 0x4d0u: goto label_4d0;
        case 0x4d4u: goto label_4d4;
        case 0x4d8u: goto label_4d8;
        case 0x4dcu: goto label_4dc;
        case 0x4e0u: goto label_4e0;
        case 0x4e4u: goto label_4e4;
        case 0x4e8u: goto label_4e8;
        case 0x4ecu: goto label_4ec;
        case 0x4f0u: goto label_4f0;
        case 0x4f4u: goto label_4f4;
        case 0x4f8u: goto label_4f8;
        case 0x4fcu: goto label_4fc;
        case 0x500u: goto label_500;
        case 0x504u: goto label_504;
        case 0x508u: goto label_508;
        case 0x50cu: goto label_50c;
        case 0x510u: goto label_510;
        case 0x514u: goto label_514;
        case 0x518u: goto label_518;
        case 0x51cu: goto label_51c;
        case 0x520u: goto label_520;
        case 0x524u: goto label_524;
        case 0x528u: goto label_528;
        case 0x52cu: goto label_52c;
        case 0x530u: goto label_530;
        case 0x534u: goto label_534;
        case 0x538u: goto label_538;
        case 0x53cu: goto label_53c;
        case 0x540u: goto label_540;
        case 0x544u: goto label_544;
        case 0x548u: goto label_548;
        case 0x54cu: goto label_54c;
        case 0x550u: goto label_550;
        case 0x554u: goto label_554;
        case 0x558u: goto label_558;
        case 0x55cu: goto label_55c;
        case 0x560u: goto label_560;
        case 0x564u: goto label_564;
        case 0x568u: goto label_568;
        case 0x56cu: goto label_56c;
        case 0x570u: goto label_570;
        case 0x574u: goto label_574;
        case 0x578u: goto label_578;
        case 0x57cu: goto label_57c;
        case 0x580u: goto label_580;
        case 0x584u: goto label_584;
        case 0x588u: goto label_588;
        case 0x58cu: goto label_58c;
        case 0x590u: goto label_590;
        case 0x594u: goto label_594;
        case 0x598u: goto label_598;
        case 0x59cu: goto label_59c;
        case 0x5a0u: goto label_5a0;
        case 0x5a4u: goto label_5a4;
        case 0x5a8u: goto label_5a8;
        case 0x5acu: goto label_5ac;
        case 0x5b0u: goto label_5b0;
        case 0x5b4u: goto label_5b4;
        case 0x5b8u: goto label_5b8;
        case 0x5bcu: goto label_5bc;
        case 0x5c0u: goto label_5c0;
        case 0x5c4u: goto label_5c4;
        case 0x5c8u: goto label_5c8;
        case 0x5ccu: goto label_5cc;
        case 0x5d0u: goto label_5d0;
        case 0x5d4u: goto label_5d4;
        case 0x5d8u: goto label_5d8;
        case 0x5dcu: goto label_5dc;
        case 0x5e0u: goto label_5e0;
        case 0x5e4u: goto label_5e4;
        case 0x5e8u: goto label_5e8;
        case 0x5ecu: goto label_5ec;
        case 0x5f0u: goto label_5f0;
        case 0x5f4u: goto label_5f4;
        case 0x5f8u: goto label_5f8;
        case 0x5fcu: goto label_5fc;
        case 0x600u: goto label_600;
        case 0x604u: goto label_604;
        case 0x608u: goto label_608;
        case 0x60cu: goto label_60c;
        case 0x610u: goto label_610;
        case 0x614u: goto label_614;
        case 0x618u: goto label_618;
        case 0x61cu: goto label_61c;
        case 0x620u: goto label_620;
        case 0x624u: goto label_624;
        case 0x628u: goto label_628;
        case 0x62cu: goto label_62c;
        case 0x630u: goto label_630;
        case 0x634u: goto label_634;
        case 0x638u: goto label_638;
        case 0x63cu: goto label_63c;
        case 0x640u: goto label_640;
        case 0x644u: goto label_644;
        case 0x648u: goto label_648;
        case 0x64cu: goto label_64c;
        case 0x650u: goto label_650;
        case 0x654u: goto label_654;
        case 0x658u: goto label_658;
        case 0x65cu: goto label_65c;
        case 0x660u: goto label_660;
        case 0x664u: goto label_664;
        case 0x668u: goto label_668;
        case 0x66cu: goto label_66c;
        case 0x670u: goto label_670;
        case 0x674u: goto label_674;
        case 0x678u: goto label_678;
        case 0x67cu: goto label_67c;
        case 0x680u: goto label_680;
        case 0x684u: goto label_684;
        case 0x688u: goto label_688;
        case 0x68cu: goto label_68c;
        case 0x690u: goto label_690;
        case 0x694u: goto label_694;
        case 0x698u: goto label_698;
        case 0x69cu: goto label_69c;
        case 0x6a0u: goto label_6a0;
        case 0x6a4u: goto label_6a4;
        case 0x6a8u: goto label_6a8;
        case 0x6acu: goto label_6ac;
        case 0x6b0u: goto label_6b0;
        case 0x6b4u: goto label_6b4;
        case 0x6b8u: goto label_6b8;
        case 0x6bcu: goto label_6bc;
        case 0x6c0u: goto label_6c0;
        case 0x6c4u: goto label_6c4;
        case 0x6c8u: goto label_6c8;
        case 0x6ccu: goto label_6cc;
        case 0x6d0u: goto label_6d0;
        case 0x6d4u: goto label_6d4;
        case 0x6d8u: goto label_6d8;
        case 0x6dcu: goto label_6dc;
        case 0x6e0u: goto label_6e0;
        case 0x6e4u: goto label_6e4;
        case 0x6e8u: goto label_6e8;
        case 0x6ecu: goto label_6ec;
        case 0x6f0u: goto label_6f0;
        case 0x6f4u: goto label_6f4;
        case 0x6f8u: goto label_6f8;
        case 0x6fcu: goto label_6fc;
        case 0x700u: goto label_700;
        case 0x704u: goto label_704;
        case 0x708u: goto label_708;
        case 0x70cu: goto label_70c;
        case 0x710u: goto label_710;
        case 0x714u: goto label_714;
        case 0x718u: goto label_718;
        case 0x71cu: goto label_71c;
        case 0x720u: goto label_720;
        case 0x724u: goto label_724;
        case 0x728u: goto label_728;
        case 0x72cu: goto label_72c;
        case 0x730u: goto label_730;
        case 0x734u: goto label_734;
        case 0x738u: goto label_738;
        case 0x73cu: goto label_73c;
        case 0x740u: goto label_740;
        case 0x744u: goto label_744;
        case 0x748u: goto label_748;
        case 0x74cu: goto label_74c;
        case 0x750u: goto label_750;
        case 0x754u: goto label_754;
        case 0x758u: goto label_758;
        case 0x75cu: goto label_75c;
        case 0x760u: goto label_760;
        case 0x764u: goto label_764;
        case 0x768u: goto label_768;
        case 0x76cu: goto label_76c;
        case 0x770u: goto label_770;
        case 0x774u: goto label_774;
        case 0x778u: goto label_778;
        case 0x77cu: goto label_77c;
        case 0x780u: goto label_780;
        case 0x784u: goto label_784;
        case 0x788u: goto label_788;
        case 0x78cu: goto label_78c;
        case 0x790u: goto label_790;
        case 0x794u: goto label_794;
        case 0x798u: goto label_798;
        case 0x79cu: goto label_79c;
        case 0x7a0u: goto label_7a0;
        case 0x7a4u: goto label_7a4;
        case 0x7a8u: goto label_7a8;
        case 0x7acu: goto label_7ac;
        case 0x7b0u: goto label_7b0;
        case 0x7b4u: goto label_7b4;
        case 0x7b8u: goto label_7b8;
        case 0x7bcu: goto label_7bc;
        case 0x7c0u: goto label_7c0;
        case 0x7c4u: goto label_7c4;
        case 0x7c8u: goto label_7c8;
        case 0x7ccu: goto label_7cc;
        case 0x7d0u: goto label_7d0;
        case 0x7d4u: goto label_7d4;
        case 0x7d8u: goto label_7d8;
        case 0x7dcu: goto label_7dc;
        case 0x7e0u: goto label_7e0;
        case 0x7e4u: goto label_7e4;
        case 0x7e8u: goto label_7e8;
        case 0x7ecu: goto label_7ec;
        case 0x7f0u: goto label_7f0;
        case 0x7f4u: goto label_7f4;
        case 0x7f8u: goto label_7f8;
        case 0x7fcu: goto label_7fc;
        case 0x800u: goto label_800;
        case 0x804u: goto label_804;
        case 0x808u: goto label_808;
        case 0x80cu: goto label_80c;
        case 0x810u: goto label_810;
        case 0x814u: goto label_814;
        case 0x818u: goto label_818;
        case 0x81cu: goto label_81c;
        case 0x820u: goto label_820;
        case 0x824u: goto label_824;
        case 0x828u: goto label_828;
        case 0x82cu: goto label_82c;
        case 0x830u: goto label_830;
        case 0x834u: goto label_834;
        case 0x838u: goto label_838;
        case 0x83cu: goto label_83c;
        case 0x840u: goto label_840;
        case 0x844u: goto label_844;
        case 0x848u: goto label_848;
        case 0x84cu: goto label_84c;
        case 0x850u: goto label_850;
        case 0x854u: goto label_854;
        case 0x858u: goto label_858;
        case 0x85cu: goto label_85c;
        case 0x860u: goto label_860;
        case 0x864u: goto label_864;
        case 0x868u: goto label_868;
        case 0x86cu: goto label_86c;
        case 0x870u: goto label_870;
        case 0x874u: goto label_874;
        case 0x878u: goto label_878;
        case 0x87cu: goto label_87c;
        case 0x880u: goto label_880;
        case 0x884u: goto label_884;
        case 0x888u: goto label_888;
        case 0x88cu: goto label_88c;
        case 0x890u: goto label_890;
        case 0x894u: goto label_894;
        case 0x898u: goto label_898;
        case 0x89cu: goto label_89c;
        case 0x8a0u: goto label_8a0;
        case 0x8a4u: goto label_8a4;
        case 0x8a8u: goto label_8a8;
        case 0x8acu: goto label_8ac;
        case 0x8b0u: goto label_8b0;
        case 0x8b4u: goto label_8b4;
        case 0x8b8u: goto label_8b8;
        case 0x8bcu: goto label_8bc;
        case 0x8c0u: goto label_8c0;
        case 0x8c4u: goto label_8c4;
        case 0x8c8u: goto label_8c8;
        case 0x8ccu: goto label_8cc;
        case 0x8d0u: goto label_8d0;
        case 0x8d4u: goto label_8d4;
        case 0x8d8u: goto label_8d8;
        case 0x8dcu: goto label_8dc;
        case 0x8e0u: goto label_8e0;
        case 0x8e4u: goto label_8e4;
        case 0x8e8u: goto label_8e8;
        case 0x8ecu: goto label_8ec;
        case 0x8f0u: goto label_8f0;
        case 0x8f4u: goto label_8f4;
        case 0x8f8u: goto label_8f8;
        case 0x8fcu: goto label_8fc;
        case 0x900u: goto label_900;
        case 0x904u: goto label_904;
        case 0x908u: goto label_908;
        case 0x90cu: goto label_90c;
        case 0x910u: goto label_910;
        case 0x914u: goto label_914;
        case 0x918u: goto label_918;
        case 0x91cu: goto label_91c;
        case 0x920u: goto label_920;
        case 0x924u: goto label_924;
        case 0x928u: goto label_928;
        case 0x92cu: goto label_92c;
        case 0x930u: goto label_930;
        case 0x934u: goto label_934;
        case 0x938u: goto label_938;
        case 0x93cu: goto label_93c;
        case 0x940u: goto label_940;
        case 0x944u: goto label_944;
        case 0x948u: goto label_948;
        case 0x94cu: goto label_94c;
        case 0x950u: goto label_950;
        case 0x954u: goto label_954;
        case 0x958u: goto label_958;
        case 0x95cu: goto label_95c;
        case 0x960u: goto label_960;
        case 0x964u: goto label_964;
        case 0x968u: goto label_968;
        case 0x96cu: goto label_96c;
        case 0x970u: goto label_970;
        case 0x974u: goto label_974;
        case 0x978u: goto label_978;
        case 0x97cu: goto label_97c;
        case 0x980u: goto label_980;
        case 0x984u: goto label_984;
        case 0x988u: goto label_988;
        case 0x98cu: goto label_98c;
        case 0x990u: goto label_990;
        case 0x994u: goto label_994;
        case 0x998u: goto label_998;
        case 0x99cu: goto label_99c;
        case 0x9a0u: goto label_9a0;
        case 0x9a4u: goto label_9a4;
        case 0x9a8u: goto label_9a8;
        case 0x9acu: goto label_9ac;
        case 0x9b0u: goto label_9b0;
        case 0x9b4u: goto label_9b4;
        case 0x9b8u: goto label_9b8;
        case 0x9bcu: goto label_9bc;
        case 0x9c0u: goto label_9c0;
        case 0x9c4u: goto label_9c4;
        case 0x9c8u: goto label_9c8;
        case 0x9ccu: goto label_9cc;
        case 0x9d0u: goto label_9d0;
        case 0x9d4u: goto label_9d4;
        case 0x9d8u: goto label_9d8;
        case 0x9dcu: goto label_9dc;
        case 0x9e0u: goto label_9e0;
        case 0x9e4u: goto label_9e4;
        case 0x9e8u: goto label_9e8;
        case 0x9ecu: goto label_9ec;
        case 0x9f0u: goto label_9f0;
        case 0x9f4u: goto label_9f4;
        case 0x9f8u: goto label_9f8;
        case 0x9fcu: goto label_9fc;
        case 0xa00u: goto label_a00;
        case 0xa04u: goto label_a04;
        case 0xa08u: goto label_a08;
        case 0xa0cu: goto label_a0c;
        case 0xa10u: goto label_a10;
        case 0xa14u: goto label_a14;
        case 0xa18u: goto label_a18;
        case 0xa1cu: goto label_a1c;
        case 0xa20u: goto label_a20;
        case 0xa24u: goto label_a24;
        case 0xa28u: goto label_a28;
        case 0xa2cu: goto label_a2c;
        case 0xa30u: goto label_a30;
        case 0xa34u: goto label_a34;
        case 0xa38u: goto label_a38;
        case 0xa3cu: goto label_a3c;
        case 0xa40u: goto label_a40;
        case 0xa44u: goto label_a44;
        case 0xa48u: goto label_a48;
        case 0xa4cu: goto label_a4c;
        case 0xa50u: goto label_a50;
        case 0xa54u: goto label_a54;
        case 0xa58u: goto label_a58;
        case 0xa5cu: goto label_a5c;
        case 0xa60u: goto label_a60;
        case 0xa64u: goto label_a64;
        case 0xa68u: goto label_a68;
        case 0xa6cu: goto label_a6c;
        case 0xa70u: goto label_a70;
        case 0xa74u: goto label_a74;
        case 0xa78u: goto label_a78;
        case 0xa7cu: goto label_a7c;
        case 0xa80u: goto label_a80;
        case 0xa84u: goto label_a84;
        case 0xa88u: goto label_a88;
        case 0xa8cu: goto label_a8c;
        case 0xa90u: goto label_a90;
        case 0xa94u: goto label_a94;
        case 0xa98u: goto label_a98;
        case 0xa9cu: goto label_a9c;
        case 0xaa0u: goto label_aa0;
        case 0xaa4u: goto label_aa4;
        case 0xaa8u: goto label_aa8;
        case 0xaacu: goto label_aac;
        case 0xab0u: goto label_ab0;
        case 0xab4u: goto label_ab4;
        case 0xab8u: goto label_ab8;
        case 0xabcu: goto label_abc;
        case 0xac0u: goto label_ac0;
        case 0xac4u: goto label_ac4;
        case 0xac8u: goto label_ac8;
        case 0xaccu: goto label_acc;
        case 0xad0u: goto label_ad0;
        case 0xad4u: goto label_ad4;
        case 0xad8u: goto label_ad8;
        case 0xadcu: goto label_adc;
        case 0xae0u: goto label_ae0;
        case 0xae4u: goto label_ae4;
        case 0xae8u: goto label_ae8;
        case 0xaecu: goto label_aec;
        case 0xaf0u: goto label_af0;
        case 0xaf4u: goto label_af4;
        case 0xaf8u: goto label_af8;
        case 0xafcu: goto label_afc;
        case 0xb00u: goto label_b00;
        case 0xb04u: goto label_b04;
        case 0xb08u: goto label_b08;
        case 0xb0cu: goto label_b0c;
        case 0xb10u: goto label_b10;
        case 0xb14u: goto label_b14;
        case 0xb18u: goto label_b18;
        case 0xb1cu: goto label_b1c;
        case 0xb20u: goto label_b20;
        case 0xb24u: goto label_b24;
        case 0xb28u: goto label_b28;
        case 0xb2cu: goto label_b2c;
        case 0xb30u: goto label_b30;
        case 0xb34u: goto label_b34;
        case 0xb38u: goto label_b38;
        case 0xb3cu: goto label_b3c;
        case 0xb40u: goto label_b40;
        case 0xb44u: goto label_b44;
        case 0xb48u: goto label_b48;
        case 0xb4cu: goto label_b4c;
        case 0xb50u: goto label_b50;
        case 0xb54u: goto label_b54;
        case 0xb58u: goto label_b58;
        case 0xb5cu: goto label_b5c;
        case 0xb60u: goto label_b60;
        case 0xb64u: goto label_b64;
        case 0xb68u: goto label_b68;
        case 0xb6cu: goto label_b6c;
        case 0xb70u: goto label_b70;
        case 0xb74u: goto label_b74;
        case 0xb78u: goto label_b78;
        case 0xb7cu: goto label_b7c;
        case 0xb80u: goto label_b80;
        case 0xb84u: goto label_b84;
        case 0xb88u: goto label_b88;
        case 0xb8cu: goto label_b8c;
        case 0xb90u: goto label_b90;
        case 0xb94u: goto label_b94;
        case 0xb98u: goto label_b98;
        case 0xb9cu: goto label_b9c;
        case 0xba0u: goto label_ba0;
        case 0xba4u: goto label_ba4;
        case 0xba8u: goto label_ba8;
        case 0xbacu: goto label_bac;
        case 0xbb0u: goto label_bb0;
        case 0xbb4u: goto label_bb4;
        case 0xbb8u: goto label_bb8;
        case 0xbbcu: goto label_bbc;
        case 0xbc0u: goto label_bc0;
        case 0xbc4u: goto label_bc4;
        case 0xbc8u: goto label_bc8;
        case 0xbccu: goto label_bcc;
        case 0xbd0u: goto label_bd0;
        case 0xbd4u: goto label_bd4;
        case 0xbd8u: goto label_bd8;
        case 0xbdcu: goto label_bdc;
        case 0xbe0u: goto label_be0;
        case 0xbe4u: goto label_be4;
        case 0xbe8u: goto label_be8;
        case 0xbecu: goto label_bec;
        case 0xbf0u: goto label_bf0;
        case 0xbf4u: goto label_bf4;
        case 0xbf8u: goto label_bf8;
        case 0xbfcu: goto label_bfc;
        case 0xc00u: goto label_c00;
        case 0xc04u: goto label_c04;
        case 0xc08u: goto label_c08;
        case 0xc0cu: goto label_c0c;
        case 0xc10u: goto label_c10;
        case 0xc14u: goto label_c14;
        case 0xc18u: goto label_c18;
        case 0xc1cu: goto label_c1c;
        case 0xc20u: goto label_c20;
        case 0xc24u: goto label_c24;
        case 0xc28u: goto label_c28;
        case 0xc2cu: goto label_c2c;
        case 0xc30u: goto label_c30;
        case 0xc34u: goto label_c34;
        case 0xc38u: goto label_c38;
        case 0xc3cu: goto label_c3c;
        case 0xc40u: goto label_c40;
        case 0xc44u: goto label_c44;
        case 0xc48u: goto label_c48;
        case 0xc4cu: goto label_c4c;
        case 0xc50u: goto label_c50;
        case 0xc54u: goto label_c54;
        case 0xc58u: goto label_c58;
        case 0xc5cu: goto label_c5c;
        case 0xc60u: goto label_c60;
        case 0xc64u: goto label_c64;
        case 0xc68u: goto label_c68;
        case 0xc6cu: goto label_c6c;
        case 0xc70u: goto label_c70;
        case 0xc74u: goto label_c74;
        case 0xc78u: goto label_c78;
        case 0xc7cu: goto label_c7c;
        case 0xc80u: goto label_c80;
        case 0xc84u: goto label_c84;
        case 0xc88u: goto label_c88;
        case 0xc8cu: goto label_c8c;
        case 0xc90u: goto label_c90;
        case 0xc94u: goto label_c94;
        case 0xc98u: goto label_c98;
        case 0xc9cu: goto label_c9c;
        case 0xca0u: goto label_ca0;
        case 0xca4u: goto label_ca4;
        case 0xca8u: goto label_ca8;
        case 0xcacu: goto label_cac;
        case 0xcb0u: goto label_cb0;
        case 0xcb4u: goto label_cb4;
        case 0xcb8u: goto label_cb8;
        case 0xcbcu: goto label_cbc;
        case 0xcc0u: goto label_cc0;
        case 0xcc4u: goto label_cc4;
        case 0xcc8u: goto label_cc8;
        case 0xcccu: goto label_ccc;
        case 0xcd0u: goto label_cd0;
        case 0xcd4u: goto label_cd4;
        case 0xcd8u: goto label_cd8;
        case 0xcdcu: goto label_cdc;
        case 0xce0u: goto label_ce0;
        case 0xce4u: goto label_ce4;
        case 0xce8u: goto label_ce8;
        case 0xcecu: goto label_cec;
        case 0xcf0u: goto label_cf0;
        case 0xcf4u: goto label_cf4;
        case 0xcf8u: goto label_cf8;
        case 0xcfcu: goto label_cfc;
        case 0xd00u: goto label_d00;
        case 0xd04u: goto label_d04;
        case 0xd08u: goto label_d08;
        case 0xd0cu: goto label_d0c;
        case 0xd10u: goto label_d10;
        case 0xd14u: goto label_d14;
        case 0xd18u: goto label_d18;
        case 0xd1cu: goto label_d1c;
        case 0xd20u: goto label_d20;
        case 0xd24u: goto label_d24;
        case 0xd28u: goto label_d28;
        case 0xd2cu: goto label_d2c;
        case 0xd30u: goto label_d30;
        case 0xd34u: goto label_d34;
        case 0xd38u: goto label_d38;
        case 0xd3cu: goto label_d3c;
        case 0xd40u: goto label_d40;
        case 0xd44u: goto label_d44;
        case 0xd48u: goto label_d48;
        case 0xd4cu: goto label_d4c;
        case 0xd50u: goto label_d50;
        case 0xd54u: goto label_d54;
        case 0xd58u: goto label_d58;
        case 0xd5cu: goto label_d5c;
        case 0xd60u: goto label_d60;
        case 0xd64u: goto label_d64;
        case 0xd68u: goto label_d68;
        case 0xd6cu: goto label_d6c;
        case 0xd70u: goto label_d70;
        case 0xd74u: goto label_d74;
        case 0xd78u: goto label_d78;
        case 0xd7cu: goto label_d7c;
        case 0xd80u: goto label_d80;
        case 0xd84u: goto label_d84;
        case 0xd88u: goto label_d88;
        case 0xd8cu: goto label_d8c;
        case 0xd90u: goto label_d90;
        case 0xd94u: goto label_d94;
        case 0xd98u: goto label_d98;
        case 0xd9cu: goto label_d9c;
        case 0xda0u: goto label_da0;
        case 0xda4u: goto label_da4;
        case 0xda8u: goto label_da8;
        case 0xdacu: goto label_dac;
        case 0xdb0u: goto label_db0;
        case 0xdb4u: goto label_db4;
        case 0xdb8u: goto label_db8;
        case 0xdbcu: goto label_dbc;
        case 0xdc0u: goto label_dc0;
        case 0xdc4u: goto label_dc4;
        case 0xdc8u: goto label_dc8;
        case 0xdccu: goto label_dcc;
        case 0xdd0u: goto label_dd0;
        case 0xdd4u: goto label_dd4;
        case 0xdd8u: goto label_dd8;
        case 0xddcu: goto label_ddc;
        case 0xde0u: goto label_de0;
        case 0xde4u: goto label_de4;
        case 0xde8u: goto label_de8;
        case 0xdecu: goto label_dec;
        case 0xdf0u: goto label_df0;
        case 0xdf4u: goto label_df4;
        case 0xdf8u: goto label_df8;
        case 0xdfcu: goto label_dfc;
        case 0xe00u: goto label_e00;
        case 0xe04u: goto label_e04;
        case 0xe08u: goto label_e08;
        case 0xe0cu: goto label_e0c;
        case 0xe10u: goto label_e10;
        case 0xe14u: goto label_e14;
        case 0xe18u: goto label_e18;
        case 0xe1cu: goto label_e1c;
        case 0xe20u: goto label_e20;
        case 0xe24u: goto label_e24;
        case 0xe28u: goto label_e28;
        case 0xe2cu: goto label_e2c;
        case 0xe30u: goto label_e30;
        case 0xe34u: goto label_e34;
        case 0xe38u: goto label_e38;
        case 0xe3cu: goto label_e3c;
        case 0xe40u: goto label_e40;
        case 0xe44u: goto label_e44;
        case 0xe48u: goto label_e48;
        case 0xe4cu: goto label_e4c;
        case 0xe50u: goto label_e50;
        case 0xe54u: goto label_e54;
        case 0xe58u: goto label_e58;
        case 0xe5cu: goto label_e5c;
        case 0xe60u: goto label_e60;
        case 0xe64u: goto label_e64;
        case 0xe68u: goto label_e68;
        case 0xe6cu: goto label_e6c;
        case 0xe70u: goto label_e70;
        case 0xe74u: goto label_e74;
        case 0xe78u: goto label_e78;
        case 0xe7cu: goto label_e7c;
        case 0xe80u: goto label_e80;
        case 0xe84u: goto label_e84;
        case 0xe88u: goto label_e88;
        case 0xe8cu: goto label_e8c;
        case 0xe90u: goto label_e90;
        case 0xe94u: goto label_e94;
        case 0xe98u: goto label_e98;
        case 0xe9cu: goto label_e9c;
        case 0xea0u: goto label_ea0;
        case 0xea4u: goto label_ea4;
        case 0xea8u: goto label_ea8;
        case 0xeacu: goto label_eac;
        case 0xeb0u: goto label_eb0;
        case 0xeb4u: goto label_eb4;
        case 0xeb8u: goto label_eb8;
        case 0xebcu: goto label_ebc;
        case 0xec0u: goto label_ec0;
        case 0xec4u: goto label_ec4;
        case 0xec8u: goto label_ec8;
        case 0xeccu: goto label_ecc;
        case 0xed0u: goto label_ed0;
        case 0xed4u: goto label_ed4;
        case 0xed8u: goto label_ed8;
        case 0xedcu: goto label_edc;
        case 0xee0u: goto label_ee0;
        case 0xee4u: goto label_ee4;
        case 0xee8u: goto label_ee8;
        case 0xeecu: goto label_eec;
        case 0xef0u: goto label_ef0;
        case 0xef4u: goto label_ef4;
        case 0xef8u: goto label_ef8;
        case 0xefcu: goto label_efc;
        case 0xf00u: goto label_f00;
        case 0xf04u: goto label_f04;
        case 0xf08u: goto label_f08;
        case 0xf0cu: goto label_f0c;
        case 0xf10u: goto label_f10;
        case 0xf14u: goto label_f14;
        case 0xf18u: goto label_f18;
        case 0xf1cu: goto label_f1c;
        case 0xf20u: goto label_f20;
        case 0xf24u: goto label_f24;
        case 0xf28u: goto label_f28;
        case 0xf2cu: goto label_f2c;
        case 0xf30u: goto label_f30;
        case 0xf34u: goto label_f34;
        case 0xf38u: goto label_f38;
        case 0xf3cu: goto label_f3c;
        case 0xf40u: goto label_f40;
        case 0xf44u: goto label_f44;
        case 0xf48u: goto label_f48;
        case 0xf4cu: goto label_f4c;
        case 0xf50u: goto label_f50;
        case 0xf54u: goto label_f54;
        case 0xf58u: goto label_f58;
        case 0xf5cu: goto label_f5c;
        case 0xf60u: goto label_f60;
        case 0xf64u: goto label_f64;
        case 0xf68u: goto label_f68;
        case 0xf6cu: goto label_f6c;
        case 0xf70u: goto label_f70;
        case 0xf74u: goto label_f74;
        case 0xf78u: goto label_f78;
        case 0xf7cu: goto label_f7c;
        case 0xf80u: goto label_f80;
        case 0xf84u: goto label_f84;
        case 0xf88u: goto label_f88;
        case 0xf8cu: goto label_f8c;
        case 0xf90u: goto label_f90;
        case 0xf94u: goto label_f94;
        case 0xf98u: goto label_f98;
        case 0xf9cu: goto label_f9c;
        case 0xfa0u: goto label_fa0;
        case 0xfa4u: goto label_fa4;
        case 0xfa8u: goto label_fa8;
        case 0xfacu: goto label_fac;
        case 0xfb0u: goto label_fb0;
        case 0xfb4u: goto label_fb4;
        case 0xfb8u: goto label_fb8;
        case 0xfbcu: goto label_fbc;
        case 0xfc0u: goto label_fc0;
        case 0xfc4u: goto label_fc4;
        case 0xfc8u: goto label_fc8;
        case 0xfccu: goto label_fcc;
        case 0xfd0u: goto label_fd0;
        case 0xfd4u: goto label_fd4;
        case 0xfd8u: goto label_fd8;
        case 0xfdcu: goto label_fdc;
        case 0xfe0u: goto label_fe0;
        case 0xfe4u: goto label_fe4;
        case 0xfe8u: goto label_fe8;
        case 0xfecu: goto label_fec;
        case 0xff0u: goto label_ff0;
        case 0xff4u: goto label_ff4;
        case 0xff8u: goto label_ff8;
        case 0xffcu: goto label_ffc;
        case 0x1000u: goto label_1000;
        case 0x1004u: goto label_1004;
        case 0x1008u: goto label_1008;
        case 0x100cu: goto label_100c;
        case 0x1010u: goto label_1010;
        case 0x1014u: goto label_1014;
        case 0x1018u: goto label_1018;
        case 0x101cu: goto label_101c;
        case 0x1020u: goto label_1020;
        case 0x1024u: goto label_1024;
        case 0x1028u: goto label_1028;
        case 0x102cu: goto label_102c;
        case 0x1030u: goto label_1030;
        case 0x1034u: goto label_1034;
        case 0x1038u: goto label_1038;
        case 0x103cu: goto label_103c;
        case 0x1040u: goto label_1040;
        case 0x1044u: goto label_1044;
        case 0x1048u: goto label_1048;
        case 0x104cu: goto label_104c;
        case 0x1050u: goto label_1050;
        case 0x1054u: goto label_1054;
        case 0x1058u: goto label_1058;
        case 0x105cu: goto label_105c;
        case 0x1060u: goto label_1060;
        case 0x1064u: goto label_1064;
        case 0x1068u: goto label_1068;
        case 0x106cu: goto label_106c;
        case 0x1070u: goto label_1070;
        case 0x1074u: goto label_1074;
        case 0x1078u: goto label_1078;
        case 0x107cu: goto label_107c;
        case 0x1080u: goto label_1080;
        case 0x1084u: goto label_1084;
        case 0x1088u: goto label_1088;
        case 0x108cu: goto label_108c;
        case 0x1090u: goto label_1090;
        case 0x1094u: goto label_1094;
        case 0x1098u: goto label_1098;
        case 0x109cu: goto label_109c;
        case 0x10a0u: goto label_10a0;
        case 0x10a4u: goto label_10a4;
        case 0x10a8u: goto label_10a8;
        case 0x10acu: goto label_10ac;
        case 0x10b0u: goto label_10b0;
        case 0x10b4u: goto label_10b4;
        case 0x10b8u: goto label_10b8;
        case 0x10bcu: goto label_10bc;
        case 0x10c0u: goto label_10c0;
        case 0x10c4u: goto label_10c4;
        case 0x10c8u: goto label_10c8;
        case 0x10ccu: goto label_10cc;
        case 0x10d0u: goto label_10d0;
        case 0x10d4u: goto label_10d4;
        case 0x10d8u: goto label_10d8;
        case 0x10dcu: goto label_10dc;
        case 0x10e0u: goto label_10e0;
        case 0x10e4u: goto label_10e4;
        case 0x10e8u: goto label_10e8;
        case 0x10ecu: goto label_10ec;
        case 0x10f0u: goto label_10f0;
        case 0x10f4u: goto label_10f4;
        case 0x10f8u: goto label_10f8;
        case 0x10fcu: goto label_10fc;
        case 0x1100u: goto label_1100;
        case 0x1104u: goto label_1104;
        case 0x1108u: goto label_1108;
        case 0x110cu: goto label_110c;
        case 0x1110u: goto label_1110;
        case 0x1114u: goto label_1114;
        case 0x1118u: goto label_1118;
        case 0x111cu: goto label_111c;
        case 0x1120u: goto label_1120;
        case 0x1124u: goto label_1124;
        case 0x1128u: goto label_1128;
        case 0x112cu: goto label_112c;
        case 0x1130u: goto label_1130;
        case 0x1134u: goto label_1134;
        case 0x1138u: goto label_1138;
        case 0x113cu: goto label_113c;
        case 0x1140u: goto label_1140;
        case 0x1144u: goto label_1144;
        case 0x1148u: goto label_1148;
        case 0x114cu: goto label_114c;
        case 0x1150u: goto label_1150;
        case 0x1154u: goto label_1154;
        case 0x1158u: goto label_1158;
        case 0x115cu: goto label_115c;
        case 0x1160u: goto label_1160;
        case 0x1164u: goto label_1164;
        case 0x1168u: goto label_1168;
        case 0x116cu: goto label_116c;
        case 0x1170u: goto label_1170;
        case 0x1174u: goto label_1174;
        case 0x1178u: goto label_1178;
        case 0x117cu: goto label_117c;
        case 0x1180u: goto label_1180;
        case 0x1184u: goto label_1184;
        case 0x1188u: goto label_1188;
        case 0x118cu: goto label_118c;
        case 0x1190u: goto label_1190;
        case 0x1194u: goto label_1194;
        case 0x1198u: goto label_1198;
        case 0x119cu: goto label_119c;
        case 0x11a0u: goto label_11a0;
        case 0x11a4u: goto label_11a4;
        case 0x11a8u: goto label_11a8;
        case 0x11acu: goto label_11ac;
        case 0x11b0u: goto label_11b0;
        case 0x11b4u: goto label_11b4;
        case 0x11b8u: goto label_11b8;
        case 0x11bcu: goto label_11bc;
        case 0x11c0u: goto label_11c0;
        case 0x11c4u: goto label_11c4;
        case 0x11c8u: goto label_11c8;
        case 0x11ccu: goto label_11cc;
        case 0x11d0u: goto label_11d0;
        case 0x11d4u: goto label_11d4;
        case 0x11d8u: goto label_11d8;
        case 0x11dcu: goto label_11dc;
        case 0x11e0u: goto label_11e0;
        case 0x11e4u: goto label_11e4;
        case 0x11e8u: goto label_11e8;
        case 0x11ecu: goto label_11ec;
        case 0x11f0u: goto label_11f0;
        case 0x11f4u: goto label_11f4;
        case 0x11f8u: goto label_11f8;
        case 0x11fcu: goto label_11fc;
        case 0x1200u: goto label_1200;
        case 0x1204u: goto label_1204;
        case 0x1208u: goto label_1208;
        case 0x120cu: goto label_120c;
        case 0x1210u: goto label_1210;
        case 0x1214u: goto label_1214;
        case 0x1218u: goto label_1218;
        case 0x121cu: goto label_121c;
        case 0x1220u: goto label_1220;
        case 0x1224u: goto label_1224;
        case 0x1228u: goto label_1228;
        case 0x122cu: goto label_122c;
        case 0x1230u: goto label_1230;
        case 0x1234u: goto label_1234;
        case 0x1238u: goto label_1238;
        case 0x123cu: goto label_123c;
        case 0x1240u: goto label_1240;
        case 0x1244u: goto label_1244;
        case 0x1248u: goto label_1248;
        case 0x124cu: goto label_124c;
        case 0x1250u: goto label_1250;
        case 0x1254u: goto label_1254;
        case 0x1258u: goto label_1258;
        case 0x125cu: goto label_125c;
        case 0x1260u: goto label_1260;
        case 0x1264u: goto label_1264;
        case 0x1268u: goto label_1268;
        case 0x126cu: goto label_126c;
        case 0x1270u: goto label_1270;
        case 0x1274u: goto label_1274;
        case 0x1278u: goto label_1278;
        case 0x127cu: goto label_127c;
        case 0x1280u: goto label_1280;
        case 0x1284u: goto label_1284;
        case 0x1288u: goto label_1288;
        case 0x128cu: goto label_128c;
        case 0x1290u: goto label_1290;
        case 0x1294u: goto label_1294;
        case 0x1298u: goto label_1298;
        case 0x129cu: goto label_129c;
        case 0x12a0u: goto label_12a0;
        case 0x12a4u: goto label_12a4;
        case 0x12a8u: goto label_12a8;
        case 0x12acu: goto label_12ac;
        case 0x12b0u: goto label_12b0;
        case 0x12b4u: goto label_12b4;
        case 0x12b8u: goto label_12b8;
        case 0x12bcu: goto label_12bc;
        case 0x12c0u: goto label_12c0;
        case 0x12c4u: goto label_12c4;
        case 0x12c8u: goto label_12c8;
        case 0x12ccu: goto label_12cc;
        case 0x12d0u: goto label_12d0;
        case 0x12d4u: goto label_12d4;
        case 0x12d8u: goto label_12d8;
        case 0x12dcu: goto label_12dc;
        case 0x12e0u: goto label_12e0;
        case 0x12e4u: goto label_12e4;
        case 0x12e8u: goto label_12e8;
        case 0x12ecu: goto label_12ec;
        case 0x12f0u: goto label_12f0;
        case 0x12f4u: goto label_12f4;
        case 0x12f8u: goto label_12f8;
        case 0x12fcu: goto label_12fc;
        case 0x1300u: goto label_1300;
        case 0x1304u: goto label_1304;
        case 0x1308u: goto label_1308;
        case 0x130cu: goto label_130c;
        case 0x1310u: goto label_1310;
        case 0x1314u: goto label_1314;
        case 0x1318u: goto label_1318;
        case 0x131cu: goto label_131c;
        case 0x1320u: goto label_1320;
        case 0x1324u: goto label_1324;
        case 0x1328u: goto label_1328;
        case 0x132cu: goto label_132c;
        case 0x1330u: goto label_1330;
        case 0x1334u: goto label_1334;
        case 0x1338u: goto label_1338;
        case 0x133cu: goto label_133c;
        case 0x1340u: goto label_1340;
        case 0x1344u: goto label_1344;
        case 0x1348u: goto label_1348;
        case 0x134cu: goto label_134c;
        case 0x1350u: goto label_1350;
        case 0x1354u: goto label_1354;
        case 0x1358u: goto label_1358;
        case 0x135cu: goto label_135c;
        case 0x1360u: goto label_1360;
        case 0x1364u: goto label_1364;
        case 0x1368u: goto label_1368;
        case 0x136cu: goto label_136c;
        case 0x1370u: goto label_1370;
        case 0x1374u: goto label_1374;
        case 0x1378u: goto label_1378;
        case 0x137cu: goto label_137c;
        case 0x1380u: goto label_1380;
        case 0x1384u: goto label_1384;
        case 0x1388u: goto label_1388;
        case 0x138cu: goto label_138c;
        case 0x1390u: goto label_1390;
        case 0x1394u: goto label_1394;
        case 0x1398u: goto label_1398;
        case 0x139cu: goto label_139c;
        case 0x13a0u: goto label_13a0;
        case 0x13a4u: goto label_13a4;
        case 0x13a8u: goto label_13a8;
        case 0x13acu: goto label_13ac;
        case 0x13b0u: goto label_13b0;
        case 0x13b4u: goto label_13b4;
        case 0x13b8u: goto label_13b8;
        case 0x13bcu: goto label_13bc;
        case 0x13c0u: goto label_13c0;
        case 0x13c4u: goto label_13c4;
        case 0x13c8u: goto label_13c8;
        case 0x13ccu: goto label_13cc;
        case 0x13d0u: goto label_13d0;
        case 0x13d4u: goto label_13d4;
        case 0x13d8u: goto label_13d8;
        case 0x13dcu: goto label_13dc;
        case 0x13e0u: goto label_13e0;
        case 0x13e4u: goto label_13e4;
        case 0x13e8u: goto label_13e8;
        case 0x13ecu: goto label_13ec;
        case 0x13f0u: goto label_13f0;
        case 0x13f4u: goto label_13f4;
        case 0x13f8u: goto label_13f8;
        case 0x13fcu: goto label_13fc;
        case 0x1400u: goto label_1400;
        case 0x1404u: goto label_1404;
        case 0x1408u: goto label_1408;
        case 0x140cu: goto label_140c;
        case 0x1410u: goto label_1410;
        case 0x1414u: goto label_1414;
        case 0x1418u: goto label_1418;
        case 0x141cu: goto label_141c;
        case 0x1420u: goto label_1420;
        case 0x1424u: goto label_1424;
        case 0x1428u: goto label_1428;
        case 0x142cu: goto label_142c;
        case 0x1430u: goto label_1430;
        case 0x1434u: goto label_1434;
        case 0x1438u: goto label_1438;
        case 0x143cu: goto label_143c;
        case 0x1440u: goto label_1440;
        case 0x1444u: goto label_1444;
        case 0x1448u: goto label_1448;
        case 0x144cu: goto label_144c;
        case 0x1450u: goto label_1450;
        case 0x1454u: goto label_1454;
        case 0x1458u: goto label_1458;
        case 0x145cu: goto label_145c;
        case 0x1460u: goto label_1460;
        case 0x1464u: goto label_1464;
        case 0x1468u: goto label_1468;
        case 0x146cu: goto label_146c;
        case 0x1470u: goto label_1470;
        case 0x1474u: goto label_1474;
        case 0x1478u: goto label_1478;
        case 0x147cu: goto label_147c;
        case 0x1480u: goto label_1480;
        case 0x1484u: goto label_1484;
        case 0x1488u: goto label_1488;
        case 0x148cu: goto label_148c;
        case 0x1490u: goto label_1490;
        case 0x1494u: goto label_1494;
        case 0x1498u: goto label_1498;
        case 0x149cu: goto label_149c;
        case 0x14a0u: goto label_14a0;
        case 0x14a4u: goto label_14a4;
        case 0x14a8u: goto label_14a8;
        case 0x14acu: goto label_14ac;
        case 0x14b0u: goto label_14b0;
        case 0x14b4u: goto label_14b4;
        case 0x14b8u: goto label_14b8;
        case 0x14bcu: goto label_14bc;
        case 0x14c0u: goto label_14c0;
        case 0x14c4u: goto label_14c4;
        case 0x14c8u: goto label_14c8;
        case 0x14ccu: goto label_14cc;
        case 0x14d0u: goto label_14d0;
        case 0x14d4u: goto label_14d4;
        case 0x14d8u: goto label_14d8;
        case 0x14dcu: goto label_14dc;
        case 0x14e0u: goto label_14e0;
        case 0x14e4u: goto label_14e4;
        case 0x14e8u: goto label_14e8;
        case 0x14ecu: goto label_14ec;
        case 0x14f0u: goto label_14f0;
        case 0x14f4u: goto label_14f4;
        case 0x14f8u: goto label_14f8;
        case 0x14fcu: goto label_14fc;
        case 0x1500u: goto label_1500;
        case 0x1504u: goto label_1504;
        case 0x1508u: goto label_1508;
        case 0x150cu: goto label_150c;
        case 0x1510u: goto label_1510;
        case 0x1514u: goto label_1514;
        case 0x1518u: goto label_1518;
        case 0x151cu: goto label_151c;
        case 0x1520u: goto label_1520;
        case 0x1524u: goto label_1524;
        case 0x1528u: goto label_1528;
        case 0x152cu: goto label_152c;
        case 0x1530u: goto label_1530;
        case 0x1534u: goto label_1534;
        case 0x1538u: goto label_1538;
        case 0x153cu: goto label_153c;
        case 0x1540u: goto label_1540;
        case 0x1544u: goto label_1544;
        case 0x1548u: goto label_1548;
        case 0x154cu: goto label_154c;
        case 0x1550u: goto label_1550;
        case 0x1554u: goto label_1554;
        case 0x1558u: goto label_1558;
        case 0x155cu: goto label_155c;
        case 0x1560u: goto label_1560;
        case 0x1564u: goto label_1564;
        case 0x1568u: goto label_1568;
        case 0x156cu: goto label_156c;
        case 0x1570u: goto label_1570;
        case 0x1574u: goto label_1574;
        case 0x1578u: goto label_1578;
        case 0x157cu: goto label_157c;
        case 0x1580u: goto label_1580;
        case 0x1584u: goto label_1584;
        case 0x1588u: goto label_1588;
        case 0x158cu: goto label_158c;
        case 0x1590u: goto label_1590;
        case 0x1594u: goto label_1594;
        case 0x1598u: goto label_1598;
        case 0x159cu: goto label_159c;
        case 0x15a0u: goto label_15a0;
        case 0x15a4u: goto label_15a4;
        case 0x15a8u: goto label_15a8;
        case 0x15acu: goto label_15ac;
        case 0x15b0u: goto label_15b0;
        case 0x15b4u: goto label_15b4;
        case 0x15b8u: goto label_15b8;
        case 0x15bcu: goto label_15bc;
        case 0x15c0u: goto label_15c0;
        case 0x15c4u: goto label_15c4;
        case 0x15c8u: goto label_15c8;
        case 0x15ccu: goto label_15cc;
        case 0x15d0u: goto label_15d0;
        case 0x15d4u: goto label_15d4;
        case 0x15d8u: goto label_15d8;
        case 0x15dcu: goto label_15dc;
        case 0x15e0u: goto label_15e0;
        case 0x15e4u: goto label_15e4;
        case 0x15e8u: goto label_15e8;
        case 0x15ecu: goto label_15ec;
        case 0x15f0u: goto label_15f0;
        case 0x15f4u: goto label_15f4;
        case 0x15f8u: goto label_15f8;
        case 0x15fcu: goto label_15fc;
        case 0x1600u: goto label_1600;
        case 0x1604u: goto label_1604;
        case 0x1608u: goto label_1608;
        case 0x160cu: goto label_160c;
        case 0x1610u: goto label_1610;
        case 0x1614u: goto label_1614;
        case 0x1618u: goto label_1618;
        case 0x161cu: goto label_161c;
        case 0x1620u: goto label_1620;
        case 0x1624u: goto label_1624;
        case 0x1628u: goto label_1628;
        case 0x162cu: goto label_162c;
        case 0x1630u: goto label_1630;
        case 0x1634u: goto label_1634;
        case 0x1638u: goto label_1638;
        case 0x163cu: goto label_163c;
        case 0x1640u: goto label_1640;
        case 0x1644u: goto label_1644;
        case 0x1648u: goto label_1648;
        case 0x164cu: goto label_164c;
        case 0x1650u: goto label_1650;
        case 0x1654u: goto label_1654;
        case 0x1658u: goto label_1658;
        case 0x165cu: goto label_165c;
        case 0x1660u: goto label_1660;
        case 0x1664u: goto label_1664;
        case 0x1668u: goto label_1668;
        case 0x166cu: goto label_166c;
        case 0x1670u: goto label_1670;
        case 0x1674u: goto label_1674;
        case 0x1678u: goto label_1678;
        case 0x167cu: goto label_167c;
        case 0x1680u: goto label_1680;
        case 0x1684u: goto label_1684;
        case 0x1688u: goto label_1688;
        case 0x168cu: goto label_168c;
        case 0x1690u: goto label_1690;
        case 0x1694u: goto label_1694;
        case 0x1698u: goto label_1698;
        case 0x169cu: goto label_169c;
        case 0x16a0u: goto label_16a0;
        case 0x16a4u: goto label_16a4;
        case 0x16a8u: goto label_16a8;
        case 0x16acu: goto label_16ac;
        case 0x16b0u: goto label_16b0;
        case 0x16b4u: goto label_16b4;
        case 0x16b8u: goto label_16b8;
        case 0x16bcu: goto label_16bc;
        case 0x16c0u: goto label_16c0;
        case 0x16c4u: goto label_16c4;
        case 0x16c8u: goto label_16c8;
        case 0x16ccu: goto label_16cc;
        case 0x16d0u: goto label_16d0;
        case 0x16d4u: goto label_16d4;
        case 0x16d8u: goto label_16d8;
        case 0x16dcu: goto label_16dc;
        case 0x16e0u: goto label_16e0;
        case 0x16e4u: goto label_16e4;
        case 0x16e8u: goto label_16e8;
        case 0x16ecu: goto label_16ec;
        case 0x16f0u: goto label_16f0;
        case 0x16f4u: goto label_16f4;
        case 0x16f8u: goto label_16f8;
        case 0x16fcu: goto label_16fc;
        case 0x1700u: goto label_1700;
        case 0x1704u: goto label_1704;
        case 0x1708u: goto label_1708;
        case 0x170cu: goto label_170c;
        case 0x1710u: goto label_1710;
        case 0x1714u: goto label_1714;
        case 0x1718u: goto label_1718;
        case 0x171cu: goto label_171c;
        case 0x1720u: goto label_1720;
        case 0x1724u: goto label_1724;
        case 0x1728u: goto label_1728;
        case 0x172cu: goto label_172c;
        case 0x1730u: goto label_1730;
        case 0x1734u: goto label_1734;
        case 0x1738u: goto label_1738;
        case 0x173cu: goto label_173c;
        case 0x1740u: goto label_1740;
        case 0x1744u: goto label_1744;
        case 0x1748u: goto label_1748;
        case 0x174cu: goto label_174c;
        case 0x1750u: goto label_1750;
        case 0x1754u: goto label_1754;
        case 0x1758u: goto label_1758;
        case 0x175cu: goto label_175c;
        case 0x1760u: goto label_1760;
        case 0x1764u: goto label_1764;
        case 0x1768u: goto label_1768;
        case 0x176cu: goto label_176c;
        case 0x1770u: goto label_1770;
        case 0x1774u: goto label_1774;
        case 0x1778u: goto label_1778;
        case 0x177cu: goto label_177c;
        case 0x1780u: goto label_1780;
        case 0x1784u: goto label_1784;
        case 0x1788u: goto label_1788;
        case 0x178cu: goto label_178c;
        case 0x1790u: goto label_1790;
        case 0x1794u: goto label_1794;
        case 0x1798u: goto label_1798;
        case 0x179cu: goto label_179c;
        case 0x17a0u: goto label_17a0;
        case 0x17a4u: goto label_17a4;
        case 0x17a8u: goto label_17a8;
        case 0x17acu: goto label_17ac;
        case 0x17b0u: goto label_17b0;
        case 0x17b4u: goto label_17b4;
        case 0x17b8u: goto label_17b8;
        case 0x17bcu: goto label_17bc;
        case 0x17c0u: goto label_17c0;
        case 0x17c4u: goto label_17c4;
        case 0x17c8u: goto label_17c8;
        case 0x17ccu: goto label_17cc;
        case 0x17d0u: goto label_17d0;
        case 0x17d4u: goto label_17d4;
        case 0x17d8u: goto label_17d8;
        case 0x17dcu: goto label_17dc;
        case 0x17e0u: goto label_17e0;
        case 0x17e4u: goto label_17e4;
        case 0x17e8u: goto label_17e8;
        case 0x17ecu: goto label_17ec;
        case 0x17f0u: goto label_17f0;
        case 0x17f4u: goto label_17f4;
        case 0x17f8u: goto label_17f8;
        case 0x17fcu: goto label_17fc;
        case 0x1800u: goto label_1800;
        case 0x1804u: goto label_1804;
        case 0x1808u: goto label_1808;
        case 0x180cu: goto label_180c;
        case 0x1810u: goto label_1810;
        case 0x1814u: goto label_1814;
        case 0x1818u: goto label_1818;
        case 0x181cu: goto label_181c;
        case 0x1820u: goto label_1820;
        case 0x1824u: goto label_1824;
        case 0x1828u: goto label_1828;
        case 0x182cu: goto label_182c;
        case 0x1830u: goto label_1830;
        case 0x1834u: goto label_1834;
        case 0x1838u: goto label_1838;
        case 0x183cu: goto label_183c;
        case 0x1840u: goto label_1840;
        case 0x1844u: goto label_1844;
        case 0x1848u: goto label_1848;
        case 0x184cu: goto label_184c;
        case 0x1850u: goto label_1850;
        case 0x1854u: goto label_1854;
        case 0x1858u: goto label_1858;
        case 0x185cu: goto label_185c;
        case 0x1860u: goto label_1860;
        case 0x1864u: goto label_1864;
        case 0x1868u: goto label_1868;
        case 0x186cu: goto label_186c;
        case 0x1870u: goto label_1870;
        case 0x1874u: goto label_1874;
        case 0x1878u: goto label_1878;
        case 0x187cu: goto label_187c;
        case 0x1880u: goto label_1880;
        case 0x1884u: goto label_1884;
        case 0x1888u: goto label_1888;
        case 0x188cu: goto label_188c;
        case 0x1890u: goto label_1890;
        case 0x1894u: goto label_1894;
        case 0x1898u: goto label_1898;
        case 0x189cu: goto label_189c;
        case 0x18a0u: goto label_18a0;
        case 0x18a4u: goto label_18a4;
        case 0x18a8u: goto label_18a8;
        case 0x18acu: goto label_18ac;
        case 0x18b0u: goto label_18b0;
        case 0x18b4u: goto label_18b4;
        case 0x18b8u: goto label_18b8;
        case 0x18bcu: goto label_18bc;
        case 0x18c0u: goto label_18c0;
        case 0x18c4u: goto label_18c4;
        case 0x18c8u: goto label_18c8;
        case 0x18ccu: goto label_18cc;
        case 0x18d0u: goto label_18d0;
        case 0x18d4u: goto label_18d4;
        case 0x18d8u: goto label_18d8;
        case 0x18dcu: goto label_18dc;
        case 0x18e0u: goto label_18e0;
        case 0x18e4u: goto label_18e4;
        case 0x18e8u: goto label_18e8;
        case 0x18ecu: goto label_18ec;
        case 0x18f0u: goto label_18f0;
        case 0x18f4u: goto label_18f4;
        case 0x18f8u: goto label_18f8;
        case 0x18fcu: goto label_18fc;
        case 0x1900u: goto label_1900;
        case 0x1904u: goto label_1904;
        case 0x1908u: goto label_1908;
        case 0x190cu: goto label_190c;
        case 0x1910u: goto label_1910;
        case 0x1914u: goto label_1914;
        case 0x1918u: goto label_1918;
        case 0x191cu: goto label_191c;
        case 0x1920u: goto label_1920;
        case 0x1924u: goto label_1924;
        case 0x1928u: goto label_1928;
        case 0x192cu: goto label_192c;
        case 0x1930u: goto label_1930;
        case 0x1934u: goto label_1934;
        case 0x1938u: goto label_1938;
        case 0x193cu: goto label_193c;
        case 0x1940u: goto label_1940;
        case 0x1944u: goto label_1944;
        case 0x1948u: goto label_1948;
        case 0x194cu: goto label_194c;
        case 0x1950u: goto label_1950;
        case 0x1954u: goto label_1954;
        case 0x1958u: goto label_1958;
        case 0x195cu: goto label_195c;
        case 0x1960u: goto label_1960;
        case 0x1964u: goto label_1964;
        case 0x1968u: goto label_1968;
        case 0x196cu: goto label_196c;
        case 0x1970u: goto label_1970;
        case 0x1974u: goto label_1974;
        case 0x1978u: goto label_1978;
        case 0x197cu: goto label_197c;
        case 0x1980u: goto label_1980;
        case 0x1984u: goto label_1984;
        case 0x1988u: goto label_1988;
        case 0x198cu: goto label_198c;
        case 0x1990u: goto label_1990;
        case 0x1994u: goto label_1994;
        case 0x1998u: goto label_1998;
        case 0x199cu: goto label_199c;
        case 0x19a0u: goto label_19a0;
        case 0x19a4u: goto label_19a4;
        case 0x19a8u: goto label_19a8;
        case 0x19acu: goto label_19ac;
        case 0x19b0u: goto label_19b0;
        case 0x19b4u: goto label_19b4;
        case 0x19b8u: goto label_19b8;
        case 0x19bcu: goto label_19bc;
        case 0x19c0u: goto label_19c0;
        case 0x19c4u: goto label_19c4;
        case 0x19c8u: goto label_19c8;
        case 0x19ccu: goto label_19cc;
        case 0x19d0u: goto label_19d0;
        case 0x19d4u: goto label_19d4;
        case 0x19d8u: goto label_19d8;
        case 0x19dcu: goto label_19dc;
        case 0x19e0u: goto label_19e0;
        case 0x19e4u: goto label_19e4;
        case 0x19e8u: goto label_19e8;
        case 0x19ecu: goto label_19ec;
        case 0x19f0u: goto label_19f0;
        case 0x19f4u: goto label_19f4;
        case 0x19f8u: goto label_19f8;
        case 0x19fcu: goto label_19fc;
        case 0x1a00u: goto label_1a00;
        case 0x1a04u: goto label_1a04;
        case 0x1a08u: goto label_1a08;
        case 0x1a0cu: goto label_1a0c;
        case 0x1a10u: goto label_1a10;
        case 0x1a14u: goto label_1a14;
        case 0x1a18u: goto label_1a18;
        case 0x1a1cu: goto label_1a1c;
        case 0x1a20u: goto label_1a20;
        case 0x1a24u: goto label_1a24;
        case 0x1a28u: goto label_1a28;
        case 0x1a2cu: goto label_1a2c;
        case 0x1a30u: goto label_1a30;
        case 0x1a34u: goto label_1a34;
        case 0x1a38u: goto label_1a38;
        case 0x1a3cu: goto label_1a3c;
        case 0x1a40u: goto label_1a40;
        case 0x1a44u: goto label_1a44;
        case 0x1a48u: goto label_1a48;
        case 0x1a4cu: goto label_1a4c;
        case 0x1a50u: goto label_1a50;
        case 0x1a54u: goto label_1a54;
        case 0x1a58u: goto label_1a58;
        case 0x1a5cu: goto label_1a5c;
        case 0x1a60u: goto label_1a60;
        case 0x1a64u: goto label_1a64;
        case 0x1a68u: goto label_1a68;
        case 0x1a6cu: goto label_1a6c;
        case 0x1a70u: goto label_1a70;
        case 0x1a74u: goto label_1a74;
        case 0x1a78u: goto label_1a78;
        case 0x1a7cu: goto label_1a7c;
        case 0x1a80u: goto label_1a80;
        case 0x1a84u: goto label_1a84;
        case 0x1a88u: goto label_1a88;
        case 0x1a8cu: goto label_1a8c;
        case 0x1a90u: goto label_1a90;
        case 0x1a94u: goto label_1a94;
        case 0x1a98u: goto label_1a98;
        case 0x1a9cu: goto label_1a9c;
        case 0x1aa0u: goto label_1aa0;
        case 0x1aa4u: goto label_1aa4;
        case 0x1aa8u: goto label_1aa8;
        case 0x1aacu: goto label_1aac;
        case 0x1ab0u: goto label_1ab0;
        case 0x1ab4u: goto label_1ab4;
        case 0x1ab8u: goto label_1ab8;
        case 0x1abcu: goto label_1abc;
        case 0x1ac0u: goto label_1ac0;
        case 0x1ac4u: goto label_1ac4;
        case 0x1ac8u: goto label_1ac8;
        case 0x1accu: goto label_1acc;
        case 0x1ad0u: goto label_1ad0;
        case 0x1ad4u: goto label_1ad4;
        case 0x1ad8u: goto label_1ad8;
        case 0x1adcu: goto label_1adc;
        case 0x1ae0u: goto label_1ae0;
        case 0x1ae4u: goto label_1ae4;
        case 0x1ae8u: goto label_1ae8;
        case 0x1aecu: goto label_1aec;
        case 0x1af0u: goto label_1af0;
        case 0x1af4u: goto label_1af4;
        case 0x1af8u: goto label_1af8;
        case 0x1afcu: goto label_1afc;
        case 0x1b00u: goto label_1b00;
        case 0x1b04u: goto label_1b04;
        case 0x1b08u: goto label_1b08;
        case 0x1b0cu: goto label_1b0c;
        case 0x1b10u: goto label_1b10;
        case 0x1b14u: goto label_1b14;
        case 0x1b18u: goto label_1b18;
        case 0x1b1cu: goto label_1b1c;
        case 0x1b20u: goto label_1b20;
        case 0x1b24u: goto label_1b24;
        case 0x1b28u: goto label_1b28;
        case 0x1b2cu: goto label_1b2c;
        case 0x1b30u: goto label_1b30;
        case 0x1b34u: goto label_1b34;
        case 0x1b38u: goto label_1b38;
        case 0x1b3cu: goto label_1b3c;
        case 0x1b40u: goto label_1b40;
        case 0x1b44u: goto label_1b44;
        case 0x1b48u: goto label_1b48;
        case 0x1b4cu: goto label_1b4c;
        case 0x1b50u: goto label_1b50;
        case 0x1b54u: goto label_1b54;
        case 0x1b58u: goto label_1b58;
        case 0x1b5cu: goto label_1b5c;
        case 0x1b60u: goto label_1b60;
        case 0x1b64u: goto label_1b64;
        case 0x1b68u: goto label_1b68;
        case 0x1b6cu: goto label_1b6c;
        case 0x1b70u: goto label_1b70;
        case 0x1b74u: goto label_1b74;
        case 0x1b78u: goto label_1b78;
        case 0x1b7cu: goto label_1b7c;
        case 0x1b80u: goto label_1b80;
        case 0x1b84u: goto label_1b84;
        case 0x1b88u: goto label_1b88;
        case 0x1b8cu: goto label_1b8c;
        case 0x1b90u: goto label_1b90;
        case 0x1b94u: goto label_1b94;
        case 0x1b98u: goto label_1b98;
        case 0x1b9cu: goto label_1b9c;
        case 0x1ba0u: goto label_1ba0;
        case 0x1ba4u: goto label_1ba4;
        case 0x1ba8u: goto label_1ba8;
        case 0x1bacu: goto label_1bac;
        case 0x1bb0u: goto label_1bb0;
        case 0x1bb4u: goto label_1bb4;
        case 0x1bb8u: goto label_1bb8;
        case 0x1bbcu: goto label_1bbc;
        case 0x1bc0u: goto label_1bc0;
        case 0x1bc4u: goto label_1bc4;
        case 0x1bc8u: goto label_1bc8;
        case 0x1bccu: goto label_1bcc;
        case 0x1bd0u: goto label_1bd0;
        case 0x1bd4u: goto label_1bd4;
        case 0x1bd8u: goto label_1bd8;
        case 0x1bdcu: goto label_1bdc;
        case 0x1be0u: goto label_1be0;
        case 0x1be4u: goto label_1be4;
        case 0x1be8u: goto label_1be8;
        case 0x1becu: goto label_1bec;
        case 0x1bf0u: goto label_1bf0;
        case 0x1bf4u: goto label_1bf4;
        case 0x1bf8u: goto label_1bf8;
        case 0x1bfcu: goto label_1bfc;
        case 0x1c00u: goto label_1c00;
        case 0x1c04u: goto label_1c04;
        case 0x1c08u: goto label_1c08;
        case 0x1c0cu: goto label_1c0c;
        case 0x1c10u: goto label_1c10;
        case 0x1c14u: goto label_1c14;
        case 0x1c18u: goto label_1c18;
        case 0x1c1cu: goto label_1c1c;
        case 0x1c20u: goto label_1c20;
        case 0x1c24u: goto label_1c24;
        case 0x1c28u: goto label_1c28;
        case 0x1c2cu: goto label_1c2c;
        case 0x1c30u: goto label_1c30;
        case 0x1c34u: goto label_1c34;
        case 0x1c38u: goto label_1c38;
        case 0x1c3cu: goto label_1c3c;
        case 0x1c40u: goto label_1c40;
        case 0x1c44u: goto label_1c44;
        case 0x1c48u: goto label_1c48;
        case 0x1c4cu: goto label_1c4c;
        case 0x1c50u: goto label_1c50;
        case 0x1c54u: goto label_1c54;
        case 0x1c58u: goto label_1c58;
        case 0x1c5cu: goto label_1c5c;
        case 0x1c60u: goto label_1c60;
        case 0x1c64u: goto label_1c64;
        case 0x1c68u: goto label_1c68;
        case 0x1c6cu: goto label_1c6c;
        case 0x1c70u: goto label_1c70;
        case 0x1c74u: goto label_1c74;
        case 0x1c78u: goto label_1c78;
        case 0x1c7cu: goto label_1c7c;
        case 0x1c80u: goto label_1c80;
        case 0x1c84u: goto label_1c84;
        case 0x1c88u: goto label_1c88;
        case 0x1c8cu: goto label_1c8c;
        case 0x1c90u: goto label_1c90;
        case 0x1c94u: goto label_1c94;
        case 0x1c98u: goto label_1c98;
        case 0x1c9cu: goto label_1c9c;
        case 0x1ca0u: goto label_1ca0;
        case 0x1ca4u: goto label_1ca4;
        case 0x1ca8u: goto label_1ca8;
        case 0x1cacu: goto label_1cac;
        case 0x1cb0u: goto label_1cb0;
        case 0x1cb4u: goto label_1cb4;
        case 0x1cb8u: goto label_1cb8;
        case 0x1cbcu: goto label_1cbc;
        case 0x1cc0u: goto label_1cc0;
        case 0x1cc4u: goto label_1cc4;
        case 0x1cc8u: goto label_1cc8;
        case 0x1cccu: goto label_1ccc;
        case 0x1cd0u: goto label_1cd0;
        case 0x1cd4u: goto label_1cd4;
        case 0x1cd8u: goto label_1cd8;
        case 0x1cdcu: goto label_1cdc;
        case 0x1ce0u: goto label_1ce0;
        case 0x1ce4u: goto label_1ce4;
        case 0x1ce8u: goto label_1ce8;
        case 0x1cecu: goto label_1cec;
        case 0x1cf0u: goto label_1cf0;
        case 0x1cf4u: goto label_1cf4;
        case 0x1cf8u: goto label_1cf8;
        case 0x1cfcu: goto label_1cfc;
        case 0x1d00u: goto label_1d00;
        case 0x1d04u: goto label_1d04;
        case 0x1d08u: goto label_1d08;
        case 0x1d0cu: goto label_1d0c;
        case 0x1d10u: goto label_1d10;
        case 0x1d14u: goto label_1d14;
        case 0x1d18u: goto label_1d18;
        case 0x1d1cu: goto label_1d1c;
        case 0x1d20u: goto label_1d20;
        case 0x1d24u: goto label_1d24;
        case 0x1d28u: goto label_1d28;
        case 0x1d2cu: goto label_1d2c;
        case 0x1d30u: goto label_1d30;
        case 0x1d34u: goto label_1d34;
        case 0x1d38u: goto label_1d38;
        case 0x1d3cu: goto label_1d3c;
        case 0x1d40u: goto label_1d40;
        case 0x1d44u: goto label_1d44;
        case 0x1d48u: goto label_1d48;
        case 0x1d4cu: goto label_1d4c;
        case 0x1d50u: goto label_1d50;
        case 0x1d54u: goto label_1d54;
        case 0x1d58u: goto label_1d58;
        case 0x1d5cu: goto label_1d5c;
        case 0x1d60u: goto label_1d60;
        case 0x1d64u: goto label_1d64;
        case 0x1d68u: goto label_1d68;
        case 0x1d6cu: goto label_1d6c;
        case 0x1d70u: goto label_1d70;
        case 0x1d74u: goto label_1d74;
        case 0x1d78u: goto label_1d78;
        case 0x1d7cu: goto label_1d7c;
        case 0x1d80u: goto label_1d80;
        case 0x1d84u: goto label_1d84;
        case 0x1d88u: goto label_1d88;
        case 0x1d8cu: goto label_1d8c;
        case 0x1d90u: goto label_1d90;
        case 0x1d94u: goto label_1d94;
        case 0x1d98u: goto label_1d98;
        case 0x1d9cu: goto label_1d9c;
        case 0x1da0u: goto label_1da0;
        case 0x1da4u: goto label_1da4;
        case 0x1da8u: goto label_1da8;
        case 0x1dacu: goto label_1dac;
        case 0x1db0u: goto label_1db0;
        case 0x1db4u: goto label_1db4;
        case 0x1db8u: goto label_1db8;
        case 0x1dbcu: goto label_1dbc;
        case 0x1dc0u: goto label_1dc0;
        case 0x1dc4u: goto label_1dc4;
        case 0x1dc8u: goto label_1dc8;
        case 0x1dccu: goto label_1dcc;
        case 0x1dd0u: goto label_1dd0;
        case 0x1dd4u: goto label_1dd4;
        case 0x1dd8u: goto label_1dd8;
        case 0x1ddcu: goto label_1ddc;
        case 0x1de0u: goto label_1de0;
        case 0x1de4u: goto label_1de4;
        case 0x1de8u: goto label_1de8;
        case 0x1decu: goto label_1dec;
        case 0x1df0u: goto label_1df0;
        case 0x1df4u: goto label_1df4;
        case 0x1df8u: goto label_1df8;
        case 0x1dfcu: goto label_1dfc;
        case 0x1e00u: goto label_1e00;
        case 0x1e04u: goto label_1e04;
        case 0x1e08u: goto label_1e08;
        case 0x1e0cu: goto label_1e0c;
        case 0x1e10u: goto label_1e10;
        case 0x1e14u: goto label_1e14;
        case 0x1e18u: goto label_1e18;
        case 0x1e1cu: goto label_1e1c;
        case 0x1e20u: goto label_1e20;
        case 0x1e24u: goto label_1e24;
        case 0x1e28u: goto label_1e28;
        case 0x1e2cu: goto label_1e2c;
        case 0x1e30u: goto label_1e30;
        case 0x1e34u: goto label_1e34;
        case 0x1e38u: goto label_1e38;
        case 0x1e3cu: goto label_1e3c;
        case 0x1e40u: goto label_1e40;
        case 0x1e44u: goto label_1e44;
        case 0x1e48u: goto label_1e48;
        case 0x1e4cu: goto label_1e4c;
        case 0x1e50u: goto label_1e50;
        case 0x1e54u: goto label_1e54;
        case 0x1e58u: goto label_1e58;
        case 0x1e5cu: goto label_1e5c;
        case 0x1e60u: goto label_1e60;
        case 0x1e64u: goto label_1e64;
        case 0x1e68u: goto label_1e68;
        case 0x1e6cu: goto label_1e6c;
        case 0x1e70u: goto label_1e70;
        case 0x1e74u: goto label_1e74;
        case 0x1e78u: goto label_1e78;
        case 0x1e7cu: goto label_1e7c;
        case 0x1e80u: goto label_1e80;
        case 0x1e84u: goto label_1e84;
        case 0x1e88u: goto label_1e88;
        case 0x1e8cu: goto label_1e8c;
        case 0x1e90u: goto label_1e90;
        case 0x1e94u: goto label_1e94;
        case 0x1e98u: goto label_1e98;
        case 0x1e9cu: goto label_1e9c;
        case 0x1ea0u: goto label_1ea0;
        case 0x1ea4u: goto label_1ea4;
        case 0x1ea8u: goto label_1ea8;
        case 0x1eacu: goto label_1eac;
        case 0x1eb0u: goto label_1eb0;
        case 0x1eb4u: goto label_1eb4;
        case 0x1eb8u: goto label_1eb8;
        case 0x1ebcu: goto label_1ebc;
        case 0x1ec0u: goto label_1ec0;
        case 0x1ec4u: goto label_1ec4;
        case 0x1ec8u: goto label_1ec8;
        case 0x1eccu: goto label_1ecc;
        case 0x1ed0u: goto label_1ed0;
        case 0x1ed4u: goto label_1ed4;
        case 0x1ed8u: goto label_1ed8;
        case 0x1edcu: goto label_1edc;
        case 0x1ee0u: goto label_1ee0;
        case 0x1ee4u: goto label_1ee4;
        case 0x1ee8u: goto label_1ee8;
        case 0x1eecu: goto label_1eec;
        case 0x1ef0u: goto label_1ef0;
        case 0x1ef4u: goto label_1ef4;
        case 0x1ef8u: goto label_1ef8;
        case 0x1efcu: goto label_1efc;
        case 0x1f00u: goto label_1f00;
        case 0x1f04u: goto label_1f04;
        case 0x1f08u: goto label_1f08;
        case 0x1f0cu: goto label_1f0c;
        case 0x1f10u: goto label_1f10;
        case 0x1f14u: goto label_1f14;
        case 0x1f18u: goto label_1f18;
        case 0x1f1cu: goto label_1f1c;
        case 0x1f20u: goto label_1f20;
        case 0x1f24u: goto label_1f24;
        case 0x1f28u: goto label_1f28;
        case 0x1f2cu: goto label_1f2c;
        case 0x1f30u: goto label_1f30;
        case 0x1f34u: goto label_1f34;
        case 0x1f38u: goto label_1f38;
        case 0x1f3cu: goto label_1f3c;
        case 0x1f40u: goto label_1f40;
        case 0x1f44u: goto label_1f44;
        case 0x1f48u: goto label_1f48;
        case 0x1f4cu: goto label_1f4c;
        case 0x1f50u: goto label_1f50;
        case 0x1f54u: goto label_1f54;
        case 0x1f58u: goto label_1f58;
        case 0x1f5cu: goto label_1f5c;
        case 0x1f60u: goto label_1f60;
        case 0x1f64u: goto label_1f64;
        case 0x1f68u: goto label_1f68;
        case 0x1f6cu: goto label_1f6c;
        case 0x1f70u: goto label_1f70;
        case 0x1f74u: goto label_1f74;
        case 0x1f78u: goto label_1f78;
        case 0x1f7cu: goto label_1f7c;
        case 0x1f80u: goto label_1f80;
        case 0x1f84u: goto label_1f84;
        case 0x1f88u: goto label_1f88;
        case 0x1f8cu: goto label_1f8c;
        case 0x1f90u: goto label_1f90;
        case 0x1f94u: goto label_1f94;
        case 0x1f98u: goto label_1f98;
        case 0x1f9cu: goto label_1f9c;
        case 0x1fa0u: goto label_1fa0;
        case 0x1fa4u: goto label_1fa4;
        case 0x1fa8u: goto label_1fa8;
        case 0x1facu: goto label_1fac;
        case 0x1fb0u: goto label_1fb0;
        case 0x1fb4u: goto label_1fb4;
        case 0x1fb8u: goto label_1fb8;
        case 0x1fbcu: goto label_1fbc;
        case 0x1fc0u: goto label_1fc0;
        case 0x1fc4u: goto label_1fc4;
        case 0x1fc8u: goto label_1fc8;
        case 0x1fccu: goto label_1fcc;
        case 0x1fd0u: goto label_1fd0;
        case 0x1fd4u: goto label_1fd4;
        case 0x1fd8u: goto label_1fd8;
        case 0x1fdcu: goto label_1fdc;
        case 0x1fe0u: goto label_1fe0;
        case 0x1fe4u: goto label_1fe4;
        case 0x1fe8u: goto label_1fe8;
        case 0x1fecu: goto label_1fec;
        case 0x1ff0u: goto label_1ff0;
        case 0x1ff4u: goto label_1ff4;
        case 0x1ff8u: goto label_1ff8;
        case 0x1ffcu: goto label_1ffc;
        case 0x2000u: goto label_2000;
        case 0x2004u: goto label_2004;
        case 0x2008u: goto label_2008;
        case 0x200cu: goto label_200c;
        case 0x2010u: goto label_2010;
        case 0x2014u: goto label_2014;
        case 0x2018u: goto label_2018;
        case 0x201cu: goto label_201c;
        case 0x2020u: goto label_2020;
        case 0x2024u: goto label_2024;
        case 0x2028u: goto label_2028;
        case 0x202cu: goto label_202c;
        case 0x2030u: goto label_2030;
        case 0x2034u: goto label_2034;
        case 0x2038u: goto label_2038;
        case 0x203cu: goto label_203c;
        case 0x2040u: goto label_2040;
        case 0x2044u: goto label_2044;
        case 0x2048u: goto label_2048;
        case 0x204cu: goto label_204c;
        case 0x2050u: goto label_2050;
        case 0x2054u: goto label_2054;
        case 0x2058u: goto label_2058;
        case 0x205cu: goto label_205c;
        case 0x2060u: goto label_2060;
        case 0x2064u: goto label_2064;
        case 0x2068u: goto label_2068;
        case 0x206cu: goto label_206c;
        case 0x2070u: goto label_2070;
        case 0x2074u: goto label_2074;
        case 0x2078u: goto label_2078;
        case 0x207cu: goto label_207c;
        case 0x2080u: goto label_2080;
        case 0x2084u: goto label_2084;
        case 0x2088u: goto label_2088;
        case 0x208cu: goto label_208c;
        case 0x2090u: goto label_2090;
        case 0x2094u: goto label_2094;
        case 0x2098u: goto label_2098;
        case 0x209cu: goto label_209c;
        case 0x20a0u: goto label_20a0;
        case 0x20a4u: goto label_20a4;
        case 0x20a8u: goto label_20a8;
        case 0x20acu: goto label_20ac;
        case 0x20b0u: goto label_20b0;
        case 0x20b4u: goto label_20b4;
        case 0x20b8u: goto label_20b8;
        case 0x20bcu: goto label_20bc;
        case 0x20c0u: goto label_20c0;
        case 0x20c4u: goto label_20c4;
        case 0x20c8u: goto label_20c8;
        case 0x20ccu: goto label_20cc;
        case 0x20d0u: goto label_20d0;
        case 0x20d4u: goto label_20d4;
        case 0x20d8u: goto label_20d8;
        case 0x20dcu: goto label_20dc;
        case 0x20e0u: goto label_20e0;
        case 0x20e4u: goto label_20e4;
        case 0x20e8u: goto label_20e8;
        case 0x20ecu: goto label_20ec;
        case 0x20f0u: goto label_20f0;
        case 0x20f4u: goto label_20f4;
        case 0x20f8u: goto label_20f8;
        case 0x20fcu: goto label_20fc;
        case 0x2100u: goto label_2100;
        case 0x2104u: goto label_2104;
        case 0x2108u: goto label_2108;
        case 0x210cu: goto label_210c;
        case 0x2110u: goto label_2110;
        case 0x2114u: goto label_2114;
        case 0x2118u: goto label_2118;
        case 0x211cu: goto label_211c;
        case 0x2120u: goto label_2120;
        case 0x2124u: goto label_2124;
        case 0x2128u: goto label_2128;
        case 0x212cu: goto label_212c;
        case 0x2130u: goto label_2130;
        case 0x2134u: goto label_2134;
        case 0x2138u: goto label_2138;
        case 0x213cu: goto label_213c;
        case 0x2140u: goto label_2140;
        case 0x2144u: goto label_2144;
        case 0x2148u: goto label_2148;
        case 0x214cu: goto label_214c;
        case 0x2150u: goto label_2150;
        case 0x2154u: goto label_2154;
        case 0x2158u: goto label_2158;
        case 0x215cu: goto label_215c;
        case 0x2160u: goto label_2160;
        case 0x2164u: goto label_2164;
        case 0x2168u: goto label_2168;
        case 0x216cu: goto label_216c;
        case 0x2170u: goto label_2170;
        case 0x2174u: goto label_2174;
        case 0x2178u: goto label_2178;
        case 0x217cu: goto label_217c;
        case 0x2180u: goto label_2180;
        case 0x2184u: goto label_2184;
        case 0x2188u: goto label_2188;
        case 0x218cu: goto label_218c;
        case 0x2190u: goto label_2190;
        case 0x2194u: goto label_2194;
        case 0x2198u: goto label_2198;
        case 0x219cu: goto label_219c;
        case 0x21a0u: goto label_21a0;
        case 0x21a4u: goto label_21a4;
        case 0x21a8u: goto label_21a8;
        case 0x21acu: goto label_21ac;
        case 0x21b0u: goto label_21b0;
        case 0x21b4u: goto label_21b4;
        case 0x21b8u: goto label_21b8;
        case 0x21bcu: goto label_21bc;
        case 0x21c0u: goto label_21c0;
        case 0x21c4u: goto label_21c4;
        case 0x21c8u: goto label_21c8;
        case 0x21ccu: goto label_21cc;
        case 0x21d0u: goto label_21d0;
        case 0x21d4u: goto label_21d4;
        case 0x21d8u: goto label_21d8;
        case 0x21dcu: goto label_21dc;
        case 0x21e0u: goto label_21e0;
        case 0x21e4u: goto label_21e4;
        case 0x21e8u: goto label_21e8;
        case 0x21ecu: goto label_21ec;
        case 0x21f0u: goto label_21f0;
        case 0x21f4u: goto label_21f4;
        case 0x21f8u: goto label_21f8;
        case 0x21fcu: goto label_21fc;
        case 0x2200u: goto label_2200;
        case 0x2204u: goto label_2204;
        case 0x2208u: goto label_2208;
        case 0x220cu: goto label_220c;
        case 0x2210u: goto label_2210;
        case 0x2214u: goto label_2214;
        case 0x2218u: goto label_2218;
        case 0x221cu: goto label_221c;
        case 0x2220u: goto label_2220;
        case 0x2224u: goto label_2224;
        case 0x2228u: goto label_2228;
        case 0x222cu: goto label_222c;
        case 0x2230u: goto label_2230;
        case 0x2234u: goto label_2234;
        case 0x2238u: goto label_2238;
        case 0x223cu: goto label_223c;
        case 0x2240u: goto label_2240;
        case 0x2244u: goto label_2244;
        case 0x2248u: goto label_2248;
        case 0x224cu: goto label_224c;
        case 0x2250u: goto label_2250;
        case 0x2254u: goto label_2254;
        case 0x2258u: goto label_2258;
        case 0x225cu: goto label_225c;
        case 0x2260u: goto label_2260;
        case 0x2264u: goto label_2264;
        case 0x2268u: goto label_2268;
        case 0x226cu: goto label_226c;
        case 0x2270u: goto label_2270;
        case 0x2274u: goto label_2274;
        case 0x2278u: goto label_2278;
        case 0x227cu: goto label_227c;
        case 0x2280u: goto label_2280;
        case 0x2284u: goto label_2284;
        case 0x2288u: goto label_2288;
        case 0x228cu: goto label_228c;
        case 0x2290u: goto label_2290;
        case 0x2294u: goto label_2294;
        case 0x2298u: goto label_2298;
        case 0x229cu: goto label_229c;
        case 0x22a0u: goto label_22a0;
        case 0x22a4u: goto label_22a4;
        case 0x22a8u: goto label_22a8;
        case 0x22acu: goto label_22ac;
        case 0x22b0u: goto label_22b0;
        case 0x22b4u: goto label_22b4;
        case 0x22b8u: goto label_22b8;
        case 0x22bcu: goto label_22bc;
        case 0x22c0u: goto label_22c0;
        case 0x22c4u: goto label_22c4;
        case 0x22c8u: goto label_22c8;
        case 0x22ccu: goto label_22cc;
        case 0x22d0u: goto label_22d0;
        case 0x22d4u: goto label_22d4;
        case 0x22d8u: goto label_22d8;
        case 0x22dcu: goto label_22dc;
        case 0x22e0u: goto label_22e0;
        case 0x22e4u: goto label_22e4;
        case 0x22e8u: goto label_22e8;
        case 0x22ecu: goto label_22ec;
        case 0x22f0u: goto label_22f0;
        case 0x22f4u: goto label_22f4;
        case 0x22f8u: goto label_22f8;
        case 0x22fcu: goto label_22fc;
        case 0x2300u: goto label_2300;
        case 0x2304u: goto label_2304;
        case 0x2308u: goto label_2308;
        case 0x230cu: goto label_230c;
        case 0x2310u: goto label_2310;
        case 0x2314u: goto label_2314;
        case 0x2318u: goto label_2318;
        case 0x231cu: goto label_231c;
        case 0x2320u: goto label_2320;
        case 0x2324u: goto label_2324;
        case 0x2328u: goto label_2328;
        case 0x232cu: goto label_232c;
        case 0x2330u: goto label_2330;
        case 0x2334u: goto label_2334;
        case 0x2338u: goto label_2338;
        case 0x233cu: goto label_233c;
        case 0x2340u: goto label_2340;
        case 0x2344u: goto label_2344;
        case 0x2348u: goto label_2348;
        case 0x234cu: goto label_234c;
        case 0x2350u: goto label_2350;
        case 0x2354u: goto label_2354;
        case 0x2358u: goto label_2358;
        case 0x235cu: goto label_235c;
        case 0x2360u: goto label_2360;
        case 0x2364u: goto label_2364;
        case 0x2368u: goto label_2368;
        case 0x236cu: goto label_236c;
        case 0x2370u: goto label_2370;
        case 0x2374u: goto label_2374;
        case 0x2378u: goto label_2378;
        case 0x237cu: goto label_237c;
        case 0x2380u: goto label_2380;
        case 0x2384u: goto label_2384;
        case 0x2388u: goto label_2388;
        case 0x238cu: goto label_238c;
        case 0x2390u: goto label_2390;
        case 0x2394u: goto label_2394;
        case 0x2398u: goto label_2398;
        case 0x239cu: goto label_239c;
        case 0x23a0u: goto label_23a0;
        case 0x23a4u: goto label_23a4;
        case 0x23a8u: goto label_23a8;
        case 0x23acu: goto label_23ac;
        case 0x23b0u: goto label_23b0;
        case 0x23b4u: goto label_23b4;
        case 0x23b8u: goto label_23b8;
        case 0x23bcu: goto label_23bc;
        case 0x23c0u: goto label_23c0;
        case 0x23c4u: goto label_23c4;
        case 0x23c8u: goto label_23c8;
        case 0x23ccu: goto label_23cc;
        case 0x23d0u: goto label_23d0;
        case 0x23d4u: goto label_23d4;
        case 0x23d8u: goto label_23d8;
        case 0x23dcu: goto label_23dc;
        case 0x23e0u: goto label_23e0;
        case 0x23e4u: goto label_23e4;
        case 0x23e8u: goto label_23e8;
        case 0x23ecu: goto label_23ec;
        case 0x23f0u: goto label_23f0;
        case 0x23f4u: goto label_23f4;
        case 0x23f8u: goto label_23f8;
        case 0x23fcu: goto label_23fc;
        case 0x2400u: goto label_2400;
        case 0x2404u: goto label_2404;
        case 0x2408u: goto label_2408;
        case 0x240cu: goto label_240c;
        case 0x2410u: goto label_2410;
        case 0x2414u: goto label_2414;
        case 0x2418u: goto label_2418;
        case 0x241cu: goto label_241c;
        case 0x2420u: goto label_2420;
        case 0x2424u: goto label_2424;
        case 0x2428u: goto label_2428;
        case 0x242cu: goto label_242c;
        case 0x2430u: goto label_2430;
        case 0x2434u: goto label_2434;
        case 0x2438u: goto label_2438;
        case 0x243cu: goto label_243c;
        case 0x2440u: goto label_2440;
        case 0x2444u: goto label_2444;
        case 0x2448u: goto label_2448;
        case 0x244cu: goto label_244c;
        case 0x2450u: goto label_2450;
        case 0x2454u: goto label_2454;
        case 0x2458u: goto label_2458;
        case 0x245cu: goto label_245c;
        case 0x2460u: goto label_2460;
        case 0x2464u: goto label_2464;
        case 0x2468u: goto label_2468;
        case 0x246cu: goto label_246c;
        case 0x2470u: goto label_2470;
        case 0x2474u: goto label_2474;
        case 0x2478u: goto label_2478;
        case 0x247cu: goto label_247c;
        case 0x2480u: goto label_2480;
        case 0x2484u: goto label_2484;
        case 0x2488u: goto label_2488;
        case 0x248cu: goto label_248c;
        case 0x2490u: goto label_2490;
        case 0x2494u: goto label_2494;
        case 0x2498u: goto label_2498;
        case 0x249cu: goto label_249c;
        case 0x24a0u: goto label_24a0;
        case 0x24a4u: goto label_24a4;
        case 0x24a8u: goto label_24a8;
        case 0x24acu: goto label_24ac;
        case 0x24b0u: goto label_24b0;
        case 0x24b4u: goto label_24b4;
        case 0x24b8u: goto label_24b8;
        case 0x24bcu: goto label_24bc;
        case 0x24c0u: goto label_24c0;
        case 0x24c4u: goto label_24c4;
        case 0x24c8u: goto label_24c8;
        case 0x24ccu: goto label_24cc;
        case 0x24d0u: goto label_24d0;
        case 0x24d4u: goto label_24d4;
        case 0x24d8u: goto label_24d8;
        case 0x24dcu: goto label_24dc;
        case 0x24e0u: goto label_24e0;
        case 0x24e4u: goto label_24e4;
        case 0x24e8u: goto label_24e8;
        case 0x24ecu: goto label_24ec;
        case 0x24f0u: goto label_24f0;
        case 0x24f4u: goto label_24f4;
        case 0x24f8u: goto label_24f8;
        case 0x24fcu: goto label_24fc;
        case 0x2500u: goto label_2500;
        case 0x2504u: goto label_2504;
        case 0x2508u: goto label_2508;
        case 0x250cu: goto label_250c;
        case 0x2510u: goto label_2510;
        case 0x2514u: goto label_2514;
        case 0x2518u: goto label_2518;
        case 0x251cu: goto label_251c;
        case 0x2520u: goto label_2520;
        case 0x2524u: goto label_2524;
        case 0x2528u: goto label_2528;
        case 0x252cu: goto label_252c;
        case 0x2530u: goto label_2530;
        case 0x2534u: goto label_2534;
        case 0x2538u: goto label_2538;
        case 0x253cu: goto label_253c;
        case 0x2540u: goto label_2540;
        case 0x2544u: goto label_2544;
        case 0x2548u: goto label_2548;
        case 0x254cu: goto label_254c;
        case 0x2550u: goto label_2550;
        case 0x2554u: goto label_2554;
        case 0x2558u: goto label_2558;
        case 0x255cu: goto label_255c;
        case 0x2560u: goto label_2560;
        case 0x2564u: goto label_2564;
        case 0x2568u: goto label_2568;
        case 0x256cu: goto label_256c;
        case 0x2570u: goto label_2570;
        case 0x2574u: goto label_2574;
        case 0x2578u: goto label_2578;
        case 0x257cu: goto label_257c;
        case 0x2580u: goto label_2580;
        case 0x2584u: goto label_2584;
        case 0x2588u: goto label_2588;
        case 0x258cu: goto label_258c;
        case 0x2590u: goto label_2590;
        case 0x2594u: goto label_2594;
        case 0x2598u: goto label_2598;
        case 0x259cu: goto label_259c;
        case 0x25a0u: goto label_25a0;
        case 0x25a4u: goto label_25a4;
        case 0x25a8u: goto label_25a8;
        case 0x25acu: goto label_25ac;
        case 0x25b0u: goto label_25b0;
        case 0x25b4u: goto label_25b4;
        case 0x25b8u: goto label_25b8;
        case 0x25bcu: goto label_25bc;
        case 0x25c0u: goto label_25c0;
        case 0x25c4u: goto label_25c4;
        case 0x25c8u: goto label_25c8;
        case 0x25ccu: goto label_25cc;
        case 0x25d0u: goto label_25d0;
        case 0x25d4u: goto label_25d4;
        case 0x25d8u: goto label_25d8;
        case 0x25dcu: goto label_25dc;
        case 0x25e0u: goto label_25e0;
        case 0x25e4u: goto label_25e4;
        case 0x25e8u: goto label_25e8;
        case 0x25ecu: goto label_25ec;
        case 0x25f0u: goto label_25f0;
        case 0x25f4u: goto label_25f4;
        case 0x25f8u: goto label_25f8;
        case 0x25fcu: goto label_25fc;
        case 0x2600u: goto label_2600;
        case 0x2604u: goto label_2604;
        case 0x2608u: goto label_2608;
        case 0x260cu: goto label_260c;
        case 0x2610u: goto label_2610;
        case 0x2614u: goto label_2614;
        case 0x2618u: goto label_2618;
        case 0x261cu: goto label_261c;
        case 0x2620u: goto label_2620;
        case 0x2624u: goto label_2624;
        case 0x2628u: goto label_2628;
        case 0x262cu: goto label_262c;
        case 0x2630u: goto label_2630;
        case 0x2634u: goto label_2634;
        case 0x2638u: goto label_2638;
        case 0x263cu: goto label_263c;
        case 0x2640u: goto label_2640;
        case 0x2644u: goto label_2644;
        case 0x2648u: goto label_2648;
        case 0x264cu: goto label_264c;
        case 0x2650u: goto label_2650;
        case 0x2654u: goto label_2654;
        case 0x2658u: goto label_2658;
        case 0x265cu: goto label_265c;
        case 0x2660u: goto label_2660;
        case 0x2664u: goto label_2664;
        case 0x2668u: goto label_2668;
        case 0x266cu: goto label_266c;
        case 0x2670u: goto label_2670;
        case 0x2674u: goto label_2674;
        case 0x2678u: goto label_2678;
        case 0x267cu: goto label_267c;
        case 0x2680u: goto label_2680;
        case 0x2684u: goto label_2684;
        case 0x2688u: goto label_2688;
        case 0x268cu: goto label_268c;
        case 0x2690u: goto label_2690;
        case 0x2694u: goto label_2694;
        case 0x2698u: goto label_2698;
        case 0x269cu: goto label_269c;
        case 0x26a0u: goto label_26a0;
        case 0x26a4u: goto label_26a4;
        case 0x26a8u: goto label_26a8;
        case 0x26acu: goto label_26ac;
        case 0x26b0u: goto label_26b0;
        case 0x26b4u: goto label_26b4;
        case 0x26b8u: goto label_26b8;
        case 0x26bcu: goto label_26bc;
        case 0x26c0u: goto label_26c0;
        case 0x26c4u: goto label_26c4;
        case 0x26c8u: goto label_26c8;
        case 0x26ccu: goto label_26cc;
        case 0x26d0u: goto label_26d0;
        case 0x26d4u: goto label_26d4;
        case 0x26d8u: goto label_26d8;
        case 0x26dcu: goto label_26dc;
        case 0x26e0u: goto label_26e0;
        case 0x26e4u: goto label_26e4;
        case 0x26e8u: goto label_26e8;
        case 0x26ecu: goto label_26ec;
        case 0x26f0u: goto label_26f0;
        case 0x26f4u: goto label_26f4;
        case 0x26f8u: goto label_26f8;
        case 0x26fcu: goto label_26fc;
        case 0x2700u: goto label_2700;
        case 0x2704u: goto label_2704;
        case 0x2708u: goto label_2708;
        case 0x270cu: goto label_270c;
        case 0x2710u: goto label_2710;
        case 0x2714u: goto label_2714;
        case 0x2718u: goto label_2718;
        case 0x271cu: goto label_271c;
        case 0x2720u: goto label_2720;
        case 0x2724u: goto label_2724;
        case 0x2728u: goto label_2728;
        case 0x272cu: goto label_272c;
        case 0x2730u: goto label_2730;
        case 0x2734u: goto label_2734;
        case 0x2738u: goto label_2738;
        case 0x273cu: goto label_273c;
        case 0x2740u: goto label_2740;
        case 0x2744u: goto label_2744;
        case 0x2748u: goto label_2748;
        case 0x274cu: goto label_274c;
        case 0x2750u: goto label_2750;
        case 0x2754u: goto label_2754;
        case 0x2758u: goto label_2758;
        case 0x275cu: goto label_275c;
        case 0x2760u: goto label_2760;
        case 0x2764u: goto label_2764;
        case 0x2768u: goto label_2768;
        case 0x276cu: goto label_276c;
        case 0x2770u: goto label_2770;
        case 0x2774u: goto label_2774;
        case 0x2778u: goto label_2778;
        case 0x277cu: goto label_277c;
        case 0x2780u: goto label_2780;
        case 0x2784u: goto label_2784;
        case 0x2788u: goto label_2788;
        case 0x278cu: goto label_278c;
        case 0x2790u: goto label_2790;
        case 0x2794u: goto label_2794;
        case 0x2798u: goto label_2798;
        case 0x279cu: goto label_279c;
        case 0x27a0u: goto label_27a0;
        case 0x27a4u: goto label_27a4;
        case 0x27a8u: goto label_27a8;
        case 0x27acu: goto label_27ac;
        case 0x27b0u: goto label_27b0;
        case 0x27b4u: goto label_27b4;
        case 0x27b8u: goto label_27b8;
        case 0x27bcu: goto label_27bc;
        case 0x27c0u: goto label_27c0;
        case 0x27c4u: goto label_27c4;
        case 0x27c8u: goto label_27c8;
        case 0x27ccu: goto label_27cc;
        case 0x27d0u: goto label_27d0;
        case 0x27d4u: goto label_27d4;
        case 0x27d8u: goto label_27d8;
        case 0x27dcu: goto label_27dc;
        case 0x27e0u: goto label_27e0;
        case 0x27e4u: goto label_27e4;
        case 0x27e8u: goto label_27e8;
        case 0x27ecu: goto label_27ec;
        case 0x27f0u: goto label_27f0;
        case 0x27f4u: goto label_27f4;
        case 0x27f8u: goto label_27f8;
        case 0x27fcu: goto label_27fc;
        case 0x2800u: goto label_2800;
        case 0x2804u: goto label_2804;
        case 0x2808u: goto label_2808;
        case 0x280cu: goto label_280c;
        case 0x2810u: goto label_2810;
        case 0x2814u: goto label_2814;
        case 0x2818u: goto label_2818;
        case 0x281cu: goto label_281c;
        case 0x2820u: goto label_2820;
        case 0x2824u: goto label_2824;
        case 0x2828u: goto label_2828;
        case 0x282cu: goto label_282c;
        case 0x2830u: goto label_2830;
        case 0x2834u: goto label_2834;
        case 0x2838u: goto label_2838;
        case 0x283cu: goto label_283c;
        case 0x2840u: goto label_2840;
        case 0x2844u: goto label_2844;
        case 0x2848u: goto label_2848;
        case 0x284cu: goto label_284c;
        case 0x2850u: goto label_2850;
        case 0x2854u: goto label_2854;
        case 0x2858u: goto label_2858;
        case 0x285cu: goto label_285c;
        case 0x2860u: goto label_2860;
        case 0x2864u: goto label_2864;
        case 0x2868u: goto label_2868;
        case 0x286cu: goto label_286c;
        case 0x2870u: goto label_2870;
        case 0x2874u: goto label_2874;
        case 0x2878u: goto label_2878;
        case 0x287cu: goto label_287c;
        case 0x2880u: goto label_2880;
        case 0x2884u: goto label_2884;
        case 0x2888u: goto label_2888;
        case 0x288cu: goto label_288c;
        case 0x2890u: goto label_2890;
        case 0x2894u: goto label_2894;
        case 0x2898u: goto label_2898;
        case 0x289cu: goto label_289c;
        case 0x28a0u: goto label_28a0;
        case 0x28a4u: goto label_28a4;
        case 0x28a8u: goto label_28a8;
        case 0x28acu: goto label_28ac;
        case 0x28b0u: goto label_28b0;
        case 0x28b4u: goto label_28b4;
        case 0x28b8u: goto label_28b8;
        case 0x28bcu: goto label_28bc;
        case 0x28c0u: goto label_28c0;
        case 0x28c4u: goto label_28c4;
        case 0x28c8u: goto label_28c8;
        case 0x28ccu: goto label_28cc;
        case 0x28d0u: goto label_28d0;
        case 0x28d4u: goto label_28d4;
        case 0x28d8u: goto label_28d8;
        case 0x28dcu: goto label_28dc;
        case 0x28e0u: goto label_28e0;
        case 0x28e4u: goto label_28e4;
        case 0x28e8u: goto label_28e8;
        case 0x28ecu: goto label_28ec;
        case 0x28f0u: goto label_28f0;
        case 0x28f4u: goto label_28f4;
        case 0x28f8u: goto label_28f8;
        case 0x28fcu: goto label_28fc;
        case 0x2900u: goto label_2900;
        case 0x2904u: goto label_2904;
        case 0x2908u: goto label_2908;
        case 0x290cu: goto label_290c;
        case 0x2910u: goto label_2910;
        case 0x2914u: goto label_2914;
        case 0x2918u: goto label_2918;
        case 0x291cu: goto label_291c;
        case 0x2920u: goto label_2920;
        case 0x2924u: goto label_2924;
        case 0x2928u: goto label_2928;
        case 0x292cu: goto label_292c;
        case 0x2930u: goto label_2930;
        case 0x2934u: goto label_2934;
        case 0x2938u: goto label_2938;
        case 0x293cu: goto label_293c;
        case 0x2940u: goto label_2940;
        case 0x2944u: goto label_2944;
        case 0x2948u: goto label_2948;
        case 0x294cu: goto label_294c;
        case 0x2950u: goto label_2950;
        case 0x2954u: goto label_2954;
        case 0x2958u: goto label_2958;
        case 0x295cu: goto label_295c;
        case 0x2960u: goto label_2960;
        case 0x2964u: goto label_2964;
        case 0x2968u: goto label_2968;
        case 0x296cu: goto label_296c;
        case 0x2970u: goto label_2970;
        case 0x2974u: goto label_2974;
        case 0x2978u: goto label_2978;
        case 0x297cu: goto label_297c;
        case 0x2980u: goto label_2980;
        case 0x2984u: goto label_2984;
        case 0x2988u: goto label_2988;
        case 0x298cu: goto label_298c;
        case 0x2990u: goto label_2990;
        case 0x2994u: goto label_2994;
        case 0x2998u: goto label_2998;
        case 0x299cu: goto label_299c;
        case 0x29a0u: goto label_29a0;
        case 0x29a4u: goto label_29a4;
        case 0x29a8u: goto label_29a8;
        case 0x29acu: goto label_29ac;
        case 0x29b0u: goto label_29b0;
        case 0x29b4u: goto label_29b4;
        case 0x29b8u: goto label_29b8;
        case 0x29bcu: goto label_29bc;
        case 0x29c0u: goto label_29c0;
        case 0x29c4u: goto label_29c4;
        case 0x29c8u: goto label_29c8;
        case 0x29ccu: goto label_29cc;
        case 0x29d0u: goto label_29d0;
        case 0x29d4u: goto label_29d4;
        case 0x29d8u: goto label_29d8;
        case 0x29dcu: goto label_29dc;
        case 0x29e0u: goto label_29e0;
        case 0x29e4u: goto label_29e4;
        case 0x29e8u: goto label_29e8;
        case 0x29ecu: goto label_29ec;
        case 0x29f0u: goto label_29f0;
        case 0x29f4u: goto label_29f4;
        case 0x29f8u: goto label_29f8;
        case 0x29fcu: goto label_29fc;
        case 0x2a00u: goto label_2a00;
        case 0x2a04u: goto label_2a04;
        case 0x2a08u: goto label_2a08;
        case 0x2a0cu: goto label_2a0c;
        case 0x2a10u: goto label_2a10;
        case 0x2a14u: goto label_2a14;
        case 0x2a18u: goto label_2a18;
        case 0x2a1cu: goto label_2a1c;
        case 0x2a20u: goto label_2a20;
        case 0x2a24u: goto label_2a24;
        case 0x2a28u: goto label_2a28;
        case 0x2a2cu: goto label_2a2c;
        case 0x2a30u: goto label_2a30;
        case 0x2a34u: goto label_2a34;
        case 0x2a38u: goto label_2a38;
        case 0x2a3cu: goto label_2a3c;
        case 0x2a40u: goto label_2a40;
        case 0x2a44u: goto label_2a44;
        case 0x2a48u: goto label_2a48;
        case 0x2a4cu: goto label_2a4c;
        case 0x2a50u: goto label_2a50;
        case 0x2a54u: goto label_2a54;
        case 0x2a58u: goto label_2a58;
        case 0x2a5cu: goto label_2a5c;
        case 0x2a60u: goto label_2a60;
        case 0x2a64u: goto label_2a64;
        case 0x2a68u: goto label_2a68;
        case 0x2a6cu: goto label_2a6c;
        case 0x2a70u: goto label_2a70;
        case 0x2a74u: goto label_2a74;
        case 0x2a78u: goto label_2a78;
        case 0x2a7cu: goto label_2a7c;
        case 0x2a80u: goto label_2a80;
        case 0x2a84u: goto label_2a84;
        case 0x2a88u: goto label_2a88;
        case 0x2a8cu: goto label_2a8c;
        case 0x2a90u: goto label_2a90;
        case 0x2a94u: goto label_2a94;
        case 0x2a98u: goto label_2a98;
        case 0x2a9cu: goto label_2a9c;
        case 0x2aa0u: goto label_2aa0;
        case 0x2aa4u: goto label_2aa4;
        case 0x2aa8u: goto label_2aa8;
        case 0x2aacu: goto label_2aac;
        case 0x2ab0u: goto label_2ab0;
        case 0x2ab4u: goto label_2ab4;
        case 0x2ab8u: goto label_2ab8;
        case 0x2abcu: goto label_2abc;
        case 0x2ac0u: goto label_2ac0;
        case 0x2ac4u: goto label_2ac4;
        case 0x2ac8u: goto label_2ac8;
        case 0x2accu: goto label_2acc;
        case 0x2ad0u: goto label_2ad0;
        case 0x2ad4u: goto label_2ad4;
        case 0x2ad8u: goto label_2ad8;
        case 0x2adcu: goto label_2adc;
        case 0x2ae0u: goto label_2ae0;
        case 0x2ae4u: goto label_2ae4;
        case 0x2ae8u: goto label_2ae8;
        case 0x2aecu: goto label_2aec;
        case 0x2af0u: goto label_2af0;
        case 0x2af4u: goto label_2af4;
        case 0x2af8u: goto label_2af8;
        case 0x2afcu: goto label_2afc;
        case 0x2b00u: goto label_2b00;
        case 0x2b04u: goto label_2b04;
        case 0x2b08u: goto label_2b08;
        case 0x2b0cu: goto label_2b0c;
        case 0x2b10u: goto label_2b10;
        case 0x2b14u: goto label_2b14;
        case 0x2b18u: goto label_2b18;
        case 0x2b1cu: goto label_2b1c;
        case 0x2b20u: goto label_2b20;
        case 0x2b24u: goto label_2b24;
        case 0x2b28u: goto label_2b28;
        case 0x2b2cu: goto label_2b2c;
        case 0x2b30u: goto label_2b30;
        case 0x2b34u: goto label_2b34;
        case 0x2b38u: goto label_2b38;
        case 0x2b3cu: goto label_2b3c;
        case 0x2b40u: goto label_2b40;
        case 0x2b44u: goto label_2b44;
        case 0x2b48u: goto label_2b48;
        case 0x2b4cu: goto label_2b4c;
        case 0x2b50u: goto label_2b50;
        case 0x2b54u: goto label_2b54;
        case 0x2b58u: goto label_2b58;
        case 0x2b5cu: goto label_2b5c;
        case 0x2b60u: goto label_2b60;
        case 0x2b64u: goto label_2b64;
        case 0x2b68u: goto label_2b68;
        case 0x2b6cu: goto label_2b6c;
        case 0x2b70u: goto label_2b70;
        case 0x2b74u: goto label_2b74;
        case 0x2b78u: goto label_2b78;
        case 0x2b7cu: goto label_2b7c;
        case 0x2b80u: goto label_2b80;
        case 0x2b84u: goto label_2b84;
        case 0x2b88u: goto label_2b88;
        case 0x2b8cu: goto label_2b8c;
        case 0x2b90u: goto label_2b90;
        case 0x2b94u: goto label_2b94;
        case 0x2b98u: goto label_2b98;
        case 0x2b9cu: goto label_2b9c;
        case 0x2ba0u: goto label_2ba0;
        case 0x2ba4u: goto label_2ba4;
        case 0x2ba8u: goto label_2ba8;
        case 0x2bacu: goto label_2bac;
        case 0x2bb0u: goto label_2bb0;
        case 0x2bb4u: goto label_2bb4;
        case 0x2bb8u: goto label_2bb8;
        case 0x2bbcu: goto label_2bbc;
        case 0x2bc0u: goto label_2bc0;
        case 0x2bc4u: goto label_2bc4;
        case 0x2bc8u: goto label_2bc8;
        case 0x2bccu: goto label_2bcc;
        case 0x2bd0u: goto label_2bd0;
        case 0x2bd4u: goto label_2bd4;
        case 0x2bd8u: goto label_2bd8;
        case 0x2bdcu: goto label_2bdc;
        case 0x2be0u: goto label_2be0;
        case 0x2be4u: goto label_2be4;
        case 0x2be8u: goto label_2be8;
        case 0x2becu: goto label_2bec;
        case 0x2bf0u: goto label_2bf0;
        case 0x2bf4u: goto label_2bf4;
        case 0x2bf8u: goto label_2bf8;
        case 0x2bfcu: goto label_2bfc;
        case 0x2c00u: goto label_2c00;
        case 0x2c04u: goto label_2c04;
        case 0x2c08u: goto label_2c08;
        case 0x2c0cu: goto label_2c0c;
        case 0x2c10u: goto label_2c10;
        case 0x2c14u: goto label_2c14;
        case 0x2c18u: goto label_2c18;
        case 0x2c1cu: goto label_2c1c;
        case 0x2c20u: goto label_2c20;
        case 0x2c24u: goto label_2c24;
        case 0x2c28u: goto label_2c28;
        case 0x2c2cu: goto label_2c2c;
        case 0x2c30u: goto label_2c30;
        case 0x2c34u: goto label_2c34;
        case 0x2c38u: goto label_2c38;
        case 0x2c3cu: goto label_2c3c;
        case 0x2c40u: goto label_2c40;
        case 0x2c44u: goto label_2c44;
        case 0x2c48u: goto label_2c48;
        case 0x2c4cu: goto label_2c4c;
        case 0x2c50u: goto label_2c50;
        case 0x2c54u: goto label_2c54;
        case 0x2c58u: goto label_2c58;
        case 0x2c5cu: goto label_2c5c;
        case 0x2c60u: goto label_2c60;
        case 0x2c64u: goto label_2c64;
        case 0x2c68u: goto label_2c68;
        case 0x2c6cu: goto label_2c6c;
        case 0x2c70u: goto label_2c70;
        case 0x2c74u: goto label_2c74;
        case 0x2c78u: goto label_2c78;
        case 0x2c7cu: goto label_2c7c;
        case 0x2c80u: goto label_2c80;
        case 0x2c84u: goto label_2c84;
        case 0x2c88u: goto label_2c88;
        case 0x2c8cu: goto label_2c8c;
        case 0x2c90u: goto label_2c90;
        case 0x2c94u: goto label_2c94;
        case 0x2c98u: goto label_2c98;
        case 0x2c9cu: goto label_2c9c;
        case 0x2ca0u: goto label_2ca0;
        case 0x2ca4u: goto label_2ca4;
        case 0x2ca8u: goto label_2ca8;
        case 0x2cacu: goto label_2cac;
        case 0x2cb0u: goto label_2cb0;
        case 0x2cb4u: goto label_2cb4;
        case 0x2cb8u: goto label_2cb8;
        case 0x2cbcu: goto label_2cbc;
        case 0x2cc0u: goto label_2cc0;
        case 0x2cc4u: goto label_2cc4;
        case 0x2cc8u: goto label_2cc8;
        case 0x2cccu: goto label_2ccc;
        case 0x2cd0u: goto label_2cd0;
        case 0x2cd4u: goto label_2cd4;
        case 0x2cd8u: goto label_2cd8;
        case 0x2cdcu: goto label_2cdc;
        case 0x2ce0u: goto label_2ce0;
        case 0x2ce4u: goto label_2ce4;
        case 0x2ce8u: goto label_2ce8;
        case 0x2cecu: goto label_2cec;
        case 0x2cf0u: goto label_2cf0;
        case 0x2cf4u: goto label_2cf4;
        case 0x2cf8u: goto label_2cf8;
        case 0x2cfcu: goto label_2cfc;
        case 0x2d00u: goto label_2d00;
        case 0x2d04u: goto label_2d04;
        case 0x2d08u: goto label_2d08;
        case 0x2d0cu: goto label_2d0c;
        case 0x2d10u: goto label_2d10;
        case 0x2d14u: goto label_2d14;
        case 0x2d18u: goto label_2d18;
        case 0x2d1cu: goto label_2d1c;
        case 0x2d20u: goto label_2d20;
        case 0x2d24u: goto label_2d24;
        case 0x2d28u: goto label_2d28;
        case 0x2d2cu: goto label_2d2c;
        case 0x2d30u: goto label_2d30;
        case 0x2d34u: goto label_2d34;
        case 0x2d38u: goto label_2d38;
        case 0x2d3cu: goto label_2d3c;
        case 0x2d40u: goto label_2d40;
        case 0x2d44u: goto label_2d44;
        case 0x2d48u: goto label_2d48;
        case 0x2d4cu: goto label_2d4c;
        case 0x2d50u: goto label_2d50;
        case 0x2d54u: goto label_2d54;
        case 0x2d58u: goto label_2d58;
        case 0x2d5cu: goto label_2d5c;
        case 0x2d60u: goto label_2d60;
        case 0x2d64u: goto label_2d64;
        case 0x2d68u: goto label_2d68;
        case 0x2d6cu: goto label_2d6c;
        case 0x2d70u: goto label_2d70;
        case 0x2d74u: goto label_2d74;
        case 0x2d78u: goto label_2d78;
        case 0x2d7cu: goto label_2d7c;
        case 0x2d80u: goto label_2d80;
        case 0x2d84u: goto label_2d84;
        case 0x2d88u: goto label_2d88;
        case 0x2d8cu: goto label_2d8c;
        case 0x2d90u: goto label_2d90;
        case 0x2d94u: goto label_2d94;
        case 0x2d98u: goto label_2d98;
        case 0x2d9cu: goto label_2d9c;
        case 0x2da0u: goto label_2da0;
        case 0x2da4u: goto label_2da4;
        case 0x2da8u: goto label_2da8;
        case 0x2dacu: goto label_2dac;
        case 0x2db0u: goto label_2db0;
        case 0x2db4u: goto label_2db4;
        case 0x2db8u: goto label_2db8;
        case 0x2dbcu: goto label_2dbc;
        case 0x2dc0u: goto label_2dc0;
        case 0x2dc4u: goto label_2dc4;
        case 0x2dc8u: goto label_2dc8;
        case 0x2dccu: goto label_2dcc;
        case 0x2dd0u: goto label_2dd0;
        case 0x2dd4u: goto label_2dd4;
        case 0x2dd8u: goto label_2dd8;
        case 0x2ddcu: goto label_2ddc;
        case 0x2de0u: goto label_2de0;
        case 0x2de4u: goto label_2de4;
        case 0x2de8u: goto label_2de8;
        case 0x2decu: goto label_2dec;
        case 0x2df0u: goto label_2df0;
        case 0x2df4u: goto label_2df4;
        case 0x2df8u: goto label_2df8;
        case 0x2dfcu: goto label_2dfc;
        case 0x2e00u: goto label_2e00;
        case 0x2e04u: goto label_2e04;
        case 0x2e08u: goto label_2e08;
        case 0x2e0cu: goto label_2e0c;
        case 0x2e10u: goto label_2e10;
        case 0x2e14u: goto label_2e14;
        case 0x2e18u: goto label_2e18;
        case 0x2e1cu: goto label_2e1c;
        case 0x2e20u: goto label_2e20;
        case 0x2e24u: goto label_2e24;
        case 0x2e28u: goto label_2e28;
        case 0x2e2cu: goto label_2e2c;
        case 0x2e30u: goto label_2e30;
        case 0x2e34u: goto label_2e34;
        case 0x2e38u: goto label_2e38;
        case 0x2e3cu: goto label_2e3c;
        case 0x2e40u: goto label_2e40;
        case 0x2e44u: goto label_2e44;
        case 0x2e48u: goto label_2e48;
        case 0x2e4cu: goto label_2e4c;
        case 0x2e50u: goto label_2e50;
        case 0x2e54u: goto label_2e54;
        case 0x2e58u: goto label_2e58;
        case 0x2e5cu: goto label_2e5c;
        case 0x2e60u: goto label_2e60;
        case 0x2e64u: goto label_2e64;
        case 0x2e68u: goto label_2e68;
        case 0x2e6cu: goto label_2e6c;
        case 0x2e70u: goto label_2e70;
        case 0x2e74u: goto label_2e74;
        case 0x2e78u: goto label_2e78;
        case 0x2e7cu: goto label_2e7c;
        case 0x2e80u: goto label_2e80;
        case 0x2e84u: goto label_2e84;
        case 0x2e88u: goto label_2e88;
        case 0x2e8cu: goto label_2e8c;
        case 0x2e90u: goto label_2e90;
        case 0x2e94u: goto label_2e94;
        case 0x2e98u: goto label_2e98;
        case 0x2e9cu: goto label_2e9c;
        case 0x2ea0u: goto label_2ea0;
        case 0x2ea4u: goto label_2ea4;
        case 0x2ea8u: goto label_2ea8;
        case 0x2eacu: goto label_2eac;
        case 0x2eb0u: goto label_2eb0;
        case 0x2eb4u: goto label_2eb4;
        case 0x2eb8u: goto label_2eb8;
        case 0x2ebcu: goto label_2ebc;
        case 0x2ec0u: goto label_2ec0;
        case 0x2ec4u: goto label_2ec4;
        case 0x2ec8u: goto label_2ec8;
        case 0x2eccu: goto label_2ecc;
        case 0x2ed0u: goto label_2ed0;
        case 0x2ed4u: goto label_2ed4;
        case 0x2ed8u: goto label_2ed8;
        case 0x2edcu: goto label_2edc;
        case 0x2ee0u: goto label_2ee0;
        case 0x2ee4u: goto label_2ee4;
        case 0x2ee8u: goto label_2ee8;
        case 0x2eecu: goto label_2eec;
        case 0x2ef0u: goto label_2ef0;
        case 0x2ef4u: goto label_2ef4;
        case 0x2ef8u: goto label_2ef8;
        case 0x2efcu: goto label_2efc;
        case 0x2f00u: goto label_2f00;
        case 0x2f04u: goto label_2f04;
        case 0x2f08u: goto label_2f08;
        case 0x2f0cu: goto label_2f0c;
        case 0x2f10u: goto label_2f10;
        case 0x2f14u: goto label_2f14;
        case 0x2f18u: goto label_2f18;
        case 0x2f1cu: goto label_2f1c;
        case 0x2f20u: goto label_2f20;
        case 0x2f24u: goto label_2f24;
        case 0x2f28u: goto label_2f28;
        case 0x2f2cu: goto label_2f2c;
        case 0x2f30u: goto label_2f30;
        case 0x2f34u: goto label_2f34;
        case 0x2f38u: goto label_2f38;
        case 0x2f3cu: goto label_2f3c;
        case 0x2f40u: goto label_2f40;
        case 0x2f44u: goto label_2f44;
        case 0x2f48u: goto label_2f48;
        case 0x2f4cu: goto label_2f4c;
        case 0x2f50u: goto label_2f50;
        case 0x2f54u: goto label_2f54;
        case 0x2f58u: goto label_2f58;
        case 0x2f5cu: goto label_2f5c;
        case 0x2f60u: goto label_2f60;
        case 0x2f64u: goto label_2f64;
        case 0x2f68u: goto label_2f68;
        case 0x2f6cu: goto label_2f6c;
        case 0x2f70u: goto label_2f70;
        case 0x2f74u: goto label_2f74;
        case 0x2f78u: goto label_2f78;
        case 0x2f7cu: goto label_2f7c;
        case 0x2f80u: goto label_2f80;
        case 0x2f84u: goto label_2f84;
        case 0x2f88u: goto label_2f88;
        case 0x2f8cu: goto label_2f8c;
        case 0x2f90u: goto label_2f90;
        case 0x2f94u: goto label_2f94;
        case 0x2f98u: goto label_2f98;
        case 0x2f9cu: goto label_2f9c;
        case 0x2fa0u: goto label_2fa0;
        case 0x2fa4u: goto label_2fa4;
        case 0x2fa8u: goto label_2fa8;
        case 0x2facu: goto label_2fac;
        case 0x2fb0u: goto label_2fb0;
        case 0x2fb4u: goto label_2fb4;
        case 0x2fb8u: goto label_2fb8;
        case 0x2fbcu: goto label_2fbc;
        case 0x2fc0u: goto label_2fc0;
        case 0x2fc4u: goto label_2fc4;
        case 0x2fc8u: goto label_2fc8;
        case 0x2fccu: goto label_2fcc;
        case 0x2fd0u: goto label_2fd0;
        case 0x2fd4u: goto label_2fd4;
        case 0x2fd8u: goto label_2fd8;
        case 0x2fdcu: goto label_2fdc;
        case 0x2fe0u: goto label_2fe0;
        case 0x2fe4u: goto label_2fe4;
        case 0x2fe8u: goto label_2fe8;
        case 0x2fecu: goto label_2fec;
        case 0x2ff0u: goto label_2ff0;
        case 0x2ff4u: goto label_2ff4;
        case 0x2ff8u: goto label_2ff8;
        case 0x2ffcu: goto label_2ffc;
        case 0x3000u: goto label_3000;
        case 0x3004u: goto label_3004;
        case 0x3008u: goto label_3008;
        case 0x300cu: goto label_300c;
        case 0x3010u: goto label_3010;
        case 0x3014u: goto label_3014;
        case 0x3018u: goto label_3018;
        case 0x301cu: goto label_301c;
        case 0x3020u: goto label_3020;
        case 0x3024u: goto label_3024;
        case 0x3028u: goto label_3028;
        case 0x302cu: goto label_302c;
        case 0x3030u: goto label_3030;
        case 0x3034u: goto label_3034;
        case 0x3038u: goto label_3038;
        case 0x303cu: goto label_303c;
        case 0x3040u: goto label_3040;
        case 0x3044u: goto label_3044;
        case 0x3048u: goto label_3048;
        case 0x304cu: goto label_304c;
        case 0x3050u: goto label_3050;
        case 0x3054u: goto label_3054;
        case 0x3058u: goto label_3058;
        case 0x305cu: goto label_305c;
        case 0x3060u: goto label_3060;
        case 0x3064u: goto label_3064;
        case 0x3068u: goto label_3068;
        case 0x306cu: goto label_306c;
        case 0x3070u: goto label_3070;
        case 0x3074u: goto label_3074;
        case 0x3078u: goto label_3078;
        case 0x307cu: goto label_307c;
        case 0x3080u: goto label_3080;
        case 0x3084u: goto label_3084;
        case 0x3088u: goto label_3088;
        case 0x308cu: goto label_308c;
        case 0x3090u: goto label_3090;
        case 0x3094u: goto label_3094;
        case 0x3098u: goto label_3098;
        case 0x309cu: goto label_309c;
        case 0x30a0u: goto label_30a0;
        case 0x30a4u: goto label_30a4;
        case 0x30a8u: goto label_30a8;
        case 0x30acu: goto label_30ac;
        case 0x30b0u: goto label_30b0;
        case 0x30b4u: goto label_30b4;
        case 0x30b8u: goto label_30b8;
        case 0x30bcu: goto label_30bc;
        case 0x30c0u: goto label_30c0;
        case 0x30c4u: goto label_30c4;
        case 0x30c8u: goto label_30c8;
        case 0x30ccu: goto label_30cc;
        case 0x30d0u: goto label_30d0;
        case 0x30d4u: goto label_30d4;
        case 0x30d8u: goto label_30d8;
        case 0x30dcu: goto label_30dc;
        case 0x30e0u: goto label_30e0;
        case 0x30e4u: goto label_30e4;
        case 0x30e8u: goto label_30e8;
        case 0x30ecu: goto label_30ec;
        case 0x30f0u: goto label_30f0;
        case 0x30f4u: goto label_30f4;
        case 0x30f8u: goto label_30f8;
        case 0x30fcu: goto label_30fc;
        case 0x3100u: goto label_3100;
        case 0x3104u: goto label_3104;
        case 0x3108u: goto label_3108;
        case 0x310cu: goto label_310c;
        case 0x3110u: goto label_3110;
        case 0x3114u: goto label_3114;
        case 0x3118u: goto label_3118;
        case 0x311cu: goto label_311c;
        case 0x3120u: goto label_3120;
        case 0x3124u: goto label_3124;
        case 0x3128u: goto label_3128;
        case 0x312cu: goto label_312c;
        case 0x3130u: goto label_3130;
        case 0x3134u: goto label_3134;
        case 0x3138u: goto label_3138;
        case 0x313cu: goto label_313c;
        case 0x3140u: goto label_3140;
        case 0x3144u: goto label_3144;
        case 0x3148u: goto label_3148;
        case 0x314cu: goto label_314c;
        case 0x3150u: goto label_3150;
        case 0x3154u: goto label_3154;
        case 0x3158u: goto label_3158;
        case 0x315cu: goto label_315c;
        case 0x3160u: goto label_3160;
        case 0x3164u: goto label_3164;
        case 0x3168u: goto label_3168;
        case 0x316cu: goto label_316c;
        case 0x3170u: goto label_3170;
        case 0x3174u: goto label_3174;
        case 0x3178u: goto label_3178;
        case 0x317cu: goto label_317c;
        case 0x3180u: goto label_3180;
        case 0x3184u: goto label_3184;
        case 0x3188u: goto label_3188;
        case 0x318cu: goto label_318c;
        case 0x3190u: goto label_3190;
        case 0x3194u: goto label_3194;
        case 0x3198u: goto label_3198;
        case 0x319cu: goto label_319c;
        case 0x31a0u: goto label_31a0;
        case 0x31a4u: goto label_31a4;
        case 0x31a8u: goto label_31a8;
        case 0x31acu: goto label_31ac;
        case 0x31b0u: goto label_31b0;
        case 0x31b4u: goto label_31b4;
        case 0x31b8u: goto label_31b8;
        case 0x31bcu: goto label_31bc;
        case 0x31c0u: goto label_31c0;
        case 0x31c4u: goto label_31c4;
        case 0x31c8u: goto label_31c8;
        case 0x31ccu: goto label_31cc;
        case 0x31d0u: goto label_31d0;
        case 0x31d4u: goto label_31d4;
        case 0x31d8u: goto label_31d8;
        case 0x31dcu: goto label_31dc;
        case 0x31e0u: goto label_31e0;
        case 0x31e4u: goto label_31e4;
        case 0x31e8u: goto label_31e8;
        case 0x31ecu: goto label_31ec;
        case 0x31f0u: goto label_31f0;
        case 0x31f4u: goto label_31f4;
        case 0x31f8u: goto label_31f8;
        case 0x31fcu: goto label_31fc;
        case 0x3200u: goto label_3200;
        case 0x3204u: goto label_3204;
        case 0x3208u: goto label_3208;
        case 0x320cu: goto label_320c;
        case 0x3210u: goto label_3210;
        case 0x3214u: goto label_3214;
        case 0x3218u: goto label_3218;
        case 0x321cu: goto label_321c;
        case 0x3220u: goto label_3220;
        case 0x3224u: goto label_3224;
        case 0x3228u: goto label_3228;
        case 0x322cu: goto label_322c;
        case 0x3230u: goto label_3230;
        case 0x3234u: goto label_3234;
        case 0x3238u: goto label_3238;
        case 0x323cu: goto label_323c;
        case 0x3240u: goto label_3240;
        case 0x3244u: goto label_3244;
        case 0x3248u: goto label_3248;
        case 0x324cu: goto label_324c;
        case 0x3250u: goto label_3250;
        case 0x3254u: goto label_3254;
        case 0x3258u: goto label_3258;
        case 0x325cu: goto label_325c;
        case 0x3260u: goto label_3260;
        case 0x3264u: goto label_3264;
        case 0x3268u: goto label_3268;
        case 0x326cu: goto label_326c;
        case 0x3270u: goto label_3270;
        case 0x3274u: goto label_3274;
        case 0x3278u: goto label_3278;
        case 0x327cu: goto label_327c;
        case 0x3280u: goto label_3280;
        case 0x3284u: goto label_3284;
        case 0x3288u: goto label_3288;
        case 0x328cu: goto label_328c;
        case 0x3290u: goto label_3290;
        case 0x3294u: goto label_3294;
        case 0x3298u: goto label_3298;
        case 0x329cu: goto label_329c;
        case 0x32a0u: goto label_32a0;
        case 0x32a4u: goto label_32a4;
        case 0x32a8u: goto label_32a8;
        case 0x32acu: goto label_32ac;
        case 0x32b0u: goto label_32b0;
        case 0x32b4u: goto label_32b4;
        case 0x32b8u: goto label_32b8;
        case 0x32bcu: goto label_32bc;
        case 0x32c0u: goto label_32c0;
        case 0x32c4u: goto label_32c4;
        case 0x32c8u: goto label_32c8;
        case 0x32ccu: goto label_32cc;
        case 0x32d0u: goto label_32d0;
        case 0x32d4u: goto label_32d4;
        case 0x32d8u: goto label_32d8;
        case 0x32dcu: goto label_32dc;
        case 0x32e0u: goto label_32e0;
        case 0x32e4u: goto label_32e4;
        case 0x32e8u: goto label_32e8;
        case 0x32ecu: goto label_32ec;
        case 0x32f0u: goto label_32f0;
        case 0x32f4u: goto label_32f4;
        case 0x32f8u: goto label_32f8;
        case 0x32fcu: goto label_32fc;
        case 0x3300u: goto label_3300;
        case 0x3304u: goto label_3304;
        case 0x3308u: goto label_3308;
        case 0x330cu: goto label_330c;
        case 0x3310u: goto label_3310;
        case 0x3314u: goto label_3314;
        case 0x3318u: goto label_3318;
        case 0x331cu: goto label_331c;
        case 0x3320u: goto label_3320;
        case 0x3324u: goto label_3324;
        case 0x3328u: goto label_3328;
        case 0x332cu: goto label_332c;
        case 0x3330u: goto label_3330;
        case 0x3334u: goto label_3334;
        case 0x3338u: goto label_3338;
        case 0x333cu: goto label_333c;
        case 0x3340u: goto label_3340;
        case 0x3344u: goto label_3344;
        case 0x3348u: goto label_3348;
        case 0x334cu: goto label_334c;
        case 0x3350u: goto label_3350;
        case 0x3354u: goto label_3354;
        case 0x3358u: goto label_3358;
        case 0x335cu: goto label_335c;
        case 0x3360u: goto label_3360;
        case 0x3364u: goto label_3364;
        case 0x3368u: goto label_3368;
        case 0x336cu: goto label_336c;
        case 0x3370u: goto label_3370;
        case 0x3374u: goto label_3374;
        case 0x3378u: goto label_3378;
        case 0x337cu: goto label_337c;
        case 0x3380u: goto label_3380;
        case 0x3384u: goto label_3384;
        case 0x3388u: goto label_3388;
        case 0x338cu: goto label_338c;
        case 0x3390u: goto label_3390;
        case 0x3394u: goto label_3394;
        case 0x3398u: goto label_3398;
        case 0x339cu: goto label_339c;
        case 0x33a0u: goto label_33a0;
        case 0x33a4u: goto label_33a4;
        case 0x33a8u: goto label_33a8;
        case 0x33acu: goto label_33ac;
        case 0x33b0u: goto label_33b0;
        case 0x33b4u: goto label_33b4;
        case 0x33b8u: goto label_33b8;
        case 0x33bcu: goto label_33bc;
        case 0x33c0u: goto label_33c0;
        case 0x33c4u: goto label_33c4;
        case 0x33c8u: goto label_33c8;
        case 0x33ccu: goto label_33cc;
        case 0x33d0u: goto label_33d0;
        case 0x33d4u: goto label_33d4;
        case 0x33d8u: goto label_33d8;
        case 0x33dcu: goto label_33dc;
        case 0x33e0u: goto label_33e0;
        case 0x33e4u: goto label_33e4;
        case 0x33e8u: goto label_33e8;
        case 0x33ecu: goto label_33ec;
        case 0x33f0u: goto label_33f0;
        case 0x33f4u: goto label_33f4;
        case 0x33f8u: goto label_33f8;
        case 0x33fcu: goto label_33fc;
        case 0x3400u: goto label_3400;
        case 0x3404u: goto label_3404;
        case 0x3408u: goto label_3408;
        case 0x340cu: goto label_340c;
        case 0x3410u: goto label_3410;
        case 0x3414u: goto label_3414;
        case 0x3418u: goto label_3418;
        case 0x341cu: goto label_341c;
        case 0x3420u: goto label_3420;
        case 0x3424u: goto label_3424;
        case 0x3428u: goto label_3428;
        case 0x342cu: goto label_342c;
        case 0x3430u: goto label_3430;
        case 0x3434u: goto label_3434;
        case 0x3438u: goto label_3438;
        case 0x343cu: goto label_343c;
        case 0x3440u: goto label_3440;
        case 0x3444u: goto label_3444;
        case 0x3448u: goto label_3448;
        case 0x344cu: goto label_344c;
        case 0x3450u: goto label_3450;
        case 0x3454u: goto label_3454;
        case 0x3458u: goto label_3458;
        case 0x345cu: goto label_345c;
        case 0x3460u: goto label_3460;
        case 0x3464u: goto label_3464;
        case 0x3468u: goto label_3468;
        case 0x346cu: goto label_346c;
        case 0x3470u: goto label_3470;
        case 0x3474u: goto label_3474;
        case 0x3478u: goto label_3478;
        case 0x347cu: goto label_347c;
        case 0x3480u: goto label_3480;
        case 0x3484u: goto label_3484;
        case 0x3488u: goto label_3488;
        case 0x348cu: goto label_348c;
        case 0x3490u: goto label_3490;
        case 0x3494u: goto label_3494;
        case 0x3498u: goto label_3498;
        case 0x349cu: goto label_349c;
        case 0x34a0u: goto label_34a0;
        case 0x34a4u: goto label_34a4;
        case 0x34a8u: goto label_34a8;
        case 0x34acu: goto label_34ac;
        case 0x34b0u: goto label_34b0;
        case 0x34b4u: goto label_34b4;
        case 0x34b8u: goto label_34b8;
        case 0x34bcu: goto label_34bc;
        case 0x34c0u: goto label_34c0;
        case 0x34c4u: goto label_34c4;
        case 0x34c8u: goto label_34c8;
        case 0x34ccu: goto label_34cc;
        case 0x34d0u: goto label_34d0;
        case 0x34d4u: goto label_34d4;
        case 0x34d8u: goto label_34d8;
        case 0x34dcu: goto label_34dc;
        case 0x34e0u: goto label_34e0;
        case 0x34e4u: goto label_34e4;
        case 0x34e8u: goto label_34e8;
        case 0x34ecu: goto label_34ec;
        case 0x34f0u: goto label_34f0;
        case 0x34f4u: goto label_34f4;
        case 0x34f8u: goto label_34f8;
        case 0x34fcu: goto label_34fc;
        case 0x3500u: goto label_3500;
        case 0x3504u: goto label_3504;
        case 0x3508u: goto label_3508;
        case 0x350cu: goto label_350c;
        case 0x3510u: goto label_3510;
        case 0x3514u: goto label_3514;
        case 0x3518u: goto label_3518;
        case 0x351cu: goto label_351c;
        case 0x3520u: goto label_3520;
        case 0x3524u: goto label_3524;
        case 0x3528u: goto label_3528;
        case 0x352cu: goto label_352c;
        case 0x3530u: goto label_3530;
        case 0x3534u: goto label_3534;
        case 0x3538u: goto label_3538;
        case 0x353cu: goto label_353c;
        case 0x3540u: goto label_3540;
        case 0x3544u: goto label_3544;
        case 0x3548u: goto label_3548;
        case 0x354cu: goto label_354c;
        case 0x3550u: goto label_3550;
        case 0x3554u: goto label_3554;
        case 0x3558u: goto label_3558;
        case 0x355cu: goto label_355c;
        case 0x3560u: goto label_3560;
        case 0x3564u: goto label_3564;
        case 0x3568u: goto label_3568;
        case 0x356cu: goto label_356c;
        case 0x3570u: goto label_3570;
        case 0x3574u: goto label_3574;
        case 0x3578u: goto label_3578;
        case 0x357cu: goto label_357c;
        case 0x3580u: goto label_3580;
        case 0x3584u: goto label_3584;
        case 0x3588u: goto label_3588;
        case 0x358cu: goto label_358c;
        case 0x3590u: goto label_3590;
        case 0x3594u: goto label_3594;
        case 0x3598u: goto label_3598;
        case 0x359cu: goto label_359c;
        case 0x35a0u: goto label_35a0;
        case 0x35a4u: goto label_35a4;
        case 0x35a8u: goto label_35a8;
        case 0x35acu: goto label_35ac;
        case 0x35b0u: goto label_35b0;
        case 0x35b4u: goto label_35b4;
        case 0x35b8u: goto label_35b8;
        case 0x35bcu: goto label_35bc;
        case 0x35c0u: goto label_35c0;
        case 0x35c4u: goto label_35c4;
        case 0x35c8u: goto label_35c8;
        case 0x35ccu: goto label_35cc;
        case 0x35d0u: goto label_35d0;
        case 0x35d4u: goto label_35d4;
        case 0x35d8u: goto label_35d8;
        case 0x35dcu: goto label_35dc;
        case 0x35e0u: goto label_35e0;
        case 0x35e4u: goto label_35e4;
        case 0x35e8u: goto label_35e8;
        case 0x35ecu: goto label_35ec;
        case 0x35f0u: goto label_35f0;
        case 0x35f4u: goto label_35f4;
        case 0x35f8u: goto label_35f8;
        case 0x35fcu: goto label_35fc;
        case 0x3600u: goto label_3600;
        case 0x3604u: goto label_3604;
        case 0x3608u: goto label_3608;
        case 0x360cu: goto label_360c;
        case 0x3610u: goto label_3610;
        case 0x3614u: goto label_3614;
        case 0x3618u: goto label_3618;
        case 0x361cu: goto label_361c;
        case 0x3620u: goto label_3620;
        case 0x3624u: goto label_3624;
        case 0x3628u: goto label_3628;
        case 0x362cu: goto label_362c;
        case 0x3630u: goto label_3630;
        case 0x3634u: goto label_3634;
        case 0x3638u: goto label_3638;
        case 0x363cu: goto label_363c;
        case 0x3640u: goto label_3640;
        case 0x3644u: goto label_3644;
        case 0x3648u: goto label_3648;
        case 0x364cu: goto label_364c;
        case 0x3650u: goto label_3650;
        case 0x3654u: goto label_3654;
        case 0x3658u: goto label_3658;
        case 0x365cu: goto label_365c;
        case 0x3660u: goto label_3660;
        case 0x3664u: goto label_3664;
        case 0x3668u: goto label_3668;
        case 0x366cu: goto label_366c;
        case 0x3670u: goto label_3670;
        case 0x3674u: goto label_3674;
        case 0x3678u: goto label_3678;
        case 0x367cu: goto label_367c;
        case 0x3680u: goto label_3680;
        case 0x3684u: goto label_3684;
        case 0x3688u: goto label_3688;
        case 0x368cu: goto label_368c;
        case 0x3690u: goto label_3690;
        case 0x3694u: goto label_3694;
        case 0x3698u: goto label_3698;
        case 0x369cu: goto label_369c;
        case 0x36a0u: goto label_36a0;
        case 0x36a4u: goto label_36a4;
        case 0x36a8u: goto label_36a8;
        case 0x36acu: goto label_36ac;
        case 0x36b0u: goto label_36b0;
        case 0x36b4u: goto label_36b4;
        case 0x36b8u: goto label_36b8;
        case 0x36bcu: goto label_36bc;
        case 0x36c0u: goto label_36c0;
        case 0x36c4u: goto label_36c4;
        case 0x36c8u: goto label_36c8;
        case 0x36ccu: goto label_36cc;
        case 0x36d0u: goto label_36d0;
        case 0x36d4u: goto label_36d4;
        case 0x36d8u: goto label_36d8;
        case 0x36dcu: goto label_36dc;
        case 0x36e0u: goto label_36e0;
        case 0x36e4u: goto label_36e4;
        case 0x36e8u: goto label_36e8;
        case 0x36ecu: goto label_36ec;
        case 0x36f0u: goto label_36f0;
        case 0x36f4u: goto label_36f4;
        case 0x36f8u: goto label_36f8;
        case 0x36fcu: goto label_36fc;
        case 0x3700u: goto label_3700;
        case 0x3704u: goto label_3704;
        case 0x3708u: goto label_3708;
        case 0x370cu: goto label_370c;
        case 0x3710u: goto label_3710;
        case 0x3714u: goto label_3714;
        case 0x3718u: goto label_3718;
        case 0x371cu: goto label_371c;
        case 0x3720u: goto label_3720;
        case 0x3724u: goto label_3724;
        case 0x3728u: goto label_3728;
        case 0x372cu: goto label_372c;
        case 0x3730u: goto label_3730;
        case 0x3734u: goto label_3734;
        case 0x3738u: goto label_3738;
        case 0x373cu: goto label_373c;
        case 0x3740u: goto label_3740;
        case 0x3744u: goto label_3744;
        case 0x3748u: goto label_3748;
        case 0x374cu: goto label_374c;
        case 0x3750u: goto label_3750;
        case 0x3754u: goto label_3754;
        case 0x3758u: goto label_3758;
        case 0x375cu: goto label_375c;
        case 0x3760u: goto label_3760;
        case 0x3764u: goto label_3764;
        case 0x3768u: goto label_3768;
        case 0x376cu: goto label_376c;
        case 0x3770u: goto label_3770;
        case 0x3774u: goto label_3774;
        case 0x3778u: goto label_3778;
        case 0x377cu: goto label_377c;
        case 0x3780u: goto label_3780;
        case 0x3784u: goto label_3784;
        case 0x3788u: goto label_3788;
        case 0x378cu: goto label_378c;
        case 0x3790u: goto label_3790;
        case 0x3794u: goto label_3794;
        case 0x3798u: goto label_3798;
        case 0x379cu: goto label_379c;
        case 0x37a0u: goto label_37a0;
        case 0x37a4u: goto label_37a4;
        case 0x37a8u: goto label_37a8;
        case 0x37acu: goto label_37ac;
        case 0x37b0u: goto label_37b0;
        case 0x37b4u: goto label_37b4;
        case 0x37b8u: goto label_37b8;
        case 0x37bcu: goto label_37bc;
        case 0x37c0u: goto label_37c0;
        case 0x37c4u: goto label_37c4;
        case 0x37c8u: goto label_37c8;
        case 0x37ccu: goto label_37cc;
        case 0x37d0u: goto label_37d0;
        case 0x37d4u: goto label_37d4;
        case 0x37d8u: goto label_37d8;
        case 0x37dcu: goto label_37dc;
        case 0x37e0u: goto label_37e0;
        case 0x37e4u: goto label_37e4;
        case 0x37e8u: goto label_37e8;
        case 0x37ecu: goto label_37ec;
        case 0x37f0u: goto label_37f0;
        case 0x37f4u: goto label_37f4;
        case 0x37f8u: goto label_37f8;
        case 0x37fcu: goto label_37fc;
        case 0x3800u: goto label_3800;
        case 0x3804u: goto label_3804;
        case 0x3808u: goto label_3808;
        case 0x380cu: goto label_380c;
        case 0x3810u: goto label_3810;
        case 0x3814u: goto label_3814;
        case 0x3818u: goto label_3818;
        case 0x381cu: goto label_381c;
        case 0x3820u: goto label_3820;
        case 0x3824u: goto label_3824;
        case 0x3828u: goto label_3828;
        case 0x382cu: goto label_382c;
        case 0x3830u: goto label_3830;
        case 0x3834u: goto label_3834;
        case 0x3838u: goto label_3838;
        case 0x383cu: goto label_383c;
        case 0x3840u: goto label_3840;
        case 0x3844u: goto label_3844;
        case 0x3848u: goto label_3848;
        case 0x384cu: goto label_384c;
        case 0x3850u: goto label_3850;
        case 0x3854u: goto label_3854;
        case 0x3858u: goto label_3858;
        case 0x385cu: goto label_385c;
        case 0x3860u: goto label_3860;
        case 0x3864u: goto label_3864;
        case 0x3868u: goto label_3868;
        case 0x386cu: goto label_386c;
        case 0x3870u: goto label_3870;
        case 0x3874u: goto label_3874;
        case 0x3878u: goto label_3878;
        case 0x387cu: goto label_387c;
        case 0x3880u: goto label_3880;
        case 0x3884u: goto label_3884;
        case 0x3888u: goto label_3888;
        case 0x388cu: goto label_388c;
        case 0x3890u: goto label_3890;
        case 0x3894u: goto label_3894;
        case 0x3898u: goto label_3898;
        case 0x389cu: goto label_389c;
        case 0x38a0u: goto label_38a0;
        case 0x38a4u: goto label_38a4;
        case 0x38a8u: goto label_38a8;
        case 0x38acu: goto label_38ac;
        case 0x38b0u: goto label_38b0;
        case 0x38b4u: goto label_38b4;
        case 0x38b8u: goto label_38b8;
        case 0x38bcu: goto label_38bc;
        case 0x38c0u: goto label_38c0;
        case 0x38c4u: goto label_38c4;
        case 0x38c8u: goto label_38c8;
        case 0x38ccu: goto label_38cc;
        case 0x38d0u: goto label_38d0;
        case 0x38d4u: goto label_38d4;
        case 0x38d8u: goto label_38d8;
        case 0x38dcu: goto label_38dc;
        case 0x38e0u: goto label_38e0;
        case 0x38e4u: goto label_38e4;
        case 0x38e8u: goto label_38e8;
        case 0x38ecu: goto label_38ec;
        case 0x38f0u: goto label_38f0;
        case 0x38f4u: goto label_38f4;
        case 0x38f8u: goto label_38f8;
        case 0x38fcu: goto label_38fc;
        case 0x3900u: goto label_3900;
        case 0x3904u: goto label_3904;
        case 0x3908u: goto label_3908;
        case 0x390cu: goto label_390c;
        case 0x3910u: goto label_3910;
        case 0x3914u: goto label_3914;
        case 0x3918u: goto label_3918;
        case 0x391cu: goto label_391c;
        case 0x3920u: goto label_3920;
        case 0x3924u: goto label_3924;
        case 0x3928u: goto label_3928;
        case 0x392cu: goto label_392c;
        case 0x3930u: goto label_3930;
        case 0x3934u: goto label_3934;
        case 0x3938u: goto label_3938;
        case 0x393cu: goto label_393c;
        case 0x3940u: goto label_3940;
        case 0x3944u: goto label_3944;
        case 0x3948u: goto label_3948;
        case 0x394cu: goto label_394c;
        case 0x3950u: goto label_3950;
        case 0x3954u: goto label_3954;
        case 0x3958u: goto label_3958;
        case 0x395cu: goto label_395c;
        case 0x3960u: goto label_3960;
        case 0x3964u: goto label_3964;
        case 0x3968u: goto label_3968;
        case 0x396cu: goto label_396c;
        case 0x3970u: goto label_3970;
        case 0x3974u: goto label_3974;
        case 0x3978u: goto label_3978;
        case 0x397cu: goto label_397c;
        case 0x3980u: goto label_3980;
        case 0x3984u: goto label_3984;
        case 0x3988u: goto label_3988;
        case 0x398cu: goto label_398c;
        case 0x3990u: goto label_3990;
        case 0x3994u: goto label_3994;
        case 0x3998u: goto label_3998;
        case 0x399cu: goto label_399c;
        case 0x39a0u: goto label_39a0;
        case 0x39a4u: goto label_39a4;
        case 0x39a8u: goto label_39a8;
        case 0x39acu: goto label_39ac;
        case 0x39b0u: goto label_39b0;
        case 0x39b4u: goto label_39b4;
        case 0x39b8u: goto label_39b8;
        case 0x39bcu: goto label_39bc;
        case 0x39c0u: goto label_39c0;
        case 0x39c4u: goto label_39c4;
        case 0x39c8u: goto label_39c8;
        case 0x39ccu: goto label_39cc;
        case 0x39d0u: goto label_39d0;
        case 0x39d4u: goto label_39d4;
        case 0x39d8u: goto label_39d8;
        case 0x39dcu: goto label_39dc;
        case 0x39e0u: goto label_39e0;
        case 0x39e4u: goto label_39e4;
        case 0x39e8u: goto label_39e8;
        case 0x39ecu: goto label_39ec;
        case 0x39f0u: goto label_39f0;
        case 0x39f4u: goto label_39f4;
        case 0x39f8u: goto label_39f8;
        case 0x39fcu: goto label_39fc;
        case 0x3a00u: goto label_3a00;
        case 0x3a04u: goto label_3a04;
        case 0x3a08u: goto label_3a08;
        case 0x3a0cu: goto label_3a0c;
        case 0x3a10u: goto label_3a10;
        case 0x3a14u: goto label_3a14;
        case 0x3a18u: goto label_3a18;
        case 0x3a1cu: goto label_3a1c;
        case 0x3a20u: goto label_3a20;
        case 0x3a24u: goto label_3a24;
        case 0x3a28u: goto label_3a28;
        case 0x3a2cu: goto label_3a2c;
        case 0x3a30u: goto label_3a30;
        case 0x3a34u: goto label_3a34;
        case 0x3a38u: goto label_3a38;
        case 0x3a3cu: goto label_3a3c;
        case 0x3a40u: goto label_3a40;
        case 0x3a44u: goto label_3a44;
        case 0x3a48u: goto label_3a48;
        case 0x3a4cu: goto label_3a4c;
        case 0x3a50u: goto label_3a50;
        case 0x3a54u: goto label_3a54;
        case 0x3a58u: goto label_3a58;
        case 0x3a5cu: goto label_3a5c;
        case 0x3a60u: goto label_3a60;
        case 0x3a64u: goto label_3a64;
        case 0x3a68u: goto label_3a68;
        case 0x3a6cu: goto label_3a6c;
        case 0x3a70u: goto label_3a70;
        case 0x3a74u: goto label_3a74;
        case 0x3a78u: goto label_3a78;
        case 0x3a7cu: goto label_3a7c;
        case 0x3a80u: goto label_3a80;
        case 0x3a84u: goto label_3a84;
        case 0x3a88u: goto label_3a88;
        case 0x3a8cu: goto label_3a8c;
        case 0x3a90u: goto label_3a90;
        case 0x3a94u: goto label_3a94;
        case 0x3a98u: goto label_3a98;
        case 0x3a9cu: goto label_3a9c;
        case 0x3aa0u: goto label_3aa0;
        case 0x3aa4u: goto label_3aa4;
        case 0x3aa8u: goto label_3aa8;
        case 0x3aacu: goto label_3aac;
        case 0x3ab0u: goto label_3ab0;
        case 0x3ab4u: goto label_3ab4;
        case 0x3ab8u: goto label_3ab8;
        case 0x3abcu: goto label_3abc;
        case 0x3ac0u: goto label_3ac0;
        case 0x3ac4u: goto label_3ac4;
        case 0x3ac8u: goto label_3ac8;
        case 0x3accu: goto label_3acc;
        case 0x3ad0u: goto label_3ad0;
        case 0x3ad4u: goto label_3ad4;
        case 0x3ad8u: goto label_3ad8;
        case 0x3adcu: goto label_3adc;
        case 0x3ae0u: goto label_3ae0;
        case 0x3ae4u: goto label_3ae4;
        case 0x3ae8u: goto label_3ae8;
        case 0x3aecu: goto label_3aec;
        case 0x3af0u: goto label_3af0;
        case 0x3af4u: goto label_3af4;
        case 0x3af8u: goto label_3af8;
        case 0x3afcu: goto label_3afc;
        case 0x3b00u: goto label_3b00;
        case 0x3b04u: goto label_3b04;
        case 0x3b08u: goto label_3b08;
        case 0x3b0cu: goto label_3b0c;
        case 0x3b10u: goto label_3b10;
        case 0x3b14u: goto label_3b14;
        case 0x3b18u: goto label_3b18;
        case 0x3b1cu: goto label_3b1c;
        case 0x3b20u: goto label_3b20;
        case 0x3b24u: goto label_3b24;
        case 0x3b28u: goto label_3b28;
        case 0x3b2cu: goto label_3b2c;
        case 0x3b30u: goto label_3b30;
        case 0x3b34u: goto label_3b34;
        case 0x3b38u: goto label_3b38;
        case 0x3b3cu: goto label_3b3c;
        case 0x3b40u: goto label_3b40;
        case 0x3b44u: goto label_3b44;
        case 0x3b48u: goto label_3b48;
        case 0x3b4cu: goto label_3b4c;
        case 0x3b50u: goto label_3b50;
        case 0x3b54u: goto label_3b54;
        case 0x3b58u: goto label_3b58;
        case 0x3b5cu: goto label_3b5c;
        case 0x3b60u: goto label_3b60;
        case 0x3b64u: goto label_3b64;
        case 0x3b68u: goto label_3b68;
        case 0x3b6cu: goto label_3b6c;
        case 0x3b70u: goto label_3b70;
        case 0x3b74u: goto label_3b74;
        case 0x3b78u: goto label_3b78;
        case 0x3b7cu: goto label_3b7c;
        case 0x3b80u: goto label_3b80;
        case 0x3b84u: goto label_3b84;
        case 0x3b88u: goto label_3b88;
        case 0x3b8cu: goto label_3b8c;
        case 0x3b90u: goto label_3b90;
        case 0x3b94u: goto label_3b94;
        case 0x3b98u: goto label_3b98;
        case 0x3b9cu: goto label_3b9c;
        case 0x3ba0u: goto label_3ba0;
        case 0x3ba4u: goto label_3ba4;
        case 0x3ba8u: goto label_3ba8;
        case 0x3bacu: goto label_3bac;
        case 0x3bb0u: goto label_3bb0;
        case 0x3bb4u: goto label_3bb4;
        case 0x3bb8u: goto label_3bb8;
        case 0x3bbcu: goto label_3bbc;
        case 0x3bc0u: goto label_3bc0;
        case 0x3bc4u: goto label_3bc4;
        case 0x3bc8u: goto label_3bc8;
        case 0x3bccu: goto label_3bcc;
        case 0x3bd0u: goto label_3bd0;
        case 0x3bd4u: goto label_3bd4;
        case 0x3bd8u: goto label_3bd8;
        case 0x3bdcu: goto label_3bdc;
        case 0x3be0u: goto label_3be0;
        case 0x3be4u: goto label_3be4;
        case 0x3be8u: goto label_3be8;
        case 0x3becu: goto label_3bec;
        case 0x3bf0u: goto label_3bf0;
        case 0x3bf4u: goto label_3bf4;
        case 0x3bf8u: goto label_3bf8;
        case 0x3bfcu: goto label_3bfc;
        case 0x3c00u: goto label_3c00;
        case 0x3c04u: goto label_3c04;
        case 0x3c08u: goto label_3c08;
        case 0x3c0cu: goto label_3c0c;
        case 0x3c10u: goto label_3c10;
        case 0x3c14u: goto label_3c14;
        case 0x3c18u: goto label_3c18;
        case 0x3c1cu: goto label_3c1c;
        case 0x3c20u: goto label_3c20;
        case 0x3c24u: goto label_3c24;
        case 0x3c28u: goto label_3c28;
        case 0x3c2cu: goto label_3c2c;
        case 0x3c30u: goto label_3c30;
        case 0x3c34u: goto label_3c34;
        case 0x3c38u: goto label_3c38;
        case 0x3c3cu: goto label_3c3c;
        case 0x3c40u: goto label_3c40;
        case 0x3c44u: goto label_3c44;
        case 0x3c48u: goto label_3c48;
        case 0x3c4cu: goto label_3c4c;
        case 0x3c50u: goto label_3c50;
        case 0x3c54u: goto label_3c54;
        case 0x3c58u: goto label_3c58;
        case 0x3c5cu: goto label_3c5c;
        case 0x3c60u: goto label_3c60;
        case 0x3c64u: goto label_3c64;
        case 0x3c68u: goto label_3c68;
        case 0x3c6cu: goto label_3c6c;
        case 0x3c70u: goto label_3c70;
        case 0x3c74u: goto label_3c74;
        case 0x3c78u: goto label_3c78;
        case 0x3c7cu: goto label_3c7c;
        case 0x3c80u: goto label_3c80;
        case 0x3c84u: goto label_3c84;
        case 0x3c88u: goto label_3c88;
        case 0x3c8cu: goto label_3c8c;
        case 0x3c90u: goto label_3c90;
        case 0x3c94u: goto label_3c94;
        case 0x3c98u: goto label_3c98;
        case 0x3c9cu: goto label_3c9c;
        case 0x3ca0u: goto label_3ca0;
        case 0x3ca4u: goto label_3ca4;
        case 0x3ca8u: goto label_3ca8;
        case 0x3cacu: goto label_3cac;
        case 0x3cb0u: goto label_3cb0;
        case 0x3cb4u: goto label_3cb4;
        case 0x3cb8u: goto label_3cb8;
        case 0x3cbcu: goto label_3cbc;
        case 0x3cc0u: goto label_3cc0;
        case 0x3cc4u: goto label_3cc4;
        case 0x3cc8u: goto label_3cc8;
        case 0x3cccu: goto label_3ccc;
        case 0x3cd0u: goto label_3cd0;
        case 0x3cd4u: goto label_3cd4;
        case 0x3cd8u: goto label_3cd8;
        case 0x3cdcu: goto label_3cdc;
        case 0x3ce0u: goto label_3ce0;
        case 0x3ce4u: goto label_3ce4;
        case 0x3ce8u: goto label_3ce8;
        case 0x3cecu: goto label_3cec;
        case 0x3cf0u: goto label_3cf0;
        case 0x3cf4u: goto label_3cf4;
        case 0x3cf8u: goto label_3cf8;
        case 0x3cfcu: goto label_3cfc;
        case 0x3d00u: goto label_3d00;
        case 0x3d04u: goto label_3d04;
        case 0x3d08u: goto label_3d08;
        case 0x3d0cu: goto label_3d0c;
        case 0x3d10u: goto label_3d10;
        case 0x3d14u: goto label_3d14;
        case 0x3d18u: goto label_3d18;
        case 0x3d1cu: goto label_3d1c;
        case 0x3d20u: goto label_3d20;
        case 0x3d24u: goto label_3d24;
        case 0x3d28u: goto label_3d28;
        case 0x3d2cu: goto label_3d2c;
        case 0x3d30u: goto label_3d30;
        case 0x3d34u: goto label_3d34;
        case 0x3d38u: goto label_3d38;
        case 0x3d3cu: goto label_3d3c;
        case 0x3d40u: goto label_3d40;
        case 0x3d44u: goto label_3d44;
        case 0x3d48u: goto label_3d48;
        case 0x3d4cu: goto label_3d4c;
        case 0x3d50u: goto label_3d50;
        case 0x3d54u: goto label_3d54;
        case 0x3d58u: goto label_3d58;
        case 0x3d5cu: goto label_3d5c;
        case 0x3d60u: goto label_3d60;
        case 0x3d64u: goto label_3d64;
        case 0x3d68u: goto label_3d68;
        case 0x3d6cu: goto label_3d6c;
        case 0x3d70u: goto label_3d70;
        case 0x3d74u: goto label_3d74;
        case 0x3d78u: goto label_3d78;
        case 0x3d7cu: goto label_3d7c;
        case 0x3d80u: goto label_3d80;
        case 0x3d84u: goto label_3d84;
        case 0x3d88u: goto label_3d88;
        case 0x3d8cu: goto label_3d8c;
        case 0x3d90u: goto label_3d90;
        case 0x3d94u: goto label_3d94;
        case 0x3d98u: goto label_3d98;
        case 0x3d9cu: goto label_3d9c;
        case 0x3da0u: goto label_3da0;
        case 0x3da4u: goto label_3da4;
        case 0x3da8u: goto label_3da8;
        case 0x3dacu: goto label_3dac;
        case 0x3db0u: goto label_3db0;
        case 0x3db4u: goto label_3db4;
        case 0x3db8u: goto label_3db8;
        case 0x3dbcu: goto label_3dbc;
        case 0x3dc0u: goto label_3dc0;
        case 0x3dc4u: goto label_3dc4;
        case 0x3dc8u: goto label_3dc8;
        case 0x3dccu: goto label_3dcc;
        case 0x3dd0u: goto label_3dd0;
        case 0x3dd4u: goto label_3dd4;
        case 0x3dd8u: goto label_3dd8;
        case 0x3ddcu: goto label_3ddc;
        case 0x3de0u: goto label_3de0;
        case 0x3de4u: goto label_3de4;
        case 0x3de8u: goto label_3de8;
        case 0x3decu: goto label_3dec;
        case 0x3df0u: goto label_3df0;
        case 0x3df4u: goto label_3df4;
        case 0x3df8u: goto label_3df8;
        case 0x3dfcu: goto label_3dfc;
        case 0x3e00u: goto label_3e00;
        case 0x3e04u: goto label_3e04;
        case 0x3e08u: goto label_3e08;
        case 0x3e0cu: goto label_3e0c;
        case 0x3e10u: goto label_3e10;
        case 0x3e14u: goto label_3e14;
        case 0x3e18u: goto label_3e18;
        case 0x3e1cu: goto label_3e1c;
        case 0x3e20u: goto label_3e20;
        case 0x3e24u: goto label_3e24;
        case 0x3e28u: goto label_3e28;
        case 0x3e2cu: goto label_3e2c;
        case 0x3e30u: goto label_3e30;
        case 0x3e34u: goto label_3e34;
        case 0x3e38u: goto label_3e38;
        case 0x3e3cu: goto label_3e3c;
        case 0x3e40u: goto label_3e40;
        case 0x3e44u: goto label_3e44;
        case 0x3e48u: goto label_3e48;
        case 0x3e4cu: goto label_3e4c;
        case 0x3e50u: goto label_3e50;
        case 0x3e54u: goto label_3e54;
        case 0x3e58u: goto label_3e58;
        case 0x3e5cu: goto label_3e5c;
        case 0x3e60u: goto label_3e60;
        case 0x3e64u: goto label_3e64;
        case 0x3e68u: goto label_3e68;
        case 0x3e6cu: goto label_3e6c;
        case 0x3e70u: goto label_3e70;
        case 0x3e74u: goto label_3e74;
        case 0x3e78u: goto label_3e78;
        case 0x3e7cu: goto label_3e7c;
        case 0x3e80u: goto label_3e80;
        case 0x3e84u: goto label_3e84;
        case 0x3e88u: goto label_3e88;
        case 0x3e8cu: goto label_3e8c;
        case 0x3e90u: goto label_3e90;
        case 0x3e94u: goto label_3e94;
        case 0x3e98u: goto label_3e98;
        case 0x3e9cu: goto label_3e9c;
        case 0x3ea0u: goto label_3ea0;
        case 0x3ea4u: goto label_3ea4;
        case 0x3ea8u: goto label_3ea8;
        case 0x3eacu: goto label_3eac;
        case 0x3eb0u: goto label_3eb0;
        case 0x3eb4u: goto label_3eb4;
        case 0x3eb8u: goto label_3eb8;
        case 0x3ebcu: goto label_3ebc;
        case 0x3ec0u: goto label_3ec0;
        case 0x3ec4u: goto label_3ec4;
        case 0x3ec8u: goto label_3ec8;
        case 0x3eccu: goto label_3ecc;
        case 0x3ed0u: goto label_3ed0;
        case 0x3ed4u: goto label_3ed4;
        case 0x3ed8u: goto label_3ed8;
        case 0x3edcu: goto label_3edc;
        case 0x3ee0u: goto label_3ee0;
        case 0x3ee4u: goto label_3ee4;
        case 0x3ee8u: goto label_3ee8;
        case 0x3eecu: goto label_3eec;
        case 0x3ef0u: goto label_3ef0;
        case 0x3ef4u: goto label_3ef4;
        case 0x3ef8u: goto label_3ef8;
        case 0x3efcu: goto label_3efc;
        case 0x3f00u: goto label_3f00;
        case 0x3f04u: goto label_3f04;
        case 0x3f08u: goto label_3f08;
        case 0x3f0cu: goto label_3f0c;
        case 0x3f10u: goto label_3f10;
        case 0x3f14u: goto label_3f14;
        case 0x3f18u: goto label_3f18;
        case 0x3f1cu: goto label_3f1c;
        case 0x3f20u: goto label_3f20;
        case 0x3f24u: goto label_3f24;
        case 0x3f28u: goto label_3f28;
        case 0x3f2cu: goto label_3f2c;
        case 0x3f30u: goto label_3f30;
        case 0x3f34u: goto label_3f34;
        case 0x3f38u: goto label_3f38;
        case 0x3f3cu: goto label_3f3c;
        case 0x3f40u: goto label_3f40;
        case 0x3f44u: goto label_3f44;
        case 0x3f48u: goto label_3f48;
        case 0x3f4cu: goto label_3f4c;
        case 0x3f50u: goto label_3f50;
        case 0x3f54u: goto label_3f54;
        case 0x3f58u: goto label_3f58;
        case 0x3f5cu: goto label_3f5c;
        case 0x3f60u: goto label_3f60;
        case 0x3f64u: goto label_3f64;
        case 0x3f68u: goto label_3f68;
        case 0x3f6cu: goto label_3f6c;
        case 0x3f70u: goto label_3f70;
        case 0x3f74u: goto label_3f74;
        case 0x3f78u: goto label_3f78;
        case 0x3f7cu: goto label_3f7c;
        case 0x3f80u: goto label_3f80;
        case 0x3f84u: goto label_3f84;
        case 0x3f88u: goto label_3f88;
        case 0x3f8cu: goto label_3f8c;
        case 0x3f90u: goto label_3f90;
        case 0x3f94u: goto label_3f94;
        case 0x3f98u: goto label_3f98;
        case 0x3f9cu: goto label_3f9c;
        case 0x3fa0u: goto label_3fa0;
        case 0x3fa4u: goto label_3fa4;
        case 0x3fa8u: goto label_3fa8;
        case 0x3facu: goto label_3fac;
        case 0x3fb0u: goto label_3fb0;
        case 0x3fb4u: goto label_3fb4;
        case 0x3fb8u: goto label_3fb8;
        case 0x3fbcu: goto label_3fbc;
        case 0x3fc0u: goto label_3fc0;
        case 0x3fc4u: goto label_3fc4;
        case 0x3fc8u: goto label_3fc8;
        case 0x3fccu: goto label_3fcc;
        case 0x3fd0u: goto label_3fd0;
        case 0x3fd4u: goto label_3fd4;
        case 0x3fd8u: goto label_3fd8;
        case 0x3fdcu: goto label_3fdc;
        case 0x3fe0u: goto label_3fe0;
        case 0x3fe4u: goto label_3fe4;
        case 0x3fe8u: goto label_3fe8;
        case 0x3fecu: goto label_3fec;
        case 0x3ff0u: goto label_3ff0;
        case 0x3ff4u: goto label_3ff4;
        case 0x3ff8u: goto label_3ff8;
        case 0x3ffcu: goto label_3ffc;
        case 0x4000u: goto label_4000;
        case 0x4004u: goto label_4004;
        case 0x4008u: goto label_4008;
        case 0x400cu: goto label_400c;
        case 0x4010u: goto label_4010;
        case 0x4014u: goto label_4014;
        case 0x4018u: goto label_4018;
        case 0x401cu: goto label_401c;
        case 0x4020u: goto label_4020;
        case 0x4024u: goto label_4024;
        case 0x4028u: goto label_4028;
        case 0x402cu: goto label_402c;
        case 0x4030u: goto label_4030;
        case 0x4034u: goto label_4034;
        case 0x4038u: goto label_4038;
        case 0x403cu: goto label_403c;
        case 0x4040u: goto label_4040;
        case 0x4044u: goto label_4044;
        case 0x4048u: goto label_4048;
        case 0x404cu: goto label_404c;
        case 0x4050u: goto label_4050;
        case 0x4054u: goto label_4054;
        case 0x4058u: goto label_4058;
        case 0x405cu: goto label_405c;
        case 0x4060u: goto label_4060;
        case 0x4064u: goto label_4064;
        case 0x4068u: goto label_4068;
        case 0x406cu: goto label_406c;
        case 0x4070u: goto label_4070;
        case 0x4074u: goto label_4074;
        case 0x4078u: goto label_4078;
        case 0x407cu: goto label_407c;
        case 0x4080u: goto label_4080;
        case 0x4084u: goto label_4084;
        case 0x4088u: goto label_4088;
        case 0x408cu: goto label_408c;
        case 0x4090u: goto label_4090;
        case 0x4094u: goto label_4094;
        case 0x4098u: goto label_4098;
        case 0x409cu: goto label_409c;
        case 0x40a0u: goto label_40a0;
        case 0x40a4u: goto label_40a4;
        case 0x40a8u: goto label_40a8;
        case 0x40acu: goto label_40ac;
        case 0x40b0u: goto label_40b0;
        case 0x40b4u: goto label_40b4;
        case 0x40b8u: goto label_40b8;
        case 0x40bcu: goto label_40bc;
        case 0x40c0u: goto label_40c0;
        case 0x40c4u: goto label_40c4;
        case 0x40c8u: goto label_40c8;
        case 0x40ccu: goto label_40cc;
        case 0x40d0u: goto label_40d0;
        case 0x40d4u: goto label_40d4;
        case 0x40d8u: goto label_40d8;
        case 0x40dcu: goto label_40dc;
        case 0x40e0u: goto label_40e0;
        case 0x40e4u: goto label_40e4;
        case 0x40e8u: goto label_40e8;
        case 0x40ecu: goto label_40ec;
        case 0x40f0u: goto label_40f0;
        case 0x40f4u: goto label_40f4;
        case 0x40f8u: goto label_40f8;
        case 0x40fcu: goto label_40fc;
        case 0x4100u: goto label_4100;
        case 0x4104u: goto label_4104;
        case 0x4108u: goto label_4108;
        case 0x410cu: goto label_410c;
        case 0x4110u: goto label_4110;
        case 0x4114u: goto label_4114;
        case 0x4118u: goto label_4118;
        case 0x411cu: goto label_411c;
        case 0x4120u: goto label_4120;
        case 0x4124u: goto label_4124;
        case 0x4128u: goto label_4128;
        case 0x412cu: goto label_412c;
        case 0x4130u: goto label_4130;
        case 0x4134u: goto label_4134;
        case 0x4138u: goto label_4138;
        case 0x413cu: goto label_413c;
        case 0x4140u: goto label_4140;
        case 0x4144u: goto label_4144;
        case 0x4148u: goto label_4148;
        case 0x414cu: goto label_414c;
        case 0x4150u: goto label_4150;
        case 0x4154u: goto label_4154;
        case 0x4158u: goto label_4158;
        case 0x415cu: goto label_415c;
        case 0x4160u: goto label_4160;
        case 0x4164u: goto label_4164;
        case 0x4168u: goto label_4168;
        case 0x416cu: goto label_416c;
        case 0x4170u: goto label_4170;
        case 0x4174u: goto label_4174;
        case 0x4178u: goto label_4178;
        case 0x417cu: goto label_417c;
        case 0x4180u: goto label_4180;
        case 0x4184u: goto label_4184;
        case 0x4188u: goto label_4188;
        case 0x418cu: goto label_418c;
        case 0x4190u: goto label_4190;
        case 0x4194u: goto label_4194;
        case 0x4198u: goto label_4198;
        case 0x419cu: goto label_419c;
        case 0x41a0u: goto label_41a0;
        case 0x41a4u: goto label_41a4;
        case 0x41a8u: goto label_41a8;
        case 0x41acu: goto label_41ac;
        case 0x41b0u: goto label_41b0;
        case 0x41b4u: goto label_41b4;
        case 0x41b8u: goto label_41b8;
        case 0x41bcu: goto label_41bc;
        case 0x41c0u: goto label_41c0;
        case 0x41c4u: goto label_41c4;
        case 0x41c8u: goto label_41c8;
        case 0x41ccu: goto label_41cc;
        case 0x41d0u: goto label_41d0;
        case 0x41d4u: goto label_41d4;
        case 0x41d8u: goto label_41d8;
        case 0x41dcu: goto label_41dc;
        case 0x41e0u: goto label_41e0;
        case 0x41e4u: goto label_41e4;
        case 0x41e8u: goto label_41e8;
        case 0x41ecu: goto label_41ec;
        case 0x41f0u: goto label_41f0;
        case 0x41f4u: goto label_41f4;
        case 0x41f8u: goto label_41f8;
        case 0x41fcu: goto label_41fc;
        case 0x4200u: goto label_4200;
        case 0x4204u: goto label_4204;
        case 0x4208u: goto label_4208;
        case 0x420cu: goto label_420c;
        case 0x4210u: goto label_4210;
        case 0x4214u: goto label_4214;
        case 0x4218u: goto label_4218;
        case 0x421cu: goto label_421c;
        case 0x4220u: goto label_4220;
        case 0x4224u: goto label_4224;
        case 0x4228u: goto label_4228;
        case 0x422cu: goto label_422c;
        case 0x4230u: goto label_4230;
        case 0x4234u: goto label_4234;
        case 0x4238u: goto label_4238;
        case 0x423cu: goto label_423c;
        case 0x4240u: goto label_4240;
        case 0x4244u: goto label_4244;
        case 0x4248u: goto label_4248;
        case 0x424cu: goto label_424c;
        case 0x4250u: goto label_4250;
        case 0x4254u: goto label_4254;
        case 0x4258u: goto label_4258;
        case 0x425cu: goto label_425c;
        case 0x4260u: goto label_4260;
        case 0x4264u: goto label_4264;
        case 0x4268u: goto label_4268;
        case 0x426cu: goto label_426c;
        case 0x4270u: goto label_4270;
        case 0x4274u: goto label_4274;
        case 0x4278u: goto label_4278;
        case 0x427cu: goto label_427c;
        case 0x4280u: goto label_4280;
        case 0x4284u: goto label_4284;
        case 0x4288u: goto label_4288;
        case 0x428cu: goto label_428c;
        case 0x4290u: goto label_4290;
        case 0x4294u: goto label_4294;
        case 0x4298u: goto label_4298;
        case 0x429cu: goto label_429c;
        case 0x42a0u: goto label_42a0;
        case 0x42a4u: goto label_42a4;
        case 0x42a8u: goto label_42a8;
        case 0x42acu: goto label_42ac;
        case 0x42b0u: goto label_42b0;
        case 0x42b4u: goto label_42b4;
        case 0x42b8u: goto label_42b8;
        case 0x42bcu: goto label_42bc;
        case 0x42c0u: goto label_42c0;
        case 0x42c4u: goto label_42c4;
        case 0x42c8u: goto label_42c8;
        case 0x42ccu: goto label_42cc;
        case 0x42d0u: goto label_42d0;
        case 0x42d4u: goto label_42d4;
        case 0x42d8u: goto label_42d8;
        case 0x42dcu: goto label_42dc;
        case 0x42e0u: goto label_42e0;
        case 0x42e4u: goto label_42e4;
        case 0x42e8u: goto label_42e8;
        case 0x42ecu: goto label_42ec;
        case 0x42f0u: goto label_42f0;
        case 0x42f4u: goto label_42f4;
        case 0x42f8u: goto label_42f8;
        case 0x42fcu: goto label_42fc;
        case 0x4300u: goto label_4300;
        case 0x4304u: goto label_4304;
        case 0x4308u: goto label_4308;
        case 0x430cu: goto label_430c;
        case 0x4310u: goto label_4310;
        case 0x4314u: goto label_4314;
        case 0x4318u: goto label_4318;
        case 0x431cu: goto label_431c;
        case 0x4320u: goto label_4320;
        case 0x4324u: goto label_4324;
        case 0x4328u: goto label_4328;
        case 0x432cu: goto label_432c;
        case 0x4330u: goto label_4330;
        case 0x4334u: goto label_4334;
        case 0x4338u: goto label_4338;
        case 0x433cu: goto label_433c;
        case 0x4340u: goto label_4340;
        case 0x4344u: goto label_4344;
        case 0x4348u: goto label_4348;
        case 0x434cu: goto label_434c;
        case 0x4350u: goto label_4350;
        case 0x4354u: goto label_4354;
        case 0x4358u: goto label_4358;
        case 0x435cu: goto label_435c;
        case 0x4360u: goto label_4360;
        case 0x4364u: goto label_4364;
        case 0x4368u: goto label_4368;
        case 0x436cu: goto label_436c;
        case 0x4370u: goto label_4370;
        case 0x4374u: goto label_4374;
        case 0x4378u: goto label_4378;
        case 0x437cu: goto label_437c;
        case 0x4380u: goto label_4380;
        case 0x4384u: goto label_4384;
        case 0x4388u: goto label_4388;
        case 0x438cu: goto label_438c;
        case 0x4390u: goto label_4390;
        case 0x4394u: goto label_4394;
        case 0x4398u: goto label_4398;
        case 0x439cu: goto label_439c;
        case 0x43a0u: goto label_43a0;
        case 0x43a4u: goto label_43a4;
        case 0x43a8u: goto label_43a8;
        case 0x43acu: goto label_43ac;
        case 0x43b0u: goto label_43b0;
        case 0x43b4u: goto label_43b4;
        case 0x43b8u: goto label_43b8;
        case 0x43bcu: goto label_43bc;
        case 0x43c0u: goto label_43c0;
        case 0x43c4u: goto label_43c4;
        case 0x43c8u: goto label_43c8;
        case 0x43ccu: goto label_43cc;
        case 0x43d0u: goto label_43d0;
        case 0x43d4u: goto label_43d4;
        case 0x43d8u: goto label_43d8;
        case 0x43dcu: goto label_43dc;
        case 0x43e0u: goto label_43e0;
        case 0x43e4u: goto label_43e4;
        case 0x43e8u: goto label_43e8;
        case 0x43ecu: goto label_43ec;
        case 0x43f0u: goto label_43f0;
        case 0x43f4u: goto label_43f4;
        case 0x43f8u: goto label_43f8;
        case 0x43fcu: goto label_43fc;
        case 0x4400u: goto label_4400;
        case 0x4404u: goto label_4404;
        case 0x4408u: goto label_4408;
        case 0x440cu: goto label_440c;
        case 0x4410u: goto label_4410;
        case 0x4414u: goto label_4414;
        case 0x4418u: goto label_4418;
        case 0x441cu: goto label_441c;
        case 0x4420u: goto label_4420;
        case 0x4424u: goto label_4424;
        case 0x4428u: goto label_4428;
        case 0x442cu: goto label_442c;
        case 0x4430u: goto label_4430;
        case 0x4434u: goto label_4434;
        case 0x4438u: goto label_4438;
        case 0x443cu: goto label_443c;
        case 0x4440u: goto label_4440;
        case 0x4444u: goto label_4444;
        case 0x4448u: goto label_4448;
        case 0x444cu: goto label_444c;
        case 0x4450u: goto label_4450;
        case 0x4454u: goto label_4454;
        case 0x4458u: goto label_4458;
        case 0x445cu: goto label_445c;
        case 0x4460u: goto label_4460;
        case 0x4464u: goto label_4464;
        case 0x4468u: goto label_4468;
        case 0x446cu: goto label_446c;
        case 0x4470u: goto label_4470;
        case 0x4474u: goto label_4474;
        case 0x4478u: goto label_4478;
        case 0x447cu: goto label_447c;
        case 0x4480u: goto label_4480;
        case 0x4484u: goto label_4484;
        case 0x4488u: goto label_4488;
        case 0x448cu: goto label_448c;
        case 0x4490u: goto label_4490;
        case 0x4494u: goto label_4494;
        case 0x4498u: goto label_4498;
        case 0x449cu: goto label_449c;
        case 0x44a0u: goto label_44a0;
        case 0x44a4u: goto label_44a4;
        case 0x44a8u: goto label_44a8;
        case 0x44acu: goto label_44ac;
        case 0x44b0u: goto label_44b0;
        case 0x44b4u: goto label_44b4;
        case 0x44b8u: goto label_44b8;
        case 0x44bcu: goto label_44bc;
        case 0x44c0u: goto label_44c0;
        case 0x44c4u: goto label_44c4;
        case 0x44c8u: goto label_44c8;
        case 0x44ccu: goto label_44cc;
        case 0x44d0u: goto label_44d0;
        case 0x44d4u: goto label_44d4;
        case 0x44d8u: goto label_44d8;
        case 0x44dcu: goto label_44dc;
        case 0x44e0u: goto label_44e0;
        case 0x44e4u: goto label_44e4;
        case 0x44e8u: goto label_44e8;
        case 0x44ecu: goto label_44ec;
        case 0x44f0u: goto label_44f0;
        case 0x44f4u: goto label_44f4;
        case 0x44f8u: goto label_44f8;
        case 0x44fcu: goto label_44fc;
        case 0x4500u: goto label_4500;
        case 0x4504u: goto label_4504;
        case 0x4508u: goto label_4508;
        case 0x450cu: goto label_450c;
        case 0x4510u: goto label_4510;
        case 0x4514u: goto label_4514;
        case 0x4518u: goto label_4518;
        case 0x451cu: goto label_451c;
        case 0x4520u: goto label_4520;
        case 0x4524u: goto label_4524;
        case 0x4528u: goto label_4528;
        case 0x452cu: goto label_452c;
        case 0x4530u: goto label_4530;
        case 0x4534u: goto label_4534;
        case 0x4538u: goto label_4538;
        case 0x453cu: goto label_453c;
        case 0x4540u: goto label_4540;
        case 0x4544u: goto label_4544;
        case 0x4548u: goto label_4548;
        case 0x454cu: goto label_454c;
        case 0x4550u: goto label_4550;
        case 0x4554u: goto label_4554;
        case 0x4558u: goto label_4558;
        case 0x455cu: goto label_455c;
        case 0x4560u: goto label_4560;
        case 0x4564u: goto label_4564;
        case 0x4568u: goto label_4568;
        case 0x456cu: goto label_456c;
        case 0x4570u: goto label_4570;
        case 0x4574u: goto label_4574;
        case 0x4578u: goto label_4578;
        case 0x457cu: goto label_457c;
        case 0x4580u: goto label_4580;
        case 0x4584u: goto label_4584;
        case 0x4588u: goto label_4588;
        case 0x458cu: goto label_458c;
        case 0x4590u: goto label_4590;
        case 0x4594u: goto label_4594;
        case 0x4598u: goto label_4598;
        case 0x459cu: goto label_459c;
        case 0x45a0u: goto label_45a0;
        case 0x45a4u: goto label_45a4;
        case 0x45a8u: goto label_45a8;
        case 0x45acu: goto label_45ac;
        case 0x45b0u: goto label_45b0;
        case 0x45b4u: goto label_45b4;
        case 0x45b8u: goto label_45b8;
        case 0x45bcu: goto label_45bc;
        case 0x45c0u: goto label_45c0;
        case 0x45c4u: goto label_45c4;
        case 0x45c8u: goto label_45c8;
        case 0x45ccu: goto label_45cc;
        case 0x45d0u: goto label_45d0;
        case 0x45d4u: goto label_45d4;
        case 0x45d8u: goto label_45d8;
        case 0x45dcu: goto label_45dc;
        case 0x45e0u: goto label_45e0;
        case 0x45e4u: goto label_45e4;
        case 0x45e8u: goto label_45e8;
        case 0x45ecu: goto label_45ec;
        case 0x45f0u: goto label_45f0;
        case 0x45f4u: goto label_45f4;
        case 0x45f8u: goto label_45f8;
        case 0x45fcu: goto label_45fc;
        case 0x4600u: goto label_4600;
        case 0x4604u: goto label_4604;
        case 0x4608u: goto label_4608;
        case 0x460cu: goto label_460c;
        case 0x4610u: goto label_4610;
        case 0x4614u: goto label_4614;
        case 0x4618u: goto label_4618;
        case 0x461cu: goto label_461c;
        case 0x4620u: goto label_4620;
        case 0x4624u: goto label_4624;
        case 0x4628u: goto label_4628;
        case 0x462cu: goto label_462c;
        case 0x4630u: goto label_4630;
        case 0x4634u: goto label_4634;
        case 0x4638u: goto label_4638;
        case 0x463cu: goto label_463c;
        case 0x4640u: goto label_4640;
        case 0x4644u: goto label_4644;
        case 0x4648u: goto label_4648;
        case 0x464cu: goto label_464c;
        case 0x4650u: goto label_4650;
        case 0x4654u: goto label_4654;
        case 0x4658u: goto label_4658;
        case 0x465cu: goto label_465c;
        case 0x4660u: goto label_4660;
        case 0x4664u: goto label_4664;
        case 0x4668u: goto label_4668;
        case 0x466cu: goto label_466c;
        case 0x4670u: goto label_4670;
        case 0x4674u: goto label_4674;
        case 0x4678u: goto label_4678;
        case 0x467cu: goto label_467c;
        case 0x4680u: goto label_4680;
        case 0x4684u: goto label_4684;
        case 0x4688u: goto label_4688;
        case 0x468cu: goto label_468c;
        case 0x4690u: goto label_4690;
        case 0x4694u: goto label_4694;
        case 0x4698u: goto label_4698;
        case 0x469cu: goto label_469c;
        case 0x46a0u: goto label_46a0;
        case 0x46a4u: goto label_46a4;
        case 0x46a8u: goto label_46a8;
        case 0x46acu: goto label_46ac;
        case 0x46b0u: goto label_46b0;
        case 0x46b4u: goto label_46b4;
        case 0x46b8u: goto label_46b8;
        case 0x46bcu: goto label_46bc;
        case 0x46c0u: goto label_46c0;
        case 0x46c4u: goto label_46c4;
        case 0x46c8u: goto label_46c8;
        case 0x46ccu: goto label_46cc;
        case 0x46d0u: goto label_46d0;
        case 0x46d4u: goto label_46d4;
        case 0x46d8u: goto label_46d8;
        case 0x46dcu: goto label_46dc;
        case 0x46e0u: goto label_46e0;
        case 0x46e4u: goto label_46e4;
        case 0x46e8u: goto label_46e8;
        case 0x46ecu: goto label_46ec;
        case 0x46f0u: goto label_46f0;
        case 0x46f4u: goto label_46f4;
        case 0x46f8u: goto label_46f8;
        case 0x46fcu: goto label_46fc;
        case 0x4700u: goto label_4700;
        case 0x4704u: goto label_4704;
        case 0x4708u: goto label_4708;
        case 0x470cu: goto label_470c;
        case 0x4710u: goto label_4710;
        case 0x4714u: goto label_4714;
        case 0x4718u: goto label_4718;
        case 0x471cu: goto label_471c;
        case 0x4720u: goto label_4720;
        case 0x4724u: goto label_4724;
        case 0x4728u: goto label_4728;
        case 0x472cu: goto label_472c;
        case 0x4730u: goto label_4730;
        case 0x4734u: goto label_4734;
        case 0x4738u: goto label_4738;
        case 0x473cu: goto label_473c;
        case 0x4740u: goto label_4740;
        case 0x4744u: goto label_4744;
        case 0x4748u: goto label_4748;
        case 0x474cu: goto label_474c;
        case 0x4750u: goto label_4750;
        case 0x4754u: goto label_4754;
        case 0x4758u: goto label_4758;
        case 0x475cu: goto label_475c;
        case 0x4760u: goto label_4760;
        case 0x4764u: goto label_4764;
        case 0x4768u: goto label_4768;
        case 0x476cu: goto label_476c;
        case 0x4770u: goto label_4770;
        default: break;
    }

    ctx->pc = 0xb0u;

label_b0:
    // 0xb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_b4:
    // 0xb4: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_b8:
    // 0xb8: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_bc:
    // 0xbc: 0xc0011e5  jal         func_004794
label_c0:
    if (ctx->pc == 0xC0u) {
        // 0xc0: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        ctx->pc = 0xC4u;
        goto label_c4;
    }
    ctx->pc = 0xBCu;
    SET_GPR_U32(ctx, 31, 0xC4u);
    // 0xc0: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0xBCu, 0xC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xC4u;
label_c4:
    // 0xc4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_c8:
    // 0xc8: 0x24840000  addiu       $a0, $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 0));
label_cc:
    // 0xcc: 0xc0011f4  jal         func_0047D0
label_d0:
    if (ctx->pc == 0xD0u) {
        ctx->pc = 0xD4u;
        goto label_d4;
    }
    ctx->pc = 0xCCu;
    SET_GPR_U32(ctx, 31, 0xD4u);
    ctx->pc = 0x47D0u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47D0u, 0xCCu, 0xD4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xD4u;
label_d4:
    // 0xd4: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_d8:
    // 0xd8: 0xc0011e7  jal         func_00479C
label_dc:
    if (ctx->pc == 0xDCu) {
        // 0xdc: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0xE0u;
        goto label_e0;
    }
    ctx->pc = 0xD8u;
    SET_GPR_U32(ctx, 31, 0xE0u);
    // 0xdc: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0xD8u, 0xE0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xE0u;
label_e0:
    // 0xe0: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
label_e4:
    if (ctx->pc == 0xE4u) {
        // 0xe4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0xE8u;
        goto label_e8;
    }
    ctx->pc = 0xE0u;
    {
        const bool branch_taken_0xe0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0xe4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xe0) {
            ctx->pc = 0xFCu;
            goto label_fc;
        }
    }
    ctx->pc = 0xE8u;
label_e8:
    // 0xe8: 0xc000554  jal         func_001550
label_ec:
    if (ctx->pc == 0xECu) {
        ctx->pc = 0xF0u;
        goto label_f0;
    }
    ctx->pc = 0xE8u;
    SET_GPR_U32(ctx, 31, 0xF0u);
    ctx->pc = 0x1550u;
    goto label_1550;
    ctx->pc = 0xF0u;
label_f0:
    // 0xf0: 0xc001168  jal         func_0045A0
label_f4:
    if (ctx->pc == 0xF4u) {
        ctx->pc = 0xF8u;
        goto label_f8;
    }
    ctx->pc = 0xF0u;
    SET_GPR_U32(ctx, 31, 0xF8u);
    ctx->pc = 0x45A0u;
    goto label_45a0;
    ctx->pc = 0xF8u;
label_f8:
    // 0xf8: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_fc:
    // 0xfc: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_100:
    // 0x100: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_104:
    // 0x104: 0x3e00008  jr          $ra
label_108:
    if (ctx->pc == 0x108u) {
        // 0x108: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x10Cu;
        goto label_10c;
    }
    ctx->pc = 0x104u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x108: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x104u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x10Cu;
label_10c:
    // 0x10c: 0x0  nop
    // NOP
label_110:
    // 0x110: 0x42240  sll         $a0, $a0, 9
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 9));
label_114:
    // 0x114: 0x852021  addu        $a0, $a0, $a1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
label_118:
    // 0x118: 0x42040  sll         $a0, $a0, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
label_11c:
    // 0x11c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_120:
    // 0x120: 0x8c425180  lw          $v0, 0x5180($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20864)));
label_124:
    // 0x124: 0x63080  sll         $a2, $a2, 2
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
label_128:
    // 0x128: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_12c:
    // 0x12c: 0x61402  srl         $v0, $a2, 16
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 16));
label_130:
    // 0x130: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_134:
    // 0x134: 0x3e00008  jr          $ra
label_138:
    if (ctx->pc == 0x138u) {
        // 0x138: 0xa4860002  sh          $a2, 0x2($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 6));
        ctx->pc = 0x13Cu;
        goto label_13c;
    }
    ctx->pc = 0x134u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x138: 0xa4860002  sh          $a2, 0x2($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 6));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x134u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x13Cu;
label_13c:
    // 0x13c: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_140:
    // 0x140: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_144:
    // 0x144: 0xa09821  addu        $s3, $a1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_148:
    // 0x148: 0xafbf0020  sw          $ra, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
label_14c:
    // 0x14c: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_150:
    // 0x150: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_154:
    // 0x154: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_158:
    // 0x158: 0x8e700000  lw          $s0, 0x0($s3)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_15c:
    // 0x15c: 0x0  nop
    // NOP
label_160:
    // 0x160: 0x2e110001  sltiu       $s1, $s0, 0x1
    SET_GPR_U64(ctx, 17, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_164:
    // 0x164: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_168:
    if (ctx->pc == 0x168u) {
        // 0x168: 0x809021  addu        $s2, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = 0x16Cu;
        goto label_16c;
    }
    ctx->pc = 0x164u;
    {
        const bool branch_taken_0x164 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x168: 0x809021  addu        $s2, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        if (branch_taken_0x164) {
            ctx->pc = 0x178u;
            goto label_178;
        }
    }
    ctx->pc = 0x16Cu;
label_16c:
    // 0x16c: 0x32020001  andi        $v0, $s0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
label_170:
    // 0x170: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_174:
    if (ctx->pc == 0x174u) {
        ctx->pc = 0x178u;
        goto label_178;
    }
    ctx->pc = 0x170u;
    {
        const bool branch_taken_0x170 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x170) {
            ctx->pc = 0x188u;
            goto label_188;
        }
    }
    ctx->pc = 0x178u;
label_178:
    // 0x178: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_17c:
    // 0x17c: 0x96660004  lhu         $a2, 0x4($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 4)));
label_180:
    // 0x180: 0xc000044  jal         func_000110
label_184:
    if (ctx->pc == 0x184u) {
        // 0x184: 0x24050172  addiu       $a1, $zero, 0x172 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 370));
        ctx->pc = 0x188u;
        goto label_188;
    }
    ctx->pc = 0x180u;
    SET_GPR_U32(ctx, 31, 0x188u);
    // 0x184: 0x24050172  addiu       $a1, $zero, 0x172 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 370));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x188u;
label_188:
    // 0x188: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_18c:
    if (ctx->pc == 0x18Cu) {
        // 0x18c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x190u;
        goto label_190;
    }
    ctx->pc = 0x188u;
    {
        const bool branch_taken_0x188 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x18c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x188) {
            ctx->pc = 0x19Cu;
            goto label_19c;
        }
    }
    ctx->pc = 0x190u;
label_190:
    // 0x190: 0x32020002  andi        $v0, $s0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)2);
label_194:
    // 0x194: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_198:
    if (ctx->pc == 0x198u) {
        ctx->pc = 0x19Cu;
        goto label_19c;
    }
    ctx->pc = 0x194u;
    {
        const bool branch_taken_0x194 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x194) {
            ctx->pc = 0x1A8u;
            goto label_1a8;
        }
    }
    ctx->pc = 0x19Cu;
label_19c:
    // 0x19c: 0x96660006  lhu         $a2, 0x6($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 6)));
label_1a0:
    // 0x1a0: 0xc000044  jal         func_000110
label_1a4:
    if (ctx->pc == 0x1A4u) {
        // 0x1a4: 0x24050174  addiu       $a1, $zero, 0x174 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 372));
        ctx->pc = 0x1A8u;
        goto label_1a8;
    }
    ctx->pc = 0x1A0u;
    SET_GPR_U32(ctx, 31, 0x1A8u);
    // 0x1a4: 0x24050174  addiu       $a1, $zero, 0x174 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 372));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x1A8u;
label_1a8:
    // 0x1a8: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_1ac:
    if (ctx->pc == 0x1ACu) {
        // 0x1ac: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x1B0u;
        goto label_1b0;
    }
    ctx->pc = 0x1A8u;
    {
        const bool branch_taken_0x1a8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x1ac: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x1a8) {
            ctx->pc = 0x1BCu;
            goto label_1bc;
        }
    }
    ctx->pc = 0x1B0u;
label_1b0:
    // 0x1b0: 0x32020004  andi        $v0, $s0, 0x4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)4);
label_1b4:
    // 0x1b4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_1b8:
    if (ctx->pc == 0x1B8u) {
        // 0x1b8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x1BCu;
        goto label_1bc;
    }
    ctx->pc = 0x1B4u;
    {
        const bool branch_taken_0x1b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1b8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x1b4) {
            ctx->pc = 0x1D8u;
            goto label_1d8;
        }
    }
    ctx->pc = 0x1BCu;
label_1bc:
    // 0x1bc: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_1c0:
    // 0x1c0: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1c4:
    // 0x1c4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_1c8:
    // 0x1c8: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_1cc:
    // 0x1cc: 0x96640008  lhu         $a0, 0x8($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 8)));
label_1d0:
    // 0x1d0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1d4:
    // 0x1d4: 0xa4440774  sh          $a0, 0x774($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1908), (uint16_t)GPR_U32(ctx, 4));
label_1d8:
    // 0x1d8: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_1dc:
    if (ctx->pc == 0x1DCu) {
        // 0x1dc: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x1E0u;
        goto label_1e0;
    }
    ctx->pc = 0x1D8u;
    {
        const bool branch_taken_0x1d8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x1dc: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x1d8) {
            ctx->pc = 0x1ECu;
            goto label_1ec;
        }
    }
    ctx->pc = 0x1E0u;
label_1e0:
    // 0x1e0: 0x32020008  andi        $v0, $s0, 0x8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)8);
label_1e4:
    // 0x1e4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_1e8:
    if (ctx->pc == 0x1E8u) {
        // 0x1e8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x1ECu;
        goto label_1ec;
    }
    ctx->pc = 0x1E4u;
    {
        const bool branch_taken_0x1e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1e8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x1e4) {
            ctx->pc = 0x208u;
            goto label_208;
        }
    }
    ctx->pc = 0x1ECu;
label_1ec:
    // 0x1ec: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_1f0:
    // 0x1f0: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1f4:
    // 0x1f4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_1f8:
    // 0x1f8: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_1fc:
    // 0x1fc: 0x9664000a  lhu         $a0, 0xA($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 10)));
label_200:
    // 0x200: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_204:
    // 0x204: 0xa4440776  sh          $a0, 0x776($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1910), (uint16_t)GPR_U32(ctx, 4));
label_208:
    // 0x208: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_20c:
    if (ctx->pc == 0x20Cu) {
        // 0x20c: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x210u;
        goto label_210;
    }
    ctx->pc = 0x208u;
    {
        const bool branch_taken_0x208 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x20c: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x208) {
            ctx->pc = 0x21Cu;
            goto label_21c;
        }
    }
    ctx->pc = 0x210u;
label_210:
    // 0x210: 0x32020010  andi        $v0, $s0, 0x10
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)16);
label_214:
    // 0x214: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_218:
    if (ctx->pc == 0x218u) {
        // 0x218: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x21Cu;
        goto label_21c;
    }
    ctx->pc = 0x214u;
    {
        const bool branch_taken_0x214 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x218: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x214) {
            ctx->pc = 0x238u;
            goto label_238;
        }
    }
    ctx->pc = 0x21Cu;
label_21c:
    // 0x21c: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_220:
    // 0x220: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_224:
    // 0x224: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_228:
    // 0x228: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_22c:
    // 0x22c: 0x9664000c  lhu         $a0, 0xC($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 12)));
label_230:
    // 0x230: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_234:
    // 0x234: 0xa4440778  sh          $a0, 0x778($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1912), (uint16_t)GPR_U32(ctx, 4));
label_238:
    // 0x238: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_23c:
    if (ctx->pc == 0x23Cu) {
        // 0x23c: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x240u;
        goto label_240;
    }
    ctx->pc = 0x238u;
    {
        const bool branch_taken_0x238 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x23c: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x238) {
            ctx->pc = 0x24Cu;
            goto label_24c;
        }
    }
    ctx->pc = 0x240u;
label_240:
    // 0x240: 0x32020020  andi        $v0, $s0, 0x20
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)32);
label_244:
    // 0x244: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_248:
    if (ctx->pc == 0x248u) {
        // 0x248: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x24Cu;
        goto label_24c;
    }
    ctx->pc = 0x244u;
    {
        const bool branch_taken_0x244 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x248: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x244) {
            ctx->pc = 0x268u;
            goto label_268;
        }
    }
    ctx->pc = 0x24Cu;
label_24c:
    // 0x24c: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_250:
    // 0x250: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_254:
    // 0x254: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_258:
    // 0x258: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_25c:
    // 0x25c: 0x9664000e  lhu         $a0, 0xE($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 14)));
label_260:
    // 0x260: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_264:
    // 0x264: 0xa444077a  sh          $a0, 0x77A($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1914), (uint16_t)GPR_U32(ctx, 4));
label_268:
    // 0x268: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_26c:
    if (ctx->pc == 0x26Cu) {
        // 0x26c: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x270u;
        goto label_270;
    }
    ctx->pc = 0x268u;
    {
        const bool branch_taken_0x268 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x26c: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x268) {
            ctx->pc = 0x27Cu;
            goto label_27c;
        }
    }
    ctx->pc = 0x270u;
label_270:
    // 0x270: 0x32020040  andi        $v0, $s0, 0x40
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)64);
label_274:
    // 0x274: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_278:
    if (ctx->pc == 0x278u) {
        // 0x278: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x27Cu;
        goto label_27c;
    }
    ctx->pc = 0x274u;
    {
        const bool branch_taken_0x274 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x278: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x274) {
            ctx->pc = 0x298u;
            goto label_298;
        }
    }
    ctx->pc = 0x27Cu;
label_27c:
    // 0x27c: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_280:
    // 0x280: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_284:
    // 0x284: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_288:
    // 0x288: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_28c:
    // 0x28c: 0x96640010  lhu         $a0, 0x10($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 16)));
label_290:
    // 0x290: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_294:
    // 0x294: 0xa444077c  sh          $a0, 0x77C($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1916), (uint16_t)GPR_U32(ctx, 4));
label_298:
    // 0x298: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_29c:
    if (ctx->pc == 0x29Cu) {
        // 0x29c: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x2A0u;
        goto label_2a0;
    }
    ctx->pc = 0x298u;
    {
        const bool branch_taken_0x298 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x29c: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x298) {
            ctx->pc = 0x2ACu;
            goto label_2ac;
        }
    }
    ctx->pc = 0x2A0u;
label_2a0:
    // 0x2a0: 0x32020080  andi        $v0, $s0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)128);
label_2a4:
    // 0x2a4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_2a8:
    if (ctx->pc == 0x2A8u) {
        // 0x2a8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x2ACu;
        goto label_2ac;
    }
    ctx->pc = 0x2A4u;
    {
        const bool branch_taken_0x2a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2a8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x2a4) {
            ctx->pc = 0x2C8u;
            goto label_2c8;
        }
    }
    ctx->pc = 0x2ACu;
label_2ac:
    // 0x2ac: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_2b0:
    // 0x2b0: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_2b4:
    // 0x2b4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_2b8:
    // 0x2b8: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_2bc:
    // 0x2bc: 0x96640012  lhu         $a0, 0x12($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 18)));
label_2c0:
    // 0x2c0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2c4:
    // 0x2c4: 0xa444077e  sh          $a0, 0x77E($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1918), (uint16_t)GPR_U32(ctx, 4));
label_2c8:
    // 0x2c8: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_2cc:
    if (ctx->pc == 0x2CCu) {
        // 0x2cc: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x2D0u;
        goto label_2d0;
    }
    ctx->pc = 0x2C8u;
    {
        const bool branch_taken_0x2c8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2cc: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x2c8) {
            ctx->pc = 0x2DCu;
            goto label_2dc;
        }
    }
    ctx->pc = 0x2D0u;
label_2d0:
    // 0x2d0: 0x32020100  andi        $v0, $s0, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)256);
label_2d4:
    // 0x2d4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_2d8:
    if (ctx->pc == 0x2D8u) {
        // 0x2d8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x2DCu;
        goto label_2dc;
    }
    ctx->pc = 0x2D4u;
    {
        const bool branch_taken_0x2d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2d8: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x2d4) {
            ctx->pc = 0x2F8u;
            goto label_2f8;
        }
    }
    ctx->pc = 0x2DCu;
label_2dc:
    // 0x2dc: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_2e0:
    // 0x2e0: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_2e4:
    // 0x2e4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_2e8:
    // 0x2e8: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_2ec:
    // 0x2ec: 0x96640014  lhu         $a0, 0x14($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 20)));
label_2f0:
    // 0x2f0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2f4:
    // 0x2f4: 0xa4440780  sh          $a0, 0x780($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1920), (uint16_t)GPR_U32(ctx, 4));
label_2f8:
    // 0x2f8: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_2fc:
    if (ctx->pc == 0x2FCu) {
        // 0x2fc: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x300u;
        goto label_300;
    }
    ctx->pc = 0x2F8u;
    {
        const bool branch_taken_0x2f8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x2fc: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x2f8) {
            ctx->pc = 0x30Cu;
            goto label_30c;
        }
    }
    ctx->pc = 0x300u;
label_300:
    // 0x300: 0x32020200  andi        $v0, $s0, 0x200
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)512);
label_304:
    // 0x304: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_308:
    if (ctx->pc == 0x308u) {
        // 0x308: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x30Cu;
        goto label_30c;
    }
    ctx->pc = 0x304u;
    {
        const bool branch_taken_0x304 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x308: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x304) {
            ctx->pc = 0x328u;
            goto label_328;
        }
    }
    ctx->pc = 0x30Cu;
label_30c:
    // 0x30c: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_310:
    // 0x310: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_314:
    // 0x314: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_318:
    // 0x318: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_31c:
    // 0x31c: 0x96640016  lhu         $a0, 0x16($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 22)));
label_320:
    // 0x320: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_324:
    // 0x324: 0xa4440782  sh          $a0, 0x782($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1922), (uint16_t)GPR_U32(ctx, 4));
label_328:
    // 0x328: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_32c:
    if (ctx->pc == 0x32Cu) {
        // 0x32c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x330u;
        goto label_330;
    }
    ctx->pc = 0x328u;
    {
        const bool branch_taken_0x328 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x32c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x328) {
            ctx->pc = 0x33Cu;
            goto label_33c;
        }
    }
    ctx->pc = 0x330u;
label_330:
    // 0x330: 0x32020400  andi        $v0, $s0, 0x400
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1024);
label_334:
    // 0x334: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_338:
    if (ctx->pc == 0x338u) {
        ctx->pc = 0x33Cu;
        goto label_33c;
    }
    ctx->pc = 0x334u;
    {
        const bool branch_taken_0x334 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x334) {
            ctx->pc = 0x348u;
            goto label_348;
        }
    }
    ctx->pc = 0x33Cu;
label_33c:
    // 0x33c: 0x96660018  lhu         $a2, 0x18($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 24)));
label_340:
    // 0x340: 0xc000044  jal         func_000110
label_344:
    if (ctx->pc == 0x344u) {
        // 0x344: 0x24050176  addiu       $a1, $zero, 0x176 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 374));
        ctx->pc = 0x348u;
        goto label_348;
    }
    ctx->pc = 0x340u;
    SET_GPR_U32(ctx, 31, 0x348u);
    // 0x344: 0x24050176  addiu       $a1, $zero, 0x176 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 374));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x348u;
label_348:
    // 0x348: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_34c:
    if (ctx->pc == 0x34Cu) {
        // 0x34c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x350u;
        goto label_350;
    }
    ctx->pc = 0x348u;
    {
        const bool branch_taken_0x348 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x34c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x348) {
            ctx->pc = 0x35Cu;
            goto label_35c;
        }
    }
    ctx->pc = 0x350u;
label_350:
    // 0x350: 0x32020800  andi        $v0, $s0, 0x800
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)2048);
label_354:
    // 0x354: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_358:
    if (ctx->pc == 0x358u) {
        ctx->pc = 0x35Cu;
        goto label_35c;
    }
    ctx->pc = 0x354u;
    {
        const bool branch_taken_0x354 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x354) {
            ctx->pc = 0x368u;
            goto label_368;
        }
    }
    ctx->pc = 0x35Cu;
label_35c:
    // 0x35c: 0x9666001a  lhu         $a2, 0x1A($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 26)));
label_360:
    // 0x360: 0xc000044  jal         func_000110
label_364:
    if (ctx->pc == 0x364u) {
        // 0x364: 0x24050178  addiu       $a1, $zero, 0x178 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 376));
        ctx->pc = 0x368u;
        goto label_368;
    }
    ctx->pc = 0x360u;
    SET_GPR_U32(ctx, 31, 0x368u);
    // 0x364: 0x24050178  addiu       $a1, $zero, 0x178 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 376));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x368u;
label_368:
    // 0x368: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_36c:
    if (ctx->pc == 0x36Cu) {
        // 0x36c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x370u;
        goto label_370;
    }
    ctx->pc = 0x368u;
    {
        const bool branch_taken_0x368 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x36c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x368) {
            ctx->pc = 0x37Cu;
            goto label_37c;
        }
    }
    ctx->pc = 0x370u;
label_370:
    // 0x370: 0x32021000  andi        $v0, $s0, 0x1000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)4096);
label_374:
    // 0x374: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_378:
    if (ctx->pc == 0x378u) {
        ctx->pc = 0x37Cu;
        goto label_37c;
    }
    ctx->pc = 0x374u;
    {
        const bool branch_taken_0x374 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x374) {
            ctx->pc = 0x388u;
            goto label_388;
        }
    }
    ctx->pc = 0x37Cu;
label_37c:
    // 0x37c: 0x9666001c  lhu         $a2, 0x1C($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 28)));
label_380:
    // 0x380: 0xc000044  jal         func_000110
label_384:
    if (ctx->pc == 0x384u) {
        // 0x384: 0x2405017a  addiu       $a1, $zero, 0x17A (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 378));
        ctx->pc = 0x388u;
        goto label_388;
    }
    ctx->pc = 0x380u;
    SET_GPR_U32(ctx, 31, 0x388u);
    // 0x384: 0x2405017a  addiu       $a1, $zero, 0x17A (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 378));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x388u;
label_388:
    // 0x388: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_38c:
    if (ctx->pc == 0x38Cu) {
        // 0x38c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x390u;
        goto label_390;
    }
    ctx->pc = 0x388u;
    {
        const bool branch_taken_0x388 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x38c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x388) {
            ctx->pc = 0x39Cu;
            goto label_39c;
        }
    }
    ctx->pc = 0x390u;
label_390:
    // 0x390: 0x32022000  andi        $v0, $s0, 0x2000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)8192);
label_394:
    // 0x394: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_398:
    if (ctx->pc == 0x398u) {
        ctx->pc = 0x39Cu;
        goto label_39c;
    }
    ctx->pc = 0x394u;
    {
        const bool branch_taken_0x394 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x394) {
            ctx->pc = 0x3A8u;
            goto label_3a8;
        }
    }
    ctx->pc = 0x39Cu;
label_39c:
    // 0x39c: 0x9666001e  lhu         $a2, 0x1E($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 30)));
label_3a0:
    // 0x3a0: 0xc000044  jal         func_000110
label_3a4:
    if (ctx->pc == 0x3A4u) {
        // 0x3a4: 0x2405017c  addiu       $a1, $zero, 0x17C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 380));
        ctx->pc = 0x3A8u;
        goto label_3a8;
    }
    ctx->pc = 0x3A0u;
    SET_GPR_U32(ctx, 31, 0x3A8u);
    // 0x3a4: 0x2405017c  addiu       $a1, $zero, 0x17C (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 380));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x3A8u;
label_3a8:
    // 0x3a8: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_3ac:
    if (ctx->pc == 0x3ACu) {
        // 0x3ac: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x3B0u;
        goto label_3b0;
    }
    ctx->pc = 0x3A8u;
    {
        const bool branch_taken_0x3a8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x3ac: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x3a8) {
            ctx->pc = 0x3BCu;
            goto label_3bc;
        }
    }
    ctx->pc = 0x3B0u;
label_3b0:
    // 0x3b0: 0x32024000  andi        $v0, $s0, 0x4000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)16384);
label_3b4:
    // 0x3b4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_3b8:
    if (ctx->pc == 0x3B8u) {
        ctx->pc = 0x3BCu;
        goto label_3bc;
    }
    ctx->pc = 0x3B4u;
    {
        const bool branch_taken_0x3b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3b4) {
            ctx->pc = 0x3C8u;
            goto label_3c8;
        }
    }
    ctx->pc = 0x3BCu;
label_3bc:
    // 0x3bc: 0x96660020  lhu         $a2, 0x20($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 32)));
label_3c0:
    // 0x3c0: 0xc000044  jal         func_000110
label_3c4:
    if (ctx->pc == 0x3C4u) {
        // 0x3c4: 0x2405017e  addiu       $a1, $zero, 0x17E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 382));
        ctx->pc = 0x3C8u;
        goto label_3c8;
    }
    ctx->pc = 0x3C0u;
    SET_GPR_U32(ctx, 31, 0x3C8u);
    // 0x3c4: 0x2405017e  addiu       $a1, $zero, 0x17E (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 382));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x3C8u;
label_3c8:
    // 0x3c8: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
label_3cc:
    if (ctx->pc == 0x3CCu) {
        // 0x3cc: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x3D0u;
        goto label_3d0;
    }
    ctx->pc = 0x3C8u;
    {
        const bool branch_taken_0x3c8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x3cc: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x3c8) {
            ctx->pc = 0x3DCu;
            goto label_3dc;
        }
    }
    ctx->pc = 0x3D0u;
label_3d0:
    // 0x3d0: 0x32028000  andi        $v0, $s0, 0x8000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)32768);
label_3d4:
    // 0x3d4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_3d8:
    if (ctx->pc == 0x3D8u) {
        ctx->pc = 0x3DCu;
        goto label_3dc;
    }
    ctx->pc = 0x3D4u;
    {
        const bool branch_taken_0x3d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3d4) {
            ctx->pc = 0x3E8u;
            goto label_3e8;
        }
    }
    ctx->pc = 0x3DCu;
label_3dc:
    // 0x3dc: 0x96660022  lhu         $a2, 0x22($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 34)));
label_3e0:
    // 0x3e0: 0xc000044  jal         func_000110
label_3e4:
    if (ctx->pc == 0x3E4u) {
        // 0x3e4: 0x24050180  addiu       $a1, $zero, 0x180 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
        ctx->pc = 0x3E8u;
        goto label_3e8;
    }
    ctx->pc = 0x3E0u;
    SET_GPR_U32(ctx, 31, 0x3E8u);
    // 0x3e4: 0x24050180  addiu       $a1, $zero, 0x180 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 384));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x3E8u;
label_3e8:
    // 0x3e8: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_3ec:
    if (ctx->pc == 0x3ECu) {
        // 0x3ec: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x3F0u;
        goto label_3f0;
    }
    ctx->pc = 0x3E8u;
    {
        const bool branch_taken_0x3e8 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x3ec: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x3e8) {
            ctx->pc = 0x400u;
            goto label_400;
        }
    }
    ctx->pc = 0x3F0u;
label_3f0:
    // 0x3f0: 0x3c020001  lui         $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
label_3f4:
    // 0x3f4: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_3f8:
    // 0x3f8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_3fc:
    if (ctx->pc == 0x3FCu) {
        ctx->pc = 0x400u;
        goto label_400;
    }
    ctx->pc = 0x3F8u;
    {
        const bool branch_taken_0x3f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3f8) {
            ctx->pc = 0x40Cu;
            goto label_40c;
        }
    }
    ctx->pc = 0x400u;
label_400:
    // 0x400: 0x96660024  lhu         $a2, 0x24($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 36)));
label_404:
    // 0x404: 0xc000044  jal         func_000110
label_408:
    if (ctx->pc == 0x408u) {
        // 0x408: 0x24050182  addiu       $a1, $zero, 0x182 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 386));
        ctx->pc = 0x40Cu;
        goto label_40c;
    }
    ctx->pc = 0x404u;
    SET_GPR_U32(ctx, 31, 0x40Cu);
    // 0x408: 0x24050182  addiu       $a1, $zero, 0x182 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 386));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x40Cu;
label_40c:
    // 0x40c: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_410:
    if (ctx->pc == 0x410u) {
        // 0x410: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x414u;
        goto label_414;
    }
    ctx->pc = 0x40Cu;
    {
        const bool branch_taken_0x40c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x410: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x40c) {
            ctx->pc = 0x424u;
            goto label_424;
        }
    }
    ctx->pc = 0x414u;
label_414:
    // 0x414: 0x3c020002  lui         $v0, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
label_418:
    // 0x418: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_41c:
    // 0x41c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_420:
    if (ctx->pc == 0x420u) {
        ctx->pc = 0x424u;
        goto label_424;
    }
    ctx->pc = 0x41Cu;
    {
        const bool branch_taken_0x41c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x41c) {
            ctx->pc = 0x430u;
            goto label_430;
        }
    }
    ctx->pc = 0x424u;
label_424:
    // 0x424: 0x96660026  lhu         $a2, 0x26($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 38)));
label_428:
    // 0x428: 0xc000044  jal         func_000110
label_42c:
    if (ctx->pc == 0x42Cu) {
        // 0x42c: 0x24050184  addiu       $a1, $zero, 0x184 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 388));
        ctx->pc = 0x430u;
        goto label_430;
    }
    ctx->pc = 0x428u;
    SET_GPR_U32(ctx, 31, 0x430u);
    // 0x42c: 0x24050184  addiu       $a1, $zero, 0x184 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 388));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x430u;
label_430:
    // 0x430: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_434:
    if (ctx->pc == 0x434u) {
        // 0x434: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x438u;
        goto label_438;
    }
    ctx->pc = 0x430u;
    {
        const bool branch_taken_0x430 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x434: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x430) {
            ctx->pc = 0x448u;
            goto label_448;
        }
    }
    ctx->pc = 0x438u;
label_438:
    // 0x438: 0x3c020004  lui         $v0, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4 << 16));
label_43c:
    // 0x43c: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_440:
    // 0x440: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_444:
    if (ctx->pc == 0x444u) {
        ctx->pc = 0x448u;
        goto label_448;
    }
    ctx->pc = 0x440u;
    {
        const bool branch_taken_0x440 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x440) {
            ctx->pc = 0x454u;
            goto label_454;
        }
    }
    ctx->pc = 0x448u;
label_448:
    // 0x448: 0x96660028  lhu         $a2, 0x28($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 40)));
label_44c:
    // 0x44c: 0xc000044  jal         func_000110
label_450:
    if (ctx->pc == 0x450u) {
        // 0x450: 0x24050186  addiu       $a1, $zero, 0x186 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 390));
        ctx->pc = 0x454u;
        goto label_454;
    }
    ctx->pc = 0x44Cu;
    SET_GPR_U32(ctx, 31, 0x454u);
    // 0x450: 0x24050186  addiu       $a1, $zero, 0x186 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 390));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x454u;
label_454:
    // 0x454: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_458:
    if (ctx->pc == 0x458u) {
        // 0x458: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x45Cu;
        goto label_45c;
    }
    ctx->pc = 0x454u;
    {
        const bool branch_taken_0x454 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x458: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x454) {
            ctx->pc = 0x46Cu;
            goto label_46c;
        }
    }
    ctx->pc = 0x45Cu;
label_45c:
    // 0x45c: 0x3c020008  lui         $v0, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
label_460:
    // 0x460: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_464:
    // 0x464: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_468:
    if (ctx->pc == 0x468u) {
        ctx->pc = 0x46Cu;
        goto label_46c;
    }
    ctx->pc = 0x464u;
    {
        const bool branch_taken_0x464 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x464) {
            ctx->pc = 0x478u;
            goto label_478;
        }
    }
    ctx->pc = 0x46Cu;
label_46c:
    // 0x46c: 0x9666002a  lhu         $a2, 0x2A($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 42)));
label_470:
    // 0x470: 0xc000044  jal         func_000110
label_474:
    if (ctx->pc == 0x474u) {
        // 0x474: 0x24050188  addiu       $a1, $zero, 0x188 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 392));
        ctx->pc = 0x478u;
        goto label_478;
    }
    ctx->pc = 0x470u;
    SET_GPR_U32(ctx, 31, 0x478u);
    // 0x474: 0x24050188  addiu       $a1, $zero, 0x188 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 392));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x478u;
label_478:
    // 0x478: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_47c:
    if (ctx->pc == 0x47Cu) {
        // 0x47c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x480u;
        goto label_480;
    }
    ctx->pc = 0x478u;
    {
        const bool branch_taken_0x478 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x47c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x478) {
            ctx->pc = 0x490u;
            goto label_490;
        }
    }
    ctx->pc = 0x480u;
label_480:
    // 0x480: 0x3c020010  lui         $v0, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
label_484:
    // 0x484: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_488:
    // 0x488: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_48c:
    if (ctx->pc == 0x48Cu) {
        ctx->pc = 0x490u;
        goto label_490;
    }
    ctx->pc = 0x488u;
    {
        const bool branch_taken_0x488 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x488) {
            ctx->pc = 0x49Cu;
            goto label_49c;
        }
    }
    ctx->pc = 0x490u;
label_490:
    // 0x490: 0x9666002c  lhu         $a2, 0x2C($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 44)));
label_494:
    // 0x494: 0xc000044  jal         func_000110
label_498:
    if (ctx->pc == 0x498u) {
        // 0x498: 0x2405018a  addiu       $a1, $zero, 0x18A (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 394));
        ctx->pc = 0x49Cu;
        goto label_49c;
    }
    ctx->pc = 0x494u;
    SET_GPR_U32(ctx, 31, 0x49Cu);
    // 0x498: 0x2405018a  addiu       $a1, $zero, 0x18A (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 394));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x49Cu;
label_49c:
    // 0x49c: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_4a0:
    if (ctx->pc == 0x4A0u) {
        // 0x4a0: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x4A4u;
        goto label_4a4;
    }
    ctx->pc = 0x49Cu;
    {
        const bool branch_taken_0x49c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x4a0: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x49c) {
            ctx->pc = 0x4B4u;
            goto label_4b4;
        }
    }
    ctx->pc = 0x4A4u;
label_4a4:
    // 0x4a4: 0x3c020020  lui         $v0, 0x20
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
label_4a8:
    // 0x4a8: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_4ac:
    // 0x4ac: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_4b0:
    if (ctx->pc == 0x4B0u) {
        ctx->pc = 0x4B4u;
        goto label_4b4;
    }
    ctx->pc = 0x4ACu;
    {
        const bool branch_taken_0x4ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x4ac) {
            ctx->pc = 0x4C0u;
            goto label_4c0;
        }
    }
    ctx->pc = 0x4B4u;
label_4b4:
    // 0x4b4: 0x9666002e  lhu         $a2, 0x2E($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 46)));
label_4b8:
    // 0x4b8: 0xc000044  jal         func_000110
label_4bc:
    if (ctx->pc == 0x4BCu) {
        // 0x4bc: 0x2405018c  addiu       $a1, $zero, 0x18C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 396));
        ctx->pc = 0x4C0u;
        goto label_4c0;
    }
    ctx->pc = 0x4B8u;
    SET_GPR_U32(ctx, 31, 0x4C0u);
    // 0x4bc: 0x2405018c  addiu       $a1, $zero, 0x18C (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 396));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x4C0u;
label_4c0:
    // 0x4c0: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_4c4:
    if (ctx->pc == 0x4C4u) {
        // 0x4c4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x4C8u;
        goto label_4c8;
    }
    ctx->pc = 0x4C0u;
    {
        const bool branch_taken_0x4c0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x4c4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x4c0) {
            ctx->pc = 0x4D8u;
            goto label_4d8;
        }
    }
    ctx->pc = 0x4C8u;
label_4c8:
    // 0x4c8: 0x3c020040  lui         $v0, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)64 << 16));
label_4cc:
    // 0x4cc: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_4d0:
    // 0x4d0: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_4d4:
    if (ctx->pc == 0x4D4u) {
        ctx->pc = 0x4D8u;
        goto label_4d8;
    }
    ctx->pc = 0x4D0u;
    {
        const bool branch_taken_0x4d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x4d0) {
            ctx->pc = 0x4E4u;
            goto label_4e4;
        }
    }
    ctx->pc = 0x4D8u;
label_4d8:
    // 0x4d8: 0x96660030  lhu         $a2, 0x30($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 48)));
label_4dc:
    // 0x4dc: 0xc000044  jal         func_000110
label_4e0:
    if (ctx->pc == 0x4E0u) {
        // 0x4e0: 0x2405018e  addiu       $a1, $zero, 0x18E (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 398));
        ctx->pc = 0x4E4u;
        goto label_4e4;
    }
    ctx->pc = 0x4DCu;
    SET_GPR_U32(ctx, 31, 0x4E4u);
    // 0x4e0: 0x2405018e  addiu       $a1, $zero, 0x18E (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 398));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x4E4u;
label_4e4:
    // 0x4e4: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_4e8:
    if (ctx->pc == 0x4E8u) {
        // 0x4e8: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x4ECu;
        goto label_4ec;
    }
    ctx->pc = 0x4E4u;
    {
        const bool branch_taken_0x4e4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x4e8: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x4e4) {
            ctx->pc = 0x4FCu;
            goto label_4fc;
        }
    }
    ctx->pc = 0x4ECu;
label_4ec:
    // 0x4ec: 0x3c020080  lui         $v0, 0x80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)128 << 16));
label_4f0:
    // 0x4f0: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_4f4:
    // 0x4f4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_4f8:
    if (ctx->pc == 0x4F8u) {
        ctx->pc = 0x4FCu;
        goto label_4fc;
    }
    ctx->pc = 0x4F4u;
    {
        const bool branch_taken_0x4f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x4f4) {
            ctx->pc = 0x508u;
            goto label_508;
        }
    }
    ctx->pc = 0x4FCu;
label_4fc:
    // 0x4fc: 0x96660032  lhu         $a2, 0x32($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 50)));
label_500:
    // 0x500: 0xc000044  jal         func_000110
label_504:
    if (ctx->pc == 0x504u) {
        // 0x504: 0x24050190  addiu       $a1, $zero, 0x190 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
        ctx->pc = 0x508u;
        goto label_508;
    }
    ctx->pc = 0x500u;
    SET_GPR_U32(ctx, 31, 0x508u);
    // 0x504: 0x24050190  addiu       $a1, $zero, 0x190 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 400));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x508u;
label_508:
    // 0x508: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_50c:
    if (ctx->pc == 0x50Cu) {
        // 0x50c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x510u;
        goto label_510;
    }
    ctx->pc = 0x508u;
    {
        const bool branch_taken_0x508 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x50c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x508) {
            ctx->pc = 0x520u;
            goto label_520;
        }
    }
    ctx->pc = 0x510u;
label_510:
    // 0x510: 0x3c020100  lui         $v0, 0x100
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)256 << 16));
label_514:
    // 0x514: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_518:
    // 0x518: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_51c:
    if (ctx->pc == 0x51Cu) {
        ctx->pc = 0x520u;
        goto label_520;
    }
    ctx->pc = 0x518u;
    {
        const bool branch_taken_0x518 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x518) {
            ctx->pc = 0x52Cu;
            goto label_52c;
        }
    }
    ctx->pc = 0x520u;
label_520:
    // 0x520: 0x96660034  lhu         $a2, 0x34($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 52)));
label_524:
    // 0x524: 0xc000044  jal         func_000110
label_528:
    if (ctx->pc == 0x528u) {
        // 0x528: 0x24050192  addiu       $a1, $zero, 0x192 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 402));
        ctx->pc = 0x52Cu;
        goto label_52c;
    }
    ctx->pc = 0x524u;
    SET_GPR_U32(ctx, 31, 0x52Cu);
    // 0x528: 0x24050192  addiu       $a1, $zero, 0x192 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 402));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x52Cu;
label_52c:
    // 0x52c: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_530:
    if (ctx->pc == 0x530u) {
        // 0x530: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x534u;
        goto label_534;
    }
    ctx->pc = 0x52Cu;
    {
        const bool branch_taken_0x52c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x530: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x52c) {
            ctx->pc = 0x544u;
            goto label_544;
        }
    }
    ctx->pc = 0x534u;
label_534:
    // 0x534: 0x3c020200  lui         $v0, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)512 << 16));
label_538:
    // 0x538: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_53c:
    // 0x53c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_540:
    if (ctx->pc == 0x540u) {
        ctx->pc = 0x544u;
        goto label_544;
    }
    ctx->pc = 0x53Cu;
    {
        const bool branch_taken_0x53c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x53c) {
            ctx->pc = 0x550u;
            goto label_550;
        }
    }
    ctx->pc = 0x544u;
label_544:
    // 0x544: 0x96660036  lhu         $a2, 0x36($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 54)));
label_548:
    // 0x548: 0xc000044  jal         func_000110
label_54c:
    if (ctx->pc == 0x54Cu) {
        // 0x54c: 0x24050194  addiu       $a1, $zero, 0x194 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 404));
        ctx->pc = 0x550u;
        goto label_550;
    }
    ctx->pc = 0x548u;
    SET_GPR_U32(ctx, 31, 0x550u);
    // 0x54c: 0x24050194  addiu       $a1, $zero, 0x194 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 404));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x550u;
label_550:
    // 0x550: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_554:
    if (ctx->pc == 0x554u) {
        // 0x554: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x558u;
        goto label_558;
    }
    ctx->pc = 0x550u;
    {
        const bool branch_taken_0x550 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x554: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x550) {
            ctx->pc = 0x568u;
            goto label_568;
        }
    }
    ctx->pc = 0x558u;
label_558:
    // 0x558: 0x3c020400  lui         $v0, 0x400
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1024 << 16));
label_55c:
    // 0x55c: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_560:
    // 0x560: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_564:
    if (ctx->pc == 0x564u) {
        ctx->pc = 0x568u;
        goto label_568;
    }
    ctx->pc = 0x560u;
    {
        const bool branch_taken_0x560 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x560) {
            ctx->pc = 0x574u;
            goto label_574;
        }
    }
    ctx->pc = 0x568u;
label_568:
    // 0x568: 0x96660038  lhu         $a2, 0x38($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 56)));
label_56c:
    // 0x56c: 0xc000044  jal         func_000110
label_570:
    if (ctx->pc == 0x570u) {
        // 0x570: 0x24050196  addiu       $a1, $zero, 0x196 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 406));
        ctx->pc = 0x574u;
        goto label_574;
    }
    ctx->pc = 0x56Cu;
    SET_GPR_U32(ctx, 31, 0x574u);
    // 0x570: 0x24050196  addiu       $a1, $zero, 0x196 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 406));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x574u;
label_574:
    // 0x574: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_578:
    if (ctx->pc == 0x578u) {
        // 0x578: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x57Cu;
        goto label_57c;
    }
    ctx->pc = 0x574u;
    {
        const bool branch_taken_0x574 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x578: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x574) {
            ctx->pc = 0x58Cu;
            goto label_58c;
        }
    }
    ctx->pc = 0x57Cu;
label_57c:
    // 0x57c: 0x3c020800  lui         $v0, 0x800
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2048 << 16));
label_580:
    // 0x580: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_584:
    // 0x584: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_588:
    if (ctx->pc == 0x588u) {
        ctx->pc = 0x58Cu;
        goto label_58c;
    }
    ctx->pc = 0x584u;
    {
        const bool branch_taken_0x584 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x584) {
            ctx->pc = 0x598u;
            goto label_598;
        }
    }
    ctx->pc = 0x58Cu;
label_58c:
    // 0x58c: 0x9666003a  lhu         $a2, 0x3A($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 58)));
label_590:
    // 0x590: 0xc000044  jal         func_000110
label_594:
    if (ctx->pc == 0x594u) {
        // 0x594: 0x24050198  addiu       $a1, $zero, 0x198 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 408));
        ctx->pc = 0x598u;
        goto label_598;
    }
    ctx->pc = 0x590u;
    SET_GPR_U32(ctx, 31, 0x598u);
    // 0x594: 0x24050198  addiu       $a1, $zero, 0x198 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 408));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x598u;
label_598:
    // 0x598: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_59c:
    if (ctx->pc == 0x59Cu) {
        // 0x59c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x5A0u;
        goto label_5a0;
    }
    ctx->pc = 0x598u;
    {
        const bool branch_taken_0x598 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x59c: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x598) {
            ctx->pc = 0x5B0u;
            goto label_5b0;
        }
    }
    ctx->pc = 0x5A0u;
label_5a0:
    // 0x5a0: 0x3c021000  lui         $v0, 0x1000
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
label_5a4:
    // 0x5a4: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_5a8:
    // 0x5a8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_5ac:
    if (ctx->pc == 0x5ACu) {
        ctx->pc = 0x5B0u;
        goto label_5b0;
    }
    ctx->pc = 0x5A8u;
    {
        const bool branch_taken_0x5a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x5a8) {
            ctx->pc = 0x5BCu;
            goto label_5bc;
        }
    }
    ctx->pc = 0x5B0u;
label_5b0:
    // 0x5b0: 0x9666003c  lhu         $a2, 0x3C($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 60)));
label_5b4:
    // 0x5b4: 0xc000044  jal         func_000110
label_5b8:
    if (ctx->pc == 0x5B8u) {
        // 0x5b8: 0x2405019a  addiu       $a1, $zero, 0x19A (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 410));
        ctx->pc = 0x5BCu;
        goto label_5bc;
    }
    ctx->pc = 0x5B4u;
    SET_GPR_U32(ctx, 31, 0x5BCu);
    // 0x5b8: 0x2405019a  addiu       $a1, $zero, 0x19A (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 410));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x5BCu;
label_5bc:
    // 0x5bc: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_5c0:
    if (ctx->pc == 0x5C0u) {
        // 0x5c0: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x5C4u;
        goto label_5c4;
    }
    ctx->pc = 0x5BCu;
    {
        const bool branch_taken_0x5bc = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x5c0: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        if (branch_taken_0x5bc) {
            ctx->pc = 0x5D4u;
            goto label_5d4;
        }
    }
    ctx->pc = 0x5C4u;
label_5c4:
    // 0x5c4: 0x3c022000  lui         $v0, 0x2000
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
label_5c8:
    // 0x5c8: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_5cc:
    // 0x5cc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_5d0:
    if (ctx->pc == 0x5D0u) {
        ctx->pc = 0x5D4u;
        goto label_5d4;
    }
    ctx->pc = 0x5CCu;
    {
        const bool branch_taken_0x5cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x5cc) {
            ctx->pc = 0x5E0u;
            goto label_5e0;
        }
    }
    ctx->pc = 0x5D4u;
label_5d4:
    // 0x5d4: 0x9666003e  lhu         $a2, 0x3E($s3)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 62)));
label_5d8:
    // 0x5d8: 0xc000044  jal         func_000110
label_5dc:
    if (ctx->pc == 0x5DCu) {
        // 0x5dc: 0x2405019c  addiu       $a1, $zero, 0x19C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 412));
        ctx->pc = 0x5E0u;
        goto label_5e0;
    }
    ctx->pc = 0x5D8u;
    SET_GPR_U32(ctx, 31, 0x5E0u);
    // 0x5dc: 0x2405019c  addiu       $a1, $zero, 0x19C (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 412));
    ctx->pc = 0x110u;
    goto label_110;
    ctx->pc = 0x5E0u;
label_5e0:
    // 0x5e0: 0x16200005  bnez        $s1, . + 4 + (0x5 << 2)
label_5e4:
    if (ctx->pc == 0x5E4u) {
        // 0x5e4: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x5E8u;
        goto label_5e8;
    }
    ctx->pc = 0x5E0u;
    {
        const bool branch_taken_0x5e0 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x5e4: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x5e0) {
            ctx->pc = 0x5F8u;
            goto label_5f8;
        }
    }
    ctx->pc = 0x5E8u;
label_5e8:
    // 0x5e8: 0x3c024000  lui         $v0, 0x4000
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
label_5ec:
    // 0x5ec: 0x2021024  and         $v0, $s0, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & GPR_U64(ctx, 2));
label_5f0:
    // 0x5f0: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_5f4:
    if (ctx->pc == 0x5F4u) {
        // 0x5f4: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x5F8u;
        goto label_5f8;
    }
    ctx->pc = 0x5F0u;
    {
        const bool branch_taken_0x5f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x5f4: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x5f0) {
            ctx->pc = 0x614u;
            goto label_614;
        }
    }
    ctx->pc = 0x5F8u;
label_5f8:
    // 0x5f8: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_5fc:
    // 0x5fc: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_600:
    // 0x600: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_604:
    // 0x604: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_608:
    // 0x608: 0x96640040  lhu         $a0, 0x40($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 64)));
label_60c:
    // 0x60c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_610:
    // 0x610: 0xa4440784  sh          $a0, 0x784($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1924), (uint16_t)GPR_U32(ctx, 4));
label_614:
    // 0x614: 0x16200003  bnez        $s1, . + 4 + (0x3 << 2)
label_618:
    if (ctx->pc == 0x618u) {
        // 0x618: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x61Cu;
        goto label_61c;
    }
    ctx->pc = 0x614u;
    {
        const bool branch_taken_0x614 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x618: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x614) {
            ctx->pc = 0x624u;
            goto label_624;
        }
    }
    ctx->pc = 0x61Cu;
label_61c:
    // 0x61c: 0x6010008  bgez        $s0, . + 4 + (0x8 << 2)
label_620:
    if (ctx->pc == 0x620u) {
        ctx->pc = 0x624u;
        goto label_624;
    }
    ctx->pc = 0x61Cu;
    {
        const bool branch_taken_0x61c = (GPR_S32(ctx, 16) >= 0);
        if (branch_taken_0x61c) {
            ctx->pc = 0x640u;
            goto label_640;
        }
    }
    ctx->pc = 0x624u;
label_624:
    // 0x624: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_628:
    // 0x628: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_62c:
    // 0x62c: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_630:
    // 0x630: 0x8c635180  lw          $v1, 0x5180($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20864)));
label_634:
    // 0x634: 0x96640042  lhu         $a0, 0x42($s3)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 19), 66)));
label_638:
    // 0x638: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_63c:
    // 0x63c: 0xa4440786  sh          $a0, 0x786($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 1926), (uint16_t)GPR_U32(ctx, 4));
label_640:
    // 0x640: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_644:
    // 0x644: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_648:
    // 0x648: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_64c:
    // 0x64c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_650:
    // 0x650: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_654:
    // 0x654: 0x3e00008  jr          $ra
label_658:
    if (ctx->pc == 0x658u) {
        // 0x658: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0x65Cu;
        goto label_65c;
    }
    ctx->pc = 0x654u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x658: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x654u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x65Cu;
label_65c:
    // 0x65c: 0x0  nop
    // NOP
label_660:
    // 0x660: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
label_664:
    // 0x664: 0xafb60038  sw          $s6, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 22));
label_668:
    // 0x668: 0x80b021  addu        $s6, $a0, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_66c:
    // 0x66c: 0xafb50034  sw          $s5, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 21));
label_670:
    // 0x670: 0xa0a821  addu        $s5, $a1, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_674:
    // 0x674: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
label_678:
    // 0x678: 0x30d000ff  andi        $s0, $a2, 0xFF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
label_67c:
    // 0x67c: 0x2e02000a  sltiu       $v0, $s0, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
label_680:
    // 0x680: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
label_684:
    // 0x684: 0xafb40030  sw          $s4, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 20));
label_688:
    // 0x688: 0xafb3002c  sw          $s3, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
label_68c:
    // 0x68c: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
label_690:
    // 0x690: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_694:
    if (ctx->pc == 0x694u) {
        // 0x694: 0xafb10024  sw          $s1, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
        ctx->pc = 0x698u;
        goto label_698;
    }
    ctx->pc = 0x690u;
    {
        const bool branch_taken_0x690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x694: 0xafb10024  sw          $s1, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
        if (branch_taken_0x690) {
            ctx->pc = 0x6A0u;
            goto label_6a0;
        }
    }
    ctx->pc = 0x698u;
label_698:
    // 0x698: 0x8000218  j           func_000860
label_69c:
    if (ctx->pc == 0x69Cu) {
        // 0x69c: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x6A0u;
        goto label_6a0;
    }
    ctx->pc = 0x698u;
    // 0x69c: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
    ctx->pc = 0x860u;
    goto label_860;
    ctx->pc = 0x6A0u;
label_6a0:
    // 0x6a0: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
label_6a4:
    if (ctx->pc == 0x6A4u) {
        // 0x6a4: 0x152100  sll         $a0, $s5, 4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 21), 4));
        ctx->pc = 0x6A8u;
        goto label_6a8;
    }
    ctx->pc = 0x6A0u;
    {
        const bool branch_taken_0x6a0 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x6a4: 0x152100  sll         $a0, $s5, 4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 21), 4));
        if (branch_taken_0x6a0) {
            ctx->pc = 0x6B0u;
            goto label_6b0;
        }
    }
    ctx->pc = 0x6A8u;
label_6a8:
    // 0x6a8: 0x8000218  j           func_000860
label_6ac:
    if (ctx->pc == 0x6ACu) {
        // 0x6ac: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x6B0u;
        goto label_6b0;
    }
    ctx->pc = 0x6A8u;
    // 0x6ac: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x860u;
    goto label_860;
    ctx->pc = 0x6B0u;
label_6b0:
    // 0x6b0: 0xc000866  jal         func_002198
label_6b4:
    if (ctx->pc == 0x6B4u) {
        // 0x6b4: 0x34840004  ori         $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4);
        ctx->pc = 0x6B8u;
        goto label_6b8;
    }
    ctx->pc = 0x6B0u;
    SET_GPR_U32(ctx, 31, 0x6B8u);
    // 0x6b4: 0x34840004  ori         $a0, $a0, 0x4 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4);
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x6B8u;
label_6b8:
    // 0x6b8: 0x14400069  bnez        $v0, . + 4 + (0x69 << 2)
label_6bc:
    if (ctx->pc == 0x6BCu) {
        // 0x6bc: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        ctx->pc = 0x6C0u;
        goto label_6c0;
    }
    ctx->pc = 0x6B8u;
    {
        const bool branch_taken_0x6b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x6bc: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        if (branch_taken_0x6b8) {
            ctx->pc = 0x860u;
            goto label_860;
        }
    }
    ctx->pc = 0x6C0u;
label_6c0:
    // 0x6c0: 0x159880  sll         $s3, $s5, 2
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 21), 2));
label_6c4:
    // 0x6c4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_6c8:
    // 0x6c8: 0x731821  addu        $v1, $v1, $s3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
label_6cc:
    // 0x6cc: 0x8c63518c  lw          $v1, 0x518C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20876)));
label_6d0:
    // 0x6d0: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_6d4:
    // 0x6d4: 0x14620062  bne         $v1, $v0, . + 4 + (0x62 << 2)
label_6d8:
    if (ctx->pc == 0x6D8u) {
        // 0x6d8: 0x2402ff37  addiu       $v0, $zero, -0xC9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967095));
        ctx->pc = 0x6DCu;
        goto label_6dc;
    }
    ctx->pc = 0x6D4u;
    {
        const bool branch_taken_0x6d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x6d8: 0x2402ff37  addiu       $v0, $zero, -0xC9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967095));
        if (branch_taken_0x6d4) {
            ctx->pc = 0x860u;
            goto label_860;
        }
    }
    ctx->pc = 0x6DCu;
label_6dc:
    // 0x6dc: 0xc0011e9  jal         func_0047A4
label_6e0:
    if (ctx->pc == 0x6E0u) {
        ctx->pc = 0x6E4u;
        goto label_6e4;
    }
    ctx->pc = 0x6DCu;
    SET_GPR_U32(ctx, 31, 0x6E4u);
    ctx->pc = 0x47A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47A4u, 0x6DCu, 0x6E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x6E4u;
label_6e4:
    // 0x6e4: 0x1440005e  bnez        $v0, . + 4 + (0x5E << 2)
label_6e8:
    if (ctx->pc == 0x6E8u) {
        // 0x6e8: 0x2402ff36  addiu       $v0, $zero, -0xCA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967094));
        ctx->pc = 0x6ECu;
        goto label_6ec;
    }
    ctx->pc = 0x6E4u;
    {
        const bool branch_taken_0x6e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x6e8: 0x2402ff36  addiu       $v0, $zero, -0xCA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967094));
        if (branch_taken_0x6e4) {
            ctx->pc = 0x860u;
            goto label_860;
        }
    }
    ctx->pc = 0x6ECu;
label_6ec:
    // 0x6ec: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
label_6f0:
    // 0x6f0: 0x101080  sll         $v0, $s0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_6f4:
    // 0x6f4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_6f8:
    // 0x6f8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_6fc:
    // 0x6fc: 0x8c224a98  lw          $v0, 0x4A98($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 19096)));
label_700:
    // 0x700: 0xa021  addu        $s4, $zero, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_704:
    // 0x704: 0xc000440  jal         func_001100
label_708:
    if (ctx->pc == 0x708u) {
        // 0x708: 0x288c0  sll         $s1, $v0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
        ctx->pc = 0x70Cu;
        goto label_70c;
    }
    ctx->pc = 0x704u;
    SET_GPR_U32(ctx, 31, 0x70Cu);
    // 0x708: 0x288c0  sll         $s1, $v0, 3 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    ctx->pc = 0x1100u;
    goto label_1100;
    ctx->pc = 0x70Cu;
label_70c:
    // 0x70c: 0x2623ffff  addiu       $v1, $s1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_710:
    // 0x710: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_714:
    // 0x714: 0x29042  srl         $s2, $v0, 1
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
label_718:
    // 0x718: 0x3222003f  andi        $v0, $s1, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)63);
label_71c:
    // 0x71c: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
label_720:
    if (ctx->pc == 0x720u) {
        // 0x720: 0x111182  srl         $v0, $s1, 6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 6));
        ctx->pc = 0x724u;
        goto label_724;
    }
    ctx->pc = 0x71Cu;
    {
        const bool branch_taken_0x71c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x720: 0x111182  srl         $v0, $s1, 6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 6));
        if (branch_taken_0x71c) {
            ctx->pc = 0x73Cu;
            goto label_73c;
        }
    }
    ctx->pc = 0x724u;
label_724:
    // 0x724: 0x28980  sll         $s1, $v0, 6
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
label_728:
    // 0x728: 0xc000440  jal         func_001100
label_72c:
    if (ctx->pc == 0x72Cu) {
        // 0x72c: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        ctx->pc = 0x730u;
        goto label_730;
    }
    ctx->pc = 0x728u;
    SET_GPR_U32(ctx, 31, 0x730u);
    // 0x72c: 0x2c02021  addu        $a0, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x1100u;
    goto label_1100;
    ctx->pc = 0x730u;
label_730:
    // 0x730: 0x2623ffff  addiu       $v1, $s1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_734:
    // 0x734: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_738:
    // 0x738: 0x2a042  srl         $s4, $v0, 1
    SET_GPR_S32(ctx, 20, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
label_73c:
    // 0x73c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_740:
    // 0x740: 0x531021  addu        $v0, $v0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
label_744:
    // 0x744: 0x8c425318  lw          $v0, 0x5318($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21272)));
label_748:
    // 0x748: 0x0  nop
    // NOP
label_74c:
    // 0x74c: 0xafa2001c  sw          $v0, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 2));
label_750:
    // 0x750: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_754:
    // 0x754: 0x531021  addu        $v0, $v0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
label_758:
    // 0x758: 0x8c4259a0  lw          $v0, 0x59A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22944)));
label_75c:
    // 0x75c: 0x0  nop
    // NOP
label_760:
    // 0x760: 0xafa20018  sw          $v0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
label_764:
    // 0x764: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_768:
    // 0x768: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_76c:
    // 0x76c: 0xac205318  sw          $zero, 0x5318($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21272), GPR_U32(ctx, 0));
label_770:
    // 0x770: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_774:
    // 0x774: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_778:
    // 0x778: 0xac2059a0  sw          $zero, 0x59A0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22944), GPR_U32(ctx, 0));
label_77c:
    // 0x77c: 0x12800012  beqz        $s4, . + 4 + (0x12 << 2)
label_780:
    if (ctx->pc == 0x780u) {
        // 0x780: 0x24020040  addiu       $v0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->pc = 0x784u;
        goto label_784;
    }
    ctx->pc = 0x77Cu;
    {
        const bool branch_taken_0x77c = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        // 0x780: 0x24020040  addiu       $v0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        if (branch_taken_0x77c) {
            ctx->pc = 0x7C8u;
            goto label_7c8;
        }
    }
    ctx->pc = 0x784u;
label_784:
    // 0x784: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_788:
    // 0x788: 0x151400  sll         $v0, $s5, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 21), 16));
label_78c:
    // 0x78c: 0x29c03  sra         $s3, $v0, 16
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 2), 16));
label_790:
    // 0x790: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_794:
    // 0x794: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_798:
    // 0x798: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_79c:
    // 0x79c: 0x24c64d70  addiu       $a2, $a2, 0x4D70
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19824));
label_7a0:
    // 0x7a0: 0xc000624  jal         func_001890
label_7a4:
    if (ctx->pc == 0x7A4u) {
        // 0x7a4: 0x123840  sll         $a3, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
        ctx->pc = 0x7A8u;
        goto label_7a8;
    }
    ctx->pc = 0x7A0u;
    SET_GPR_U32(ctx, 31, 0x7A8u);
    // 0x7a4: 0x123840  sll         $a3, $s2, 1 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    ctx->pc = 0x1890u;
    goto label_1890;
    ctx->pc = 0x7A8u;
label_7a8:
    // 0x7a8: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_7ac:
    // 0x7ac: 0x6000020  bltz        $s0, . + 4 + (0x20 << 2)
label_7b0:
    if (ctx->pc == 0x7B0u) {
        // 0x7b0: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0x7B4u;
        goto label_7b4;
    }
    ctx->pc = 0x7ACu;
    {
        const bool branch_taken_0x7ac = (GPR_S32(ctx, 16) < 0);
        // 0x7b0: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x7ac) {
            ctx->pc = 0x830u;
            goto label_830;
        }
    }
    ctx->pc = 0x7B4u;
label_7b4:
    // 0x7b4: 0xc0006bc  jal         func_001AF0
label_7b8:
    if (ctx->pc == 0x7B8u) {
        // 0x7b8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x7BCu;
        goto label_7bc;
    }
    ctx->pc = 0x7B4u;
    SET_GPR_U32(ctx, 31, 0x7BCu);
    // 0x7b8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1AF0u;
    goto label_1af0;
    ctx->pc = 0x7BCu;
label_7bc:
    // 0x7bc: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_7c0:
    // 0x7c0: 0x600001b  bltz        $s0, . + 4 + (0x1B << 2)
label_7c4:
    if (ctx->pc == 0x7C4u) {
        // 0x7c4: 0x2809021  addu        $s2, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0x7C8u;
        goto label_7c8;
    }
    ctx->pc = 0x7C0u;
    {
        const bool branch_taken_0x7c0 = (GPR_S32(ctx, 16) < 0);
        // 0x7c4: 0x2809021  addu        $s2, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0x7c0) {
            ctx->pc = 0x830u;
            goto label_830;
        }
    }
    ctx->pc = 0x7C8u;
label_7c8:
    // 0x7c8: 0x24140001  addiu       $s4, $zero, 0x1
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_7cc:
    // 0x7cc: 0x151400  sll         $v0, $s5, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 21), 16));
label_7d0:
    // 0x7d0: 0x29c03  sra         $s3, $v0, 16
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 2), 16));
label_7d4:
    // 0x7d4: 0x2e220401  sltiu       $v0, $s1, 0x401
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)1025) ? 1 : 0);
label_7d8:
    // 0x7d8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_7dc:
    if (ctx->pc == 0x7DCu) {
        // 0x7dc: 0x24030400  addiu       $v1, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->pc = 0x7E0u;
        goto label_7e0;
    }
    ctx->pc = 0x7D8u;
    {
        const bool branch_taken_0x7d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x7dc: 0x24030400  addiu       $v1, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        if (branch_taken_0x7d8) {
            ctx->pc = 0x7E8u;
            goto label_7e8;
        }
    }
    ctx->pc = 0x7E0u;
label_7e0:
    // 0x7e0: 0x2201821  addu        $v1, $s1, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_7e4:
    // 0x7e4: 0xa021  addu        $s4, $zero, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_7e8:
    // 0x7e8: 0xafa30010  sw          $v1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
label_7ec:
    // 0x7ec: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_7f0:
    // 0x7f0: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_7f4:
    // 0x7f4: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_7f8:
    // 0x7f8: 0x24c64d70  addiu       $a2, $a2, 0x4D70
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19824));
label_7fc:
    // 0x7fc: 0xc000624  jal         func_001890
label_800:
    if (ctx->pc == 0x800u) {
        // 0x800: 0x123840  sll         $a3, $s2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
        ctx->pc = 0x804u;
        goto label_804;
    }
    ctx->pc = 0x7FCu;
    SET_GPR_U32(ctx, 31, 0x804u);
    // 0x800: 0x123840  sll         $a3, $s2, 1 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    ctx->pc = 0x1890u;
    goto label_1890;
    ctx->pc = 0x804u;
label_804:
    // 0x804: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_808:
    // 0x808: 0x6000009  bltz        $s0, . + 4 + (0x9 << 2)
label_80c:
    if (ctx->pc == 0x80Cu) {
        // 0x80c: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0x810u;
        goto label_810;
    }
    ctx->pc = 0x808u;
    {
        const bool branch_taken_0x808 = (GPR_S32(ctx, 16) < 0);
        // 0x80c: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x808) {
            ctx->pc = 0x830u;
            goto label_830;
        }
    }
    ctx->pc = 0x810u;
label_810:
    // 0x810: 0xc0006bc  jal         func_001AF0
label_814:
    if (ctx->pc == 0x814u) {
        // 0x814: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x818u;
        goto label_818;
    }
    ctx->pc = 0x810u;
    SET_GPR_U32(ctx, 31, 0x818u);
    // 0x814: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1AF0u;
    goto label_1af0;
    ctx->pc = 0x818u;
label_818:
    // 0x818: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_81c:
    // 0x81c: 0x6000004  bltz        $s0, . + 4 + (0x4 << 2)
label_820:
    if (ctx->pc == 0x820u) {
        // 0x820: 0x2631fc00  addiu       $s1, $s1, -0x400 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294966272));
        ctx->pc = 0x824u;
        goto label_824;
    }
    ctx->pc = 0x81Cu;
    {
        const bool branch_taken_0x81c = (GPR_S32(ctx, 16) < 0);
        // 0x820: 0x2631fc00  addiu       $s1, $s1, -0x400 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294966272));
        if (branch_taken_0x81c) {
            ctx->pc = 0x830u;
            goto label_830;
        }
    }
    ctx->pc = 0x824u;
label_824:
    // 0x824: 0x1680ffeb  bnez        $s4, . + 4 + (-0x15 << 2)
label_828:
    if (ctx->pc == 0x828u) {
        // 0x828: 0x26520200  addiu       $s2, $s2, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 512));
        ctx->pc = 0x82Cu;
        goto label_82c;
    }
    ctx->pc = 0x824u;
    {
        const bool branch_taken_0x824 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 0));
        // 0x828: 0x26520200  addiu       $s2, $s2, 0x200 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 512));
        if (branch_taken_0x824) {
            ctx->pc = 0x7D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_7d4;
        }
    }
    ctx->pc = 0x82Cu;
label_82c:
    // 0x82c: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_830:
    // 0x830: 0x8fa2001c  lw          $v0, 0x1C($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_834:
    // 0x834: 0x151880  sll         $v1, $s5, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 21), 2));
label_838:
    // 0x838: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_83c:
    // 0x83c: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_840:
    // 0x840: 0xac225318  sw          $v0, 0x5318($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21272), GPR_U32(ctx, 2));
label_844:
    // 0x844: 0x8fa20018  lw          $v0, 0x18($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_848:
    // 0x848: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_84c:
    // 0x84c: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_850:
    // 0x850: 0xac2259a0  sw          $v0, 0x59A0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22944), GPR_U32(ctx, 2));
label_854:
    // 0x854: 0xc0007a4  jal         func_001E90
label_858:
    if (ctx->pc == 0x858u) {
        ctx->pc = 0x85Cu;
        goto label_85c;
    }
    ctx->pc = 0x854u;
    SET_GPR_U32(ctx, 31, 0x85Cu);
    ctx->pc = 0x1E90u;
    goto label_1e90;
    ctx->pc = 0x85Cu;
label_85c:
    // 0x85c: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_860:
    // 0x860: 0x8fbf003c  lw          $ra, 0x3C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
label_864:
    // 0x864: 0x8fb60038  lw          $s6, 0x38($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_868:
    // 0x868: 0x8fb50034  lw          $s5, 0x34($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_86c:
    // 0x86c: 0x8fb40030  lw          $s4, 0x30($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_870:
    // 0x870: 0x8fb3002c  lw          $s3, 0x2C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_874:
    // 0x874: 0x8fb20028  lw          $s2, 0x28($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_878:
    // 0x878: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_87c:
    // 0x87c: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_880:
    // 0x880: 0x3e00008  jr          $ra
label_884:
    if (ctx->pc == 0x884u) {
        // 0x884: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x888u;
        goto label_888;
    }
    ctx->pc = 0x880u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x884: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x880u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x888u;
label_888:
    // 0x888: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_88c:
    // 0x88c: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_890:
    // 0x890: 0x49080  sll         $s2, $a0, 2
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_894:
    // 0x894: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_898:
    // 0x898: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_89c:
    // 0x89c: 0x8c425358  lw          $v0, 0x5358($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21336)));
label_8a0:
    // 0x8a0: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_8a4:
    // 0x8a4: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_8a8:
    // 0x8a8: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_8ac:
    // 0x8ac: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_8b0:
    // 0x8b0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_8b4:
    // 0x8b4: 0x320821  addu        $at, $at, $s2
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 18)));
label_8b8:
    // 0x8b8: 0xac225358  sw          $v0, 0x5358($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21336), GPR_U32(ctx, 2));
label_8bc:
    // 0x8bc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_8c0:
    // 0x8c0: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_8c4:
    // 0x8c4: 0x8c425350  lw          $v0, 0x5350($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21328)));
label_8c8:
    // 0x8c8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_8cc:
    // 0x8cc: 0x721821  addu        $v1, $v1, $s2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
label_8d0:
    // 0x8d0: 0x8c635358  lw          $v1, 0x5358($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21336)));
label_8d4:
    // 0x8d4: 0x2442ffff  addiu       $v0, $v0, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
label_8d8:
    // 0x8d8: 0x62182a  slt         $v1, $v1, $v0
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
label_8dc:
    // 0x8dc: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
label_8e0:
    if (ctx->pc == 0x8E0u) {
        // 0x8e0: 0x48900  sll         $s1, $a0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
        ctx->pc = 0x8E4u;
        goto label_8e4;
    }
    ctx->pc = 0x8DCu;
    {
        const bool branch_taken_0x8dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        // 0x8e0: 0x48900  sll         $s1, $a0, 4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
        if (branch_taken_0x8dc) {
            ctx->pc = 0x8F4u;
            goto label_8f4;
        }
    }
    ctx->pc = 0x8E4u;
label_8e4:
    // 0x8e4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_8e8:
    // 0x8e8: 0x320821  addu        $at, $at, $s2
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 18)));
label_8ec:
    // 0x8ec: 0xac205320  sw          $zero, 0x5320($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21280), GPR_U32(ctx, 0));
label_8f0:
    // 0x8f0: 0x48900  sll         $s1, $a0, 4
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
label_8f4:
    // 0x8f4: 0x48040  sll         $s0, $a0, 1
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
label_8f8:
    // 0x8f8: 0x2048021  addu        $s0, $s0, $a0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_8fc:
    // 0x8fc: 0x108140  sll         $s0, $s0, 5
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 5));
label_900:
    // 0x900: 0x2048021  addu        $s0, $s0, $a0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
label_904:
    // 0x904: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_908:
    // 0x908: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_90c:
    // 0x90c: 0x8c425358  lw          $v0, 0x5358($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21336)));
label_910:
    // 0x910: 0x1080c0  sll         $s0, $s0, 3
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
label_914:
    // 0x914: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_918:
    // 0x918: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_91c:
    // 0x91c: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_920:
    // 0x920: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_924:
    // 0x924: 0x8ca55360  lw          $a1, 0x5360($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 21344)));
label_928:
    // 0x928: 0xc000866  jal         func_002198
label_92c:
    if (ctx->pc == 0x92Cu) {
        // 0x92c: 0x36240002  ori         $a0, $s1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)2);
        ctx->pc = 0x930u;
        goto label_930;
    }
    ctx->pc = 0x928u;
    SET_GPR_U32(ctx, 31, 0x930u);
    // 0x92c: 0x36240002  ori         $a0, $s1, 0x2 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)2);
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x930u;
label_930:
    // 0x930: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_934:
    // 0x934: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_938:
    // 0x938: 0x8c425358  lw          $v0, 0x5358($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21336)));
label_93c:
    // 0x93c: 0x36240006  ori         $a0, $s1, 0x6
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)6);
label_940:
    // 0x940: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_944:
    // 0x944: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_948:
    // 0x948: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_94c:
    // 0x94c: 0xc23021  addu        $a2, $a2, $v0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
label_950:
    // 0x950: 0x8cc65364  lw          $a2, 0x5364($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 21348)));
label_954:
    // 0x954: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_958:
    // 0x958: 0xc000866  jal         func_002198
label_95c:
    if (ctx->pc == 0x95Cu) {
        // 0x95c: 0x24a54d70  addiu       $a1, $a1, 0x4D70 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19824));
        ctx->pc = 0x960u;
        goto label_960;
    }
    ctx->pc = 0x958u;
    SET_GPR_U32(ctx, 31, 0x960u);
    // 0x95c: 0x24a54d70  addiu       $a1, $a1, 0x4D70 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 19824));
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x960u;
label_960:
    // 0x960: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_964:
    // 0x964: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_968:
    // 0x968: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_96c:
    // 0x96c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_970:
    // 0x970: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_974:
    // 0x974: 0x3e00008  jr          $ra
label_978:
    if (ctx->pc == 0x978u) {
        // 0x978: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x97Cu;
        goto label_97c;
    }
    ctx->pc = 0x974u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x978: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x974u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x97Cu;
label_97c:
    // 0x97c: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_980:
    // 0x980: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_984:
    // 0x984: 0x80a021  addu        $s4, $a0, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_988:
    // 0x988: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_98c:
    // 0x98c: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_990:
    // 0x990: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_994:
    // 0x994: 0x30d000ff  andi        $s0, $a2, 0xFF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
label_998:
    // 0x998: 0x2e02000a  sltiu       $v0, $s0, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
label_99c:
    // 0x99c: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
label_9a0:
    // 0x9a0: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_9a4:
    // 0x9a4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_9a8:
    if (ctx->pc == 0x9A8u) {
        // 0x9a8: 0xafb1001c  sw          $s1, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
        ctx->pc = 0x9ACu;
        goto label_9ac;
    }
    ctx->pc = 0x9A4u;
    {
        const bool branch_taken_0x9a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x9a8: 0xafb1001c  sw          $s1, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
        if (branch_taken_0x9a4) {
            ctx->pc = 0x9B4u;
            goto label_9b4;
        }
    }
    ctx->pc = 0x9ACu;
label_9ac:
    // 0x9ac: 0x80002db  j           func_000B6C
label_9b0:
    if (ctx->pc == 0x9B0u) {
        // 0x9b0: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x9B4u;
        goto label_9b4;
    }
    ctx->pc = 0x9ACu;
    // 0x9b0: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
    ctx->pc = 0xB6Cu;
    goto label_b6c;
    ctx->pc = 0x9B4u;
label_9b4:
    // 0x9b4: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
label_9b8:
    if (ctx->pc == 0x9B8u) {
        // 0x9b8: 0x122100  sll         $a0, $s2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
        ctx->pc = 0x9BCu;
        goto label_9bc;
    }
    ctx->pc = 0x9B4u;
    {
        const bool branch_taken_0x9b4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        // 0x9b8: 0x122100  sll         $a0, $s2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
        if (branch_taken_0x9b4) {
            ctx->pc = 0x9C4u;
            goto label_9c4;
        }
    }
    ctx->pc = 0x9BCu;
label_9bc:
    // 0x9bc: 0x80002db  j           func_000B6C
label_9c0:
    if (ctx->pc == 0x9C0u) {
        // 0x9c0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x9C4u;
        goto label_9c4;
    }
    ctx->pc = 0x9BCu;
    // 0x9c0: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0xB6Cu;
    goto label_b6c;
    ctx->pc = 0x9C4u;
label_9c4:
    // 0x9c4: 0xc000866  jal         func_002198
label_9c8:
    if (ctx->pc == 0x9C8u) {
        // 0x9c8: 0x34840004  ori         $a0, $a0, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4);
        ctx->pc = 0x9CCu;
        goto label_9cc;
    }
    ctx->pc = 0x9C4u;
    SET_GPR_U32(ctx, 31, 0x9CCu);
    // 0x9c8: 0x34840004  ori         $a0, $a0, 0x4 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4);
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x9CCu;
label_9cc:
    // 0x9cc: 0x14400067  bnez        $v0, . + 4 + (0x67 << 2)
label_9d0:
    if (ctx->pc == 0x9D0u) {
        // 0x9d0: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        ctx->pc = 0x9D4u;
        goto label_9d4;
    }
    ctx->pc = 0x9CCu;
    {
        const bool branch_taken_0x9cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x9d0: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        if (branch_taken_0x9cc) {
            ctx->pc = 0xB6Cu;
            goto label_b6c;
        }
    }
    ctx->pc = 0x9D4u;
label_9d4:
    // 0x9d4: 0x129880  sll         $s3, $s2, 2
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
label_9d8:
    // 0x9d8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_9dc:
    // 0x9dc: 0x731821  addu        $v1, $v1, $s3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
label_9e0:
    // 0x9e0: 0x8c63518c  lw          $v1, 0x518C($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20876)));
label_9e4:
    // 0x9e4: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_9e8:
    // 0x9e8: 0x14620060  bne         $v1, $v0, . + 4 + (0x60 << 2)
label_9ec:
    if (ctx->pc == 0x9ECu) {
        // 0x9ec: 0x2402ff37  addiu       $v0, $zero, -0xC9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967095));
        ctx->pc = 0x9F0u;
        goto label_9f0;
    }
    ctx->pc = 0x9E8u;
    {
        const bool branch_taken_0x9e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x9ec: 0x2402ff37  addiu       $v0, $zero, -0xC9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967095));
        if (branch_taken_0x9e8) {
            ctx->pc = 0xB6Cu;
            goto label_b6c;
        }
    }
    ctx->pc = 0x9F0u;
label_9f0:
    // 0x9f0: 0x101080  sll         $v0, $s0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_9f4:
    // 0x9f4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_9f8:
    // 0x9f8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_9fc:
    // 0x9fc: 0x8c224a98  lw          $v0, 0x4A98($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 19096)));
label_a00:
    // 0xa00: 0x2802021  addu        $a0, $s4, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_a04:
    // 0xa04: 0xc000440  jal         func_001100
label_a08:
    if (ctx->pc == 0xA08u) {
        // 0xa08: 0x288c0  sll         $s1, $v0, 3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
        ctx->pc = 0xA0Cu;
        goto label_a0c;
    }
    ctx->pc = 0xA04u;
    SET_GPR_U32(ctx, 31, 0xA0Cu);
    // 0xa08: 0x288c0  sll         $s1, $v0, 3 (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    ctx->pc = 0x1100u;
    goto label_1100;
    ctx->pc = 0xA0Cu;
label_a0c:
    // 0xa0c: 0x2623ffff  addiu       $v1, $s1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_a10:
    // 0xa10: 0x433823  subu        $a3, $v0, $v1
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_a14:
    // 0xa14: 0x3222003f  andi        $v0, $s1, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)63);
label_a18:
    // 0xa18: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
label_a1c:
    if (ctx->pc == 0xA1Cu) {
        // 0xa1c: 0x111182  srl         $v0, $s1, 6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 6));
        ctx->pc = 0xA20u;
        goto label_a20;
    }
    ctx->pc = 0xA18u;
    {
        const bool branch_taken_0xa18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xa1c: 0x111182  srl         $v0, $s1, 6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 17), 6));
        if (branch_taken_0xa18) {
            ctx->pc = 0xA60u;
            goto label_a60;
        }
    }
    ctx->pc = 0xA20u;
label_a20:
    // 0xa20: 0x28980  sll         $s1, $v0, 6
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
label_a24:
    // 0xa24: 0x24020040  addiu       $v0, $zero, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
label_a28:
    // 0xa28: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_a2c:
    // 0xa2c: 0x122400  sll         $a0, $s2, 16
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
label_a30:
    // 0xa30: 0x42403  sra         $a0, $a0, 16
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
label_a34:
    // 0xa34: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_a38:
    // 0xa38: 0x24c64d70  addiu       $a2, $a2, 0x4D70
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19824));
label_a3c:
    // 0xa3c: 0xc000624  jal         func_001890
label_a40:
    if (ctx->pc == 0xA40u) {
        // 0xa40: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->pc = 0xA44u;
        goto label_a44;
    }
    ctx->pc = 0xA3Cu;
    SET_GPR_U32(ctx, 31, 0xA44u);
    // 0xa40: 0x24050008  addiu       $a1, $zero, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x1890u;
    goto label_1890;
    ctx->pc = 0xA44u;
label_a44:
    // 0xa44: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_a48:
    // 0xa48: 0x6000045  bltz        $s0, . + 4 + (0x45 << 2)
label_a4c:
    if (ctx->pc == 0xA4Cu) {
        ctx->pc = 0xA50u;
        goto label_a50;
    }
    ctx->pc = 0xA48u;
    {
        const bool branch_taken_0xa48 = (GPR_S32(ctx, 16) < 0);
        if (branch_taken_0xa48) {
            ctx->pc = 0xB60u;
            goto label_b60;
        }
    }
    ctx->pc = 0xA50u;
label_a50:
    // 0xa50: 0xc000440  jal         func_001100
label_a54:
    if (ctx->pc == 0xA54u) {
        // 0xa54: 0x2802021  addu        $a0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0xA58u;
        goto label_a58;
    }
    ctx->pc = 0xA50u;
    SET_GPR_U32(ctx, 31, 0xA58u);
    // 0xa54: 0x2802021  addu        $a0, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x1100u;
    goto label_1100;
    ctx->pc = 0xA58u;
label_a58:
    // 0xa58: 0x2623ffff  addiu       $v1, $s1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_a5c:
    // 0xa5c: 0x433823  subu        $a3, $v0, $v1
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_a60:
    // 0xa60: 0x121040  sll         $v0, $s2, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_a64:
    // 0xa64: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_a68:
    // 0xa68: 0x21140  sll         $v0, $v0, 5
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
label_a6c:
    // 0xa6c: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_a70:
    // 0xa70: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_a74:
    // 0xa74: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_a78:
    // 0xa78: 0x24635360  addiu       $v1, $v1, 0x5360
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 21344));
label_a7c:
    // 0xa7c: 0x434021  addu        $t0, $v0, $v1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_a80:
    // 0xa80: 0x24e90400  addiu       $t1, $a3, 0x400
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), 1024));
label_a84:
    // 0xa84: 0x2623fc00  addiu       $v1, $s1, -0x400
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294966272));
label_a88:
    // 0xa88: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_a8c:
    // 0xa8c: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_a90:
    // 0xa90: 0xac205350  sw          $zero, 0x5350($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21328), GPR_U32(ctx, 0));
label_a94:
    // 0xa94: 0x28620401  slti        $v0, $v1, 0x401
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)1025) ? 1 : 0);
label_a98:
    // 0xa98: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
label_a9c:
    if (ctx->pc == 0xA9Cu) {
        // 0xa9c: 0x122400  sll         $a0, $s2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
        ctx->pc = 0xAA0u;
        goto label_aa0;
    }
    ctx->pc = 0xA98u;
    {
        const bool branch_taken_0xa98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xa9c: 0x122400  sll         $a0, $s2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
        if (branch_taken_0xa98) {
            ctx->pc = 0xAE8u;
            goto label_ae8;
        }
    }
    ctx->pc = 0xAA0u;
label_aa0:
    // 0xaa0: 0x24050400  addiu       $a1, $zero, 0x400
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_aa4:
    // 0xaa4: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_aa8:
    // 0xaa8: 0xad090000  sw          $t1, 0x0($t0)
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 9));
label_aac:
    // 0xaac: 0xad050004  sw          $a1, 0x4($t0)
    WRITE32(ADD32(GPR_U32(ctx, 8), 4), GPR_U32(ctx, 5));
label_ab0:
    // 0xab0: 0x25080008  addiu       $t0, $t0, 0x8
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 8));
label_ab4:
    // 0xab4: 0x25290400  addiu       $t1, $t1, 0x400
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1024));
label_ab8:
    // 0xab8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_abc:
    // 0xabc: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_ac0:
    // 0xac0: 0x8c425350  lw          $v0, 0x5350($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21328)));
label_ac4:
    // 0xac4: 0x2463fc00  addiu       $v1, $v1, -0x400
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294966272));
label_ac8:
    // 0xac8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_acc:
    // 0xacc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_ad0:
    // 0xad0: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
label_ad4:
    // 0xad4: 0xac225350  sw          $v0, 0x5350($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21328), GPR_U32(ctx, 2));
label_ad8:
    // 0xad8: 0x28620401  slti        $v0, $v1, 0x401
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)1025) ? 1 : 0);
label_adc:
    // 0xadc: 0x1040fff2  beqz        $v0, . + 4 + (-0xE << 2)
label_ae0:
    if (ctx->pc == 0xAE0u) {
        ctx->pc = 0xAE4u;
        goto label_ae4;
    }
    ctx->pc = 0xADCu;
    {
        const bool branch_taken_0xadc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0xadc) {
            ctx->pc = 0xAA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_aa8;
        }
    }
    ctx->pc = 0xAE4u;
label_ae4:
    // 0xae4: 0x122400  sll         $a0, $s2, 16
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
label_ae8:
    // 0xae8: 0x42403  sra         $a0, $a0, 16
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
label_aec:
    // 0xaec: 0x2821  addu        $a1, $zero, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_af0:
    // 0xaf0: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_af4:
    // 0xaf4: 0x24c64d70  addiu       $a2, $a2, 0x4D70
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19824));
label_af8:
    // 0xaf8: 0xad090000  sw          $t1, 0x0($t0)
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 9));
label_afc:
    // 0xafc: 0xad030004  sw          $v1, 0x4($t0)
    WRITE32(ADD32(GPR_U32(ctx, 8), 4), GPR_U32(ctx, 3));
label_b00:
    // 0xb00: 0x124080  sll         $t0, $s2, 2
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
label_b04:
    // 0xb04: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_b08:
    // 0xb08: 0x481021  addu        $v0, $v0, $t0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
label_b0c:
    // 0xb0c: 0x8c425350  lw          $v0, 0x5350($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21328)));
label_b10:
    // 0xb10: 0x24030400  addiu       $v1, $zero, 0x400
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_b14:
    // 0xb14: 0xafa30010  sw          $v1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
label_b18:
    // 0xb18: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_b1c:
    // 0xb1c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_b20:
    // 0xb20: 0x280821  addu        $at, $at, $t0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 8)));
label_b24:
    // 0xb24: 0xac225350  sw          $v0, 0x5350($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21328), GPR_U32(ctx, 2));
label_b28:
    // 0xb28: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_b2c:
    // 0xb2c: 0x24420888  addiu       $v0, $v0, 0x888
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2184));
label_b30:
    // 0xb30: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_b34:
    // 0xb34: 0x280821  addu        $at, $at, $t0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 8)));
label_b38:
    // 0xb38: 0xac225320  sw          $v0, 0x5320($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21280), GPR_U32(ctx, 2));
label_b3c:
    // 0xb3c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_b40:
    // 0xb40: 0x280821  addu        $at, $at, $t0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 8)));
label_b44:
    // 0xb44: 0xac205358  sw          $zero, 0x5358($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21336), GPR_U32(ctx, 0));
label_b48:
    // 0xb48: 0xc000624  jal         func_001890
label_b4c:
    if (ctx->pc == 0xB4Cu) {
        ctx->pc = 0xB50u;
        goto label_b50;
    }
    ctx->pc = 0xB48u;
    SET_GPR_U32(ctx, 31, 0xB50u);
    ctx->pc = 0x1890u;
    goto label_1890;
    ctx->pc = 0xB50u;
label_b50:
    // 0xb50: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_b54:
    // 0xb54: 0x6000002  bltz        $s0, . + 4 + (0x2 << 2)
label_b58:
    if (ctx->pc == 0xB58u) {
        ctx->pc = 0xB5Cu;
        goto label_b5c;
    }
    ctx->pc = 0xB54u;
    {
        const bool branch_taken_0xb54 = (GPR_S32(ctx, 16) < 0);
        if (branch_taken_0xb54) {
            ctx->pc = 0xB60u;
            goto label_b60;
        }
    }
    ctx->pc = 0xB5Cu;
label_b5c:
    // 0xb5c: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_b60:
    // 0xb60: 0xc0007a4  jal         func_001E90
label_b64:
    if (ctx->pc == 0xB64u) {
        ctx->pc = 0xB68u;
        goto label_b68;
    }
    ctx->pc = 0xB60u;
    SET_GPR_U32(ctx, 31, 0xB68u);
    ctx->pc = 0x1E90u;
    goto label_1e90;
    ctx->pc = 0xB68u;
label_b68:
    // 0xb68: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_b6c:
    // 0xb6c: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_b70:
    // 0xb70: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_b74:
    // 0xb74: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_b78:
    // 0xb78: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_b7c:
    // 0xb7c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_b80:
    // 0xb80: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_b84:
    // 0xb84: 0x3e00008  jr          $ra
label_b88:
    if (ctx->pc == 0xB88u) {
        // 0xb88: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0xB8Cu;
        goto label_b8c;
    }
    ctx->pc = 0xB84u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xb88: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xB84u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xB8Cu;
label_b8c:
    // 0xb8c: 0x0  nop
    // NOP
label_b90:
    // 0xb90: 0x10c00008  beqz        $a2, . + 4 + (0x8 << 2)
label_b94:
    if (ctx->pc == 0xB94u) {
        // 0xb94: 0x24c3ffff  addiu       $v1, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->pc = 0xB98u;
        goto label_b98;
    }
    ctx->pc = 0xB90u;
    {
        const bool branch_taken_0xb90 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0xb94: 0x24c3ffff  addiu       $v1, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        if (branch_taken_0xb90) {
            ctx->pc = 0xBB4u;
            goto label_bb4;
        }
    }
    ctx->pc = 0xB98u;
label_b98:
    // 0xb98: 0x2406ffff  addiu       $a2, $zero, -0x1
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_b9c:
    // 0xb9c: 0x90a20000  lbu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
label_ba0:
    // 0xba0: 0x24a50001  addiu       $a1, $a1, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_ba4:
    // 0xba4: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
label_ba8:
    // 0xba8: 0xa0820000  sb          $v0, 0x0($a0)
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
label_bac:
    // 0xbac: 0x1466fffb  bne         $v1, $a2, . + 4 + (-0x5 << 2)
label_bb0:
    if (ctx->pc == 0xBB0u) {
        // 0xbb0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->pc = 0xBB4u;
        goto label_bb4;
    }
    ctx->pc = 0xBACu;
    {
        const bool branch_taken_0xbac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        // 0xbb0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0xbac) {
            ctx->pc = 0xB9Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_b9c;
        }
    }
    ctx->pc = 0xBB4u;
label_bb4:
    // 0xbb4: 0x3e00008  jr          $ra
label_bb8:
    if (ctx->pc == 0xBB8u) {
        ctx->pc = 0xBBCu;
        goto label_bbc;
    }
    ctx->pc = 0xBB4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xBB4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xBBCu;
label_bbc:
    // 0xbbc: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_bc0:
    // 0xbc0: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_bc4:
    // 0xbc4: 0x21880  sll         $v1, $v0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_bc8:
    // 0xbc8: 0x3c06bf90  lui         $a2, 0xBF90
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
label_bcc:
    // 0xbcc: 0x34c60764  ori         $a2, $a2, 0x764
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)1892);
label_bd0:
    // 0xbd0: 0xaca40000  sw          $a0, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
label_bd4:
    // 0xbd4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_bd8:
    // 0xbd8: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_bdc:
    // 0xbdc: 0x8c8452d4  lw          $a0, 0x52D4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21204)));
label_be0:
    // 0xbe0: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_be4:
    // 0xbe4: 0xaca40004  sw          $a0, 0x4($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 4));
label_be8:
    // 0xbe8: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_bec:
    // 0xbec: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_bf0:
    // 0xbf0: 0x8c8452dc  lw          $a0, 0x52DC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21212)));
label_bf4:
    // 0xbf4: 0x463021  addu        $a2, $v0, $a2
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_bf8:
    // 0xbf8: 0xaca4000c  sw          $a0, 0xC($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 4));
label_bfc:
    // 0xbfc: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_c00:
    // 0xc00: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_c04:
    // 0xc04: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_c08:
    // 0xc08: 0x8c2352e0  lw          $v1, 0x52E0($at)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 21216)));
label_c0c:
    // 0xc0c: 0x34840766  ori         $a0, $a0, 0x766
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1894);
label_c10:
    // 0xc10: 0xaca30010  sw          $v1, 0x10($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 16), GPR_U32(ctx, 3));
label_c14:
    // 0xc14: 0x94c30000  lhu         $v1, 0x0($a2)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
label_c18:
    // 0xc18: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_c1c:
    // 0xc1c: 0xa4a30008  sh          $v1, 0x8($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 8), (uint16_t)GPR_U32(ctx, 3));
label_c20:
    // 0xc20: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_c24:
    // 0xc24: 0x3e00008  jr          $ra
label_c28:
    if (ctx->pc == 0xC28u) {
        // 0xc28: 0xa4a2000a  sh          $v0, 0xA($a1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 5), 10), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0xC2Cu;
        goto label_c2c;
    }
    ctx->pc = 0xC24u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0xc28: 0xa4a2000a  sh          $v0, 0xA($a1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 5), 10), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0xC24u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0xC2Cu;
label_c2c:
    // 0xc2c: 0x27bdff68  addiu       $sp, $sp, -0x98
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967144));
label_c30:
    // 0xc30: 0xafb3007c  sw          $s3, 0x7C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 19));
label_c34:
    // 0xc34: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_c38:
    // 0xc38: 0xafb7008c  sw          $s7, 0x8C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 140), GPR_U32(ctx, 23));
label_c3c:
    // 0xc3c: 0xb821  addu        $s7, $zero, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_c40:
    // 0xc40: 0xafb60088  sw          $s6, 0x88($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 136), GPR_U32(ctx, 22));
label_c44:
    // 0xc44: 0x2e0b021  addu        $s6, $s7, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
label_c48:
    // 0xc48: 0xafb50084  sw          $s5, 0x84($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 132), GPR_U32(ctx, 21));
label_c4c:
    // 0xc4c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_c50:
    // 0xc50: 0x3442019a  ori         $v0, $v0, 0x19A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)410);
label_c54:
    // 0xc54: 0xa04021  addu        $t0, $a1, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_c58:
    // 0xc58: 0x131a80  sll         $v1, $s3, 10
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 10));
label_c5c:
    // 0xc5c: 0xafbf0094  sw          $ra, 0x94($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 148), GPR_U32(ctx, 31));
label_c60:
    // 0xc60: 0xafbe0090  sw          $fp, 0x90($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 144), GPR_U32(ctx, 30));
label_c64:
    // 0xc64: 0xafb40080  sw          $s4, 0x80($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 20));
label_c68:
    // 0xc68: 0xafb20078  sw          $s2, 0x78($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 18));
label_c6c:
    // 0xc6c: 0xafb10074  sw          $s1, 0x74($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 116), GPR_U32(ctx, 17));
label_c70:
    // 0xc70: 0xafb00070  sw          $s0, 0x70($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 16));
label_c74:
    // 0xc74: 0xafa5009c  sw          $a1, 0x9C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 156), GPR_U32(ctx, 5));
label_c78:
    // 0xc78: 0xafa00060  sw          $zero, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 0));
label_c7c:
    // 0xc7c: 0xafa00068  sw          $zero, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 0));
label_c80:
    // 0xc80: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_c84:
    // 0xc84: 0x8d120004  lw          $s2, 0x4($t0)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 4)));
label_c88:
    // 0xc88: 0x62a021  addu        $s4, $v1, $v0
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_c8c:
    // 0xc8c: 0x32420100  andi        $v0, $s2, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)256);
label_c90:
    // 0xc90: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
label_c94:
    if (ctx->pc == 0xC94u) {
        // 0xc94: 0x2e0a821  addu        $s5, $s7, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
        ctx->pc = 0xC98u;
        goto label_c98;
    }
    ctx->pc = 0xC90u;
    {
        const bool branch_taken_0xc90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xc94: 0x2e0a821  addu        $s5, $s7, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
        if (branch_taken_0xc90) {
            ctx->pc = 0xCC0u;
            goto label_cc0;
        }
    }
    ctx->pc = 0xC98u;
label_c98:
    // 0xc98: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_c9c:
    // 0xc9c: 0x531021  addu        $v0, $v0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
label_ca0:
    // 0xca0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_ca4:
    // 0xca4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_ca8:
    // 0xca8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_cac:
    // 0xcac: 0x8c2252d4  lw          $v0, 0x52D4($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 21204)));
label_cb0:
    // 0xcb0: 0x24170001  addiu       $s7, $zero, 0x1
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_cb4:
    // 0xcb4: 0xafa20060  sw          $v0, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 2));
label_cb8:
    // 0xcb8: 0x32420200  andi        $v0, $s2, 0x200
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)512);
label_cbc:
    // 0xcbc: 0x2b02b  sltu        $s6, $zero, $v0
    SET_GPR_U64(ctx, 22, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_cc0:
    // 0xcc0: 0x325200ff  andi        $s2, $s2, 0xFF
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
label_cc4:
    // 0xcc4: 0x2e42000a  sltiu       $v0, $s2, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
label_cc8:
    // 0xcc8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_ccc:
    if (ctx->pc == 0xCCCu) {
        // 0xccc: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0xCD0u;
        goto label_cd0;
    }
    ctx->pc = 0xCC8u;
    {
        const bool branch_taken_0xcc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xccc: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0xcc8) {
            ctx->pc = 0xCD8u;
            goto label_cd8;
        }
    }
    ctx->pc = 0xCD0u;
label_cd0:
    // 0xcd0: 0x8000434  j           func_0010D0
label_cd4:
    if (ctx->pc == 0xCD4u) {
        // 0xcd4: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0xCD8u;
        goto label_cd8;
    }
    ctx->pc = 0xCD0u;
    // 0xcd4: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
    ctx->pc = 0x10D0u;
    goto label_10d0;
    ctx->pc = 0xCD8u;
label_cd8:
    // 0xcd8: 0x138080  sll         $s0, $s3, 2
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_cdc:
    // 0xcdc: 0x2131021  addu        $v0, $s0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
label_ce0:
    // 0xce0: 0x28880  sll         $s1, $v0, 2
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_ce4:
    // 0xce4: 0x134240  sll         $t0, $s3, 9
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 19), 9));
label_ce8:
    // 0xce8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_cec:
    // 0xcec: 0x310821  addu        $at, $at, $s1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 17)));
label_cf0:
    // 0xcf0: 0xac3252d4  sw          $s2, 0x52D4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21204), GPR_U32(ctx, 18));
label_cf4:
    // 0xcf4: 0xc000440  jal         func_001100
label_cf8:
    if (ctx->pc == 0xCF8u) {
        // 0xcf8: 0xafa80064  sw          $t0, 0x64($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 8));
        ctx->pc = 0xCFCu;
        goto label_cfc;
    }
    ctx->pc = 0xCF4u;
    SET_GPR_U32(ctx, 31, 0xCFCu);
    // 0xcf8: 0xafa80064  sw          $t0, 0x64($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 8));
    ctx->pc = 0x1100u;
    goto label_1100;
    ctx->pc = 0xCFCu;
label_cfc:
    // 0xcfc: 0x121880  sll         $v1, $s2, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
label_d00:
    // 0xd00: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_d04:
    // 0xd04: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_d08:
    // 0xd08: 0x8c234a98  lw          $v1, 0x4A98($at)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 19096)));
label_d0c:
    // 0xd0c: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_d10:
    // 0xd10: 0x318c0  sll         $v1, $v1, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
label_d14:
    // 0xd14: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
label_d18:
    // 0xd18: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_d1c:
    // 0xd1c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_d20:
    // 0xd20: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_d24:
    // 0xd24: 0xac2259a8  sw          $v0, 0x59A8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22952), GPR_U32(ctx, 2));
label_d28:
    // 0xd28: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_d2c:
    // 0xd2c: 0x511021  addu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
label_d30:
    // 0xd30: 0x8c4252d4  lw          $v0, 0x52D4($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21204)));
label_d34:
    // 0xd34: 0x24060044  addiu       $a2, $zero, 0x44
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
label_d38:
    // 0xd38: 0x22900  sll         $a1, $v0, 4
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
label_d3c:
    // 0xd3c: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_d40:
    // 0xd40: 0x52880  sll         $a1, $a1, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
label_d44:
    // 0xd44: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_d48:
    // 0xd48: 0x24424ac0  addiu       $v0, $v0, 0x4AC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19136));
label_d4c:
    // 0xd4c: 0xc0002e4  jal         func_000B90
label_d50:
    if (ctx->pc == 0xD50u) {
        // 0xd50: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->pc = 0xD54u;
        goto label_d54;
    }
    ctx->pc = 0xD4Cu;
    SET_GPR_U32(ctx, 31, 0xD54u);
    // 0xd50: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    ctx->pc = 0xB90u;
    goto label_b90;
    ctx->pc = 0xD54u;
label_d54:
    // 0xd54: 0x24020007  addiu       $v0, $zero, 0x7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
label_d58:
    // 0xd58: 0x12420006  beq         $s2, $v0, . + 4 + (0x6 << 2)
label_d5c:
    if (ctx->pc == 0xD5Cu) {
        // 0xd5c: 0x241e0001  addiu       $fp, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0xD60u;
        goto label_d60;
    }
    ctx->pc = 0xD58u;
    {
        const bool branch_taken_0xd58 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        // 0xd5c: 0x241e0001  addiu       $fp, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0xd58) {
            ctx->pc = 0xD74u;
            goto label_d74;
        }
    }
    ctx->pc = 0xD60u;
label_d60:
    // 0xd60: 0x24020008  addiu       $v0, $zero, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_d64:
    // 0xd64: 0x1242000c  beq         $s2, $v0, . + 4 + (0xC << 2)
label_d68:
    if (ctx->pc == 0xD68u) {
        // 0xd68: 0x131080  sll         $v0, $s3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
        ctx->pc = 0xD6Cu;
        goto label_d6c;
    }
    ctx->pc = 0xD64u;
    {
        const bool branch_taken_0xd64 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 2));
        // 0xd68: 0x131080  sll         $v0, $s3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
        if (branch_taken_0xd64) {
            ctx->pc = 0xD98u;
            goto label_d98;
        }
    }
    ctx->pc = 0xD6Cu;
label_d6c:
    // 0xd6c: 0x800036f  j           func_000DBC
label_d70:
    if (ctx->pc == 0xD70u) {
        // 0xd70: 0x531021  addu        $v0, $v0, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
        ctx->pc = 0xD74u;
        goto label_d74;
    }
    ctx->pc = 0xD6Cu;
    // 0xd70: 0x531021  addu        $v0, $v0, $s3 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    ctx->pc = 0xDBCu;
    goto label_dbc;
    ctx->pc = 0xD74u;
label_d74:
    // 0xd74: 0x24020080  addiu       $v0, $zero, 0x80
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
label_d78:
    // 0xd78: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_d7c:
    // 0xd7c: 0x310821  addu        $at, $at, $s1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 17)));
label_d80:
    // 0xd80: 0xac2252e0  sw          $v0, 0x52E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21216), GPR_U32(ctx, 2));
label_d84:
    // 0xd84: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_d88:
    // 0xd88: 0x310821  addu        $at, $at, $s1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 17)));
label_d8c:
    // 0xd8c: 0xac2252dc  sw          $v0, 0x52DC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21212), GPR_U32(ctx, 2));
label_d90:
    // 0xd90: 0x8000377  j           func_000DDC
label_d94:
    if (ctx->pc == 0xD94u) {
        // 0xd94: 0x2a420009  slti        $v0, $s2, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
        ctx->pc = 0xD98u;
        goto label_d98;
    }
    ctx->pc = 0xD90u;
    // 0xd94: 0x2a420009  slti        $v0, $s2, 0x9 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
    ctx->pc = 0xDDCu;
    goto label_ddc;
    ctx->pc = 0xD98u;
label_d98:
    // 0xd98: 0x24020080  addiu       $v0, $zero, 0x80
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
label_d9c:
    // 0xd9c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_da0:
    // 0xda0: 0x310821  addu        $at, $at, $s1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 17)));
label_da4:
    // 0xda4: 0xac2052e0  sw          $zero, 0x52E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21216), GPR_U32(ctx, 0));
label_da8:
    // 0xda8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_dac:
    // 0xdac: 0x310821  addu        $at, $at, $s1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 17)));
label_db0:
    // 0xdb0: 0xac2252dc  sw          $v0, 0x52DC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21212), GPR_U32(ctx, 2));
label_db4:
    // 0xdb4: 0x8000377  j           func_000DDC
label_db8:
    if (ctx->pc == 0xDB8u) {
        // 0xdb8: 0x2a420009  slti        $v0, $s2, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
        ctx->pc = 0xDBCu;
        goto label_dbc;
    }
    ctx->pc = 0xDB4u;
    // 0xdb8: 0x2a420009  slti        $v0, $s2, 0x9 (Delay Slot)
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
    ctx->pc = 0xDDCu;
    goto label_ddc;
    ctx->pc = 0xDBCu;
label_dbc:
    // 0xdbc: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_dc0:
    // 0xdc0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_dc4:
    // 0xdc4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_dc8:
    // 0xdc8: 0xac2052e0  sw          $zero, 0x52E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21216), GPR_U32(ctx, 0));
label_dcc:
    // 0xdcc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_dd0:
    // 0xdd0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_dd4:
    // 0xdd4: 0xac2052dc  sw          $zero, 0x52DC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21212), GPR_U32(ctx, 0));
label_dd8:
    // 0xdd8: 0x2a420009  slti        $v0, $s2, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
label_ddc:
    // 0xddc: 0x10400060  beqz        $v0, . + 4 + (0x60 << 2)
label_de0:
    if (ctx->pc == 0xDE0u) {
        // 0xde0: 0x2a420007  slti        $v0, $s2, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)7) ? 1 : 0);
        ctx->pc = 0xDE4u;
        goto label_de4;
    }
    ctx->pc = 0xDDCu;
    {
        const bool branch_taken_0xddc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xde0: 0x2a420007  slti        $v0, $s2, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)7) ? 1 : 0);
        if (branch_taken_0xddc) {
            ctx->pc = 0xF60u;
            goto label_f60;
        }
    }
    ctx->pc = 0xDE4u;
label_de4:
    // 0xde4: 0x14400034  bnez        $v0, . + 4 + (0x34 << 2)
label_de8:
    if (ctx->pc == 0xDE8u) {
        // 0xde8: 0x2a420009  slti        $v0, $s2, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
        ctx->pc = 0xDECu;
        goto label_dec;
    }
    ctx->pc = 0xDE4u;
    {
        const bool branch_taken_0xde4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0xde8: 0x2a420009  slti        $v0, $s2, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
        if (branch_taken_0xde4) {
            ctx->pc = 0xEB8u;
            goto label_eb8;
        }
    }
    ctx->pc = 0xDECu;
label_dec:
    // 0xdec: 0x24080001  addiu       $t0, $zero, 0x1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_df0:
    // 0xdf0: 0x17c00013  bnez        $fp, . + 4 + (0x13 << 2)
label_df4:
    if (ctx->pc == 0xDF4u) {
        // 0xdf4: 0xafa80068  sw          $t0, 0x68($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 8));
        ctx->pc = 0xDF8u;
        goto label_df8;
    }
    ctx->pc = 0xDF0u;
    {
        const bool branch_taken_0xdf0 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        // 0xdf4: 0xafa80068  sw          $t0, 0x68($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 8));
        if (branch_taken_0xdf0) {
            ctx->pc = 0xE40u;
            goto label_e40;
        }
    }
    ctx->pc = 0xDF8u;
label_df8:
    // 0xdf8: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_dfc:
    // 0xdfc: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_e00:
    // 0xe00: 0x531021  addu        $v0, $v0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
label_e04:
    // 0xe04: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_e08:
    // 0xe08: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_e0c:
    // 0xe0c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_e10:
    // 0xe10: 0x8c2252d4  lw          $v0, 0x52D4($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 21204)));
label_e14:
    // 0xe14: 0x24060044  addiu       $a2, $zero, 0x44
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
label_e18:
    // 0xe18: 0x22900  sll         $a1, $v0, 4
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
label_e1c:
    // 0xe1c: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_e20:
    // 0xe20: 0x52880  sll         $a1, $a1, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
label_e24:
    // 0xe24: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_e28:
    // 0xe28: 0x24424ac0  addiu       $v0, $v0, 0x4AC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19136));
label_e2c:
    // 0xe2c: 0xc0002e4  jal         func_000B90
label_e30:
    if (ctx->pc == 0xE30u) {
        // 0xe30: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->pc = 0xE34u;
        goto label_e34;
    }
    ctx->pc = 0xE2Cu;
    SET_GPR_U32(ctx, 31, 0xE34u);
    // 0xe30: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    ctx->pc = 0xB90u;
    goto label_b90;
    ctx->pc = 0xE34u;
label_e34:
    // 0xe34: 0x3c020c01  lui         $v0, 0xC01
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3073 << 16));
label_e38:
    // 0xe38: 0x34421c00  ori         $v0, $v0, 0x1C00
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)7168);
label_e3c:
    // 0xe3c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_e40:
    // 0xe40: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_e44:
    // 0xe44: 0x531021  addu        $v0, $v0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
label_e48:
    // 0xe48: 0x8fa8009c  lw          $t0, 0x9C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
label_e4c:
    // 0xe4c: 0x97a30014  lhu         $v1, 0x14($sp)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 20)));
label_e50:
    // 0xe50: 0x8d04000c  lw          $a0, 0xC($t0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 12)));
label_e54:
    // 0xe54: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_e58:
    // 0xe58: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_e5c:
    // 0xe5c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_e60:
    // 0xe60: 0xac2452dc  sw          $a0, 0x52DC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21212), GPR_U32(ctx, 4));
label_e64:
    // 0xe64: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_e68:
    // 0xe68: 0x41180  sll         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
label_e6c:
    // 0xe6c: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_e70:
    // 0xe70: 0x42140  sll         $a0, $a0, 5
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
label_e74:
    // 0xe74: 0xa7a20028  sh          $v0, 0x28($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 40), (uint16_t)GPR_U32(ctx, 2));
label_e78:
    // 0xe78: 0x97a20016  lhu         $v0, 0x16($sp)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 22)));
label_e7c:
    // 0xe7c: 0x97a30036  lhu         $v1, 0x36($sp)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 54)));
label_e80:
    // 0xe80: 0x821023  subu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_e84:
    // 0xe84: 0xa7a2002a  sh          $v0, 0x2A($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 42), (uint16_t)GPR_U32(ctx, 2));
label_e88:
    // 0xe88: 0x97a2002e  lhu         $v0, 0x2E($sp)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 46)));
label_e8c:
    // 0xe8c: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_e90:
    // 0xe90: 0xa7a30034  sh          $v1, 0x34($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 52), (uint16_t)GPR_U32(ctx, 3));
label_e94:
    // 0xe94: 0x97a3004e  lhu         $v1, 0x4E($sp)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 78)));
label_e98:
    // 0xe98: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_e9c:
    // 0xe9c: 0xa7a2002c  sh          $v0, 0x2C($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 44), (uint16_t)GPR_U32(ctx, 2));
label_ea0:
    // 0xea0: 0x97a2004c  lhu         $v0, 0x4C($sp)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 76)));
label_ea4:
    // 0xea4: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_ea8:
    // 0xea8: 0xa7a3004a  sh          $v1, 0x4A($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 74), (uint16_t)GPR_U32(ctx, 3));
label_eac:
    // 0xeac: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_eb0:
    // 0xeb0: 0xa7a20048  sh          $v0, 0x48($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 72), (uint16_t)GPR_U32(ctx, 2));
label_eb4:
    // 0xeb4: 0x2a420009  slti        $v0, $s2, 0x9
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)9) ? 1 : 0);
label_eb8:
    // 0xeb8: 0x10400029  beqz        $v0, . + 4 + (0x29 << 2)
label_ebc:
    if (ctx->pc == 0xEBCu) {
        // 0xebc: 0x2a420007  slti        $v0, $s2, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)7) ? 1 : 0);
        ctx->pc = 0xEC0u;
        goto label_ec0;
    }
    ctx->pc = 0xEB8u;
    {
        const bool branch_taken_0xeb8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0xebc: 0x2a420007  slti        $v0, $s2, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)7) ? 1 : 0);
        if (branch_taken_0xeb8) {
            ctx->pc = 0xF60u;
            goto label_f60;
        }
    }
    ctx->pc = 0xEC0u;
label_ec0:
    // 0xec0: 0x14400027  bnez        $v0, . + 4 + (0x27 << 2)
label_ec4:
    if (ctx->pc == 0xEC4u) {
        ctx->pc = 0xEC8u;
        goto label_ec8;
    }
    ctx->pc = 0xEC0u;
    {
        const bool branch_taken_0xec0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0xec0) {
            ctx->pc = 0xF60u;
            goto label_f60;
        }
    }
    ctx->pc = 0xEC8u;
label_ec8:
    // 0xec8: 0x17c00019  bnez        $fp, . + 4 + (0x19 << 2)
label_ecc:
    if (ctx->pc == 0xECCu) {
        ctx->pc = 0xED0u;
        goto label_ed0;
    }
    ctx->pc = 0xEC8u;
    {
        const bool branch_taken_0xec8 = (GPR_U64(ctx, 30) != GPR_U64(ctx, 0));
        if (branch_taken_0xec8) {
            ctx->pc = 0xF30u;
            goto label_f30;
        }
    }
    ctx->pc = 0xED0u;
label_ed0:
    // 0xed0: 0x8fa80068  lw          $t0, 0x68($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
label_ed4:
    // 0xed4: 0x0  nop
    // NOP
label_ed8:
    // 0xed8: 0x15000011  bnez        $t0, . + 4 + (0x11 << 2)
label_edc:
    if (ctx->pc == 0xEDCu) {
        // 0xedc: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0xEE0u;
        goto label_ee0;
    }
    ctx->pc = 0xED8u;
    {
        const bool branch_taken_0xed8 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        // 0xedc: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        if (branch_taken_0xed8) {
            ctx->pc = 0xF20u;
            goto label_f20;
        }
    }
    ctx->pc = 0xEE0u;
label_ee0:
    // 0xee0: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_ee4:
    // 0xee4: 0x531021  addu        $v0, $v0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
label_ee8:
    // 0xee8: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_eec:
    // 0xeec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_ef0:
    // 0xef0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_ef4:
    // 0xef4: 0x8c2252d4  lw          $v0, 0x52D4($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 21204)));
label_ef8:
    // 0xef8: 0x24060044  addiu       $a2, $zero, 0x44
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 68));
label_efc:
    // 0xefc: 0x22900  sll         $a1, $v0, 4
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
label_f00:
    // 0xf00: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_f04:
    // 0xf04: 0x52880  sll         $a1, $a1, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
label_f08:
    // 0xf08: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_f0c:
    // 0xf0c: 0x24424ac0  addiu       $v0, $v0, 0x4AC0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19136));
label_f10:
    // 0xf10: 0xc0002e4  jal         func_000B90
label_f14:
    if (ctx->pc == 0xF14u) {
        // 0xf14: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->pc = 0xF18u;
        goto label_f18;
    }
    ctx->pc = 0xF10u;
    SET_GPR_U32(ctx, 31, 0xF18u);
    // 0xf14: 0xa22821  addu        $a1, $a1, $v0 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    ctx->pc = 0xB90u;
    goto label_b90;
    ctx->pc = 0xF18u;
label_f18:
    // 0xf18: 0x80003cb  j           func_000F2C
label_f1c:
    if (ctx->pc == 0xF1Cu) {
        // 0xf1c: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->pc = 0xF20u;
        goto label_f20;
    }
    ctx->pc = 0xF18u;
    // 0xf1c: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    ctx->pc = 0xF2Cu;
    goto label_f2c;
    ctx->pc = 0xF20u;
label_f20:
    // 0xf20: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_f24:
    // 0xf24: 0x0  nop
    // NOP
label_f28:
    // 0xf28: 0x34420080  ori         $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
label_f2c:
    // 0xf2c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_f30:
    // 0xf30: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_f34:
    // 0xf34: 0x8fa8009c  lw          $t0, 0x9C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
label_f38:
    // 0xf38: 0x531021  addu        $v0, $v0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
label_f3c:
    // 0xf3c: 0x8d030010  lw          $v1, 0x10($t0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 16)));
label_f40:
    // 0xf40: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_f44:
    // 0xf44: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_f48:
    // 0xf48: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_f4c:
    // 0xf4c: 0xac2352e0  sw          $v1, 0x52E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21216), GPR_U32(ctx, 3));
label_f50:
    // 0xf50: 0x311c0  sll         $v0, $v1, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
label_f54:
    // 0xf54: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_f58:
    // 0xf58: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_f5c:
    // 0xf5c: 0xa7a20022  sh          $v0, 0x22($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 34), (uint16_t)GPR_U32(ctx, 2));
label_f60:
    // 0xf60: 0x13c00010  beqz        $fp, . + 4 + (0x10 << 2)
label_f64:
    if (ctx->pc == 0xF64u) {
        ctx->pc = 0xF68u;
        goto label_f68;
    }
    ctx->pc = 0xF60u;
    {
        const bool branch_taken_0xf60 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        if (branch_taken_0xf60) {
            ctx->pc = 0xFA4u;
            goto label_fa4;
        }
    }
    ctx->pc = 0xF68u;
label_f68:
    // 0xf68: 0x96820000  lhu         $v0, 0x0($s4)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
label_f6c:
    // 0xf6c: 0x0  nop
    // NOP
label_f70:
    // 0xf70: 0x211c2  srl         $v0, $v0, 7
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 7));
label_f74:
    // 0xf74: 0x30550001  andi        $s5, $v0, 0x1
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
label_f78:
    // 0xf78: 0x12a00015  beqz        $s5, . + 4 + (0x15 << 2)
label_f7c:
    if (ctx->pc == 0xF7Cu) {
        // 0xf7c: 0x3c06bf90  lui         $a2, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0xF80u;
        goto label_f80;
    }
    ctx->pc = 0xF78u;
    {
        const bool branch_taken_0xf78 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        // 0xf7c: 0x3c06bf90  lui         $a2, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0xf78) {
            ctx->pc = 0xFD0u;
            goto label_fd0;
        }
    }
    ctx->pc = 0xF80u;
label_f80:
    // 0xf80: 0xc0011e5  jal         func_004794
label_f84:
    if (ctx->pc == 0xF84u) {
        // 0xf84: 0x27a4005c  addiu       $a0, $sp, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
        ctx->pc = 0xF88u;
        goto label_f88;
    }
    ctx->pc = 0xF80u;
    SET_GPR_U32(ctx, 31, 0xF88u);
    // 0xf84: 0x27a4005c  addiu       $a0, $sp, 0x5C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0xF80u, 0xF88u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xF88u;
label_f88:
    // 0xf88: 0x96820000  lhu         $v0, 0x0($s4)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
label_f8c:
    // 0xf8c: 0x0  nop
    // NOP
label_f90:
    // 0xf90: 0x3042ff7f  andi        $v0, $v0, 0xFF7F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65407);
label_f94:
    // 0xf94: 0xa6820000  sh          $v0, 0x0($s4)
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
label_f98:
    // 0xf98: 0x8fa4005c  lw          $a0, 0x5C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
label_f9c:
    // 0xf9c: 0xc0011e7  jal         func_00479C
label_fa0:
    if (ctx->pc == 0xFA0u) {
        ctx->pc = 0xFA4u;
        goto label_fa4;
    }
    ctx->pc = 0xF9Cu;
    SET_GPR_U32(ctx, 31, 0xFA4u);
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0xF9Cu, 0xFA4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0xFA4u;
label_fa4:
    // 0xfa4: 0x12a0000a  beqz        $s5, . + 4 + (0xA << 2)
label_fa8:
    if (ctx->pc == 0xFA8u) {
        // 0xfa8: 0x3c06bf90  lui         $a2, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0xFACu;
        goto label_fac;
    }
    ctx->pc = 0xFA4u;
    {
        const bool branch_taken_0xfa4 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        // 0xfa8: 0x3c06bf90  lui         $a2, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0xfa4) {
            ctx->pc = 0xFD0u;
            goto label_fd0;
        }
    }
    ctx->pc = 0xFACu;
label_fac:
    // 0xfac: 0x12e00008  beqz        $s7, . + 4 + (0x8 << 2)
label_fb0:
    if (ctx->pc == 0xFB0u) {
        // 0xfb0: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0xFB4u;
        goto label_fb4;
    }
    ctx->pc = 0xFACu;
    {
        const bool branch_taken_0xfac = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        // 0xfb0: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0xfac) {
            ctx->pc = 0xFD0u;
            goto label_fd0;
        }
    }
    ctx->pc = 0xFB4u;
label_fb4:
    // 0xfb4: 0x8fa60060  lw          $a2, 0x60($sp)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
label_fb8:
    // 0xfb8: 0xc000198  jal         func_000660
label_fbc:
    if (ctx->pc == 0xFBCu) {
        // 0xfbc: 0x2c02821  addu        $a1, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        ctx->pc = 0xFC0u;
        goto label_fc0;
    }
    ctx->pc = 0xFB8u;
    SET_GPR_U32(ctx, 31, 0xFC0u);
    // 0xfbc: 0x2c02821  addu        $a1, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x660u;
    goto label_660;
    ctx->pc = 0xFC0u;
label_fc0:
    // 0xfc0: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_fc4:
    // 0xfc4: 0x6000030  bltz        $s0, . + 4 + (0x30 << 2)
label_fc8:
    if (ctx->pc == 0xFC8u) {
        ctx->pc = 0xFCCu;
        goto label_fcc;
    }
    ctx->pc = 0xFC4u;
    {
        const bool branch_taken_0xfc4 = (GPR_S32(ctx, 16) < 0);
        if (branch_taken_0xfc4) {
            ctx->pc = 0x1088u;
            goto label_1088;
        }
    }
    ctx->pc = 0xFCCu;
label_fcc:
    // 0xfcc: 0x3c06bf90  lui         $a2, 0xBF90
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
label_fd0:
    // 0xfd0: 0x34c60764  ori         $a2, $a2, 0x764
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)1892);
label_fd4:
    // 0xfd4: 0x3c07bf90  lui         $a3, 0xBF90
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)49040 << 16));
label_fd8:
    // 0xfd8: 0x34e70766  ori         $a3, $a3, 0x766
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)1894);
label_fdc:
    // 0xfdc: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_fe0:
    // 0xfe0: 0x27a50010  addiu       $a1, $sp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_fe4:
    // 0xfe4: 0x138080  sll         $s0, $s3, 2
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_fe8:
    // 0xfe8: 0x2131021  addu        $v0, $s0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
label_fec:
    // 0xfec: 0x8fa8009c  lw          $t0, 0x9C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 156)));
label_ff0:
    // 0xff0: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_ff4:
    // 0xff4: 0x95030008  lhu         $v1, 0x8($t0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 8)));
label_ff8:
    // 0xff8: 0x463021  addu        $a2, $v0, $a2
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_ffc:
    // 0xffc: 0xa4c30000  sh          $v1, 0x0($a2)
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
label_1000:
    // 0x1000: 0x9503000a  lhu         $v1, 0xA($t0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 10)));
label_1004:
    // 0x1004: 0x471021  addu        $v0, $v0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
label_1008:
    // 0x1008: 0xc00004f  jal         func_00013C
label_100c:
    if (ctx->pc == 0x100Cu) {
        // 0x100c: 0xa4430000  sh          $v1, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->pc = 0x1010u;
        goto label_1010;
    }
    ctx->pc = 0x1008u;
    SET_GPR_U32(ctx, 31, 0x1010u);
    // 0x100c: 0xa4430000  sh          $v1, 0x0($v0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    ctx->pc = 0x13Cu;
    goto label_13c;
    ctx->pc = 0x1010u;
label_1010:
    // 0x1010: 0x13c00016  beqz        $fp, . + 4 + (0x16 << 2)
label_1014:
    if (ctx->pc == 0x1014u) {
        // 0x1014: 0x3c04bf90  lui         $a0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x1018u;
        goto label_1018;
    }
    ctx->pc = 0x1010u;
    {
        const bool branch_taken_0x1010 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        // 0x1014: 0x3c04bf90  lui         $a0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x1010) {
            ctx->pc = 0x106Cu;
            goto label_106c;
        }
    }
    ctx->pc = 0x1018u;
label_1018:
    // 0x1018: 0x348402e0  ori         $a0, $a0, 0x2E0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)736);
label_101c:
    // 0x101c: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_1020:
    // 0x1020: 0x34a502e2  ori         $a1, $a1, 0x2E2
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)738);
label_1024:
    // 0x1024: 0x8fa80064  lw          $t0, 0x64($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
label_1028:
    // 0x1028: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_102c:
    // 0x102c: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_1030:
    // 0x1030: 0x8c4259a8  lw          $v0, 0x59A8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22952)));
label_1034:
    // 0x1034: 0x81840  sll         $v1, $t0, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
label_1038:
    // 0x1038: 0x642021  addu        $a0, $v1, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_103c:
    // 0x103c: 0x21442  srl         $v0, $v0, 17
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 17));
label_1040:
    // 0x1040: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_1044:
    // 0x1044: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_1048:
    // 0x1048: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_104c:
    // 0x104c: 0x8c4259a8  lw          $v0, 0x59A8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22952)));
label_1050:
    // 0x1050: 0x651821  addu        $v1, $v1, $a1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_1054:
    // 0x1054: 0x21042  srl         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
label_1058:
    // 0x1058: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_105c:
    // 0x105c: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_1060:
    // 0x1060: 0x0  nop
    // NOP
label_1064:
    // 0x1064: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_1068:
    // 0x1068: 0xafa20058  sw          $v0, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 2));
label_106c:
    // 0x106c: 0x12e00006  beqz        $s7, . + 4 + (0x6 << 2)
label_1070:
    if (ctx->pc == 0x1070u) {
        // 0x1070: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x1074u;
        goto label_1074;
    }
    ctx->pc = 0x106Cu;
    {
        const bool branch_taken_0x106c = (GPR_U64(ctx, 23) == GPR_U64(ctx, 0));
        // 0x1070: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x106c) {
            ctx->pc = 0x1088u;
            goto label_1088;
        }
    }
    ctx->pc = 0x1074u;
label_1074:
    // 0x1074: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_1078:
    // 0x1078: 0x2c02821  addu        $a1, $s6, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
label_107c:
    // 0x107c: 0xc000198  jal         func_000660
label_1080:
    if (ctx->pc == 0x1080u) {
        // 0x1080: 0x2403021  addu        $a2, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x1084u;
        goto label_1084;
    }
    ctx->pc = 0x107Cu;
    SET_GPR_U32(ctx, 31, 0x1084u);
    // 0x1080: 0x2403021  addu        $a2, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x660u;
    goto label_660;
    ctx->pc = 0x1084u;
label_1084:
    // 0x1084: 0x408021  addu        $s0, $v0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_1088:
    // 0x1088: 0x13c0000e  beqz        $fp, . + 4 + (0xE << 2)
label_108c:
    if (ctx->pc == 0x108Cu) {
        ctx->pc = 0x1090u;
        goto label_1090;
    }
    ctx->pc = 0x1088u;
    {
        const bool branch_taken_0x1088 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        if (branch_taken_0x1088) {
            ctx->pc = 0x10C4u;
            goto label_10c4;
        }
    }
    ctx->pc = 0x1090u;
label_1090:
    // 0x1090: 0x12a0000c  beqz        $s5, . + 4 + (0xC << 2)
label_1094:
    if (ctx->pc == 0x1094u) {
        ctx->pc = 0x1098u;
        goto label_1098;
    }
    ctx->pc = 0x1090u;
    {
        const bool branch_taken_0x1090 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x1090) {
            ctx->pc = 0x10C4u;
            goto label_10c4;
        }
    }
    ctx->pc = 0x1098u;
label_1098:
    // 0x1098: 0xc0011e5  jal         func_004794
label_109c:
    if (ctx->pc == 0x109Cu) {
        // 0x109c: 0x27a4005c  addiu       $a0, $sp, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
        ctx->pc = 0x10A0u;
        goto label_10a0;
    }
    ctx->pc = 0x1098u;
    SET_GPR_U32(ctx, 31, 0x10A0u);
    // 0x109c: 0x27a4005c  addiu       $a0, $sp, 0x5C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x1098u, 0x10A0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10A0u;
label_10a0:
    // 0x10a0: 0x96820000  lhu         $v0, 0x0($s4)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
label_10a4:
    // 0x10a4: 0x0  nop
    // NOP
label_10a8:
    // 0x10a8: 0x34420080  ori         $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
label_10ac:
    // 0x10ac: 0xa6820000  sh          $v0, 0x0($s4)
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
label_10b0:
    // 0x10b0: 0x96820000  lhu         $v0, 0x0($s4)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
label_10b4:
    // 0x10b4: 0x8fa4005c  lw          $a0, 0x5C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
label_10b8:
    // 0x10b8: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_10bc:
    // 0x10bc: 0xc0011e7  jal         func_00479C
label_10c0:
    if (ctx->pc == 0x10C0u) {
        // 0x10c0: 0xafa20058  sw          $v0, 0x58($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 2));
        ctx->pc = 0x10C4u;
        goto label_10c4;
    }
    ctx->pc = 0x10BCu;
    SET_GPR_U32(ctx, 31, 0x10C4u);
    // 0x10c0: 0xafa20058  sw          $v0, 0x58($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 2));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x10BCu, 0x10C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x10C4u;
label_10c4:
    // 0x10c4: 0xc0007a4  jal         func_001E90
label_10c8:
    if (ctx->pc == 0x10C8u) {
        ctx->pc = 0x10CCu;
        goto label_10cc;
    }
    ctx->pc = 0x10C4u;
    SET_GPR_U32(ctx, 31, 0x10CCu);
    ctx->pc = 0x1E90u;
    goto label_1e90;
    ctx->pc = 0x10CCu;
label_10cc:
    // 0x10cc: 0x2001021  addu        $v0, $s0, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_10d0:
    // 0x10d0: 0x8fbf0094  lw          $ra, 0x94($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 148)));
label_10d4:
    // 0x10d4: 0x8fbe0090  lw          $fp, 0x90($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
label_10d8:
    // 0x10d8: 0x8fb7008c  lw          $s7, 0x8C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 140)));
label_10dc:
    // 0x10dc: 0x8fb60088  lw          $s6, 0x88($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 136)));
label_10e0:
    // 0x10e0: 0x8fb50084  lw          $s5, 0x84($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 132)));
label_10e4:
    // 0x10e4: 0x8fb40080  lw          $s4, 0x80($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 128)));
label_10e8:
    // 0x10e8: 0x8fb3007c  lw          $s3, 0x7C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
label_10ec:
    // 0x10ec: 0x8fb20078  lw          $s2, 0x78($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
label_10f0:
    // 0x10f0: 0x8fb10074  lw          $s1, 0x74($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
label_10f4:
    // 0x10f4: 0x8fb00070  lw          $s0, 0x70($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
label_10f8:
    // 0x10f8: 0x3e00008  jr          $ra
label_10fc:
    if (ctx->pc == 0x10FCu) {
        // 0x10fc: 0x27bd0098  addiu       $sp, $sp, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 152));
        ctx->pc = 0x1100u;
        goto label_1100;
    }
    ctx->pc = 0x10F8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x10fc: 0x27bd0098  addiu       $sp, $sp, 0x98 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 152));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x10F8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1100u;
label_1100:
    // 0x1100: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_1104:
    // 0x1104: 0x3442033c  ori         $v0, $v0, 0x33C
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)828);
label_1108:
    // 0x1108: 0x3c030001  lui         $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
label_110c:
    // 0x110c: 0x42280  sll         $a0, $a0, 10
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 10));
label_1110:
    // 0x1110: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1114:
    // 0x1114: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_1118:
    // 0x1118: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
label_111c:
    // 0x111c: 0x21440  sll         $v0, $v0, 17
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 17));
label_1120:
    // 0x1120: 0x3e00008  jr          $ra
label_1124:
    if (ctx->pc == 0x1124u) {
        // 0x1124: 0x431025  or          $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->pc = 0x1128u;
        goto label_1128;
    }
    ctx->pc = 0x1120u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1124: 0x431025  or          $v0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1120u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1128u;
label_1128:
    // 0x1128: 0x27bdff80  addiu       $sp, $sp, -0x80
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
label_112c:
    // 0x112c: 0xafb3006c  sw          $s3, 0x6C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 19));
label_1130:
    // 0x1130: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1134:
    // 0x1134: 0xafb60078  sw          $s6, 0x78($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 22));
label_1138:
    // 0x1138: 0xb021  addu        $s6, $zero, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_113c:
    // 0x113c: 0xafb50074  sw          $s5, 0x74($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 116), GPR_U32(ctx, 21));
label_1140:
    // 0x1140: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_1144:
    // 0x1144: 0x3442019a  ori         $v0, $v0, 0x19A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)410);
label_1148:
    // 0x1148: 0x131a80  sll         $v1, $s3, 10
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 10));
label_114c:
    // 0x114c: 0xafbf007c  sw          $ra, 0x7C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 31));
label_1150:
    // 0x1150: 0xafb40070  sw          $s4, 0x70($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 20));
label_1154:
    // 0x1154: 0xafb20068  sw          $s2, 0x68($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 18));
label_1158:
    // 0x1158: 0xafb10064  sw          $s1, 0x64($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 100), GPR_U32(ctx, 17));
label_115c:
    // 0x115c: 0xafb00060  sw          $s0, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 16));
label_1160:
    // 0x1160: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_1164:
    // 0x1164: 0x8cb10004  lw          $s1, 0x4($a1)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4)));
label_1168:
    // 0x1168: 0x629021  addu        $s2, $v1, $v0
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_116c:
    // 0x116c: 0x32220100  andi        $v0, $s1, 0x100
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)256);
label_1170:
    // 0x1170: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_1174:
    if (ctx->pc == 0x1174u) {
        // 0x1174: 0x2c0a821  addu        $s5, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        ctx->pc = 0x1178u;
        goto label_1178;
    }
    ctx->pc = 0x1170u;
    {
        const bool branch_taken_0x1170 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1174: 0x2c0a821  addu        $s5, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        if (branch_taken_0x1170) {
            ctx->pc = 0x1184u;
            goto label_1184;
        }
    }
    ctx->pc = 0x1178u;
label_1178:
    // 0x1178: 0x24160001  addiu       $s6, $zero, 0x1
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_117c:
    // 0x117c: 0x32220200  andi        $v0, $s1, 0x200
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)512);
label_1180:
    // 0x1180: 0x2a82b  sltu        $s5, $zero, $v0
    SET_GPR_U64(ctx, 21, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_1184:
    // 0x1184: 0x323100ff  andi        $s1, $s1, 0xFF
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)255);
label_1188:
    // 0x1188: 0x2e22000a  sltiu       $v0, $s1, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
label_118c:
    // 0x118c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_1190:
    if (ctx->pc == 0x1190u) {
        // 0x1190: 0x138080  sll         $s0, $s3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
        ctx->pc = 0x1194u;
        goto label_1194;
    }
    ctx->pc = 0x118Cu;
    {
        const bool branch_taken_0x118c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1190: 0x138080  sll         $s0, $s3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
        if (branch_taken_0x118c) {
            ctx->pc = 0x119Cu;
            goto label_119c;
        }
    }
    ctx->pc = 0x1194u;
label_1194:
    // 0x1194: 0x80004d6  j           func_001358
label_1198:
    if (ctx->pc == 0x1198u) {
        // 0x1198: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x119Cu;
        goto label_119c;
    }
    ctx->pc = 0x1194u;
    // 0x1198: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
    ctx->pc = 0x1358u;
    goto label_1358;
    ctx->pc = 0x119Cu;
label_119c:
    // 0x119c: 0x2131021  addu        $v0, $s0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
label_11a0:
    // 0x11a0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_11a4:
    // 0x11a4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_11a8:
    // 0x11a8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_11ac:
    // 0x11ac: 0xac3152d4  sw          $s1, 0x52D4($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21204), GPR_U32(ctx, 17));
label_11b0:
    // 0x11b0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_11b4:
    // 0x11b4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_11b8:
    // 0x11b8: 0xac2052dc  sw          $zero, 0x52DC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21212), GPR_U32(ctx, 0));
label_11bc:
    // 0x11bc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_11c0:
    // 0x11c0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_11c4:
    // 0x11c4: 0xac2052e0  sw          $zero, 0x52E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21216), GPR_U32(ctx, 0));
label_11c8:
    // 0x11c8: 0xc000440  jal         func_001100
label_11cc:
    if (ctx->pc == 0x11CCu) {
        // 0x11cc: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0x11D0u;
        goto label_11d0;
    }
    ctx->pc = 0x11C8u;
    SET_GPR_U32(ctx, 31, 0x11D0u);
    // 0x11cc: 0x2602021  addu        $a0, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x1100u;
    goto label_1100;
    ctx->pc = 0x11D0u;
label_11d0:
    // 0x11d0: 0x27a50010  addiu       $a1, $sp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_11d4:
    // 0x11d4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_11d8:
    // 0x11d8: 0x24844ac0  addiu       $a0, $a0, 0x4AC0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19136));
label_11dc:
    // 0x11dc: 0x111900  sll         $v1, $s1, 4
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
label_11e0:
    // 0x11e0: 0x711821  addu        $v1, $v1, $s1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
label_11e4:
    // 0x11e4: 0x31880  sll         $v1, $v1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_11e8:
    // 0x11e8: 0x642021  addu        $a0, $v1, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_11ec:
    // 0x11ec: 0x111880  sll         $v1, $s1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
label_11f0:
    // 0x11f0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_11f4:
    // 0x11f4: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_11f8:
    // 0x11f8: 0x8c234a98  lw          $v1, 0x4A98($at)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 19096)));
label_11fc:
    // 0x11fc: 0x24860040  addiu       $a2, $a0, 0x40
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 64));
label_1200:
    // 0x1200: 0x318c0  sll         $v1, $v1, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
label_1204:
    // 0x1204: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
label_1208:
    // 0x1208: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_120c:
    // 0x120c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1210:
    // 0x1210: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_1214:
    // 0x1214: 0xac2259a8  sw          $v0, 0x59A8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22952), GPR_U32(ctx, 2));
label_1218:
    // 0x1218: 0x8c870000  lw          $a3, 0x0($a0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_121c:
    // 0x121c: 0x8c880004  lw          $t0, 0x4($a0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
label_1220:
    // 0x1220: 0x8c890008  lw          $t1, 0x8($a0)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
label_1224:
    // 0x1224: 0x8c8a000c  lw          $t2, 0xC($a0)
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
label_1228:
    // 0x1228: 0xaca70000  sw          $a3, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 7));
label_122c:
    // 0x122c: 0xaca80004  sw          $t0, 0x4($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 8));
label_1230:
    // 0x1230: 0xaca90008  sw          $t1, 0x8($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 9));
label_1234:
    // 0x1234: 0xacaa000c  sw          $t2, 0xC($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 10));
label_1238:
    // 0x1238: 0x24840010  addiu       $a0, $a0, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 16));
label_123c:
    // 0x123c: 0x1486fff6  bne         $a0, $a2, . + 4 + (-0xA << 2)
label_1240:
    if (ctx->pc == 0x1240u) {
        // 0x1240: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->pc = 0x1244u;
        goto label_1244;
    }
    ctx->pc = 0x123Cu;
    {
        const bool branch_taken_0x123c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        // 0x1240: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        if (branch_taken_0x123c) {
            ctx->pc = 0x1218u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1218;
        }
    }
    ctx->pc = 0x1244u;
label_1244:
    // 0x1244: 0x8c870000  lw          $a3, 0x0($a0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_1248:
    // 0x1248: 0x0  nop
    // NOP
label_124c:
    // 0x124c: 0xaca70000  sw          $a3, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 7));
label_1250:
    // 0x1250: 0x96420000  lhu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
label_1254:
    // 0x1254: 0x0  nop
    // NOP
label_1258:
    // 0x1258: 0x211c2  srl         $v0, $v0, 7
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 7));
label_125c:
    // 0x125c: 0x30540001  andi        $s4, $v0, 0x1
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
label_1260:
    // 0x1260: 0x1280000b  beqz        $s4, . + 4 + (0xB << 2)
label_1264:
    if (ctx->pc == 0x1264u) {
        // 0x1264: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x1268u;
        goto label_1268;
    }
    ctx->pc = 0x1260u;
    {
        const bool branch_taken_0x1260 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        // 0x1264: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x1260) {
            ctx->pc = 0x1290u;
            goto label_1290;
        }
    }
    ctx->pc = 0x1268u;
label_1268:
    // 0x1268: 0xc0011e5  jal         func_004794
label_126c:
    if (ctx->pc == 0x126Cu) {
        // 0x126c: 0x27a4005c  addiu       $a0, $sp, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
        ctx->pc = 0x1270u;
        goto label_1270;
    }
    ctx->pc = 0x1268u;
    SET_GPR_U32(ctx, 31, 0x1270u);
    // 0x126c: 0x27a4005c  addiu       $a0, $sp, 0x5C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x1268u, 0x1270u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1270u;
label_1270:
    // 0x1270: 0x96420000  lhu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
label_1274:
    // 0x1274: 0x0  nop
    // NOP
label_1278:
    // 0x1278: 0x3042ff7f  andi        $v0, $v0, 0xFF7F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65407);
label_127c:
    // 0x127c: 0xa6420000  sh          $v0, 0x0($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
label_1280:
    // 0x1280: 0x8fa4005c  lw          $a0, 0x5C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
label_1284:
    // 0x1284: 0xc0011e7  jal         func_00479C
label_1288:
    if (ctx->pc == 0x1288u) {
        ctx->pc = 0x128Cu;
        goto label_128c;
    }
    ctx->pc = 0x1284u;
    SET_GPR_U32(ctx, 31, 0x128Cu);
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x1284u, 0x128Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x128Cu;
label_128c:
    // 0x128c: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_1290:
    // 0x1290: 0x34630764  ori         $v1, $v1, 0x764
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1892);
label_1294:
    // 0x1294: 0x3c06bf90  lui         $a2, 0xBF90
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
label_1298:
    // 0x1298: 0x34c60766  ori         $a2, $a2, 0x766
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)1894);
label_129c:
    // 0x129c: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_12a0:
    // 0x12a0: 0x27a50010  addiu       $a1, $sp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_12a4:
    // 0x12a4: 0x138080  sll         $s0, $s3, 2
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_12a8:
    // 0x12a8: 0x2131021  addu        $v0, $s0, $s3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
label_12ac:
    // 0x12ac: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_12b0:
    // 0x12b0: 0x431821  addu        $v1, $v0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_12b4:
    // 0x12b4: 0x461021  addu        $v0, $v0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_12b8:
    // 0x12b8: 0xa4600000  sh          $zero, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 0));
label_12bc:
    // 0x12bc: 0xc00004f  jal         func_00013C
label_12c0:
    if (ctx->pc == 0x12C0u) {
        // 0x12c0: 0xa4400000  sh          $zero, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->pc = 0x12C4u;
        goto label_12c4;
    }
    ctx->pc = 0x12BCu;
    SET_GPR_U32(ctx, 31, 0x12C4u);
    // 0x12c0: 0xa4400000  sh          $zero, 0x0($v0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
    ctx->pc = 0x13Cu;
    goto label_13c;
    ctx->pc = 0x12C4u;
label_12c4:
    // 0x12c4: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_12c8:
    // 0x12c8: 0x348402e0  ori         $a0, $a0, 0x2E0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)736);
label_12cc:
    // 0x12cc: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_12d0:
    // 0x12d0: 0x34a502e2  ori         $a1, $a1, 0x2E2
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)738);
label_12d4:
    // 0x12d4: 0x131a80  sll         $v1, $s3, 10
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 10));
label_12d8:
    // 0x12d8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_12dc:
    // 0x12dc: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_12e0:
    // 0x12e0: 0x8c4259a8  lw          $v0, 0x59A8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22952)));
label_12e4:
    // 0x12e4: 0x642021  addu        $a0, $v1, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_12e8:
    // 0x12e8: 0x21442  srl         $v0, $v0, 17
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 17));
label_12ec:
    // 0x12ec: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_12f0:
    // 0x12f0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_12f4:
    // 0x12f4: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_12f8:
    // 0x12f8: 0x8c4259a8  lw          $v0, 0x59A8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22952)));
label_12fc:
    // 0x12fc: 0x651821  addu        $v1, $v1, $a1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_1300:
    // 0x1300: 0x21042  srl         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
label_1304:
    // 0x1304: 0x1280000e  beqz        $s4, . + 4 + (0xE << 2)
label_1308:
    if (ctx->pc == 0x1308u) {
        // 0x1308: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x130Cu;
        goto label_130c;
    }
    ctx->pc = 0x1304u;
    {
        const bool branch_taken_0x1304 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        // 0x1308: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        if (branch_taken_0x1304) {
            ctx->pc = 0x1340u;
            goto label_1340;
        }
    }
    ctx->pc = 0x130Cu;
label_130c:
    // 0x130c: 0xc0011e5  jal         func_004794
label_1310:
    if (ctx->pc == 0x1310u) {
        // 0x1310: 0x27a4005c  addiu       $a0, $sp, 0x5C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
        ctx->pc = 0x1314u;
        goto label_1314;
    }
    ctx->pc = 0x130Cu;
    SET_GPR_U32(ctx, 31, 0x1314u);
    // 0x1310: 0x27a4005c  addiu       $a0, $sp, 0x5C (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 92));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x130Cu, 0x1314u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1314u;
label_1314:
    // 0x1314: 0x96420000  lhu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
label_1318:
    // 0x1318: 0x0  nop
    // NOP
label_131c:
    // 0x131c: 0x34420080  ori         $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
label_1320:
    // 0x1320: 0xa6420000  sh          $v0, 0x0($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
label_1324:
    // 0x1324: 0x8fa4005c  lw          $a0, 0x5C($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
label_1328:
    // 0x1328: 0xc0011e7  jal         func_00479C
label_132c:
    if (ctx->pc == 0x132Cu) {
        ctx->pc = 0x1330u;
        goto label_1330;
    }
    ctx->pc = 0x1328u;
    SET_GPR_U32(ctx, 31, 0x1330u);
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x1328u, 0x1330u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1330u;
label_1330:
    // 0x1330: 0x96420000  lhu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
label_1334:
    // 0x1334: 0x0  nop
    // NOP
label_1338:
    // 0x1338: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_133c:
    // 0x133c: 0xafa20058  sw          $v0, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 2));
label_1340:
    // 0x1340: 0x12c00005  beqz        $s6, . + 4 + (0x5 << 2)
label_1344:
    if (ctx->pc == 0x1344u) {
        // 0x1344: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x1348u;
        goto label_1348;
    }
    ctx->pc = 0x1340u;
    {
        const bool branch_taken_0x1340 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x1344: 0x1021  addu        $v0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x1340) {
            ctx->pc = 0x1358u;
            goto label_1358;
        }
    }
    ctx->pc = 0x1348u;
label_1348:
    // 0x1348: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_134c:
    // 0x134c: 0x2a02821  addu        $a1, $s5, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
label_1350:
    // 0x1350: 0xc00025f  jal         func_00097C
label_1354:
    if (ctx->pc == 0x1354u) {
        // 0x1354: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x1358u;
        goto label_1358;
    }
    ctx->pc = 0x1350u;
    SET_GPR_U32(ctx, 31, 0x1358u);
    // 0x1354: 0x2203021  addu        $a2, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x97Cu;
    goto label_97c;
    ctx->pc = 0x1358u;
label_1358:
    // 0x1358: 0x8fbf007c  lw          $ra, 0x7C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 124)));
label_135c:
    // 0x135c: 0x8fb60078  lw          $s6, 0x78($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 120)));
label_1360:
    // 0x1360: 0x8fb50074  lw          $s5, 0x74($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 116)));
label_1364:
    // 0x1364: 0x8fb40070  lw          $s4, 0x70($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
label_1368:
    // 0x1368: 0x8fb3006c  lw          $s3, 0x6C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
label_136c:
    // 0x136c: 0x8fb20068  lw          $s2, 0x68($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
label_1370:
    // 0x1370: 0x8fb10064  lw          $s1, 0x64($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 100)));
label_1374:
    // 0x1374: 0x8fb00060  lw          $s0, 0x60($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
label_1378:
    // 0x1378: 0x3e00008  jr          $ra
label_137c:
    if (ctx->pc == 0x137Cu) {
        // 0x137c: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = 0x1380u;
        goto label_1380;
    }
    ctx->pc = 0x1378u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x137c: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1378u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1380u;
label_1380:
    // 0x1380: 0x27bdff98  addiu       $sp, $sp, -0x68
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967192));
label_1384:
    // 0x1384: 0xafb1005c  sw          $s1, 0x5C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 17));
label_1388:
    // 0x1388: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_138c:
    // 0x138c: 0xafbf0060  sw          $ra, 0x60($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 31));
label_1390:
    // 0x1390: 0xafb00058  sw          $s0, 0x58($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 16));
label_1394:
    // 0x1394: 0x92230004  lbu         $v1, 0x4($s1)
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 4)));
label_1398:
    // 0x1398: 0x0  nop
    // NOP
label_139c:
    // 0x139c: 0x2c62000a  sltiu       $v0, $v1, 0xA
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
label_13a0:
    // 0x13a0: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
label_13a4:
    if (ctx->pc == 0x13A4u) {
        // 0x13a4: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        ctx->pc = 0x13A8u;
        goto label_13a8;
    }
    ctx->pc = 0x13A0u;
    {
        const bool branch_taken_0x13a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x13a4: 0x808021  addu        $s0, $a0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
        if (branch_taken_0x13a0) {
            ctx->pc = 0x13CCu;
            goto label_13cc;
        }
    }
    ctx->pc = 0x13A8u;
label_13a8:
    // 0x13a8: 0x101080  sll         $v0, $s0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_13ac:
    // 0x13ac: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_13b0:
    // 0x13b0: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_13b4:
    // 0x13b4: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_13b8:
    // 0x13b8: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_13bc:
    // 0x13bc: 0x8c8452d4  lw          $a0, 0x52D4($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21204)));
label_13c0:
    // 0x13c0: 0x0  nop
    // NOP
label_13c4:
    // 0x13c4: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
label_13c8:
    if (ctx->pc == 0x13C8u) {
        // 0x13c8: 0x28820009  slti        $v0, $a0, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9) ? 1 : 0);
        ctx->pc = 0x13CCu;
        goto label_13cc;
    }
    ctx->pc = 0x13C4u;
    {
        const bool branch_taken_0x13c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        // 0x13c8: 0x28820009  slti        $v0, $a0, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)9) ? 1 : 0);
        if (branch_taken_0x13c4) {
            ctx->pc = 0x13D4u;
            goto label_13d4;
        }
    }
    ctx->pc = 0x13CCu;
label_13cc:
    // 0x13cc: 0x800054d  j           func_001534
label_13d0:
    if (ctx->pc == 0x13D0u) {
        // 0x13d0: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x13D4u;
        goto label_13d4;
    }
    ctx->pc = 0x13CCu;
    // 0x13d0: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
    ctx->pc = 0x1534u;
    goto label_1534;
    ctx->pc = 0x13D4u;
label_13d4:
    // 0x13d4: 0x10400048  beqz        $v0, . + 4 + (0x48 << 2)
label_13d8:
    if (ctx->pc == 0x13D8u) {
        // 0x13d8: 0x28820007  slti        $v0, $a0, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)7) ? 1 : 0);
        ctx->pc = 0x13DCu;
        goto label_13dc;
    }
    ctx->pc = 0x13D4u;
    {
        const bool branch_taken_0x13d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x13d8: 0x28820007  slti        $v0, $a0, 0x7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)7) ? 1 : 0);
        if (branch_taken_0x13d4) {
            ctx->pc = 0x14F8u;
            goto label_14f8;
        }
    }
    ctx->pc = 0x13DCu;
label_13dc:
    // 0x13dc: 0x14400046  bnez        $v0, . + 4 + (0x46 << 2)
label_13e0:
    if (ctx->pc == 0x13E0u) {
        // 0x13e0: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x13E4u;
        goto label_13e4;
    }
    ctx->pc = 0x13DCu;
    {
        const bool branch_taken_0x13dc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x13e0: 0x27a50010  addiu       $a1, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        if (branch_taken_0x13dc) {
            ctx->pc = 0x14F8u;
            goto label_14f8;
        }
    }
    ctx->pc = 0x13E4u;
label_13e4:
    // 0x13e4: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_13e8:
    // 0x13e8: 0x24634ac0  addiu       $v1, $v1, 0x4AC0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19136));
label_13ec:
    // 0x13ec: 0x41100  sll         $v0, $a0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
label_13f0:
    // 0x13f0: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_13f4:
    // 0x13f4: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_13f8:
    // 0x13f8: 0x431821  addu        $v1, $v0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_13fc:
    // 0x13fc: 0x24620040  addiu       $v0, $v1, 0x40
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
label_1400:
    // 0x1400: 0x8c660000  lw          $a2, 0x0($v1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_1404:
    // 0x1404: 0x8c670004  lw          $a3, 0x4($v1)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
label_1408:
    // 0x1408: 0x8c680008  lw          $t0, 0x8($v1)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
label_140c:
    // 0x140c: 0x8c69000c  lw          $t1, 0xC($v1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 12)));
label_1410:
    // 0x1410: 0xaca60000  sw          $a2, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
label_1414:
    // 0x1414: 0xaca70004  sw          $a3, 0x4($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 7));
label_1418:
    // 0x1418: 0xaca80008  sw          $t0, 0x8($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 8));
label_141c:
    // 0x141c: 0xaca9000c  sw          $t1, 0xC($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 9));
label_1420:
    // 0x1420: 0x24630010  addiu       $v1, $v1, 0x10
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16));
label_1424:
    // 0x1424: 0x1462fff6  bne         $v1, $v0, . + 4 + (-0xA << 2)
label_1428:
    if (ctx->pc == 0x1428u) {
        // 0x1428: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        ctx->pc = 0x142Cu;
        goto label_142c;
    }
    ctx->pc = 0x1424u;
    {
        const bool branch_taken_0x1424 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x1428: 0x24a50010  addiu       $a1, $a1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
        if (branch_taken_0x1424) {
            ctx->pc = 0x1400u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1400;
        }
    }
    ctx->pc = 0x142Cu;
label_142c:
    // 0x142c: 0x3c020c01  lui         $v0, 0xC01
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)3073 << 16));
label_1430:
    // 0x1430: 0x34421c80  ori         $v0, $v0, 0x1C80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)7296);
label_1434:
    // 0x1434: 0x8c660000  lw          $a2, 0x0($v1)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_1438:
    // 0x1438: 0x0  nop
    // NOP
label_143c:
    // 0x143c: 0xaca60000  sw          $a2, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
label_1440:
    // 0x1440: 0x102880  sll         $a1, $s0, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_1444:
    // 0x1444: 0xb02821  addu        $a1, $a1, $s0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
label_1448:
    // 0x1448: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_144c:
    // 0x144c: 0x8e22000c  lw          $v0, 0xC($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
label_1450:
    // 0x1450: 0x97a30014  lhu         $v1, 0x14($sp)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 20)));
label_1454:
    // 0x1454: 0x52880  sll         $a1, $a1, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
label_1458:
    // 0x1458: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_145c:
    // 0x145c: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
label_1460:
    // 0x1460: 0xac2252dc  sw          $v0, 0x52DC($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21212), GPR_U32(ctx, 2));
label_1464:
    // 0x1464: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1468:
    // 0x1468: 0x852021  addu        $a0, $a0, $a1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
label_146c:
    // 0x146c: 0x8c8452dc  lw          $a0, 0x52DC($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21212)));
label_1470:
    // 0x1470: 0x8e220010  lw          $v0, 0x10($s1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
label_1474:
    // 0x1474: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_1478:
    // 0x1478: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_147c:
    // 0x147c: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
label_1480:
    // 0x1480: 0xac2252e0  sw          $v0, 0x52E0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21216), GPR_U32(ctx, 2));
label_1484:
    // 0x1484: 0x41180  sll         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
label_1488:
    // 0x1488: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_148c:
    // 0x148c: 0x42140  sll         $a0, $a0, 5
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 5));
label_1490:
    // 0x1490: 0xa7a20028  sh          $v0, 0x28($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 40), (uint16_t)GPR_U32(ctx, 2));
label_1494:
    // 0x1494: 0x97a20016  lhu         $v0, 0x16($sp)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 22)));
label_1498:
    // 0x1498: 0x97a3002e  lhu         $v1, 0x2E($sp)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 46)));
label_149c:
    // 0x149c: 0x821023  subu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_14a0:
    // 0x14a0: 0xa7a2002a  sh          $v0, 0x2A($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 42), (uint16_t)GPR_U32(ctx, 2));
label_14a4:
    // 0x14a4: 0x97a20036  lhu         $v0, 0x36($sp)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 54)));
label_14a8:
    // 0x14a8: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_14ac:
    // 0x14ac: 0xa7a3002c  sh          $v1, 0x2C($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 44), (uint16_t)GPR_U32(ctx, 3));
label_14b0:
    // 0x14b0: 0x97a3004c  lhu         $v1, 0x4C($sp)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 76)));
label_14b4:
    // 0x14b4: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_14b8:
    // 0x14b8: 0xa7a20034  sh          $v0, 0x34($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 52), (uint16_t)GPR_U32(ctx, 2));
label_14bc:
    // 0x14bc: 0x97a2004e  lhu         $v0, 0x4E($sp)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 78)));
label_14c0:
    // 0x14c0: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_14c4:
    // 0x14c4: 0xa7a30048  sh          $v1, 0x48($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 72), (uint16_t)GPR_U32(ctx, 3));
label_14c8:
    // 0x14c8: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_14cc:
    // 0x14cc: 0x651821  addu        $v1, $v1, $a1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_14d0:
    // 0x14d0: 0x8c6352e0  lw          $v1, 0x52E0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21216)));
label_14d4:
    // 0x14d4: 0x27a50010  addiu       $a1, $sp, 0x10
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_14d8:
    // 0x14d8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_14dc:
    // 0x14dc: 0xa7a2004a  sh          $v0, 0x4A($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 74), (uint16_t)GPR_U32(ctx, 2));
label_14e0:
    // 0x14e0: 0x311c0  sll         $v0, $v1, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 7));
label_14e4:
    // 0x14e4: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_14e8:
    // 0x14e8: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_14ec:
    // 0x14ec: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_14f0:
    // 0x14f0: 0xc00004f  jal         func_00013C
label_14f4:
    if (ctx->pc == 0x14F4u) {
        // 0x14f4: 0xa7a20022  sh          $v0, 0x22($sp) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 29), 34), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x14F8u;
        goto label_14f8;
    }
    ctx->pc = 0x14F0u;
    SET_GPR_U32(ctx, 31, 0x14F8u);
    // 0x14f4: 0xa7a20022  sh          $v0, 0x22($sp) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 29), 34), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x13Cu;
    goto label_13c;
    ctx->pc = 0x14F8u;
label_14f8:
    // 0x14f8: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_14fc:
    // 0x14fc: 0x34840764  ori         $a0, $a0, 0x764
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1892);
label_1500:
    // 0x1500: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_1504:
    // 0x1504: 0x34a50766  ori         $a1, $a1, 0x766
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1894);
label_1508:
    // 0x1508: 0x101080  sll         $v0, $s0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
label_150c:
    // 0x150c: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_1510:
    // 0x1510: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_1514:
    // 0x1514: 0x96230008  lhu         $v1, 0x8($s1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 8)));
label_1518:
    // 0x1518: 0x442021  addu        $a0, $v0, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_151c:
    // 0x151c: 0xa4830000  sh          $v1, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
label_1520:
    // 0x1520: 0x9623000a  lhu         $v1, 0xA($s1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 10)));
label_1524:
    // 0x1524: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_1528:
    // 0x1528: 0xc0007a4  jal         func_001E90
label_152c:
    if (ctx->pc == 0x152Cu) {
        // 0x152c: 0xa4430000  sh          $v1, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->pc = 0x1530u;
        goto label_1530;
    }
    ctx->pc = 0x1528u;
    SET_GPR_U32(ctx, 31, 0x1530u);
    // 0x152c: 0xa4430000  sh          $v1, 0x0($v0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    ctx->pc = 0x1E90u;
    goto label_1e90;
    ctx->pc = 0x1530u;
label_1530:
    // 0x1530: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1534:
    // 0x1534: 0x8fbf0060  lw          $ra, 0x60($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
label_1538:
    // 0x1538: 0x8fb1005c  lw          $s1, 0x5C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 92)));
label_153c:
    // 0x153c: 0x8fb00058  lw          $s0, 0x58($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
label_1540:
    // 0x1540: 0x3e00008  jr          $ra
label_1544:
    if (ctx->pc == 0x1544u) {
        // 0x1544: 0x27bd0068  addiu       $sp, $sp, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
        ctx->pc = 0x1548u;
        goto label_1548;
    }
    ctx->pc = 0x1540u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1544: 0x27bd0068  addiu       $sp, $sp, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1540u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1548u;
label_1548:
    // 0x1548: 0x0  nop
    // NOP
label_154c:
    // 0x154c: 0x0  nop
    // NOP
label_1550:
    // 0x1550: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_1554:
    // 0x1554: 0x3c06bf80  lui         $a2, 0xBF80
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49024 << 16));
label_1558:
    // 0x1558: 0x34c61404  ori         $a2, $a2, 0x1404
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)5124);
label_155c:
    // 0x155c: 0x3c05bf80  lui         $a1, 0xBF80
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49024 << 16));
label_1560:
    // 0x1560: 0x34a5140c  ori         $a1, $a1, 0x140C
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)5132);
label_1564:
    // 0x1564: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_1568:
    // 0x1568: 0x34630800  ori         $v1, $v1, 0x800
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)2048);
label_156c:
    // 0x156c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_1570:
    // 0x1570: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
label_1574:
    // 0x1574: 0xacc20000  sw          $v0, 0x0($a2)
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
label_1578:
    // 0x1578: 0xaca30000  sw          $v1, 0x0($a1)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
label_157c:
    // 0x157c: 0xc0011e5  jal         func_004794
label_1580:
    if (ctx->pc == 0x1580u) {
        // 0x1580: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x1584u;
        goto label_1584;
    }
    ctx->pc = 0x157Cu;
    SET_GPR_U32(ctx, 31, 0x1584u);
    // 0x1580: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x157Cu, 0x1584u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1584u;
label_1584:
    // 0x1584: 0x3c04bf80  lui         $a0, 0xBF80
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49024 << 16));
label_1588:
    // 0x1588: 0x348410f0  ori         $a0, $a0, 0x10F0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4336);
label_158c:
    // 0x158c: 0x3c05bf80  lui         $a1, 0xBF80
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49024 << 16));
label_1590:
    // 0x1590: 0x34a51570  ori         $a1, $a1, 0x1570
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)5488);
label_1594:
    // 0x1594: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_1598:
    // 0x1598: 0x3c030008  lui         $v1, 0x8
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8 << 16));
label_159c:
    // 0x159c: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
label_15a0:
    // 0x15a0: 0xac820000  sw          $v0, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
label_15a4:
    // 0x15a4: 0x8ca20000  lw          $v0, 0x0($a1)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
label_15a8:
    // 0x15a8: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_15ac:
    // 0x15ac: 0x34420008  ori         $v0, $v0, 0x8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8);
label_15b0:
    // 0x15b0: 0xc0011e7  jal         func_00479C
label_15b4:
    if (ctx->pc == 0x15B4u) {
        // 0x15b4: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x15B8u;
        goto label_15b8;
    }
    ctx->pc = 0x15B0u;
    SET_GPR_U32(ctx, 31, 0x15B8u);
    // 0x15b4: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x15B0u, 0x15B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x15B8u;
label_15b8:
    // 0x15b8: 0x3c04bf80  lui         $a0, 0xBF80
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49024 << 16));
label_15bc:
    // 0x15bc: 0x34841014  ori         $a0, $a0, 0x1014
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4116);
label_15c0:
    // 0x15c0: 0x3c03200b  lui         $v1, 0x200B
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8203 << 16));
label_15c4:
    // 0x15c4: 0x346331e1  ori         $v1, $v1, 0x31E1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)12769);
label_15c8:
    // 0x15c8: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
label_15cc:
    // 0x15cc: 0x34421414  ori         $v0, $v0, 0x1414
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)5140);
label_15d0:
    // 0x15d0: 0xac830000  sw          $v1, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
label_15d4:
    // 0x15d4: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_15d8:
    // 0x15d8: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_15dc:
    // 0x15dc: 0x0  nop
    // NOP
label_15e0:
    // 0x15e0: 0x3e00008  jr          $ra
label_15e4:
    if (ctx->pc == 0x15E4u) {
        // 0x15e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x15E8u;
        goto label_15e8;
    }
    ctx->pc = 0x15E0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x15e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x15E0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x15E8u;
label_15e8:
    // 0x15e8: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_15ec:
    // 0x15ec: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
label_15f0:
    // 0x15f0: 0xc000554  jal         func_001550
label_15f4:
    if (ctx->pc == 0x15F4u) {
        ctx->pc = 0x15F8u;
        goto label_15f8;
    }
    ctx->pc = 0x15F0u;
    SET_GPR_U32(ctx, 31, 0x15F8u);
    ctx->pc = 0x1550u;
    goto label_1550;
    ctx->pc = 0x15F8u;
label_15f8:
    // 0x15f8: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_15fc:
    // 0x15fc: 0x346307c6  ori         $v1, $v1, 0x7C6
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1990);
label_1600:
    // 0x1600: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_1604:
    // 0x1604: 0x348407c8  ori         $a0, $a0, 0x7C8
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1992);
label_1608:
    // 0x1608: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_160c:
    // 0x160c: 0x34a507ca  ori         $a1, $a1, 0x7CA
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1994);
label_1610:
    // 0x1610: 0x24020900  addiu       $v0, $zero, 0x900
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2304));
label_1614:
    // 0x1614: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_1618:
    // 0x1618: 0x24020200  addiu       $v0, $zero, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
label_161c:
    // 0x161c: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_1620:
    // 0x1620: 0x24020008  addiu       $v0, $zero, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_1624:
    // 0x1624: 0xa4a20000  sh          $v0, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
label_1628:
    // 0x1628: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_162c:
    // 0x162c: 0x0  nop
    // NOP
label_1630:
    // 0x1630: 0x3e00008  jr          $ra
label_1634:
    if (ctx->pc == 0x1634u) {
        // 0x1634: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0x1638u;
        goto label_1638;
    }
    ctx->pc = 0x1630u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1634: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1630u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1638u;
label_1638:
    // 0x1638: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_163c:
    // 0x163c: 0x80c021  addu        $t8, $a0, $zero
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1640:
    // 0x1640: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_1644:
    // 0x1644: 0x346307c0  ori         $v1, $v1, 0x7C0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1984);
label_1648:
    // 0x1648: 0x3402c032  ori         $v0, $zero, 0xC032
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49202);
label_164c:
    // 0x164c: 0xafb40010  sw          $s4, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
label_1650:
    // 0x1650: 0xafb3000c  sw          $s3, 0xC($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 19));
label_1654:
    // 0x1654: 0xafb20008  sw          $s2, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
label_1658:
    // 0x1658: 0xafb10004  sw          $s1, 0x4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 17));
label_165c:
    // 0x165c: 0xafb00000  sw          $s0, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 16));
label_1660:
    // 0x1660: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_1664:
    // 0x1664: 0x17000008  bnez        $t8, . + 4 + (0x8 << 2)
label_1668:
    if (ctx->pc == 0x1668u) {
        // 0x1668: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x166Cu;
        goto label_166c;
    }
    ctx->pc = 0x1664u;
    {
        const bool branch_taken_0x1664 = (GPR_U64(ctx, 24) != GPR_U64(ctx, 0));
        // 0x1668: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x1664) {
            ctx->pc = 0x1688u;
            goto label_1688;
        }
    }
    ctx->pc = 0x166Cu;
label_166c:
    // 0x166c: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_1670:
    // 0x1670: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_1674:
    // 0x1674: 0x3484059a  ori         $a0, $a0, 0x59A
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1434);
label_1678:
    // 0x1678: 0x3402c000  ori         $v0, $zero, 0xC000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49152);
label_167c:
    // 0x167c: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_1680:
    // 0x1680: 0x80005a8  j           func_0016A0
label_1684:
    if (ctx->pc == 0x1684u) {
        // 0x1684: 0x3402c001  ori         $v0, $zero, 0xC001 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49153);
        ctx->pc = 0x1688u;
        goto label_1688;
    }
    ctx->pc = 0x1680u;
    // 0x1684: 0x3402c001  ori         $v0, $zero, 0xC001 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49153);
    ctx->pc = 0x16A0u;
    goto label_16a0;
    ctx->pc = 0x1688u;
label_1688:
    // 0x1688: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_168c:
    // 0x168c: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_1690:
    // 0x1690: 0x3484059a  ori         $a0, $a0, 0x59A
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1434);
label_1694:
    // 0x1694: 0x3402c080  ori         $v0, $zero, 0xC080
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49280);
label_1698:
    // 0x1698: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_169c:
    // 0x169c: 0x3402c081  ori         $v0, $zero, 0xC081
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)49281);
label_16a0:
    // 0x16a0: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_16a4:
    // 0x16a4: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_16a8:
    // 0x16a8: 0x34420188  ori         $v0, $v0, 0x188
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)392);
label_16ac:
    // 0x16ac: 0x3c14bf90  lui         $s4, 0xBF90
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)49040 << 16));
label_16b0:
    // 0x16b0: 0x3694018a  ori         $s4, $s4, 0x18A
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | (uint64_t)(uint16_t)394);
label_16b4:
    // 0x16b4: 0x3c13bf90  lui         $s3, 0xBF90
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)49040 << 16));
label_16b8:
    // 0x16b8: 0x36730190  ori         $s3, $s3, 0x190
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)400);
label_16bc:
    // 0x16bc: 0x3c12bf90  lui         $s2, 0xBF90
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)49040 << 16));
label_16c0:
    // 0x16c0: 0x36520192  ori         $s2, $s2, 0x192
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)402);
label_16c4:
    // 0x16c4: 0x3c11bf90  lui         $s1, 0xBF90
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49040 << 16));
label_16c8:
    // 0x16c8: 0x3631018c  ori         $s1, $s1, 0x18C
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)396);
label_16cc:
    // 0x16cc: 0x3c10bf90  lui         $s0, 0xBF90
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49040 << 16));
label_16d0:
    // 0x16d0: 0x3610018e  ori         $s0, $s0, 0x18E
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)398);
label_16d4:
    // 0x16d4: 0x3c0fbf90  lui         $t7, 0xBF90
    SET_GPR_S32(ctx, 15, (int32_t)((uint32_t)49040 << 16));
label_16d8:
    // 0x16d8: 0x35ef0194  ori         $t7, $t7, 0x194
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) | (uint64_t)(uint16_t)404);
label_16dc:
    // 0x16dc: 0x3c0ebf90  lui         $t6, 0xBF90
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)49040 << 16));
label_16e0:
    // 0x16e0: 0x35ce0196  ori         $t6, $t6, 0x196
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | (uint64_t)(uint16_t)406);
label_16e4:
    // 0x16e4: 0x3c0dbf90  lui         $t5, 0xBF90
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)49040 << 16));
label_16e8:
    // 0x16e8: 0x35ad0588  ori         $t5, $t5, 0x588
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) | (uint64_t)(uint16_t)1416);
label_16ec:
    // 0x16ec: 0x3c0cbf90  lui         $t4, 0xBF90
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)49040 << 16));
label_16f0:
    // 0x16f0: 0x358c058a  ori         $t4, $t4, 0x58A
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | (uint64_t)(uint16_t)1418);
label_16f4:
    // 0x16f4: 0x3c0bbf90  lui         $t3, 0xBF90
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)49040 << 16));
label_16f8:
    // 0x16f8: 0x356b0590  ori         $t3, $t3, 0x590
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)1424);
label_16fc:
    // 0x16fc: 0x3c0abf90  lui         $t2, 0xBF90
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)49040 << 16));
label_1700:
    // 0x1700: 0x354a0592  ori         $t2, $t2, 0x592
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)1426);
label_1704:
    // 0x1704: 0x3c09bf90  lui         $t1, 0xBF90
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)49040 << 16));
label_1708:
    // 0x1708: 0x3529058c  ori         $t1, $t1, 0x58C
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)1420);
label_170c:
    // 0x170c: 0x3c08bf90  lui         $t0, 0xBF90
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)49040 << 16));
label_1710:
    // 0x1710: 0x3508058e  ori         $t0, $t0, 0x58E
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)1422);
label_1714:
    // 0x1714: 0x3c07bf90  lui         $a3, 0xBF90
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)49040 << 16));
label_1718:
    // 0x1718: 0x34e70594  ori         $a3, $a3, 0x594
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)1428);
label_171c:
    // 0x171c: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_1720:
    // 0x1720: 0x34840596  ori         $a0, $a0, 0x596
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1430);
label_1724:
    // 0x1724: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_1728:
    // 0x1728: 0x34a50198  ori         $a1, $a1, 0x198
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)408);
label_172c:
    // 0x172c: 0x3c06bf90  lui         $a2, 0xBF90
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
label_1730:
    // 0x1730: 0x34c60598  ori         $a2, $a2, 0x598
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)1432);
label_1734:
    // 0x1734: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
label_1738:
    // 0x1738: 0xa4430000  sh          $v1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
label_173c:
    // 0x173c: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_1740:
    // 0x1740: 0xa6820000  sh          $v0, 0x0($s4)
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
label_1744:
    // 0x1744: 0xa6630000  sh          $v1, 0x0($s3)
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 3));
label_1748:
    // 0x1748: 0xa6420000  sh          $v0, 0x0($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
label_174c:
    // 0x174c: 0xa6230000  sh          $v1, 0x0($s1)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 3));
label_1750:
    // 0x1750: 0xa6020000  sh          $v0, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_1754:
    // 0x1754: 0xa5e30000  sh          $v1, 0x0($t7)
    WRITE16(ADD32(GPR_U32(ctx, 15), 0), (uint16_t)GPR_U32(ctx, 3));
label_1758:
    // 0x1758: 0xa5c20000  sh          $v0, 0x0($t6)
    WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 2));
label_175c:
    // 0x175c: 0xa5a30000  sh          $v1, 0x0($t5)
    WRITE16(ADD32(GPR_U32(ctx, 13), 0), (uint16_t)GPR_U32(ctx, 3));
label_1760:
    // 0x1760: 0xa5820000  sh          $v0, 0x0($t4)
    WRITE16(ADD32(GPR_U32(ctx, 12), 0), (uint16_t)GPR_U32(ctx, 2));
label_1764:
    // 0x1764: 0xa5630000  sh          $v1, 0x0($t3)
    WRITE16(ADD32(GPR_U32(ctx, 11), 0), (uint16_t)GPR_U32(ctx, 3));
label_1768:
    // 0x1768: 0xa5420000  sh          $v0, 0x0($t2)
    WRITE16(ADD32(GPR_U32(ctx, 10), 0), (uint16_t)GPR_U32(ctx, 2));
label_176c:
    // 0x176c: 0xa5230000  sh          $v1, 0x0($t1)
    WRITE16(ADD32(GPR_U32(ctx, 9), 0), (uint16_t)GPR_U32(ctx, 3));
label_1770:
    // 0x1770: 0xa5020000  sh          $v0, 0x0($t0)
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
label_1774:
    // 0x1774: 0xa4e30000  sh          $v1, 0x0($a3)
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 3));
label_1778:
    // 0x1778: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_177c:
    // 0x177c: 0x24020ff0  addiu       $v0, $zero, 0xFF0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4080));
label_1780:
    // 0x1780: 0xa4a20000  sh          $v0, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
label_1784:
    // 0x1784: 0x24020ffc  addiu       $v0, $zero, 0xFFC
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4092));
label_1788:
    // 0x1788: 0xa4c20000  sh          $v0, 0x0($a2)
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
label_178c:
    // 0x178c: 0x17000021  bnez        $t8, . + 4 + (0x21 << 2)
label_1790:
    if (ctx->pc == 0x1790u) {
        // 0x1790: 0x3c09bf90  lui         $t1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x1794u;
        goto label_1794;
    }
    ctx->pc = 0x178Cu;
    {
        const bool branch_taken_0x178c = (GPR_U64(ctx, 24) != GPR_U64(ctx, 0));
        // 0x1790: 0x3c09bf90  lui         $t1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x178c) {
            ctx->pc = 0x1814u;
            goto label_1814;
        }
    }
    ctx->pc = 0x1794u;
label_1794:
    // 0x1794: 0x3c0bbf90  lui         $t3, 0xBF90
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)49040 << 16));
label_1798:
    // 0x1798: 0x356b0760  ori         $t3, $t3, 0x760
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)1888);
label_179c:
    // 0x179c: 0x3c0abf90  lui         $t2, 0xBF90
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)49040 << 16));
label_17a0:
    // 0x17a0: 0x354a0762  ori         $t2, $t2, 0x762
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)1890);
label_17a4:
    // 0x17a4: 0x35290788  ori         $t1, $t1, 0x788
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)1928);
label_17a8:
    // 0x17a8: 0x3c08bf90  lui         $t0, 0xBF90
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)49040 << 16));
label_17ac:
    // 0x17ac: 0x3508078a  ori         $t0, $t0, 0x78A
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)1930);
label_17b0:
    // 0x17b0: 0x3c07bf90  lui         $a3, 0xBF90
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)49040 << 16));
label_17b4:
    // 0x17b4: 0x34e70764  ori         $a3, $a3, 0x764
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)1892);
label_17b8:
    // 0x17b8: 0x3c06bf90  lui         $a2, 0xBF90
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
label_17bc:
    // 0x17bc: 0x34c60766  ori         $a2, $a2, 0x766
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)1894);
label_17c0:
    // 0x17c0: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_17c4:
    // 0x17c4: 0x34a5078c  ori         $a1, $a1, 0x78C
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1932);
label_17c8:
    // 0x17c8: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_17cc:
    // 0x17cc: 0x3442078e  ori         $v0, $v0, 0x78E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1934);
label_17d0:
    // 0x17d0: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_17d4:
    // 0x17d4: 0x3463033c  ori         $v1, $v1, 0x33C
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)828);
label_17d8:
    // 0x17d8: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_17dc:
    // 0x17dc: 0x3484073c  ori         $a0, $a0, 0x73C
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1852);
label_17e0:
    // 0x17e0: 0xa5600000  sh          $zero, 0x0($t3)
    WRITE16(ADD32(GPR_U32(ctx, 11), 0), (uint16_t)GPR_U32(ctx, 0));
label_17e4:
    // 0x17e4: 0xa5400000  sh          $zero, 0x0($t2)
    WRITE16(ADD32(GPR_U32(ctx, 10), 0), (uint16_t)GPR_U32(ctx, 0));
label_17e8:
    // 0x17e8: 0xa5200000  sh          $zero, 0x0($t1)
    WRITE16(ADD32(GPR_U32(ctx, 9), 0), (uint16_t)GPR_U32(ctx, 0));
label_17ec:
    // 0x17ec: 0xa5000000  sh          $zero, 0x0($t0)
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 0));
label_17f0:
    // 0x17f0: 0xa4e00000  sh          $zero, 0x0($a3)
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 0));
label_17f4:
    // 0x17f4: 0xa4c00000  sh          $zero, 0x0($a2)
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 0));
label_17f8:
    // 0x17f8: 0xa4a00000  sh          $zero, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 0));
label_17fc:
    // 0x17fc: 0xa4400000  sh          $zero, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
label_1800:
    // 0x1800: 0x2402000e  addiu       $v0, $zero, 0xE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
label_1804:
    // 0x1804: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_1808:
    // 0x1808: 0x2402000f  addiu       $v0, $zero, 0xF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_180c:
    // 0x180c: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_1810:
    // 0x1810: 0x3c09bf90  lui         $t1, 0xBF90
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)49040 << 16));
label_1814:
    // 0x1814: 0x35290768  ori         $t1, $t1, 0x768
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)1896);
label_1818:
    // 0x1818: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_181c:
    // 0x181c: 0x3442076a  ori         $v0, $v0, 0x76A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1898);
label_1820:
    // 0x1820: 0x3c08bf90  lui         $t0, 0xBF90
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)49040 << 16));
label_1824:
    // 0x1824: 0x35080790  ori         $t0, $t0, 0x790
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)1936);
label_1828:
    // 0x1828: 0x3c07bf90  lui         $a3, 0xBF90
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)49040 << 16));
label_182c:
    // 0x182c: 0x34e70792  ori         $a3, $a3, 0x792
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)1938);
label_1830:
    // 0x1830: 0x3c06bf90  lui         $a2, 0xBF90
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
label_1834:
    // 0x1834: 0x34c6076c  ori         $a2, $a2, 0x76C
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)1900);
label_1838:
    // 0x1838: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_183c:
    // 0x183c: 0x34a5076e  ori         $a1, $a1, 0x76E
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1902);
label_1840:
    // 0x1840: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_1844:
    // 0x1844: 0x34840794  ori         $a0, $a0, 0x794
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1940);
label_1848:
    // 0x1848: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_184c:
    // 0x184c: 0x34630796  ori         $v1, $v1, 0x796
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1942);
label_1850:
    // 0x1850: 0xa5200000  sh          $zero, 0x0($t1)
    WRITE16(ADD32(GPR_U32(ctx, 9), 0), (uint16_t)GPR_U32(ctx, 0));
label_1854:
    // 0x1854: 0xa4400000  sh          $zero, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
label_1858:
    // 0x1858: 0x24027fff  addiu       $v0, $zero, 0x7FFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
label_185c:
    // 0x185c: 0xa5020000  sh          $v0, 0x0($t0)
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
label_1860:
    // 0x1860: 0xa4e20000  sh          $v0, 0x0($a3)
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 2));
label_1864:
    // 0x1864: 0xa4c00000  sh          $zero, 0x0($a2)
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 0));
label_1868:
    // 0x1868: 0xa4a00000  sh          $zero, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 0));
label_186c:
    // 0x186c: 0xa4800000  sh          $zero, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 0));
label_1870:
    // 0x1870: 0xa4600000  sh          $zero, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 0));
label_1874:
    // 0x1874: 0x8fb40010  lw          $s4, 0x10($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1878:
    // 0x1878: 0x8fb3000c  lw          $s3, 0xC($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
label_187c:
    // 0x187c: 0x8fb20008  lw          $s2, 0x8($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
label_1880:
    // 0x1880: 0x8fb10004  lw          $s1, 0x4($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_1884:
    // 0x1884: 0x8fb00000  lw          $s0, 0x0($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_1888:
    // 0x1888: 0x3e00008  jr          $ra
label_188c:
    if (ctx->pc == 0x188Cu) {
        // 0x188c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0x1890u;
        goto label_1890;
    }
    ctx->pc = 0x1888u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x188c: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1888u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1890u;
label_1890:
    // 0x1890: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_1894:
    // 0x1894: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_1898:
    // 0x1898: 0x8fb20040  lw          $s2, 0x40($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
label_189c:
    // 0x189c: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
label_18a0:
    // 0x18a0: 0xa0a021  addu        $s4, $a1, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_18a4:
    // 0x18a4: 0xafb60028  sw          $s6, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 22));
label_18a8:
    // 0x18a8: 0xc0b021  addu        $s6, $a2, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_18ac:
    // 0x18ac: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
label_18b0:
    // 0x18b0: 0xe0a821  addu        $s5, $a3, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_18b4:
    // 0x18b4: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_18b8:
    // 0x18b8: 0x30930001  andi        $s3, $a0, 0x1
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_18bc:
    // 0x18bc: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
label_18c0:
    // 0x18c0: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_18c4:
    // 0x18c4: 0x16400003  bnez        $s2, . + 4 + (0x3 << 2)
label_18c8:
    if (ctx->pc == 0x18C8u) {
        // 0x18c8: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        ctx->pc = 0x18CCu;
        goto label_18cc;
    }
    ctx->pc = 0x18C4u;
    {
        const bool branch_taken_0x18c4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        // 0x18c8: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x18c4) {
            ctx->pc = 0x18D4u;
            goto label_18d4;
        }
    }
    ctx->pc = 0x18CCu;
label_18cc:
    // 0x18cc: 0x80006b0  j           func_001AC0
label_18d0:
    if (ctx->pc == 0x18D0u) {
        // 0x18d0: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x18D4u;
        goto label_18d4;
    }
    ctx->pc = 0x18CCu;
    // 0x18d0: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
    ctx->pc = 0x1AC0u;
    goto label_1ac0;
    ctx->pc = 0x18D4u;
label_18d4:
    // 0x18d4: 0x138900  sll         $s1, $s3, 4
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 19), 4));
label_18d8:
    // 0x18d8: 0xc000866  jal         func_002198
label_18dc:
    if (ctx->pc == 0x18DCu) {
        // 0x18dc: 0x36240004  ori         $a0, $s1, 0x4 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)4);
        ctx->pc = 0x18E0u;
        goto label_18e0;
    }
    ctx->pc = 0x18D8u;
    SET_GPR_U32(ctx, 31, 0x18E0u);
    // 0x18dc: 0x36240004  ori         $a0, $s1, 0x4 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)4);
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x18E0u;
label_18e0:
    // 0x18e0: 0x14400077  bnez        $v0, . + 4 + (0x77 << 2)
label_18e4:
    if (ctx->pc == 0x18E4u) {
        // 0x18e4: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        ctx->pc = 0x18E8u;
        goto label_18e8;
    }
    ctx->pc = 0x18E0u;
    {
        const bool branch_taken_0x18e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x18e4: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        if (branch_taken_0x18e0) {
            ctx->pc = 0x1AC0u;
            goto label_1ac0;
        }
    }
    ctx->pc = 0x18E8u;
label_18e8:
    // 0x18e8: 0x138080  sll         $s0, $s3, 2
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_18ec:
    // 0x18ec: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_18f0:
    // 0x18f0: 0xd03021  addu        $a2, $a2, $s0
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
label_18f4:
    // 0x18f4: 0x8cc6518c  lw          $a2, 0x518C($a2)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 20876)));
label_18f8:
    // 0x18f8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_18fc:
    // 0x18fc: 0x14c20070  bne         $a2, $v0, . + 4 + (0x70 << 2)
label_1900:
    if (ctx->pc == 0x1900u) {
        // 0x1900: 0x2402ff37  addiu       $v0, $zero, -0xC9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967095));
        ctx->pc = 0x1904u;
        goto label_1904;
    }
    ctx->pc = 0x18FCu;
    {
        const bool branch_taken_0x18fc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        // 0x1900: 0x2402ff37  addiu       $v0, $zero, -0xC9 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967095));
        if (branch_taken_0x18fc) {
            ctx->pc = 0x1AC0u;
            goto label_1ac0;
        }
    }
    ctx->pc = 0x1904u;
label_1904:
    // 0x1904: 0x32830003  andi        $v1, $s4, 0x3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)3);
label_1908:
    // 0x1908: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
label_190c:
    if (ctx->pc == 0x190Cu) {
        // 0x190c: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x1910u;
        goto label_1910;
    }
    ctx->pc = 0x1908u;
    {
        const bool branch_taken_0x1908 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x190c: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        if (branch_taken_0x1908) {
            ctx->pc = 0x1920u;
            goto label_1920;
        }
    }
    ctx->pc = 0x1910u;
label_1910:
    // 0x1910: 0x10660044  beq         $v1, $a2, . + 4 + (0x44 << 2)
label_1914:
    if (ctx->pc == 0x1914u) {
        // 0x1914: 0x36240002  ori         $a0, $s1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)2);
        ctx->pc = 0x1918u;
        goto label_1918;
    }
    ctx->pc = 0x1910u;
    {
        const bool branch_taken_0x1910 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        // 0x1914: 0x36240002  ori         $a0, $s1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)2);
        if (branch_taken_0x1910) {
            ctx->pc = 0x1A24u;
            goto label_1a24;
        }
    }
    ctx->pc = 0x1918u;
label_1918:
    // 0x1918: 0x80006b0  j           func_001AC0
label_191c:
    if (ctx->pc == 0x191Cu) {
        ctx->pc = 0x1920u;
        goto label_1920;
    }
    ctx->pc = 0x1918u;
    ctx->pc = 0x1AC0u;
    goto label_1ac0;
    ctx->pc = 0x1920u;
label_1920:
    // 0x1920: 0x32820008  andi        $v0, $s4, 0x8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)8);
label_1924:
    // 0x1924: 0x14400028  bnez        $v0, . + 4 + (0x28 << 2)
label_1928:
    if (ctx->pc == 0x1928u) {
        // 0x1928: 0x36240002  ori         $a0, $s1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)2);
        ctx->pc = 0x192Cu;
        goto label_192c;
    }
    ctx->pc = 0x1924u;
    {
        const bool branch_taken_0x1924 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1928: 0x36240002  ori         $a0, $s1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)2);
        if (branch_taken_0x1924) {
            ctx->pc = 0x19C8u;
            goto label_19c8;
        }
    }
    ctx->pc = 0x192Cu;
label_192c:
    // 0x192c: 0x1318c0  sll         $v1, $s3, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
label_1930:
    // 0x1930: 0x36620500  ori         $v0, $s3, 0x500
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)1280);
label_1934:
    // 0x1934: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1938:
    // 0x1938: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_193c:
    // 0x193c: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_1940:
    // 0x1940: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1944:
    // 0x1944: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_1948:
    // 0x1948: 0xac205184  sw          $zero, 0x5184($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20868), GPR_U32(ctx, 0));
label_194c:
    // 0x194c: 0xc000866  jal         func_002198
label_1950:
    if (ctx->pc == 0x1950u) {
        // 0x1950: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        ctx->pc = 0x1954u;
        goto label_1954;
    }
    ctx->pc = 0x194Cu;
    SET_GPR_U32(ctx, 31, 0x1954u);
    // 0x1950: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x1954u;
label_1954:
    // 0x1954: 0xc0011e9  jal         func_0047A4
label_1958:
    if (ctx->pc == 0x1958u) {
        ctx->pc = 0x195Cu;
        goto label_195c;
    }
    ctx->pc = 0x1954u;
    SET_GPR_U32(ctx, 31, 0x195Cu);
    ctx->pc = 0x47A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47A4u, 0x1954u, 0x195Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x195Cu;
label_195c:
    // 0x195c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_1960:
    if (ctx->pc == 0x1960u) {
        ctx->pc = 0x1964u;
        goto label_1964;
    }
    ctx->pc = 0x195Cu;
    {
        const bool branch_taken_0x195c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x195c) {
            ctx->pc = 0x1980u;
            goto label_1980;
        }
    }
    ctx->pc = 0x1964u;
label_1964:
    // 0x1964: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1968:
    // 0x1968: 0x902021  addu        $a0, $a0, $s0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
label_196c:
    // 0x196c: 0x8c845300  lw          $a0, 0x5300($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21248)));
label_1970:
    // 0x1970: 0xc00121b  jal         func_00486C
label_1974:
    if (ctx->pc == 0x1974u) {
        // 0x1974: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->pc = 0x1978u;
        goto label_1978;
    }
    ctx->pc = 0x1970u;
    SET_GPR_U32(ctx, 31, 0x1978u);
    // 0x1974: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x486Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x486Cu, 0x1970u, 0x1978u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1978u;
label_1978:
    // 0x1978: 0x8000666  j           func_001998
label_197c:
    if (ctx->pc == 0x197Cu) {
        // 0x197c: 0x131080  sll         $v0, $s3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
        ctx->pc = 0x1980u;
        goto label_1980;
    }
    ctx->pc = 0x1978u;
    // 0x197c: 0x131080  sll         $v0, $s3, 2 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    ctx->pc = 0x1998u;
    goto label_1998;
    ctx->pc = 0x1980u;
label_1980:
    // 0x1980: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1984:
    // 0x1984: 0x902021  addu        $a0, $a0, $s0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
label_1988:
    // 0x1988: 0x8c845300  lw          $a0, 0x5300($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21248)));
label_198c:
    // 0x198c: 0xc001219  jal         func_004864
label_1990:
    if (ctx->pc == 0x1990u) {
        // 0x1990: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->pc = 0x1994u;
        goto label_1994;
    }
    ctx->pc = 0x198Cu;
    SET_GPR_U32(ctx, 31, 0x1994u);
    // 0x1990: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4864u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4864u, 0x198Cu, 0x1994u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1994u;
label_1994:
    // 0x1994: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_1998:
    // 0x1998: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_199c:
    // 0x199c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_19a0:
    // 0x19a0: 0xac20518c  sw          $zero, 0x518C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20876), GPR_U32(ctx, 0));
label_19a4:
    // 0x19a4: 0x121182  srl         $v0, $s2, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 6));
label_19a8:
    // 0x19a8: 0x23180  sll         $a2, $v0, 6
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
label_19ac:
    // 0x19ac: 0x3242003f  andi        $v0, $s2, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)63);
label_19b0:
    // 0x19b0: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
label_19b4:
    if (ctx->pc == 0x19B4u) {
        ctx->pc = 0x19B8u;
        goto label_19b8;
    }
    ctx->pc = 0x19B0u;
    {
        const bool branch_taken_0x19b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x19b0) {
            ctx->pc = 0x19BCu;
            goto label_19bc;
        }
    }
    ctx->pc = 0x19B8u;
label_19b8:
    // 0x19b8: 0x24c60040  addiu       $a2, $a2, 0x40
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
label_19bc:
    // 0x19bc: 0x132100  sll         $a0, $s3, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 19), 4));
label_19c0:
    // 0x19c0: 0x80006ae  j           func_001AB8
label_19c4:
    if (ctx->pc == 0x19C4u) {
        // 0x19c4: 0x34840006  ori         $a0, $a0, 0x6 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)6);
        ctx->pc = 0x19C8u;
        goto label_19c8;
    }
    ctx->pc = 0x19C0u;
    // 0x19c4: 0x34840006  ori         $a0, $a0, 0x6 (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)6);
    ctx->pc = 0x1AB8u;
    goto label_1ab8;
    ctx->pc = 0x19C8u;
label_19c8:
    // 0x19c8: 0x1318c0  sll         $v1, $s3, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
label_19cc:
    // 0x19cc: 0x36620500  ori         $v0, $s3, 0x500
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)1280);
label_19d0:
    // 0x19d0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_19d4:
    // 0x19d4: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_19d8:
    // 0x19d8: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_19dc:
    // 0x19dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_19e0:
    // 0x19e0: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_19e4:
    // 0x19e4: 0xac265184  sw          $a2, 0x5184($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20868), GPR_U32(ctx, 6));
label_19e8:
    // 0x19e8: 0xc000866  jal         func_002198
label_19ec:
    if (ctx->pc == 0x19ECu) {
        // 0x19ec: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        ctx->pc = 0x19F0u;
        goto label_19f0;
    }
    ctx->pc = 0x19E8u;
    SET_GPR_U32(ctx, 31, 0x19F0u);
    // 0x19ec: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x19F0u;
label_19f0:
    // 0x19f0: 0x121182  srl         $v0, $s2, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 6));
label_19f4:
    // 0x19f4: 0x21980  sll         $v1, $v0, 6
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
label_19f8:
    // 0x19f8: 0x3242003f  andi        $v0, $s2, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)63);
label_19fc:
    // 0x19fc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_1a00:
    if (ctx->pc == 0x1A00u) {
        // 0x1a00: 0x609021  addu        $s2, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        ctx->pc = 0x1A04u;
        goto label_1a04;
    }
    ctx->pc = 0x19FCu;
    {
        const bool branch_taken_0x19fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1a00: 0x609021  addu        $s2, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x19fc) {
            ctx->pc = 0x1A0Cu;
            goto label_1a0c;
        }
    }
    ctx->pc = 0x1A04u;
label_1a04:
    // 0x1a04: 0x24630040  addiu       $v1, $v1, 0x40
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 64));
label_1a08:
    // 0x1a08: 0x609021  addu        $s2, $v1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_1a0c:
    // 0x1a0c: 0x2c02021  addu        $a0, $s6, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
label_1a10:
    // 0x1a10: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_1a14:
    // 0x1a14: 0xc000993  jal         func_00264C
label_1a18:
    if (ctx->pc == 0x1A18u) {
        // 0x1a18: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0x1A1Cu;
        goto label_1a1c;
    }
    ctx->pc = 0x1A14u;
    SET_GPR_U32(ctx, 31, 0x1A1Cu);
    // 0x1a18: 0x2603021  addu        $a2, $s3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
    ctx->pc = 0x264Cu;
    goto label_264c;
    ctx->pc = 0x1A1Cu;
label_1a1c:
    // 0x1a1c: 0x80006b0  j           func_001AC0
label_1a20:
    if (ctx->pc == 0x1A20u) {
        // 0x1a20: 0x2401021  addu        $v0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x1A24u;
        goto label_1a24;
    }
    ctx->pc = 0x1A1Cu;
    // 0x1a20: 0x2401021  addu        $v0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x1AC0u;
    goto label_1ac0;
    ctx->pc = 0x1A24u;
label_1a24:
    // 0x1a24: 0x1318c0  sll         $v1, $s3, 3
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
label_1a28:
    // 0x1a28: 0x36620900  ori         $v0, $s3, 0x900
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)2304);
label_1a2c:
    // 0x1a2c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1a30:
    // 0x1a30: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_1a34:
    // 0x1a34: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_1a38:
    // 0x1a38: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1a3c:
    // 0x1a3c: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_1a40:
    // 0x1a40: 0xac205184  sw          $zero, 0x5184($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20868), GPR_U32(ctx, 0));
label_1a44:
    // 0x1a44: 0xc000866  jal         func_002198
label_1a48:
    if (ctx->pc == 0x1A48u) {
        // 0x1a48: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
        ctx->pc = 0x1A4Cu;
        goto label_1a4c;
    }
    ctx->pc = 0x1A44u;
    SET_GPR_U32(ctx, 31, 0x1A4Cu);
    // 0x1a48: 0x2a02821  addu        $a1, $s5, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x1A4Cu;
label_1a4c:
    // 0x1a4c: 0xc0011e9  jal         func_0047A4
label_1a50:
    if (ctx->pc == 0x1A50u) {
        ctx->pc = 0x1A54u;
        goto label_1a54;
    }
    ctx->pc = 0x1A4Cu;
    SET_GPR_U32(ctx, 31, 0x1A54u);
    ctx->pc = 0x47A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47A4u, 0x1A4Cu, 0x1A54u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A54u;
label_1a54:
    // 0x1a54: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_1a58:
    if (ctx->pc == 0x1A58u) {
        ctx->pc = 0x1A5Cu;
        goto label_1a5c;
    }
    ctx->pc = 0x1A54u;
    {
        const bool branch_taken_0x1a54 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a54) {
            ctx->pc = 0x1A78u;
            goto label_1a78;
        }
    }
    ctx->pc = 0x1A5Cu;
label_1a5c:
    // 0x1a5c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1a60:
    // 0x1a60: 0x902021  addu        $a0, $a0, $s0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
label_1a64:
    // 0x1a64: 0x8c845300  lw          $a0, 0x5300($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21248)));
label_1a68:
    // 0x1a68: 0xc00121b  jal         func_00486C
label_1a6c:
    if (ctx->pc == 0x1A6Cu) {
        // 0x1a6c: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->pc = 0x1A70u;
        goto label_1a70;
    }
    ctx->pc = 0x1A68u;
    SET_GPR_U32(ctx, 31, 0x1A70u);
    // 0x1a6c: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x486Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x486Cu, 0x1A68u, 0x1A70u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A70u;
label_1a70:
    // 0x1a70: 0x80006a4  j           func_001A90
label_1a74:
    if (ctx->pc == 0x1A74u) {
        // 0x1a74: 0x131080  sll         $v0, $s3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
        ctx->pc = 0x1A78u;
        goto label_1a78;
    }
    ctx->pc = 0x1A70u;
    // 0x1a74: 0x131080  sll         $v0, $s3, 2 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
    ctx->pc = 0x1A90u;
    goto label_1a90;
    ctx->pc = 0x1A78u;
label_1a78:
    // 0x1a78: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1a7c:
    // 0x1a7c: 0x902021  addu        $a0, $a0, $s0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
label_1a80:
    // 0x1a80: 0x8c845300  lw          $a0, 0x5300($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21248)));
label_1a84:
    // 0x1a84: 0xc001219  jal         func_004864
label_1a88:
    if (ctx->pc == 0x1A88u) {
        // 0x1a88: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->pc = 0x1A8Cu;
        goto label_1a8c;
    }
    ctx->pc = 0x1A84u;
    SET_GPR_U32(ctx, 31, 0x1A8Cu);
    // 0x1a88: 0x2405fffe  addiu       $a1, $zero, -0x2 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    ctx->pc = 0x4864u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4864u, 0x1A84u, 0x1A8Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1A8Cu;
label_1a8c:
    // 0x1a8c: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_1a90:
    // 0x1a90: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1a94:
    // 0x1a94: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_1a98:
    // 0x1a98: 0xac20518c  sw          $zero, 0x518C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20876), GPR_U32(ctx, 0));
label_1a9c:
    // 0x1a9c: 0x121182  srl         $v0, $s2, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 18), 6));
label_1aa0:
    // 0x1aa0: 0x23180  sll         $a2, $v0, 6
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
label_1aa4:
    // 0x1aa4: 0x3242003f  andi        $v0, $s2, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)63);
label_1aa8:
    // 0x1aa8: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
label_1aac:
    if (ctx->pc == 0x1AACu) {
        // 0x1aac: 0x132100  sll         $a0, $s3, 4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 19), 4));
        ctx->pc = 0x1AB0u;
        goto label_1ab0;
    }
    ctx->pc = 0x1AA8u;
    {
        const bool branch_taken_0x1aa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1aac: 0x132100  sll         $a0, $s3, 4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 19), 4));
        if (branch_taken_0x1aa8) {
            ctx->pc = 0x1AB4u;
            goto label_1ab4;
        }
    }
    ctx->pc = 0x1AB0u;
label_1ab0:
    // 0x1ab0: 0x24c60040  addiu       $a2, $a2, 0x40
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 64));
label_1ab4:
    // 0x1ab4: 0x34840005  ori         $a0, $a0, 0x5
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)5);
label_1ab8:
    // 0x1ab8: 0xc000866  jal         func_002198
label_1abc:
    if (ctx->pc == 0x1ABCu) {
        // 0x1abc: 0x2c02821  addu        $a1, $s6, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
        ctx->pc = 0x1AC0u;
        goto label_1ac0;
    }
    ctx->pc = 0x1AB8u;
    SET_GPR_U32(ctx, 31, 0x1AC0u);
    // 0x1abc: 0x2c02821  addu        $a1, $s6, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x1AC0u;
label_1ac0:
    // 0x1ac0: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_1ac4:
    // 0x1ac4: 0x8fb60028  lw          $s6, 0x28($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_1ac8:
    // 0x1ac8: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_1acc:
    // 0x1acc: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_1ad0:
    // 0x1ad0: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_1ad4:
    // 0x1ad4: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1ad8:
    // 0x1ad8: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_1adc:
    // 0x1adc: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1ae0:
    // 0x1ae0: 0x3e00008  jr          $ra
label_1ae4:
    if (ctx->pc == 0x1AE4u) {
        // 0x1ae4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x1AE8u;
        goto label_1ae8;
    }
    ctx->pc = 0x1AE0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1ae4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1AE0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1AE8u;
label_1ae8:
    // 0x1ae8: 0x0  nop
    // NOP
label_1aec:
    // 0x1aec: 0x0  nop
    // NOP
label_1af0:
    // 0x1af0: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_1af4:
    // 0x1af4: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_1af8:
    // 0x1af8: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1afc:
    // 0x1afc: 0x42400  sll         $a0, $a0, 16
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
label_1b00:
    // 0x1b00: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_1b04:
    // 0x1b04: 0x48383  sra         $s0, $a0, 14
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 4), 14));
label_1b08:
    // 0x1b08: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_1b0c:
    // 0x1b0c: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_1b10:
    // 0x1b10: 0x8c425184  lw          $v0, 0x5184($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20868)));
label_1b14:
    // 0x1b14: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_1b18:
    // 0x1b18: 0x24110001  addiu       $s1, $zero, 0x1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b1c:
    // 0x1b1c: 0x10510007  beq         $v0, $s1, . + 4 + (0x7 << 2)
label_1b20:
    if (ctx->pc == 0x1B20u) {
        // 0x1b20: 0xafbf0024  sw          $ra, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
        ctx->pc = 0x1B24u;
        goto label_1b24;
    }
    ctx->pc = 0x1B1Cu;
    {
        const bool branch_taken_0x1b1c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        // 0x1b20: 0xafbf0024  sw          $ra, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
        if (branch_taken_0x1b1c) {
            ctx->pc = 0x1B3Cu;
            goto label_1b3c;
        }
    }
    ctx->pc = 0x1B24u;
label_1b24:
    // 0x1b24: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_1b28:
    // 0x1b28: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_1b2c:
    // 0x1b2c: 0x8c42518c  lw          $v0, 0x518C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 20876)));
label_1b30:
    // 0x1b30: 0x0  nop
    // NOP
label_1b34:
    // 0x1b34: 0x14510003  bne         $v0, $s1, . + 4 + (0x3 << 2)
label_1b38:
    if (ctx->pc == 0x1B38u) {
        // 0x1b38: 0x51400  sll         $v0, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
        ctx->pc = 0x1B3Cu;
        goto label_1b3c;
    }
    ctx->pc = 0x1B34u;
    {
        const bool branch_taken_0x1b34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        // 0x1b38: 0x51400  sll         $v0, $a1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
        if (branch_taken_0x1b34) {
            ctx->pc = 0x1B44u;
            goto label_1b44;
        }
    }
    ctx->pc = 0x1B3Cu;
label_1b3c:
    // 0x1b3c: 0x80006f4  j           func_001BD0
label_1b40:
    if (ctx->pc == 0x1B40u) {
        // 0x1b40: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1B44u;
        goto label_1b44;
    }
    ctx->pc = 0x1B3Cu;
    // 0x1b40: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1BD0u;
    goto label_1bd0;
    ctx->pc = 0x1B44u;
label_1b44:
    // 0x1b44: 0x21403  sra         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
label_1b48:
    // 0x1b48: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
label_1b4c:
    if (ctx->pc == 0x1B4Cu) {
        ctx->pc = 0x1B50u;
        goto label_1b50;
    }
    ctx->pc = 0x1B48u;
    {
        const bool branch_taken_0x1b48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b48) {
            ctx->pc = 0x1B8Cu;
            goto label_1b8c;
        }
    }
    ctx->pc = 0x1B50u;
label_1b50:
    // 0x1b50: 0x1451001b  bne         $v0, $s1, . + 4 + (0x1B << 2)
label_1b54:
    if (ctx->pc == 0x1B54u) {
        // 0x1b54: 0x121400  sll         $v0, $s2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
        ctx->pc = 0x1B58u;
        goto label_1b58;
    }
    ctx->pc = 0x1B50u;
    {
        const bool branch_taken_0x1b50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        // 0x1b54: 0x121400  sll         $v0, $s2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
        if (branch_taken_0x1b50) {
            ctx->pc = 0x1BC0u;
            goto label_1bc0;
        }
    }
    ctx->pc = 0x1B58u;
label_1b58:
    // 0x1b58: 0xc0011e9  jal         func_0047A4
label_1b5c:
    if (ctx->pc == 0x1B5Cu) {
        ctx->pc = 0x1B60u;
        goto label_1b60;
    }
    ctx->pc = 0x1B58u;
    SET_GPR_U32(ctx, 31, 0x1B60u);
    ctx->pc = 0x47A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47A4u, 0x1B58u, 0x1B60u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B60u;
label_1b60:
    // 0x1b60: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
label_1b64:
    if (ctx->pc == 0x1B64u) {
        // 0x1b64: 0x2402ff36  addiu       $v0, $zero, -0xCA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967094));
        ctx->pc = 0x1B68u;
        goto label_1b68;
    }
    ctx->pc = 0x1B60u;
    {
        const bool branch_taken_0x1b60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1b64: 0x2402ff36  addiu       $v0, $zero, -0xCA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967094));
        if (branch_taken_0x1b60) {
            ctx->pc = 0x1BD0u;
            goto label_1bd0;
        }
    }
    ctx->pc = 0x1B68u;
label_1b68:
    // 0x1b68: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1b6c:
    // 0x1b6c: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_1b70:
    // 0x1b70: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_1b74:
    // 0x1b74: 0x902021  addu        $a0, $a0, $s0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
label_1b78:
    // 0x1b78: 0x8c845300  lw          $a0, 0x5300($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21248)));
label_1b7c:
    // 0x1b7c: 0xc00121d  jal         func_004874
label_1b80:
    if (ctx->pc == 0x1B80u) {
        // 0x1b80: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x1B84u;
        goto label_1b84;
    }
    ctx->pc = 0x1B7Cu;
    SET_GPR_U32(ctx, 31, 0x1B84u);
    // 0x1b80: 0x27a70010  addiu       $a3, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4874u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4874u, 0x1B7Cu, 0x1B84u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x1B84u;
label_1b84:
    // 0x1b84: 0x80006e9  j           func_001BA4
label_1b88:
    if (ctx->pc == 0x1B88u) {
        ctx->pc = 0x1B8Cu;
        goto label_1b8c;
    }
    ctx->pc = 0x1B84u;
    ctx->pc = 0x1BA4u;
    goto label_1ba4;
    ctx->pc = 0x1B8Cu;
label_1b8c:
    // 0x1b8c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_1b90:
    // 0x1b90: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_1b94:
    // 0x1b94: 0x8c4252f8  lw          $v0, 0x52F8($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21240)));
label_1b98:
    // 0x1b98: 0x0  nop
    // NOP
label_1b9c:
    // 0x1b9c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_1ba0:
    if (ctx->pc == 0x1BA0u) {
        // 0x1ba0: 0x121400  sll         $v0, $s2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
        ctx->pc = 0x1BA4u;
        goto label_1ba4;
    }
    ctx->pc = 0x1B9Cu;
    {
        const bool branch_taken_0x1b9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1ba0: 0x121400  sll         $v0, $s2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
        if (branch_taken_0x1b9c) {
            ctx->pc = 0x1BC0u;
            goto label_1bc0;
        }
    }
    ctx->pc = 0x1BA4u;
label_1ba4:
    // 0x1ba4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1ba8:
    // 0x1ba8: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_1bac:
    // 0x1bac: 0xac2052f8  sw          $zero, 0x52F8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21240), GPR_U32(ctx, 0));
label_1bb0:
    // 0x1bb0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1bb4:
    // 0x1bb4: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_1bb8:
    // 0x1bb8: 0xac31518c  sw          $s1, 0x518C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20876), GPR_U32(ctx, 17));
label_1bbc:
    // 0x1bbc: 0x121400  sll         $v0, $s2, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 16));
label_1bc0:
    // 0x1bc0: 0x21383  sra         $v0, $v0, 14
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 14));
label_1bc4:
    // 0x1bc4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1bc8:
    // 0x1bc8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_1bcc:
    // 0x1bcc: 0x8c22518c  lw          $v0, 0x518C($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20876)));
label_1bd0:
    // 0x1bd0: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_1bd4:
    // 0x1bd4: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_1bd8:
    // 0x1bd8: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_1bdc:
    // 0x1bdc: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1be0:
    // 0x1be0: 0x3e00008  jr          $ra
label_1be4:
    if (ctx->pc == 0x1BE4u) {
        // 0x1be4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0x1BE8u;
        goto label_1be8;
    }
    ctx->pc = 0x1BE0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1be4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1BE0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1BE8u;
label_1be8:
    // 0x1be8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_1bec:
    // 0x1bec: 0x30840001  andi        $a0, $a0, 0x1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_1bf0:
    // 0x1bf0: 0x410c0  sll         $v0, $a0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
label_1bf4:
    // 0x1bf4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1bf8:
    // 0x1bf8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_1bfc:
    // 0x1bfc: 0xac245328  sw          $a0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 4));
label_1c00:
    // 0x1c00: 0xafa40010  sw          $a0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 4));
label_1c04:
    // 0x1c04: 0x42100  sll         $a0, $a0, 4
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
label_1c08:
    // 0x1c08: 0xafbf0018  sw          $ra, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
label_1c0c:
    // 0x1c0c: 0xc000866  jal         func_002198
label_1c10:
    if (ctx->pc == 0x1C10u) {
        // 0x1c10: 0x3484000a  ori         $a0, $a0, 0xA (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)10);
        ctx->pc = 0x1C14u;
        goto label_1c14;
    }
    ctx->pc = 0x1C0Cu;
    SET_GPR_U32(ctx, 31, 0x1C14u);
    // 0x1c10: 0x3484000a  ori         $a0, $a0, 0xA (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)10);
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x1C14u;
label_1c14:
    // 0x1c14: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1c18:
    // 0x1c18: 0x0  nop
    // NOP
label_1c1c:
    // 0x1c1c: 0x3e00008  jr          $ra
label_1c20:
    if (ctx->pc == 0x1C20u) {
        // 0x1c20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x1C24u;
        goto label_1c24;
    }
    ctx->pc = 0x1C1Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1c20: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1C1Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1C24u;
label_1c24:
    // 0x1c24: 0x0  nop
    // NOP
label_1c28:
    // 0x1c28: 0x0  nop
    // NOP
label_1c2c:
    // 0x1c2c: 0x0  nop
    // NOP
label_1c30:
    // 0x1c30: 0xafa7000c  sw          $a3, 0xC($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 7));
label_1c34:
    // 0x1c34: 0x27bdffb8  addiu       $sp, $sp, -0x48
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967224));
label_1c38:
    // 0x1c38: 0xafb50034  sw          $s5, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 21));
label_1c3c:
    // 0x1c3c: 0x80a821  addu        $s5, $a0, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_1c40:
    // 0x1c40: 0xafb40030  sw          $s4, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 20));
label_1c44:
    // 0x1c44: 0xa0a021  addu        $s4, $a1, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_1c48:
    // 0x1c48: 0xafb7003c  sw          $s7, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 23));
label_1c4c:
    // 0x1c4c: 0xc0b821  addu        $s7, $a2, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_1c50:
    // 0x1c50: 0xafb20028  sw          $s2, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 18));
label_1c54:
    // 0x1c54: 0xe09021  addu        $s2, $a3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_1c58:
    // 0x1c58: 0xafb10024  sw          $s1, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
label_1c5c:
    // 0x1c5c: 0x2411ff9c  addiu       $s1, $zero, -0x64
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
label_1c60:
    // 0x1c60: 0xafb00020  sw          $s0, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 16));
label_1c64:
    // 0x1c64: 0x32b00001  andi        $s0, $s5, 0x1
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)1);
label_1c68:
    // 0x1c68: 0xafb3002c  sw          $s3, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 19));
label_1c6c:
    // 0x1c6c: 0x109900  sll         $s3, $s0, 4
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
label_1c70:
    // 0x1c70: 0x36640004  ori         $a0, $s3, 0x4
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)4);
label_1c74:
    // 0x1c74: 0xafbf0040  sw          $ra, 0x40($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 31));
label_1c78:
    // 0x1c78: 0xc000866  jal         func_002198
label_1c7c:
    if (ctx->pc == 0x1C7Cu) {
        // 0x1c7c: 0xafb60038  sw          $s6, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 22));
        ctx->pc = 0x1C80u;
        goto label_1c80;
    }
    ctx->pc = 0x1C78u;
    SET_GPR_U32(ctx, 31, 0x1C80u);
    // 0x1c7c: 0xafb60038  sw          $s6, 0x38($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 22));
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x1C80u;
label_1c80:
    // 0x1c80: 0x402021  addu        $a0, $v0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_1c84:
    // 0x1c84: 0x32830003  andi        $v1, $s4, 0x3
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)3);
label_1c88:
    // 0x1c88: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c8c:
    // 0x1c8c: 0x10620025  beq         $v1, $v0, . + 4 + (0x25 << 2)
label_1c90:
    if (ctx->pc == 0x1C90u) {
        // 0x1c90: 0x280b021  addu        $s6, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0x1C94u;
        goto label_1c94;
    }
    ctx->pc = 0x1C8Cu;
    {
        const bool branch_taken_0x1c8c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1c90: 0x280b021  addu        $s6, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0x1c8c) {
            ctx->pc = 0x1D24u;
            goto label_1d24;
        }
    }
    ctx->pc = 0x1C94u;
label_1c94:
    // 0x1c94: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
label_1c98:
    // 0x1c98: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_1c9c:
    if (ctx->pc == 0x1C9Cu) {
        // 0x1c9c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x1CA0u;
        goto label_1ca0;
    }
    ctx->pc = 0x1C98u;
    {
        const bool branch_taken_0x1c98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1c9c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1c98) {
            ctx->pc = 0x1CB0u;
            goto label_1cb0;
        }
    }
    ctx->pc = 0x1CA0u;
label_1ca0:
    // 0x1ca0: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
label_1ca4:
    if (ctx->pc == 0x1CA4u) {
        // 0x1ca4: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x1CA8u;
        goto label_1ca8;
    }
    ctx->pc = 0x1CA0u;
    {
        const bool branch_taken_0x1ca0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x1ca4: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1ca0) {
            ctx->pc = 0x1CC8u;
            goto label_1cc8;
        }
    }
    ctx->pc = 0x1CA8u;
label_1ca8:
    // 0x1ca8: 0x800078e  j           func_001E38
label_1cac:
    if (ctx->pc == 0x1CACu) {
        ctx->pc = 0x1CB0u;
        goto label_1cb0;
    }
    ctx->pc = 0x1CA8u;
    ctx->pc = 0x1E38u;
    goto label_1e38;
    ctx->pc = 0x1CB0u;
label_1cb0:
    // 0x1cb0: 0x10620058  beq         $v1, $v0, . + 4 + (0x58 << 2)
label_1cb4:
    if (ctx->pc == 0x1CB4u) {
        // 0x1cb4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->pc = 0x1CB8u;
        goto label_1cb8;
    }
    ctx->pc = 0x1CB0u;
    {
        const bool branch_taken_0x1cb0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1cb4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1cb0) {
            ctx->pc = 0x1E14u;
            goto label_1e14;
        }
    }
    ctx->pc = 0x1CB8u;
label_1cb8:
    // 0x1cb8: 0x10620031  beq         $v1, $v0, . + 4 + (0x31 << 2)
label_1cbc:
    if (ctx->pc == 0x1CBCu) {
        // 0x1cbc: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x1CC0u;
        goto label_1cc0;
    }
    ctx->pc = 0x1CB8u;
    {
        const bool branch_taken_0x1cb8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x1cbc: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1cb8) {
            ctx->pc = 0x1D80u;
            goto label_1d80;
        }
    }
    ctx->pc = 0x1CC0u;
label_1cc0:
    // 0x1cc0: 0x800078e  j           func_001E38
label_1cc4:
    if (ctx->pc == 0x1CC4u) {
        ctx->pc = 0x1CC8u;
        goto label_1cc8;
    }
    ctx->pc = 0x1CC0u;
    ctx->pc = 0x1E38u;
    goto label_1e38;
    ctx->pc = 0x1CC8u;
label_1cc8:
    // 0x1cc8: 0x1240005b  beqz        $s2, . + 4 + (0x5B << 2)
label_1ccc:
    if (ctx->pc == 0x1CCCu) {
        // 0x1ccc: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x1CD0u;
        goto label_1cd0;
    }
    ctx->pc = 0x1CC8u;
    {
        const bool branch_taken_0x1cc8 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        // 0x1ccc: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        if (branch_taken_0x1cc8) {
            ctx->pc = 0x1E38u;
            goto label_1e38;
        }
    }
    ctx->pc = 0x1CD0u;
label_1cd0:
    // 0x1cd0: 0x14800059  bnez        $a0, . + 4 + (0x59 << 2)
label_1cd4:
    if (ctx->pc == 0x1CD4u) {
        // 0x1cd4: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        ctx->pc = 0x1CD8u;
        goto label_1cd8;
    }
    ctx->pc = 0x1CD0u;
    {
        const bool branch_taken_0x1cd0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x1cd4: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        if (branch_taken_0x1cd0) {
            ctx->pc = 0x1E38u;
            goto label_1e38;
        }
    }
    ctx->pc = 0x1CD8u;
label_1cd8:
    // 0x1cd8: 0x1098c0  sll         $s3, $s0, 3
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
label_1cdc:
    // 0x1cdc: 0x36020600  ori         $v0, $s0, 0x600
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)1536);
label_1ce0:
    // 0x1ce0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1ce4:
    // 0x1ce4: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_1ce8:
    // 0x1ce8: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_1cec:
    // 0x1cec: 0x32820010  andi        $v0, $s4, 0x10
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)16);
label_1cf0:
    // 0x1cf0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_1cf4:
    if (ctx->pc == 0x1CF4u) {
        // 0x1cf4: 0x36021600  ori         $v0, $s0, 0x1600 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)5632);
        ctx->pc = 0x1CF8u;
        goto label_1cf8;
    }
    ctx->pc = 0x1CF0u;
    {
        const bool branch_taken_0x1cf0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1cf4: 0x36021600  ori         $v0, $s0, 0x1600 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)5632);
        if (branch_taken_0x1cf0) {
            ctx->pc = 0x1D08u;
            goto label_1d08;
        }
    }
    ctx->pc = 0x1CF8u;
label_1cf8:
    // 0x1cf8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1cfc:
    // 0x1cfc: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_1d00:
    // 0x1d00: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_1d04:
    // 0x1d04: 0x129042  srl         $s2, $s2, 1
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
label_1d08:
    // 0x1d08: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_1d0c:
    // 0x1d0c: 0x2e02021  addu        $a0, $s7, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
label_1d10:
    // 0x1d10: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_1d14:
    // 0x1d14: 0x153400  sll         $a2, $s5, 16
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 21), 16));
label_1d18:
    // 0x1d18: 0x63403  sra         $a2, $a2, 16
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
label_1d1c:
    // 0x1d1c: 0x800077a  j           func_001DE8
label_1d20:
    if (ctx->pc == 0x1D20u) {
        // 0x1d20: 0x32c7ffff  andi        $a3, $s6, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x1D24u;
        goto label_1d24;
    }
    ctx->pc = 0x1D1Cu;
    // 0x1d20: 0x32c7ffff  andi        $a3, $s6, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x1DE8u;
    goto label_1de8;
    ctx->pc = 0x1D24u;
label_1d24:
    // 0x1d24: 0x12400044  beqz        $s2, . + 4 + (0x44 << 2)
label_1d28:
    if (ctx->pc == 0x1D28u) {
        // 0x1d28: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x1D2Cu;
        goto label_1d2c;
    }
    ctx->pc = 0x1D24u;
    {
        const bool branch_taken_0x1d24 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        // 0x1d28: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        if (branch_taken_0x1d24) {
            ctx->pc = 0x1E38u;
            goto label_1e38;
        }
    }
    ctx->pc = 0x1D2Cu;
label_1d2c:
    // 0x1d2c: 0x14800042  bnez        $a0, . + 4 + (0x42 << 2)
label_1d30:
    if (ctx->pc == 0x1D30u) {
        // 0x1d30: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        ctx->pc = 0x1D34u;
        goto label_1d34;
    }
    ctx->pc = 0x1D2Cu;
    {
        const bool branch_taken_0x1d2c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x1d30: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        if (branch_taken_0x1d2c) {
            ctx->pc = 0x1E38u;
            goto label_1e38;
        }
    }
    ctx->pc = 0x1D34u;
label_1d34:
    // 0x1d34: 0x1098c0  sll         $s3, $s0, 3
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
label_1d38:
    // 0x1d38: 0x36020a00  ori         $v0, $s0, 0xA00
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)2560);
label_1d3c:
    // 0x1d3c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1d40:
    // 0x1d40: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_1d44:
    // 0x1d44: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_1d48:
    // 0x1d48: 0x32820010  andi        $v0, $s4, 0x10
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)16);
label_1d4c:
    // 0x1d4c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_1d50:
    if (ctx->pc == 0x1D50u) {
        // 0x1d50: 0x36021a00  ori         $v0, $s0, 0x1A00 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)6656);
        ctx->pc = 0x1D54u;
        goto label_1d54;
    }
    ctx->pc = 0x1D4Cu;
    {
        const bool branch_taken_0x1d4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1d50: 0x36021a00  ori         $v0, $s0, 0x1A00 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)6656);
        if (branch_taken_0x1d4c) {
            ctx->pc = 0x1D64u;
            goto label_1d64;
        }
    }
    ctx->pc = 0x1D54u;
label_1d54:
    // 0x1d54: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1d58:
    // 0x1d58: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_1d5c:
    // 0x1d5c: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_1d60:
    // 0x1d60: 0x129042  srl         $s2, $s2, 1
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
label_1d64:
    // 0x1d64: 0x2e02021  addu        $a0, $s7, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
label_1d68:
    // 0x1d68: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_1d6c:
    // 0x1d6c: 0x2003021  addu        $a2, $s0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_1d70:
    // 0x1d70: 0xc000b99  jal         func_002E64
label_1d74:
    if (ctx->pc == 0x1D74u) {
        // 0x1d74: 0x32c7ffff  andi        $a3, $s6, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x1D78u;
        goto label_1d78;
    }
    ctx->pc = 0x1D70u;
    SET_GPR_U32(ctx, 31, 0x1D78u);
    // 0x1d74: 0x32c7ffff  andi        $a3, $s6, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x2E64u;
    goto label_2e64;
    ctx->pc = 0x1D78u;
label_1d78:
    // 0x1d78: 0x800077d  j           func_001DF4
label_1d7c:
    if (ctx->pc == 0x1D7Cu) {
        // 0x1d7c: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x1D80u;
        goto label_1d80;
    }
    ctx->pc = 0x1D78u;
    // 0x1d7c: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x1DF4u;
    goto label_1df4;
    ctx->pc = 0x1D80u;
label_1d80:
    // 0x1d80: 0x1240002d  beqz        $s2, . + 4 + (0x2D << 2)
label_1d84:
    if (ctx->pc == 0x1D84u) {
        // 0x1d84: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x1D88u;
        goto label_1d88;
    }
    ctx->pc = 0x1D80u;
    {
        const bool branch_taken_0x1d80 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        // 0x1d84: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        if (branch_taken_0x1d80) {
            ctx->pc = 0x1E38u;
            goto label_1e38;
        }
    }
    ctx->pc = 0x1D88u;
label_1d88:
    // 0x1d88: 0x1480002b  bnez        $a0, . + 4 + (0x2B << 2)
label_1d8c:
    if (ctx->pc == 0x1D8Cu) {
        // 0x1d8c: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        ctx->pc = 0x1D90u;
        goto label_1d90;
    }
    ctx->pc = 0x1D88u;
    {
        const bool branch_taken_0x1d88 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x1d8c: 0x2402ff2e  addiu       $v0, $zero, -0xD2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967086));
        if (branch_taken_0x1d88) {
            ctx->pc = 0x1E38u;
            goto label_1e38;
        }
    }
    ctx->pc = 0x1D90u;
label_1d90:
    // 0x1d90: 0x1098c0  sll         $s3, $s0, 3
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
label_1d94:
    // 0x1d94: 0x36020600  ori         $v0, $s0, 0x600
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)1536);
label_1d98:
    // 0x1d98: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1d9c:
    // 0x1d9c: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_1da0:
    // 0x1da0: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_1da4:
    // 0x1da4: 0x32820010  andi        $v0, $s4, 0x10
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)16);
label_1da8:
    // 0x1da8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_1dac:
    if (ctx->pc == 0x1DACu) {
        // 0x1dac: 0x36021600  ori         $v0, $s0, 0x1600 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)5632);
        ctx->pc = 0x1DB0u;
        goto label_1db0;
    }
    ctx->pc = 0x1DA8u;
    {
        const bool branch_taken_0x1da8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1dac: 0x36021600  ori         $v0, $s0, 0x1600 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)5632);
        if (branch_taken_0x1da8) {
            ctx->pc = 0x1DC0u;
            goto label_1dc0;
        }
    }
    ctx->pc = 0x1DB0u;
label_1db0:
    // 0x1db0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1db4:
    // 0x1db4: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_1db8:
    // 0x1db8: 0xac225328  sw          $v0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 2));
label_1dbc:
    // 0x1dbc: 0x129042  srl         $s2, $s2, 1
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 18), 1));
label_1dc0:
    // 0x1dc0: 0x2e02021  addu        $a0, $s7, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
label_1dc4:
    // 0x1dc4: 0x2402821  addu        $a1, $s2, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_1dc8:
    // 0x1dc8: 0x153400  sll         $a2, $s5, 16
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 21), 16));
label_1dcc:
    // 0x1dcc: 0x63403  sra         $a2, $a2, 16
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
label_1dd0:
    // 0x1dd0: 0x27a2005b  addiu       $v0, $sp, 0x5B
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 29), 91));
label_1dd4:
    // 0x1dd4: 0x2403fffc  addiu       $v1, $zero, -0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
label_1dd8:
    // 0x1dd8: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_1ddc:
    // 0x1ddc: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1de0:
    // 0x1de0: 0x32c7ffff  andi        $a3, $s6, 0xFFFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)65535);
label_1de4:
    // 0x1de4: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_1de8:
    // 0x1de8: 0xc000b0f  jal         func_002C3C
label_1dec:
    if (ctx->pc == 0x1DECu) {
        ctx->pc = 0x1DF0u;
        goto label_1df0;
    }
    ctx->pc = 0x1DE8u;
    SET_GPR_U32(ctx, 31, 0x1DF0u);
    ctx->pc = 0x2C3Cu;
    goto label_2c3c;
    ctx->pc = 0x1DF0u;
label_1df0:
    // 0x1df0: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_1df4:
    // 0x1df4: 0x6210010  bgez        $s1, . + 4 + (0x10 << 2)
label_1df8:
    if (ctx->pc == 0x1DF8u) {
        // 0x1df8: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x1DFCu;
        goto label_1dfc;
    }
    ctx->pc = 0x1DF4u;
    {
        const bool branch_taken_0x1df4 = (GPR_S32(ctx, 17) >= 0);
        // 0x1df8: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x1df4) {
            ctx->pc = 0x1E38u;
            goto label_1e38;
        }
    }
    ctx->pc = 0x1DFCu;
label_1dfc:
    // 0x1dfc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1e00:
    // 0x1e00: 0x330821  addu        $at, $at, $s3
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 19)));
label_1e04:
    // 0x1e04: 0xac305328  sw          $s0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 16));
label_1e08:
    // 0x1e08: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_1e0c:
    // 0x1e0c: 0x800078e  j           func_001E38
label_1e10:
    if (ctx->pc == 0x1E10u) {
        // 0x1e10: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x1E14u;
        goto label_1e14;
    }
    ctx->pc = 0x1E0Cu;
    // 0x1e10: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x1E38u;
    goto label_1e38;
    ctx->pc = 0x1E14u;
label_1e14:
    // 0x1e14: 0x1010c0  sll         $v0, $s0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
label_1e18:
    // 0x1e18: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_1e1c:
    // 0x1e1c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_1e20:
    // 0x1e20: 0xac305328  sw          $s0, 0x5328($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21288), GPR_U32(ctx, 16));
label_1e24:
    // 0x1e24: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_1e28:
    // 0x1e28: 0xc000866  jal         func_002198
label_1e2c:
    if (ctx->pc == 0x1E2Cu) {
        // 0x1e2c: 0x3664000a  ori         $a0, $s3, 0xA (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)10);
        ctx->pc = 0x1E30u;
        goto label_1e30;
    }
    ctx->pc = 0x1E28u;
    SET_GPR_U32(ctx, 31, 0x1E30u);
    // 0x1e2c: 0x3664000a  ori         $a0, $s3, 0xA (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)10);
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x1E30u;
label_1e30:
    // 0x1e30: 0x408821  addu        $s1, $v0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_1e34:
    // 0x1e34: 0x2201021  addu        $v0, $s1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_1e38:
    // 0x1e38: 0x8fbf0040  lw          $ra, 0x40($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
label_1e3c:
    // 0x1e3c: 0x8fb7003c  lw          $s7, 0x3C($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
label_1e40:
    // 0x1e40: 0x8fb60038  lw          $s6, 0x38($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_1e44:
    // 0x1e44: 0x8fb50034  lw          $s5, 0x34($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_1e48:
    // 0x1e48: 0x8fb40030  lw          $s4, 0x30($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_1e4c:
    // 0x1e4c: 0x8fb3002c  lw          $s3, 0x2C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_1e50:
    // 0x1e50: 0x8fb20028  lw          $s2, 0x28($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_1e54:
    // 0x1e54: 0x8fb10024  lw          $s1, 0x24($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_1e58:
    // 0x1e58: 0x8fb00020  lw          $s0, 0x20($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_1e5c:
    // 0x1e5c: 0x3e00008  jr          $ra
label_1e60:
    if (ctx->pc == 0x1E60u) {
        // 0x1e60: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = 0x1E64u;
        goto label_1e64;
    }
    ctx->pc = 0x1E5Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1e60: 0x27bd0048  addiu       $sp, $sp, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 72));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1E5Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E64u;
label_1e64:
    // 0x1e64: 0x27bdffe8  addiu       $sp, $sp, -0x18
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967272));
label_1e68:
    // 0x1e68: 0x42400  sll         $a0, $a0, 16
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
label_1e6c:
    // 0x1e6c: 0xafbf0010  sw          $ra, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 31));
label_1e70:
    // 0x1e70: 0xc000aea  jal         func_002BA8
label_1e74:
    if (ctx->pc == 0x1E74u) {
        // 0x1e74: 0x42403  sra         $a0, $a0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
        ctx->pc = 0x1E78u;
        goto label_1e78;
    }
    ctx->pc = 0x1E70u;
    SET_GPR_U32(ctx, 31, 0x1E78u);
    // 0x1e74: 0x42403  sra         $a0, $a0, 16 (Delay Slot)
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    ctx->pc = 0x2BA8u;
    goto label_2ba8;
    ctx->pc = 0x1E78u;
label_1e78:
    // 0x1e78: 0x8fbf0010  lw          $ra, 0x10($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_1e7c:
    // 0x1e7c: 0x0  nop
    // NOP
label_1e80:
    // 0x1e80: 0x3e00008  jr          $ra
label_1e84:
    if (ctx->pc == 0x1E84u) {
        // 0x1e84: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = 0x1E88u;
        goto label_1e88;
    }
    ctx->pc = 0x1E80u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1e84: 0x27bd0018  addiu       $sp, $sp, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 24));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1E80u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1E88u;
label_1e88:
    // 0x1e88: 0x0  nop
    // NOP
label_1e8c:
    // 0x1e8c: 0x0  nop
    // NOP
label_1e90:
    // 0x1e90: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
label_1e94:
    // 0x1e94: 0xafa00000  sw          $zero, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
label_1e98:
    // 0x1e98: 0xafa00000  sw          $zero, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
label_1e9c:
    // 0x1e9c: 0xafa00000  sw          $zero, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
label_1ea0:
    // 0x1ea0: 0xafa00000  sw          $zero, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
label_1ea4:
    // 0x1ea4: 0x3e00008  jr          $ra
label_1ea8:
    if (ctx->pc == 0x1EA8u) {
        // 0x1ea8: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = 0x1EACu;
        goto label_1eac;
    }
    ctx->pc = 0x1EA4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x1ea8: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x1EA4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x1EACu;
label_1eac:
    // 0x1eac: 0x27bdffd0  addiu       $sp, $sp, -0x30
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_1eb0:
    // 0x1eb0: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_1eb4:
    // 0x1eb4: 0x3c10bf90  lui         $s0, 0xBF90
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49040 << 16));
label_1eb8:
    // 0x1eb8: 0x361007c0  ori         $s0, $s0, 0x7C0
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)1984);
label_1ebc:
    // 0x1ebc: 0xafbf002c  sw          $ra, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 31));
label_1ec0:
    // 0x1ec0: 0xafb60028  sw          $s6, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 22));
label_1ec4:
    // 0x1ec4: 0xafb50024  sw          $s5, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 21));
label_1ec8:
    // 0x1ec8: 0xafb40020  sw          $s4, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 20));
label_1ecc:
    // 0x1ecc: 0xafb3001c  sw          $s3, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 19));
label_1ed0:
    // 0x1ed0: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_1ed4:
    // 0x1ed4: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_1ed8:
    // 0x1ed8: 0xa6000000  sh          $zero, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_1edc:
    // 0x1edc: 0xc000854  jal         func_002150
label_1ee0:
    if (ctx->pc == 0x1EE0u) {
        // 0x1ee0: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x1EE4u;
        goto label_1ee4;
    }
    ctx->pc = 0x1EDCu;
    SET_GPR_U32(ctx, 31, 0x1EE4u);
    // 0x1ee0: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x1EE4u;
label_1ee4:
    // 0x1ee4: 0x24040001  addiu       $a0, $zero, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1ee8:
    // 0x1ee8: 0x34118000  ori         $s1, $zero, 0x8000
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
label_1eec:
    // 0x1eec: 0xa6110000  sh          $s1, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 17));
label_1ef0:
    // 0x1ef0: 0xc000854  jal         func_002150
label_1ef4:
    if (ctx->pc == 0x1EF4u) {
        // 0x1ef4: 0x3c16bf90  lui         $s6, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x1EF8u;
        goto label_1ef8;
    }
    ctx->pc = 0x1EF0u;
    SET_GPR_U32(ctx, 31, 0x1EF8u);
    // 0x1ef4: 0x3c16bf90  lui         $s6, 0xBF90 (Delay Slot)
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)49040 << 16));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x1EF8u;
label_1ef8:
    // 0x1ef8: 0x36d60760  ori         $s6, $s6, 0x760
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 22) | (uint64_t)(uint16_t)1888);
label_1efc:
    // 0x1efc: 0x3c15bf90  lui         $s5, 0xBF90
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)49040 << 16));
label_1f00:
    // 0x1f00: 0x36b50762  ori         $s5, $s5, 0x762
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) | (uint64_t)(uint16_t)1890);
label_1f04:
    // 0x1f04: 0x3c14bf90  lui         $s4, 0xBF90
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)49040 << 16));
label_1f08:
    // 0x1f08: 0x36940788  ori         $s4, $s4, 0x788
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | (uint64_t)(uint16_t)1928);
label_1f0c:
    // 0x1f0c: 0x3c13bf90  lui         $s3, 0xBF90
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)49040 << 16));
label_1f10:
    // 0x1f10: 0x3673078a  ori         $s3, $s3, 0x78A
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)1930);
label_1f14:
    // 0x1f14: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_1f18:
    // 0x1f18: 0x346301b0  ori         $v1, $v1, 0x1B0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)432);
label_1f1c:
    // 0x1f1c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_1f20:
    // 0x1f20: 0x344205b0  ori         $v0, $v0, 0x5B0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1456);
label_1f24:
    // 0x1f24: 0x3c12bf90  lui         $s2, 0xBF90
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)49040 << 16));
label_1f28:
    // 0x1f28: 0x3652019a  ori         $s2, $s2, 0x19A
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)410);
label_1f2c:
    // 0x1f2c: 0x3c10bf90  lui         $s0, 0xBF90
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49040 << 16));
label_1f30:
    // 0x1f30: 0x3610059a  ori         $s0, $s0, 0x59A
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)1434);
label_1f34:
    // 0x1f34: 0x24040001  addiu       $a0, $zero, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1f38:
    // 0x1f38: 0xa6c00000  sh          $zero, 0x0($s6)
    WRITE16(ADD32(GPR_U32(ctx, 22), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f3c:
    // 0x1f3c: 0xa6a00000  sh          $zero, 0x0($s5)
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f40:
    // 0x1f40: 0xa6800000  sh          $zero, 0x0($s4)
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f44:
    // 0x1f44: 0xa6600000  sh          $zero, 0x0($s3)
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f48:
    // 0x1f48: 0xa4600000  sh          $zero, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f4c:
    // 0x1f4c: 0xa4400000  sh          $zero, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f50:
    // 0x1f50: 0xa6400000  sh          $zero, 0x0($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f54:
    // 0x1f54: 0xc000854  jal         func_002150
label_1f58:
    if (ctx->pc == 0x1F58u) {
        // 0x1f58: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->pc = 0x1F5Cu;
        goto label_1f5c;
    }
    ctx->pc = 0x1F54u;
    SET_GPR_U32(ctx, 31, 0x1F5Cu);
    // 0x1f58: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x1F5Cu;
label_1f5c:
    // 0x1f5c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_1f60:
    // 0x1f60: 0x34420344  ori         $v0, $v0, 0x344
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)836);
label_1f64:
    // 0x1f64: 0xa6510000  sh          $s1, 0x0($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 17));
label_1f68:
    // 0x1f68: 0xa6110000  sh          $s1, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 17));
label_1f6c:
    // 0x1f6c: 0xa6c00000  sh          $zero, 0x0($s6)
    WRITE16(ADD32(GPR_U32(ctx, 22), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f70:
    // 0x1f70: 0xa6a00000  sh          $zero, 0x0($s5)
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f74:
    // 0x1f74: 0xa6800000  sh          $zero, 0x0($s4)
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f78:
    // 0x1f78: 0xa6600000  sh          $zero, 0x0($s3)
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
label_1f7c:
    // 0x1f7c: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_1f80:
    // 0x1f80: 0x80007eb  j           func_001FAC
label_1f84:
    if (ctx->pc == 0x1F84u) {
        // 0x1f84: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x1F88u;
        goto label_1f88;
    }
    ctx->pc = 0x1F80u;
    // 0x1f84: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1FACu;
    goto label_1fac;
    ctx->pc = 0x1F88u;
label_1f88:
    // 0x1f88: 0x2e020f01  sltiu       $v0, $s0, 0xF01
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)3841) ? 1 : 0);
label_1f8c:
    // 0x1f8c: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
label_1f90:
    if (ctx->pc == 0x1F90u) {
        // 0x1f90: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x1F94u;
        goto label_1f94;
    }
    ctx->pc = 0x1F8Cu;
    {
        const bool branch_taken_0x1f8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x1f90: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x1f8c) {
            ctx->pc = 0x1FDCu;
            goto label_1fdc;
        }
    }
    ctx->pc = 0x1F94u;
label_1f94:
    // 0x1f94: 0xc000854  jal         func_002150
label_1f98:
    if (ctx->pc == 0x1F98u) {
        // 0x1f98: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1F9Cu;
        goto label_1f9c;
    }
    ctx->pc = 0x1F94u;
    SET_GPR_U32(ctx, 31, 0x1F9Cu);
    // 0x1f98: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x1F9Cu;
label_1f9c:
    // 0x1f9c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_1fa0:
    // 0x1fa0: 0x34420344  ori         $v0, $v0, 0x344
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)836);
label_1fa4:
    // 0x1fa4: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_1fa8:
    // 0x1fa8: 0x0  nop
    // NOP
label_1fac:
    // 0x1fac: 0x304207ff  andi        $v0, $v0, 0x7FF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2047);
label_1fb0:
    // 0x1fb0: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
label_1fb4:
    if (ctx->pc == 0x1FB4u) {
        // 0x1fb4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->pc = 0x1FB8u;
        goto label_1fb8;
    }
    ctx->pc = 0x1FB0u;
    {
        const bool branch_taken_0x1fb0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1fb4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x1fb0) {
            ctx->pc = 0x1F88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f88;
        }
    }
    ctx->pc = 0x1FB8u;
label_1fb8:
    // 0x1fb8: 0x2610ffff  addiu       $s0, $s0, -0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
label_1fbc:
    // 0x1fbc: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_1fc0:
    // 0x1fc0: 0x34420744  ori         $v0, $v0, 0x744
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1860);
label_1fc4:
    // 0x1fc4: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_1fc8:
    // 0x1fc8: 0x0  nop
    // NOP
label_1fcc:
    // 0x1fcc: 0x304207ff  andi        $v0, $v0, 0x7FF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)2047);
label_1fd0:
    // 0x1fd0: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
label_1fd4:
    if (ctx->pc == 0x1FD4u) {
        // 0x1fd4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->pc = 0x1FD8u;
        goto label_1fd8;
    }
    ctx->pc = 0x1FD0u;
    {
        const bool branch_taken_0x1fd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x1fd4: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x1fd0) {
            ctx->pc = 0x1F88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f88;
        }
    }
    ctx->pc = 0x1FD8u;
label_1fd8:
    // 0x1fd8: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_1fdc:
    // 0x1fdc: 0x344201a4  ori         $v0, $v0, 0x1A4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)420);
label_1fe0:
    // 0x1fe0: 0x3c0ebf90  lui         $t6, 0xBF90
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)49040 << 16));
label_1fe4:
    // 0x1fe4: 0x35ce01a6  ori         $t6, $t6, 0x1A6
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | (uint64_t)(uint16_t)422);
label_1fe8:
    // 0x1fe8: 0x3c0dbf90  lui         $t5, 0xBF90
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)49040 << 16));
label_1fec:
    // 0x1fec: 0x35ad05a4  ori         $t5, $t5, 0x5A4
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) | (uint64_t)(uint16_t)1444);
label_1ff0:
    // 0x1ff0: 0x3c0cbf90  lui         $t4, 0xBF90
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)49040 << 16));
label_1ff4:
    // 0x1ff4: 0x358c05a6  ori         $t4, $t4, 0x5A6
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | (uint64_t)(uint16_t)1446);
label_1ff8:
    // 0x1ff8: 0x3c0bbf90  lui         $t3, 0xBF90
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)49040 << 16));
label_1ffc:
    // 0x1ffc: 0x356b0180  ori         $t3, $t3, 0x180
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)384);
label_2000:
    // 0x2000: 0x3c0abf90  lui         $t2, 0xBF90
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)49040 << 16));
label_2004:
    // 0x2004: 0x354a0182  ori         $t2, $t2, 0x182
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)386);
label_2008:
    // 0x2008: 0x3c09bf90  lui         $t1, 0xBF90
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)49040 << 16));
label_200c:
    // 0x200c: 0x35290580  ori         $t1, $t1, 0x580
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)1408);
label_2010:
    // 0x2010: 0x3c08bf90  lui         $t0, 0xBF90
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)49040 << 16));
label_2014:
    // 0x2014: 0x35080582  ori         $t0, $t0, 0x582
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)1410);
label_2018:
    // 0x2018: 0x3c07bf90  lui         $a3, 0xBF90
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)49040 << 16));
label_201c:
    // 0x201c: 0x34e70184  ori         $a3, $a3, 0x184
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)388);
label_2020:
    // 0x2020: 0x3c06bf90  lui         $a2, 0xBF90
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
label_2024:
    // 0x2024: 0x34c60186  ori         $a2, $a2, 0x186
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)390);
label_2028:
    // 0x2028: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_202c:
    // 0x202c: 0x34a50584  ori         $a1, $a1, 0x584
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1412);
label_2030:
    // 0x2030: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_2034:
    // 0x2034: 0x34840586  ori         $a0, $a0, 0x586
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1414);
label_2038:
    // 0x2038: 0x3403ffff  ori         $v1, $zero, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
label_203c:
    // 0x203c: 0xa4430000  sh          $v1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
label_2040:
    // 0x2040: 0x240200ff  addiu       $v0, $zero, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_2044:
    // 0x2044: 0xa5c20000  sh          $v0, 0x0($t6)
    WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 2));
label_2048:
    // 0x2048: 0xa5a30000  sh          $v1, 0x0($t5)
    WRITE16(ADD32(GPR_U32(ctx, 13), 0), (uint16_t)GPR_U32(ctx, 3));
label_204c:
    // 0x204c: 0xa5820000  sh          $v0, 0x0($t4)
    WRITE16(ADD32(GPR_U32(ctx, 12), 0), (uint16_t)GPR_U32(ctx, 2));
label_2050:
    // 0x2050: 0xa5600000  sh          $zero, 0x0($t3)
    WRITE16(ADD32(GPR_U32(ctx, 11), 0), (uint16_t)GPR_U32(ctx, 0));
label_2054:
    // 0x2054: 0xa5400000  sh          $zero, 0x0($t2)
    WRITE16(ADD32(GPR_U32(ctx, 10), 0), (uint16_t)GPR_U32(ctx, 0));
label_2058:
    // 0x2058: 0xa5200000  sh          $zero, 0x0($t1)
    WRITE16(ADD32(GPR_U32(ctx, 9), 0), (uint16_t)GPR_U32(ctx, 0));
label_205c:
    // 0x205c: 0xa5000000  sh          $zero, 0x0($t0)
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 0));
label_2060:
    // 0x2060: 0xa4e00000  sh          $zero, 0x0($a3)
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 0));
label_2064:
    // 0x2064: 0xa4c00000  sh          $zero, 0x0($a2)
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 0));
label_2068:
    // 0x2068: 0xa4a00000  sh          $zero, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 0));
label_206c:
    // 0x206c: 0xa4800000  sh          $zero, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 0));
label_2070:
    // 0x2070: 0x8fbf002c  lw          $ra, 0x2C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_2074:
    // 0x2074: 0x8fb60028  lw          $s6, 0x28($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_2078:
    // 0x2078: 0x8fb50024  lw          $s5, 0x24($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_207c:
    // 0x207c: 0x8fb40020  lw          $s4, 0x20($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_2080:
    // 0x2080: 0x8fb3001c  lw          $s3, 0x1C($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_2084:
    // 0x2084: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_2088:
    // 0x2088: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_208c:
    // 0x208c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_2090:
    // 0x2090: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2094:
    // 0x2094: 0x3e00008  jr          $ra
label_2098:
    if (ctx->pc == 0x2098u) {
        // 0x2098: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x209Cu;
        goto label_209c;
    }
    ctx->pc = 0x2094u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2098: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2094u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x209Cu;
label_209c:
    // 0x209c: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
label_20a0:
    // 0x20a0: 0x34421014  ori         $v0, $v0, 0x1014
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4116);
label_20a4:
    // 0x20a4: 0x3c03f0ff  lui         $v1, 0xF0FF
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)61695 << 16));
label_20a8:
    // 0x20a8: 0x42280  sll         $a0, $a0, 10
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 10));
label_20ac:
    // 0x20ac: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_20b0:
    // 0x20b0: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_20b4:
    // 0x20b4: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
label_20b8:
    // 0x20b8: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_20bc:
    // 0x20bc: 0x3e00008  jr          $ra
label_20c0:
    if (ctx->pc == 0x20C0u) {
        // 0x20c0: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x20C4u;
        goto label_20c4;
    }
    ctx->pc = 0x20BCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x20c0: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x20BCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x20C4u;
label_20c4:
    // 0x20c4: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
label_20c8:
    // 0x20c8: 0x34421014  ori         $v0, $v0, 0x1014
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4116);
label_20cc:
    // 0x20cc: 0x3c03f0ff  lui         $v1, 0xF0FF
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)61695 << 16));
label_20d0:
    // 0x20d0: 0x42280  sll         $a0, $a0, 10
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 10));
label_20d4:
    // 0x20d4: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_20d8:
    // 0x20d8: 0x8c820000  lw          $v0, 0x0($a0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_20dc:
    // 0x20dc: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
label_20e0:
    // 0x20e0: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_20e4:
    // 0x20e4: 0x3c030200  lui         $v1, 0x200
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)512 << 16));
label_20e8:
    // 0x20e8: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
label_20ec:
    // 0x20ec: 0x3e00008  jr          $ra
label_20f0:
    if (ctx->pc == 0x20F0u) {
        // 0x20f0: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x20F4u;
        goto label_20f4;
    }
    ctx->pc = 0x20ECu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x20f0: 0xac820000  sw          $v0, 0x0($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x20ECu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x20F4u;
label_20f4:
    // 0x20f4: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
label_20f8:
    // 0x20f8: 0x2402000d  addiu       $v0, $zero, 0xD
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
label_20fc:
    // 0x20fc: 0xafa20004  sw          $v0, 0x4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
label_2100:
    // 0x2100: 0x800084d  j           func_002134
label_2104:
    if (ctx->pc == 0x2104u) {
        // 0x2104: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->pc = 0x2108u;
        goto label_2108;
    }
    ctx->pc = 0x2100u;
    // 0x2104: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x2134u;
    goto label_2134;
    ctx->pc = 0x2108u;
label_2108:
    // 0x2108: 0x8fa30004  lw          $v1, 0x4($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_210c:
    // 0x210c: 0x0  nop
    // NOP
label_2110:
    // 0x2110: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
label_2114:
    // 0x2114: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2118:
    // 0x2118: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_211c:
    // 0x211c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2120:
    // 0x2120: 0xafa20004  sw          $v0, 0x4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
label_2124:
    // 0x2124: 0x8fa20000  lw          $v0, 0x0($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_2128:
    // 0x2128: 0x0  nop
    // NOP
label_212c:
    // 0x212c: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_2130:
    // 0x2130: 0xafa20000  sw          $v0, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
label_2134:
    // 0x2134: 0x8fa20000  lw          $v0, 0x0($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_2138:
    // 0x2138: 0x0  nop
    // NOP
label_213c:
    // 0x213c: 0x28420078  slti        $v0, $v0, 0x78
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)120) ? 1 : 0);
label_2140:
    // 0x2140: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
label_2144:
    if (ctx->pc == 0x2144u) {
        ctx->pc = 0x2148u;
        goto label_2148;
    }
    ctx->pc = 0x2140u;
    {
        const bool branch_taken_0x2140 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2140) {
            ctx->pc = 0x2108u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2108;
        }
    }
    ctx->pc = 0x2148u;
label_2148:
    // 0x2148: 0x3e00008  jr          $ra
label_214c:
    if (ctx->pc == 0x214Cu) {
        // 0x214c: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = 0x2150u;
        goto label_2150;
    }
    ctx->pc = 0x2148u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x214c: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2148u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2150u;
label_2150:
    // 0x2150: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_2154:
    // 0x2154: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_2158:
    // 0x2158: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_215c:
    // 0x215c: 0xafb00010  sw          $s0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
label_2160:
    // 0x2160: 0x8021  addu        $s0, $zero, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2164:
    // 0x2164: 0x1a200007  blez        $s1, . + 4 + (0x7 << 2)
label_2168:
    if (ctx->pc == 0x2168u) {
        // 0x2168: 0xafbf0018  sw          $ra, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
        ctx->pc = 0x216Cu;
        goto label_216c;
    }
    ctx->pc = 0x2164u;
    {
        const bool branch_taken_0x2164 = (GPR_S32(ctx, 17) <= 0);
        // 0x2168: 0xafbf0018  sw          $ra, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 31));
        if (branch_taken_0x2164) {
            ctx->pc = 0x2184u;
            goto label_2184;
        }
    }
    ctx->pc = 0x216Cu;
label_216c:
    // 0x216c: 0xc00083d  jal         func_0020F4
label_2170:
    if (ctx->pc == 0x2170u) {
        // 0x2170: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2174u;
        goto label_2174;
    }
    ctx->pc = 0x216Cu;
    SET_GPR_U32(ctx, 31, 0x2174u);
    // 0x2170: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x20F4u;
    goto label_20f4;
    ctx->pc = 0x2174u;
label_2174:
    // 0x2174: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_2178:
    // 0x2178: 0x211102a  slt         $v0, $s0, $s1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
label_217c:
    // 0x217c: 0x1440fffb  bnez        $v0, . + 4 + (-0x5 << 2)
label_2180:
    if (ctx->pc == 0x2180u) {
        ctx->pc = 0x2184u;
        goto label_2184;
    }
    ctx->pc = 0x217Cu;
    {
        const bool branch_taken_0x217c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x217c) {
            ctx->pc = 0x216Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_216c;
        }
    }
    ctx->pc = 0x2184u;
label_2184:
    // 0x2184: 0x8fbf0018  lw          $ra, 0x18($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_2188:
    // 0x2188: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_218c:
    // 0x218c: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_2190:
    // 0x2190: 0x3e00008  jr          $ra
label_2194:
    if (ctx->pc == 0x2194u) {
        // 0x2194: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x2198u;
        goto label_2198;
    }
    ctx->pc = 0x2190u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2194: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2190u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2198u;
label_2198:
    // 0x2198: 0xafa40000  sw          $a0, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
label_219c:
    // 0x219c: 0xafa50004  sw          $a1, 0x4($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
label_21a0:
    // 0x21a0: 0xafa60008  sw          $a2, 0x8($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
label_21a4:
    // 0x21a4: 0xafa7000c  sw          $a3, 0xC($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 7));
label_21a8:
    // 0x21a8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
label_21ac:
    // 0x21ac: 0x3c03bf80  lui         $v1, 0xBF80
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49024 << 16));
label_21b0:
    // 0x21b0: 0x346310c8  ori         $v1, $v1, 0x10C8
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4296);
label_21b4:
    // 0x21b4: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_21b8:
    // 0x21b8: 0xa021  addu        $s4, $zero, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_21bc:
    // 0x21bc: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_21c0:
    // 0x21c0: 0x48903  sra         $s1, $a0, 4
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 4), 4));
label_21c4:
    // 0x21c4: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_21c8:
    // 0x21c8: 0x119240  sll         $s2, $s1, 9
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 17), 9));
label_21cc:
    // 0x21cc: 0x111100  sll         $v0, $s1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
label_21d0:
    // 0x21d0: 0x511021  addu        $v0, $v0, $s1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
label_21d4:
    // 0x21d4: 0xafb60030  sw          $s6, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 22));
label_21d8:
    // 0x21d8: 0x2b100  sll         $s6, $v0, 4
    SET_GPR_S32(ctx, 22, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
label_21dc:
    // 0x21dc: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
label_21e0:
    // 0x21e0: 0x2a940  sll         $s5, $v0, 5
    SET_GPR_S32(ctx, 21, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
label_21e4:
    // 0x21e4: 0x21180  sll         $v0, $v0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
label_21e8:
    // 0x21e8: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_21ec:
    // 0x21ec: 0x439821  addu        $s3, $v0, $v1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_21f0:
    // 0x21f0: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_21f4:
    // 0x21f4: 0x27b00044  addiu       $s0, $sp, 0x44
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 68));
label_21f8:
    // 0x21f8: 0x3084000f  andi        $a0, $a0, 0xF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
label_21fc:
    // 0x21fc: 0x2484fffe  addiu       $a0, $a0, -0x2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
label_2200:
    // 0x2200: 0x2c820009  sltiu       $v0, $a0, 0x9
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)9) ? 1 : 0);
label_2204:
    // 0x2204: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
label_2208:
    // 0x2208: 0x10400104  beqz        $v0, . + 4 + (0x104 << 2)
label_220c:
    if (ctx->pc == 0x220Cu) {
        // 0x220c: 0xafb70034  sw          $s7, 0x34($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 23));
        ctx->pc = 0x2210u;
        goto label_2210;
    }
    ctx->pc = 0x2208u;
    {
        const bool branch_taken_0x2208 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x220c: 0xafb70034  sw          $s7, 0x34($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 23));
        if (branch_taken_0x2208) {
            ctx->pc = 0x261Cu;
            goto label_261c;
        }
    }
    ctx->pc = 0x2210u;
label_2210:
    // 0x2210: 0x41080  sll         $v0, $a0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_2214:
    // 0x2214: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2218:
    // 0x2218: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_221c:
    // 0x221c: 0x8c2248b0  lw          $v0, 0x48B0($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18608)));
label_2220:
    // 0x2220: 0x0  nop
    // NOP
label_2224:
    // 0x2224: 0x400008  jr          $v0
label_2228:
    if (ctx->pc == 0x2228u) {
        ctx->pc = 0x222Cu;
        goto label_222c;
    }
    ctx->pc = 0x2224u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x222Cu: goto label_222c;
            case 0x2284u: goto label_2284;
            case 0x22DCu: goto label_22dc;
            case 0x2338u: goto label_2338;
            case 0x23F4u: goto label_23f4;
            case 0x261Cu: goto label_261c;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x2224u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x222Cu;
label_222c:
    // 0x222c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_2230:
    // 0x2230: 0x3442019a  ori         $v0, $v0, 0x19A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)410);
label_2234:
    // 0x2234: 0x122040  sll         $a0, $s2, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_2238:
    // 0x2238: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_223c:
    // 0x223c: 0x94450000  lhu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_2240:
    // 0x2240: 0x0  nop
    // NOP
label_2244:
    // 0x2244: 0x30a20030  andi        $v0, $a1, 0x30
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)48);
label_2248:
    // 0x2248: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
label_224c:
    if (ctx->pc == 0x224Cu) {
        ctx->pc = 0x2250u;
        goto label_2250;
    }
    ctx->pc = 0x2248u;
    {
        const bool branch_taken_0x2248 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2248) {
            ctx->pc = 0x227Cu;
            goto label_227c;
        }
    }
    ctx->pc = 0x2250u;
label_2250:
    // 0x2250: 0x8e620000  lw          $v0, 0x0($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_2254:
    // 0x2254: 0x3c030100  lui         $v1, 0x100
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
label_2258:
    // 0x2258: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_225c:
    // 0x225c: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
label_2260:
    if (ctx->pc == 0x2260u) {
        // 0x2260: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x2264u;
        goto label_2264;
    }
    ctx->pc = 0x225Cu;
    {
        const bool branch_taken_0x225c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2260: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x225c) {
            ctx->pc = 0x227Cu;
            goto label_227c;
        }
    }
    ctx->pc = 0x2264u;
label_2264:
    // 0x2264: 0x344201b0  ori         $v0, $v0, 0x1B0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)432);
label_2268:
    // 0x2268: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_226c:
    // 0x226c: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_2270:
    // 0x2270: 0x0  nop
    // NOP
label_2274:
    // 0x2274: 0x104000ea  beqz        $v0, . + 4 + (0xEA << 2)
label_2278:
    if (ctx->pc == 0x2278u) {
        // 0x2278: 0x2801021  addu        $v0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0x227Cu;
        goto label_227c;
    }
    ctx->pc = 0x2274u;
    {
        const bool branch_taken_0x2274 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2278: 0x2801021  addu        $v0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        if (branch_taken_0x2274) {
            ctx->pc = 0x2620u;
            goto label_2620;
        }
    }
    ctx->pc = 0x227Cu;
label_227c:
    // 0x227c: 0x8000987  j           func_00261C
label_2280:
    if (ctx->pc == 0x2280u) {
        // 0x2280: 0x2414ffff  addiu       $s4, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x2284u;
        goto label_2284;
    }
    ctx->pc = 0x227Cu;
    // 0x2280: 0x2414ffff  addiu       $s4, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x261Cu;
    goto label_261c;
    ctx->pc = 0x2284u;
label_2284:
    // 0x2284: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_2288:
    // 0x2288: 0x348401aa  ori         $a0, $a0, 0x1AA
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)426);
label_228c:
    // 0x228c: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_2290:
    // 0x2290: 0x26020003  addiu       $v0, $s0, 0x3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 3));
label_2294:
    // 0x2294: 0x2403fffc  addiu       $v1, $zero, -0x4
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
label_2298:
    // 0x2298: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_229c:
    // 0x229c: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_22a0:
    // 0x22a0: 0x34a501a8  ori         $a1, $a1, 0x1A8
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)424);
label_22a4:
    // 0x22a4: 0x21842  srl         $v1, $v0, 1
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
label_22a8:
    // 0x22a8: 0x2402fff8  addiu       $v0, $zero, -0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967288));
label_22ac:
    // 0x22ac: 0x624824  and         $t1, $v1, $v0
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
label_22b0:
    // 0x22b0: 0x121040  sll         $v0, $s2, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_22b4:
    // 0x22b4: 0x442021  addu        $a0, $v0, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_22b8:
    // 0x22b8: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_22bc:
    // 0x22bc: 0x91c02  srl         $v1, $t1, 16
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
label_22c0:
    // 0x22c0: 0xa4890000  sh          $t1, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 9));
label_22c4:
    // 0x22c4: 0xa4430000  sh          $v1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
label_22c8:
    // 0x22c8: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_22cc:
    // 0x22cc: 0x0  nop
    // NOP
label_22d0:
    // 0x22d0: 0xa7a20010  sh          $v0, 0x10($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 16), (uint16_t)GPR_U32(ctx, 2));
label_22d4:
    // 0x22d4: 0x8000988  j           func_002620
label_22d8:
    if (ctx->pc == 0x22D8u) {
        // 0x22d8: 0x2801021  addu        $v0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0x22DCu;
        goto label_22dc;
    }
    ctx->pc = 0x22D4u;
    // 0x22d8: 0x2801021  addu        $v0, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x2620u;
    goto label_2620;
    ctx->pc = 0x22DCu;
label_22dc:
    // 0x22dc: 0xc0011e5  jal         func_004794
label_22e0:
    if (ctx->pc == 0x22E0u) {
        // 0x22e0: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
        ctx->pc = 0x22E4u;
        goto label_22e4;
    }
    ctx->pc = 0x22DCu;
    SET_GPR_U32(ctx, 31, 0x22E4u);
    // 0x22e0: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x22DCu, 0x22E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x22E4u;
label_22e4:
    // 0x22e4: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_22e8:
    // 0x22e8: 0x3442019a  ori         $v0, $v0, 0x19A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)410);
label_22ec:
    // 0x22ec: 0x121840  sll         $v1, $s2, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_22f0:
    // 0x22f0: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_22f4:
    // 0x22f4: 0x94650000  lhu         $a1, 0x0($v1)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_22f8:
    // 0x22f8: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_22fc:
    // 0x22fc: 0x30a2ffcf  andi        $v0, $a1, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65487);
label_2300:
    // 0x2300: 0x34420020  ori         $v0, $v0, 0x20
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32);
label_2304:
    // 0x2304: 0xc0011e7  jal         func_00479C
label_2308:
    if (ctx->pc == 0x2308u) {
        // 0x2308: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x230Cu;
        goto label_230c;
    }
    ctx->pc = 0x2304u;
    SET_GPR_U32(ctx, 31, 0x230Cu);
    // 0x2308: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x2304u, 0x230Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x230Cu;
label_230c:
    // 0x230c: 0xc000827  jal         func_00209C
label_2310:
    if (ctx->pc == 0x2310u) {
        // 0x2310: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x2314u;
        goto label_2314;
    }
    ctx->pc = 0x230Cu;
    SET_GPR_U32(ctx, 31, 0x2314u);
    // 0x2310: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x209Cu;
    goto label_209c;
    ctx->pc = 0x2314u;
label_2314:
    // 0x2314: 0x3c06bf80  lui         $a2, 0xBF80
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49024 << 16));
label_2318:
    // 0x2318: 0x34c610c0  ori         $a2, $a2, 0x10C0
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4288);
label_231c:
    // 0x231c: 0x3c05bf80  lui         $a1, 0xBF80
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49024 << 16));
label_2320:
    // 0x2320: 0x34a510c4  ori         $a1, $a1, 0x10C4
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4292);
label_2324:
    // 0x2324: 0x3c07bf80  lui         $a3, 0xBF80
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)49024 << 16));
label_2328:
    // 0x2328: 0x34e710c6  ori         $a3, $a3, 0x10C6
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)4294);
label_232c:
    // 0x232c: 0x3c080100  lui         $t0, 0x100
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)256 << 16));
label_2330:
    // 0x2330: 0x80008e3  j           func_00238C
label_2334:
    if (ctx->pc == 0x2334u) {
        // 0x2334: 0x35080201  ori         $t0, $t0, 0x201 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)513);
        ctx->pc = 0x2338u;
        goto label_2338;
    }
    ctx->pc = 0x2330u;
    // 0x2334: 0x35080201  ori         $t0, $t0, 0x201 (Delay Slot)
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)513);
    ctx->pc = 0x238Cu;
    goto label_238c;
    ctx->pc = 0x2338u;
label_2338:
    // 0x2338: 0xc0011e5  jal         func_004794
label_233c:
    if (ctx->pc == 0x233Cu) {
        // 0x233c: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
        ctx->pc = 0x2340u;
        goto label_2340;
    }
    ctx->pc = 0x2338u;
    SET_GPR_U32(ctx, 31, 0x2340u);
    // 0x233c: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x2338u, 0x2340u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2340u;
label_2340:
    // 0x2340: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2344:
    // 0x2344: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_2348:
    // 0x2348: 0x121040  sll         $v0, $s2, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_234c:
    // 0x234c: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2350:
    // 0x2350: 0x94450000  lhu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_2354:
    // 0x2354: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_2358:
    // 0x2358: 0x34a30030  ori         $v1, $a1, 0x30
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)48);
label_235c:
    // 0x235c: 0xc0011e7  jal         func_00479C
label_2360:
    if (ctx->pc == 0x2360u) {
        // 0x2360: 0xa4430000  sh          $v1, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->pc = 0x2364u;
        goto label_2364;
    }
    ctx->pc = 0x235Cu;
    SET_GPR_U32(ctx, 31, 0x2364u);
    // 0x2360: 0xa4430000  sh          $v1, 0x0($v0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x235Cu, 0x2364u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2364u;
label_2364:
    // 0x2364: 0xc000831  jal         func_0020C4
label_2368:
    if (ctx->pc == 0x2368u) {
        // 0x2368: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x236Cu;
        goto label_236c;
    }
    ctx->pc = 0x2364u;
    SET_GPR_U32(ctx, 31, 0x236Cu);
    // 0x2368: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x20C4u;
    goto label_20c4;
    ctx->pc = 0x236Cu;
label_236c:
    // 0x236c: 0x3c06bf80  lui         $a2, 0xBF80
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49024 << 16));
label_2370:
    // 0x2370: 0x34c610c0  ori         $a2, $a2, 0x10C0
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)4288);
label_2374:
    // 0x2374: 0x3c05bf80  lui         $a1, 0xBF80
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49024 << 16));
label_2378:
    // 0x2378: 0x34a510c4  ori         $a1, $a1, 0x10C4
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4292);
label_237c:
    // 0x237c: 0x3c07bf80  lui         $a3, 0xBF80
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)49024 << 16));
label_2380:
    // 0x2380: 0x34e710c6  ori         $a3, $a3, 0x10C6
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)4294);
label_2384:
    // 0x2384: 0x3c080100  lui         $t0, 0x100
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)256 << 16));
label_2388:
    // 0x2388: 0x35080200  ori         $t0, $t0, 0x200
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)512);
label_238c:
    // 0x238c: 0x26030003  addiu       $v1, $s0, 0x3
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 3));
label_2390:
    // 0x2390: 0x2404fffc  addiu       $a0, $zero, -0x4
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
label_2394:
    // 0x2394: 0x641824  and         $v1, $v1, $a0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
label_2398:
    // 0x2398: 0x24620007  addiu       $v0, $v1, 0x7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 7));
label_239c:
    // 0x239c: 0x441024  and         $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
label_23a0:
    // 0x23a0: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_23a4:
    // 0x23a4: 0x8c690000  lw          $t1, 0x0($v1)
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_23a8:
    // 0x23a8: 0x21982  srl         $v1, $v0, 6
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 6));
label_23ac:
    // 0x23ac: 0x3042003f  andi        $v0, $v0, 0x3F
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
label_23b0:
    // 0x23b0: 0x2102b  sltu        $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_23b4:
    // 0x23b4: 0x622021  addu        $a0, $v1, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_23b8:
    // 0x23b8: 0x161080  sll         $v0, $s6, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 2));
label_23bc:
    // 0x23bc: 0x461021  addu        $v0, $v0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_23c0:
    // 0x23c0: 0xac490000  sw          $t1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 9));
label_23c4:
    // 0x23c4: 0x151040  sll         $v0, $s5, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 21), 1));
label_23c8:
    // 0x23c8: 0x452821  addu        $a1, $v0, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_23cc:
    // 0x23cc: 0x24030010  addiu       $v1, $zero, 0x10
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_23d0:
    // 0x23d0: 0x471021  addu        $v0, $v0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
label_23d4:
    // 0x23d4: 0xa4a30000  sh          $v1, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
label_23d8:
    // 0x23d8: 0xa4440000  sh          $a0, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
label_23dc:
    // 0x23dc: 0xae680000  sw          $t0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 8));
label_23e0:
    // 0x23e0: 0x8e620000  lw          $v0, 0x0($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_23e4:
    // 0x23e4: 0x4a180  sll         $s4, $a0, 6
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
label_23e8:
    // 0x23e8: 0xa7a20010  sh          $v0, 0x10($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 16), (uint16_t)GPR_U32(ctx, 2));
label_23ec:
    // 0x23ec: 0x8000988  j           func_002620
label_23f0:
    if (ctx->pc == 0x23F0u) {
        // 0x23f0: 0x2801021  addu        $v0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0x23F4u;
        goto label_23f4;
    }
    ctx->pc = 0x23ECu;
    // 0x23f0: 0x2801021  addu        $v0, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x2620u;
    goto label_2620;
    ctx->pc = 0x23F4u;
label_23f4:
    // 0x23f4: 0xa021  addu        $s4, $zero, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_23f8:
    // 0x23f8: 0x280b821  addu        $s7, $s4, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_23fc:
    // 0x23fc: 0x280a821  addu        $s5, $s4, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_2400:
    // 0x2400: 0x8e620000  lw          $v0, 0x0($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_2404:
    // 0x2404: 0x3c030100  lui         $v1, 0x100
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
label_2408:
    // 0x2408: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_240c:
    // 0x240c: 0x10400032  beqz        $v0, . + 4 + (0x32 << 2)
label_2410:
    if (ctx->pc == 0x2410u) {
        // 0x2410: 0x111880  sll         $v1, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->pc = 0x2414u;
        goto label_2414;
    }
    ctx->pc = 0x240Cu;
    {
        const bool branch_taken_0x240c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2410: 0x111880  sll         $v1, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        if (branch_taken_0x240c) {
            ctx->pc = 0x24D8u;
            goto label_24d8;
        }
    }
    ctx->pc = 0x2414u;
label_2414:
    // 0x2414: 0x3c04bf80  lui         $a0, 0xBF80
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49024 << 16));
label_2418:
    // 0x2418: 0x348410c0  ori         $a0, $a0, 0x10C0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4288);
label_241c:
    // 0x241c: 0x161080  sll         $v0, $s6, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 2));
label_2420:
    // 0x2420: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_2424:
    // 0x2424: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_2428:
    // 0x2428: 0x832021  addu        $a0, $a0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_242c:
    // 0x242c: 0x8c845970  lw          $a0, 0x5970($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 22896)));
label_2430:
    // 0x2430: 0x8c450000  lw          $a1, 0x0($v0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_2434:
    // 0x2434: 0x3c170000  lui         $s7, 0x0
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)0 << 16));
label_2438:
    // 0x2438: 0x2e3b821  addu        $s7, $s7, $v1
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 3)));
label_243c:
    // 0x243c: 0x8ef75970  lw          $s7, 0x5970($s7)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 22896)));
label_2440:
    // 0x2440: 0x8c550000  lw          $s5, 0x0($v0)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_2444:
    // 0x2444: 0x14970005  bne         $a0, $s7, . + 4 + (0x5 << 2)
label_2448:
    if (ctx->pc == 0x2448u) {
        // 0x2448: 0x3c04feff  lui         $a0, 0xFEFF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65279 << 16));
        ctx->pc = 0x244Cu;
        goto label_244c;
    }
    ctx->pc = 0x2444u;
    {
        const bool branch_taken_0x2444 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 23));
        // 0x2448: 0x3c04feff  lui         $a0, 0xFEFF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65279 << 16));
        if (branch_taken_0x2444) {
            ctx->pc = 0x245Cu;
            goto label_245c;
        }
    }
    ctx->pc = 0x244Cu;
label_244c:
    // 0x244c: 0x10b50004  beq         $a1, $s5, . + 4 + (0x4 << 2)
label_2450:
    if (ctx->pc == 0x2450u) {
        // 0x2450: 0x3484ffff  ori         $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
        ctx->pc = 0x2454u;
        goto label_2454;
    }
    ctx->pc = 0x244Cu;
    {
        const bool branch_taken_0x244c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 21));
        // 0x2450: 0x3484ffff  ori         $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
        if (branch_taken_0x244c) {
            ctx->pc = 0x2460u;
            goto label_2460;
        }
    }
    ctx->pc = 0x2454u;
label_2454:
    // 0x2454: 0xa0a821  addu        $s5, $a1, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_2458:
    // 0x2458: 0x3c04feff  lui         $a0, 0xFEFF
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)65279 << 16));
label_245c:
    // 0x245c: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
label_2460:
    // 0x2460: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2464:
    // 0x2464: 0x8e620000  lw          $v0, 0x0($s3)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
label_2468:
    // 0x2468: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_246c:
    // 0x246c: 0x441024  and         $v0, $v0, $a0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
label_2470:
    // 0x2470: 0x122040  sll         $a0, $s2, 1
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_2474:
    // 0x2474: 0x831821  addu        $v1, $a0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_2478:
    // 0x2478: 0xae620000  sw          $v0, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
label_247c:
    // 0x247c: 0x94650000  lhu         $a1, 0x0($v1)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_2480:
    // 0x2480: 0x0  nop
    // NOP
label_2484:
    // 0x2484: 0x30a20030  andi        $v0, $a1, 0x30
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)48);
label_2488:
    // 0x2488: 0x10400013  beqz        $v0, . + 4 + (0x13 << 2)
label_248c:
    if (ctx->pc == 0x248Cu) {
        // 0x248c: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x2490u;
        goto label_2490;
    }
    ctx->pc = 0x2488u;
    {
        const bool branch_taken_0x2488 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x248c: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x2488) {
            ctx->pc = 0x24D8u;
            goto label_24d8;
        }
    }
    ctx->pc = 0x2490u;
label_2490:
    // 0x2490: 0x34420344  ori         $v0, $v0, 0x344
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)836);
label_2494:
    // 0x2494: 0x821821  addu        $v1, $a0, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_2498:
    // 0x2498: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_249c:
    // 0x249c: 0x0  nop
    // NOP
label_24a0:
    // 0x24a0: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
label_24a4:
    // 0x24a4: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
label_24a8:
    if (ctx->pc == 0x24A8u) {
        // 0x24a8: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x24ACu;
        goto label_24ac;
    }
    ctx->pc = 0x24A4u;
    {
        const bool branch_taken_0x24a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x24a8: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x24a4) {
            ctx->pc = 0x24D8u;
            goto label_24d8;
        }
    }
    ctx->pc = 0x24ACu;
label_24ac:
    // 0x24ac: 0x3c050100  lui         $a1, 0x100
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
label_24b0:
    // 0x24b0: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_24b4:
    // 0x24b4: 0xa4102b  sltu        $v0, $a1, $a0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
label_24b8:
    // 0x24b8: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
label_24bc:
    if (ctx->pc == 0x24BCu) {
        // 0x24bc: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x24C0u;
        goto label_24c0;
    }
    ctx->pc = 0x24B8u;
    {
        const bool branch_taken_0x24b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x24bc: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x24b8) {
            ctx->pc = 0x24DCu;
            goto label_24dc;
        }
    }
    ctx->pc = 0x24C0u;
label_24c0:
    // 0x24c0: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_24c4:
    // 0x24c4: 0x0  nop
    // NOP
label_24c8:
    // 0x24c8: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
label_24cc:
    // 0x24cc: 0x1040fff9  beqz        $v0, . + 4 + (-0x7 << 2)
label_24d0:
    if (ctx->pc == 0x24D0u) {
        // 0x24d0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->pc = 0x24D4u;
        goto label_24d4;
    }
    ctx->pc = 0x24CCu;
    {
        const bool branch_taken_0x24cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x24d0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x24cc) {
            ctx->pc = 0x24B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_24b4;
        }
    }
    ctx->pc = 0x24D4u;
label_24d4:
    // 0x24d4: 0x2484ffff  addiu       $a0, $a0, -0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
label_24d8:
    // 0x24d8: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_24dc:
    // 0x24dc: 0x3442019a  ori         $v0, $v0, 0x19A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)410);
label_24e0:
    // 0x24e0: 0x121840  sll         $v1, $s2, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_24e4:
    // 0x24e4: 0x628021  addu        $s0, $v1, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_24e8:
    // 0x24e8: 0x96050000  lhu         $a1, 0x0($s0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_24ec:
    // 0x24ec: 0x0  nop
    // NOP
label_24f0:
    // 0x24f0: 0x30a20030  andi        $v0, $a1, 0x30
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)48);
label_24f4:
    // 0x24f4: 0x10400018  beqz        $v0, . + 4 + (0x18 << 2)
label_24f8:
    if (ctx->pc == 0x24F8u) {
        // 0x24f8: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x24FCu;
        goto label_24fc;
    }
    ctx->pc = 0x24F4u;
    {
        const bool branch_taken_0x24f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x24f8: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x24f4) {
            ctx->pc = 0x2558u;
            goto label_2558;
        }
    }
    ctx->pc = 0x24FCu;
label_24fc:
    // 0x24fc: 0xc0011e5  jal         func_004794
label_2500:
    if (ctx->pc == 0x2500u) {
        // 0x2500: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
        ctx->pc = 0x2504u;
        goto label_2504;
    }
    ctx->pc = 0x24FCu;
    SET_GPR_U32(ctx, 31, 0x2504u);
    // 0x2500: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x24FCu, 0x2504u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2504u;
label_2504:
    // 0x2504: 0x96050000  lhu         $a1, 0x0($s0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_2508:
    // 0x2508: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_250c:
    // 0x250c: 0x30a2ffcf  andi        $v0, $a1, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65487);
label_2510:
    // 0x2510: 0xc0011e7  jal         func_00479C
label_2514:
    if (ctx->pc == 0x2514u) {
        // 0x2514: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x2518u;
        goto label_2518;
    }
    ctx->pc = 0x2510u;
    SET_GPR_U32(ctx, 31, 0x2518u);
    // 0x2514: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x2510u, 0x2518u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2518u;
label_2518:
    // 0x2518: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_251c:
    // 0x251c: 0x0  nop
    // NOP
label_2520:
    // 0x2520: 0x30420030  andi        $v0, $v0, 0x30
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)48);
label_2524:
    // 0x2524: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
label_2528:
    if (ctx->pc == 0x2528u) {
        // 0x2528: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x252Cu;
        goto label_252c;
    }
    ctx->pc = 0x2524u;
    {
        const bool branch_taken_0x2524 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2528: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2524) {
            ctx->pc = 0x2554u;
            goto label_2554;
        }
    }
    ctx->pc = 0x252Cu;
label_252c:
    // 0x252c: 0x2001821  addu        $v1, $s0, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_2530:
    // 0x2530: 0x24840001  addiu       $a0, $a0, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_2534:
    // 0x2534: 0x2c820f01  sltiu       $v0, $a0, 0xF01
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3841) ? 1 : 0);
label_2538:
    // 0x2538: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
label_253c:
    if (ctx->pc == 0x253Cu) {
        ctx->pc = 0x2540u;
        goto label_2540;
    }
    ctx->pc = 0x2538u;
    {
        const bool branch_taken_0x2538 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2538) {
            ctx->pc = 0x2554u;
            goto label_2554;
        }
    }
    ctx->pc = 0x2540u;
label_2540:
    // 0x2540: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_2544:
    // 0x2544: 0x0  nop
    // NOP
label_2548:
    // 0x2548: 0x30420030  andi        $v0, $v0, 0x30
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)48);
label_254c:
    // 0x254c: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
label_2550:
    if (ctx->pc == 0x2550u) {
        // 0x2550: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->pc = 0x2554u;
        goto label_2554;
    }
    ctx->pc = 0x254Cu;
    {
        const bool branch_taken_0x254c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2550: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x254c) {
            ctx->pc = 0x2534u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2534;
        }
    }
    ctx->pc = 0x2554u;
label_2554:
    // 0x2554: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2558:
    // 0x2558: 0x346301b0  ori         $v1, $v1, 0x1B0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)432);
label_255c:
    // 0x255c: 0x121040  sll         $v0, $s2, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
label_2560:
    // 0x2560: 0x431821  addu        $v1, $v0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2564:
    // 0x2564: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_2568:
    // 0x2568: 0x0  nop
    // NOP
label_256c:
    // 0x256c: 0x30420007  andi        $v0, $v0, 0x7
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
label_2570:
    // 0x2570: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_2574:
    if (ctx->pc == 0x2574u) {
        // 0x2574: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2578u;
        goto label_2578;
    }
    ctx->pc = 0x2570u;
    {
        const bool branch_taken_0x2570 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2574: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2570) {
            ctx->pc = 0x2580u;
            goto label_2580;
        }
    }
    ctx->pc = 0x2578u;
label_2578:
    // 0x2578: 0x24100001  addiu       $s0, $zero, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_257c:
    // 0x257c: 0xa4600000  sh          $zero, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 0));
label_2580:
    // 0x2580: 0xc0011e9  jal         func_0047A4
label_2584:
    if (ctx->pc == 0x2584u) {
        ctx->pc = 0x2588u;
        goto label_2588;
    }
    ctx->pc = 0x2580u;
    SET_GPR_U32(ctx, 31, 0x2588u);
    ctx->pc = 0x47A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47A4u, 0x2580u, 0x2588u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2588u;
label_2588:
    // 0x2588: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_258c:
    if (ctx->pc == 0x258Cu) {
        // 0x258c: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->pc = 0x2590u;
        goto label_2590;
    }
    ctx->pc = 0x2588u;
    {
        const bool branch_taken_0x2588 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x258c: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        if (branch_taken_0x2588) {
            ctx->pc = 0x25ACu;
            goto label_25ac;
        }
    }
    ctx->pc = 0x2590u;
label_2590:
    // 0x2590: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_2594:
    // 0x2594: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_2598:
    // 0x2598: 0x8c845300  lw          $a0, 0x5300($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21248)));
label_259c:
    // 0x259c: 0xc001217  jal         func_00485C
label_25a0:
    if (ctx->pc == 0x25A0u) {
        // 0x25a0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x25A4u;
        goto label_25a4;
    }
    ctx->pc = 0x259Cu;
    SET_GPR_U32(ctx, 31, 0x25A4u);
    // 0x25a0: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x485Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x485Cu, 0x259Cu, 0x25A4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x25A4u;
label_25a4:
    // 0x25a4: 0x8000971  j           func_0025C4
label_25a8:
    if (ctx->pc == 0x25A8u) {
        // 0x25a8: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->pc = 0x25ACu;
        goto label_25ac;
    }
    ctx->pc = 0x25A4u;
    // 0x25a8: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    ctx->pc = 0x25C4u;
    goto label_25c4;
    ctx->pc = 0x25ACu;
label_25ac:
    // 0x25ac: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_25b0:
    // 0x25b0: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_25b4:
    // 0x25b4: 0x8c845300  lw          $a0, 0x5300($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21248)));
label_25b8:
    // 0x25b8: 0xc001215  jal         func_004854
label_25bc:
    if (ctx->pc == 0x25BCu) {
        // 0x25bc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x25C0u;
        goto label_25c0;
    }
    ctx->pc = 0x25B8u;
    SET_GPR_U32(ctx, 31, 0x25C0u);
    // 0x25bc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4854u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4854u, 0x25B8u, 0x25C0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x25C0u;
label_25c0:
    // 0x25c0: 0x111080  sll         $v0, $s1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
label_25c4:
    // 0x25c4: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_25c8:
    // 0x25c8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_25cc:
    // 0x25cc: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_25d0:
    // 0x25d0: 0xac2052f8  sw          $zero, 0x52F8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21240), GPR_U32(ctx, 0));
label_25d4:
    // 0x25d4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_25d8:
    // 0x25d8: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_25dc:
    // 0x25dc: 0xac23518c  sw          $v1, 0x518C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20876), GPR_U32(ctx, 3));
label_25e0:
    // 0x25e0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_25e4:
    // 0x25e4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_25e8:
    // 0x25e8: 0xac205320  sw          $zero, 0x5320($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21280), GPR_U32(ctx, 0));
label_25ec:
    // 0x25ec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_25f0:
    // 0x25f0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_25f4:
    // 0x25f4: 0x8c22518c  lw          $v0, 0x518C($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20876)));
label_25f8:
    // 0x25f8: 0x0  nop
    // NOP
label_25fc:
    // 0x25fc: 0xa7a20010  sh          $v0, 0x10($sp)
    WRITE16(ADD32(GPR_U32(ctx, 29), 16), (uint16_t)GPR_U32(ctx, 2));
label_2600:
    // 0x2600: 0x12a00006  beqz        $s5, . + 4 + (0x6 << 2)
label_2604:
    if (ctx->pc == 0x2604u) {
        // 0x2604: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->pc = 0x2608u;
        goto label_2608;
    }
    ctx->pc = 0x2600u;
    {
        const bool branch_taken_0x2600 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        // 0x2604: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        if (branch_taken_0x2600) {
            ctx->pc = 0x261Cu;
            goto label_261c;
        }
    }
    ctx->pc = 0x2608u;
label_2608:
    // 0x2608: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_260c:
    // 0x260c: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
label_2610:
    if (ctx->pc == 0x2610u) {
        // 0x2610: 0x2a2a024  and         $s4, $s5, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 20, GPR_U64(ctx, 21) & GPR_U64(ctx, 2));
        ctx->pc = 0x2614u;
        goto label_2614;
    }
    ctx->pc = 0x260Cu;
    {
        const bool branch_taken_0x260c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        // 0x2610: 0x2a2a024  and         $s4, $s5, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 20, GPR_U64(ctx, 21) & GPR_U64(ctx, 2));
        if (branch_taken_0x260c) {
            ctx->pc = 0x261Cu;
            goto label_261c;
        }
    }
    ctx->pc = 0x2614u;
label_2614:
    // 0x2614: 0x171600  sll         $v0, $s7, 24
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 23), 24));
label_2618:
    // 0x2618: 0x282a025  or          $s4, $s4, $v0
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | GPR_U64(ctx, 2));
label_261c:
    // 0x261c: 0x2801021  addu        $v0, $s4, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_2620:
    // 0x2620: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_2624:
    // 0x2624: 0x8fb70034  lw          $s7, 0x34($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_2628:
    // 0x2628: 0x8fb60030  lw          $s6, 0x30($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_262c:
    // 0x262c: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_2630:
    // 0x2630: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_2634:
    // 0x2634: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_2638:
    // 0x2638: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_263c:
    // 0x263c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_2640:
    // 0x2640: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_2644:
    // 0x2644: 0x3e00008  jr          $ra
label_2648:
    if (ctx->pc == 0x2648u) {
        // 0x2648: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x264Cu;
        goto label_264c;
    }
    ctx->pc = 0x2644u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2648: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2644u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x264Cu;
label_264c:
    // 0x264c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
label_2650:
    // 0x2650: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_2654:
    // 0x2654: 0xa09821  addu        $s3, $a1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_2658:
    // 0x2658: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_265c:
    // 0x265c: 0x80a021  addu        $s4, $a0, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_2660:
    // 0x2660: 0xafbe0038  sw          $fp, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 30));
label_2664:
    // 0x2664: 0xafa60048  sw          $a2, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 6));
label_2668:
    // 0x2668: 0x6f240  sll         $fp, $a2, 9
    SET_GPR_S32(ctx, 30, (int32_t)SLL32(GPR_U32(ctx, 6), 9));
label_266c:
    // 0x266c: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
label_2670:
    // 0x2670: 0xafb70034  sw          $s7, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 23));
label_2674:
    // 0x2674: 0xafb60030  sw          $s6, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 22));
label_2678:
    // 0x2678: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
label_267c:
    // 0x267c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_2680:
    // 0x2680: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_2684:
    // 0x2684: 0x12600036  beqz        $s3, . + 4 + (0x36 << 2)
label_2688:
    if (ctx->pc == 0x2688u) {
        // 0x2688: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        ctx->pc = 0x268Cu;
        goto label_268c;
    }
    ctx->pc = 0x2684u;
    {
        const bool branch_taken_0x2684 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        // 0x2688: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        if (branch_taken_0x2684) {
            ctx->pc = 0x2760u;
            goto label_2760;
        }
    }
    ctx->pc = 0x268Cu;
label_268c:
    // 0x268c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_2690:
    // 0x2690: 0x344201ac  ori         $v0, $v0, 0x1AC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)428);
label_2694:
    // 0x2694: 0x6b280  sll         $s6, $a2, 10
    SET_GPR_S32(ctx, 22, (int32_t)SLL32(GPR_U32(ctx, 6), 10));
label_2698:
    // 0x2698: 0x2c2b821  addu        $s7, $s6, $v0
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 2)));
label_269c:
    // 0x269c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_26a0:
    // 0x26a0: 0x3442019a  ori         $v0, $v0, 0x19A
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)410);
label_26a4:
    // 0x26a4: 0x2c2a821  addu        $s5, $s6, $v0
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 2)));
label_26a8:
    // 0x26a8: 0x2e620041  sltiu       $v0, $s3, 0x41
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)(int64_t)(int32_t)65) ? 1 : 0);
label_26ac:
    // 0x26ac: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
label_26b0:
    if (ctx->pc == 0x26B0u) {
        // 0x26b0: 0x24120040  addiu       $s2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->pc = 0x26B4u;
        goto label_26b4;
    }
    ctx->pc = 0x26ACu;
    {
        const bool branch_taken_0x26ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x26b0: 0x24120040  addiu       $s2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        if (branch_taken_0x26ac) {
            ctx->pc = 0x26B8u;
            goto label_26b8;
        }
    }
    ctx->pc = 0x26B4u;
label_26b4:
    // 0x26b4: 0x2609021  addu        $s2, $s3, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_26b8:
    // 0x26b8: 0x1a400008  blez        $s2, . + 4 + (0x8 << 2)
label_26bc:
    if (ctx->pc == 0x26BCu) {
        // 0x26bc: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x26C0u;
        goto label_26c0;
    }
    ctx->pc = 0x26B8u;
    {
        const bool branch_taken_0x26b8 = (GPR_S32(ctx, 18) <= 0);
        // 0x26bc: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x26b8) {
            ctx->pc = 0x26DCu;
            goto label_26dc;
        }
    }
    ctx->pc = 0x26C0u;
label_26c0:
    // 0x26c0: 0x96820000  lhu         $v0, 0x0($s4)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
label_26c4:
    // 0x26c4: 0x26940002  addiu       $s4, $s4, 0x2
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 2));
label_26c8:
    // 0x26c8: 0x24630002  addiu       $v1, $v1, 0x2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2));
label_26cc:
    // 0x26cc: 0xa6e20000  sh          $v0, 0x0($s7)
    WRITE16(ADD32(GPR_U32(ctx, 23), 0), (uint16_t)GPR_U32(ctx, 2));
label_26d0:
    // 0x26d0: 0x72102a  slt         $v0, $v1, $s2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
label_26d4:
    // 0x26d4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
label_26d8:
    if (ctx->pc == 0x26D8u) {
        ctx->pc = 0x26DCu;
        goto label_26dc;
    }
    ctx->pc = 0x26D4u;
    {
        const bool branch_taken_0x26d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x26d4) {
            ctx->pc = 0x26C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_26c0;
        }
    }
    ctx->pc = 0x26DCu;
label_26dc:
    // 0x26dc: 0xc0011e5  jal         func_004794
label_26e0:
    if (ctx->pc == 0x26E0u) {
        // 0x26e0: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
        ctx->pc = 0x26E4u;
        goto label_26e4;
    }
    ctx->pc = 0x26DCu;
    SET_GPR_U32(ctx, 31, 0x26E4u);
    // 0x26e0: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x26DCu, 0x26E4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26E4u;
label_26e4:
    // 0x26e4: 0x96a30000  lhu         $v1, 0x0($s5)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 0)));
label_26e8:
    // 0x26e8: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_26ec:
    // 0x26ec: 0x3062ffcf  andi        $v0, $v1, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65487);
label_26f0:
    // 0x26f0: 0x34420010  ori         $v0, $v0, 0x10
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
label_26f4:
    // 0x26f4: 0xc0011e7  jal         func_00479C
label_26f8:
    if (ctx->pc == 0x26F8u) {
        // 0x26f8: 0xa6a20000  sh          $v0, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x26FCu;
        goto label_26fc;
    }
    ctx->pc = 0x26F4u;
    SET_GPR_U32(ctx, 31, 0x26FCu);
    // 0x26f8: 0xa6a20000  sh          $v0, 0x0($s5) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x26F4u, 0x26FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x26FCu;
label_26fc:
    // 0x26fc: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2700:
    // 0x2700: 0x34630344  ori         $v1, $v1, 0x344
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)836);
label_2704:
    // 0x2704: 0x2c31021  addu        $v0, $s6, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 3)));
label_2708:
    // 0x2708: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_270c:
    // 0x270c: 0x0  nop
    // NOP
label_2710:
    // 0x2710: 0x30420400  andi        $v0, $v0, 0x400
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1024);
label_2714:
    // 0x2714: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
label_2718:
    if (ctx->pc == 0x2718u) {
        // 0x2718: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x271Cu;
        goto label_271c;
    }
    ctx->pc = 0x2714u;
    {
        const bool branch_taken_0x2714 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2718: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2714) {
            ctx->pc = 0x2754u;
            goto label_2754;
        }
    }
    ctx->pc = 0x271Cu;
label_271c:
    // 0x271c: 0x1e1040  sll         $v0, $fp, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), 1));
label_2720:
    // 0x2720: 0x438821  addu        $s1, $v0, $v1
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2724:
    // 0x2724: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_2728:
    // 0x2728: 0x2e020f01  sltiu       $v0, $s0, 0xF01
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)(int64_t)(int32_t)3841) ? 1 : 0);
label_272c:
    // 0x272c: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
label_2730:
    if (ctx->pc == 0x2730u) {
        ctx->pc = 0x2734u;
        goto label_2734;
    }
    ctx->pc = 0x272Cu;
    {
        const bool branch_taken_0x272c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x272c) {
            ctx->pc = 0x2754u;
            goto label_2754;
        }
    }
    ctx->pc = 0x2734u;
label_2734:
    // 0x2734: 0xc000854  jal         func_002150
label_2738:
    if (ctx->pc == 0x2738u) {
        // 0x2738: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x273Cu;
        goto label_273c;
    }
    ctx->pc = 0x2734u;
    SET_GPR_U32(ctx, 31, 0x273Cu);
    // 0x2738: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x273Cu;
label_273c:
    // 0x273c: 0x96220000  lhu         $v0, 0x0($s1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
label_2740:
    // 0x2740: 0x0  nop
    // NOP
label_2744:
    // 0x2744: 0x30420400  andi        $v0, $v0, 0x400
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1024);
label_2748:
    // 0x2748: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
label_274c:
    if (ctx->pc == 0x274Cu) {
        // 0x274c: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->pc = 0x2750u;
        goto label_2750;
    }
    ctx->pc = 0x2748u;
    {
        const bool branch_taken_0x2748 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x274c: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x2748) {
            ctx->pc = 0x2728u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2728;
        }
    }
    ctx->pc = 0x2750u;
label_2750:
    // 0x2750: 0x2610ffff  addiu       $s0, $s0, -0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
label_2754:
    // 0x2754: 0x2729823  subu        $s3, $s3, $s2
    SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
label_2758:
    // 0x2758: 0x1660ffd4  bnez        $s3, . + 4 + (-0x2C << 2)
label_275c:
    if (ctx->pc == 0x275Cu) {
        // 0x275c: 0x2e620041  sltiu       $v0, $s3, 0x41 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)(int64_t)(int32_t)65) ? 1 : 0);
        ctx->pc = 0x2760u;
        goto label_2760;
    }
    ctx->pc = 0x2758u;
    {
        const bool branch_taken_0x2758 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        // 0x275c: 0x2e620041  sltiu       $v0, $s3, 0x41 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)(int64_t)(int32_t)65) ? 1 : 0);
        if (branch_taken_0x2758) {
            ctx->pc = 0x26ACu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_26ac;
        }
    }
    ctx->pc = 0x2760u;
label_2760:
    // 0x2760: 0xc0011e5  jal         func_004794
label_2764:
    if (ctx->pc == 0x2764u) {
        // 0x2764: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
        ctx->pc = 0x2768u;
        goto label_2768;
    }
    ctx->pc = 0x2760u;
    SET_GPR_U32(ctx, 31, 0x2768u);
    // 0x2764: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x2760u, 0x2768u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2768u;
label_2768:
    // 0x2768: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_276c:
    // 0x276c: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_2770:
    // 0x2770: 0x1e1040  sll         $v0, $fp, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), 1));
label_2774:
    // 0x2774: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2778:
    // 0x2778: 0x94430000  lhu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_277c:
    // 0x277c: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_2780:
    // 0x2780: 0x3063ffcf  andi        $v1, $v1, 0xFFCF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65487);
label_2784:
    // 0x2784: 0xc0011e7  jal         func_00479C
label_2788:
    if (ctx->pc == 0x2788u) {
        // 0x2788: 0xa4430000  sh          $v1, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->pc = 0x278Cu;
        goto label_278c;
    }
    ctx->pc = 0x2784u;
    SET_GPR_U32(ctx, 31, 0x278Cu);
    // 0x2788: 0xa4430000  sh          $v1, 0x0($v0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x2784u, 0x278Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x278Cu;
label_278c:
    // 0x278c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2790:
    // 0x2790: 0x8fa70048  lw          $a3, 0x48($sp)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
label_2794:
    // 0x2794: 0x8fbf003c  lw          $ra, 0x3C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
label_2798:
    // 0x2798: 0x8fbe0038  lw          $fp, 0x38($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_279c:
    // 0x279c: 0x8fb70034  lw          $s7, 0x34($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_27a0:
    // 0x27a0: 0x8fb60030  lw          $s6, 0x30($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_27a4:
    // 0x27a4: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_27a8:
    // 0x27a8: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_27ac:
    // 0x27ac: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_27b0:
    // 0x27b0: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_27b4:
    // 0x27b4: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_27b8:
    // 0x27b8: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_27bc:
    // 0x27bc: 0x71880  sll         $v1, $a3, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
label_27c0:
    // 0x27c0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_27c4:
    // 0x27c4: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_27c8:
    // 0x27c8: 0xac22518c  sw          $v0, 0x518C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20876), GPR_U32(ctx, 2));
label_27cc:
    // 0x27cc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_27d0:
    // 0x27d0: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_27d4:
    // 0x27d4: 0x8c23518c  lw          $v1, 0x518C($at)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20876)));
label_27d8:
    // 0x27d8: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_27dc:
    // 0x27dc: 0xafa30010  sw          $v1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
label_27e0:
    // 0x27e0: 0x3e00008  jr          $ra
label_27e4:
    if (ctx->pc == 0x27E4u) {
        // 0x27e4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x27E8u;
        goto label_27e8;
    }
    ctx->pc = 0x27E0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x27e4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x27E0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x27E8u;
label_27e8:
    // 0x27e8: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_27ec:
    // 0x27ec: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_27f0:
    // 0x27f0: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_27f4:
    // 0x27f4: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_27f8:
    // 0x27f8: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_27fc:
    // 0x27fc: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_2800:
    // 0x2800: 0x8e420000  lw          $v0, 0x0($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_2804:
    // 0x2804: 0x0  nop
    // NOP
label_2808:
    // 0x2808: 0x30430c00  andi        $v1, $v0, 0xC00
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3072);
label_280c:
    // 0x280c: 0x24020400  addiu       $v0, $zero, 0x400
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_2810:
    // 0x2810: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
label_2814:
    if (ctx->pc == 0x2814u) {
        // 0x2814: 0x24020800  addiu       $v0, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        ctx->pc = 0x2818u;
        goto label_2818;
    }
    ctx->pc = 0x2810u;
    {
        const bool branch_taken_0x2810 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x2814: 0x24020800  addiu       $v0, $zero, 0x800 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
        if (branch_taken_0x2810) {
            ctx->pc = 0x2820u;
            goto label_2820;
        }
    }
    ctx->pc = 0x2818u;
label_2818:
    // 0x2818: 0x8000a0b  j           func_00282C
label_281c:
    if (ctx->pc == 0x281Cu) {
        // 0x281c: 0x24090001  addiu       $t1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2820u;
        goto label_2820;
    }
    ctx->pc = 0x2818u;
    // 0x281c: 0x24090001  addiu       $t1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x282Cu;
    goto label_282c;
    ctx->pc = 0x2820u;
label_2820:
    // 0x2820: 0x146200db  bne         $v1, $v0, . + 4 + (0xDB << 2)
label_2824:
    if (ctx->pc == 0x2824u) {
        // 0x2824: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2828u;
        goto label_2828;
    }
    ctx->pc = 0x2820u;
    {
        const bool branch_taken_0x2820 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x2824: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2820) {
            ctx->pc = 0x2B90u;
            goto label_2b90;
        }
    }
    ctx->pc = 0x2828u;
label_2828:
    // 0x2828: 0x4821  addu        $t1, $zero, $zero
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_282c:
    // 0x282c: 0x8c830000  lw          $v1, 0x0($a0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_2830:
    // 0x2830: 0x0  nop
    // NOP
label_2834:
    // 0x2834: 0x307100ff  andi        $s1, $v1, 0xFF
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
label_2838:
    // 0x2838: 0x113240  sll         $a2, $s1, 9
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 17), 9));
label_283c:
    // 0x283c: 0x111100  sll         $v0, $s1, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 4));
label_2840:
    // 0x2840: 0x512821  addu        $a1, $v0, $s1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
label_2844:
    // 0x2844: 0x30640300  andi        $a0, $v1, 0x300
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)768);
label_2848:
    // 0x2848: 0x24020100  addiu       $v0, $zero, 0x100
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
label_284c:
    // 0x284c: 0x14820065  bne         $a0, $v0, . + 4 + (0x65 << 2)
label_2850:
    if (ctx->pc == 0x2850u) {
        // 0x2850: 0x55940  sll         $t3, $a1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 5), 5));
        ctx->pc = 0x2854u;
        goto label_2854;
    }
    ctx->pc = 0x284Cu;
    {
        const bool branch_taken_0x284c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        // 0x2850: 0x55940  sll         $t3, $a1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 5), 5));
        if (branch_taken_0x284c) {
            ctx->pc = 0x29E4u;
            goto label_29e4;
        }
    }
    ctx->pc = 0x2854u;
label_2854:
    // 0x2854: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2858:
    // 0x2858: 0x34630344  ori         $v1, $v1, 0x344
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)836);
label_285c:
    // 0x285c: 0x111280  sll         $v0, $s1, 10
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 10));
label_2860:
    // 0x2860: 0x432021  addu        $a0, $v0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2864:
    // 0x2864: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_2868:
    // 0x2868: 0x0  nop
    // NOP
label_286c:
    // 0x286c: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
label_2870:
    // 0x2870: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
label_2874:
    if (ctx->pc == 0x2874u) {
        // 0x2874: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2878u;
        goto label_2878;
    }
    ctx->pc = 0x2870u;
    {
        const bool branch_taken_0x2870 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2874: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x2870) {
            ctx->pc = 0x28A4u;
            goto label_28a4;
        }
    }
    ctx->pc = 0x2878u;
label_2878:
    // 0x2878: 0x3c050100  lui         $a1, 0x100
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)256 << 16));
label_287c:
    // 0x287c: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_2880:
    // 0x2880: 0xa3102a  slt         $v0, $a1, $v1
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
label_2884:
    // 0x2884: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
label_2888:
    if (ctx->pc == 0x2888u) {
        ctx->pc = 0x288Cu;
        goto label_288c;
    }
    ctx->pc = 0x2884u;
    {
        const bool branch_taken_0x2884 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2884) {
            ctx->pc = 0x28A4u;
            goto label_28a4;
        }
    }
    ctx->pc = 0x288Cu;
label_288c:
    // 0x288c: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_2890:
    // 0x2890: 0x0  nop
    // NOP
label_2894:
    // 0x2894: 0x30420080  andi        $v0, $v0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
label_2898:
    // 0x2898: 0x1040fff9  beqz        $v0, . + 4 + (-0x7 << 2)
label_289c:
    if (ctx->pc == 0x289Cu) {
        // 0x289c: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->pc = 0x28A0u;
        goto label_28a0;
    }
    ctx->pc = 0x2898u;
    {
        const bool branch_taken_0x2898 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x289c: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x2898) {
            ctx->pc = 0x2880u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_2880;
        }
    }
    ctx->pc = 0x28A0u;
label_28a0:
    // 0x28a0: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
label_28a4:
    // 0x28a4: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_28a8:
    // 0x28a8: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_28ac:
    // 0x28ac: 0x61040  sll         $v0, $a2, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
label_28b0:
    // 0x28b0: 0x432021  addu        $a0, $v0, $v1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_28b4:
    // 0x28b4: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_28b8:
    // 0x28b8: 0x0  nop
    // NOP
label_28bc:
    // 0x28bc: 0x3042ffcf  andi        $v0, $v0, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65487);
label_28c0:
    // 0x28c0: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_28c4:
    // 0x28c4: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_28c8:
    // 0x28c8: 0x0  nop
    // NOP
label_28cc:
    // 0x28cc: 0x30420030  andi        $v0, $v0, 0x30
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)48);
label_28d0:
    // 0x28d0: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
label_28d4:
    if (ctx->pc == 0x28D4u) {
        // 0x28d4: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x28D8u;
        goto label_28d8;
    }
    ctx->pc = 0x28D0u;
    {
        const bool branch_taken_0x28d0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x28d4: 0x1821  addu        $v1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x28d0) {
            ctx->pc = 0x2900u;
            goto label_2900;
        }
    }
    ctx->pc = 0x28D8u;
label_28d8:
    // 0x28d8: 0x24630001  addiu       $v1, $v1, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_28dc:
    // 0x28dc: 0x2c620f01  sltiu       $v0, $v1, 0xF01
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)3841) ? 1 : 0);
label_28e0:
    // 0x28e0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
label_28e4:
    if (ctx->pc == 0x28E4u) {
        ctx->pc = 0x28E8u;
        goto label_28e8;
    }
    ctx->pc = 0x28E0u;
    {
        const bool branch_taken_0x28e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x28e0) {
            ctx->pc = 0x2900u;
            goto label_2900;
        }
    }
    ctx->pc = 0x28E8u;
label_28e8:
    // 0x28e8: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_28ec:
    // 0x28ec: 0x0  nop
    // NOP
label_28f0:
    // 0x28f0: 0x30420030  andi        $v0, $v0, 0x30
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)48);
label_28f4:
    // 0x28f4: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
label_28f8:
    if (ctx->pc == 0x28F8u) {
        // 0x28f8: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->pc = 0x28FCu;
        goto label_28fc;
    }
    ctx->pc = 0x28F4u;
    {
        const bool branch_taken_0x28f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x28f8: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x28f4) {
            ctx->pc = 0x28DCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_28dc;
        }
    }
    ctx->pc = 0x28FCu;
label_28fc:
    // 0x28fc: 0x2463ffff  addiu       $v1, $v1, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
label_2900:
    // 0x2900: 0x15200003  bnez        $t1, . + 4 + (0x3 << 2)
label_2904:
    if (ctx->pc == 0x2904u) {
        // 0x2904: 0x118080  sll         $s0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->pc = 0x2908u;
        goto label_2908;
    }
    ctx->pc = 0x2900u;
    {
        const bool branch_taken_0x2900 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        // 0x2904: 0x118080  sll         $s0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        if (branch_taken_0x2900) {
            ctx->pc = 0x2910u;
            goto label_2910;
        }
    }
    ctx->pc = 0x2908u;
label_2908:
    // 0x2908: 0xc0011f2  jal         func_0047C8
label_290c:
    if (ctx->pc == 0x290Cu) {
        ctx->pc = 0x2910u;
        goto label_2910;
    }
    ctx->pc = 0x2908u;
    SET_GPR_U32(ctx, 31, 0x2910u);
    ctx->pc = 0x47C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47C8u, 0x2908u, 0x2910u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2910u;
label_2910:
    // 0x2910: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2914:
    // 0x2914: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_2918:
    // 0x2918: 0x8c425320  lw          $v0, 0x5320($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21280)));
label_291c:
    // 0x291c: 0x0  nop
    // NOP
label_2920:
    // 0x2920: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
label_2924:
    if (ctx->pc == 0x2924u) {
        // 0x2924: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x2928u;
        goto label_2928;
    }
    ctx->pc = 0x2920u;
    {
        const bool branch_taken_0x2920 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2924: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x2920) {
            ctx->pc = 0x2948u;
            goto label_2948;
        }
    }
    ctx->pc = 0x2928u;
label_2928:
    // 0x2928: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_292c:
    // 0x292c: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_2930:
    // 0x2930: 0x8c425320  lw          $v0, 0x5320($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21280)));
label_2934:
    // 0x2934: 0x0  nop
    // NOP
label_2938:
    // 0x2938: 0x40f809  jalr        $v0
label_293c:
    if (ctx->pc == 0x293Cu) {
        // 0x293c: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x2940u;
        goto label_2940;
    }
    ctx->pc = 0x2938u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x2940u);
        // 0x293c: 0x2821  addu        $a1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x2938u, 0x2940u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x2940u;
label_2940:
    // 0x2940: 0x8000ae4  j           func_002B90
label_2944:
    if (ctx->pc == 0x2944u) {
        // 0x2944: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2948u;
        goto label_2948;
    }
    ctx->pc = 0x2940u;
    // 0x2944: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2B90u;
    goto label_2b90;
    ctx->pc = 0x2948u;
label_2948:
    // 0x2948: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_294c:
    // 0x294c: 0x902021  addu        $a0, $a0, $s0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
label_2950:
    // 0x2950: 0x8c845300  lw          $a0, 0x5300($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 21248)));
label_2954:
    // 0x2954: 0xc001217  jal         func_00485C
label_2958:
    if (ctx->pc == 0x2958u) {
        // 0x2958: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x295Cu;
        goto label_295c;
    }
    ctx->pc = 0x2954u;
    SET_GPR_U32(ctx, 31, 0x295Cu);
    // 0x2958: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x485Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x485Cu, 0x2954u, 0x295Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x295Cu;
label_295c:
    // 0x295c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2960:
    // 0x2960: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_2964:
    // 0x2964: 0x8c425318  lw          $v0, 0x5318($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21272)));
label_2968:
    // 0x2968: 0x0  nop
    // NOP
label_296c:
    // 0x296c: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
label_2970:
    if (ctx->pc == 0x2970u) {
        // 0x2970: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2974u;
        goto label_2974;
    }
    ctx->pc = 0x296Cu;
    {
        const bool branch_taken_0x296c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2970: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x296c) {
            ctx->pc = 0x2998u;
            goto label_2998;
        }
    }
    ctx->pc = 0x2974u;
label_2974:
    // 0x2974: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2978:
    // 0x2978: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_297c:
    // 0x297c: 0xac22518c  sw          $v0, 0x518C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20876), GPR_U32(ctx, 2));
label_2980:
    // 0x2980: 0x8e450004  lw          $a1, 0x4($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_2984:
    // 0x2984: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2988:
    // 0x2988: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_298c:
    // 0x298c: 0x8c425318  lw          $v0, 0x5318($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21272)));
label_2990:
    // 0x2990: 0x8000ad3  j           func_002B4C
label_2994:
    if (ctx->pc == 0x2994u) {
        ctx->pc = 0x2998u;
        goto label_2998;
    }
    ctx->pc = 0x2990u;
    ctx->pc = 0x2B4Cu;
    goto label_2b4c;
    ctx->pc = 0x2998u;
label_2998:
    // 0x2998: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_299c:
    // 0x299c: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_29a0:
    // 0x29a0: 0x8c4259a0  lw          $v0, 0x59A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22944)));
label_29a4:
    // 0x29a4: 0x0  nop
    // NOP
label_29a8:
    // 0x29a8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
label_29ac:
    if (ctx->pc == 0x29ACu) {
        // 0x29ac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x29B0u;
        goto label_29b0;
    }
    ctx->pc = 0x29A8u;
    {
        const bool branch_taken_0x29a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x29ac: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x29a8) {
            ctx->pc = 0x29D0u;
            goto label_29d0;
        }
    }
    ctx->pc = 0x29B0u;
label_29b0:
    // 0x29b0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_29b4:
    // 0x29b4: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_29b8:
    // 0x29b8: 0xac22518c  sw          $v0, 0x518C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 20876), GPR_U32(ctx, 2));
label_29bc:
    // 0x29bc: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_29c0:
    // 0x29c0: 0x501021  addu        $v0, $v0, $s0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_29c4:
    // 0x29c4: 0x8c4259a0  lw          $v0, 0x59A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22944)));
label_29c8:
    // 0x29c8: 0x8000ae1  j           func_002B84
label_29cc:
    if (ctx->pc == 0x29CCu) {
        ctx->pc = 0x29D0u;
        goto label_29d0;
    }
    ctx->pc = 0x29C8u;
    ctx->pc = 0x2B84u;
    goto label_2b84;
    ctx->pc = 0x29D0u;
label_29d0:
    // 0x29d0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_29d4:
    // 0x29d4: 0x300821  addu        $at, $at, $s0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 16)));
label_29d8:
    // 0x29d8: 0xac2252f8  sw          $v0, 0x52F8($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21240), GPR_U32(ctx, 2));
label_29dc:
    // 0x29dc: 0x8000ae4  j           func_002B90
label_29e0:
    if (ctx->pc == 0x29E0u) {
        // 0x29e0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x29E4u;
        goto label_29e4;
    }
    ctx->pc = 0x29DCu;
    // 0x29e0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2B90u;
    goto label_2b90;
    ctx->pc = 0x29E4u;
label_29e4:
    // 0x29e4: 0x24020200  addiu       $v0, $zero, 0x200
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
label_29e8:
    // 0x29e8: 0x14820069  bne         $a0, $v0, . + 4 + (0x69 << 2)
label_29ec:
    if (ctx->pc == 0x29ECu) {
        // 0x29ec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x29F0u;
        goto label_29f0;
    }
    ctx->pc = 0x29E8u;
    {
        const bool branch_taken_0x29e8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        // 0x29ec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x29e8) {
            ctx->pc = 0x2B90u;
            goto label_2b90;
        }
    }
    ctx->pc = 0x29F0u;
label_29f0:
    // 0x29f0: 0x30621000  andi        $v0, $v1, 0x1000
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)4096);
label_29f4:
    // 0x29f4: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
label_29f8:
    if (ctx->pc == 0x29F8u) {
        // 0x29f8: 0x113080  sll         $a2, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->pc = 0x29FCu;
        goto label_29fc;
    }
    ctx->pc = 0x29F4u;
    {
        const bool branch_taken_0x29f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x29f8: 0x113080  sll         $a2, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        if (branch_taken_0x29f4) {
            ctx->pc = 0x2A34u;
            goto label_2a34;
        }
    }
    ctx->pc = 0x29FCu;
label_29fc:
    // 0x29fc: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_2a00:
    // 0x2a00: 0x3484019a  ori         $a0, $a0, 0x19A
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)410);
label_2a04:
    // 0x2a04: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_2a08:
    // 0x2a08: 0x111a80  sll         $v1, $s1, 10
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 10));
label_2a0c:
    // 0x2a0c: 0x642021  addu        $a0, $v1, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_2a10:
    // 0x2a10: 0x34a501b0  ori         $a1, $a1, 0x1B0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)432);
label_2a14:
    // 0x2a14: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_2a18:
    // 0x2a18: 0x651821  addu        $v1, $v1, $a1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_2a1c:
    // 0x2a1c: 0x3042ffcf  andi        $v0, $v0, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65487);
label_2a20:
    // 0x2a20: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_2a24:
    // 0x2a24: 0xa4600000  sh          $zero, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 0));
label_2a28:
    // 0x2a28: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_2a2c:
    // 0x2a2c: 0x8000ac2  j           func_002B08
label_2a30:
    if (ctx->pc == 0x2A30u) {
        // 0x2a30: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x2A34u;
        goto label_2a34;
    }
    ctx->pc = 0x2A2Cu;
    // 0x2a30: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x2B08u;
    goto label_2b08;
    ctx->pc = 0x2A34u;
label_2a34:
    // 0x2a34: 0x24040001  addiu       $a0, $zero, 0x1
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2a38:
    // 0x2a38: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2a3c:
    // 0x2a3c: 0x461021  addu        $v0, $v0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_2a40:
    // 0x2a40: 0x8c425970  lw          $v0, 0x5970($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22896)));
label_2a44:
    // 0x2a44: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_2a48:
    // 0x2a48: 0x661821  addu        $v1, $v1, $a2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
label_2a4c:
    // 0x2a4c: 0x8c635980  lw          $v1, 0x5980($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 22912)));
label_2a50:
    // 0x2a50: 0x823823  subu        $a3, $a0, $v0
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_2a54:
    // 0x2a54: 0xe30018  mult        $zero, $a3, $v1
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
label_2a58:
    // 0x2a58: 0x3c03bf80  lui         $v1, 0xBF80
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49024 << 16));
label_2a5c:
    // 0x2a5c: 0x346310c6  ori         $v1, $v1, 0x10C6
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4294);
label_2a60:
    // 0x2a60: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2a64:
    // 0x2a64: 0x461021  addu        $v0, $v0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_2a68:
    // 0x2a68: 0x8c425978  lw          $v0, 0x5978($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22904)));
label_2a6c:
    // 0x2a6c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_2a70:
    // 0x2a70: 0x862021  addu        $a0, $a0, $a2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
label_2a74:
    // 0x2a74: 0x8c845980  lw          $a0, 0x5980($a0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 22912)));
label_2a78:
    // 0x2a78: 0x6012  mflo        $t4
    SET_GPR_U64(ctx, 12, ctx->lo);
label_2a7c:
    // 0x2a7c: 0x4c5021  addu        $t2, $v0, $t4
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
label_2a80:
    // 0x2a80: 0x51180  sll         $v0, $a1, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
label_2a84:
    // 0x2a84: 0x4810002  bgez        $a0, . + 4 + (0x2 << 2)
label_2a88:
    if (ctx->pc == 0x2A88u) {
        // 0x2a88: 0x434021  addu        $t0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->pc = 0x2A8Cu;
        goto label_2a8c;
    }
    ctx->pc = 0x2A84u;
    {
        const bool branch_taken_0x2a84 = (GPR_S32(ctx, 4) >= 0);
        // 0x2a88: 0x434021  addu        $t0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        if (branch_taken_0x2a84) {
            ctx->pc = 0x2A90u;
            goto label_2a90;
        }
    }
    ctx->pc = 0x2A8Cu;
label_2a8c:
    // 0x2a8c: 0x2484003f  addiu       $a0, $a0, 0x3F
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 63));
label_2a90:
    // 0x2a90: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_2a94:
    // 0x2a94: 0x661821  addu        $v1, $v1, $a2
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
label_2a98:
    // 0x2a98: 0x8c635980  lw          $v1, 0x5980($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 22912)));
label_2a9c:
    // 0x2a9c: 0x42183  sra         $a0, $a0, 6
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 6));
label_2aa0:
    // 0x2aa0: 0x4610002  bgez        $v1, . + 4 + (0x2 << 2)
label_2aa4:
    if (ctx->pc == 0x2AA4u) {
        // 0x2aa4: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        ctx->pc = 0x2AA8u;
        goto label_2aa8;
    }
    ctx->pc = 0x2AA0u;
    {
        const bool branch_taken_0x2aa0 = (GPR_S32(ctx, 3) >= 0);
        // 0x2aa4: 0x601021  addu        $v0, $v1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
        if (branch_taken_0x2aa0) {
            ctx->pc = 0x2AACu;
            goto label_2aac;
        }
    }
    ctx->pc = 0x2AA8u;
label_2aa8:
    // 0x2aa8: 0x2462003f  addiu       $v0, $v1, 0x3F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
label_2aac:
    // 0x2aac: 0x21183  sra         $v0, $v0, 6
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 6));
label_2ab0:
    // 0x2ab0: 0x21180  sll         $v0, $v0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
label_2ab4:
    // 0x2ab4: 0x621023  subu        $v0, $v1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_2ab8:
    // 0x2ab8: 0x2102a  slt         $v0, $zero, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
label_2abc:
    // 0x2abc: 0x821021  addu        $v0, $a0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_2ac0:
    // 0x2ac0: 0x3c04bf80  lui         $a0, 0xBF80
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49024 << 16));
label_2ac4:
    // 0x2ac4: 0x348410c0  ori         $a0, $a0, 0x10C0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4288);
label_2ac8:
    // 0x2ac8: 0x3c05bf80  lui         $a1, 0xBF80
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49024 << 16));
label_2acc:
    // 0x2acc: 0x34a510c8  ori         $a1, $a1, 0x10C8
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4296);
label_2ad0:
    // 0x2ad0: 0x3c030100  lui         $v1, 0x100
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
label_2ad4:
    // 0x2ad4: 0x34630200  ori         $v1, $v1, 0x200
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)512);
label_2ad8:
    // 0x2ad8: 0xa5020000  sh          $v0, 0x0($t0)
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
label_2adc:
    // 0x2adc: 0xb1040  sll         $v0, $t3, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 11), 1));
label_2ae0:
    // 0x2ae0: 0x442021  addu        $a0, $v0, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_2ae4:
    // 0x2ae4: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_2ae8:
    // 0x2ae8: 0x1231825  or          $v1, $t1, $v1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) | GPR_U64(ctx, 3));
label_2aec:
    // 0x2aec: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2af0:
    // 0x2af0: 0x260821  addu        $at, $at, $a2
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 6)));
label_2af4:
    // 0x2af4: 0xac275970  sw          $a3, 0x5970($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22896), GPR_U32(ctx, 7));
label_2af8:
    // 0x2af8: 0xac8a0000  sw          $t2, 0x0($a0)
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 10));
label_2afc:
    // 0x2afc: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_2b00:
    // 0x2b00: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_2b04:
    // 0x2b04: 0x0  nop
    // NOP
label_2b08:
    // 0x2b08: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_2b0c:
    // 0x2b0c: 0x15200004  bnez        $t1, . + 4 + (0x4 << 2)
label_2b10:
    if (ctx->pc == 0x2B10u) {
        // 0x2b10: 0x111880  sll         $v1, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->pc = 0x2B14u;
        goto label_2b14;
    }
    ctx->pc = 0x2B0Cu;
    {
        const bool branch_taken_0x2b0c = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        // 0x2b10: 0x111880  sll         $v1, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        if (branch_taken_0x2b0c) {
            ctx->pc = 0x2B20u;
            goto label_2b20;
        }
    }
    ctx->pc = 0x2B14u;
label_2b14:
    // 0x2b14: 0xc0011f2  jal         func_0047C8
label_2b18:
    if (ctx->pc == 0x2B18u) {
        ctx->pc = 0x2B1Cu;
        goto label_2b1c;
    }
    ctx->pc = 0x2B14u;
    SET_GPR_U32(ctx, 31, 0x2B1Cu);
    ctx->pc = 0x47C8u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47C8u, 0x2B14u, 0x2B1Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2B1Cu;
label_2b1c:
    // 0x2b1c: 0x111880  sll         $v1, $s1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
label_2b20:
    // 0x2b20: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2b24:
    // 0x2b24: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2b28:
    // 0x2b28: 0x8c425318  lw          $v0, 0x5318($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21272)));
label_2b2c:
    // 0x2b2c: 0x0  nop
    // NOP
label_2b30:
    // 0x2b30: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
label_2b34:
    if (ctx->pc == 0x2B34u) {
        ctx->pc = 0x2B38u;
        goto label_2b38;
    }
    ctx->pc = 0x2B30u;
    {
        const bool branch_taken_0x2b30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x2b30) {
            ctx->pc = 0x2B5Cu;
            goto label_2b5c;
        }
    }
    ctx->pc = 0x2B38u;
label_2b38:
    // 0x2b38: 0x8e450004  lw          $a1, 0x4($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_2b3c:
    // 0x2b3c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2b40:
    // 0x2b40: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2b44:
    // 0x2b44: 0x8c425318  lw          $v0, 0x5318($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21272)));
label_2b48:
    // 0x2b48: 0x0  nop
    // NOP
label_2b4c:
    // 0x2b4c: 0x40f809  jalr        $v0
label_2b50:
    if (ctx->pc == 0x2B50u) {
        // 0x2b50: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x2B54u;
        goto label_2b54;
    }
    ctx->pc = 0x2B4Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x2B54u);
        // 0x2b50: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x2B4Cu, 0x2B54u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x2B54u;
label_2b54:
    // 0x2b54: 0x8000ae4  j           func_002B90
label_2b58:
    if (ctx->pc == 0x2B58u) {
        // 0x2b58: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2B5Cu;
        goto label_2b5c;
    }
    ctx->pc = 0x2B54u;
    // 0x2b58: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2B90u;
    goto label_2b90;
    ctx->pc = 0x2B5Cu;
label_2b5c:
    // 0x2b5c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2b60:
    // 0x2b60: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2b64:
    // 0x2b64: 0x8c4259a0  lw          $v0, 0x59A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22944)));
label_2b68:
    // 0x2b68: 0x0  nop
    // NOP
label_2b6c:
    // 0x2b6c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_2b70:
    if (ctx->pc == 0x2B70u) {
        // 0x2b70: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x2B74u;
        goto label_2b74;
    }
    ctx->pc = 0x2B6Cu;
    {
        const bool branch_taken_0x2b6c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2b70: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x2b6c) {
            ctx->pc = 0x2B90u;
            goto label_2b90;
        }
    }
    ctx->pc = 0x2B74u;
label_2b74:
    // 0x2b74: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2b78:
    // 0x2b78: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_2b7c:
    // 0x2b7c: 0x8c4259a0  lw          $v0, 0x59A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22944)));
label_2b80:
    // 0x2b80: 0x0  nop
    // NOP
label_2b84:
    // 0x2b84: 0x40f809  jalr        $v0
label_2b88:
    if (ctx->pc == 0x2B88u) {
        ctx->pc = 0x2B8Cu;
        goto label_2b8c;
    }
    ctx->pc = 0x2B84u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x2B8Cu);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x2B84u, 0x2B8Cu, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x2B8Cu;
label_2b8c:
    // 0x2b8c: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2b90:
    // 0x2b90: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_2b94:
    // 0x2b94: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_2b98:
    // 0x2b98: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_2b9c:
    // 0x2b9c: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_2ba0:
    // 0x2ba0: 0x3e00008  jr          $ra
label_2ba4:
    if (ctx->pc == 0x2BA4u) {
        // 0x2ba4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0x2BA8u;
        goto label_2ba8;
    }
    ctx->pc = 0x2BA0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2ba4: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2BA0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2BA8u;
label_2ba8:
    // 0x2ba8: 0x3c05bf80  lui         $a1, 0xBF80
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49024 << 16));
label_2bac:
    // 0x2bac: 0x34a510c0  ori         $a1, $a1, 0x10C0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4288);
label_2bb0:
    // 0x2bb0: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_2bb4:
    // 0x2bb4: 0x41100  sll         $v0, $a0, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
label_2bb8:
    // 0x2bb8: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_2bbc:
    // 0x2bbc: 0x21180  sll         $v0, $v0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
label_2bc0:
    // 0x2bc0: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_2bc4:
    // 0x2bc4: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_2bc8:
    // 0x2bc8: 0xa32821  addu        $a1, $a1, $v1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_2bcc:
    // 0x2bcc: 0x8ca55970  lw          $a1, 0x5970($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 22896)));
label_2bd0:
    // 0x2bd0: 0x8c470000  lw          $a3, 0x0($v0)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_2bd4:
    // 0x2bd4: 0x3c080000  lui         $t0, 0x0
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)0 << 16));
label_2bd8:
    // 0x2bd8: 0x1034021  addu        $t0, $t0, $v1
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
label_2bdc:
    // 0x2bdc: 0x8d085970  lw          $t0, 0x5970($t0)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 22896)));
label_2be0:
    // 0x2be0: 0x41a40  sll         $v1, $a0, 9
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 9));
label_2be4:
    // 0x2be4: 0x8c460000  lw          $a2, 0x0($v0)
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_2be8:
    // 0x2be8: 0x14a80005  bne         $a1, $t0, . + 4 + (0x5 << 2)
label_2bec:
    if (ctx->pc == 0x2BECu) {
        // 0x2bec: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x2BF0u;
        goto label_2bf0;
    }
    ctx->pc = 0x2BE8u;
    {
        const bool branch_taken_0x2be8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 8));
        // 0x2bec: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x2be8) {
            ctx->pc = 0x2C00u;
            goto label_2c00;
        }
    }
    ctx->pc = 0x2BF0u;
label_2bf0:
    // 0x2bf0: 0x10e60004  beq         $a3, $a2, . + 4 + (0x4 << 2)
label_2bf4:
    if (ctx->pc == 0x2BF4u) {
        // 0x2bf4: 0x344201b0  ori         $v0, $v0, 0x1B0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)432);
        ctx->pc = 0x2BF8u;
        goto label_2bf8;
    }
    ctx->pc = 0x2BF0u;
    {
        const bool branch_taken_0x2bf0 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 6));
        // 0x2bf4: 0x344201b0  ori         $v0, $v0, 0x1B0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)432);
        if (branch_taken_0x2bf0) {
            ctx->pc = 0x2C04u;
            goto label_2c04;
        }
    }
    ctx->pc = 0x2BF8u;
label_2bf8:
    // 0x2bf8: 0xe03021  addu        $a2, $a3, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_2bfc:
    // 0x2bfc: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_2c00:
    // 0x2c00: 0x344201b0  ori         $v0, $v0, 0x1B0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)432);
label_2c04:
    // 0x2c04: 0x31840  sll         $v1, $v1, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
label_2c08:
    // 0x2c08: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_2c0c:
    // 0x2c0c: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_2c10:
    // 0x2c10: 0x0  nop
    // NOP
label_2c14:
    // 0x2c14: 0x30420007  andi        $v0, $v0, 0x7
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
label_2c18:
    // 0x2c18: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
label_2c1c:
    if (ctx->pc == 0x2C1Cu) {
        ctx->pc = 0x2C20u;
        goto label_2c20;
    }
    ctx->pc = 0x2C18u;
    {
        const bool branch_taken_0x2c18 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2c18) {
            ctx->pc = 0x2C24u;
            goto label_2c24;
        }
    }
    ctx->pc = 0x2C20u;
label_2c20:
    // 0x2c20: 0x3021  addu        $a2, $zero, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_2c24:
    // 0x2c24: 0x3c0200ff  lui         $v0, 0xFF
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
label_2c28:
    // 0x2c28: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
label_2c2c:
    // 0x2c2c: 0x81e00  sll         $v1, $t0, 24
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 24));
label_2c30:
    // 0x2c30: 0xc21024  and         $v0, $a2, $v0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
label_2c34:
    // 0x2c34: 0x3e00008  jr          $ra
label_2c38:
    if (ctx->pc == 0x2C38u) {
        // 0x2c38: 0x621025  or          $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->pc = 0x2C3Cu;
        goto label_2c3c;
    }
    ctx->pc = 0x2C34u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2c38: 0x621025  or          $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2C34u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2C3Cu;
label_2c3c:
    // 0x2c3c: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
label_2c40:
    // 0x2c40: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_2c44:
    // 0x2c44: 0xa0a021  addu        $s4, $a1, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_2c48:
    // 0x2c48: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_2c4c:
    // 0x2c4c: 0x30d20001  andi        $s2, $a2, 0x1
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)1);
label_2c50:
    // 0x2c50: 0x122880  sll         $a1, $s2, 2
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
label_2c54:
    // 0x2c54: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_2c58:
    // 0x2c58: 0x128240  sll         $s0, $s2, 9
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 18), 9));
label_2c5c:
    // 0x2c5c: 0x121100  sll         $v0, $s2, 4
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 4));
label_2c60:
    // 0x2c60: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_2c64:
    // 0x2c64: 0x8fb30048  lw          $s3, 0x48($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
label_2c68:
    // 0x2c68: 0x521021  addu        $v0, $v0, $s2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_2c6c:
    // 0x2c6c: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
label_2c70:
    // 0x2c70: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
label_2c74:
    // 0x2c74: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_2c78:
    // 0x2c78: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2c7c:
    // 0x2c7c: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
label_2c80:
    // 0x2c80: 0xac245978  sw          $a0, 0x5978($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22904), GPR_U32(ctx, 4));
label_2c84:
    // 0x2c84: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2c88:
    // 0x2c88: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
label_2c8c:
    // 0x2c8c: 0xac205970  sw          $zero, 0x5970($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22896), GPR_U32(ctx, 0));
label_2c90:
    // 0x2c90: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2c94:
    // 0x2c94: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
label_2c98:
    // 0x2c98: 0xac345980  sw          $s4, 0x5980($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22912), GPR_U32(ctx, 20));
label_2c9c:
    // 0x2c9c: 0x16600004  bnez        $s3, . + 4 + (0x4 << 2)
label_2ca0:
    if (ctx->pc == 0x2CA0u) {
        // 0x2ca0: 0x2a940  sll         $s5, $v0, 5 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
        ctx->pc = 0x2CA4u;
        goto label_2ca4;
    }
    ctx->pc = 0x2C9Cu;
    {
        const bool branch_taken_0x2c9c = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        // 0x2ca0: 0x2a940  sll         $s5, $v0, 5 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
        if (branch_taken_0x2c9c) {
            ctx->pc = 0x2CB0u;
            goto label_2cb0;
        }
    }
    ctx->pc = 0x2CA4u;
label_2ca4:
    // 0x2ca4: 0x809821  addu        $s3, $a0, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_2ca8:
    // 0x2ca8: 0x8000b54  j           func_002D50
label_2cac:
    if (ctx->pc == 0x2CACu) {
        // 0x2cac: 0x2808821  addu        $s1, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0x2CB0u;
        goto label_2cb0;
    }
    ctx->pc = 0x2CA8u;
    // 0x2cac: 0x2808821  addu        $s1, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x2D50u;
    goto label_2d50;
    ctx->pc = 0x2CB0u;
label_2cb0:
    // 0x2cb0: 0x2641823  subu        $v1, $s3, $a0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
label_2cb4:
    // 0x2cb4: 0x74102b  sltu        $v0, $v1, $s4
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 20)) ? 1 : 0);
label_2cb8:
    // 0x2cb8: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
label_2cbc:
    if (ctx->pc == 0x2CBCu) {
        // 0x2cbc: 0x2838823  subu        $s1, $s4, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
        ctx->pc = 0x2CC0u;
        goto label_2cc0;
    }
    ctx->pc = 0x2CB8u;
    {
        const bool branch_taken_0x2cb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x2cbc: 0x2838823  subu        $s1, $s4, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
        if (branch_taken_0x2cb8) {
            ctx->pc = 0x2D04u;
            goto label_2d04;
        }
    }
    ctx->pc = 0x2CC0u;
label_2cc0:
    // 0x2cc0: 0x30e20010  andi        $v0, $a3, 0x10
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)16);
label_2cc4:
    // 0x2cc4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_2cc8:
    if (ctx->pc == 0x2CC8u) {
        // 0x2cc8: 0x741823  subu        $v1, $v1, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
        ctx->pc = 0x2CCCu;
        goto label_2ccc;
    }
    ctx->pc = 0x2CC4u;
    {
        const bool branch_taken_0x2cc4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x2cc8: 0x741823  subu        $v1, $v1, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
        if (branch_taken_0x2cc4) {
            ctx->pc = 0x2CD8u;
            goto label_2cd8;
        }
    }
    ctx->pc = 0x2CCCu;
label_2ccc:
    // 0x2ccc: 0x74102b  sltu        $v0, $v1, $s4
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 20)) ? 1 : 0);
label_2cd0:
    // 0x2cd0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_2cd4:
    if (ctx->pc == 0x2CD4u) {
        ctx->pc = 0x2CD8u;
        goto label_2cd8;
    }
    ctx->pc = 0x2CD0u;
    {
        const bool branch_taken_0x2cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x2cd0) {
            ctx->pc = 0x2CE0u;
            goto label_2ce0;
        }
    }
    ctx->pc = 0x2CD8u;
label_2cd8:
    // 0x2cd8: 0x8000b90  j           func_002E40
label_2cdc:
    if (ctx->pc == 0x2CDCu) {
        // 0x2cdc: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x2CE0u;
        goto label_2ce0;
    }
    ctx->pc = 0x2CD8u;
    // 0x2cdc: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
    ctx->pc = 0x2E40u;
    goto label_2e40;
    ctx->pc = 0x2CE0u;
label_2ce0:
    // 0x2ce0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_2ce4:
    // 0x2ce4: 0x451021  addu        $v0, $v0, $a1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_2ce8:
    // 0x2ce8: 0x8c425970  lw          $v0, 0x5970($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22896)));
label_2cec:
    // 0x2cec: 0x0  nop
    // NOP
label_2cf0:
    // 0x2cf0: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_2cf4:
    // 0x2cf4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2cf8:
    // 0x2cf8: 0x250821  addu        $at, $at, $a1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 5)));
label_2cfc:
    // 0x2cfc: 0xac225970  sw          $v0, 0x5970($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22896), GPR_U32(ctx, 2));
label_2d00:
    // 0x2d00: 0x2838823  subu        $s1, $s4, $v1
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
label_2d04:
    // 0x2d04: 0x6210002  bgez        $s1, . + 4 + (0x2 << 2)
label_2d08:
    if (ctx->pc == 0x2D08u) {
        // 0x2d08: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x2D0Cu;
        goto label_2d0c;
    }
    ctx->pc = 0x2D04u;
    {
        const bool branch_taken_0x2d04 = (GPR_S32(ctx, 17) >= 0);
        // 0x2d08: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x2d04) {
            ctx->pc = 0x2D10u;
            goto label_2d10;
        }
    }
    ctx->pc = 0x2D0Cu;
label_2d0c:
    // 0x2d0c: 0x262203ff  addiu       $v0, $s1, 0x3FF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 1023));
label_2d10:
    // 0x2d10: 0x21a83  sra         $v1, $v0, 10
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 2), 10));
label_2d14:
    // 0x2d14: 0x31280  sll         $v0, $v1, 10
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 10));
label_2d18:
    // 0x2d18: 0x2221023  subu        $v0, $s1, $v0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_2d1c:
    // 0x2d1c: 0x1840000c  blez        $v0, . + 4 + (0xC << 2)
label_2d20:
    if (ctx->pc == 0x2D20u) {
        // 0x2d20: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        ctx->pc = 0x2D24u;
        goto label_2d24;
    }
    ctx->pc = 0x2D1Cu;
    {
        const bool branch_taken_0x2d1c = (GPR_S32(ctx, 2) <= 0);
        // 0x2d20: 0x121080  sll         $v0, $s2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x2d1c) {
            ctx->pc = 0x2D50u;
            goto label_2d50;
        }
    }
    ctx->pc = 0x2D24u;
label_2d24:
    // 0x2d24: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2d28:
    // 0x2d28: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_2d2c:
    // 0x2d2c: 0x8c225970  lw          $v0, 0x5970($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 22896)));
label_2d30:
    // 0x2d30: 0x0  nop
    // NOP
label_2d34:
    // 0x2d34: 0x540018  mult        $zero, $v0, $s4
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
label_2d38:
    // 0x2d38: 0x24620001  addiu       $v0, $v1, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_2d3c:
    // 0x2d3c: 0x28a80  sll         $s1, $v0, 10
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
label_2d40:
    // 0x2d40: 0x2911023  subu        $v0, $s4, $s1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 20), GPR_U32(ctx, 17)));
label_2d44:
    // 0x2d44: 0x4012  mflo        $t0
    SET_GPR_U64(ctx, 8, ctx->lo);
label_2d48:
    // 0x2d48: 0x1021021  addu        $v0, $t0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
label_2d4c:
    // 0x2d4c: 0x829821  addu        $s3, $a0, $v0
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_2d50:
    // 0x2d50: 0xc0011e5  jal         func_004794
label_2d54:
    if (ctx->pc == 0x2D54u) {
        // 0x2d54: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
        ctx->pc = 0x2D58u;
        goto label_2d58;
    }
    ctx->pc = 0x2D50u;
    SET_GPR_U32(ctx, 31, 0x2D58u);
    // 0x2d54: 0x27a40014  addiu       $a0, $sp, 0x14 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x2D50u, 0x2D58u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D58u;
label_2d58:
    // 0x2d58: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2d5c:
    // 0x2d5c: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_2d60:
    // 0x2d60: 0x108040  sll         $s0, $s0, 1
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
label_2d64:
    // 0x2d64: 0x2031821  addu        $v1, $s0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_2d68:
    // 0x2d68: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_2d6c:
    // 0x2d6c: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_2d70:
    // 0x2d70: 0x3042ffcf  andi        $v0, $v0, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65487);
label_2d74:
    // 0x2d74: 0xc0011e7  jal         func_00479C
label_2d78:
    if (ctx->pc == 0x2D78u) {
        // 0x2d78: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x2D7Cu;
        goto label_2d7c;
    }
    ctx->pc = 0x2D74u;
    SET_GPR_U32(ctx, 31, 0x2D7Cu);
    // 0x2d78: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x2D74u, 0x2D7Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2D7Cu;
label_2d7c:
    // 0x2d7c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_2d80:
    // 0x2d80: 0x344201a8  ori         $v0, $v0, 0x1A8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)424);
label_2d84:
    // 0x2d84: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2d88:
    // 0x2d88: 0x346301aa  ori         $v1, $v1, 0x1AA
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)426);
label_2d8c:
    // 0x2d8c: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_2d90:
    // 0x2d90: 0x34a501b0  ori         $a1, $a1, 0x1B0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)432);
label_2d94:
    // 0x2d94: 0x2402021  addu        $a0, $s2, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_2d98:
    // 0x2d98: 0x2021021  addu        $v0, $s0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
label_2d9c:
    // 0x2d9c: 0x2031821  addu        $v1, $s0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_2da0:
    // 0x2da0: 0x2058021  addu        $s0, $s0, $a1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
label_2da4:
    // 0x2da4: 0xa4400000  sh          $zero, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
label_2da8:
    // 0x2da8: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_2dac:
    // 0x2dac: 0x821004  sllv        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 4) & 0x1F));
label_2db0:
    // 0x2db0: 0xa4600000  sh          $zero, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 0));
label_2db4:
    // 0x2db4: 0xc000827  jal         func_00209C
label_2db8:
    if (ctx->pc == 0x2DB8u) {
        // 0x2db8: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x2DBCu;
        goto label_2dbc;
    }
    ctx->pc = 0x2DB4u;
    SET_GPR_U32(ctx, 31, 0x2DBCu);
    // 0x2db8: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x209Cu;
    goto label_209c;
    ctx->pc = 0x2DBCu;
label_2dbc:
    // 0x2dbc: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
label_2dc0:
    // 0x2dc0: 0x344210c0  ori         $v0, $v0, 0x10C0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4288);
label_2dc4:
    // 0x2dc4: 0x3c04bf80  lui         $a0, 0xBF80
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49024 << 16));
label_2dc8:
    // 0x2dc8: 0x348410c4  ori         $a0, $a0, 0x10C4
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4292);
label_2dcc:
    // 0x2dcc: 0x3c05bf80  lui         $a1, 0xBF80
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49024 << 16));
label_2dd0:
    // 0x2dd0: 0x34a510c6  ori         $a1, $a1, 0x10C6
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4294);
label_2dd4:
    // 0x2dd4: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_2dd8:
    // 0x2dd8: 0x153840  sll         $a3, $s5, 1
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 21), 1));
label_2ddc:
    // 0x2ddc: 0xe21021  addu        $v0, $a3, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
label_2de0:
    // 0x2de0: 0xe01821  addu        $v1, $a3, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_2de4:
    // 0x2de4: 0x642021  addu        $a0, $v1, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_2de8:
    // 0x2de8: 0xac530000  sw          $s3, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 19));
label_2dec:
    // 0x2dec: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_2df0:
    // 0x2df0: 0x652821  addu        $a1, $v1, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_2df4:
    // 0x2df4: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_2df8:
    // 0x2df8: 0x6210003  bgez        $s1, . + 4 + (0x3 << 2)
label_2dfc:
    if (ctx->pc == 0x2DFCu) {
        // 0x2dfc: 0x61983  sra         $v1, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), 6));
        ctx->pc = 0x2E00u;
        goto label_2e00;
    }
    ctx->pc = 0x2DF8u;
    {
        const bool branch_taken_0x2df8 = (GPR_S32(ctx, 17) >= 0);
        // 0x2dfc: 0x61983  sra         $v1, $a2, 6 (Delay Slot)
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), 6));
        if (branch_taken_0x2df8) {
            ctx->pc = 0x2E08u;
            goto label_2e08;
        }
    }
    ctx->pc = 0x2E00u;
label_2e00:
    // 0x2e00: 0x2626003f  addiu       $a2, $s1, 0x3F
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 63));
label_2e04:
    // 0x2e04: 0x61983  sra         $v1, $a2, 6
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), 6));
label_2e08:
    // 0x2e08: 0x31180  sll         $v0, $v1, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 6));
label_2e0c:
    // 0x2e0c: 0x2222023  subu        $a0, $s1, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_2e10:
    // 0x2e10: 0x4102a  slt         $v0, $zero, $a0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
label_2e14:
    // 0x2e14: 0x622021  addu        $a0, $v1, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_2e18:
    // 0x2e18: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
label_2e1c:
    // 0x2e1c: 0x344210c8  ori         $v0, $v0, 0x10C8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4296);
label_2e20:
    // 0x2e20: 0x3c030100  lui         $v1, 0x100
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
label_2e24:
    // 0x2e24: 0x34630201  ori         $v1, $v1, 0x201
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)513);
label_2e28:
    // 0x2e28: 0xe21021  addu        $v0, $a3, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
label_2e2c:
    // 0x2e2c: 0xa4a40000  sh          $a0, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 4));
label_2e30:
    // 0x2e30: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_2e34:
    // 0x2e34: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_2e38:
    // 0x2e38: 0x2801021  addu        $v0, $s4, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
label_2e3c:
    // 0x2e3c: 0xafa30010  sw          $v1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
label_2e40:
    // 0x2e40: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_2e44:
    // 0x2e44: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_2e48:
    // 0x2e48: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_2e4c:
    // 0x2e4c: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_2e50:
    // 0x2e50: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_2e54:
    // 0x2e54: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_2e58:
    // 0x2e58: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_2e5c:
    // 0x2e5c: 0x3e00008  jr          $ra
label_2e60:
    if (ctx->pc == 0x2E60u) {
        // 0x2e60: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = 0x2E64u;
        goto label_2e64;
    }
    ctx->pc = 0x2E5Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x2e60: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x2E5Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x2E64u;
label_2e64:
    // 0x2e64: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
label_2e68:
    // 0x2e68: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_2e6c:
    // 0x2e6c: 0x80a021  addu        $s4, $a0, $zero
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_2e70:
    // 0x2e70: 0xafb60030  sw          $s6, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 22));
label_2e74:
    // 0x2e74: 0xa0b021  addu        $s6, $a1, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_2e78:
    // 0x2e78: 0x27a40014  addiu       $a0, $sp, 0x14
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 20));
label_2e7c:
    // 0x2e7c: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_2e80:
    // 0x2e80: 0x30d30001  andi        $s3, $a2, 0x1
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)1);
label_2e84:
    // 0x2e84: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
label_2e88:
    // 0x2e88: 0x13a880  sll         $s5, $s3, 2
    SET_GPR_S32(ctx, 21, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_2e8c:
    // 0x2e8c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_2e90:
    // 0x2e90: 0xe08821  addu        $s1, $a3, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_2e94:
    // 0x2e94: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_2e98:
    // 0x2e98: 0x139100  sll         $s2, $s3, 4
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 19), 4));
label_2e9c:
    // 0x2e9c: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
label_2ea0:
    // 0x2ea0: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_2ea4:
    // 0x2ea4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2ea8:
    // 0x2ea8: 0x350821  addu        $at, $at, $s5
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 21)));
label_2eac:
    // 0x2eac: 0xac345978  sw          $s4, 0x5978($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22904), GPR_U32(ctx, 20));
label_2eb0:
    // 0x2eb0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2eb4:
    // 0x2eb4: 0x350821  addu        $at, $at, $s5
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 21)));
label_2eb8:
    // 0x2eb8: 0xac205970  sw          $zero, 0x5970($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22896), GPR_U32(ctx, 0));
label_2ebc:
    // 0x2ebc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_2ec0:
    // 0x2ec0: 0x350821  addu        $at, $at, $s5
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 21)));
label_2ec4:
    // 0x2ec4: 0xac365980  sw          $s6, 0x5980($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22912), GPR_U32(ctx, 22));
label_2ec8:
    // 0x2ec8: 0xc0011e5  jal         func_004794
label_2ecc:
    if (ctx->pc == 0x2ECCu) {
        // 0x2ecc: 0x2539021  addu        $s2, $s2, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
        ctx->pc = 0x2ED0u;
        goto label_2ed0;
    }
    ctx->pc = 0x2EC8u;
    SET_GPR_U32(ctx, 31, 0x2ED0u);
    // 0x2ecc: 0x2539021  addu        $s2, $s2, $s3 (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 19)));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x2EC8u, 0x2ED0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2ED0u;
label_2ed0:
    // 0x2ed0: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2ed4:
    // 0x2ed4: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_2ed8:
    // 0x2ed8: 0x138280  sll         $s0, $s3, 10
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 19), 10));
label_2edc:
    // 0x2edc: 0x2031821  addu        $v1, $s0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_2ee0:
    // 0x2ee0: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_2ee4:
    // 0x2ee4: 0x8fa40014  lw          $a0, 0x14($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_2ee8:
    // 0x2ee8: 0x3042ffcf  andi        $v0, $v0, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65487);
label_2eec:
    // 0x2eec: 0xc0011e7  jal         func_00479C
label_2ef0:
    if (ctx->pc == 0x2EF0u) {
        // 0x2ef0: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x2EF4u;
        goto label_2ef4;
    }
    ctx->pc = 0x2EECu;
    SET_GPR_U32(ctx, 31, 0x2EF4u);
    // 0x2ef0: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x2EECu, 0x2EF4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x2EF4u;
label_2ef4:
    // 0x2ef4: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_2ef8:
    // 0x2ef8: 0x344201a8  ori         $v0, $v0, 0x1A8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)424);
label_2efc:
    // 0x2efc: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_2f00:
    // 0x2f00: 0x346301aa  ori         $v1, $v1, 0x1AA
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)426);
label_2f04:
    // 0x2f04: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_2f08:
    // 0x2f08: 0x34a501ae  ori         $a1, $a1, 0x1AE
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)430);
label_2f0c:
    // 0x2f0c: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_2f10:
    // 0x2f10: 0x2021021  addu        $v0, $s0, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
label_2f14:
    // 0x2f14: 0x2031821  addu        $v1, $s0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_2f18:
    // 0x2f18: 0xa4400000  sh          $zero, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
label_2f1c:
    // 0x2f1c: 0x32220f00  andi        $v0, $s1, 0xF00
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)3840);
label_2f20:
    // 0x2f20: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_2f24:
    // 0x2f24: 0x24420400  addiu       $v0, $v0, 0x400
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1024));
label_2f28:
    // 0x2f28: 0x2052821  addu        $a1, $s0, $a1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 5)));
label_2f2c:
    // 0x2f2c: 0x3231f000  andi        $s1, $s1, 0xF000
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)61440);
label_2f30:
    // 0x2f30: 0x118ac2  srl         $s1, $s1, 11
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 17), 11));
label_2f34:
    // 0x2f34: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_2f38:
    // 0x2f38: 0xc000854  jal         func_002150
label_2f3c:
    if (ctx->pc == 0x2F3Cu) {
        // 0x2f3c: 0xa4b10000  sh          $s1, 0x0($a1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 17));
        ctx->pc = 0x2F40u;
        goto label_2f40;
    }
    ctx->pc = 0x2F38u;
    SET_GPR_U32(ctx, 31, 0x2F40u);
    // 0x2f3c: 0xa4b10000  sh          $s1, 0x0($a1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 17));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x2F40u;
label_2f40:
    // 0x2f40: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_2f44:
    // 0x2f44: 0x344201b0  ori         $v0, $v0, 0x1B0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)432);
label_2f48:
    // 0x2f48: 0x2602021  addu        $a0, $s3, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_2f4c:
    // 0x2f4c: 0x2028021  addu        $s0, $s0, $v0
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
label_2f50:
    // 0x2f50: 0x24020004  addiu       $v0, $zero, 0x4
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
label_2f54:
    // 0x2f54: 0xc000831  jal         func_0020C4
label_2f58:
    if (ctx->pc == 0x2F58u) {
        // 0x2f58: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x2F5Cu;
        goto label_2f5c;
    }
    ctx->pc = 0x2F54u;
    SET_GPR_U32(ctx, 31, 0x2F5Cu);
    // 0x2f58: 0xa6020000  sh          $v0, 0x0($s0) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x20C4u;
    goto label_20c4;
    ctx->pc = 0x2F5Cu;
label_2f5c:
    // 0x2f5c: 0x3c03bf80  lui         $v1, 0xBF80
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49024 << 16));
label_2f60:
    // 0x2f60: 0x346310c0  ori         $v1, $v1, 0x10C0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4288);
label_2f64:
    // 0x2f64: 0x3c04bf80  lui         $a0, 0xBF80
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49024 << 16));
label_2f68:
    // 0x2f68: 0x348410c4  ori         $a0, $a0, 0x10C4
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)4292);
label_2f6c:
    // 0x2f6c: 0x3c05bf80  lui         $a1, 0xBF80
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49024 << 16));
label_2f70:
    // 0x2f70: 0x34a510c6  ori         $a1, $a1, 0x10C6
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4294);
label_2f74:
    // 0x2f74: 0x121140  sll         $v0, $s2, 5
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 5));
label_2f78:
    // 0x2f78: 0x23040  sll         $a2, $v0, 1
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_2f7c:
    // 0x2f7c: 0xc31821  addu        $v1, $a2, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
label_2f80:
    // 0x2f80: 0x129180  sll         $s2, $s2, 6
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 6));
label_2f84:
    // 0x2f84: 0x2442021  addu        $a0, $s2, $a0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
label_2f88:
    // 0x2f88: 0x24020010  addiu       $v0, $zero, 0x10
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_2f8c:
    // 0x2f8c: 0xac740000  sw          $s4, 0x0($v1)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 20));
label_2f90:
    // 0x2f90: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_2f94:
    // 0x2f94: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_2f98:
    // 0x2f98: 0x751821  addu        $v1, $v1, $s5
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 21)));
label_2f9c:
    // 0x2f9c: 0x8c635980  lw          $v1, 0x5980($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 22912)));
label_2fa0:
    // 0x2fa0: 0x0  nop
    // NOP
label_2fa4:
    // 0x2fa4: 0x4610002  bgez        $v1, . + 4 + (0x2 << 2)
label_2fa8:
    if (ctx->pc == 0x2FA8u) {
        // 0x2fa8: 0x2459021  addu        $s2, $s2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        ctx->pc = 0x2FACu;
        goto label_2fac;
    }
    ctx->pc = 0x2FA4u;
    {
        const bool branch_taken_0x2fa4 = (GPR_S32(ctx, 3) >= 0);
        // 0x2fa8: 0x2459021  addu        $s2, $s2, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        if (branch_taken_0x2fa4) {
            ctx->pc = 0x2FB0u;
            goto label_2fb0;
        }
    }
    ctx->pc = 0x2FACu;
label_2fac:
    // 0x2fac: 0x2463003f  addiu       $v1, $v1, 0x3F
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 63));
label_2fb0:
    // 0x2fb0: 0x3c130000  lui         $s3, 0x0
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)0 << 16));
label_2fb4:
    // 0x2fb4: 0x2759821  addu        $s3, $s3, $s5
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 21)));
label_2fb8:
    // 0x2fb8: 0x8e735980  lw          $s3, 0x5980($s3)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 22912)));
label_2fbc:
    // 0x2fbc: 0x31983  sra         $v1, $v1, 6
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 6));
label_2fc0:
    // 0x2fc0: 0x6610002  bgez        $s3, . + 4 + (0x2 << 2)
label_2fc4:
    if (ctx->pc == 0x2FC4u) {
        // 0x2fc4: 0x2601021  addu        $v0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        ctx->pc = 0x2FC8u;
        goto label_2fc8;
    }
    ctx->pc = 0x2FC0u;
    {
        const bool branch_taken_0x2fc0 = (GPR_S32(ctx, 19) >= 0);
        // 0x2fc4: 0x2601021  addu        $v0, $s3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
        if (branch_taken_0x2fc0) {
            ctx->pc = 0x2FCCu;
            goto label_2fcc;
        }
    }
    ctx->pc = 0x2FC8u;
label_2fc8:
    // 0x2fc8: 0x2662003f  addiu       $v0, $s3, 0x3F
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), 63));
label_2fcc:
    // 0x2fcc: 0x22183  sra         $a0, $v0, 6
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 2), 6));
label_2fd0:
    // 0x2fd0: 0x41180  sll         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
label_2fd4:
    // 0x2fd4: 0x2622023  subu        $a0, $s3, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
label_2fd8:
    // 0x2fd8: 0x4102a  slt         $v0, $zero, $a0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
label_2fdc:
    // 0x2fdc: 0x622021  addu        $a0, $v1, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_2fe0:
    // 0x2fe0: 0x3c02bf80  lui         $v0, 0xBF80
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49024 << 16));
label_2fe4:
    // 0x2fe4: 0x344210c8  ori         $v0, $v0, 0x10C8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4296);
label_2fe8:
    // 0x2fe8: 0x3c030100  lui         $v1, 0x100
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
label_2fec:
    // 0x2fec: 0x34630200  ori         $v1, $v1, 0x200
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)512);
label_2ff0:
    // 0x2ff0: 0xc21021  addu        $v0, $a2, $v0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
label_2ff4:
    // 0x2ff4: 0xa6440000  sh          $a0, 0x0($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 4));
label_2ff8:
    // 0x2ff8: 0xac430000  sw          $v1, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_2ffc:
    // 0x2ffc: 0x8c430000  lw          $v1, 0x0($v0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_3000:
    // 0x3000: 0x2c01021  addu        $v0, $s6, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
label_3004:
    // 0x3004: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_3008:
    // 0x3008: 0x8fb60030  lw          $s6, 0x30($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_300c:
    // 0x300c: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_3010:
    // 0x3010: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_3014:
    // 0x3014: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_3018:
    // 0x3018: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_301c:
    // 0x301c: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_3020:
    // 0x3020: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_3024:
    // 0x3024: 0xafa30010  sw          $v1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
label_3028:
    // 0x3028: 0x3e00008  jr          $ra
label_302c:
    if (ctx->pc == 0x302Cu) {
        // 0x302c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = 0x3030u;
        goto label_3030;
    }
    ctx->pc = 0x3028u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x302c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3028u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3030u;
label_3030:
    // 0x3030: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
label_3034:
    // 0x3034: 0xafb30034  sw          $s3, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 19));
label_3038:
    // 0x3038: 0x9821  addu        $s3, $zero, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_303c:
    // 0x303c: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
label_3040:
    // 0x3040: 0x27b00020  addiu       $s0, $sp, 0x20
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
label_3044:
    // 0x3044: 0xafa40014  sw          $a0, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 4));
label_3048:
    // 0x3048: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_304c:
    // 0x304c: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
label_3050:
    // 0x3050: 0xafb20030  sw          $s2, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
label_3054:
    // 0x3054: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
label_3058:
    // 0x3058: 0xafa50010  sw          $a1, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 5));
label_305c:
    // 0x305c: 0xafa60018  sw          $a2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 6));
label_3060:
    // 0x3060: 0xc0011e5  jal         func_004794
label_3064:
    if (ctx->pc == 0x3064u) {
        // 0x3064: 0xafa0001c  sw          $zero, 0x1C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
        ctx->pc = 0x3068u;
        goto label_3068;
    }
    ctx->pc = 0x3060u;
    SET_GPR_U32(ctx, 31, 0x3068u);
    // 0x3064: 0xafa0001c  sw          $zero, 0x1C($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 0));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x3060u, 0x3068u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3068u;
label_3068:
    // 0x3068: 0x27a40010  addiu       $a0, $sp, 0x10
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_306c:
    // 0x306c: 0xc0011fd  jal         func_0047F4
label_3070:
    if (ctx->pc == 0x3070u) {
        // 0x3070: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x3074u;
        goto label_3074;
    }
    ctx->pc = 0x306Cu;
    SET_GPR_U32(ctx, 31, 0x3074u);
    // 0x3070: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x47F4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47F4u, 0x306Cu, 0x3074u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3074u;
label_3074:
    // 0x3074: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_3078:
    // 0x3078: 0xc0011e7  jal         func_00479C
label_307c:
    if (ctx->pc == 0x307Cu) {
        // 0x307c: 0x409021  addu        $s2, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x3080u;
        goto label_3080;
    }
    ctx->pc = 0x3078u;
    SET_GPR_U32(ctx, 31, 0x3080u);
    // 0x307c: 0x409021  addu        $s2, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x3078u, 0x3080u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3080u;
label_3080:
    // 0x3080: 0x16400005  bnez        $s2, . + 4 + (0x5 << 2)
label_3084:
    if (ctx->pc == 0x3084u) {
        // 0x3084: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x3088u;
        goto label_3088;
    }
    ctx->pc = 0x3080u;
    {
        const bool branch_taken_0x3080 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        // 0x3084: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3080) {
            ctx->pc = 0x3098u;
            goto label_3098;
        }
    }
    ctx->pc = 0x3088u;
label_3088:
    // 0x3088: 0x8000c34  j           func_0030D0
label_308c:
    if (ctx->pc == 0x308Cu) {
        // 0x308c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x3090u;
        goto label_3090;
    }
    ctx->pc = 0x3088u;
    // 0x308c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x30D0u;
    goto label_30d0;
    ctx->pc = 0x3090u;
label_3090:
    // 0x3090: 0x8000c33  j           func_0030CC
label_3094:
    if (ctx->pc == 0x3094u) {
        // 0x3094: 0x2413ffff  addiu       $s3, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x3098u;
        goto label_3098;
    }
    ctx->pc = 0x3090u;
    // 0x3094: 0x2413ffff  addiu       $s3, $zero, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    ctx->pc = 0x30CCu;
    goto label_30cc;
    ctx->pc = 0x3098u;
label_3098:
    // 0x3098: 0x8000c2a  j           func_0030A8
label_309c:
    if (ctx->pc == 0x309Cu) {
        // 0x309c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x30A0u;
        goto label_30a0;
    }
    ctx->pc = 0x3098u;
    // 0x309c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x30A8u;
    goto label_30a8;
    ctx->pc = 0x30A0u;
label_30a0:
    // 0x30a0: 0x620fffb  bltz        $s1, . + 4 + (-0x5 << 2)
label_30a4:
    if (ctx->pc == 0x30A4u) {
        // 0x30a4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x30A8u;
        goto label_30a8;
    }
    ctx->pc = 0x30A0u;
    {
        const bool branch_taken_0x30a0 = (GPR_S32(ctx, 17) < 0);
        // 0x30a4: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        if (branch_taken_0x30a0) {
            ctx->pc = 0x3090u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3090;
        }
    }
    ctx->pc = 0x30A8u;
label_30a8:
    // 0x30a8: 0xc0011e5  jal         func_004794
label_30ac:
    if (ctx->pc == 0x30ACu) {
        ctx->pc = 0x30B0u;
        goto label_30b0;
    }
    ctx->pc = 0x30A8u;
    SET_GPR_U32(ctx, 31, 0x30B0u);
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x30A8u, 0x30B0u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30B0u;
label_30b0:
    // 0x30b0: 0xc0011ff  jal         func_0047FC
label_30b4:
    if (ctx->pc == 0x30B4u) {
        // 0x30b4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
        ctx->pc = 0x30B8u;
        goto label_30b8;
    }
    ctx->pc = 0x30B0u;
    SET_GPR_U32(ctx, 31, 0x30B8u);
    // 0x30b4: 0x2402021  addu        $a0, $s2, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
    ctx->pc = 0x47FCu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47FCu, 0x30B0u, 0x30B8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30B8u;
label_30b8:
    // 0x30b8: 0x8fa40020  lw          $a0, 0x20($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_30bc:
    // 0x30bc: 0xc0011e7  jal         func_00479C
label_30c0:
    if (ctx->pc == 0x30C0u) {
        // 0x30c0: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x30C4u;
        goto label_30c4;
    }
    ctx->pc = 0x30BCu;
    SET_GPR_U32(ctx, 31, 0x30C4u);
    // 0x30c0: 0x408021  addu        $s0, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x30BCu, 0x30C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x30C4u;
label_30c4:
    // 0x30c4: 0x601fff6  bgez        $s0, . + 4 + (-0xA << 2)
label_30c8:
    if (ctx->pc == 0x30C8u) {
        // 0x30c8: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->pc = 0x30CCu;
        goto label_30cc;
    }
    ctx->pc = 0x30C4u;
    {
        const bool branch_taken_0x30c4 = (GPR_S32(ctx, 16) >= 0);
        // 0x30c8: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        if (branch_taken_0x30c4) {
            ctx->pc = 0x30A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_30a0;
        }
    }
    ctx->pc = 0x30CCu;
label_30cc:
    // 0x30cc: 0x2601021  addu        $v0, $s3, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_30d0:
    // 0x30d0: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_30d4:
    // 0x30d4: 0x8fb30034  lw          $s3, 0x34($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_30d8:
    // 0x30d8: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_30dc:
    // 0x30dc: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_30e0:
    // 0x30e0: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_30e4:
    // 0x30e4: 0x3e00008  jr          $ra
label_30e8:
    if (ctx->pc == 0x30E8u) {
        // 0x30e8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x30ECu;
        goto label_30ec;
    }
    ctx->pc = 0x30E4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x30e8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x30E4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x30ECu;
label_30ec:
    // 0x30ec: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
label_30f0:
    // 0x30f0: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
label_30f4:
    // 0x30f4: 0xa0a821  addu        $s5, $a1, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_30f8:
    // 0x30f8: 0xafb60030  sw          $s6, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 22));
label_30fc:
    // 0x30fc: 0xc0b021  addu        $s6, $a2, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_3100:
    // 0x3100: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_3104:
    // 0x3104: 0x9021  addu        $s2, $zero, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_3108:
    // 0x3108: 0xafbf0038  sw          $ra, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 31));
label_310c:
    // 0x310c: 0xafb70034  sw          $s7, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 23));
label_3110:
    // 0x3110: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_3114:
    // 0x3114: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_3118:
    // 0x3118: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_311c:
    // 0x311c: 0x12c0005f  beqz        $s6, . + 4 + (0x5F << 2)
label_3120:
    if (ctx->pc == 0x3120u) {
        // 0x3120: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        ctx->pc = 0x3124u;
        goto label_3124;
    }
    ctx->pc = 0x311Cu;
    {
        const bool branch_taken_0x311c = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x3120: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        if (branch_taken_0x311c) {
            ctx->pc = 0x329Cu;
            goto label_329c;
        }
    }
    ctx->pc = 0x3124u;
label_3124:
    // 0x3124: 0x3c170000  lui         $s7, 0x0
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)0 << 16));
label_3128:
    // 0x3128: 0x26f748e0  addiu       $s7, $s7, 0x48E0
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 18656));
label_312c:
    // 0x312c: 0x2a09821  addu        $s3, $s5, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
label_3130:
    // 0x3130: 0x2414ffff  addiu       $s4, $zero, -0x1
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_3134:
    // 0x3134: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_3138:
    // 0x3138: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_313c:
    // 0x313c: 0x0  nop
    // NOP
label_3140:
    // 0x3140: 0x2443ffff  addiu       $v1, $v0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
label_3144:
    // 0x3144: 0x2c620014  sltiu       $v0, $v1, 0x14
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)20) ? 1 : 0);
label_3148:
    // 0x3148: 0x10400047  beqz        $v0, . + 4 + (0x47 << 2)
label_314c:
    if (ctx->pc == 0x314Cu) {
        // 0x314c: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x3150u;
        goto label_3150;
    }
    ctx->pc = 0x3148u;
    {
        const bool branch_taken_0x3148 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x314c: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3148) {
            ctx->pc = 0x3268u;
            goto label_3268;
        }
    }
    ctx->pc = 0x3150u;
label_3150:
    // 0x3150: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_3154:
    // 0x3154: 0x571021  addu        $v0, $v0, $s7
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 23)));
label_3158:
    // 0x3158: 0x8c420000  lw          $v0, 0x0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_315c:
    // 0x315c: 0x0  nop
    // NOP
label_3160:
    // 0x3160: 0x400008  jr          $v0
label_3164:
    if (ctx->pc == 0x3164u) {
        ctx->pc = 0x3168u;
        goto label_3168;
    }
    ctx->pc = 0x3160u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x3168u: goto label_3168;
            case 0x3180u: goto label_3180;
            case 0x3194u: goto label_3194;
            case 0x31ACu: goto label_31ac;
            case 0x31C0u: goto label_31c0;
            case 0x31D8u: goto label_31d8;
            case 0x31ECu: goto label_31ec;
            case 0x3204u: goto label_3204;
            case 0x3218u: goto label_3218;
            case 0x3228u: goto label_3228;
            case 0x324Cu: goto label_324c;
            case 0x3268u: goto label_3268;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x3160u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x3168u;
label_3168:
    // 0x3168: 0x96040002  lhu         $a0, 0x2($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_316c:
    // 0x316c: 0x96050004  lhu         $a1, 0x4($s0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
label_3170:
    // 0x3170: 0xc000da4  jal         func_003690
label_3174:
    if (ctx->pc == 0x3174u) {
        ctx->pc = 0x3178u;
        goto label_3178;
    }
    ctx->pc = 0x3170u;
    SET_GPR_U32(ctx, 31, 0x3178u);
    ctx->pc = 0x3690u;
    goto label_3690;
    ctx->pc = 0x3178u;
label_3178:
    // 0x3178: 0x8000c9e  j           func_003278
label_317c:
    if (ctx->pc == 0x317Cu) {
        ctx->pc = 0x3180u;
        goto label_3180;
    }
    ctx->pc = 0x3178u;
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x3180u;
label_3180:
    // 0x3180: 0x96040002  lhu         $a0, 0x2($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_3184:
    // 0x3184: 0xc000dbb  jal         func_0036EC
label_3188:
    if (ctx->pc == 0x3188u) {
        ctx->pc = 0x318Cu;
        goto label_318c;
    }
    ctx->pc = 0x3184u;
    SET_GPR_U32(ctx, 31, 0x318Cu);
    ctx->pc = 0x36ECu;
    goto label_36ec;
    ctx->pc = 0x318Cu;
label_318c:
    // 0x318c: 0x8000c9e  j           func_003278
label_3190:
    if (ctx->pc == 0x3190u) {
        // 0x3190: 0x3051ffff  andi        $s1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3194u;
        goto label_3194;
    }
    ctx->pc = 0x318Cu;
    // 0x3190: 0x3051ffff  andi        $s1, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x3194u;
label_3194:
    // 0x3194: 0x96040002  lhu         $a0, 0x2($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_3198:
    // 0x3198: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_319c:
    // 0x319c: 0xc000dd3  jal         func_00374C
label_31a0:
    if (ctx->pc == 0x31A0u) {
        ctx->pc = 0x31A4u;
        goto label_31a4;
    }
    ctx->pc = 0x319Cu;
    SET_GPR_U32(ctx, 31, 0x31A4u);
    ctx->pc = 0x374Cu;
    goto label_374c;
    ctx->pc = 0x31A4u;
label_31a4:
    // 0x31a4: 0x8000c9e  j           func_003278
label_31a8:
    if (ctx->pc == 0x31A8u) {
        ctx->pc = 0x31ACu;
        goto label_31ac;
    }
    ctx->pc = 0x31A4u;
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x31ACu;
label_31ac:
    // 0x31ac: 0x96040002  lhu         $a0, 0x2($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_31b0:
    // 0x31b0: 0xc000de1  jal         func_003784
label_31b4:
    if (ctx->pc == 0x31B4u) {
        ctx->pc = 0x31B8u;
        goto label_31b8;
    }
    ctx->pc = 0x31B0u;
    SET_GPR_U32(ctx, 31, 0x31B8u);
    ctx->pc = 0x3784u;
    goto label_3784;
    ctx->pc = 0x31B8u;
label_31b8:
    // 0x31b8: 0x8000c9e  j           func_003278
label_31bc:
    if (ctx->pc == 0x31BCu) {
        // 0x31bc: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x31C0u;
        goto label_31c0;
    }
    ctx->pc = 0x31B8u;
    // 0x31bc: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x31C0u;
label_31c0:
    // 0x31c0: 0x96040002  lhu         $a0, 0x2($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_31c4:
    // 0x31c4: 0x8e050004  lw          $a1, 0x4($s0)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_31c8:
    // 0x31c8: 0xc000def  jal         func_0037BC
label_31cc:
    if (ctx->pc == 0x31CCu) {
        ctx->pc = 0x31D0u;
        goto label_31d0;
    }
    ctx->pc = 0x31C8u;
    SET_GPR_U32(ctx, 31, 0x31D0u);
    ctx->pc = 0x37BCu;
    goto label_37bc;
    ctx->pc = 0x31D0u;
label_31d0:
    // 0x31d0: 0x8000c9e  j           func_003278
label_31d4:
    if (ctx->pc == 0x31D4u) {
        ctx->pc = 0x31D8u;
        goto label_31d8;
    }
    ctx->pc = 0x31D0u;
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x31D8u;
label_31d8:
    // 0x31d8: 0x96040002  lhu         $a0, 0x2($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_31dc:
    // 0x31dc: 0xc000e08  jal         func_003820
label_31e0:
    if (ctx->pc == 0x31E0u) {
        ctx->pc = 0x31E4u;
        goto label_31e4;
    }
    ctx->pc = 0x31DCu;
    SET_GPR_U32(ctx, 31, 0x31E4u);
    ctx->pc = 0x3820u;
    goto label_3820;
    ctx->pc = 0x31E4u;
label_31e4:
    // 0x31e4: 0x8000c9e  j           func_003278
label_31e8:
    if (ctx->pc == 0x31E8u) {
        // 0x31e8: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x31ECu;
        goto label_31ec;
    }
    ctx->pc = 0x31E4u;
    // 0x31e8: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x31ECu;
label_31ec:
    // 0x31ec: 0x96040002  lhu         $a0, 0x2($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_31f0:
    // 0x31f0: 0x96050004  lhu         $a1, 0x4($s0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
label_31f4:
    // 0x31f4: 0xc000f37  jal         func_003CDC
label_31f8:
    if (ctx->pc == 0x31F8u) {
        ctx->pc = 0x31FCu;
        goto label_31fc;
    }
    ctx->pc = 0x31F4u;
    SET_GPR_U32(ctx, 31, 0x31FCu);
    ctx->pc = 0x3CDCu;
    goto label_3cdc;
    ctx->pc = 0x31FCu;
label_31fc:
    // 0x31fc: 0x8000c9e  j           func_003278
label_3200:
    if (ctx->pc == 0x3200u) {
        ctx->pc = 0x3204u;
        goto label_3204;
    }
    ctx->pc = 0x31FCu;
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x3204u;
label_3204:
    // 0x3204: 0x96040002  lhu         $a0, 0x2($s0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_3208:
    // 0x3208: 0xc000f64  jal         func_003D90
label_320c:
    if (ctx->pc == 0x320Cu) {
        ctx->pc = 0x3210u;
        goto label_3210;
    }
    ctx->pc = 0x3208u;
    SET_GPR_U32(ctx, 31, 0x3210u);
    ctx->pc = 0x3D90u;
    goto label_3d90;
    ctx->pc = 0x3210u;
label_3210:
    // 0x3210: 0x8000c9e  j           func_003278
label_3214:
    if (ctx->pc == 0x3214u) {
        // 0x3214: 0x3051ffff  andi        $s1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3218u;
        goto label_3218;
    }
    ctx->pc = 0x3210u;
    // 0x3214: 0x3051ffff  andi        $s1, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x3218u;
label_3218:
    // 0x3218: 0x8e030004  lw          $v1, 0x4($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_321c:
    // 0x321c: 0x96020002  lhu         $v0, 0x2($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_3220:
    // 0x3220: 0x8000c9e  j           func_003278
label_3224:
    if (ctx->pc == 0x3224u) {
        // 0x3224: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x3228u;
        goto label_3228;
    }
    ctx->pc = 0x3220u;
    // 0x3224: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x3228u;
label_3228:
    // 0x3228: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_322c:
    // 0x322c: 0x24a55990  addiu       $a1, $a1, 0x5990
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22928));
label_3230:
    // 0x3230: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_3234:
    // 0x3234: 0x96020002  lhu         $v0, 0x2($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_3238:
    // 0x3238: 0x0  nop
    // NOP
label_323c:
    // 0x323c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3240:
    // 0x3240: 0xac225990  sw          $v0, 0x5990($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22928), GPR_U32(ctx, 2));
label_3244:
    // 0x3244: 0x8000c96  j           func_003258
label_3248:
    if (ctx->pc == 0x3248u) {
        // 0x3248: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->pc = 0x324Cu;
        goto label_324c;
    }
    ctx->pc = 0x3244u;
    // 0x3248: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x3258u;
    goto label_3258;
    ctx->pc = 0x324Cu;
label_324c:
    // 0x324c: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_3250:
    // 0x3250: 0x96060002  lhu         $a2, 0x2($s0)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
label_3254:
    // 0x3254: 0x2a02821  addu        $a1, $s5, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 0)));
label_3258:
    // 0x3258: 0xc000c0c  jal         func_003030
label_325c:
    if (ctx->pc == 0x325Cu) {
        ctx->pc = 0x3260u;
        goto label_3260;
    }
    ctx->pc = 0x3258u;
    SET_GPR_U32(ctx, 31, 0x3260u);
    ctx->pc = 0x3030u;
    goto label_3030;
    ctx->pc = 0x3260u;
label_3260:
    // 0x3260: 0x8000c9e  j           func_003278
label_3264:
    if (ctx->pc == 0x3264u) {
        // 0x3264: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x3268u;
        goto label_3268;
    }
    ctx->pc = 0x3260u;
    // 0x3264: 0x408821  addu        $s1, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x3278u;
    goto label_3278;
    ctx->pc = 0x3268u;
label_3268:
    // 0x3268: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_326c:
    // 0x326c: 0x8fa30010  lw          $v1, 0x10($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_3270:
    // 0x3270: 0x8000caa  j           func_0032A8
label_3274:
    if (ctx->pc == 0x3274u) {
        // 0x3274: 0x2801021  addu        $v0, $s4, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
        ctx->pc = 0x3278u;
        goto label_3278;
    }
    ctx->pc = 0x3270u;
    // 0x3274: 0x2801021  addu        $v0, $s4, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 0)));
    ctx->pc = 0x32A8u;
    goto label_32a8;
    ctx->pc = 0x3278u;
label_3278:
    // 0x3278: 0x12a00002  beqz        $s5, . + 4 + (0x2 << 2)
label_327c:
    if (ctx->pc == 0x327Cu) {
        ctx->pc = 0x3280u;
        goto label_3280;
    }
    ctx->pc = 0x3278u;
    {
        const bool branch_taken_0x3278 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        if (branch_taken_0x3278) {
            ctx->pc = 0x3284u;
            goto label_3284;
        }
    }
    ctx->pc = 0x3280u;
label_3280:
    // 0x3280: 0xae710000  sw          $s1, 0x0($s3)
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 17));
label_3284:
    // 0x3284: 0x26730004  addiu       $s3, $s3, 0x4
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
label_3288:
    // 0x3288: 0x2694ffff  addiu       $s4, $s4, -0x1
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
label_328c:
    // 0x328c: 0x26520001  addiu       $s2, $s2, 0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_3290:
    // 0x3290: 0x256102b  sltu        $v0, $s2, $s6
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 22)) ? 1 : 0);
label_3294:
    // 0x3294: 0x1440ffa8  bnez        $v0, . + 4 + (-0x58 << 2)
label_3298:
    if (ctx->pc == 0x3298u) {
        // 0x3298: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->pc = 0x329Cu;
        goto label_329c;
    }
    ctx->pc = 0x3294u;
    {
        const bool branch_taken_0x3294 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3298: 0x26100008  addiu       $s0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        if (branch_taken_0x3294) {
            ctx->pc = 0x3138u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3138;
        }
    }
    ctx->pc = 0x329Cu;
label_329c:
    // 0x329c: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_32a0:
    // 0x32a0: 0x8fa30010  lw          $v1, 0x10($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_32a4:
    // 0x32a4: 0x2401021  addu        $v0, $s2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_32a8:
    // 0x32a8: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
label_32ac:
    // 0x32ac: 0x8fbf0038  lw          $ra, 0x38($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_32b0:
    // 0x32b0: 0x8fb70034  lw          $s7, 0x34($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_32b4:
    // 0x32b4: 0x8fb60030  lw          $s6, 0x30($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_32b8:
    // 0x32b8: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_32bc:
    // 0x32bc: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_32c0:
    // 0x32c0: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_32c4:
    // 0x32c4: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_32c8:
    // 0x32c8: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_32cc:
    // 0x32cc: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_32d0:
    // 0x32d0: 0x3e00008  jr          $ra
label_32d4:
    if (ctx->pc == 0x32D4u) {
        // 0x32d4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x32D8u;
        goto label_32d8;
    }
    ctx->pc = 0x32D0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x32d4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x32D0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x32D8u;
label_32d8:
    // 0x32d8: 0x27bdffc0  addiu       $sp, $sp, -0x40
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
label_32dc:
    // 0x32dc: 0xafb60030  sw          $s6, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 22));
label_32e0:
    // 0x32e0: 0xa0b021  addu        $s6, $a1, $zero
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_32e4:
    // 0x32e4: 0xafb70034  sw          $s7, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 23));
label_32e8:
    // 0x32e8: 0xb821  addu        $s7, $zero, $zero
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_32ec:
    // 0x32ec: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_32f0:
    // 0x32f0: 0x2e09821  addu        $s3, $s7, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 0)));
label_32f4:
    // 0x32f4: 0xafbf003c  sw          $ra, 0x3C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 31));
label_32f8:
    // 0x32f8: 0xafbe0038  sw          $fp, 0x38($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 30));
label_32fc:
    // 0x32fc: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
label_3300:
    // 0x3300: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_3304:
    // 0x3304: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_3308:
    // 0x3308: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_330c:
    // 0x330c: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_3310:
    // 0x3310: 0xafa60048  sw          $a2, 0x48($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 6));
label_3314:
    // 0x3314: 0x10c000cb  beqz        $a2, . + 4 + (0xCB << 2)
label_3318:
    if (ctx->pc == 0x3318u) {
        // 0x3318: 0xafa7004c  sw          $a3, 0x4C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 7));
        ctx->pc = 0x331Cu;
        goto label_331c;
    }
    ctx->pc = 0x3314u;
    {
        const bool branch_taken_0x3314 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        // 0x3318: 0xafa7004c  sw          $a3, 0x4C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 7));
        if (branch_taken_0x3314) {
            ctx->pc = 0x3644u;
            goto label_3644;
        }
    }
    ctx->pc = 0x331Cu;
label_331c:
    // 0x331c: 0x241e0001  addiu       $fp, $zero, 0x1
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_3320:
    // 0x3320: 0x809021  addu        $s2, $a0, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_3324:
    // 0x3324: 0x96420000  lhu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
label_3328:
    // 0x3328: 0x0  nop
    // NOP
label_332c:
    // 0x332c: 0x2443ffff  addiu       $v1, $v0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
label_3330:
    // 0x3330: 0x2c620014  sltiu       $v0, $v1, 0x14
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)20) ? 1 : 0);
label_3334:
    // 0x3334: 0x104000b4  beqz        $v0, . + 4 + (0xB4 << 2)
label_3338:
    if (ctx->pc == 0x3338u) {
        // 0x3338: 0xa021  addu        $s4, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x333Cu;
        goto label_333c;
    }
    ctx->pc = 0x3334u;
    {
        const bool branch_taken_0x3334 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3338: 0xa021  addu        $s4, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3334) {
            ctx->pc = 0x3608u;
            goto label_3608;
        }
    }
    ctx->pc = 0x333Cu;
label_333c:
    // 0x333c: 0x31080  sll         $v0, $v1, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_3340:
    // 0x3340: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3344:
    // 0x3344: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_3348:
    // 0x3348: 0x8c224930  lw          $v0, 0x4930($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18736)));
label_334c:
    // 0x334c: 0x0  nop
    // NOP
label_3350:
    // 0x3350: 0x400008  jr          $v0
label_3354:
    if (ctx->pc == 0x3354u) {
        ctx->pc = 0x3358u;
        goto label_3358;
    }
    ctx->pc = 0x3350u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x3358u: goto label_3358;
            case 0x33D0u: goto label_33d0;
            case 0x345Cu: goto label_345c;
            case 0x3474u: goto label_3474;
            case 0x3488u: goto label_3488;
            case 0x3500u: goto label_3500;
            case 0x358Cu: goto label_358c;
            case 0x35A4u: goto label_35a4;
            case 0x35B8u: goto label_35b8;
            case 0x35C8u: goto label_35c8;
            case 0x35ECu: goto label_35ec;
            case 0x3608u: goto label_3608;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x3350u, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x3358u;
label_3358:
    // 0x3358: 0x96420002  lhu         $v0, 0x2($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_335c:
    // 0x335c: 0x2408003e  addiu       $t0, $zero, 0x3E
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
label_3360:
    // 0x3360: 0x3042003e  andi        $v0, $v0, 0x3E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)62);
label_3364:
    // 0x3364: 0x10480007  beq         $v0, $t0, . + 4 + (0x7 << 2)
label_3368:
    if (ctx->pc == 0x3368u) {
        // 0x3368: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x336Cu;
        goto label_336c;
    }
    ctx->pc = 0x3364u;
    {
        const bool branch_taken_0x3364 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 8));
        // 0x3368: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3364) {
            ctx->pc = 0x3384u;
            goto label_3384;
        }
    }
    ctx->pc = 0x336Cu;
label_336c:
    // 0x336c: 0x96440002  lhu         $a0, 0x2($s2)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_3370:
    // 0x3370: 0x96450004  lhu         $a1, 0x4($s2)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 4)));
label_3374:
    // 0x3374: 0xc000da4  jal         func_003690
label_3378:
    if (ctx->pc == 0x3378u) {
        ctx->pc = 0x337Cu;
        goto label_337c;
    }
    ctx->pc = 0x3374u;
    SET_GPR_U32(ctx, 31, 0x337Cu);
    ctx->pc = 0x3690u;
    goto label_3690;
    ctx->pc = 0x337Cu;
label_337c:
    // 0x337c: 0x8000d86  j           func_003618
label_3380:
    if (ctx->pc == 0x3380u) {
        ctx->pc = 0x3384u;
        goto label_3384;
    }
    ctx->pc = 0x337Cu;
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x3384u;
label_3384:
    // 0x3384: 0x2408821  addu        $s1, $s2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_3388:
    // 0x3388: 0x8fa8004c  lw          $t0, 0x4C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
label_338c:
    // 0x338c: 0x21e1004  sllv        $v0, $fp, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), GPR_U32(ctx, 16) & 0x1F));
label_3390:
    // 0x3390: 0x481024  and         $v0, $v0, $t0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
label_3394:
    // 0x3394: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_3398:
    if (ctx->pc == 0x3398u) {
        // 0x3398: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->pc = 0x339Cu;
        goto label_339c;
    }
    ctx->pc = 0x3394u;
    {
        const bool branch_taken_0x3394 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3398: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x3394) {
            ctx->pc = 0x33B8u;
            goto label_33b8;
        }
    }
    ctx->pc = 0x339Cu;
label_339c:
    // 0x339c: 0x26730001  addiu       $s3, $s3, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_33a0:
    // 0x33a0: 0x96240002  lhu         $a0, 0x2($s1)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
label_33a4:
    // 0x33a4: 0x96250004  lhu         $a1, 0x4($s1)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 4)));
label_33a8:
    // 0x33a8: 0x3084ffc1  andi        $a0, $a0, 0xFFC1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65473);
label_33ac:
    // 0x33ac: 0x822025  or          $a0, $a0, $v0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
label_33b0:
    // 0x33b0: 0xc000da4  jal         func_003690
label_33b4:
    if (ctx->pc == 0x33B4u) {
        // 0x33b4: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x33B8u;
        goto label_33b8;
    }
    ctx->pc = 0x33B0u;
    SET_GPR_U32(ctx, 31, 0x33B8u);
    // 0x33b4: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3690u;
    goto label_3690;
    ctx->pc = 0x33B8u;
label_33b8:
    // 0x33b8: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_33bc:
    // 0x33bc: 0x2a020018  slti        $v0, $s0, 0x18
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)24) ? 1 : 0);
label_33c0:
    // 0x33c0: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
label_33c4:
    if (ctx->pc == 0x33C4u) {
        ctx->pc = 0x33C8u;
        goto label_33c8;
    }
    ctx->pc = 0x33C0u;
    {
        const bool branch_taken_0x33c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x33c0) {
            ctx->pc = 0x3388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3388;
        }
    }
    ctx->pc = 0x33C8u;
label_33c8:
    // 0x33c8: 0x8000d86  j           func_003618
label_33cc:
    if (ctx->pc == 0x33CCu) {
        // 0x33cc: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
        ctx->pc = 0x33D0u;
        goto label_33d0;
    }
    ctx->pc = 0x33C8u;
    // 0x33cc: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x33D0u;
label_33d0:
    // 0x33d0: 0x96420002  lhu         $v0, 0x2($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_33d4:
    // 0x33d4: 0x2408003e  addiu       $t0, $zero, 0x3E
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
label_33d8:
    // 0x33d8: 0x3042003e  andi        $v0, $v0, 0x3E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)62);
label_33dc:
    // 0x33dc: 0x10480006  beq         $v0, $t0, . + 4 + (0x6 << 2)
label_33e0:
    if (ctx->pc == 0x33E0u) {
        // 0x33e0: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x33E4u;
        goto label_33e4;
    }
    ctx->pc = 0x33DCu;
    {
        const bool branch_taken_0x33dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 8));
        // 0x33e0: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x33dc) {
            ctx->pc = 0x33F8u;
            goto label_33f8;
        }
    }
    ctx->pc = 0x33E4u;
label_33e4:
    // 0x33e4: 0x96440002  lhu         $a0, 0x2($s2)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_33e8:
    // 0x33e8: 0xc000dbb  jal         func_0036EC
label_33ec:
    if (ctx->pc == 0x33ECu) {
        ctx->pc = 0x33F0u;
        goto label_33f0;
    }
    ctx->pc = 0x33E8u;
    SET_GPR_U32(ctx, 31, 0x33F0u);
    ctx->pc = 0x36ECu;
    goto label_36ec;
    ctx->pc = 0x33F0u;
label_33f0:
    // 0x33f0: 0x8000d86  j           func_003618
label_33f4:
    if (ctx->pc == 0x33F4u) {
        // 0x33f4: 0x3054ffff  andi        $s4, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x33F8u;
        goto label_33f8;
    }
    ctx->pc = 0x33F0u;
    // 0x33f4: 0x3054ffff  andi        $s4, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x33F8u;
label_33f8:
    // 0x33f8: 0x240a821  addu        $s5, $s2, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_33fc:
    // 0x33fc: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_3400:
    // 0x3400: 0x568821  addu        $s1, $v0, $s6
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
label_3404:
    // 0x3404: 0x8fa8004c  lw          $t0, 0x4C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
label_3408:
    // 0x3408: 0x21e1004  sllv        $v0, $fp, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), GPR_U32(ctx, 16) & 0x1F));
label_340c:
    // 0x340c: 0x481024  and         $v0, $v0, $t0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
label_3410:
    // 0x3410: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_3414:
    if (ctx->pc == 0x3414u) {
        // 0x3414: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->pc = 0x3418u;
        goto label_3418;
    }
    ctx->pc = 0x3410u;
    {
        const bool branch_taken_0x3410 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3414: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x3410) {
            ctx->pc = 0x3434u;
            goto label_3434;
        }
    }
    ctx->pc = 0x3418u;
label_3418:
    // 0x3418: 0x96a40002  lhu         $a0, 0x2($s5)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 2)));
label_341c:
    // 0x341c: 0x0  nop
    // NOP
label_3420:
    // 0x3420: 0x3084ffc1  andi        $a0, $a0, 0xFFC1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65473);
label_3424:
    // 0x3424: 0x822025  or          $a0, $a0, $v0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
label_3428:
    // 0x3428: 0xc000dbb  jal         func_0036EC
label_342c:
    if (ctx->pc == 0x342Cu) {
        // 0x342c: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3430u;
        goto label_3430;
    }
    ctx->pc = 0x3428u;
    SET_GPR_U32(ctx, 31, 0x3430u);
    // 0x342c: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x36ECu;
    goto label_36ec;
    ctx->pc = 0x3430u;
label_3430:
    // 0x3430: 0x3054ffff  andi        $s4, $v0, 0xFFFF
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
label_3434:
    // 0x3434: 0x12c00002  beqz        $s6, . + 4 + (0x2 << 2)
label_3438:
    if (ctx->pc == 0x3438u) {
        ctx->pc = 0x343Cu;
        goto label_343c;
    }
    ctx->pc = 0x3434u;
    {
        const bool branch_taken_0x3434 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        if (branch_taken_0x3434) {
            ctx->pc = 0x3440u;
            goto label_3440;
        }
    }
    ctx->pc = 0x343Cu;
label_343c:
    // 0x343c: 0xae340000  sw          $s4, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 20));
label_3440:
    // 0x3440: 0x26310004  addiu       $s1, $s1, 0x4
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_3444:
    // 0x3444: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_3448:
    // 0x3448: 0x2a020018  slti        $v0, $s0, 0x18
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)24) ? 1 : 0);
label_344c:
    // 0x344c: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
label_3450:
    if (ctx->pc == 0x3450u) {
        // 0x3450: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->pc = 0x3454u;
        goto label_3454;
    }
    ctx->pc = 0x344Cu;
    {
        const bool branch_taken_0x344c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3450: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        if (branch_taken_0x344c) {
            ctx->pc = 0x3404u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3404;
        }
    }
    ctx->pc = 0x3454u;
label_3454:
    // 0x3454: 0x8000d86  j           func_003618
label_3458:
    if (ctx->pc == 0x3458u) {
        // 0x3458: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
        ctx->pc = 0x345Cu;
        goto label_345c;
    }
    ctx->pc = 0x3454u;
    // 0x3458: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x345Cu;
label_345c:
    // 0x345c: 0x96440002  lhu         $a0, 0x2($s2)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_3460:
    // 0x3460: 0x8e450004  lw          $a1, 0x4($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_3464:
    // 0x3464: 0xc000dd3  jal         func_00374C
label_3468:
    if (ctx->pc == 0x3468u) {
        ctx->pc = 0x346Cu;
        goto label_346c;
    }
    ctx->pc = 0x3464u;
    SET_GPR_U32(ctx, 31, 0x346Cu);
    ctx->pc = 0x374Cu;
    goto label_374c;
    ctx->pc = 0x346Cu;
label_346c:
    // 0x346c: 0x8000d86  j           func_003618
label_3470:
    if (ctx->pc == 0x3470u) {
        ctx->pc = 0x3474u;
        goto label_3474;
    }
    ctx->pc = 0x346Cu;
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x3474u;
label_3474:
    // 0x3474: 0x96440002  lhu         $a0, 0x2($s2)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_3478:
    // 0x3478: 0xc000de1  jal         func_003784
label_347c:
    if (ctx->pc == 0x347Cu) {
        ctx->pc = 0x3480u;
        goto label_3480;
    }
    ctx->pc = 0x3478u;
    SET_GPR_U32(ctx, 31, 0x3480u);
    ctx->pc = 0x3784u;
    goto label_3784;
    ctx->pc = 0x3480u;
label_3480:
    // 0x3480: 0x8000d86  j           func_003618
label_3484:
    if (ctx->pc == 0x3484u) {
        // 0x3484: 0x40a021  addu        $s4, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x3488u;
        goto label_3488;
    }
    ctx->pc = 0x3480u;
    // 0x3484: 0x40a021  addu        $s4, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x3488u;
label_3488:
    // 0x3488: 0x8e420000  lw          $v0, 0x0($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_348c:
    // 0x348c: 0x3c03007e  lui         $v1, 0x7E
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)126 << 16));
label_3490:
    // 0x3490: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_3494:
    // 0x3494: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
label_3498:
    if (ctx->pc == 0x3498u) {
        // 0x3498: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x349Cu;
        goto label_349c;
    }
    ctx->pc = 0x3494u;
    {
        const bool branch_taken_0x3494 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        // 0x3498: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x3494) {
            ctx->pc = 0x34B4u;
            goto label_34b4;
        }
    }
    ctx->pc = 0x349Cu;
label_349c:
    // 0x349c: 0x96440002  lhu         $a0, 0x2($s2)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_34a0:
    // 0x34a0: 0x8e450004  lw          $a1, 0x4($s2)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_34a4:
    // 0x34a4: 0xc000def  jal         func_0037BC
label_34a8:
    if (ctx->pc == 0x34A8u) {
        ctx->pc = 0x34ACu;
        goto label_34ac;
    }
    ctx->pc = 0x34A4u;
    SET_GPR_U32(ctx, 31, 0x34ACu);
    ctx->pc = 0x37BCu;
    goto label_37bc;
    ctx->pc = 0x34ACu;
label_34ac:
    // 0x34ac: 0x8000d86  j           func_003618
label_34b0:
    if (ctx->pc == 0x34B0u) {
        ctx->pc = 0x34B4u;
        goto label_34b4;
    }
    ctx->pc = 0x34ACu;
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x34B4u;
label_34b4:
    // 0x34b4: 0x2408821  addu        $s1, $s2, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_34b8:
    // 0x34b8: 0x8fa8004c  lw          $t0, 0x4C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
label_34bc:
    // 0x34bc: 0x21e1004  sllv        $v0, $fp, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), GPR_U32(ctx, 16) & 0x1F));
label_34c0:
    // 0x34c0: 0x481024  and         $v0, $v0, $t0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
label_34c4:
    // 0x34c4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
label_34c8:
    if (ctx->pc == 0x34C8u) {
        // 0x34c8: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->pc = 0x34CCu;
        goto label_34cc;
    }
    ctx->pc = 0x34C4u;
    {
        const bool branch_taken_0x34c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x34c8: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x34c4) {
            ctx->pc = 0x34E8u;
            goto label_34e8;
        }
    }
    ctx->pc = 0x34CCu;
label_34cc:
    // 0x34cc: 0x26730001  addiu       $s3, $s3, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_34d0:
    // 0x34d0: 0x96240002  lhu         $a0, 0x2($s1)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 2)));
label_34d4:
    // 0x34d4: 0x8e250004  lw          $a1, 0x4($s1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_34d8:
    // 0x34d8: 0x3084ffc1  andi        $a0, $a0, 0xFFC1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65473);
label_34dc:
    // 0x34dc: 0x822025  or          $a0, $a0, $v0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
label_34e0:
    // 0x34e0: 0xc000def  jal         func_0037BC
label_34e4:
    if (ctx->pc == 0x34E4u) {
        // 0x34e4: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x34E8u;
        goto label_34e8;
    }
    ctx->pc = 0x34E0u;
    SET_GPR_U32(ctx, 31, 0x34E8u);
    // 0x34e4: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x37BCu;
    goto label_37bc;
    ctx->pc = 0x34E8u;
label_34e8:
    // 0x34e8: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_34ec:
    // 0x34ec: 0x2a020018  slti        $v0, $s0, 0x18
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)24) ? 1 : 0);
label_34f0:
    // 0x34f0: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
label_34f4:
    if (ctx->pc == 0x34F4u) {
        ctx->pc = 0x34F8u;
        goto label_34f8;
    }
    ctx->pc = 0x34F0u;
    {
        const bool branch_taken_0x34f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x34f0) {
            ctx->pc = 0x34B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_34b8;
        }
    }
    ctx->pc = 0x34F8u;
label_34f8:
    // 0x34f8: 0x8000d86  j           func_003618
label_34fc:
    if (ctx->pc == 0x34FCu) {
        // 0x34fc: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
        ctx->pc = 0x3500u;
        goto label_3500;
    }
    ctx->pc = 0x34F8u;
    // 0x34fc: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x3500u;
label_3500:
    // 0x3500: 0x8e420000  lw          $v0, 0x0($s2)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_3504:
    // 0x3504: 0x3c03007e  lui         $v1, 0x7E
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)126 << 16));
label_3508:
    // 0x3508: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_350c:
    // 0x350c: 0x10430006  beq         $v0, $v1, . + 4 + (0x6 << 2)
label_3510:
    if (ctx->pc == 0x3510u) {
        // 0x3510: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x3514u;
        goto label_3514;
    }
    ctx->pc = 0x350Cu;
    {
        const bool branch_taken_0x350c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        // 0x3510: 0x8021  addu        $s0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x350c) {
            ctx->pc = 0x3528u;
            goto label_3528;
        }
    }
    ctx->pc = 0x3514u;
label_3514:
    // 0x3514: 0x96440002  lhu         $a0, 0x2($s2)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_3518:
    // 0x3518: 0xc000e08  jal         func_003820
label_351c:
    if (ctx->pc == 0x351Cu) {
        ctx->pc = 0x3520u;
        goto label_3520;
    }
    ctx->pc = 0x3518u;
    SET_GPR_U32(ctx, 31, 0x3520u);
    ctx->pc = 0x3820u;
    goto label_3820;
    ctx->pc = 0x3520u;
label_3520:
    // 0x3520: 0x8000d86  j           func_003618
label_3524:
    if (ctx->pc == 0x3524u) {
        // 0x3524: 0x40a021  addu        $s4, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x3528u;
        goto label_3528;
    }
    ctx->pc = 0x3520u;
    // 0x3524: 0x40a021  addu        $s4, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x3528u;
label_3528:
    // 0x3528: 0x240a821  addu        $s5, $s2, $zero
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_352c:
    // 0x352c: 0x131080  sll         $v0, $s3, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
label_3530:
    // 0x3530: 0x568821  addu        $s1, $v0, $s6
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
label_3534:
    // 0x3534: 0x8fa8004c  lw          $t0, 0x4C($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 76)));
label_3538:
    // 0x3538: 0x21e1004  sllv        $v0, $fp, $s0
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 30), GPR_U32(ctx, 16) & 0x1F));
label_353c:
    // 0x353c: 0x481024  and         $v0, $v0, $t0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 8));
label_3540:
    // 0x3540: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
label_3544:
    if (ctx->pc == 0x3544u) {
        // 0x3544: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        ctx->pc = 0x3548u;
        goto label_3548;
    }
    ctx->pc = 0x3540u;
    {
        const bool branch_taken_0x3540 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3544: 0x101040  sll         $v0, $s0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x3540) {
            ctx->pc = 0x3574u;
            goto label_3574;
        }
    }
    ctx->pc = 0x3548u;
label_3548:
    // 0x3548: 0x96a40002  lhu         $a0, 0x2($s5)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 21), 2)));
label_354c:
    // 0x354c: 0x0  nop
    // NOP
label_3550:
    // 0x3550: 0x3084ffc1  andi        $a0, $a0, 0xFFC1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65473);
label_3554:
    // 0x3554: 0x822025  or          $a0, $a0, $v0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
label_3558:
    // 0x3558: 0xc000e08  jal         func_003820
label_355c:
    if (ctx->pc == 0x355Cu) {
        // 0x355c: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3560u;
        goto label_3560;
    }
    ctx->pc = 0x3558u;
    SET_GPR_U32(ctx, 31, 0x3560u);
    // 0x355c: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3820u;
    goto label_3820;
    ctx->pc = 0x3560u;
label_3560:
    // 0x3560: 0x12c00002  beqz        $s6, . + 4 + (0x2 << 2)
label_3564:
    if (ctx->pc == 0x3564u) {
        // 0x3564: 0x40a021  addu        $s4, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x3568u;
        goto label_3568;
    }
    ctx->pc = 0x3560u;
    {
        const bool branch_taken_0x3560 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x3564: 0x40a021  addu        $s4, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        if (branch_taken_0x3560) {
            ctx->pc = 0x356Cu;
            goto label_356c;
        }
    }
    ctx->pc = 0x3568u;
label_3568:
    // 0x3568: 0xae340000  sw          $s4, 0x0($s1)
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 20));
label_356c:
    // 0x356c: 0x26310004  addiu       $s1, $s1, 0x4
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_3570:
    // 0x3570: 0x26730001  addiu       $s3, $s3, 0x1
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_3574:
    // 0x3574: 0x26100001  addiu       $s0, $s0, 0x1
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
label_3578:
    // 0x3578: 0x2a020018  slti        $v0, $s0, 0x18
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)24) ? 1 : 0);
label_357c:
    // 0x357c: 0x1440ffed  bnez        $v0, . + 4 + (-0x13 << 2)
label_3580:
    if (ctx->pc == 0x3580u) {
        ctx->pc = 0x3584u;
        goto label_3584;
    }
    ctx->pc = 0x357Cu;
    {
        const bool branch_taken_0x357c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x357c) {
            ctx->pc = 0x3534u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3534;
        }
    }
    ctx->pc = 0x3584u;
label_3584:
    // 0x3584: 0x8000d86  j           func_003618
label_3588:
    if (ctx->pc == 0x3588u) {
        // 0x3588: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
        ctx->pc = 0x358Cu;
        goto label_358c;
    }
    ctx->pc = 0x3584u;
    // 0x3588: 0x2673ffff  addiu       $s3, $s3, -0x1 (Delay Slot)
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4294967295));
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x358Cu;
label_358c:
    // 0x358c: 0x96440002  lhu         $a0, 0x2($s2)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_3590:
    // 0x3590: 0x96450004  lhu         $a1, 0x4($s2)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 4)));
label_3594:
    // 0x3594: 0xc000f37  jal         func_003CDC
label_3598:
    if (ctx->pc == 0x3598u) {
        ctx->pc = 0x359Cu;
        goto label_359c;
    }
    ctx->pc = 0x3594u;
    SET_GPR_U32(ctx, 31, 0x359Cu);
    ctx->pc = 0x3CDCu;
    goto label_3cdc;
    ctx->pc = 0x359Cu;
label_359c:
    // 0x359c: 0x8000d86  j           func_003618
label_35a0:
    if (ctx->pc == 0x35A0u) {
        ctx->pc = 0x35A4u;
        goto label_35a4;
    }
    ctx->pc = 0x359Cu;
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x35A4u;
label_35a4:
    // 0x35a4: 0x96440002  lhu         $a0, 0x2($s2)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_35a8:
    // 0x35a8: 0xc000f64  jal         func_003D90
label_35ac:
    if (ctx->pc == 0x35ACu) {
        ctx->pc = 0x35B0u;
        goto label_35b0;
    }
    ctx->pc = 0x35A8u;
    SET_GPR_U32(ctx, 31, 0x35B0u);
    ctx->pc = 0x3D90u;
    goto label_3d90;
    ctx->pc = 0x35B0u;
label_35b0:
    // 0x35b0: 0x8000d86  j           func_003618
label_35b4:
    if (ctx->pc == 0x35B4u) {
        // 0x35b4: 0x3054ffff  andi        $s4, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x35B8u;
        goto label_35b8;
    }
    ctx->pc = 0x35B0u;
    // 0x35b4: 0x3054ffff  andi        $s4, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x35B8u;
label_35b8:
    // 0x35b8: 0x8e430004  lw          $v1, 0x4($s2)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_35bc:
    // 0x35bc: 0x96420002  lhu         $v0, 0x2($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_35c0:
    // 0x35c0: 0x8000d86  j           func_003618
label_35c4:
    if (ctx->pc == 0x35C4u) {
        // 0x35c4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = 0x35C8u;
        goto label_35c8;
    }
    ctx->pc = 0x35C0u;
    // 0x35c4: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x35C8u;
label_35c8:
    // 0x35c8: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_35cc:
    // 0x35cc: 0x24a55990  addiu       $a1, $a1, 0x5990
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 22928));
label_35d0:
    // 0x35d0: 0x8e440004  lw          $a0, 0x4($s2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_35d4:
    // 0x35d4: 0x96420002  lhu         $v0, 0x2($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_35d8:
    // 0x35d8: 0x0  nop
    // NOP
label_35dc:
    // 0x35dc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_35e0:
    // 0x35e0: 0xac225990  sw          $v0, 0x5990($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22928), GPR_U32(ctx, 2));
label_35e4:
    // 0x35e4: 0x8000d7e  j           func_0035F8
label_35e8:
    if (ctx->pc == 0x35E8u) {
        // 0x35e8: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->pc = 0x35ECu;
        goto label_35ec;
    }
    ctx->pc = 0x35E4u;
    // 0x35e8: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x35F8u;
    goto label_35f8;
    ctx->pc = 0x35ECu;
label_35ec:
    // 0x35ec: 0x8e440004  lw          $a0, 0x4($s2)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_35f0:
    // 0x35f0: 0x96460002  lhu         $a2, 0x2($s2)
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
label_35f4:
    // 0x35f4: 0x2c02821  addu        $a1, $s6, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 0)));
label_35f8:
    // 0x35f8: 0xc000c0c  jal         func_003030
label_35fc:
    if (ctx->pc == 0x35FCu) {
        ctx->pc = 0x3600u;
        goto label_3600;
    }
    ctx->pc = 0x35F8u;
    SET_GPR_U32(ctx, 31, 0x3600u);
    ctx->pc = 0x3030u;
    goto label_3030;
    ctx->pc = 0x3600u;
label_3600:
    // 0x3600: 0x8000d86  j           func_003618
label_3604:
    if (ctx->pc == 0x3604u) {
        // 0x3604: 0x40a021  addu        $s4, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x3608u;
        goto label_3608;
    }
    ctx->pc = 0x3600u;
    // 0x3604: 0x40a021  addu        $s4, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x3618u;
    goto label_3618;
    ctx->pc = 0x3608u;
label_3608:
    // 0x3608: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_360c:
    // 0x360c: 0x8fa30010  lw          $v1, 0x10($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_3610:
    // 0x3610: 0x8000d94  j           func_003650
label_3614:
    if (ctx->pc == 0x3614u) {
        // 0x3614: 0x171027  nor         $v0, $zero, $s7 (Delay Slot)
        SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 23)));
        ctx->pc = 0x3618u;
        goto label_3618;
    }
    ctx->pc = 0x3610u;
    // 0x3614: 0x171027  nor         $v0, $zero, $s7 (Delay Slot)
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 23)));
    ctx->pc = 0x3650u;
    goto label_3650;
    ctx->pc = 0x3618u;
label_3618:
    // 0x3618: 0x12c00003  beqz        $s6, . + 4 + (0x3 << 2)
label_361c:
    if (ctx->pc == 0x361Cu) {
        // 0x361c: 0x131080  sll         $v0, $s3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
        ctx->pc = 0x3620u;
        goto label_3620;
    }
    ctx->pc = 0x3618u;
    {
        const bool branch_taken_0x3618 = (GPR_U64(ctx, 22) == GPR_U64(ctx, 0));
        // 0x361c: 0x131080  sll         $v0, $s3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 19), 2));
        if (branch_taken_0x3618) {
            ctx->pc = 0x3628u;
            goto label_3628;
        }
    }
    ctx->pc = 0x3620u;
label_3620:
    // 0x3620: 0x561021  addu        $v0, $v0, $s6
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
label_3624:
    // 0x3624: 0xac540000  sw          $s4, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 20));
label_3628:
    // 0x3628: 0x26520008  addiu       $s2, $s2, 0x8
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 8));
label_362c:
    // 0x362c: 0x26f70001  addiu       $s7, $s7, 0x1
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 1));
label_3630:
    // 0x3630: 0x8fa80048  lw          $t0, 0x48($sp)
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 72)));
label_3634:
    // 0x3634: 0x0  nop
    // NOP
label_3638:
    // 0x3638: 0x2e8102b  sltu        $v0, $s7, $t0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 23) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
label_363c:
    // 0x363c: 0x1440ff39  bnez        $v0, . + 4 + (-0xC7 << 2)
label_3640:
    if (ctx->pc == 0x3640u) {
        // 0x3640: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->pc = 0x3644u;
        goto label_3644;
    }
    ctx->pc = 0x363Cu;
    {
        const bool branch_taken_0x363c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3640: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        if (branch_taken_0x363c) {
            ctx->pc = 0x3324u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3324;
        }
    }
    ctx->pc = 0x3644u;
label_3644:
    // 0x3644: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_3648:
    // 0x3648: 0x8fa30010  lw          $v1, 0x10($sp)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_364c:
    // 0x364c: 0x2601021  addu        $v0, $s3, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 0)));
label_3650:
    // 0x3650: 0xafa30014  sw          $v1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
label_3654:
    // 0x3654: 0x8fbf003c  lw          $ra, 0x3C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
label_3658:
    // 0x3658: 0x8fbe0038  lw          $fp, 0x38($sp)
    SET_GPR_S32(ctx, 30, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
label_365c:
    // 0x365c: 0x8fb70034  lw          $s7, 0x34($sp)
    SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_3660:
    // 0x3660: 0x8fb60030  lw          $s6, 0x30($sp)
    SET_GPR_S32(ctx, 22, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_3664:
    // 0x3664: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_3668:
    // 0x3668: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_366c:
    // 0x366c: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_3670:
    // 0x3670: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_3674:
    // 0x3674: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_3678:
    // 0x3678: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_367c:
    // 0x367c: 0x3e00008  jr          $ra
label_3680:
    if (ctx->pc == 0x3680u) {
        // 0x3680: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x3684u;
        goto label_3684;
    }
    ctx->pc = 0x367Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3680: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x367Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3684u;
label_3684:
    // 0x3684: 0x0  nop
    // NOP
label_3688:
    // 0x3688: 0x0  nop
    // NOP
label_368c:
    // 0x368c: 0x0  nop
    // NOP
label_3690:
    // 0x3690: 0x30860001  andi        $a2, $a0, 0x1
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_3694:
    // 0x3694: 0x30830080  andi        $v1, $a0, 0x80
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)128);
label_3698:
    // 0x3698: 0x3182b  sltu        $v1, $zero, $v1
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
label_369c:
    // 0x369c: 0x31140  sll         $v0, $v1, 5
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
label_36a0:
    // 0x36a0: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_36a4:
    // 0x36a4: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_36a8:
    // 0x36a8: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_36ac:
    // 0x36ac: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_36b0:
    // 0x36b0: 0x24030400  addiu       $v1, $zero, 0x400
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_36b4:
    // 0x36b4: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_36b8:
    // 0x36b8: 0xc30018  mult        $zero, $a2, $v1
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
label_36bc:
    // 0x36bc: 0x41182  srl         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
label_36c0:
    // 0x36c0: 0x304203fc  andi        $v0, $v0, 0x3FC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1020);
label_36c4:
    // 0x36c4: 0x3084003e  andi        $a0, $a0, 0x3E
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)62);
label_36c8:
    // 0x36c8: 0x420c0  sll         $a0, $a0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
label_36cc:
    // 0x36cc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_36d0:
    // 0x36d0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_36d4:
    // 0x36d4: 0x8c224980  lw          $v0, 0x4980($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18816)));
label_36d8:
    // 0x36d8: 0x3812  mflo        $a3
    SET_GPR_U64(ctx, 7, ctx->lo);
label_36dc:
    // 0x36dc: 0x471021  addu        $v0, $v0, $a3
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
label_36e0:
    // 0x36e0: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_36e4:
    // 0x36e4: 0x3e00008  jr          $ra
label_36e8:
    if (ctx->pc == 0x36E8u) {
        // 0x36e8: 0xa4450000  sh          $a1, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 5));
        ctx->pc = 0x36ECu;
        goto label_36ec;
    }
    ctx->pc = 0x36E4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x36e8: 0xa4450000  sh          $a1, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x36E4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x36ECu;
label_36ec:
    // 0x36ec: 0x30850001  andi        $a1, $a0, 0x1
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_36f0:
    // 0x36f0: 0x30830080  andi        $v1, $a0, 0x80
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)128);
label_36f4:
    // 0x36f4: 0x3182b  sltu        $v1, $zero, $v1
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
label_36f8:
    // 0x36f8: 0x31140  sll         $v0, $v1, 5
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
label_36fc:
    // 0x36fc: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_3700:
    // 0x3700: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_3704:
    // 0x3704: 0x431023  subu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_3708:
    // 0x3708: 0x210c0  sll         $v0, $v0, 3
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
label_370c:
    // 0x370c: 0x24030400  addiu       $v1, $zero, 0x400
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
label_3710:
    // 0x3710: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_3714:
    // 0x3714: 0xa30018  mult        $zero, $a1, $v1
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
label_3718:
    // 0x3718: 0x41182  srl         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
label_371c:
    // 0x371c: 0x304203fc  andi        $v0, $v0, 0x3FC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1020);
label_3720:
    // 0x3720: 0x3084003e  andi        $a0, $a0, 0x3E
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)62);
label_3724:
    // 0x3724: 0x420c0  sll         $a0, $a0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
label_3728:
    // 0x3728: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_372c:
    // 0x372c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_3730:
    // 0x3730: 0x8c224980  lw          $v0, 0x4980($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18816)));
label_3734:
    // 0x3734: 0x3012  mflo        $a2
    SET_GPR_U64(ctx, 6, ctx->lo);
label_3738:
    // 0x3738: 0x461021  addu        $v0, $v0, $a2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_373c:
    // 0x373c: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_3740:
    // 0x3740: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_3744:
    // 0x3744: 0x3e00008  jr          $ra
label_3748:
    if (ctx->pc == 0x3748u) {
        ctx->pc = 0x374Cu;
        goto label_374c;
    }
    ctx->pc = 0x3744u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3744u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x374Cu;
label_374c:
    // 0x374c: 0x41182  srl         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
label_3750:
    // 0x3750: 0x304203fc  andi        $v0, $v0, 0x3FC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1020);
label_3754:
    // 0x3754: 0x30840001  andi        $a0, $a0, 0x1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_3758:
    // 0x3758: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_375c:
    // 0x375c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_3760:
    // 0x3760: 0x8c224980  lw          $v0, 0x4980($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18816)));
label_3764:
    // 0x3764: 0x42280  sll         $a0, $a0, 10
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 10));
label_3768:
    // 0x3768: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_376c:
    // 0x376c: 0xa4450000  sh          $a1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 5));
label_3770:
    // 0x3770: 0x24420002  addiu       $v0, $v0, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2));
label_3774:
    // 0x3774: 0x52c02  srl         $a1, $a1, 16
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 16));
label_3778:
    // 0x3778: 0x30a500ff  andi        $a1, $a1, 0xFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
label_377c:
    // 0x377c: 0x3e00008  jr          $ra
label_3780:
    if (ctx->pc == 0x3780u) {
        // 0x3780: 0xa4450000  sh          $a1, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 5));
        ctx->pc = 0x3784u;
        goto label_3784;
    }
    ctx->pc = 0x377Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3780: 0xa4450000  sh          $a1, 0x0($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x377Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3784u;
label_3784:
    // 0x3784: 0x41182  srl         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
label_3788:
    // 0x3788: 0x304203fc  andi        $v0, $v0, 0x3FC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1020);
label_378c:
    // 0x378c: 0x30840001  andi        $a0, $a0, 0x1
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_3790:
    // 0x3790: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3794:
    // 0x3794: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_3798:
    // 0x3798: 0x8c224980  lw          $v0, 0x4980($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18816)));
label_379c:
    // 0x379c: 0x42280  sll         $a0, $a0, 10
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 10));
label_37a0:
    // 0x37a0: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_37a4:
    // 0x37a4: 0x94830000  lhu         $v1, 0x0($a0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_37a8:
    // 0x37a8: 0x94820002  lhu         $v0, 0x2($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
label_37ac:
    // 0x37ac: 0x0  nop
    // NOP
label_37b0:
    // 0x37b0: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
label_37b4:
    // 0x37b4: 0x3e00008  jr          $ra
label_37b8:
    if (ctx->pc == 0x37B8u) {
        // 0x37b8: 0x621025  or          $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->pc = 0x37BCu;
        goto label_37bc;
    }
    ctx->pc = 0x37B4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x37b8: 0x621025  or          $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x37B4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x37BCu;
label_37bc:
    // 0x37bc: 0xa03021  addu        $a2, $a1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_37c0:
    // 0x37c0: 0x41182  srl         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
label_37c4:
    // 0x37c4: 0x304203fc  andi        $v0, $v0, 0x3FC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1020);
label_37c8:
    // 0x37c8: 0x30830001  andi        $v1, $a0, 0x1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_37cc:
    // 0x37cc: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_37d0:
    // 0x37d0: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_37d4:
    // 0x37d4: 0x8ca54980  lw          $a1, 0x4980($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18816)));
label_37d8:
    // 0x37d8: 0x31a80  sll         $v1, $v1, 10
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 10));
label_37dc:
    // 0x37dc: 0xa32821  addu        $a1, $a1, $v1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_37e0:
    // 0x37e0: 0x3083003e  andi        $v1, $a0, 0x3E
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)62);
label_37e4:
    // 0x37e4: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
label_37e8:
    // 0x37e8: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_37ec:
    // 0x37ec: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_37f0:
    // 0x37f0: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_37f4:
    // 0x37f4: 0x61442  srl         $v0, $a2, 17
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 17));
label_37f8:
    // 0x37f8: 0x3084ff00  andi        $a0, $a0, 0xFF00
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
label_37fc:
    // 0x37fc: 0xa4a20000  sh          $v0, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
label_3800:
    // 0x3800: 0x24021d00  addiu       $v0, $zero, 0x1D00
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7424));
label_3804:
    // 0x3804: 0x10820004  beq         $a0, $v0, . + 4 + (0x4 << 2)
label_3808:
    if (ctx->pc == 0x3808u) {
        // 0x3808: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->pc = 0x380Cu;
        goto label_380c;
    }
    ctx->pc = 0x3804u;
    {
        const bool branch_taken_0x3804 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x3808: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        if (branch_taken_0x3804) {
            ctx->pc = 0x3818u;
            goto label_3818;
        }
    }
    ctx->pc = 0x380Cu;
label_380c:
    // 0x380c: 0x61042  srl         $v0, $a2, 1
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 6), 1));
label_3810:
    // 0x3810: 0x3042fff8  andi        $v0, $v0, 0xFFF8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65528);
label_3814:
    // 0x3814: 0xa4a20000  sh          $v0, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
label_3818:
    // 0x3818: 0x3e00008  jr          $ra
label_381c:
    if (ctx->pc == 0x381Cu) {
        ctx->pc = 0x3820u;
        goto label_3820;
    }
    ctx->pc = 0x3818u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3818u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3820u;
label_3820:
    // 0x3820: 0x3c070001  lui         $a3, 0x1
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)1 << 16));
label_3824:
    // 0x3824: 0x41182  srl         $v0, $a0, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 6));
label_3828:
    // 0x3828: 0x304203fc  andi        $v0, $v0, 0x3FC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1020);
label_382c:
    // 0x382c: 0x30830001  andi        $v1, $a0, 0x1
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_3830:
    // 0x3830: 0x31a80  sll         $v1, $v1, 10
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 10));
label_3834:
    // 0x3834: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_3838:
    // 0x3838: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_383c:
    // 0x383c: 0x8ca54980  lw          $a1, 0x4980($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 18816)));
label_3840:
    // 0x3840: 0x34e7ffff  ori         $a3, $a3, 0xFFFF
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)65535);
label_3844:
    // 0x3844: 0xa32821  addu        $a1, $a1, $v1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_3848:
    // 0x3848: 0x3083003e  andi        $v1, $a0, 0x3E
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)62);
label_384c:
    // 0x384c: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
label_3850:
    // 0x3850: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_3854:
    // 0x3854: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_3858:
    // 0x3858: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_385c:
    // 0x385c: 0x94a20000  lhu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
label_3860:
    // 0x3860: 0x3084ff00  andi        $a0, $a0, 0xFF00
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
label_3864:
    // 0x3864: 0x23440  sll         $a2, $v0, 17
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 17));
label_3868:
    // 0x3868: 0x24021d00  addiu       $v0, $zero, 0x1D00
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7424));
label_386c:
    // 0x386c: 0x10820012  beq         $a0, $v0, . + 4 + (0x12 << 2)
label_3870:
    if (ctx->pc == 0x3870u) {
        ctx->pc = 0x3874u;
        goto label_3874;
    }
    ctx->pc = 0x386Cu;
    {
        const bool branch_taken_0x386c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x386c) {
            ctx->pc = 0x38B8u;
            goto label_38b8;
        }
    }
    ctx->pc = 0x3874u;
label_3874:
    // 0x3874: 0x94a20002  lhu         $v0, 0x2($a1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
label_3878:
    // 0x3878: 0x0  nop
    // NOP
label_387c:
    // 0x387c: 0x23840  sll         $a3, $v0, 1
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_3880:
    // 0x3880: 0x24022100  addiu       $v0, $zero, 0x2100
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8448));
label_3884:
    // 0x3884: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
label_3888:
    if (ctx->pc == 0x3888u) {
        // 0x3888: 0x24022200  addiu       $v0, $zero, 0x2200 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8704));
        ctx->pc = 0x388Cu;
        goto label_388c;
    }
    ctx->pc = 0x3884u;
    {
        const bool branch_taken_0x3884 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        // 0x3888: 0x24022200  addiu       $v0, $zero, 0x2200 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8704));
        if (branch_taken_0x3884) {
            ctx->pc = 0x3894u;
            goto label_3894;
        }
    }
    ctx->pc = 0x388Cu;
label_388c:
    // 0x388c: 0x1482000a  bne         $a0, $v0, . + 4 + (0xA << 2)
label_3890:
    if (ctx->pc == 0x3890u) {
        ctx->pc = 0x3894u;
        goto label_3894;
    }
    ctx->pc = 0x388Cu;
    {
        const bool branch_taken_0x388c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x388c) {
            ctx->pc = 0x38B8u;
            goto label_38b8;
        }
    }
    ctx->pc = 0x3894u;
label_3894:
    // 0x3894: 0x94a20000  lhu         $v0, 0x0($a1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
label_3898:
    // 0x3898: 0x94a30002  lhu         $v1, 0x2($a1)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
label_389c:
    // 0x389c: 0x21440  sll         $v0, $v0, 17
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 17));
label_38a0:
    // 0x38a0: 0x14c20003  bne         $a2, $v0, . + 4 + (0x3 << 2)
label_38a4:
    if (ctx->pc == 0x38A4u) {
        // 0x38a4: 0x31840  sll         $v1, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
        ctx->pc = 0x38A8u;
        goto label_38a8;
    }
    ctx->pc = 0x38A0u;
    {
        const bool branch_taken_0x38a0 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        // 0x38a4: 0x31840  sll         $v1, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
        if (branch_taken_0x38a0) {
            ctx->pc = 0x38B0u;
            goto label_38b0;
        }
    }
    ctx->pc = 0x38A8u;
label_38a8:
    // 0x38a8: 0x14e30003  bne         $a3, $v1, . + 4 + (0x3 << 2)
label_38ac:
    if (ctx->pc == 0x38ACu) {
        ctx->pc = 0x38B0u;
        goto label_38b0;
    }
    ctx->pc = 0x38A8u;
    {
        const bool branch_taken_0x38a8 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        if (branch_taken_0x38a8) {
            ctx->pc = 0x38B8u;
            goto label_38b8;
        }
    }
    ctx->pc = 0x38B0u;
label_38b0:
    // 0x38b0: 0x403021  addu        $a2, $v0, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
label_38b4:
    // 0x38b4: 0x603821  addu        $a3, $v1, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_38b8:
    // 0x38b8: 0x3e00008  jr          $ra
label_38bc:
    if (ctx->pc == 0x38BCu) {
        // 0x38bc: 0xc71025  or          $v0, $a2, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
        ctx->pc = 0x38C0u;
        goto label_38c0;
    }
    ctx->pc = 0x38B8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x38bc: 0xc71025  or          $v0, $a2, $a3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 7));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x38B8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x38C0u;
label_38c0:
    // 0x38c0: 0x804021  addu        $t0, $a0, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_38c4:
    // 0x38c4: 0x73c00  sll         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_38c8:
    // 0x38c8: 0x73c03  sra         $a3, $a3, 16
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 16));
label_38cc:
    // 0x38cc: 0x30a5ffff  andi        $a1, $a1, 0xFFFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
label_38d0:
    // 0x38d0: 0xe53821  addu        $a3, $a3, $a1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
label_38d4:
    // 0x38d4: 0x4e10002  bgez        $a3, . + 4 + (0x2 << 2)
label_38d8:
    if (ctx->pc == 0x38D8u) {
        // 0x38d8: 0xe01821  addu        $v1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = 0x38DCu;
        goto label_38dc;
    }
    ctx->pc = 0x38D4u;
    {
        const bool branch_taken_0x38d4 = (GPR_S32(ctx, 7) >= 0);
        // 0x38d8: 0xe01821  addu        $v1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        if (branch_taken_0x38d4) {
            ctx->pc = 0x38E0u;
            goto label_38e0;
        }
    }
    ctx->pc = 0x38DCu;
label_38dc:
    // 0x38dc: 0x24e3007f  addiu       $v1, $a3, 0x7F
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 127));
label_38e0:
    // 0x38e0: 0x3c042aaa  lui         $a0, 0x2AAA
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)10922 << 16));
label_38e4:
    // 0x38e4: 0x3484aaab  ori         $a0, $a0, 0xAAAB
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)43691);
label_38e8:
    // 0x38e8: 0x319c3  sra         $v1, $v1, 7
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 7));
label_38ec:
    // 0x38ec: 0xc31021  addu        $v0, $a2, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
label_38f0:
    // 0x38f0: 0x481023  subu        $v0, $v0, $t0
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
label_38f4:
    // 0x38f4: 0x21400  sll         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
label_38f8:
    // 0x38f8: 0x22c03  sra         $a1, $v0, 16
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 2), 16));
label_38fc:
    // 0x38fc: 0xa40018  mult        $zero, $a1, $a0
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
label_3900:
    // 0x3900: 0x603021  addu        $a2, $v1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 0)));
label_3904:
    // 0x3904: 0x619c0  sll         $v1, $a2, 7
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 7));
label_3908:
    // 0x3908: 0xe33823  subu        $a3, $a3, $v1
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
label_390c:
    // 0x390c: 0x217c3  sra         $v0, $v0, 31
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 31));
label_3910:
    // 0x3910: 0x4810  mfhi        $t1
    SET_GPR_U64(ctx, 9, ctx->hi);
label_3914:
    // 0x3914: 0x91843  sra         $v1, $t1, 1
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 9), 1));
label_3918:
    // 0x3918: 0x621823  subu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_391c:
    // 0x391c: 0x2468fffe  addiu       $t0, $v1, -0x2
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967294));
label_3920:
    // 0x3920: 0x31040  sll         $v0, $v1, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
label_3924:
    // 0x3924: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_3928:
    // 0x3928: 0x21080  sll         $v0, $v0, 2
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_392c:
    // 0x392c: 0xa22823  subu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_3930:
    // 0x3930: 0x51400  sll         $v0, $a1, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
label_3934:
    // 0x3934: 0x21403  sra         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
label_3938:
    // 0x3938: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
label_393c:
    if (ctx->pc == 0x393Cu) {
        // 0x393c: 0xa02021  addu        $a0, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        ctx->pc = 0x3940u;
        goto label_3940;
    }
    ctx->pc = 0x3938u;
    {
        const bool branch_taken_0x3938 = (GPR_S32(ctx, 2) < 0);
        // 0x393c: 0xa02021  addu        $a0, $a1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
        if (branch_taken_0x3938) {
            ctx->pc = 0x3950u;
            goto label_3950;
        }
    }
    ctx->pc = 0x3940u;
label_3940:
    // 0x3940: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
label_3944:
    if (ctx->pc == 0x3944u) {
        ctx->pc = 0x3948u;
        goto label_3948;
    }
    ctx->pc = 0x3940u;
    {
        const bool branch_taken_0x3940 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3940) {
            ctx->pc = 0x3958u;
            goto label_3958;
        }
    }
    ctx->pc = 0x3948u;
label_3948:
    // 0x3948: 0x4e1000b  bgez        $a3, . + 4 + (0xB << 2)
label_394c:
    if (ctx->pc == 0x394Cu) {
        // 0x394c: 0x41400  sll         $v0, $a0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
        ctx->pc = 0x3950u;
        goto label_3950;
    }
    ctx->pc = 0x3948u;
    {
        const bool branch_taken_0x3948 = (GPR_S32(ctx, 7) >= 0);
        // 0x394c: 0x41400  sll         $v0, $a0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
        if (branch_taken_0x3948) {
            ctx->pc = 0x3978u;
            goto label_3978;
        }
    }
    ctx->pc = 0x3950u;
label_3950:
    // 0x3950: 0x24a4000c  addiu       $a0, $a1, 0xC
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 12));
label_3954:
    // 0x3954: 0x2468fffd  addiu       $t0, $v1, -0x3
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967293));
label_3958:
    // 0x3958: 0x4e10007  bgez        $a3, . + 4 + (0x7 << 2)
label_395c:
    if (ctx->pc == 0x395Cu) {
        // 0x395c: 0x41400  sll         $v0, $a0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
        ctx->pc = 0x3960u;
        goto label_3960;
    }
    ctx->pc = 0x3958u;
    {
        const bool branch_taken_0x3958 = (GPR_S32(ctx, 7) >= 0);
        // 0x395c: 0x41400  sll         $v0, $a0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
        if (branch_taken_0x3958) {
            ctx->pc = 0x3978u;
            goto label_3978;
        }
    }
    ctx->pc = 0x3960u;
label_3960:
    // 0x3960: 0x2482ffff  addiu       $v0, $a0, -0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
label_3964:
    // 0x3964: 0x462021  addu        $a0, $v0, $a2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_3968:
    // 0x3968: 0x24c20001  addiu       $v0, $a2, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_396c:
    // 0x396c: 0x211c0  sll         $v0, $v0, 7
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 7));
label_3970:
    // 0x3970: 0xe23821  addu        $a3, $a3, $v0
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
label_3974:
    // 0x3974: 0x41400  sll         $v0, $a0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
label_3978:
    // 0x3978: 0x213c3  sra         $v0, $v0, 15
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 15));
label_397c:
    // 0x397c: 0x71840  sll         $v1, $a3, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
label_3980:
    // 0x3980: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_3984:
    // 0x3984: 0x822021  addu        $a0, $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_3988:
    // 0x3988: 0x948451a0  lhu         $a0, 0x51A0($a0)
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 20896)));
label_398c:
    // 0x398c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3990:
    // 0x3990: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_3994:
    // 0x3994: 0x944251b8  lhu         $v0, 0x51B8($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 20920)));
label_3998:
    // 0x3998: 0x0  nop
    // NOP
label_399c:
    // 0x399c: 0x820018  mult        $zero, $a0, $v0
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
label_39a0:
    // 0x39a0: 0x81400  sll         $v0, $t0, 16
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
label_39a4:
    // 0x39a4: 0x21403  sra         $v0, $v0, 16
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
label_39a8:
    // 0x39a8: 0x4812  mflo        $t1
    SET_GPR_U64(ctx, 9, ctx->lo);
label_39ac:
    // 0x39ac: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
label_39b0:
    if (ctx->pc == 0x39B0u) {
        // 0x39b0: 0x92c03  sra         $a1, $t1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 9), 16));
        ctx->pc = 0x39B4u;
        goto label_39b4;
    }
    ctx->pc = 0x39ACu;
    {
        const bool branch_taken_0x39ac = (GPR_S32(ctx, 2) >= 0);
        // 0x39b0: 0x92c03  sra         $a1, $t1, 16 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 9), 16));
        if (branch_taken_0x39ac) {
            ctx->pc = 0x39CCu;
            goto label_39cc;
        }
    }
    ctx->pc = 0x39B4u;
label_39b4:
    // 0x39b4: 0x22023  negu        $a0, $v0
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
label_39b8:
    // 0x39b8: 0x2483ffff  addiu       $v1, $a0, -0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
label_39bc:
    // 0x39bc: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_39c0:
    // 0x39c0: 0x621004  sllv        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 3) & 0x1F));
label_39c4:
    // 0x39c4: 0xa22821  addu        $a1, $a1, $v0
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_39c8:
    // 0x39c8: 0x852806  srlv        $a1, $a1, $a0
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), GPR_U32(ctx, 4) & 0x1F));
label_39cc:
    // 0x39cc: 0x3e00008  jr          $ra
label_39d0:
    if (ctx->pc == 0x39D0u) {
        // 0x39d0: 0x30a2ffff  andi        $v0, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x39D4u;
        goto label_39d4;
    }
    ctx->pc = 0x39CCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x39d0: 0x30a2ffff  andi        $v0, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x39CCu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x39D4u;
label_39d4:
    // 0x39d4: 0x4821  addu        $t1, $zero, $zero
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_39d8:
    // 0x39d8: 0x1205021  addu        $t2, $t1, $zero
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 0)));
label_39dc:
    // 0x39dc: 0x30c2ffff  andi        $v0, $a2, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
label_39e0:
    // 0x39e0: 0x2c424000  sltiu       $v0, $v0, 0x4000
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)16384) ? 1 : 0);
label_39e4:
    // 0x39e4: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
label_39e8:
    if (ctx->pc == 0x39E8u) {
        // 0x39e8: 0x1204021  addu        $t0, $t1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 0)));
        ctx->pc = 0x39ECu;
        goto label_39ec;
    }
    ctx->pc = 0x39E4u;
    {
        const bool branch_taken_0x39e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x39e8: 0x1204021  addu        $t0, $t1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 0)));
        if (branch_taken_0x39e4) {
            ctx->pc = 0x39F0u;
            goto label_39f0;
        }
    }
    ctx->pc = 0x39ECu;
label_39ec:
    // 0x39ec: 0x24063fff  addiu       $a2, $zero, 0x3FFF
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16383));
label_39f0:
    // 0x39f0: 0x3821  addu        $a3, $zero, $zero
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_39f4:
    // 0x39f4: 0x30c3ffff  andi        $v1, $a2, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
label_39f8:
    // 0x39f8: 0xe31007  srav        $v0, $v1, $a3
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 7) & 0x1F));
label_39fc:
    // 0x39fc: 0x30420001  andi        $v0, $v0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
label_3a00:
    // 0x3a00: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
label_3a04:
    if (ctx->pc == 0x3A04u) {
        ctx->pc = 0x3A08u;
        goto label_3a08;
    }
    ctx->pc = 0x3A00u;
    {
        const bool branch_taken_0x3a00 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3a00) {
            ctx->pc = 0x3A0Cu;
            goto label_3a0c;
        }
    }
    ctx->pc = 0x3A08u;
label_3a08:
    // 0x3a08: 0xe04821  addu        $t1, $a3, $zero
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
label_3a0c:
    // 0x3a0c: 0x24e70001  addiu       $a3, $a3, 0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_3a10:
    // 0x3a10: 0x28e2000e  slti        $v0, $a3, 0xE
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)14) ? 1 : 0);
label_3a14:
    // 0x3a14: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
label_3a18:
    if (ctx->pc == 0x3A18u) {
        // 0x3a18: 0xe31007  srav        $v0, $v1, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 7) & 0x1F));
        ctx->pc = 0x3A1Cu;
        goto label_3a1c;
    }
    ctx->pc = 0x3A14u;
    {
        const bool branch_taken_0x3a14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3a18: 0xe31007  srav        $v0, $v1, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), GPR_U32(ctx, 7) & 0x1F));
        if (branch_taken_0x3a14) {
            ctx->pc = 0x39FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_39fc;
        }
    }
    ctx->pc = 0x3A1Cu;
label_3a1c:
    // 0x3a1c: 0x30c3ffff  andi        $v1, $a2, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
label_3a20:
    // 0x3a20: 0x2402000f  addiu       $v0, $zero, 0xF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_3a24:
    // 0x3a24: 0x491023  subu        $v0, $v0, $t1
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
label_3a28:
    // 0x3a28: 0x433004  sllv        $a2, $v1, $v0
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 2) & 0x1F));
label_3a2c:
    // 0x3a2c: 0x2407000b  addiu       $a3, $zero, 0xB
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
label_3a30:
    // 0x3a30: 0x30c3ffff  andi        $v1, $a2, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
label_3a34:
    // 0x3a34: 0x71040  sll         $v0, $a3, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
label_3a38:
    // 0x3a38: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3a3c:
    // 0x3a3c: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_3a40:
    // 0x3a40: 0x942251a0  lhu         $v0, 0x51A0($at)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20896)));
label_3a44:
    // 0x3a44: 0x0  nop
    // NOP
label_3a48:
    // 0x3a48: 0x62102b  sltu        $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_3a4c:
    // 0x3a4c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_3a50:
    if (ctx->pc == 0x3A50u) {
        ctx->pc = 0x3A54u;
        goto label_3a54;
    }
    ctx->pc = 0x3A4Cu;
    {
        const bool branch_taken_0x3a4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3a4c) {
            ctx->pc = 0x3A5Cu;
            goto label_3a5c;
        }
    }
    ctx->pc = 0x3A54u;
label_3a54:
    // 0x3a54: 0x8000e9a  j           func_003A68
label_3a58:
    if (ctx->pc == 0x3A58u) {
        // 0x3a58: 0xe05021  addu        $t2, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = 0x3A5Cu;
        goto label_3a5c;
    }
    ctx->pc = 0x3A54u;
    // 0x3a58: 0xe05021  addu        $t2, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x3A68u;
    goto label_3a68;
    ctx->pc = 0x3A5Cu;
label_3a5c:
    // 0x3a5c: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
label_3a60:
    // 0x3a60: 0x4e1fff5  bgez        $a3, . + 4 + (-0xB << 2)
label_3a64:
    if (ctx->pc == 0x3A64u) {
        // 0x3a64: 0x71040  sll         $v0, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        ctx->pc = 0x3A68u;
        goto label_3a68;
    }
    ctx->pc = 0x3A60u;
    {
        const bool branch_taken_0x3a60 = (GPR_S32(ctx, 7) >= 0);
        // 0x3a64: 0x71040  sll         $v0, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        if (branch_taken_0x3a60) {
            ctx->pc = 0x3A38u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3a38;
        }
    }
    ctx->pc = 0x3A68u;
label_3a68:
    // 0x3a68: 0x30c3ffff  andi        $v1, $a2, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
label_3a6c:
    // 0x3a6c: 0x3142ffff  andi        $v0, $t2, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
label_3a70:
    // 0x3a70: 0x21040  sll         $v0, $v0, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_3a74:
    // 0x3a74: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3a78:
    // 0x3a78: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_3a7c:
    // 0x3a7c: 0x942251a0  lhu         $v0, 0x51A0($at)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20896)));
label_3a80:
    // 0x3a80: 0x31bc0  sll         $v1, $v1, 15
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 15));
label_3a84:
    // 0x3a84: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
label_3a88:
    if (ctx->pc == 0x3A88u) {
        // 0x3a88: 0x62001b  divu        $zero, $v1, $v0 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
        ctx->pc = 0x3A8Cu;
        goto label_3a8c;
    }
    ctx->pc = 0x3A84u;
    {
        const bool branch_taken_0x3a84 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3a88: 0x62001b  divu        $zero, $v1, $v0 (Delay Slot)
        { uint32_t divisor = GPR_U32(ctx, 2); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
        if (branch_taken_0x3a84) {
            ctx->pc = 0x3A90u;
            goto label_3a90;
        }
    }
    ctx->pc = 0x3A8Cu;
label_3a8c:
    // 0x3a8c: 0x7000d  break       7
    ctx->pc = 0x3a8cu;
    runtime->handleBreak(rdram, ctx);
label_3a90:
    // 0x3a90: 0x1812  mflo        $v1
    SET_GPR_U64(ctx, 3, ctx->lo);
label_3a94:
    // 0x3a94: 0x2407007f  addiu       $a3, $zero, 0x7F
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
label_3a98:
    // 0x3a98: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
label_3a9c:
    // 0x3a9c: 0x71040  sll         $v0, $a3, 1
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
label_3aa0:
    // 0x3aa0: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3aa4:
    // 0x3aa4: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_3aa8:
    // 0x3aa8: 0x942251b8  lhu         $v0, 0x51B8($at)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 20920)));
label_3aac:
    // 0x3aac: 0x0  nop
    // NOP
label_3ab0:
    // 0x3ab0: 0x62102b  sltu        $v0, $v1, $v0
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_3ab4:
    // 0x3ab4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_3ab8:
    if (ctx->pc == 0x3AB8u) {
        ctx->pc = 0x3ABCu;
        goto label_3abc;
    }
    ctx->pc = 0x3AB4u;
    {
        const bool branch_taken_0x3ab4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x3ab4) {
            ctx->pc = 0x3AC4u;
            goto label_3ac4;
        }
    }
    ctx->pc = 0x3ABCu;
label_3abc:
    // 0x3abc: 0x8000eb4  j           func_003AD0
label_3ac0:
    if (ctx->pc == 0x3AC0u) {
        // 0x3ac0: 0xe04021  addu        $t0, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = 0x3AC4u;
        goto label_3ac4;
    }
    ctx->pc = 0x3ABCu;
    // 0x3ac0: 0xe04021  addu        $t0, $a3, $zero (Delay Slot)
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
    ctx->pc = 0x3AD0u;
    goto label_3ad0;
    ctx->pc = 0x3AC4u;
label_3ac4:
    // 0x3ac4: 0x24e7ffff  addiu       $a3, $a3, -0x1
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
label_3ac8:
    // 0x3ac8: 0x4e1fff4  bgez        $a3, . + 4 + (-0xC << 2)
label_3acc:
    if (ctx->pc == 0x3ACCu) {
        ctx->pc = 0x3AD0u;
        goto label_3ad0;
    }
    ctx->pc = 0x3AC8u;
    {
        const bool branch_taken_0x3ac8 = (GPR_S32(ctx, 7) >= 0);
        if (branch_taken_0x3ac8) {
            ctx->pc = 0x3A9Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3a9c;
        }
    }
    ctx->pc = 0x3AD0u;
label_3ad0:
    // 0x3ad0: 0x25020001  addiu       $v0, $t0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
label_3ad4:
    // 0x3ad4: 0xa24021  addu        $t0, $a1, $v0
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_3ad8:
    // 0x3ad8: 0x2522fff4  addiu       $v0, $t1, -0xC
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967284));
label_3adc:
    // 0x3adc: 0x21840  sll         $v1, $v0, 1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
label_3ae0:
    // 0x3ae0: 0x621821  addu        $v1, $v1, $v0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_3ae4:
    // 0x3ae4: 0x31880  sll         $v1, $v1, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_3ae8:
    // 0x3ae8: 0x831821  addu        $v1, $a0, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_3aec:
    // 0x3aec: 0x1431821  addu        $v1, $t2, $v1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
label_3af0:
    // 0x3af0: 0x3102ffff  andi        $v0, $t0, 0xFFFF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)65535);
label_3af4:
    // 0x3af4: 0x221c2  srl         $a0, $v0, 7
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 7));
label_3af8:
    // 0x3af8: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_3afc:
    // 0x3afc: 0x3042007e  andi        $v0, $v0, 0x7E
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)126);
label_3b00:
    // 0x3b00: 0x31a00  sll         $v1, $v1, 8
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
label_3b04:
    // 0x3b04: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_3b08:
    // 0x3b08: 0x3e00008  jr          $ra
label_3b0c:
    if (ctx->pc == 0x3B0Cu) {
        // 0x3b0c: 0x3042fffe  andi        $v0, $v0, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65534);
        ctx->pc = 0x3B10u;
        goto label_3b10;
    }
    ctx->pc = 0x3B08u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3b0c: 0x3042fffe  andi        $v0, $v0, 0xFFFE (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65534);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3B08u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3B10u;
label_3b10:
    // 0x3b10: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
label_3b14:
    // 0x3b14: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_3b18:
    // 0x3b18: 0x346307c0  ori         $v1, $v1, 0x7C0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1984);
label_3b1c:
    // 0x3b1c: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_3b20:
    // 0x3b20: 0x344207c6  ori         $v0, $v0, 0x7C6
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1990);
label_3b24:
    // 0x3b24: 0x94680000  lhu         $t0, 0x0($v1)
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_3b28:
    // 0x3b28: 0x3083000f  andi        $v1, $a0, 0xF
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
label_3b2c:
    // 0x3b2c: 0x94450000  lhu         $a1, 0x0($v0)
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_3b30:
    // 0x3b30: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_3b34:
    // 0x3b34: 0x3106fe57  andi        $a2, $t0, 0xFE57
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)65111);
label_3b38:
    // 0x3b38: 0xc04021  addu        $t0, $a2, $zero
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 0)));
label_3b3c:
    // 0x3b3c: 0x30a7fffd  andi        $a3, $a1, 0xFFFD
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65533);
label_3b40:
    // 0x3b40: 0x10620010  beq         $v1, $v0, . + 4 + (0x10 << 2)
label_3b44:
    if (ctx->pc == 0x3B44u) {
        // 0x3b44: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        ctx->pc = 0x3B48u;
        goto label_3b48;
    }
    ctx->pc = 0x3B40u;
    {
        const bool branch_taken_0x3b40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x3b44: 0xe02821  addu        $a1, $a3, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 0)));
        if (branch_taken_0x3b40) {
            ctx->pc = 0x3B84u;
            goto label_3b84;
        }
    }
    ctx->pc = 0x3B48u;
label_3b48:
    // 0x3b48: 0x28620002  slti        $v0, $v1, 0x2
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
label_3b4c:
    // 0x3b4c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_3b50:
    if (ctx->pc == 0x3B50u) {
        // 0x3b50: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x3B54u;
        goto label_3b54;
    }
    ctx->pc = 0x3B4Cu;
    {
        const bool branch_taken_0x3b4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3b50: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x3b4c) {
            ctx->pc = 0x3B64u;
            goto label_3b64;
        }
    }
    ctx->pc = 0x3B54u;
label_3b54:
    // 0x3b54: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
label_3b58:
    if (ctx->pc == 0x3B58u) {
        // 0x3b58: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x3B5Cu;
        goto label_3b5c;
    }
    ctx->pc = 0x3B54u;
    {
        const bool branch_taken_0x3b54 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        // 0x3b58: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        if (branch_taken_0x3b54) {
            ctx->pc = 0x3B7Cu;
            goto label_3b7c;
        }
    }
    ctx->pc = 0x3B5Cu;
label_3b5c:
    // 0x3b5c: 0x8000f0e  j           func_003C38
label_3b60:
    if (ctx->pc == 0x3B60u) {
        ctx->pc = 0x3B64u;
        goto label_3b64;
    }
    ctx->pc = 0x3B5Cu;
    ctx->pc = 0x3C38u;
    goto label_3c38;
    ctx->pc = 0x3B64u;
label_3b64:
    // 0x3b64: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
label_3b68:
    if (ctx->pc == 0x3B68u) {
        // 0x3b68: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->pc = 0x3B6Cu;
        goto label_3b6c;
    }
    ctx->pc = 0x3B64u;
    {
        const bool branch_taken_0x3b64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x3b68: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x3b64) {
            ctx->pc = 0x3B94u;
            goto label_3b94;
        }
    }
    ctx->pc = 0x3B6Cu;
label_3b6c:
    // 0x3b6c: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
label_3b70:
    if (ctx->pc == 0x3B70u) {
        // 0x3b70: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        ctx->pc = 0x3B74u;
        goto label_3b74;
    }
    ctx->pc = 0x3B6Cu;
    {
        const bool branch_taken_0x3b6c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        // 0x3b70: 0x2402ff9c  addiu       $v0, $zero, -0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967196));
        if (branch_taken_0x3b6c) {
            ctx->pc = 0x3B90u;
            goto label_3b90;
        }
    }
    ctx->pc = 0x3B74u;
label_3b74:
    // 0x3b74: 0x8000f0e  j           func_003C38
label_3b78:
    if (ctx->pc == 0x3B78u) {
        ctx->pc = 0x3B7Cu;
        goto label_3b7c;
    }
    ctx->pc = 0x3B74u;
    ctx->pc = 0x3C38u;
    goto label_3c38;
    ctx->pc = 0x3B7Cu;
label_3b7c:
    // 0x3b7c: 0x8000ee5  j           func_003B94
label_3b80:
    if (ctx->pc == 0x3B80u) {
        // 0x3b80: 0x34c80020  ori         $t0, $a2, 0x20 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)32);
        ctx->pc = 0x3B84u;
        goto label_3b84;
    }
    ctx->pc = 0x3B7Cu;
    // 0x3b80: 0x34c80020  ori         $t0, $a2, 0x20 (Delay Slot)
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)32);
    ctx->pc = 0x3B94u;
    goto label_3b94;
    ctx->pc = 0x3B84u;
label_3b84:
    // 0x3b84: 0x34c80100  ori         $t0, $a2, 0x100
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)256);
label_3b88:
    // 0x3b88: 0x8000ee5  j           func_003B94
label_3b8c:
    if (ctx->pc == 0x3B8Cu) {
        // 0x3b8c: 0x34e50002  ori         $a1, $a3, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)2);
        ctx->pc = 0x3B90u;
        goto label_3b90;
    }
    ctx->pc = 0x3B88u;
    // 0x3b8c: 0x34e50002  ori         $a1, $a3, 0x2 (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)2);
    ctx->pc = 0x3B94u;
    goto label_3b94;
    ctx->pc = 0x3B90u;
label_3b90:
    // 0x3b90: 0x34c80100  ori         $t0, $a2, 0x100
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)256);
label_3b94:
    // 0x3b94: 0x30820080  andi        $v0, $a0, 0x80
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)128);
label_3b98:
    // 0x3b98: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_3b9c:
    if (ctx->pc == 0x3B9Cu) {
        ctx->pc = 0x3BA0u;
        goto label_3ba0;
    }
    ctx->pc = 0x3B98u;
    {
        const bool branch_taken_0x3b98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3b98) {
            ctx->pc = 0x3BA8u;
            goto label_3ba8;
        }
    }
    ctx->pc = 0x3BA0u;
label_3ba0:
    // 0x3ba0: 0x8000eeb  j           func_003BAC
label_3ba4:
    if (ctx->pc == 0x3BA4u) {
        // 0x3ba4: 0x34a58000  ori         $a1, $a1, 0x8000 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)32768);
        ctx->pc = 0x3BA8u;
        goto label_3ba8;
    }
    ctx->pc = 0x3BA0u;
    // 0x3ba4: 0x34a58000  ori         $a1, $a1, 0x8000 (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)32768);
    ctx->pc = 0x3BACu;
    goto label_3bac;
    ctx->pc = 0x3BA8u;
label_3ba8:
    // 0x3ba8: 0x30a57fff  andi        $a1, $a1, 0x7FFF
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)32767);
label_3bac:
    // 0x3bac: 0x30830f00  andi        $v1, $a0, 0xF00
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3840);
label_3bb0:
    // 0x3bb0: 0x24020800  addiu       $v0, $zero, 0x800
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
label_3bb4:
    // 0x3bb4: 0x14620008  bne         $v1, $v0, . + 4 + (0x8 << 2)
label_3bb8:
    if (ctx->pc == 0x3BB8u) {
        // 0x3bb8: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        ctx->pc = 0x3BBCu;
        goto label_3bbc;
    }
    ctx->pc = 0x3BB4u;
    {
        const bool branch_taken_0x3bb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x3bb8: 0x24020400  addiu       $v0, $zero, 0x400 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
        if (branch_taken_0x3bb4) {
            ctx->pc = 0x3BD8u;
            goto label_3bd8;
        }
    }
    ctx->pc = 0x3BBCu;
label_3bbc:
    // 0x3bbc: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_3bc0:
    // 0x3bc0: 0x344207c8  ori         $v0, $v0, 0x7C8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1992);
label_3bc4:
    // 0x3bc4: 0x24030200  addiu       $v1, $zero, 0x200
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
label_3bc8:
    // 0x3bc8: 0xa4430000  sh          $v1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
label_3bcc:
    // 0x3bcc: 0x30a2c0ff  andi        $v0, $a1, 0xC0FF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)49407);
label_3bd0:
    // 0x3bd0: 0x8000f02  j           func_003C08
label_3bd4:
    if (ctx->pc == 0x3BD4u) {
        // 0x3bd4: 0x34451900  ori         $a1, $v0, 0x1900 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6400);
        ctx->pc = 0x3BD8u;
        goto label_3bd8;
    }
    ctx->pc = 0x3BD0u;
    // 0x3bd4: 0x34451900  ori         $a1, $v0, 0x1900 (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)6400);
    ctx->pc = 0x3C08u;
    goto label_3c08;
    ctx->pc = 0x3BD8u;
label_3bd8:
    // 0x3bd8: 0x14620006  bne         $v1, $v0, . + 4 + (0x6 << 2)
label_3bdc:
    if (ctx->pc == 0x3BDCu) {
        // 0x3bdc: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x3BE0u;
        goto label_3be0;
    }
    ctx->pc = 0x3BD8u;
    {
        const bool branch_taken_0x3bd8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x3bdc: 0x3c02bf90  lui         $v0, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x3bd8) {
            ctx->pc = 0x3BF4u;
            goto label_3bf4;
        }
    }
    ctx->pc = 0x3BE0u;
label_3be0:
    // 0x3be0: 0x344207c8  ori         $v0, $v0, 0x7C8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1992);
label_3be4:
    // 0x3be4: 0xa4400000  sh          $zero, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
label_3be8:
    // 0x3be8: 0x30a2c0ff  andi        $v0, $a1, 0xC0FF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)49407);
label_3bec:
    // 0x3bec: 0x8000f02  j           func_003C08
label_3bf0:
    if (ctx->pc == 0x3BF0u) {
        // 0x3bf0: 0x34450100  ori         $a1, $v0, 0x100 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
        ctx->pc = 0x3BF4u;
        goto label_3bf4;
    }
    ctx->pc = 0x3BECu;
    // 0x3bf0: 0x34450100  ori         $a1, $v0, 0x100 (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    ctx->pc = 0x3C08u;
    goto label_3c08;
    ctx->pc = 0x3BF4u;
label_3bf4:
    // 0x3bf4: 0x344207c8  ori         $v0, $v0, 0x7C8
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1992);
label_3bf8:
    // 0x3bf8: 0x24030200  addiu       $v1, $zero, 0x200
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
label_3bfc:
    // 0x3bfc: 0xa4430000  sh          $v1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 3));
label_3c00:
    // 0x3c00: 0x30a2c0ff  andi        $v0, $a1, 0xC0FF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)49407);
label_3c04:
    // 0x3c04: 0x34450900  ori         $a1, $v0, 0x900
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2304);
label_3c08:
    // 0x3c08: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_3c0c:
    // 0x3c0c: 0x346307c0  ori         $v1, $v1, 0x7C0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1984);
label_3c10:
    // 0x3c10: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_3c14:
    // 0x3c14: 0x344207c6  ori         $v0, $v0, 0x7C6
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1990);
label_3c18:
    // 0x3c18: 0xa4680000  sh          $t0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 8));
label_3c1c:
    // 0x3c1c: 0xa4450000  sh          $a1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 5));
label_3c20:
    // 0x3c20: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3c24:
    // 0x3c24: 0xac2452c0  sw          $a0, 0x52C0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21184), GPR_U32(ctx, 4));
label_3c28:
    // 0x3c28: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_3c2c:
    // 0x3c2c: 0x8c6352c0  lw          $v1, 0x52C0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 21184)));
label_3c30:
    // 0x3c30: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_3c34:
    // 0x3c34: 0xafa30000  sw          $v1, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
label_3c38:
    // 0x3c38: 0x3e00008  jr          $ra
label_3c3c:
    if (ctx->pc == 0x3C3Cu) {
        // 0x3c3c: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = 0x3C40u;
        goto label_3c40;
    }
    ctx->pc = 0x3C38u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3c3c: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3C38u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3C40u;
label_3c40:
    // 0x3c40: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_3c44:
    // 0x3c44: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_3c48:
    // 0x3c48: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_3c4c:
    // 0x3c4c: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_3c50:
    // 0x3c50: 0xa09021  addu        $s2, $a1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_3c54:
    // 0x3c54: 0x3202000e  andi        $v0, $s0, 0xE
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)14);
label_3c58:
    // 0x3c58: 0xafbf0024  sw          $ra, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 31));
label_3c5c:
    // 0x3c5c: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_3c60:
    // 0x3c60: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
label_3c64:
    // 0x3c64: 0x2228821  addu        $s1, $s1, $v0
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_3c68:
    // 0x3c68: 0x963152c2  lhu         $s1, 0x52C2($s1)
    SET_GPR_U32(ctx, 17, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 21186)));
label_3c6c:
    // 0x3c6c: 0xc0011e5  jal         func_004794
label_3c70:
    if (ctx->pc == 0x3C70u) {
        // 0x3c70: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x3C74u;
        goto label_3c74;
    }
    ctx->pc = 0x3C6Cu;
    SET_GPR_U32(ctx, 31, 0x3C74u);
    // 0x3c70: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x3C6Cu, 0x3C74u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3C74u;
label_3c74:
    // 0x3c74: 0x32100001  andi        $s0, $s0, 0x1
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
label_3c78:
    // 0x3c78: 0x36102300  ori         $s0, $s0, 0x2300
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)8960);
label_3c7c:
    // 0x3c7c: 0x3210ffff  andi        $s0, $s0, 0xFFFF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
label_3c80:
    // 0x3c80: 0xc000dbb  jal         func_0036EC
label_3c84:
    if (ctx->pc == 0x3C84u) {
        // 0x3c84: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x3C88u;
        goto label_3c88;
    }
    ctx->pc = 0x3C80u;
    SET_GPR_U32(ctx, 31, 0x3C88u);
    // 0x3c84: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x36ECu;
    goto label_36ec;
    ctx->pc = 0x3C88u;
label_3c88:
    // 0x3c88: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_3c8c:
    // 0x3c8c: 0x24030001  addiu       $v1, $zero, 0x1
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_3c90:
    // 0x3c90: 0x32520001  andi        $s2, $s2, 0x1
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)1);
label_3c94:
    // 0x3c94: 0x118c00  sll         $s1, $s1, 16
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 16));
label_3c98:
    // 0x3c98: 0x118c03  sra         $s1, $s1, 16
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 16));
label_3c9c:
    // 0x3c9c: 0x2231804  sllv        $v1, $v1, $s1
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), GPR_U32(ctx, 17) & 0x1F));
label_3ca0:
    // 0x3ca0: 0x31827  nor         $v1, $zero, $v1
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 3)));
label_3ca4:
    // 0x3ca4: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_3ca8:
    // 0x3ca8: 0x2329004  sllv        $s2, $s2, $s1
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), GPR_U32(ctx, 17) & 0x1F));
label_3cac:
    // 0x3cac: 0x521025  or          $v0, $v0, $s2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 18));
label_3cb0:
    // 0x3cb0: 0xc000da4  jal         func_003690
label_3cb4:
    if (ctx->pc == 0x3CB4u) {
        // 0x3cb4: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3CB8u;
        goto label_3cb8;
    }
    ctx->pc = 0x3CB0u;
    SET_GPR_U32(ctx, 31, 0x3CB8u);
    // 0x3cb4: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3690u;
    goto label_3690;
    ctx->pc = 0x3CB8u;
label_3cb8:
    // 0x3cb8: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_3cbc:
    // 0x3cbc: 0xc0011e7  jal         func_00479C
label_3cc0:
    if (ctx->pc == 0x3CC0u) {
        ctx->pc = 0x3CC4u;
        goto label_3cc4;
    }
    ctx->pc = 0x3CBCu;
    SET_GPR_U32(ctx, 31, 0x3CC4u);
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x3CBCu, 0x3CC4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3CC4u;
label_3cc4:
    // 0x3cc4: 0x8fbf0024  lw          $ra, 0x24($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_3cc8:
    // 0x3cc8: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_3ccc:
    // 0x3ccc: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_3cd0:
    // 0x3cd0: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_3cd4:
    // 0x3cd4: 0x3e00008  jr          $ra
label_3cd8:
    if (ctx->pc == 0x3CD8u) {
        // 0x3cd8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0x3CDCu;
        goto label_3cdc;
    }
    ctx->pc = 0x3CD4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3cd8: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3CD4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3CDCu;
label_3cdc:
    // 0x3cdc: 0x27bdffd8  addiu       $sp, $sp, -0x28
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967256));
label_3ce0:
    // 0x3ce0: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_3ce4:
    // 0x3ce4: 0x808021  addu        $s0, $a0, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_3ce8:
    // 0x3ce8: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_3cec:
    // 0x3cec: 0xa08821  addu        $s1, $a1, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_3cf0:
    // 0x3cf0: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_3cf4:
    // 0x3cf4: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_3cf8:
    // 0x3cf8: 0x3203fffe  andi        $v1, $s0, 0xFFFE
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65534);
label_3cfc:
    // 0x3cfc: 0x2402000a  addiu       $v0, $zero, 0xA
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
label_3d00:
    // 0x3d00: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
label_3d04:
    if (ctx->pc == 0x3D04u) {
        // 0x3d04: 0xafbf0020  sw          $ra, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
        ctx->pc = 0x3D08u;
        goto label_3d08;
    }
    ctx->pc = 0x3D00u;
    {
        const bool branch_taken_0x3d00 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x3d04: 0xafbf0020  sw          $ra, 0x20($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 31));
        if (branch_taken_0x3d00) {
            ctx->pc = 0x3D18u;
            goto label_3d18;
        }
    }
    ctx->pc = 0x3D08u;
label_3d08:
    // 0x3d08: 0xc000ec4  jal         func_003B10
label_3d0c:
    if (ctx->pc == 0x3D0Cu) {
        // 0x3d0c: 0x30a4ffff  andi        $a0, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3D10u;
        goto label_3d10;
    }
    ctx->pc = 0x3D08u;
    SET_GPR_U32(ctx, 31, 0x3D10u);
    // 0x3d0c: 0x30a4ffff  andi        $a0, $a1, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3B10u;
    goto label_3b10;
    ctx->pc = 0x3D10u;
label_3d10:
    // 0x3d10: 0x8000f5f  j           func_003D7C
label_3d14:
    if (ctx->pc == 0x3D14u) {
        ctx->pc = 0x3D18u;
        goto label_3d18;
    }
    ctx->pc = 0x3D10u;
    ctx->pc = 0x3D7Cu;
    goto label_3d7c;
    ctx->pc = 0x3D18u;
label_3d18:
    // 0x3d18: 0x24020008  addiu       $v0, $zero, 0x8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_3d1c:
    // 0x3d1c: 0x14620015  bne         $v1, $v0, . + 4 + (0x15 << 2)
label_3d20:
    if (ctx->pc == 0x3D20u) {
        // 0x3d20: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3D24u;
        goto label_3d24;
    }
    ctx->pc = 0x3D1Cu;
    {
        const bool branch_taken_0x3d1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        // 0x3d20: 0x3084ffff  andi        $a0, $a0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
        if (branch_taken_0x3d1c) {
            ctx->pc = 0x3D74u;
            goto label_3d74;
        }
    }
    ctx->pc = 0x3D24u;
label_3d24:
    // 0x3d24: 0xc0011e5  jal         func_004794
label_3d28:
    if (ctx->pc == 0x3D28u) {
        // 0x3d28: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x3D2Cu;
        goto label_3d2c;
    }
    ctx->pc = 0x3D24u;
    SET_GPR_U32(ctx, 31, 0x3D2Cu);
    // 0x3d28: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4794u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4794u, 0x3D24u, 0x3D2Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D2Cu;
label_3d2c:
    // 0x3d2c: 0x32100001  andi        $s0, $s0, 0x1
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)1);
label_3d30:
    // 0x3d30: 0x36102300  ori         $s0, $s0, 0x2300
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)8960);
label_3d34:
    // 0x3d34: 0x3210ffff  andi        $s0, $s0, 0xFFFF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)65535);
label_3d38:
    // 0x3d38: 0xc000dbb  jal         func_0036EC
label_3d3c:
    if (ctx->pc == 0x3D3Cu) {
        // 0x3d3c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x3D40u;
        goto label_3d40;
    }
    ctx->pc = 0x3D38u;
    SET_GPR_U32(ctx, 31, 0x3D40u);
    // 0x3d3c: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x36ECu;
    goto label_36ec;
    ctx->pc = 0x3D40u;
label_3d40:
    // 0x3d40: 0x2002021  addu        $a0, $s0, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_3d44:
    // 0x3d44: 0x2403c0ff  addiu       $v1, $zero, -0x3F01
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294951167));
label_3d48:
    // 0x3d48: 0x431024  and         $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
label_3d4c:
    // 0x3d4c: 0x3223003f  andi        $v1, $s1, 0x3F
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)63);
label_3d50:
    // 0x3d50: 0x31a00  sll         $v1, $v1, 8
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
label_3d54:
    // 0x3d54: 0x431025  or          $v0, $v0, $v1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
label_3d58:
    // 0x3d58: 0xc000da4  jal         func_003690
label_3d5c:
    if (ctx->pc == 0x3D5Cu) {
        // 0x3d5c: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3D60u;
        goto label_3d60;
    }
    ctx->pc = 0x3D58u;
    SET_GPR_U32(ctx, 31, 0x3D60u);
    // 0x3d5c: 0x3045ffff  andi        $a1, $v0, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3690u;
    goto label_3690;
    ctx->pc = 0x3D60u;
label_3d60:
    // 0x3d60: 0x8fa40010  lw          $a0, 0x10($sp)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_3d64:
    // 0x3d64: 0xc0011e7  jal         func_00479C
label_3d68:
    if (ctx->pc == 0x3D68u) {
        ctx->pc = 0x3D6Cu;
        goto label_3d6c;
    }
    ctx->pc = 0x3D64u;
    SET_GPR_U32(ctx, 31, 0x3D6Cu);
    ctx->pc = 0x479Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x479Cu, 0x3D64u, 0x3D6Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x3D6Cu;
label_3d6c:
    // 0x3d6c: 0x8000f5f  j           func_003D7C
label_3d70:
    if (ctx->pc == 0x3D70u) {
        ctx->pc = 0x3D74u;
        goto label_3d74;
    }
    ctx->pc = 0x3D6Cu;
    ctx->pc = 0x3D7Cu;
    goto label_3d7c;
    ctx->pc = 0x3D74u;
label_3d74:
    // 0x3d74: 0xc000f10  jal         func_003C40
label_3d78:
    if (ctx->pc == 0x3D78u) {
        // 0x3d78: 0x30a5ffff  andi        $a1, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3D7Cu;
        goto label_3d7c;
    }
    ctx->pc = 0x3D74u;
    SET_GPR_U32(ctx, 31, 0x3D7Cu);
    // 0x3d78: 0x30a5ffff  andi        $a1, $a1, 0xFFFF (Delay Slot)
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
    ctx->pc = 0x3C40u;
    goto label_3c40;
    ctx->pc = 0x3D7Cu;
label_3d7c:
    // 0x3d7c: 0x8fbf0020  lw          $ra, 0x20($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_3d80:
    // 0x3d80: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_3d84:
    // 0x3d84: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_3d88:
    // 0x3d88: 0x3e00008  jr          $ra
label_3d8c:
    if (ctx->pc == 0x3D8Cu) {
        // 0x3d8c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = 0x3D90u;
        goto label_3d90;
    }
    ctx->pc = 0x3D88u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3d8c: 0x27bd0028  addiu       $sp, $sp, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 40));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3D88u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3D90u;
label_3d90:
    // 0x3d90: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_3d94:
    // 0x3d94: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_3d98:
    // 0x3d98: 0x30820001  andi        $v0, $a0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_3d9c:
    // 0x3d9c: 0x21280  sll         $v0, $v0, 10
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
label_3da0:
    // 0x3da0: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_3da4:
    // 0x3da4: 0x94430000  lhu         $v1, 0x0($v0)
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_3da8:
    // 0x3da8: 0x3084000e  andi        $a0, $a0, 0xE
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)14);
label_3dac:
    // 0x3dac: 0x2484fffe  addiu       $a0, $a0, -0x2
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
label_3db0:
    // 0x3db0: 0x2c820009  sltiu       $v0, $a0, 0x9
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)9) ? 1 : 0);
label_3db4:
    // 0x3db4: 0x10400017  beqz        $v0, . + 4 + (0x17 << 2)
label_3db8:
    if (ctx->pc == 0x3DB8u) {
        // 0x3db8: 0x41080  sll         $v0, $a0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
        ctx->pc = 0x3DBCu;
        goto label_3dbc;
    }
    ctx->pc = 0x3DB4u;
    {
        const bool branch_taken_0x3db4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3db8: 0x41080  sll         $v0, $a0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
        if (branch_taken_0x3db4) {
            ctx->pc = 0x3E14u;
            goto label_3e14;
        }
    }
    ctx->pc = 0x3DBCu;
label_3dbc:
    // 0x3dbc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3dc0:
    // 0x3dc0: 0x220821  addu        $at, $at, $v0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_3dc4:
    // 0x3dc4: 0x8c224a30  lw          $v0, 0x4A30($at)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 18992)));
label_3dc8:
    // 0x3dc8: 0x0  nop
    // NOP
label_3dcc:
    // 0x3dcc: 0x400008  jr          $v0
label_3dd0:
    if (ctx->pc == 0x3DD0u) {
        ctx->pc = 0x3DD4u;
        goto label_3dd4;
    }
    ctx->pc = 0x3DCCu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x3DD4u: goto label_3dd4;
            case 0x3DE0u: goto label_3de0;
            case 0x3DECu: goto label_3dec;
            case 0x3DF8u: goto label_3df8;
            case 0x3E04u: goto label_3e04;
            case 0x3E14u: goto label_3e14;
            default: break;
        }
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x3DCCu, 0x0u, PS2Runtime::GuestBranchKind::IndirectJump, "JR")) {
            return;
        }
    }
    ctx->pc = 0x3DD4u;
label_3dd4:
    // 0x3dd4: 0x311c2  srl         $v0, $v1, 7
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 7));
label_3dd8:
    // 0x3dd8: 0x8000f86  j           func_003E18
label_3ddc:
    if (ctx->pc == 0x3DDCu) {
        // 0x3ddc: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->pc = 0x3DE0u;
        goto label_3de0;
    }
    ctx->pc = 0x3DD8u;
    // 0x3ddc: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    ctx->pc = 0x3E18u;
    goto label_3e18;
    ctx->pc = 0x3DE0u;
label_3de0:
    // 0x3de0: 0x31182  srl         $v0, $v1, 6
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 6));
label_3de4:
    // 0x3de4: 0x8000f86  j           func_003E18
label_3de8:
    if (ctx->pc == 0x3DE8u) {
        // 0x3de8: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->pc = 0x3DECu;
        goto label_3dec;
    }
    ctx->pc = 0x3DE4u;
    // 0x3de8: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    ctx->pc = 0x3E18u;
    goto label_3e18;
    ctx->pc = 0x3DECu;
label_3dec:
    // 0x3dec: 0x31382  srl         $v0, $v1, 14
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 14));
label_3df0:
    // 0x3df0: 0x8000f86  j           func_003E18
label_3df4:
    if (ctx->pc == 0x3DF4u) {
        // 0x3df4: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
        ctx->pc = 0x3DF8u;
        goto label_3df8;
    }
    ctx->pc = 0x3DF0u;
    // 0x3df4: 0x30420001  andi        $v0, $v0, 0x1 (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    ctx->pc = 0x3E18u;
    goto label_3e18;
    ctx->pc = 0x3DF8u;
label_3df8:
    // 0x3df8: 0x31202  srl         $v0, $v1, 8
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
label_3dfc:
    // 0x3dfc: 0x8000f86  j           func_003E18
label_3e00:
    if (ctx->pc == 0x3E00u) {
        // 0x3e00: 0x3042003f  andi        $v0, $v0, 0x3F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
        ctx->pc = 0x3E04u;
        goto label_3e04;
    }
    ctx->pc = 0x3DFCu;
    // 0x3e00: 0x3042003f  andi        $v0, $v0, 0x3F (Delay Slot)
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)63);
    ctx->pc = 0x3E18u;
    goto label_3e18;
    ctx->pc = 0x3E04u;
label_3e04:
    // 0x3e04: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3e08:
    // 0x3e08: 0x8c4252c0  lw          $v0, 0x52C0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21184)));
label_3e0c:
    // 0x3e0c: 0x3e00008  jr          $ra
label_3e10:
    if (ctx->pc == 0x3E10u) {
        // 0x3e10: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3E14u;
        goto label_3e14;
    }
    ctx->pc = 0x3E0Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3e10: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3E0Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3E14u;
label_3e14:
    // 0x3e14: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_3e18:
    // 0x3e18: 0x3e00008  jr          $ra
label_3e1c:
    if (ctx->pc == 0x3E1Cu) {
        // 0x3e1c: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = 0x3E20u;
        goto label_3e20;
    }
    ctx->pc = 0x3E18u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3e1c: 0x3042ffff  andi        $v0, $v0, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3E18u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3E20u;
label_3e20:
    // 0x3e20: 0x3084ffff  andi        $a0, $a0, 0xFFFF
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
label_3e24:
    // 0x3e24: 0x42080  sll         $a0, $a0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_3e28:
    // 0x3e28: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3e2c:
    // 0x3e2c: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_3e30:
    // 0x3e30: 0x8c4259a0  lw          $v0, 0x59A0($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 22944)));
label_3e34:
    // 0x3e34: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3e38:
    // 0x3e38: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
label_3e3c:
    // 0x3e3c: 0xac2559a0  sw          $a1, 0x59A0($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 22944), GPR_U32(ctx, 5));
label_3e40:
    // 0x3e40: 0x3c030000  lui         $v1, 0x0
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)0 << 16));
label_3e44:
    // 0x3e44: 0x641821  addu        $v1, $v1, $a0
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_3e48:
    // 0x3e48: 0x8c6359a0  lw          $v1, 0x59A0($v1)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 22944)));
label_3e4c:
    // 0x3e4c: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
label_3e50:
    // 0x3e50: 0xafa30000  sw          $v1, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
label_3e54:
    // 0x3e54: 0x3e00008  jr          $ra
label_3e58:
    if (ctx->pc == 0x3E58u) {
        // 0x3e58: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = 0x3E5Cu;
        goto label_3e5c;
    }
    ctx->pc = 0x3E54u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3e58: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3E54u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3E5Cu;
label_3e5c:
    // 0x3e5c: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
label_3e60:
    // 0x3e60: 0x41880  sll         $v1, $a0, 2
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
label_3e64:
    // 0x3e64: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3e68:
    // 0x3e68: 0x431021  addu        $v0, $v0, $v1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_3e6c:
    // 0x3e6c: 0x8c425318  lw          $v0, 0x5318($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21272)));
label_3e70:
    // 0x3e70: 0x420c0  sll         $a0, $a0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
label_3e74:
    // 0x3e74: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3e78:
    // 0x3e78: 0x230821  addu        $at, $at, $v1
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
label_3e7c:
    // 0x3e7c: 0xac255318  sw          $a1, 0x5318($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21272), GPR_U32(ctx, 5));
label_3e80:
    // 0x3e80: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3e84:
    // 0x3e84: 0x240821  addu        $at, $at, $a0
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 4)));
label_3e88:
    // 0x3e88: 0xac26532c  sw          $a2, 0x532C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21292), GPR_U32(ctx, 6));
label_3e8c:
    // 0x3e8c: 0xafa60000  sw          $a2, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
label_3e90:
    // 0x3e90: 0x3e00008  jr          $ra
label_3e94:
    if (ctx->pc == 0x3E94u) {
        // 0x3e94: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = 0x3E98u;
        goto label_3e98;
    }
    ctx->pc = 0x3E90u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3e94: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3E90u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3E98u;
label_3e98:
    // 0x3e98: 0x420c0  sll         $a0, $a0, 3
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
label_3e9c:
    // 0x3e9c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3ea0:
    // 0x3ea0: 0x441021  addu        $v0, $v0, $a0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_3ea4:
    // 0x3ea4: 0x8c42532c  lw          $v0, 0x532C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21292)));
label_3ea8:
    // 0x3ea8: 0x3e00008  jr          $ra
label_3eac:
    if (ctx->pc == 0x3EACu) {
        ctx->pc = 0x3EB0u;
        goto label_3eb0;
    }
    ctx->pc = 0x3EA8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3EA8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3EB0u;
label_3eb0:
    // 0x3eb0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3eb4:
    // 0x3eb4: 0x8c42530c  lw          $v0, 0x530C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21260)));
label_3eb8:
    // 0x3eb8: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
label_3ebc:
    // 0x3ebc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3ec0:
    // 0x3ec0: 0xac24530c  sw          $a0, 0x530C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21260), GPR_U32(ctx, 4));
label_3ec4:
    // 0x3ec4: 0xafa40000  sw          $a0, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
label_3ec8:
    // 0x3ec8: 0x3e00008  jr          $ra
label_3ecc:
    if (ctx->pc == 0x3ECCu) {
        // 0x3ecc: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = 0x3ED0u;
        goto label_3ed0;
    }
    ctx->pc = 0x3EC8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3ecc: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3EC8u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3ED0u;
label_3ed0:
    // 0x3ed0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3ed4:
    // 0x3ed4: 0x8c425310  lw          $v0, 0x5310($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21264)));
label_3ed8:
    // 0x3ed8: 0x27bdfff8  addiu       $sp, $sp, -0x8
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967288));
label_3edc:
    // 0x3edc: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3ee0:
    // 0x3ee0: 0xac245310  sw          $a0, 0x5310($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21264), GPR_U32(ctx, 4));
label_3ee4:
    // 0x3ee4: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_3ee8:
    // 0x3ee8: 0xac255314  sw          $a1, 0x5314($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21268), GPR_U32(ctx, 5));
label_3eec:
    // 0x3eec: 0xafa50000  sw          $a1, 0x0($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
label_3ef0:
    // 0x3ef0: 0x3e00008  jr          $ra
label_3ef4:
    if (ctx->pc == 0x3EF4u) {
        // 0x3ef4: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = 0x3EF8u;
        goto label_3ef8;
    }
    ctx->pc = 0x3EF0u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x3ef4: 0x27bd0008  addiu       $sp, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3EF0u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3EF8u;
label_3ef8:
    // 0x3ef8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3efc:
    // 0x3efc: 0x8c425314  lw          $v0, 0x5314($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21268)));
label_3f00:
    // 0x3f00: 0x3e00008  jr          $ra
label_3f04:
    if (ctx->pc == 0x3F04u) {
        ctx->pc = 0x3F08u;
        goto label_3f08;
    }
    ctx->pc = 0x3F00u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x3F00u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x3F08u;
label_3f08:
    // 0x3f08: 0x0  nop
    // NOP
label_3f0c:
    // 0x3f0c: 0x0  nop
    // NOP
label_3f10:
    // 0x3f10: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3f14:
    // 0x3f14: 0x8c425310  lw          $v0, 0x5310($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21264)));
label_3f18:
    // 0x3f18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_3f1c:
    // 0x3f1c: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_3f20:
    // 0x3f20: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_3f24:
    // 0x3f24: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_3f28:
    // 0x3f28: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
label_3f2c:
    if (ctx->pc == 0x3F2Cu) {
        // 0x3f2c: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        ctx->pc = 0x3F30u;
        goto label_3f30;
    }
    ctx->pc = 0x3F28u;
    {
        const bool branch_taken_0x3f28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x3f2c: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        if (branch_taken_0x3f28) {
            ctx->pc = 0x3F44u;
            goto label_3f44;
        }
    }
    ctx->pc = 0x3F30u;
label_3f30:
    // 0x3f30: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3f34:
    // 0x3f34: 0x8c42530c  lw          $v0, 0x530C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21260)));
label_3f38:
    // 0x3f38: 0x0  nop
    // NOP
label_3f3c:
    // 0x3f3c: 0x10400036  beqz        $v0, . + 4 + (0x36 << 2)
label_3f40:
    if (ctx->pc == 0x3F40u) {
        ctx->pc = 0x3F44u;
        goto label_3f44;
    }
    ctx->pc = 0x3F3Cu;
    {
        const bool branch_taken_0x3f3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3f3c) {
            ctx->pc = 0x4018u;
            goto label_4018;
        }
    }
    ctx->pc = 0x3F44u;
label_3f44:
    // 0x3f44: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_3f48:
    // 0x3f48: 0x344207c2  ori         $v0, $v0, 0x7C2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1986);
label_3f4c:
    // 0x3f4c: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_3f50:
    // 0x3f50: 0x0  nop
    // NOP
label_3f54:
    // 0x3f54: 0x3042000c  andi        $v0, $v0, 0xC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)12);
label_3f58:
    // 0x3f58: 0x22082  srl         $a0, $v0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
label_3f5c:
    // 0x3f5c: 0x1080002e  beqz        $a0, . + 4 + (0x2E << 2)
label_3f60:
    if (ctx->pc == 0x3F60u) {
        // 0x3f60: 0x3c11bf90  lui         $s1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x3F64u;
        goto label_3f64;
    }
    ctx->pc = 0x3F5Cu;
    {
        const bool branch_taken_0x3f5c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        // 0x3f60: 0x3c11bf90  lui         $s1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x3f5c) {
            ctx->pc = 0x4018u;
            goto label_4018;
        }
    }
    ctx->pc = 0x3F64u;
label_3f64:
    // 0x3f64: 0x3631019a  ori         $s1, $s1, 0x19A
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)410);
label_3f68:
    // 0x3f68: 0x3c10bf90  lui         $s0, 0xBF90
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)49040 << 16));
label_3f6c:
    // 0x3f6c: 0x3610059a  ori         $s0, $s0, 0x59A
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)1434);
label_3f70:
    // 0x3f70: 0x3c12bf90  lui         $s2, 0xBF90
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)49040 << 16));
label_3f74:
    // 0x3f74: 0x365207c2  ori         $s2, $s2, 0x7C2
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)1986);
label_3f78:
    // 0x3f78: 0x30820001  andi        $v0, $a0, 0x1
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
label_3f7c:
    // 0x3f7c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
label_3f80:
    if (ctx->pc == 0x3F80u) {
        // 0x3f80: 0x30820002  andi        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
        ctx->pc = 0x3F84u;
        goto label_3f84;
    }
    ctx->pc = 0x3F7Cu;
    {
        const bool branch_taken_0x3f7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x3f80: 0x30820002  andi        $v0, $a0, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
        if (branch_taken_0x3f7c) {
            ctx->pc = 0x3F98u;
            goto label_3f98;
        }
    }
    ctx->pc = 0x3F84u;
label_3f84:
    // 0x3f84: 0x96220000  lhu         $v0, 0x0($s1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
label_3f88:
    // 0x3f88: 0x0  nop
    // NOP
label_3f8c:
    // 0x3f8c: 0x3042ffbf  andi        $v0, $v0, 0xFFBF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65471);
label_3f90:
    // 0x3f90: 0xa6220000  sh          $v0, 0x0($s1)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_3f94:
    // 0x3f94: 0x30820002  andi        $v0, $a0, 0x2
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)2);
label_3f98:
    // 0x3f98: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
label_3f9c:
    if (ctx->pc == 0x3F9Cu) {
        ctx->pc = 0x3FA0u;
        goto label_3fa0;
    }
    ctx->pc = 0x3F98u;
    {
        const bool branch_taken_0x3f98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3f98) {
            ctx->pc = 0x3FB0u;
            goto label_3fb0;
        }
    }
    ctx->pc = 0x3FA0u;
label_3fa0:
    // 0x3fa0: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_3fa4:
    // 0x3fa4: 0x0  nop
    // NOP
label_3fa8:
    // 0x3fa8: 0x3042ffbf  andi        $v0, $v0, 0xFFBF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65471);
label_3fac:
    // 0x3fac: 0xa6020000  sh          $v0, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
label_3fb0:
    // 0x3fb0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3fb4:
    // 0x3fb4: 0x8c425310  lw          $v0, 0x5310($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21264)));
label_3fb8:
    // 0x3fb8: 0x0  nop
    // NOP
label_3fbc:
    // 0x3fbc: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
label_3fc0:
    if (ctx->pc == 0x3FC0u) {
        ctx->pc = 0x3FC4u;
        goto label_3fc4;
    }
    ctx->pc = 0x3FBCu;
    {
        const bool branch_taken_0x3fbc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3fbc) {
            ctx->pc = 0x3FE4u;
            goto label_3fe4;
        }
    }
    ctx->pc = 0x3FC4u;
label_3fc4:
    // 0x3fc4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3fc8:
    // 0x3fc8: 0x8c425310  lw          $v0, 0x5310($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21264)));
label_3fcc:
    // 0x3fcc: 0x3c050000  lui         $a1, 0x0
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)0 << 16));
label_3fd0:
    // 0x3fd0: 0x8ca55314  lw          $a1, 0x5314($a1)
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 21268)));
label_3fd4:
    // 0x3fd4: 0x40f809  jalr        $v0
label_3fd8:
    if (ctx->pc == 0x3FD8u) {
        ctx->pc = 0x3FDCu;
        goto label_3fdc;
    }
    ctx->pc = 0x3FD4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x3FDCu);
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x3FD4u, 0x3FDCu, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x3FDCu;
label_3fdc:
    // 0x3fdc: 0x8001000  j           func_004000
label_3fe0:
    if (ctx->pc == 0x3FE0u) {
        ctx->pc = 0x3FE4u;
        goto label_3fe4;
    }
    ctx->pc = 0x3FDCu;
    ctx->pc = 0x4000u;
    goto label_4000;
    ctx->pc = 0x3FE4u;
label_3fe4:
    // 0x3fe4: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_3fe8:
    // 0x3fe8: 0x8c42530c  lw          $v0, 0x530C($v0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 21260)));
label_3fec:
    // 0x3fec: 0x0  nop
    // NOP
label_3ff0:
    // 0x3ff0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
label_3ff4:
    if (ctx->pc == 0x3FF4u) {
        ctx->pc = 0x3FF8u;
        goto label_3ff8;
    }
    ctx->pc = 0x3FF0u;
    {
        const bool branch_taken_0x3ff0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x3ff0) {
            ctx->pc = 0x4000u;
            goto label_4000;
        }
    }
    ctx->pc = 0x3FF8u;
label_3ff8:
    // 0x3ff8: 0x40f809  jalr        $v0
label_3ffc:
    if (ctx->pc == 0x3FFCu) {
        // 0x3ffc: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x4000u;
        goto label_4000;
    }
    ctx->pc = 0x3FF8u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x4000u);
        // 0x3ffc: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = jumpTarget;
        if (!runtime->dispatchIopBranch(rdram, ctx, jumpTarget, 0x3FF8u, 0x4000u, PS2Runtime::GuestBranchKind::IndirectCall, "JALR")) {
            return;
        }
    }
    ctx->pc = 0x4000u;
label_4000:
    // 0x4000: 0x96420000  lhu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
label_4004:
    // 0x4004: 0x0  nop
    // NOP
label_4008:
    // 0x4008: 0x3042000c  andi        $v0, $v0, 0xC
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)12);
label_400c:
    // 0x400c: 0x22082  srl         $a0, $v0, 2
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
label_4010:
    // 0x4010: 0x1480ffda  bnez        $a0, . + 4 + (-0x26 << 2)
label_4014:
    if (ctx->pc == 0x4014u) {
        // 0x4014: 0x30820001  andi        $v0, $a0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
        ctx->pc = 0x4018u;
        goto label_4018;
    }
    ctx->pc = 0x4010u;
    {
        const bool branch_taken_0x4010 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        // 0x4014: 0x30820001  andi        $v0, $a0, 0x1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
        if (branch_taken_0x4010) {
            ctx->pc = 0x3F7Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_3f7c;
        }
    }
    ctx->pc = 0x4018u;
label_4018:
    // 0x4018: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_401c:
    // 0x401c: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_4020:
    // 0x4020: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_4024:
    // 0x4024: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_4028:
    // 0x4028: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_402c:
    // 0x402c: 0x3e00008  jr          $ra
label_4030:
    if (ctx->pc == 0x4030u) {
        // 0x4030: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x4034u;
        goto label_4034;
    }
    ctx->pc = 0x402Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4030: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x402Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4034u;
label_4034:
    // 0x4034: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
label_4038:
    // 0x4038: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_403c:
    // 0x403c: 0x24c65338  addiu       $a2, $a2, 0x5338
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 21304));
label_4040:
    // 0x4040: 0xafb1001c  sw          $s1, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
label_4044:
    // 0x4044: 0x3c11bf90  lui         $s1, 0xBF90
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49040 << 16));
label_4048:
    // 0x4048: 0xafb00018  sw          $s0, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
label_404c:
    // 0x404c: 0x2208021  addu        $s0, $s1, $zero
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_4050:
    // 0x4050: 0x36100400  ori         $s0, $s0, 0x400
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)1024);
label_4054:
    // 0x4054: 0xafb30024  sw          $s3, 0x24($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 19));
label_4058:
    // 0x4058: 0x2209821  addu        $s3, $s1, $zero
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_405c:
    // 0x405c: 0x367301c0  ori         $s3, $s3, 0x1C0
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 19) | (uint64_t)(uint16_t)448);
label_4060:
    // 0x4060: 0xafb20020  sw          $s2, 0x20($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 18));
label_4064:
    // 0x4064: 0x2209021  addu        $s2, $s1, $zero
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_4068:
    // 0x4068: 0x2201821  addu        $v1, $s1, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_406c:
    // 0x406c: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_4070:
    // 0x4070: 0x2202021  addu        $a0, $s1, $zero
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_4074:
    // 0x4074: 0x348401a8  ori         $a0, $a0, 0x1A8
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)424);
label_4078:
    // 0x4078: 0x2202821  addu        $a1, $s1, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_407c:
    // 0x407c: 0xafbf0030  sw          $ra, 0x30($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 31));
label_4080:
    // 0x4080: 0xafb5002c  sw          $s5, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 21));
label_4084:
    // 0x4084: 0xafb40028  sw          $s4, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 20));
label_4088:
    // 0x4088: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_408c:
    // 0x408c: 0x34a501aa  ori         $a1, $a1, 0x1AA
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)426);
label_4090:
    // 0x4090: 0x3042ffcf  andi        $v0, $v0, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65487);
label_4094:
    // 0x4094: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_4098:
    // 0x4098: 0x24022800  addiu       $v0, $zero, 0x2800
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10240));
label_409c:
    // 0x409c: 0xa4800000  sh          $zero, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 0));
label_40a0:
    // 0x40a0: 0xa4a20000  sh          $v0, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
label_40a4:
    // 0x40a4: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_40a8:
    // 0x40a8: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_40ac:
    // 0x40ac: 0x0  nop
    // NOP
label_40b0:
    // 0x40b0: 0x28420008  slti        $v0, $v0, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
label_40b4:
    // 0x40b4: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
label_40b8:
    if (ctx->pc == 0x40B8u) {
        // 0x40b8: 0x365205c0  ori         $s2, $s2, 0x5C0 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)1472);
        ctx->pc = 0x40BCu;
        goto label_40bc;
    }
    ctx->pc = 0x40B4u;
    {
        const bool branch_taken_0x40b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x40b8: 0x365205c0  ori         $s2, $s2, 0x5C0 (Delay Slot)
        SET_GPR_U64(ctx, 18, GPR_U64(ctx, 18) | (uint64_t)(uint16_t)1472);
        if (branch_taken_0x40b4) {
            ctx->pc = 0x40F4u;
            goto label_40f4;
        }
    }
    ctx->pc = 0x40BCu;
label_40bc:
    // 0x40bc: 0x2201821  addu        $v1, $s1, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_40c0:
    // 0x40c0: 0x346301ac  ori         $v1, $v1, 0x1AC
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)428);
label_40c4:
    // 0x40c4: 0x94c20000  lhu         $v0, 0x0($a2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
label_40c8:
    // 0x40c8: 0x0  nop
    // NOP
label_40cc:
    // 0x40cc: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_40d0:
    // 0x40d0: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_40d4:
    // 0x40d4: 0x0  nop
    // NOP
label_40d8:
    // 0x40d8: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_40dc:
    // 0x40dc: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_40e0:
    // 0x40e0: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_40e4:
    // 0x40e4: 0x0  nop
    // NOP
label_40e8:
    // 0x40e8: 0x28420008  slti        $v0, $v0, 0x8
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)8) ? 1 : 0);
label_40ec:
    // 0x40ec: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
label_40f0:
    if (ctx->pc == 0x40F0u) {
        // 0x40f0: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->pc = 0x40F4u;
        goto label_40f4;
    }
    ctx->pc = 0x40ECu;
    {
        const bool branch_taken_0x40ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x40f0: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        if (branch_taken_0x40ec) {
            ctx->pc = 0x40C4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_40c4;
        }
    }
    ctx->pc = 0x40F4u;
label_40f4:
    // 0x40f4: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_40f8:
    // 0x40f8: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_40fc:
    // 0x40fc: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_4100:
    // 0x4100: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_4104:
    // 0x4104: 0x34840344  ori         $a0, $a0, 0x344
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)836);
label_4108:
    // 0x4108: 0x3042ffcf  andi        $v0, $v0, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65487);
label_410c:
    // 0x410c: 0x34420010  ori         $v0, $v0, 0x10
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
label_4110:
    // 0x4110: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_4114:
    // 0x4114: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_4118:
    // 0x4118: 0x94820000  lhu         $v0, 0x0($a0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
label_411c:
    // 0x411c: 0x0  nop
    // NOP
label_4120:
    // 0x4120: 0x30420400  andi        $v0, $v0, 0x400
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1024);
label_4124:
    // 0x4124: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
label_4128:
    if (ctx->pc == 0x4128u) {
        // 0x4128: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x412Cu;
        goto label_412c;
    }
    ctx->pc = 0x4124u;
    {
        const bool branch_taken_0x4124 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x4128: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x4124) {
            ctx->pc = 0x4178u;
            goto label_4178;
        }
    }
    ctx->pc = 0x412Cu;
label_412c:
    // 0x412c: 0x3c150100  lui         $s5, 0x100
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)256 << 16));
label_4130:
    // 0x4130: 0x3c14bf90  lui         $s4, 0xBF90
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)49040 << 16));
label_4134:
    // 0x4134: 0x36940344  ori         $s4, $s4, 0x344
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) | (uint64_t)(uint16_t)836);
label_4138:
    // 0x4138: 0xc000854  jal         func_002150
label_413c:
    if (ctx->pc == 0x413Cu) {
        // 0x413c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x4140u;
        goto label_4140;
    }
    ctx->pc = 0x4138u;
    SET_GPR_U32(ctx, 31, 0x4140u);
    // 0x413c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x4140u;
label_4140:
    // 0x4140: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_4144:
    // 0x4144: 0x0  nop
    // NOP
label_4148:
    // 0x4148: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_414c:
    // 0x414c: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_4150:
    // 0x4150: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_4154:
    // 0x4154: 0x0  nop
    // NOP
label_4158:
    // 0x4158: 0x2a2102a  slt         $v0, $s5, $v0
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 21) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
label_415c:
    // 0x415c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
label_4160:
    if (ctx->pc == 0x4160u) {
        // 0x4160: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        ctx->pc = 0x4164u;
        goto label_4164;
    }
    ctx->pc = 0x415Cu;
    {
        const bool branch_taken_0x415c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x4160: 0x3c03bf90  lui         $v1, 0xBF90 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
        if (branch_taken_0x415c) {
            ctx->pc = 0x4178u;
            goto label_4178;
        }
    }
    ctx->pc = 0x4164u;
label_4164:
    // 0x4164: 0x96820000  lhu         $v0, 0x0($s4)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
label_4168:
    // 0x4168: 0x0  nop
    // NOP
label_416c:
    // 0x416c: 0x30420400  andi        $v0, $v0, 0x400
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1024);
label_4170:
    // 0x4170: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
label_4174:
    if (ctx->pc == 0x4174u) {
        ctx->pc = 0x4178u;
        goto label_4178;
    }
    ctx->pc = 0x4170u;
    {
        const bool branch_taken_0x4170 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x4170) {
            ctx->pc = 0x4138u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_4138;
        }
    }
    ctx->pc = 0x4178u;
label_4178:
    // 0x4178: 0x3463019a  ori         $v1, $v1, 0x19A
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)410);
label_417c:
    // 0x417c: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_4180:
    // 0x4180: 0x0  nop
    // NOP
label_4184:
    // 0x4184: 0x3042ffcf  andi        $v0, $v0, 0xFFCF
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65487);
label_4188:
    // 0x4188: 0xa4620000  sh          $v0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
label_418c:
    // 0x418c: 0xafa00010  sw          $zero, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
label_4190:
    // 0x4190: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_4194:
    // 0x4194: 0x0  nop
    // NOP
label_4198:
    // 0x4198: 0x28420018  slti        $v0, $v0, 0x18
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)24) ? 1 : 0);
label_419c:
    // 0x419c: 0x1040002c  beqz        $v0, . + 4 + (0x2C << 2)
label_41a0:
    if (ctx->pc == 0x41A0u) {
        // 0x41a0: 0x24043fff  addiu       $a0, $zero, 0x3FFF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16383));
        ctx->pc = 0x41A4u;
        goto label_41a4;
    }
    ctx->pc = 0x419Cu;
    {
        const bool branch_taken_0x419c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        // 0x41a0: 0x24043fff  addiu       $a0, $zero, 0x3FFF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16383));
        if (branch_taken_0x419c) {
            ctx->pc = 0x4250u;
            goto label_4250;
        }
    }
    ctx->pc = 0x41A4u;
label_41a4:
    // 0x41a4: 0x24032800  addiu       $v1, $zero, 0x2800
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10240));
label_41a8:
    // 0x41a8: 0xa6000000  sh          $zero, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_41ac:
    // 0x41ac: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_41b0:
    // 0x41b0: 0x26100002  addiu       $s0, $s0, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
label_41b4:
    // 0x41b4: 0xa6220000  sh          $v0, 0x0($s1)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_41b8:
    // 0x41b8: 0x26310002  addiu       $s1, $s1, 0x2
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
label_41bc:
    // 0x41bc: 0xa6000000  sh          $zero, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_41c0:
    // 0x41c0: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_41c4:
    // 0x41c4: 0x26100002  addiu       $s0, $s0, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
label_41c8:
    // 0x41c8: 0xa6220000  sh          $v0, 0x0($s1)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_41cc:
    // 0x41cc: 0x26310002  addiu       $s1, $s1, 0x2
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
label_41d0:
    // 0x41d0: 0xa6040000  sh          $a0, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 4));
label_41d4:
    // 0x41d4: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_41d8:
    // 0x41d8: 0x26100002  addiu       $s0, $s0, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
label_41dc:
    // 0x41dc: 0xa6220000  sh          $v0, 0x0($s1)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_41e0:
    // 0x41e0: 0x26310002  addiu       $s1, $s1, 0x2
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
label_41e4:
    // 0x41e4: 0xa6000000  sh          $zero, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_41e8:
    // 0x41e8: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_41ec:
    // 0x41ec: 0x26100002  addiu       $s0, $s0, 0x2
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
label_41f0:
    // 0x41f0: 0xa6220000  sh          $v0, 0x0($s1)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_41f4:
    // 0x41f4: 0x26310002  addiu       $s1, $s1, 0x2
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
label_41f8:
    // 0x41f8: 0xa6000000  sh          $zero, 0x0($s0)
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
label_41fc:
    // 0x41fc: 0x96020000  lhu         $v0, 0x0($s0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
label_4200:
    // 0x4200: 0x26100008  addiu       $s0, $s0, 0x8
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
label_4204:
    // 0x4204: 0xa6220000  sh          $v0, 0x0($s1)
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_4208:
    // 0x4208: 0x26310008  addiu       $s1, $s1, 0x8
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
label_420c:
    // 0x420c: 0xa6400000  sh          $zero, 0x0($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
label_4210:
    // 0x4210: 0x96420000  lhu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
label_4214:
    // 0x4214: 0x26520002  addiu       $s2, $s2, 0x2
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
label_4218:
    // 0x4218: 0xa6620000  sh          $v0, 0x0($s3)
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
label_421c:
    // 0x421c: 0xa6430000  sh          $v1, 0x0($s2)
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 3));
label_4220:
    // 0x4220: 0x96420000  lhu         $v0, 0x0($s2)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
label_4224:
    // 0x4224: 0x26730002  addiu       $s3, $s3, 0x2
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 2));
label_4228:
    // 0x4228: 0xa6620000  sh          $v0, 0x0($s3)
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
label_422c:
    // 0x422c: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_4230:
    // 0x4230: 0x2652000a  addiu       $s2, $s2, 0xA
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 10));
label_4234:
    // 0x4234: 0x24420001  addiu       $v0, $v0, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_4238:
    // 0x4238: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_423c:
    // 0x423c: 0x8fa20010  lw          $v0, 0x10($sp)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_4240:
    // 0x4240: 0x0  nop
    // NOP
label_4244:
    // 0x4244: 0x28420018  slti        $v0, $v0, 0x18
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)24) ? 1 : 0);
label_4248:
    // 0x4248: 0x1440ffd7  bnez        $v0, . + 4 + (-0x29 << 2)
label_424c:
    if (ctx->pc == 0x424Cu) {
        // 0x424c: 0x2673000a  addiu       $s3, $s3, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 10));
        ctx->pc = 0x4250u;
        goto label_4250;
    }
    ctx->pc = 0x4248u;
    {
        const bool branch_taken_0x4248 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        // 0x424c: 0x2673000a  addiu       $s3, $s3, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 10));
        if (branch_taken_0x4248) {
            ctx->pc = 0x41A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_41a8;
        }
    }
    ctx->pc = 0x4250u;
label_4250:
    // 0x4250: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_4254:
    // 0x4254: 0x348401a0  ori         $a0, $a0, 0x1A0
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)416);
label_4258:
    // 0x4258: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_425c:
    // 0x425c: 0x344205a0  ori         $v0, $v0, 0x5A0
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1440);
label_4260:
    // 0x4260: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_4264:
    // 0x4264: 0x34a501a2  ori         $a1, $a1, 0x1A2
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)418);
label_4268:
    // 0x4268: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_426c:
    // 0x426c: 0x3411ffff  ori         $s1, $zero, 0xFFFF
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
label_4270:
    // 0x4270: 0x346305a2  ori         $v1, $v1, 0x5A2
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1442);
label_4274:
    // 0x4274: 0xa4510000  sh          $s1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 17));
label_4278:
    // 0x4278: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_427c:
    // 0x427c: 0x241000ff  addiu       $s0, $zero, 0xFF
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_4280:
    // 0x4280: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_4284:
    // 0x4284: 0xa4700000  sh          $s0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 16));
label_4288:
    // 0x4288: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_428c:
    // 0x428c: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_4290:
    // 0x4290: 0xc000854  jal         func_002150
label_4294:
    if (ctx->pc == 0x4294u) {
        // 0x4294: 0xa4a20000  sh          $v0, 0x0($a1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x4298u;
        goto label_4298;
    }
    ctx->pc = 0x4290u;
    SET_GPR_U32(ctx, 31, 0x4298u);
    // 0x4294: 0xa4a20000  sh          $v0, 0x0($a1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x4298u;
label_4298:
    // 0x4298: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_429c:
    // 0x429c: 0x348401a4  ori         $a0, $a0, 0x1A4
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)420);
label_42a0:
    // 0x42a0: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_42a4:
    // 0x42a4: 0x344205a4  ori         $v0, $v0, 0x5A4
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1444);
label_42a8:
    // 0x42a8: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_42ac:
    // 0x42ac: 0x34a501a6  ori         $a1, $a1, 0x1A6
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)422);
label_42b0:
    // 0x42b0: 0x3c03bf90  lui         $v1, 0xBF90
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)49040 << 16));
label_42b4:
    // 0x42b4: 0xa4510000  sh          $s1, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 17));
label_42b8:
    // 0x42b8: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_42bc:
    // 0x42bc: 0x346305a6  ori         $v1, $v1, 0x5A6
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1446);
label_42c0:
    // 0x42c0: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_42c4:
    // 0x42c4: 0xa4700000  sh          $s0, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 16));
label_42c8:
    // 0x42c8: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_42cc:
    // 0x42cc: 0x24040003  addiu       $a0, $zero, 0x3
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_42d0:
    // 0x42d0: 0xc000854  jal         func_002150
label_42d4:
    if (ctx->pc == 0x42D4u) {
        // 0x42d4: 0xa4a20000  sh          $v0, 0x0($a1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->pc = 0x42D8u;
        goto label_42d8;
    }
    ctx->pc = 0x42D0u;
    SET_GPR_U32(ctx, 31, 0x42D8u);
    // 0x42d4: 0xa4a20000  sh          $v0, 0x0($a1) (Delay Slot)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x2150u;
    goto label_2150;
    ctx->pc = 0x42D8u;
label_42d8:
    // 0x42d8: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_42dc:
    // 0x42dc: 0x34840340  ori         $a0, $a0, 0x340
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)832);
label_42e0:
    // 0x42e0: 0x3c02bf90  lui         $v0, 0xBF90
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)49040 << 16));
label_42e4:
    // 0x42e4: 0x34420342  ori         $v0, $v0, 0x342
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)834);
label_42e8:
    // 0x42e8: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_42ec:
    // 0x42ec: 0xa01821  addu        $v1, $a1, $zero
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 0)));
label_42f0:
    // 0x42f0: 0xa4400000  sh          $zero, 0x0($v0)
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 0));
label_42f4:
    // 0x42f4: 0x94420000  lhu         $v0, 0x0($v0)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_42f8:
    // 0x42f8: 0x34630742  ori         $v1, $v1, 0x742
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)1858);
label_42fc:
    // 0x42fc: 0xa4820000  sh          $v0, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
label_4300:
    // 0x4300: 0xa4600000  sh          $zero, 0x0($v1)
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 0));
label_4304:
    // 0x4304: 0x94620000  lhu         $v0, 0x0($v1)
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
label_4308:
    // 0x4308: 0x34a50740  ori         $a1, $a1, 0x740
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1856);
label_430c:
    // 0x430c: 0xa4a20000  sh          $v0, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
label_4310:
    // 0x4310: 0x8fbf0030  lw          $ra, 0x30($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_4314:
    // 0x4314: 0x8fb5002c  lw          $s5, 0x2C($sp)
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_4318:
    // 0x4318: 0x8fb40028  lw          $s4, 0x28($sp)
    SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_431c:
    // 0x431c: 0x8fb30024  lw          $s3, 0x24($sp)
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
label_4320:
    // 0x4320: 0x8fb20020  lw          $s2, 0x20($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_4324:
    // 0x4324: 0x8fb1001c  lw          $s1, 0x1C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_4328:
    // 0x4328: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_432c:
    // 0x432c: 0x3e00008  jr          $ra
label_4330:
    if (ctx->pc == 0x4330u) {
        // 0x4330: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = 0x4334u;
        goto label_4334;
    }
    ctx->pc = 0x432Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4330: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x432Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4334u;
label_4334:
    // 0x4334: 0x27bdffc8  addiu       $sp, $sp, -0x38
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967240));
label_4338:
    // 0x4338: 0xafb1002c  sw          $s1, 0x2C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 17));
label_433c:
    // 0x433c: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_4340:
    // 0x4340: 0x24040024  addiu       $a0, $zero, 0x24
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
label_4344:
    // 0x4344: 0xafb00028  sw          $s0, 0x28($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 16));
label_4348:
    // 0x4348: 0x27b00020  addiu       $s0, $sp, 0x20
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
label_434c:
    // 0x434c: 0x2002821  addu        $a1, $s0, $zero
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
label_4350:
    // 0x4350: 0xafbf0034  sw          $ra, 0x34($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 31));
label_4354:
    // 0x4354: 0xc0011e3  jal         func_00478C
label_4358:
    if (ctx->pc == 0x4358u) {
        // 0x4358: 0xafb20030  sw          $s2, 0x30($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
        ctx->pc = 0x435Cu;
        goto label_435c;
    }
    ctx->pc = 0x4354u;
    SET_GPR_U32(ctx, 31, 0x435Cu);
    // 0x4358: 0xafb20030  sw          $s2, 0x30($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 18));
    ctx->pc = 0x478Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x478Cu, 0x4354u, 0x435Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x435Cu;
label_435c:
    // 0x435c: 0x24040028  addiu       $a0, $zero, 0x28
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
label_4360:
    // 0x4360: 0xc0011e3  jal         func_00478C
label_4364:
    if (ctx->pc == 0x4364u) {
        // 0x4364: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x4368u;
        goto label_4368;
    }
    ctx->pc = 0x4360u;
    SET_GPR_U32(ctx, 31, 0x4368u);
    // 0x4364: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x478Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x478Cu, 0x4360u, 0x4368u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4368u;
label_4368:
    // 0x4368: 0x24040009  addiu       $a0, $zero, 0x9
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
label_436c:
    // 0x436c: 0xc0011e3  jal         func_00478C
label_4370:
    if (ctx->pc == 0x4370u) {
        // 0x4370: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x4374u;
        goto label_4374;
    }
    ctx->pc = 0x436Cu;
    SET_GPR_U32(ctx, 31, 0x4374u);
    // 0x4370: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x478Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x478Cu, 0x436Cu, 0x4374u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4374u;
label_4374:
    // 0x4374: 0xc0011df  jal         func_00477C
label_4378:
    if (ctx->pc == 0x4378u) {
        // 0x4378: 0x24040024  addiu       $a0, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->pc = 0x437Cu;
        goto label_437c;
    }
    ctx->pc = 0x4374u;
    SET_GPR_U32(ctx, 31, 0x437Cu);
    // 0x4378: 0x24040024  addiu       $a0, $zero, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    ctx->pc = 0x477Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x477Cu, 0x4374u, 0x437Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x437Cu;
label_437c:
    // 0x437c: 0xc0011df  jal         func_00477C
label_4380:
    if (ctx->pc == 0x4380u) {
        // 0x4380: 0x24040028  addiu       $a0, $zero, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
        ctx->pc = 0x4384u;
        goto label_4384;
    }
    ctx->pc = 0x437Cu;
    SET_GPR_U32(ctx, 31, 0x4384u);
    // 0x4380: 0x24040028  addiu       $a0, $zero, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    ctx->pc = 0x477Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x477Cu, 0x437Cu, 0x4384u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4384u;
label_4384:
    // 0x4384: 0xc0011df  jal         func_00477C
label_4388:
    if (ctx->pc == 0x4388u) {
        // 0x4388: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->pc = 0x438Cu;
        goto label_438c;
    }
    ctx->pc = 0x4384u;
    SET_GPR_U32(ctx, 31, 0x438Cu);
    // 0x4388: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    ctx->pc = 0x477Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x477Cu, 0x4384u, 0x438Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x438Cu;
label_438c:
    // 0x438c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_4390:
    // 0x4390: 0x24425184  addiu       $v0, $v0, 0x5184
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20868));
label_4394:
    // 0x4394: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_4398:
    // 0x4398: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
label_439c:
    // 0x439c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_43a0:
    // 0x43a0: 0x2442518c  addiu       $v0, $v0, 0x518C
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20876));
label_43a4:
    // 0x43a4: 0x24120001  addiu       $s2, $zero, 0x1
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_43a8:
    // 0x43a8: 0xac520000  sw          $s2, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 18));
label_43ac:
    // 0x43ac: 0xac520004  sw          $s2, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 18));
label_43b0:
    // 0x43b0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_43b4:
    // 0x43b4: 0x244252f8  addiu       $v0, $v0, 0x52F8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21240));
label_43b8:
    // 0x43b8: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_43bc:
    // 0x43bc: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
label_43c0:
    // 0x43c0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_43c4:
    // 0x43c4: 0x24425318  addiu       $v0, $v0, 0x5318
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21272));
label_43c8:
    // 0x43c8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_43cc:
    // 0x43cc: 0xac205310  sw          $zero, 0x5310($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21264), GPR_U32(ctx, 0));
label_43d0:
    // 0x43d0: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_43d4:
    // 0x43d4: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
label_43d8:
    // 0x43d8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_43dc:
    // 0x43dc: 0x24425320  addiu       $v0, $v0, 0x5320
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21280));
label_43e0:
    // 0x43e0: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_43e4:
    // 0x43e4: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
label_43e8:
    // 0x43e8: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_43ec:
    // 0x43ec: 0x24425328  addiu       $v0, $v0, 0x5328
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21288));
label_43f0:
    // 0x43f0: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_43f4:
    // 0x43f4: 0xac520008  sw          $s2, 0x8($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 18));
label_43f8:
    // 0x43f8: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
label_43fc:
    // 0x43fc: 0xac40000c  sw          $zero, 0xC($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 0));
label_4400:
    // 0x4400: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_4404:
    // 0x4404: 0x244259a0  addiu       $v0, $v0, 0x59A0
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22944));
label_4408:
    // 0x4408: 0x3231000f  andi        $s1, $s1, 0xF
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
label_440c:
    // 0x440c: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_4410:
    // 0x4410: 0xac205314  sw          $zero, 0x5314($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21268), GPR_U32(ctx, 0));
label_4414:
    // 0x4414: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_4418:
    // 0x4418: 0xac20530c  sw          $zero, 0x530C($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21260), GPR_U32(ctx, 0));
label_441c:
    // 0x441c: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_4420:
    // 0x4420: 0xac400004  sw          $zero, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
label_4424:
    // 0x4424: 0x1620001d  bnez        $s1, . + 4 + (0x1D << 2)
label_4428:
    if (ctx->pc == 0x4428u) {
        // 0x4428: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x442Cu;
        goto label_442c;
    }
    ctx->pc = 0x4424u;
    {
        const bool branch_taken_0x4424 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        // 0x4428: 0x8821  addu        $s1, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        if (branch_taken_0x4424) {
            ctx->pc = 0x449Cu;
            goto label_449c;
        }
    }
    ctx->pc = 0x442Cu;
label_442c:
    // 0x442c: 0x3c040000  lui         $a0, 0x0
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)0 << 16));
label_4430:
    // 0x4430: 0x248452d0  addiu       $a0, $a0, 0x52D0
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 21200));
label_4434:
    // 0x4434: 0xc001208  jal         func_004820
label_4438:
    if (ctx->pc == 0x4438u) {
        // 0x4438: 0x24050028  addiu       $a1, $zero, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
        ctx->pc = 0x443Cu;
        goto label_443c;
    }
    ctx->pc = 0x4434u;
    SET_GPR_U32(ctx, 31, 0x443Cu);
    // 0x4438: 0x24050028  addiu       $a1, $zero, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    ctx->pc = 0x4820u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4820u, 0x4434u, 0x443Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x443Cu;
label_443c:
    // 0x443c: 0x3c08001d  lui         $t0, 0x1D
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)29 << 16));
label_4440:
    // 0x4440: 0x3508fff0  ori         $t0, $t0, 0xFFF0
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)65520);
label_4444:
    // 0x4444: 0x3c03001f  lui         $v1, 0x1F
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)31 << 16));
label_4448:
    // 0x4448: 0x3463fff0  ori         $v1, $v1, 0xFFF0
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65520);
label_444c:
    // 0x444c: 0x3c05bf90  lui         $a1, 0xBF90
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)49040 << 16));
label_4450:
    // 0x4450: 0x34a502e0  ori         $a1, $a1, 0x2E0
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)736);
label_4454:
    // 0x4454: 0x3c06bf90  lui         $a2, 0xBF90
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49040 << 16));
label_4458:
    // 0x4458: 0x34c602e2  ori         $a2, $a2, 0x2E2
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)738);
label_445c:
    // 0x445c: 0x3c07bf90  lui         $a3, 0xBF90
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)49040 << 16));
label_4460:
    // 0x4460: 0x34e706e0  ori         $a3, $a3, 0x6E0
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)1760);
label_4464:
    // 0x4464: 0x3c04bf90  lui         $a0, 0xBF90
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)49040 << 16));
label_4468:
    // 0x4468: 0x348406e2  ori         $a0, $a0, 0x6E2
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)1762);
label_446c:
    // 0x446c: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_4470:
    // 0x4470: 0x244259a8  addiu       $v0, $v0, 0x59A8
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22952));
label_4474:
    // 0x4474: 0xac480000  sw          $t0, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 8));
label_4478:
    // 0x4478: 0xac430004  sw          $v1, 0x4($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
label_447c:
    // 0x447c: 0x2402000e  addiu       $v0, $zero, 0xE
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
label_4480:
    // 0x4480: 0x3403fff8  ori         $v1, $zero, 0xFFF8
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65528);
label_4484:
    // 0x4484: 0xa4a20000  sh          $v0, 0x0($a1)
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
label_4488:
    // 0x4488: 0x2402000f  addiu       $v0, $zero, 0xF
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_448c:
    // 0x448c: 0xa4c30000  sh          $v1, 0x0($a2)
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 3));
label_4490:
    // 0x4490: 0xa4e20000  sh          $v0, 0x0($a3)
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 2));
label_4494:
    // 0x4494: 0xa4830000  sh          $v1, 0x0($a0)
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
label_4498:
    // 0x4498: 0x8821  addu        $s1, $zero, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_449c:
    // 0x449c: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
label_44a0:
    // 0x44a0: 0x26105300  addiu       $s0, $s0, 0x5300
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21248));
label_44a4:
    // 0x44a4: 0x8e030000  lw          $v1, 0x0($s0)
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_44a8:
    // 0x44a8: 0x24020002  addiu       $v0, $zero, 0x2
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_44ac:
    // 0x44ac: 0xafa20010  sw          $v0, 0x10($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
label_44b0:
    // 0x44b0: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_44b4:
    // 0x44b4: 0x1860000f  blez        $v1, . + 4 + (0xF << 2)
label_44b8:
    if (ctx->pc == 0x44B8u) {
        // 0x44b8: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
        ctx->pc = 0x44BCu;
        goto label_44bc;
    }
    ctx->pc = 0x44B4u;
    {
        const bool branch_taken_0x44b4 = (GPR_S32(ctx, 3) <= 0);
        // 0x44b8: 0xafa00014  sw          $zero, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
        if (branch_taken_0x44b4) {
            ctx->pc = 0x44F4u;
            goto label_44f4;
        }
    }
    ctx->pc = 0x44BCu;
label_44bc:
    // 0x44bc: 0xc0011e9  jal         func_0047A4
label_44c0:
    if (ctx->pc == 0x44C0u) {
        ctx->pc = 0x44C4u;
        goto label_44c4;
    }
    ctx->pc = 0x44BCu;
    SET_GPR_U32(ctx, 31, 0x44C4u);
    ctx->pc = 0x47A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47A4u, 0x44BCu, 0x44C4u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x44C4u;
label_44c4:
    // 0x44c4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
label_44c8:
    if (ctx->pc == 0x44C8u) {
        ctx->pc = 0x44CCu;
        goto label_44cc;
    }
    ctx->pc = 0x44C4u;
    {
        const bool branch_taken_0x44c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x44c4) {
            ctx->pc = 0x44E0u;
            goto label_44e0;
        }
    }
    ctx->pc = 0x44CCu;
label_44cc:
    // 0x44cc: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_44d0:
    // 0x44d0: 0xc001217  jal         func_00485C
label_44d4:
    if (ctx->pc == 0x44D4u) {
        // 0x44d4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x44D8u;
        goto label_44d8;
    }
    ctx->pc = 0x44D0u;
    SET_GPR_U32(ctx, 31, 0x44D8u);
    // 0x44d4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x485Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x485Cu, 0x44D0u, 0x44D8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x44D8u;
label_44d8:
    // 0x44d8: 0x8001145  j           func_004514
label_44dc:
    if (ctx->pc == 0x44DCu) {
        ctx->pc = 0x44E0u;
        goto label_44e0;
    }
    ctx->pc = 0x44D8u;
    ctx->pc = 0x4514u;
    goto label_4514;
    ctx->pc = 0x44E0u;
label_44e0:
    // 0x44e0: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_44e4:
    // 0x44e4: 0xc001215  jal         func_004854
label_44e8:
    if (ctx->pc == 0x44E8u) {
        // 0x44e8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x44ECu;
        goto label_44ec;
    }
    ctx->pc = 0x44E4u;
    SET_GPR_U32(ctx, 31, 0x44ECu);
    // 0x44e8: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4854u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4854u, 0x44E4u, 0x44ECu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x44ECu;
label_44ec:
    // 0x44ec: 0x8001145  j           func_004514
label_44f0:
    if (ctx->pc == 0x44F0u) {
        ctx->pc = 0x44F4u;
        goto label_44f4;
    }
    ctx->pc = 0x44ECu;
    ctx->pc = 0x4514u;
    goto label_4514;
    ctx->pc = 0x44F4u;
label_44f4:
    // 0x44f4: 0xc001211  jal         func_004844
label_44f8:
    if (ctx->pc == 0x44F8u) {
        // 0x44f8: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x44FCu;
        goto label_44fc;
    }
    ctx->pc = 0x44F4u;
    SET_GPR_U32(ctx, 31, 0x44FCu);
    // 0x44f8: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x44F4u, 0x44FCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x44FCu;
label_44fc:
    // 0x44fc: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_4500:
    // 0x4500: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_4504:
    // 0x4504: 0x0  nop
    // NOP
label_4508:
    // 0x4508: 0x1c400002  bgtz        $v0, . + 4 + (0x2 << 2)
label_450c:
    if (ctx->pc == 0x450Cu) {
        ctx->pc = 0x4510u;
        goto label_4510;
    }
    ctx->pc = 0x4508u;
    {
        const bool branch_taken_0x4508 = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x4508) {
            ctx->pc = 0x4514u;
            goto label_4514;
        }
    }
    ctx->pc = 0x4510u;
label_4510:
    // 0x4510: 0x2411fed3  addiu       $s1, $zero, -0x12D
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966995));
label_4514:
    // 0x4514: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
label_4518:
    // 0x4518: 0x26105304  addiu       $s0, $s0, 0x5304
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21252));
label_451c:
    // 0x451c: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_4520:
    // 0x4520: 0x0  nop
    // NOP
label_4524:
    // 0x4524: 0x1840000f  blez        $v0, . + 4 + (0xF << 2)
label_4528:
    if (ctx->pc == 0x4528u) {
        ctx->pc = 0x452Cu;
        goto label_452c;
    }
    ctx->pc = 0x4524u;
    {
        const bool branch_taken_0x4524 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x4524) {
            ctx->pc = 0x4564u;
            goto label_4564;
        }
    }
    ctx->pc = 0x452Cu;
label_452c:
    // 0x452c: 0xc0011e9  jal         func_0047A4
label_4530:
    if (ctx->pc == 0x4530u) {
        ctx->pc = 0x4534u;
        goto label_4534;
    }
    ctx->pc = 0x452Cu;
    SET_GPR_U32(ctx, 31, 0x4534u);
    ctx->pc = 0x47A4u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x47A4u, 0x452Cu, 0x4534u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4534u;
label_4534:
    // 0x4534: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
label_4538:
    if (ctx->pc == 0x4538u) {
        ctx->pc = 0x453Cu;
        goto label_453c;
    }
    ctx->pc = 0x4534u;
    {
        const bool branch_taken_0x4534 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x4534) {
            ctx->pc = 0x4550u;
            goto label_4550;
        }
    }
    ctx->pc = 0x453Cu;
label_453c:
    // 0x453c: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_4540:
    // 0x4540: 0xc001217  jal         func_00485C
label_4544:
    if (ctx->pc == 0x4544u) {
        // 0x4544: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x4548u;
        goto label_4548;
    }
    ctx->pc = 0x4540u;
    SET_GPR_U32(ctx, 31, 0x4548u);
    // 0x4544: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x485Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x485Cu, 0x4540u, 0x4548u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4548u;
label_4548:
    // 0x4548: 0x8001162  j           func_004588
label_454c:
    if (ctx->pc == 0x454Cu) {
        // 0x454c: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x4550u;
        goto label_4550;
    }
    ctx->pc = 0x4548u;
    // 0x454c: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4588u;
    goto label_4588;
    ctx->pc = 0x4550u;
label_4550:
    // 0x4550: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_4554:
    // 0x4554: 0xc001215  jal         func_004854
label_4558:
    if (ctx->pc == 0x4558u) {
        // 0x4558: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x455Cu;
        goto label_455c;
    }
    ctx->pc = 0x4554u;
    SET_GPR_U32(ctx, 31, 0x455Cu);
    // 0x4558: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4854u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4854u, 0x4554u, 0x455Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x455Cu;
label_455c:
    // 0x455c: 0x8001162  j           func_004588
label_4560:
    if (ctx->pc == 0x4560u) {
        // 0x4560: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x4564u;
        goto label_4564;
    }
    ctx->pc = 0x455Cu;
    // 0x4560: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4588u;
    goto label_4588;
    ctx->pc = 0x4564u;
label_4564:
    // 0x4564: 0xc001211  jal         func_004844
label_4568:
    if (ctx->pc == 0x4568u) {
        // 0x4568: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x456Cu;
        goto label_456c;
    }
    ctx->pc = 0x4564u;
    SET_GPR_U32(ctx, 31, 0x456Cu);
    // 0x4568: 0x27a40010  addiu       $a0, $sp, 0x10 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x4844u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4844u, 0x4564u, 0x456Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x456Cu;
label_456c:
    // 0x456c: 0xae020000  sw          $v0, 0x0($s0)
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
label_4570:
    // 0x4570: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_4574:
    // 0x4574: 0x0  nop
    // NOP
label_4578:
    // 0x4578: 0x1c400003  bgtz        $v0, . + 4 + (0x3 << 2)
label_457c:
    if (ctx->pc == 0x457Cu) {
        // 0x457c: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x4580u;
        goto label_4580;
    }
    ctx->pc = 0x4578u;
    {
        const bool branch_taken_0x4578 = (GPR_S32(ctx, 2) > 0);
        // 0x457c: 0x2201021  addu        $v0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        if (branch_taken_0x4578) {
            ctx->pc = 0x4588u;
            goto label_4588;
        }
    }
    ctx->pc = 0x4580u;
label_4580:
    // 0x4580: 0x2411fed3  addiu       $s1, $zero, -0x12D
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966995));
label_4584:
    // 0x4584: 0x2201021  addu        $v0, $s1, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_4588:
    // 0x4588: 0x8fbf0034  lw          $ra, 0x34($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 52)));
label_458c:
    // 0x458c: 0x8fb20030  lw          $s2, 0x30($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 48)));
label_4590:
    // 0x4590: 0x8fb1002c  lw          $s1, 0x2C($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_4594:
    // 0x4594: 0x8fb00028  lw          $s0, 0x28($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
label_4598:
    // 0x4598: 0x3e00008  jr          $ra
label_459c:
    if (ctx->pc == 0x459Cu) {
        // 0x459c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = 0x45A0u;
        goto label_45a0;
    }
    ctx->pc = 0x4598u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x459c: 0x27bd0038  addiu       $sp, $sp, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 56));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x4598u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x45A0u;
label_45a0:
    // 0x45a0: 0x3c020000  lui         $v0, 0x0
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)0 << 16));
label_45a4:
    // 0x45a4: 0x24425300  addiu       $v0, $v0, 0x5300
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 21248));
label_45a8:
    // 0x45a8: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_45ac:
    // 0x45ac: 0xac205308  sw          $zero, 0x5308($at)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21256), GPR_U32(ctx, 0));
label_45b0:
    // 0x45b0: 0xac400000  sw          $zero, 0x0($v0)
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_45b4:
    // 0x45b4: 0x3e00008  jr          $ra
label_45b8:
    if (ctx->pc == 0x45B8u) {
        // 0x45b8: 0xac400004  sw          $zero, 0x4($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
        ctx->pc = 0x45BCu;
        goto label_45bc;
    }
    ctx->pc = 0x45B4u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x45b8: 0xac400004  sw          $zero, 0x4($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x45B4u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x45BCu;
label_45bc:
    // 0x45bc: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_45c0:
    // 0x45c0: 0xafb10014  sw          $s1, 0x14($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 17));
label_45c4:
    // 0x45c4: 0x808821  addu        $s1, $a0, $zero
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 0)));
label_45c8:
    // 0x45c8: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_45cc:
    // 0x45cc: 0xafb20018  sw          $s2, 0x18($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 18));
label_45d0:
    // 0x45d0: 0xc00057a  jal         func_0015E8
label_45d4:
    if (ctx->pc == 0x45D4u) {
        // 0x45d4: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
        ctx->pc = 0x45D8u;
        goto label_45d8;
    }
    ctx->pc = 0x45D0u;
    SET_GPR_U32(ctx, 31, 0x45D8u);
    // 0x45d4: 0xafb00010  sw          $s0, 0x10($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 16));
    ctx->pc = 0x15E8u;
    goto label_15e8;
    ctx->pc = 0x45D8u;
label_45d8:
    // 0x45d8: 0x3230000f  andi        $s0, $s1, 0xF
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 17) & (uint64_t)(uint16_t)15);
label_45dc:
    // 0x45dc: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
label_45e0:
    if (ctx->pc == 0x45E0u) {
        ctx->pc = 0x45E4u;
        goto label_45e4;
    }
    ctx->pc = 0x45DCu;
    {
        const bool branch_taken_0x45dc = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x45dc) {
            ctx->pc = 0x45ECu;
            goto label_45ec;
        }
    }
    ctx->pc = 0x45E4u;
label_45e4:
    // 0x45e4: 0xc0007ab  jal         func_001EAC
label_45e8:
    if (ctx->pc == 0x45E8u) {
        // 0x45e8: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
        ctx->pc = 0x45ECu;
        goto label_45ec;
    }
    ctx->pc = 0x45E4u;
    SET_GPR_U32(ctx, 31, 0x45ECu);
    // 0x45e8: 0x2021  addu        $a0, $zero, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
    ctx->pc = 0x1EACu;
    goto label_1eac;
    ctx->pc = 0x45ECu;
label_45ec:
    // 0x45ec: 0xc0010cd  jal         func_004334
label_45f0:
    if (ctx->pc == 0x45F0u) {
        // 0x45f0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
        ctx->pc = 0x45F4u;
        goto label_45f4;
    }
    ctx->pc = 0x45ECu;
    SET_GPR_U32(ctx, 31, 0x45F4u);
    // 0x45f0: 0x2202021  addu        $a0, $s1, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
    ctx->pc = 0x4334u;
    goto label_4334;
    ctx->pc = 0x45F4u;
label_45f4:
    // 0x45f4: 0xc00100d  jal         func_004034
label_45f8:
    if (ctx->pc == 0x45F8u) {
        // 0x45f8: 0x409021  addu        $s2, $v0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
        ctx->pc = 0x45FCu;
        goto label_45fc;
    }
    ctx->pc = 0x45F4u;
    SET_GPR_U32(ctx, 31, 0x45FCu);
    // 0x45f8: 0x409021  addu        $s2, $v0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 0)));
    ctx->pc = 0x4034u;
    goto label_4034;
    ctx->pc = 0x45FCu;
label_45fc:
    // 0x45fc: 0xc00058e  jal         func_001638
label_4600:
    if (ctx->pc == 0x4600u) {
        // 0x4600: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x4604u;
        goto label_4604;
    }
    ctx->pc = 0x45FCu;
    SET_GPR_U32(ctx, 31, 0x4604u);
    // 0x4600: 0x2002021  addu        $a0, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x1638u;
    goto label_1638;
    ctx->pc = 0x4604u;
label_4604:
    // 0x4604: 0xc0011e1  jal         func_004784
label_4608:
    if (ctx->pc == 0x4608u) {
        // 0x4608: 0x24040024  addiu       $a0, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->pc = 0x460Cu;
        goto label_460c;
    }
    ctx->pc = 0x4604u;
    SET_GPR_U32(ctx, 31, 0x460Cu);
    // 0x4608: 0x24040024  addiu       $a0, $zero, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    ctx->pc = 0x4784u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4784u, 0x4604u, 0x460Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x460Cu;
label_460c:
    // 0x460c: 0xc0011e1  jal         func_004784
label_4610:
    if (ctx->pc == 0x4610u) {
        // 0x4610: 0x24040028  addiu       $a0, $zero, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
        ctx->pc = 0x4614u;
        goto label_4614;
    }
    ctx->pc = 0x460Cu;
    SET_GPR_U32(ctx, 31, 0x4614u);
    // 0x4610: 0x24040028  addiu       $a0, $zero, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    ctx->pc = 0x4784u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4784u, 0x460Cu, 0x4614u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4614u;
label_4614:
    // 0x4614: 0xc0011e1  jal         func_004784
label_4618:
    if (ctx->pc == 0x4618u) {
        // 0x4618: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->pc = 0x461Cu;
        goto label_461c;
    }
    ctx->pc = 0x4614u;
    SET_GPR_U32(ctx, 31, 0x461Cu);
    // 0x4618: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    ctx->pc = 0x4784u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4784u, 0x4614u, 0x461Cu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x461Cu;
label_461c:
    // 0x461c: 0x24040024  addiu       $a0, $zero, 0x24
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
label_4620:
    // 0x4620: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_4624:
    // 0x4624: 0x3c110000  lui         $s1, 0x0
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)0 << 16));
label_4628:
    // 0x4628: 0x263127e8  addiu       $s1, $s1, 0x27E8
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 10216));
label_462c:
    // 0x462c: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_4630:
    // 0x4630: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
label_4634:
    // 0x4634: 0x26105328  addiu       $s0, $s0, 0x5328
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21288));
label_4638:
    // 0x4638: 0xc0011dd  jal         func_004774
label_463c:
    if (ctx->pc == 0x463Cu) {
        // 0x463c: 0x2003821  addu        $a3, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x4640u;
        goto label_4640;
    }
    ctx->pc = 0x4638u;
    SET_GPR_U32(ctx, 31, 0x4640u);
    // 0x463c: 0x2003821  addu        $a3, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x4774u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4774u, 0x4638u, 0x4640u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4640u;
label_4640:
    // 0x4640: 0x24040028  addiu       $a0, $zero, 0x28
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
label_4644:
    // 0x4644: 0x24050001  addiu       $a1, $zero, 0x1
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_4648:
    // 0x4648: 0x2203021  addu        $a2, $s1, $zero
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 0)));
label_464c:
    // 0x464c: 0xc0011dd  jal         func_004774
label_4650:
    if (ctx->pc == 0x4650u) {
        // 0x4650: 0x26070008  addiu       $a3, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->pc = 0x4654u;
        goto label_4654;
    }
    ctx->pc = 0x464Cu;
    SET_GPR_U32(ctx, 31, 0x4654u);
    // 0x4650: 0x26070008  addiu       $a3, $s0, 0x8 (Delay Slot)
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    ctx->pc = 0x4774u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4774u, 0x464Cu, 0x4654u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4654u;
label_4654:
    // 0x4654: 0x24040009  addiu       $a0, $zero, 0x9
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
label_4658:
    // 0x4658: 0x3c070000  lui         $a3, 0x0
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)0 << 16));
label_465c:
    // 0x465c: 0x8ce75314  lw          $a3, 0x5314($a3)
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 21268)));
label_4660:
    // 0x4660: 0x3c060000  lui         $a2, 0x0
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)0 << 16));
label_4664:
    // 0x4664: 0x24c63f10  addiu       $a2, $a2, 0x3F10
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 16144));
label_4668:
    // 0x4668: 0xc0011dd  jal         func_004774
label_466c:
    if (ctx->pc == 0x466Cu) {
        // 0x466c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x4670u;
        goto label_4670;
    }
    ctx->pc = 0x4668u;
    SET_GPR_U32(ctx, 31, 0x4670u);
    // 0x466c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x4774u;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x4774u, 0x4668u, 0x4670u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4670u;
label_4670:
    // 0x4670: 0x24020001  addiu       $v0, $zero, 0x1
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_4674:
    // 0x4674: 0x3c010000  lui         $at, 0x0
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)0 << 16));
label_4678:
    // 0x4678: 0xc0007a4  jal         func_001E90
label_467c:
    if (ctx->pc == 0x467Cu) {
        // 0x467c: 0xac225308  sw          $v0, 0x5308($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 21256), GPR_U32(ctx, 2));
        ctx->pc = 0x4680u;
        goto label_4680;
    }
    ctx->pc = 0x4678u;
    SET_GPR_U32(ctx, 31, 0x4680u);
    // 0x467c: 0xac225308  sw          $v0, 0x5308($at) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 1), 21256), GPR_U32(ctx, 2));
    ctx->pc = 0x1E90u;
    goto label_1e90;
    ctx->pc = 0x4680u;
label_4680:
    // 0x4680: 0x2401021  addu        $v0, $s2, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 0)));
label_4684:
    // 0x4684: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_4688:
    // 0x4688: 0x8fb20018  lw          $s2, 0x18($sp)
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_468c:
    // 0x468c: 0x8fb10014  lw          $s1, 0x14($sp)
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_4690:
    // 0x4690: 0x8fb00010  lw          $s0, 0x10($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
label_4694:
    // 0x4694: 0x3e00008  jr          $ra
label_4698:
    if (ctx->pc == 0x4698u) {
        // 0x4698: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x469Cu;
        goto label_469c;
    }
    ctx->pc = 0x4694u;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4698: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x4694u, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x469Cu;
label_469c:
    // 0x469c: 0x27bdffe0  addiu       $sp, $sp, -0x20
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_46a0:
    // 0x46a0: 0x2404000a  addiu       $a0, $zero, 0xA
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
label_46a4:
    // 0x46a4: 0xafbf001c  sw          $ra, 0x1C($sp)
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 31));
label_46a8:
    // 0x46a8: 0xc000866  jal         func_002198
label_46ac:
    if (ctx->pc == 0x46ACu) {
        // 0x46ac: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        ctx->pc = 0x46B0u;
        goto label_46b0;
    }
    ctx->pc = 0x46A8u;
    SET_GPR_U32(ctx, 31, 0x46B0u);
    // 0x46ac: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x46B0u;
label_46b0:
    // 0x46b0: 0xc000866  jal         func_002198
label_46b4:
    if (ctx->pc == 0x46B4u) {
        // 0x46b4: 0x2404001a  addiu       $a0, $zero, 0x1A (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
        ctx->pc = 0x46B8u;
        goto label_46b8;
    }
    ctx->pc = 0x46B0u;
    SET_GPR_U32(ctx, 31, 0x46B8u);
    // 0x46b4: 0x2404001a  addiu       $a0, $zero, 0x1A (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 26));
    ctx->pc = 0x2198u;
    goto label_2198;
    ctx->pc = 0x46B8u;
label_46b8:
    // 0x46b8: 0x3c100000  lui         $s0, 0x0
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)0 << 16));
label_46bc:
    // 0x46bc: 0x26105300  addiu       $s0, $s0, 0x5300
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 21248));
label_46c0:
    // 0x46c0: 0x8e020000  lw          $v0, 0x0($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_46c4:
    // 0x46c4: 0x0  nop
    // NOP
label_46c8:
    // 0x46c8: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
label_46cc:
    if (ctx->pc == 0x46CCu) {
        ctx->pc = 0x46D0u;
        goto label_46d0;
    }
    ctx->pc = 0x46C8u;
    {
        const bool branch_taken_0x46c8 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x46c8) {
            ctx->pc = 0x46DCu;
            goto label_46dc;
        }
    }
    ctx->pc = 0x46D0u;
label_46d0:
    // 0x46d0: 0x8e040000  lw          $a0, 0x0($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_46d4:
    // 0x46d4: 0xc001213  jal         func_00484C
label_46d8:
    if (ctx->pc == 0x46D8u) {
        ctx->pc = 0x46DCu;
        goto label_46dc;
    }
    ctx->pc = 0x46D4u;
    SET_GPR_U32(ctx, 31, 0x46DCu);
    ctx->pc = 0x484Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x484Cu, 0x46D4u, 0x46DCu, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x46DCu;
label_46dc:
    // 0x46dc: 0x8e020004  lw          $v0, 0x4($s0)
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_46e0:
    // 0x46e0: 0x0  nop
    // NOP
label_46e4:
    // 0x46e4: 0x18400004  blez        $v0, . + 4 + (0x4 << 2)
label_46e8:
    if (ctx->pc == 0x46E8u) {
        ctx->pc = 0x46ECu;
        goto label_46ec;
    }
    ctx->pc = 0x46E4u;
    {
        const bool branch_taken_0x46e4 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x46e4) {
            ctx->pc = 0x46F8u;
            goto label_46f8;
        }
    }
    ctx->pc = 0x46ECu;
label_46ec:
    // 0x46ec: 0x8e040004  lw          $a0, 0x4($s0)
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
label_46f0:
    // 0x46f0: 0xc001213  jal         func_00484C
label_46f4:
    if (ctx->pc == 0x46F4u) {
        ctx->pc = 0x46F8u;
        goto label_46f8;
    }
    ctx->pc = 0x46F0u;
    SET_GPR_U32(ctx, 31, 0x46F8u);
    ctx->pc = 0x484Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x484Cu, 0x46F0u, 0x46F8u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x46F8u;
label_46f8:
    // 0x46f8: 0x24040028  addiu       $a0, $zero, 0x28
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
label_46fc:
    // 0x46fc: 0x27b00010  addiu       $s0, $sp, 0x10
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
label_4700:
    // 0x4700: 0xc0011e3  jal         func_00478C
label_4704:
    if (ctx->pc == 0x4704u) {
        // 0x4704: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x4708u;
        goto label_4708;
    }
    ctx->pc = 0x4700u;
    SET_GPR_U32(ctx, 31, 0x4708u);
    // 0x4704: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x478Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x478Cu, 0x4700u, 0x4708u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4708u;
label_4708:
    // 0x4708: 0x24040024  addiu       $a0, $zero, 0x24
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
label_470c:
    // 0x470c: 0xc0011e3  jal         func_00478C
label_4710:
    if (ctx->pc == 0x4710u) {
        // 0x4710: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x4714u;
        goto label_4714;
    }
    ctx->pc = 0x470Cu;
    SET_GPR_U32(ctx, 31, 0x4714u);
    // 0x4710: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x478Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x478Cu, 0x470Cu, 0x4714u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4714u;
label_4714:
    // 0x4714: 0x24040009  addiu       $a0, $zero, 0x9
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
label_4718:
    // 0x4718: 0xc0011e3  jal         func_00478C
label_471c:
    if (ctx->pc == 0x471Cu) {
        // 0x471c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
        ctx->pc = 0x4720u;
        goto label_4720;
    }
    ctx->pc = 0x4718u;
    SET_GPR_U32(ctx, 31, 0x4720u);
    // 0x471c: 0x2002821  addu        $a1, $s0, $zero (Delay Slot)
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 0)));
    ctx->pc = 0x478Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x478Cu, 0x4718u, 0x4720u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4720u;
label_4720:
    // 0x4720: 0xc0011df  jal         func_00477C
label_4724:
    if (ctx->pc == 0x4724u) {
        // 0x4724: 0x24040028  addiu       $a0, $zero, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
        ctx->pc = 0x4728u;
        goto label_4728;
    }
    ctx->pc = 0x4720u;
    SET_GPR_U32(ctx, 31, 0x4728u);
    // 0x4724: 0x24040028  addiu       $a0, $zero, 0x28 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    ctx->pc = 0x477Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x477Cu, 0x4720u, 0x4728u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4728u;
label_4728:
    // 0x4728: 0xc0011df  jal         func_00477C
label_472c:
    if (ctx->pc == 0x472Cu) {
        // 0x472c: 0x24040024  addiu       $a0, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->pc = 0x4730u;
        goto label_4730;
    }
    ctx->pc = 0x4728u;
    SET_GPR_U32(ctx, 31, 0x4730u);
    // 0x472c: 0x24040024  addiu       $a0, $zero, 0x24 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    ctx->pc = 0x477Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x477Cu, 0x4728u, 0x4730u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4730u;
label_4730:
    // 0x4730: 0xc0011df  jal         func_00477C
label_4734:
    if (ctx->pc == 0x4734u) {
        // 0x4734: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->pc = 0x4738u;
        goto label_4738;
    }
    ctx->pc = 0x4730u;
    SET_GPR_U32(ctx, 31, 0x4738u);
    // 0x4734: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    ctx->pc = 0x477Cu;
    if (!runtime->dispatchIopBranch(rdram, ctx, 0x477Cu, 0x4730u, 0x4738u, PS2Runtime::GuestBranchKind::DirectCall, "JAL")) {
        return;
    }
    ctx->pc = 0x4738u;
label_4738:
    // 0x4738: 0xc0007a4  jal         func_001E90
label_473c:
    if (ctx->pc == 0x473Cu) {
        ctx->pc = 0x4740u;
        goto label_4740;
    }
    ctx->pc = 0x4738u;
    SET_GPR_U32(ctx, 31, 0x4740u);
    ctx->pc = 0x1E90u;
    goto label_1e90;
    ctx->pc = 0x4740u;
label_4740:
    // 0x4740: 0x8fbf001c  lw          $ra, 0x1C($sp)
    SET_GPR_S32(ctx, 31, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
label_4744:
    // 0x4744: 0x8fb00018  lw          $s0, 0x18($sp)
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_4748:
    // 0x4748: 0x1021  addu        $v0, $zero, $zero
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), GPR_U32(ctx, 0)));
label_474c:
    // 0x474c: 0x3e00008  jr          $ra
label_4750:
    if (ctx->pc == 0x4750u) {
        // 0x4750: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x4754u;
        goto label_4754;
    }
    ctx->pc = 0x474Cu;
    {
        const uint32_t jumpTarget = GPR_U32(ctx, 31);
        // 0x4750: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        #if defined(PS2X_STRICT_RETURN_DIAGNOSTICS) && PS2X_STRICT_RETURN_DIAGNOSTICS
        (void)runtime->dispatchGuestBranch(rdram, ctx, jumpTarget, 0x474Cu, 0u, PS2Runtime::GuestBranchKind::Return, "JR $ra");
        return;
        #else
        ctx->pc = jumpTarget;
        return;
        #endif
    }
    ctx->pc = 0x4754u;
label_4754:
    // 0x4754: 0x0  nop
    // NOP
label_4758:
    // 0x4758: 0x0  nop
    // NOP
label_475c:
    // 0x475c: 0x0  nop
    // NOP
label_4760:
    // 0x4760: 0x41e00000  .word       0x41E00000                   # INVALID     $t7, $zero, 0x0 # 00000000 <InstrIdType: R5900_COP0>
    throw std::runtime_error("Unhandled COP0 instruction format: 0xF at 0x4760 raw=0x41E00000");
label_4764:
    // 0x4764: 0x0  nop
    // NOP
label_4768:
    // 0x4768: 0x102  srl         $zero, $zero, 4
    SET_GPR_S32(ctx, 0, (int32_t)SRL32(GPR_U32(ctx, 0), 4));
label_476c:
    // 0x476c: 0x72746e69  .word       0x72746E69                   # INVALID     $s3, $s4, 0x6E69 # 00000000 <InstrIdType: R5900_MMI_3>
    throw std::runtime_error("R5900-only (MMI/VU) instruction in an R3000 build at 0x476C raw=0x72746E69");
label_4770:
    // 0x4770: 0x6e616d  .word       0x006E616D                   # daddu       $t4, $v1, $t6 # 00000140 <InstrIdType: CPU_SPECIAL>
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 14));
}


// Function: libsd_00004774
// Address: 0x4774 - 0x477c
void libsd_00004774_0x4774(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_00004774_0x4774");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 4u);
}


// Function: libsd_0000477c
// Address: 0x477c - 0x4784
void libsd_0000477c_0x477c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_0000477c_0x477c");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 5u);
}


// Function: libsd_00004784
// Address: 0x4784 - 0x478c
void libsd_00004784_0x4784(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_00004784_0x4784");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 6u);
}


// Function: libsd_0000478c
// Address: 0x478c - 0x4794
void libsd_0000478c_0x478c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_0000478c_0x478c");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 7u);
}


// Function: libsd_00004794
// Address: 0x4794 - 0x479c
void libsd_00004794_0x4794(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_00004794_0x4794");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 17u);
}


// Function: libsd_0000479c
// Address: 0x479c - 0x47a4
void libsd_0000479c_0x479c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_0000479c_0x479c");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 18u);
}


// Function: libsd_000047a4
// Address: 0x47a4 - 0x47c8
void libsd_000047a4_0x47a4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_000047a4_0x47a4");
#endif

    runtime->iopImport(rdram, ctx, "intrman", 23u);
}


// Function: libsd_000047c8
// Address: 0x47c8 - 0x47d0
void libsd_000047c8_0x47c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_000047c8_0x47c8");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 5u);
}


// Function: libsd_000047d0
// Address: 0x47d0 - 0x47f4
void libsd_000047d0_0x47d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_000047d0_0x47d0");
#endif

    runtime->iopImport(rdram, ctx, "loadcore", 6u);
}


// Function: libsd_000047f4
// Address: 0x47f4 - 0x47fc
void libsd_000047f4_0x47f4(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_000047f4_0x47f4");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 7u);
}


// Function: libsd_000047fc
// Address: 0x47fc - 0x4820
void libsd_000047fc_0x47fc(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_000047fc_0x47fc");
#endif

    runtime->iopImport(rdram, ctx, "sifman", 8u);
}


// Function: libsd_00004820
// Address: 0x4820 - 0x4844
void libsd_00004820_0x4820(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_00004820_0x4820");
#endif

    runtime->iopImport(rdram, ctx, "sysclib", 17u);
}


// Function: libsd_00004844
// Address: 0x4844 - 0x484c
void libsd_00004844_0x4844(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_00004844_0x4844");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 4u);
}


// Function: libsd_0000484c
// Address: 0x484c - 0x4854
void libsd_0000484c_0x484c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_0000484c_0x484c");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 5u);
}


// Function: libsd_00004854
// Address: 0x4854 - 0x485c
void libsd_00004854_0x4854(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_00004854_0x4854");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 6u);
}


// Function: libsd_0000485c
// Address: 0x485c - 0x4864
void libsd_0000485c_0x485c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_0000485c_0x485c");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 7u);
}


// Function: libsd_00004864
// Address: 0x4864 - 0x486c
void libsd_00004864_0x4864(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_00004864_0x4864");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 8u);
}


// Function: libsd_0000486c
// Address: 0x486c - 0x4874
void libsd_0000486c_0x486c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("libsd_0000486c_0x486c");
#endif

    runtime->iopImport(rdram, ctx, "thevent", 9u);
}


