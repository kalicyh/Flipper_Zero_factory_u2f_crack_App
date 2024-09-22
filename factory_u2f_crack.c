#include <furi.h>
#include <furi_hal.h>
#include <furi_hal_crypto.h>
#include <gui/gui.h>
#include <input/input.h>
#include "factory_u2f_crack_icons.h"

#define TAG "factory_u2f_crack"

#define ENCLAVE_FACTORY_KEY_SLOTS 10
#define ENCLAVE_SIGNATURE_SIZE    16

static const uint8_t kalicyh[1535] =
    "y\0\3\2\4\4\2\5\5\11\16\0\376\7\376\10\377\1F\2\226\3\276 \5\0\362\12!\7qC"
    "\212A\11\42\7#W\213D\11#\16uB\233\312\240\224\222(I\6\245\2$\16\225>\253l\251("
    "\331\226(\225-\2%\16wB\234,i\213\322R\226\264%\0&\16v\302\253\60\311\222L\222\22-"
    "Z\2'\6!W\12\1(\13\223\77\253$J\242Z\224\5)\14\223\77\213,\312\242J\224D\0*"
    "\12UF\253Jei\212\0+\12UF\253\60\32\244\60\2,\7\62:\232D\1-\6\25N\213A"
    ".\6\21C\212\0/\13\224\276\272R\26e\245,\3\60\14t\302\32%R\206D\222\22\5\61\10s"
    "\303\232D\352\62\62\12t\302\32%\312\242\266!\63\14t\302\32%\312\242PJ\24\0\64\12t\302*"
    "\245E\222\6-\65\13t\302\212A\313\306lH\0\66\14t\302\32%\322\226HJ\24\0\67\12t\302"
    "\212!+e-\0\70\14t\302\32%\222\22%\222\22\5\71\14t\302\32%\222\222MJ\24\0:\6"
    "QC\212,;\11r:\232\34H\24\0<\7SF\252\244V=\10\65J\213A\35\4>\10SF"
    "\212\254R\2\77\13uB\233%\13\263:\24\1@\16\205>\233%\223\226DI\224!]\0A\14u"
    "B\253\60K\242$Z\62-B\15uB\213!\311\264A\311\264A\1C\12uB\233%\23\333\222\5"
    "D\13uB\213!\311\274\15\12\0E\13uB\213c\70$a\70\10F\12uB\213c\70$a\21"
    "G\13uB\233%\23K[\62\4H\12uB\213\314\66\14\231-I\10sB\212%\352\62J\12t"
    "\302\272\66IJ\24\0K\15uB\213LJJZ\22U\262\0L\10t\302\212\254\267!M\16wB"
    "\214t\33\262\245\242T\244H*N\13uB\213l\232\224D\272\5O\12uB\233%\363\226,\0P"
    "\14uB\213!\311\264A\11\213\0Q\13uB\233%sI\244H\11R\15uB\213!\311\264A\211"
    "\222L\13S\13uB\233%SW-Y\0T\11uB\213A\12{\2U\11uB\213\314\267d\1"
    "V\15uB\213LKJI\224da\4W\20wB\214(\222\42)R*J\267(K\0X\13u"
    "B\213LKj\225\232\26Y\14uB\213LKJI\26\226\0Z\12uB\213A\314:\16\2[\11"
    "\223\77\213!\352\323\0\134\13\224\276\212,\314\302\254\230\5]\11\223\77\213\251OC\0^\6#V\232"
    "\6_\6\24\272\212!`\6\42\327\212(a\11T\302\32\61\31\242db\13t\302\212,[\42\323\220"
    "\0c\12T\302\32%\322\242D\1d\12t\302\272\312\20\231\222\1e\11T\302\32%\32F\5f\12"
    "t\302*%\32\222\254\11g\13t\272\232!\62%[\242\0h\12t\302\212,[\42\247\0i\10s"
    "B\232Pj\31j\11\223:\252l\352\264\0k\13t\302\212\254\244$RR\12l\10sB\12\251'"
    "\1m\13UB\13\245EI\224D)n\10T\302\212%r\12o\12T\302\32%\62%\12\0p\13"
    "t\272\212%\62\15I\226\1q\12t\272\232!\62%[\1r\12T\302\212d\210\262\32\0s\11T"
    "\302\232!\24\207\4t\12t\302\232,\32\222\254(u\10T\302\212\310)\31v\13UB\213LKJ"
    "I\26\1w\14UB\213$Q\22\245S\222\0x\12UB\213,\251Uj\1y\15u:\213LK"
    "JI\26F\32\0z\11T\302\212!j\33\2{\12\224\277+%+\205YQ|\6\221\77\212\7}"
    "\13\224\277\13\61+FYE\2~\11\65J\233,\251%\0\0\0\0\4\377\377N\216\23\231>\235a"
    "Hs$G\302\341\230#\71\22\217\0Qe\24\231>\255\34\312\241\34\311\201$N\322\254\232\344@\0"
    "Qh\23\231>\275\65\253&\311\240\204\351\60\244\71\22\16\7Qs\23\231>\235\64\253\15C\232#\341"
    "pK\322,R\5Q\231\24\231>\215\207$\215\206-G\206\35I\206%G\322\11Q\373\23\231>\315"
    "\34I\207!\15\207c\32\365\64\14\11\0R\237\27\231>\355h\253\14K\26%Y\224dQ\22eC"
    "\222\305\12\0S:\25\231>\215\207\34\211\262$K\242\60\253D\211\226\344\310pSs\33\231>\215!"
    "\31\244$\32\224HJ\42)\211\6%R\242HJ\222A\321\0T\15\22\231>\275\34\70\211ITV"
    "\207K\230\205\331\60V\336\27\231>\215\207\34P\6E\311\22%K\224,Q\6E\7\36\2Y\7\25"
    "\231>\255a\31\263AK\223\341\22\225\206!j\32\206\4[\211\23\231>\315p\70\344@\226\16\247,"
    "\314\302!\23\7[\214\24\231>\315p\70\344\200\62(\71\64\334\222\64\212\266![\306\26\231>\315p"
    "\70Da\222%\335\242a\221\322\250\64\14\11\0b\20\26\231>\335$\32\6%\13\227R\322\224\64%"
    "Q\66%\232\42g:\30\231>\255d\310\222(\31\244,\211\42%\212\224(iJ\332\42\61g\345\24"
    "\231>\315p\70%\265\250\62\134\322h\30\242\64\31\16p\271\24\231>\315\34\31\304t\30\242\64\32\206"
    "\34L\272%\5w\13\24\231>\215\307t\30\302t\70\205\321\60$\305lX\0\213\276\26\231>\235h"
    "\310\222(\215\22)Rr$\31\244&[\42\11\217\324\26\231>\215lP\242\60\33\224(\13\223d\224"
    "\42K\34\15\3\224\245\30\231>\235hP\206L\33\16Y\22e\303!\211\262D\311\222\232\0\226\217\31"
    "\231>\215\61I\224A\311\42E\31\222dQ*\303R\321\302(\31\2\227b\27\231>\215\307p\70$"
    "Y\242\14\212\222%\312\240(Y\62\34\2\230u\20\231>\215\307t\30\242\64\352\227\266\222*\0";

