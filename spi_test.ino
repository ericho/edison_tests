#include <SPI.h>

const int chipSelect = 10;
unsigned int dead = 0x0d0e0a0d;
unsigned int beef = 0x0b0e0e0f;

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  pinMode(chipSelect, OUTPUT);
}

void loop() {
  writeNumbers(dead);
  delay(500);
  writeNumbers(beef);
  delay(500);
}

/*
 * Shows the hex representation of 4-byte unsigned int
 * in 7 segment display
 */
void writeNumbers(unsigned int number) {
  digitalWrite(chipSelect, LOW);
  SPI.transfer((number >> 24) & 0xFF);
  SPI.transfer((number >> 16) & 0xFF);
  SPI.transfer((number >> 8) & 0xFF);
  SPI.transfer(number & 0xFF);
  digitalWrite(chipSelect, HIGH);  
}


