#include <furi.h>
#include <furi_hal.h>
#include <gui/gui.h>
#include <input/input.h>
#include "factory_u2f_crack_icons.h"

static const uint8_t kalicyh[1753] =
    "z\0\3\2\4\4\3\4\5\13\15\0\376\10\376\12\377\1a\2\317\4\30 \5\0L\13!\7\221F"
    "\213S\0\42\7\64}\213\310\24#\16\226\304\233\250eX\242^\206%j\1$\17\245<\253l\251("
    "\231\250%Je\213\0%\20\226<\233(\351\242%a\232DI\27-\1&\16\205D\253,\211\222\254"
    "\62%Q\244\4'\6\61\376\212\1(\13\263=\253$J\242nQ\26)\14\263=\213,\312\242.Q"
    "\22\1*\14uD\253J\345\240,M\21\0+\13wD\274\270\66\14Y\134\3,\7\62>\13E\1"
    "-\6\25d\213A.\6!\306\12\1/\14\304<\273\246\254\224\225\262\32\0\60\12\205D\233%\363-"
    "Y\0\61\11\205D\213\261O\203\0\62\13\205D\233%\13km\203\0\63\14\205D\213!\15\223\65\14"
    "\7\5\64\16\206\304;-\211\272d\311\60\246\11\0\65\15\205D\213!\11\303!\15\303A\1\66\15\205"
    "D\233%\14\207$\263%\13\0\67\13\205D\213A\254\205YX\2\70\15\205D\233%\323\222%\263%"
    "\13\0\71\15\205D\233%\263%C\250%\13\0:\6aD\11I;\11\202>\213!V\24\0<\10"
    "\225D\313\254k\7=\10\65\134\213A\35\4>\11\225D\213\264[G\0\77\15\225D\233%\323\302H"
    "\313\241\60\2@\24\247<\254\255\222HZ\42)JE\251H\211\222e\23\0A\16\207D\274\70M\302"
    "$+\15J\252\6B\15\206\304\213A\11\305a\11\215\303\2C\14\206\304\233!\11\325\216\311\220\0D"
    "\15\207D\214A\12\223\324c\62H\0E\12\205D\213c\70\214\305AF\13\205D\213c\70$a#"
    "\0G\15\206\304\233!\11\325\332(&\203\0H\13\206\304\213\320\70\14\242c\0I\10\203D\212%\352"
    "eJ\10\243\64\252\376\264\0K\15\205D\213LJJ\232\226D\225,L\11\205D\213\260\217\203\0M"
    "\20\207D\14m\310\226\212R\221\42)R\325\0N\15\206\304\213pS\42)\321Fc\0O\14\207D"
    "\254\255\222\272&Y\66\1P\14\205D\213!\311l\203\22\26\1Q\16\227<\254\255\222\272&Y\266\3"
    "\11\0R\20\206\304\213!\312\222,\311\222!jK\302\0S\14\205D\233AL\327\60\34\24\0T\11"
    "\207D\214C\26\367\15U\12\206\304\213\320\217\311\220\0V\17\207D\214TM\262(\253\204I\32g\0"
    "W\21\211D\215,\323\62\255\322)iJ\332\212Y\4X\15\206\304\213PL\242L\213ZB\61Y\13"
    "\207D\214\64\311*i\334\15Z\12\207D\214C\332\347a\10[\11\263>\213!\352O\3\134\14\245<"
    "\213\60\15\323\60\15\323\60]\11\263=\213\251\77\15\1^\10\65t\253,\251\5_\6\25<\213A`"
    "\7\62\375\212$\12a\14eD\233%K\6MK\206\0b\14\205D\213\60\34\222\314mP\0c\10"
    "d\304\232!k\34d\13\205D\313\312\240\271%C\0e\13eD\233%\33\206\60\35\2f\11\203D"
    "\232i\210:\1g\14\205\64\233AsK\206\60Y\0h\13\205D\213\60\34\222\314[\0i\7\201D"
    "\211d\30j\10\242\264\231,\351ek\15\205D\213\260\224\224\264$\252d\1l\7\201D\211\203\0m"
    "\16gD\214E\211\42)\222\42)\222\12n\11eD\213!\311\274\5o\12eD\233%sK\26\0"
    "p\14\205\64\213!\311\334\6%\14\1q\13\205\64\233AsK\206\260\0r\10cD\212!\352\4s"
    "\14eD\233%K\324$K\26\0t\12\203D\212(\32\242\66\1u\11eD\213\314[\62\4v\14"
    "eD\213LKJI\26F\0w\16gD\214(\222\42\245\242t\213\262\4x\13eD\213,\251U"
    "jZ\0y\15\205\64\213LKJI\26fa\6z\12eD\213A\314\332\6\1{\13\243<\252$"
    "\252dQ[\0|\7\261\276\212\7\1}\13\243<\212,\252%QK\4~\7&\334\33\311\2\200\17"
    "\225D+\251\222\15Q\66Da\24)\0\0\0\0\4\377\377N\216\27\273<\236\341\234c\71\226\16\7"
    "\65\307r,\307r,GV\0Qe\30\273<>\35\314\261\34\313\241$G\352@\26gi-\7\222"
    "\34\12Qh\31\273<\336\34Jr KK\312\240\250\71\226#\203\216\344X<\134\0Qs\27\273<"
    "\256\264\26\16\347\34K\207C\234CI\16diI\7\4Q\231\34\273<\236\341\220\344\210\224\206\303\232"
    "c\303\220c\321\60$\71\226\3I\16e\0Q\373\26\273<\336\34\213\207s\216\245\303A\215\263RV"
    "\312J\303\5R\237\32\273<~ \307\262AJ\243a\12\243bT\214\242%\33\263\64\314,\0S:"
    "\32\272=\216\227\34J\302\250\26eI\26\326\222,\312\242$\214rh\70\4Ss\36\272=\216A\31"
    "\264$\32\226HK\242a\211\264$R\262H\212\24\245\213\224\344P\6T\15\31\272<\276\34\32\206,"
    "\314\222(\313t$\7\36\324,\315\322l\30\2V\336\30\272=\216\7\35\321\21i\210\244\222T\222\206"
    "H*\351\310\360\216\4Y\7\31\273<\276\34\33F-\214v$Q\305\341\61*\16C\30\25\207!\2"
    "[\211\30\273<\336x\70$\71\242\205i<\34\264\252\226\3;\22i\253\0[\214\33\273<\336x\70"
    "$\71\42\15J\16\17\207\60\311\201(\7\242,\312*\351\20[\306\32\273<\336tx\253\364\26\65&"
    "Q\62$\203\222\346@T\214\212\303\20\1b\20\33\273<\356$G\242h\70$a\32\246C\22\265D"
    "-\265\250\245\224$b&g:\34\273<\256\34\213\206\60*\15S\30\325\226(S\244J\324\22\25\223"
    ",\211\304\1g\345\31\273<\336t\70hI\65*\15\7)\15\207!L\303a\310\341\341 p\271\30"
    "\273<\336\34\313\261A\316\201C\230\206i\70\14\71!\211*YTw\13\32\273<\236\341\34\17\203\34"
    "\17\7-\14\207!K\302(\32\326\60\35&\0\213\276\32\273<\236l\10\243:\20\305\331\260c\311\260"
    "EYK\250\245Y\222n\2\217\324\35\273<\236\34\220\242!\214rl\70iQ\245\26\25\223(\311\42"
    "-\251\3\331\60\4\224\245 \273<\236pP\302,\31\222L\35\16I\26e\331\260\14RVJj\221"
    "\22%Q\22&\0\226\217 \273<\216\61K\224aH\32\265A\251EIrH:%R\62$Y\22"
    "%\231\32E\203\0\227b\30\272=\216\207\60G\342\341 \225\244!\222J\322\20I\245\341\35\11\230u"
    "\31\273<\216\7\65\7\16a\32F\305\250\30\25#%\216\342P\222\23\0\0";