static uint8_t enclave_factory_keys[11][32] = {
    {0xC4, 0x5A, 0x4A, 0xBF, 0x29, 0x8B, 0x75, 0x39, 0x39, 0x55, 0xB9,
     0x1A, 0xCD, 0x45, 0x57, 0xF8, 0x12, 0xD2, 0x2B, 0x26, 0x0C, 0x7F,
     0x5C, 0x7E, 0xD7, 0xBC, 0x3F, 0x24, 0x98, 0xB4, 0x35, 0x8D},
    {0x6C, 0xAE, 0xB3, 0xA0, 0xE3, 0xDF, 0xEA, 0x45, 0x97, 0xC7, 0x33,
     0x64, 0x43, 0xC4, 0x4F, 0xEB, 0x59, 0x22, 0xF8, 0xB1, 0xD7, 0x84,
     0xF0, 0x14, 0x87, 0x11, 0x89, 0x0D, 0x3F, 0xAF, 0x12, 0x0D},
    {0xEE, 0x7D, 0x67, 0x3E, 0x14, 0x22, 0xFC, 0xA6, 0x06, 0xE7, 0x4B,
     0x54, 0x3D, 0xAE, 0x10, 0xCB, 0xBE, 0x11, 0xA4, 0xF5, 0x2B, 0x41,
     0xF1, 0x40, 0x54, 0x71, 0x96, 0x0B, 0xC3, 0x55, 0x0E, 0xAC},
    {0x8E, 0xD8, 0xE3, 0x35, 0xC3, 0xF6, 0x7C, 0xDA, 0x65, 0x37, 0xAF,
     0x20, 0x73, 0x4F, 0xE2, 0x71, 0xD4, 0x76, 0xA8, 0xDF, 0x78, 0x26,
     0x6B, 0x76, 0xCB, 0x68, 0x1C, 0xDF, 0x91, 0x3C, 0xC1, 0x11},
    {0x1B, 0x16, 0x5C, 0x8E, 0x2B, 0x87, 0xBB, 0xEC, 0x9D, 0x4F, 0x37,
     0x72, 0x29, 0xDC, 0x92, 0x91, 0x4D, 0xF6, 0xFA, 0xF8, 0xDB, 0x65,
     0xD8, 0x61, 0x0C, 0x91, 0xC3, 0x1A, 0x68, 0x8B, 0x0E, 0x43},
    {0x69, 0xCA, 0x2A, 0xF1, 0x6C, 0x2C, 0x83, 0xDA, 0xB4, 0x1B, 0xAF,
     0x08, 0xB3, 0xDB, 0x1A, 0x69, 0x0C, 0x18, 0xA1, 0xF7, 0x75, 0x6F,
     0x59, 0xE2, 0xD8, 0x59, 0x6B, 0x81, 0x62, 0xE1, 0xB7, 0xD1},
    {0x85, 0x9C, 0x6B, 0x18, 0xA4, 0x54, 0x72, 0x6A, 0x2C, 0xAA, 0x2F,
     0x20, 0xA8, 0x7F, 0xBB, 0x05, 0x36, 0x83, 0xF7, 0x1A, 0x77, 0x9A,
     0x2F, 0x2B, 0x47, 0xA6, 0x6E, 0x6F, 0xA5, 0x5D, 0xB6, 0xFF},
    {0xC7, 0xF6, 0x82, 0x10, 0x41, 0x20, 0x83, 0xEC, 0x4D, 0x04, 0x35,
     0x60, 0x3A, 0x79, 0xC1, 0xF1, 0x19, 0x2B, 0x0C, 0xC1, 0xD5, 0xEB,
     0x11, 0x80, 0xB6, 0x8D, 0x37, 0x47, 0x0E, 0x5C, 0x6E, 0x3D},
    {0x1C, 0x5B, 0x78, 0x40, 0xC1, 0xB9, 0x10, 0x25, 0x65, 0x33, 0xAB,
     0x5C, 0x94, 0xC8, 0x35, 0xCD, 0x8E, 0x54, 0xFC, 0xF2, 0x0F, 0xF3,
     0x75, 0xF0, 0xE8, 0x7F, 0x1F, 0x81, 0x18, 0x76, 0x5F, 0x4C},
    {0x96, 0xD3, 0xB1, 0xC3, 0x0E, 0x05, 0xA5, 0x76, 0xF1, 0x4C, 0x25,
     0xBF, 0x7E, 0xA3, 0x6B, 0x56, 0xE0, 0x19, 0x20, 0x08, 0xB9, 0x01,
     0xE3, 0x53, 0x34, 0x20, 0xB5, 0x5A, 0x3D, 0xBC, 0x86, 0x26},
    {0x69, 0x44, 0x2E, 0xF3, 0x3A, 0xDA, 0xA9, 0xFF, 0x9B, 0xEE, 0x7D,
     0x59, 0x77, 0x63, 0xAA, 0xF5, 0x4D, 0x9C, 0xE8, 0x14, 0xFC, 0xE6,
     0xE3, 0xBB, 0xFD, 0x64, 0xAD, 0x2B, 0x70, 0x28, 0xEE, 0x81},
};

