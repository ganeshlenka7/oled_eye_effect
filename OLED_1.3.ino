#include <Wire.h>
#include <U8g2lib.h>

// SH1106 128x64 OLED
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// Eye parameters
const int eyeX = 64;       // center X
const int eyeY = 32;       // center Y
const int eyeRadius = 50;  // radius of the iris

void setup() {
  u8g2.begin();
}

void loop() {
  // Blink: closing
  for (int h = eyeRadius*2; h >= 2; h -= 2) {
    drawEye(h, 0, 0);
    delay(25);
  }

  delay(150); // pause closed

  // Blink: opening
  for (int h = 2; h <= eyeRadius*2; h += 2) {
    drawEye(h, 0, 0);
    delay(25);
  }

  delay(200);

  // Iris movement while open
  for (int i = 0; i < 15; i++) {
    int offsetX = random(-10, 11); // move left/right
    int offsetY = random(-5, 6);   // move up/down
    drawEye(eyeRadius*2, offsetX, offsetY);
    delay(200);
  }

  delay(300);
}

// Draw the iris with vertical height 'h' and offsets
void drawEye(int h, int offsetX, int offsetY) {
  u8g2.clearBuffer();
  u8g2.setDrawColor(1);

  int width = eyeRadius*2;
  int height = h;

  for (int y = -height/2; y <= height/2; y++) {
    float dx = (width/2) * sqrt(1.0 - (float)(y*y)/(height/2.0*height/2.0));
    u8g2.drawHLine(eyeX - dx + offsetX, eyeY + y + offsetY, 2*dx);
  }

  u8g2.sendBuffer();
}