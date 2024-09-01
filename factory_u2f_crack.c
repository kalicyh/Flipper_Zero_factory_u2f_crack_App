#include <furi.h>
#include <furi_hal.h>
// 用于图形显示
#include <gui/gui.h>
// 用于按键操作
#include <input/input.h>

static const uint8_t zhairen_font[] =
    "\223\0\3\2\4\4\2\4\5\11\12\0\376\7\376\10\377\1\71\2\177\3\230 "
    "\5\0f\4!\7q\242"
    "\304\240\4\42\7\63\62Eb\11#\13U\246MeP*\203R\1$\16\225\236U\266T\224lK\224"
    "\312\26\1%\13u\242M\226t\253tK\0&\14u\242\215T\251U\22)R\2'\6\61\262\304\0"
    "(\10\223\36UR\352V)\11\223\36EV\352R\2*\12U\252U\245\262\64E\0+\12U\246U"
    "\30\15R\30\1,\7\62\336L\242\0-\6\24n\305\20.\6\21\242D\0/"
    "\13\204^])\213\262"
    "(\313\0\60\14u\242\315\222IK\62i\311\2\61\11u\242U\64v\32\4\62\12u\242\315"
    "\222\205Y"
    "\333 "
    "\63\14u\242\315\222\205\221\252%\13\0\64\14u\242]&%"
    "\245d\320\302\4\65\13u\242\305q"
    "HC-Y\0\66\14u\242\315\222\211C\222i\311\2\67\12u\242\305 "
    "\326\212%\0\70\14u\242\315"
    "\222i\311\222i\311\2\71\14u\242\315\222i\311\252%\13\0:\6A\246D\24;"
    "\10b\336L\232("
    "\0<\7S&UR+=\10\65\252\305\240\16\2>\10S&EV)\1\77\13u\242\315\222\205Y"
    "\35\212\0@\15u\242\315\222)C\222(C:"
    "\4A\13u\242\315\222i\303\220\331\2B\15u\242\305"
    "\220d\332\240d\332\240\0C\12u\242\315\222\211m\311\2D\12u\242\305\220d\336"
    "\6\5E\13u\242"
    "\305\61\34\222\60\34\4F\12u\242\305\61\34\222\260\10G\14u\242\315\222\211"
    "\321\246%\13\0H\12u"
    "\242Ef\33\206\314\26I\6q\242\304!J\12u\242e\243\246%\13\0K\15u\242E&%%-"
    "\211*Y\0L\10u\242E\330\343 M\14u\242E\266,\211\222h\266\0N\14u\242E\246MJ"
    "\42mZ\0O\12u\242\315\222yK\26\0P\14u\242\305\220d\332\240\204E\0Q\12\205"
    "\236\315\222"
    "yK\326\0R\15u\242\305\220d\332\240\224*Y\0S\13u\242\315\222\251\253\226,"
    "\0T\11u\242"
    "\305 \205=\1U\11u\242E\346[\262\0V\14u\242EfKJI\26F\0W\16u\242E\246"
    "$J\242$J\242t\1X\13u\242E\246%\265JM\13Y\12u\242EfKja\11Z\12u"
    "\242\305 "
    "f\35\7\1[\10\223\36\305\20\365i\134\13\204^E\26fa\26f\1]\10\223\36\305\324"
    "\247!^\10\65\262U\226\324\2_\6\24b\305\20`"
    "\6\63\62EVa\11Tb\315\20\231\222\1b"
    "\13tbE\226-\221iH\0c\12Tb\215\22iQ\242\0d\12tb]e\210L\311\0e\11"
    "Tb\215\22\15\243\2f\11r\342\214\222,\25\0g\13tZ\315\20\231\222-Q\0h\12tbE"
    "\226-\221S\0i\7q\242D\62\10j\11\222\332L\226tQ\0k\13tbEVR\22))\5"
    "l\6q\242\304!m\13U\242\205\322\242$"
    "J\242\24n\10Tb\305\22\71\5o\11Tb\215\22\231"
    "\22\5p\13tZ\305\22\231\206$"
    "\313\0q\12tZ\315\20\231\222\255\0r\10S\42\305\20\65\1s"
    "\10S\42\315\226-\0t\12s\42M\224,Q\13\0u\10TbE\344\224\14v\11TbE\344\224"
    "(\0w\13U\242E\246$J\242t\1x\12TbE$%J$\5y\12tZE\344\224l\211"
    "\2z\12Tb\305\220%J\66\4{\12\223\36U\22U\262\250\26|\6\221\236\304\3}"
    "\13\223\36E"
    "\26\325\222\250\22\1~\7&\352\215d\1\0\0\0\4\377\377 "
    "\30\10\62\362\214\222\0 \31\10\62\362"
    "L\242\0 \34\12\65\262M$%Q\2 "
    "\35\12\65\262M\224DR\2\60\2\12D\237\216\22I\211"
    "\2N\0\11)\256>\62\34\2N\272\23\231\236f\216\344H\216\344@\22'iVMr O\177\27"
    "\231\236V\26\16C\22F\312\260\224\222\312\260\204Y%"
    "J\264\0Qe\23\231\236\316\220#\71\222#\71"
    "\222\3I\32\205\245XQh\21\231\236\336\232U\223\341\230\16C\232#"
    "\341pQ\231\24\231\236\306C\222"
    "*\203\22\345\310\240#\321pN\67\0Q\373\22\231\236f:"
    "\14i\216\204\303\61\215z\32\206\4R\377"
    "\26\231\236V\216\14C\22%MI\42U\244$\352\22e%"
    "\5Ss\33\231\236\306\220\14R\22\15J"
    "$%\221\224D\203\22)Q$%\311\240h\0T\15\24\231\236f\216\14a\26ii\222\3\203$."
    "a\66\14W\60\27\231\236N\230EI\264$K\264T\224\246$\213\302%"
    "\13\7\1Y\7\23\231\236N"
    "\216\14\227,\335\16Y\66\34\264l\70\4["
    "\205\23\231\236f\70\34r\340\240\346\310p\310\221\60\33\6"
    "[\211\23\231\236f\70\34r K\207S\26f\341\220\211\3[\214\24\231\236f\70\34r "
    "\32tp"
    "\270%i\24mC\0[\266\26\231\236f\70\34r \31\206,\311&%S$-\321D\0[\306\27"
    "\231\236f\70\34\242$J\242J\242DI\62\350`T\32\206\4^"
    "\217\26\231\236n\70\14J\216$\303"
    "\222Fa\24\15C\32\205\22\0a\37\26\231\236n\64\34\224\246\244E\231r "
    "Q\22\245-Q\6%"
    "b\20\26\231\236v\222\14\203\22fC\322\224\64\265HI\232hR\0b\200\24\231\236N"
    "\230%\303\255"
    "\230%\303\242dS\233\244H\2c\1\27\231\236N\26&\303)L\206%M\224aI\243$K\244D"
    "\1e/"
    "\21\231\236f\70\34s$\35\206,"
    "\314\252\333\1e\71\24\231\236f\270\14R\22eZ\62%"
    "\305\244-\232TIg/"
    "\22\231\236f\22Gi\70\234\222bR\213z\15\1g:\30\231\236V\62d"
    "I\224\14R\226D\221\22EJ\224\64%"
    "m\221\30kc\22\231\236\306c\216\244Q\32\15Q\65J\243"
    "p\70p\271\24\231\236f\216\14i:\14Q\32\15C\16&"
    "\335\222\2rH\27\231\236F\222\14K\61"
    ").\303\226\15J\244DI\233R\221\2u(\31\231\236\316\60(Q\226\14\203\22eI\224%"
    "\303\240"
    "D\231\226i\221\0v\204\25\231\236N\224F\303!"
    "\223\302A\211\244\212\24\16b\254\0xn\26\231\236"
    "\356\62H\245A\31\222\226aP\224\226a\31\222b\62z\13\30\231\236\216\62\14Q"
    "\226D\303\240\3\321"
    "\60h\221\64(a\26\15\2~\247\30\231\236N\62(Y\224,\265("
    "\31\262lH\224\64\321\244H\251"
    "\10~\377\25\231\236N\62(qr\210\322h\70%"
    "\225\243RY\244\0\204\335\25\231\236V\26\15\327,"
    "\211\6\245\224\203\303\20%-\303\1\213\244\26\231\236F\232\205\71\22iI\224%"
    "Q\226D\265D\311\246"
    ",\213\276\27\231\236F\64HI\226iC\216$\203\224dQ%"
    "\223\62\305\2\213\367\26\231\236FX\31"
    "\326L\32\242,L\206%*)C\42U\0\214\42\30\231\236F\24&\311\224%\321\62,"
    "MI\262("
    "\221\224,\321\262\10\220 "
    "\26\231\236FTK\206-\312\221H\31\226(K\242a\211\243a\224\245\31\231"
    "\236N\64\14J\26fC\62(Q\66$Y\22\15J\224%J$\225.\30\231\236N\30-\203\234\14"
    "\311\240\204\311\220\324\222a\211\222l\31\2\226\217\31\231\236\306\22%"
    "\225a\311\42e\30\222\26\245\62,"
    "\25-I\244d\10\230\336\24\231\236\306\35\211\322$\326\201$\216\322\34Jr "
    "\1\232\330\24\231\236f"
    "\70\234\262p\320\301\341\220d\211\62(\262\0\377\14\11\63\237\216\62$\0\0";