static const uint8_t enclave_signature_iv[ENCLAVE_FACTORY_KEY_SLOTS][16] = {
    {0xac, 0x5d, 0x68, 0xb8, 0x79, 0x74, 0xfc, 0x7f, 0x45, 0x02, 0x82, 0xf1, 0x48, 0x7e, 0x75, 0x8a},
    {0x38, 0xe6, 0x6a, 0x90, 0x5e, 0x5b, 0x8a, 0xa6, 0x70, 0x30, 0x04, 0x72, 0xc2, 0x42, 0xea, 0xaf},
    {0x73, 0xd5, 0x8e, 0xfb, 0x0f, 0x4b, 0xa9, 0x79, 0x0f, 0xde, 0x0e, 0x53, 0x44, 0x7d, 0xaa, 0xfd},
    {0x3c, 0x9a, 0xf4, 0x43, 0x2b, 0xfe, 0xea, 0xae, 0x8c, 0xc6, 0xd1, 0x60, 0xd2, 0x96, 0x64, 0xa9},
    {0x10, 0xac, 0x7b, 0x63, 0x03, 0x7f, 0x43, 0x18, 0xec, 0x9d, 0x9c, 0xc4, 0x01, 0xdc, 0x35, 0xa7},
    {0x26, 0x21, 0x64, 0xe6, 0xd0, 0xf2, 0x47, 0x49, 0xdc, 0x36, 0xcd, 0x68, 0x0c, 0x91, 0x03, 0x44},
    {0x7a, 0xbd, 0xce, 0x9c, 0x24, 0x7a, 0x2a, 0xb1, 0x3c, 0x4f, 0x5a, 0x7d, 0x80, 0x3e, 0xfc, 0x0d},
    {0xcd, 0xdd, 0xd3, 0x02, 0x85, 0x65, 0x43, 0x83, 0xf9, 0xac, 0x75, 0x2f, 0x21, 0xef, 0x28, 0x6b},
    {0xab, 0x73, 0x70, 0xe8, 0xe2, 0x56, 0x0f, 0x58, 0xab, 0x29, 0xa5, 0xb1, 0x13, 0x47, 0x5e, 0xe8},
    {0x4f, 0x3c, 0x43, 0x77, 0xde, 0xed, 0x79, 0xa1, 0x8d, 0x4c, 0x1f, 0xfd, 0xdb, 0x96, 0x87, 0x2e},
};

