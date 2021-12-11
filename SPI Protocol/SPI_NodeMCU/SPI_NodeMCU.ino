#include <SPI.h>

char buff[] = "Hello Slave\n";

void setup() {
	Serial.begin(9600); /* begin serial with 9600 baud */
	SPI.begin();  /* begin SPI */
}

void loop() {
	for (int i = 0; i < sizeof buff; i++)  /* transfer buff data per second */
		SPI.transfer(buff[i]);
	delay(1000);
}