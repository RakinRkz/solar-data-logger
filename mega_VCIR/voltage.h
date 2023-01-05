#define num_sensors 2
const float volt_sensor_const = 5.0/1024;
float R1 = 30000.0;
float R2 = 7500.0;

const float v_ref = 5.0;
float volts[num_sensors];
int vpin[num_sensors] = { A3, A4 };

void volt_init() {
  for (uint8_t i = 0; i < num_sensors; i++) {
    pinMode(vpin[i], INPUT);
  }
}
void read_volt() {
  int adc_val;
  for (uint8_t i = 0; i < num_sensors; i++) {
    adc_val = analogRead(vpin[i]);
    volts[i] = 1.0 * adc_val * volt_sensor_const/ (R2 / (R1 + R2));
  }
}

String get_volt() {
  read_volt();
  delay(100);

  String vString = "";
  for (int i = 0; i < num_sensors; i++) {
    vString += String(volts[i]);
    if (i != num_sensors - 1)
      vString += ",";
  }

  return vString;
}

String volt_data(uint8_t i) {
  read_volt();
  return String(volts[i]) + " V";
}