static const uint8_t enclave_signature_input[ENCLAVE_FACTORY_KEY_SLOTS][ENCLAVE_SIGNATURE_SIZE] = {
    {0x9f, 0x5c, 0xb1, 0x43, 0x17, 0x53, 0x18, 0x8c, 0x66, 0x3d, 0x39, 0x45, 0x90, 0x13, 0xa9, 0xde},
    {0xc5, 0x98, 0xe9, 0x17, 0xb8, 0x97, 0x9e, 0x03, 0x33, 0x14, 0x13, 0x8f, 0xce, 0x74, 0x0d, 0x54},
    {0x34, 0xba, 0x99, 0x59, 0x9f, 0x70, 0x67, 0xe9, 0x09, 0xee, 0x64, 0x0e, 0xb3, 0xba, 0xfb, 0x75},
    {0xdc, 0xfa, 0x6c, 0x9a, 0x6f, 0x0a, 0x3e, 0xdc, 0x42, 0xf6, 0xae, 0x0d, 0x3c, 0xf7, 0x83, 0xaf},
    {0xea, 0x2d, 0xe3, 0x1f, 0x02, 0x99, 0x1a, 0x7e, 0x6d, 0x93, 0x4c, 0xb5, 0x42, 0xf0, 0x7a, 0x9b},
    {0x53, 0x5e, 0x04, 0xa2, 0x49, 0xa0, 0x73, 0x49, 0x56, 0xb0, 0x88, 0x8c, 0x12, 0xa0, 0xe4, 0x18},
    {0x7d, 0xa7, 0xc5, 0x21, 0x7f, 0x12, 0x95, 0xdd, 0x4d, 0x77, 0x01, 0xfa, 0x71, 0x88, 0x2b, 0x7f},
    {0xdc, 0x9b, 0xc5, 0xa7, 0x6b, 0x84, 0x5c, 0x37, 0x7c, 0xec, 0x05, 0xa1, 0x9f, 0x91, 0x17, 0x3b},
    {0xea, 0xcf, 0xd9, 0x9b, 0x86, 0xcd, 0x2b, 0x43, 0x54, 0x45, 0x82, 0xc6, 0xfe, 0x73, 0x1a, 0x1a},
    {0x77, 0xb8, 0x1b, 0x90, 0xb4, 0xb7, 0x32, 0x76, 0x8f, 0x8a, 0x57, 0x06, 0xc7, 0xdd, 0x08, 0x90},
};

