#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;


float lux;

void light_init() {
  lightMeter.begin();
  Serial.println("irradiance sensor ok");
}

void read_light() {
  lux = lightMeter.readLightLevel();
}

String get_light() {
  read_light();
  delay(100);

  String lString = String(lux);

  return lString;
}

String light_data() {
  return String(lux) + " lx";
}