// 绘制屏幕(app_draw_callback)分辨率 128x64 px
static void app_draw_callback(Canvas *canvas, void *ctx) {
  UNUSED(ctx);

  canvas_clear(canvas);
  canvas_set_custom_u8g2_font(canvas, zhairen_font);

  char draw_str[44] = {};

  snprintf(draw_str, sizeof(draw_str), "设备SN: %s",
           furi_hal_version_get_name_ptr());
  canvas_draw_str_aligned(canvas, 0, 2, AlignLeft, AlignTop, draw_str);

  canvas_draw_str_aligned(canvas, 128, 2, AlignRight, AlignTop, "宅人改造家");

  canvas_draw_line(canvas, 0, 12, 128, 12); // 横线

  canvas_draw_str_aligned(canvas, 64, 15, AlignCenter, AlignTop,
                          "安全飞地随机密钥写入程序");
  canvas_draw_str_aligned(canvas, 64, 25, AlignCenter, AlignTop,
                          "!!!!!正版设备请勿使用!!!!!");
  canvas_draw_str_aligned(canvas, 64, 35, AlignCenter, AlignTop,
                          "点击<确认键>即完成写入");
  canvas_draw_str_aligned(canvas, 64, 45, AlignCenter, AlignTop,
                          "感谢QQ2144195995");
  canvas_draw_str_aligned(canvas, 64, 55, AlignCenter, AlignTop,
                          "感谢QQ1353859364");
}