static const uint8_t enclave_signature_expected[ENCLAVE_FACTORY_KEY_SLOTS][ENCLAVE_SIGNATURE_SIZE] = {
    // key_slot 0
    {0x3D, 0x93, 0x55, 0xE9, 0x2C, 0x3F, 0xD8, 0x12, 0x44, 0x76, 0x94, 0xB4, 0x9A, 0xDB, 0x1A, 0x66},

    // key_slot 1
    {0x5A, 0x3C, 0xAF, 0x24, 0xD2, 0xEA, 0x02, 0x6A, 0xF3, 0xA3, 0x0D, 0xA7, 0x27, 0x7B, 0x80, 0x6A},

    // key_slot 2
    {0xCD, 0x6B, 0x58, 0xF5, 0xFE, 0x59, 0x1C, 0xFC, 0x72, 0x27, 0xEF, 0xC2, 0x5B, 0x81, 0x72, 0x56},

    // key_slot 3
    {0x06, 0x88, 0xD2, 0xE4, 0x1C, 0x06, 0x20, 0xEB, 0xFF, 0x57, 0x58, 0x26, 0xF3, 0x3E, 0x50, 0xAE},

    // key_slot 4
    {0x14, 0xB5, 0x46, 0x30, 0xE8, 0xE5, 0x34, 0x87, 0x0C, 0xCD, 0x7F, 0x1A, 0x27, 0x2C, 0x8D, 0x39},

    // key_slot 5
    {0x35, 0xBD, 0x30, 0xC2, 0x52, 0x9C, 0xDF, 0x3A, 0xEF, 0x5A, 0x96, 0x05, 0xC9, 0x8B, 0xD6, 0xEF},

    // key_slot 6
    {0xFB, 0x67, 0x49, 0x50, 0x55, 0x43, 0xB4, 0x8C, 0xF1, 0xE4, 0xB3, 0xF0, 0x33, 0x37, 0x8E, 0xB6},

    // key_slot 7
    {0x29, 0xA8, 0xC5, 0xAD, 0xC2, 0x6C, 0x60, 0xAE, 0x34, 0x66, 0x35, 0x7F, 0x20, 0xA0, 0x3D, 0xCE},

    // key_slot 8
    {0x8D, 0x02, 0xD5, 0x73, 0xEA, 0x63, 0x51, 0x9D, 0x10, 0x0B, 0xA9, 0x6D, 0xA6, 0x39, 0xB4, 0x99},

    // key_slot 9
    {0xF3, 0xCD, 0xA7, 0x52, 0x09, 0x14, 0x2E, 0x3A, 0x2E, 0xD5, 0x66, 0xCF, 0xB2, 0xA9, 0xDC, 0xA1},

};
// 绘制屏幕(app_draw_callback)分辨率 128x64 px
static void app_draw_callback(Canvas* canvas, void* ctx) {
    UNUSED(ctx);

    canvas_clear(canvas);
    // canvas_set_custom_u8g2_font(canvas, kalicyh);

    char draw_str[44] = {};

    snprintf(draw_str, sizeof(draw_str), "设备名: %s", furi_hal_version_get_name_ptr());
    canvas_draw_str_aligned(canvas, 0, 2, AlignLeft, AlignTop, draw_str);

    canvas_draw_icon(canvas, 100, 3, &I_ButtonUp_7x4);
    canvas_draw_str_aligned(canvas, 128, 2, AlignRight, AlignTop, "关于");

    canvas_draw_line(canvas, 0, 12, 128, 12); // 横线

    canvas_draw_str_aligned(canvas, 64, 20, AlignCenter, AlignTop, "安全区随机密钥写入");

    canvas_draw_icon(canvas, 45, 45, &I_ButtonCenter_7x7);
    canvas_draw_str_aligned(canvas, 64, 45, AlignCenter, AlignTop, "点击  即完成写入");
}

