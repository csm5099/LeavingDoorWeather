#include <LedControl.h>

LedControl lc1 = LedControl(5, 7, 6, 1);
LedControl lc2 = LedControl(8, 10, 9, 2);
LedControl lc3 = LedControl(11, 13, 12, 3);

int delayTime = 3000;

// R 알파벳 패턴
byte R[8] = { B00000000, B00000000, B01111111, B00001001, B00011001, B00101001, B01000110, B00000000 };
byte ai[8] = { B01110000, B01001000, B01111000, B01000000, B00000000, B00000000, B01110100, B00000000 };
byte n[8] = { B01110000, B00001000, B00001000, B01111000, B00000000, B00000000, B00000000, B00000000 };

byte S[8] = { B00000000, B00100110, B01001001, B01001001, B01001001, B00110010, B00000000, B00000000 };
byte u[8] = { B00000000, B00111100, B01000000, B01000000, B01000000, B00111100, B00000000, B00000000 };

byte D[8] = { B00000000, B00000000, B00000000, B01111110, B01000010, B01000010, B01000010, B00111100 };
byte st[8] = { B00001000, B01010100, B01010100, B01010100, B00100000, B00001000, B01111100, B01001000 };

void ledInit() {
  lc1.shutdown(0, false);
  lc1.setIntensity(0, 8);
  lc1.clearDisplay(0);

  lc2.shutdown(0, false);
  lc2.setIntensity(0, 8);
  lc2.clearDisplay(0);

  lc3.shutdown(0, false);
  lc3.setIntensity(0, 8);
  lc3.clearDisplay(0);
}
void ledClearDisplay() {
  lc1.clearDisplay(0);
  lc2.clearDisplay(0);
  lc3.clearDisplay(0);
}

void ledRain() {
  ledInit();
  for (int i = 0; i < 8; i++) {
    lc1.setRow(0, i, R[i]);
    lc2.setRow(0, i, ai[i]);
    lc3.setRow(0, i, n[i]);
  }
}

void ledSun() {
  ledInit();
  for (int i = 0; i < 8; i++) {
    lc1.setRow(0, i, S[i]);
    lc2.setRow(0, i, u[i]);
    lc3.setRow(0, i, n[i]);
  }
}

void ledDust() {
  ledInit();
  for (int i = 0; i < 8; i++) {
    lc1.setRow(0, i, D[i]);
    lc2.setRow(0, i, u[i]);
    lc3.setRow(0, i, st[i]);
  }
}