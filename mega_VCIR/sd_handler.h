#include <SPI.h>
#include <SD.h>


String filename = "module2.csv";

const int chipSelect = 53;

void sd_init() {
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1)
      ;
  }
  Serial.println("card initialized.");
}

void sd_write(String dataString) {
  Serial.println("Writing to module2.csv");

  File dataFile = SD.open(filename, FILE_WRITE);
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
  }
  // if the file doesn't open, pop up an error:
  else {
    Serial.print("error opening ");
    Serial.println(filename);
  }
}