static void app_draw_down(Canvas* canvas, void* ctx) {
    UNUSED(ctx);

    canvas_clear(canvas);
    canvas_set_custom_u8g2_font(canvas, kalicyh);

    char draw_str[44] = {};

    snprintf(draw_str, sizeof(draw_str), "设备名: %s", furi_hal_version_get_name_ptr());
    canvas_draw_str_aligned(canvas, 0, 2, AlignLeft, AlignTop, draw_str);
    // canvas_draw_icon(canvas, 1, 15, &I_ButtonDown_7x4);
    // canvas_draw_icon(canvas, 2, 23, &I_ButtonLeft_4x7);
    // canvas_draw_icon(canvas, 2, 33, &I_ButtonRight_4x7);

    canvas_draw_icon(canvas, 95, 3, &I_ButtonUp_7x4);
    canvas_draw_str_aligned(canvas, 128, 2, AlignRight, AlignTop, "关于");

    canvas_draw_line(canvas, 0, 12, 128, 12); // 横线

    canvas_draw_str_aligned(canvas, 64, 35, AlignCenter, AlignTop, "写入成功");

    canvas_draw_icon(canvas, 43, 55, &I_ButtonLeft_4x7);
    canvas_draw_str_aligned(canvas, 64, 55, AlignCenter, AlignTop, "点击  返回");
}

// static void app_about(Canvas* canvas, void* ctx) {
//     UNUSED(ctx);

//     canvas_clear(canvas);
//     canvas_set_custom_u8g2_font(canvas, kalicyh);

//     char draw_str[44] = {};

//     snprintf(draw_str, sizeof(draw_str), "设备名: %s", furi_hal_version_get_name_ptr());
//     canvas_draw_str_aligned(canvas, 0, 2, AlignLeft, AlignTop, draw_str);

//     canvas_draw_icon(canvas, 95, 3, &I_ButtonUp_7x4);
//     canvas_draw_str_aligned(canvas, 128, 2, AlignRight, AlignTop, "关于");

//     canvas_draw_line(canvas, 0, 12, 128, 12); // 横线

//     canvas_draw_str_aligned(canvas, 64, 35, AlignCenter, AlignTop, "关于页面");

//     canvas_draw_icon(canvas, 40, 55, &I_ButtonLeft_4x7);
//     canvas_draw_str_aligned(canvas, 64, 55, AlignCenter, AlignTop, "点击  返回");
// }

