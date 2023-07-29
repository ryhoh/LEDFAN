// 跳ねるLED by KenKen
// Arduino版

#include <Adafruit_NeoPixel.h>

#define PIN (2) //信号端子のピン番号
#define LED_NUM (12)  //LEDの総数

#define RAINBOW_NUM (7)
#define RAINBOW_WEAK_GAIN (7)  // 虹の色の強さを暗くするための係数 2^RAINBOW_WEAK_GAIN 倍暗くなる

// 虹の色
const int rainbow_rgb[RAINBOW_NUM][3] = {
  {255, 0, 0},    // 赤
  {255, 127, 0},  // オレンジ
  {255, 255, 0},  // 黄
  {0, 255, 0},    // 緑
  {0, 0, 255},    // 青
  {75, 0, 130},   // 紫
  {148, 0, 211},  // 紫
};

Adafruit_NeoPixel LED = Adafruit_NeoPixel(LED_NUM, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // LED初期化、全体消去
  LED.begin();
  LED.show();
}

void loop() {
  // 虹を回転させる
  for (int i = 0; i < RAINBOW_NUM; i++) {
    for (int j = 0; j < LED_NUM; j++) {
      LED.setPixelColor(
        j,
        rainbow_rgb[(i + j) % RAINBOW_NUM][0] >> RAINBOW_WEAK_GAIN,
        rainbow_rgb[(i + j) % RAINBOW_NUM][1] >> RAINBOW_WEAK_GAIN,
        rainbow_rgb[(i + j) % RAINBOW_NUM][2] >> RAINBOW_WEAK_GAIN
      );
    }
    LED.show();
    delay(1000);
  }
  
}
