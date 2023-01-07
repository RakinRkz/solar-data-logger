#include <Wire.h>
#include "rtc_handler.h"
#include "temperature_handler.h"
#include "sd_handler.h"
#include "screen_handler.h"

#define DELAY_PER_DISP 1000  //micro seconds, integer
#define sd_write_interval 2  //in minutes, integer only
#define num_sensors 10

#define DEBUG 0


void setup() {

  Serial.begin(9600);
  Wire.begin();

  screen_init();
  screen_display("Initializing", ".....");
  delay(1000);

  rtc_init();
  delay(1000);
  screen_display("RTC OK", get_time());

  delay(1000);
  sd_init();
  screen_display("SD card OK", "starting...");

  temp_init();

  delay(1000);
  Serial.println("init done");
}

void loop() {
  debug();
  screen_display("time:", get_time());

  delay(10);
  // screen_display();
  Serial.println("waiting at interval...");
  Serial.println("gg");
  int c_minute;
  c_minute = time_minute();
  if (c_minute % sd_write_interval == 0) {
    Serial.println("writing to sd card");
    screen_display("writing..", get_time());

    String dataString = get_datetime() + "," + get_temp();
    sd_write(dataString);

    while (time_minute() == c_minute) {
      for (int i = 0; i < num_sensors; i++) {
        screen_display("Temp. " + String(i + 1), temp_data(i));
        Serial.print("Temp sensor ");
        Serial.print(i+1);
        Serial.print(" : ");
        Serial.println(temp_data(i));

        delay(DELAY_PER_DISP);
      }
      // delay(8000);
    }
  }
}
void debug() {
  while (DEBUG) {
    String dataString = get_datetime() + "," + get_temp();
    Serial.println(dataString);
    delay(1000);
  }
}