static void app_view(Canvas* canvas, void* ctx) {
    UNUSED(ctx);

    canvas_clear(canvas);
    canvas_set_custom_u8g2_font(canvas, kalicyh);

    char draw_str[44] = {};

    snprintf(draw_str, sizeof(draw_str), "设备名: %s", furi_hal_version_get_name_ptr());
    canvas_draw_str_aligned(canvas, 0, 2, AlignLeft, AlignTop, draw_str);

    canvas_draw_icon(canvas, 95, 3, &I_ButtonUp_7x4);
    canvas_draw_str_aligned(canvas, 128, 2, AlignRight, AlignTop, "关于");

    canvas_draw_line(canvas, 0, 12, 128, 12); // 横线

    canvas_draw_str_aligned(canvas, 64, 35, AlignCenter, AlignTop, "设备查看页面");
    canvas_draw_icon(canvas, 40, 55, &I_ButtonLeft_4x7);
    canvas_draw_str_aligned(canvas, 64, 55, AlignCenter, AlignTop, "点击  返回");
}

// 监听按键输入(app_input_callback)
static void app_input_callback(InputEvent* input_event, void* ctx) {
    furi_assert(ctx);

    FuriMessageQueue* event_queue = ctx;
    furi_message_queue_put(event_queue, input_event, FuriWaitForever);
}

static bool furi_hal_crypto_generate_unique_keys(uint8_t start_slot, uint8_t end_slot) {
    FuriHalCryptoKey key;
    uint8_t key_data[32];
    for(uint8_t slot = start_slot; slot <= end_slot; slot++) {
        key.type = FuriHalCryptoKeyTypeSimple;
        key.size = FuriHalCryptoKeySize256;
        key.data = key_data;
        furi_hal_random_fill_buf(key_data, 32);
        if(!furi_hal_crypto_enclave_store_key(&key, &slot)) {
            return false;
        }
    }
    return true;
}

static bool write_factory_keys(uint8_t start_slot, uint8_t end_slot) {
    FuriHalCryptoKey key;
    FURI_LOG_I(TAG, "Writing factory keys %u..%u", start_slot, end_slot);

    // Add Master key
    if(start_slot == 0) {
        uint8_t slot_master = 0;
        key.type = FuriHalCryptoKeyTypeMaster;
        key.size = FuriHalCryptoKeySize256;
        key.data = enclave_factory_keys[0];
        if(!furi_hal_crypto_enclave_store_key(&key, &start_slot)) {
            FURI_LOG_E(TAG, "Error writing key to slot %u", slot_master);
            // record_failure(0);
        }
    }

    // Add Secure keys
    for(uint8_t slot = start_slot + 1; slot <= end_slot; slot++) {
        key.type = FuriHalCryptoKeyTypeEncrypted;
        key.size = FuriHalCryptoKeySize256;
        key.data = enclave_factory_keys[slot];
        if(!furi_hal_crypto_enclave_store_key(&key, &slot)) {
            FURI_LOG_E(TAG, "Error writing key to slot %u", slot);
            // record_failure(slot);
        }
    }
    return true;
}

