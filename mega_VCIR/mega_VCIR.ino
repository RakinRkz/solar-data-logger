#include <Wire.h>
#include "rtc_handler.h"
#include "voltage.h"
#include "current.h"
#include "irradiance.h"

#include "sd_handler.h"
#include "screen_handler.h"

#define DELAY_PER_DISP 1000  //micro seconds, integer
#define sd_write_interval 2  //in minutes, integer only
#define num_sensors 2

#define DEBUG 0

void setup() {

  Serial.begin(9600);
  Wire.begin();

  rtc_init();
  delay(1000);
  screen_display("RTC OK", get_time());

  delay(1000);
  sd_init();
  screen_display("SD card OK", "starting...");
  Serial.println("SD card OK");

  light_init();
  curr_init();
  volt_init();
  delay(1000);

  delay(1000);
  Serial.println("init done");
}

void loop() {
  debug();
  Serial.println("waiting at interval...");

  int c_minute;
  c_minute = time_minute();
  if (c_minute % sd_write_interval == 0) {
    String dataString = get_datetime() + "," + get_volt() + "," + get_cur() + "," + get_light();
    sd_write(dataString);

    while (time_minute() == c_minute) {
      delay(1000);
      String dataString = get_datetime() + ", " + get_volt() + ", " + get_cur() + ", " + get_light();
      Serial.println(dataString);
    }
  }
  delay(1000);
  String dataString = get_datetime() + ", " + get_volt() + ", " + get_cur() + ", " + get_light();
  Serial.println(dataString);
}

void debug() {
  while (DEBUG) {
    String dataString = get_datetime() + ", " + get_volt() + ", " + get_cur() + ", " + get_light();
    Serial.println(dataString);
    delay(10000);
  }
}