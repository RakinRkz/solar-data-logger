#ifndef screen_handler_h
#define screen_handler_h

#include <spi.h>
#include <wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define textSize 2

#define OLED_RESET -1     //reset pin for oled, if none give -1 and arduino reset is used

#define display_off false

Adafruit_SSD1306 display(OLED_RESET);

#define i2c_ID 0x3C

void screen_init() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED error: SSD1306 allocation failed"));
    delay(1000);
  }
  else
  {
    Serial.println(F("OLED screen ok"));
  }
  display.clearDisplay();
}

void screen_display() {
  display.clearDisplay();
  display.display();
}

void screen_display(String title, String message) {
  if (display_off)
    return;
  display.clearDisplay();
  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  display.setCursor(20, 0);
  display.println(title);
  display.setCursor(20, 15);
  display.println(message);
  display.display();
}

#endif