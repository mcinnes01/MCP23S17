// This #include statement was automatically added by the Particle IDE.
#include "mcp23s17_photon/mcp23s17_photon.h"

const uint8_t chipSelect = 10;

// Create an object for each chip
// Bank 0 is address 0
// Bank 1 is address 1.
// Increase the addresses by 2 for each BA value.

MCP23S17 Bank1(chipSelect, 0);
MCP23S17 Bank2(chipSelect, 1);

void setup() {
	Bank1.begin();
	Bank2.begin();

	Bank1.pinMode(15, OUTPUT);
	Bank2.pinMode(15, INPUT_PULLUP);
}

void loop() {
	Bank1.digitalWrite(15, !Bank2.digitalRead(15));
}