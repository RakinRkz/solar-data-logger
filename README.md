# Arduino data logger

This project was created to monitor solar panel wattage and temperature simultaneously with timestamps.

## Sensors used: 
  - DS18B20(teamperature), connected by **one-wire** protocol
  - ACS712(Current sensor)
  - DC voltage sensor

## Micro controllers:
  - Arduino Uno
  - Arduino Mega

## Additional components:
  - Sd card reader module, connected by **SPI** interface
  - RTC(clock) module, connected by **I2C** interface