// 绘制屏幕(app_draw_callback)分辨率 128x64 px
static void app_draw_callback(Canvas* canvas, void* ctx) {
    UNUSED(ctx);

    canvas_clear(canvas);
    canvas_set_custom_u8g2_font(canvas, kalicyh);

    char draw_str[44] = {};

    snprintf(draw_str, sizeof(draw_str), "设备名: %s", furi_hal_version_get_name_ptr());
    canvas_draw_str_aligned(canvas, 0, 2, AlignLeft, AlignTop, draw_str);

    canvas_draw_icon(canvas, 95, 3, &I_ButtonUp_7x4);
    canvas_draw_str_aligned(canvas, 128, 2, AlignRight, AlignTop, "关于");

    canvas_draw_line(canvas, 0, 12, 128, 12); // 横线

    canvas_draw_str_aligned(canvas, 64, 20, AlignCenter, AlignTop, "安全区随机密钥写入");

    canvas_draw_icon(canvas, 43, 45, &I_ButtonCenter_7x7);
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

    canvas_draw_icon(canvas, 40, 55, &I_ButtonLeft_4x7);
    canvas_draw_str_aligned(canvas, 64, 55, AlignCenter, AlignTop, "点击  返回");
}

static void app_about(Canvas* canvas, void* ctx) {
    UNUSED(ctx);

    canvas_clear(canvas);
    canvas_set_custom_u8g2_font(canvas, kalicyh);

    char draw_str[44] = {};

    snprintf(draw_str, sizeof(draw_str), "设备名: %s", furi_hal_version_get_name_ptr());
    canvas_draw_str_aligned(canvas, 0, 2, AlignLeft, AlignTop, draw_str);

    canvas_draw_icon(canvas, 95, 3, &I_ButtonUp_7x4);
    canvas_draw_str_aligned(canvas, 128, 2, AlignRight, AlignTop, "关于");

    canvas_draw_line(canvas, 0, 12, 128, 12); // 横线

    canvas_draw_str_aligned(canvas, 64, 35, AlignCenter, AlignTop, "关于页面");

    canvas_draw_icon(canvas, 40, 55, &I_ButtonLeft_4x7);
    canvas_draw_str_aligned(canvas, 64, 55, AlignCenter, AlignTop, "点击  返回");
}

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
                    view_port_draw_callback_set(view_port, app_about, NULL);
                    break;
                // 按下键
                case InputKeyDown:
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
