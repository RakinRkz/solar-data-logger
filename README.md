# Solar panel data logger

## Introduction
This project is a part of a larger experimental project of testing cooling solution for Solar panels. The data logger monitors wattage and temperature simultaneously with timestamps and stores them in sd card for further analysis.

## Implementation
Requirement gathering and analysis for number of temperature sensors, which model of sensor to use etc. was done. After that PCB design, fabrication and assembly was done.
**Components:** 
  - DS18B20(teamperature), connected by _one-wire_ protocol
  - ACS712(Current sensor)
  - DC voltage sensor
  - Arduino Uno
  - Arduino Mega
  - Sd card reader module, connected by _SPI_ interface
  - RTC(clock) module, connected by _I2C_ interface

## Conclusion
The project performed as per requirements of the experiment. This project has potential to be used in many other use cases with some modification. Realtime data monitoring will be possible with wireless modules or ESP MCUs.
