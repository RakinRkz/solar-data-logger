#define num_sensors 10
#define ONE_WIRE_BUS 2
int deviceCount = 0;

float temperatures[num_sensors];
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void temp_init() {
  sensors.begin();  // Start up the library
  Serial.print("Locating devices...");
  Serial.print("Found ");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");
}
void read_temperature() {
  sensors.requestTemperatures();

  int adc_val;
  for (uint8_t i = 0; i < num_sensors; i++) {
    temperatures[i] = sensors.getTempCByIndex(i);
  }
}

String get_temp() {
  read_temperature();
  delay(100);

  String tString = "";
  for (int i = 0; i < num_sensors; i++) {
    tString += String(temperatures[i]);
    if (i != num_sensors - 1)
      tString += ",";
  }

  return tString;
}

String temp_data(uint8_t i) {
  return String(temperatures[i]) + " C";
}