// 监听按键输入(app_input_callback)
static void app_input_callback(InputEvent *input_event, void *ctx) {
  furi_assert(ctx);

  FuriMessageQueue *event_queue = ctx;
  furi_message_queue_put(event_queue, input_event, FuriWaitForever);
}

static bool furi_hal_crypto_generate_unique_keys(uint8_t start_slot,
                                                 uint8_t end_slot) {
  FuriHalCryptoKey key;
  uint8_t key_data[32];
  for (uint8_t slot = start_slot; slot <= end_slot; slot++) {
    key.type = FuriHalCryptoKeyTypeSimple;
    key.size = FuriHalCryptoKeySize256;
    key.data = key_data;
    furi_hal_random_fill_buf(key_data, 32);
    if (!furi_hal_crypto_enclave_store_key(&key, &slot)) {
      return false;
    }
  }
  return true;
}

int32_t factory_u2f_crack_app(void *p) {
  // 必须有
  UNUSED(p);

  FuriMessageQueue *event_queue =
      furi_message_queue_alloc(8, sizeof(InputEvent));

  // 配置程序视图端口
  ViewPort *view_port = view_port_alloc();
  // 绘制屏幕(app_draw_callback)
  view_port_draw_callback_set(view_port, app_draw_callback, NULL);
  // 监听按键输入(app_input_callback)
  view_port_input_callback_set(view_port, app_input_callback, event_queue);

  // 在GUI中注册程序视图端口
  Gui *gui = furi_record_open(RECORD_GUI);
  gui_add_view_port(gui, view_port, GuiLayerFullscreen);

  InputEvent event;

  // 检测按键输入
  bool running = true;
  while (running) {
    if (furi_message_queue_get(event_queue, &event, 100) == FuriStatusOk) {
      if ((event.type == InputTypePress) || event.type == InputTypeLong ||
          (event.type == InputTypeRepeat)) {
        switch (event.key) {
        // 按返回键
        case InputKeyBack:
          // 退出程序
          running = false;
          break;
        // 按确认键
        case InputKeyOk:
          furi_hal_crypto_generate_unique_keys(0, 10);
        // 按左键
        case InputKeyLeft:
          break;
        // 按右键
        case InputKeyRight:
          break;
        // 按上键
        case InputKeyUp:
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
