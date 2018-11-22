#include <Arduino.h>
#include <M5Stack.h>
#include "misakiUTF16/misakiUTF16.h"

void misakiPrint(int x, int y, char * pUTF8) {
	int n=0;
	byte buf[40][8];  //320x8ドットのバナー表示パターン
	while(*pUTF8)
		pUTF8 = getFontData(&buf[n++][0], pUTF8);  // フォントデータの取得

	// 文字の描画
	for (byte i=0; i < 8; i++) {
		for (byte j=0; j < n; j++) {
			for (byte k=0; k<8;k++) {
				if(bitRead(buf[j][i],7-k)) {
					M5.Lcd.drawPixel(x + 8*j + k , y + i, TFT_WHITE);
				}
			}
		}
	}
}

void setup(){
    M5.begin();
      M5.Lcd.print("Hello World!");
      misakiPrint(0,0, "みさきフォントで書き出してみる☆");
      M5.Speaker.setVolume(1);
      M5.Speaker.beep();
      delay(100);
}
void loop() {
  M5.Speaker.mute();
}
