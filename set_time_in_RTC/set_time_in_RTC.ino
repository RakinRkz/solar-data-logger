#include <Wire.h>


#define  set_new 0  //change to false to not set new time in rtc module
#include "DS3231.h"


struct ts t; // for RTC

void setup() {
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
  Serial.begin(9600);
  /*----------------------------------------------------------------------------
  In order to synchronise your clock module, insert timetable values below !
  ----------------------------------------------------------------------------*/
  if (set_new) {

    t.hour = 12;
    t.min = 58;
    t.sec = 0;
    t.mday = 5;
    t.mon = 1;
    t.year = 2023;

    DS3231_set(t);

    Serial.println("Done setting new time. Showing current time now: ");
  }

  
}

void loop() {
  DS3231_get(&t);
  Serial.print("Date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Hour : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);
  delay(1000);
}