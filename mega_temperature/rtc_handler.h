#include "ds3231.h"


struct ts t;  // for RTC

void rtc_init() {
  DS3231_init(DS3231_CONTROL_INTCN);
}

void print_date_time() {
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
  Serial.println();
}

String get_time() {
  DS3231_get(&t);
  String s_time = String(t.hour) + " : " + String(t.min);
  // Serial.println(s_time);
  return s_time;
}

String get_datetime() {
  DS3231_get(&t);
  String s_datetime = String(t.mday) + "/" + String(t.mon)+"/"+String(t.year)+"  "+String(t.hour) + " : " + String(t.min);
  Serial.println(s_datetime);
  return s_datetime;
}

uint8_t time_minute(){
  DS3231_get(&t);
  return t.min;
}