bool verify_key_slot(size_t key_slot) {
    uint8_t buffer[ENCLAVE_SIGNATURE_SIZE];

    // 加载指定的密钥
    if(furi_hal_crypto_enclave_load_key(key_slot + 1, enclave_signature_iv[key_slot])) {
        // 执行加密
        if(furi_hal_crypto_encrypt(
               enclave_signature_input[key_slot], buffer, ENCLAVE_SIGNATURE_SIZE)) {
            // 比较加密结果
            bool is_valid =
                memcmp(buffer, enclave_signature_expected[key_slot], ENCLAVE_SIGNATURE_SIZE) == 0;

            // 卸载密钥
            furi_hal_crypto_enclave_unload_key(key_slot + 1);

            // 输出日志
            FURI_LOG_I(TAG, "key_slot: %zu", key_slot);
            // FURI_LOG_I(TAG, "iv: ");
            // for(size_t i = 0; i < 16; i++) {
            //     FURI_LOG_I(TAG, "%02X ", enclave_signature_iv[key_slot][i]);
            // }
            // FURI_LOG_I(TAG, "\ninput: ");
            // for(size_t i = 0; i < ENCLAVE_SIGNATURE_SIZE; i++) {
            //     FURI_LOG_I(TAG, "%02X ", enclave_signature_input[key_slot][i]);
            // }
            // FURI_LOG_I(TAG, "\nbuffer: ");
            // for(size_t i = 0; i < ENCLAVE_SIGNATURE_SIZE; i++) {
            //     FURI_LOG_I(TAG, "%02X ", buffer[i]);
            // }
            // FURI_LOG_I(TAG, "\nexp: ");
            // for(size_t i = 0; i < ENCLAVE_SIGNATURE_SIZE; i++) {
            //     FURI_LOG_I(TAG, "%02X ", enclave_signature_expected[key_slot][i]);
            // }
            FURI_LOG_I(TAG, "\n");

            return is_valid; // 返回密钥是否有效
        }
        // 卸载密钥失败时的处理
        furi_hal_crypto_enclave_unload_key(key_slot + 1);
    }
    return false; // 加载密钥失败
}

void verify_key_slots(size_t start_slot, size_t end_slot) {
    for(size_t slot = start_slot; slot <= end_slot; slot++) {
        if(verify_key_slot(slot)) {
            FURI_LOG_I(TAG, "Key in slot %u is valid", slot);
        } else {
            FURI_LOG_E(TAG, "Error writing key to slot %u", slot);
        }
    }
}

int32_t factory_u2f_crack_app(void* p) {
    // 必须有
    UNUSED(p);

    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));

    // 配置程序视图端口
    ViewPort* view_port = view_port_alloc();
    // 绘制屏幕(app_draw_callback)
    view_port_draw_callback_set(view_port, app_draw_callback, NULL);
    // 监听按键输入(app_input_callback)
    view_port_input_callback_set(view_port, app_input_callback, event_queue);

    // 在GUI中注册程序视图端口
    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    InputEvent event;

    // 检测按键输入
    bool running = true;
    while(running) {
        if(furi_message_queue_get(event_queue, &event, 100) == FuriStatusOk) {
            if((event.type == InputTypePress) || event.type == InputTypeLong ||
               (event.type == InputTypeRepeat)) {
                switch(event.key) {
                // 按返回键
                case InputKeyBack:
                    // 退出程序
                    running = false;
                    break;
                // 按确认键
                case InputKeyOk:
                    furi_hal_crypto_generate_unique_keys(0, 10);
                    view_port_draw_callback_set(view_port, app_draw_down, NULL);
                    break;
                // 按左键
                case InputKeyLeft:
                    view_port_draw_callback_set(view_port, app_draw_callback, NULL);
                    break;
                // 按右键
                case InputKeyRight:
                    view_port_draw_callback_set(view_port, app_view, NULL);
                    break;
                // 按上键
                case InputKeyUp:
                    // view_port_draw_callback_set(view_port, app_about, NULL);
                    verify_key_slots(0, 9);
                    break;
                // 按下键
                case InputKeyDown:
                    write_factory_keys(0, 0);
                    write_factory_keys(20, 30);
                    view_port_draw_callback_set(view_port, app_draw_down, NULL);
                    break;
                default:
                    break;
                }
            }
        }
    }

    // 禁用程序视图端口
    view_port_enabled_set(view_port, false);
    // 在GUI中注销程序视图端口
    gui_remove_view_port(gui, view_port);
    // 释放程序视图端口
    view_port_free(view_port);
    // 释放消息队列(返回键)
    furi_message_queue_free(event_queue);
    // 关闭程序视图端口
    furi_record_close(RECORD_GUI);
    // 程序结束
    return 0;
}
