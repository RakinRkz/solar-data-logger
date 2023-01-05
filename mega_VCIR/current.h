#define num_sensors 2
const float cur_sensor_const = 5.0 / 1024.0;

float curs[num_sensors];
int cpin[num_sensors] = { A5, A6 };

void curr_init() {
  for (uint8_t i = 0; i < num_sensors; i++) {
    pinMode(cpin[i], INPUT);
  }
}


void read_cur() {
  for (uint8_t i = 0; i < num_sensors; i++) {
    float AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0, AcsValueF = 0.0;

    for (int x = 0; x < 150; x++) {  //Get 150 samples
      AcsValue = analogRead(cpin[i]);     //Read current sensor values
      Samples = Samples + AcsValue;  //Add samples together
      delay(3);                      // let ADC settle before next sample 3ms
    }
    AvgAcs = Samples / 150.0;  //Taking Average of Samples
    // Serial.println(Samples);
    //((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
    //2.5 is offset(I assumed that arduino is working on 5v so the viout at no current comes
    //out to be 2.5 which is out offset. If your arduino is working on different voltage than
    //you must change the offset according to the input voltage)
    //0.066v(66mV) is rise in output voltage when 1A current flows at input
    curs[i] = ((2.5 - (AvgAcs * (5.0 / 1024.0))) / 0.066) - 0.05;
  }
}

String get_cur() {
  read_cur();
  delay(100);

  String cString = "";
  for (int i = 0; i < num_sensors; i++) {
    cString += String(curs[i]);
    if (i != num_sensors - 1)
      cString += ",";
  }

  return cString;
}

String cur_data(uint8_t i) {
  read_cur();
  return String(curs[i]) + " A";
}
