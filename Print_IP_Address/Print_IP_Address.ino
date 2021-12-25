/*
 * Connects the ESP8266 NodeMCU board to wifi and prints the IP address
 * 
 * by:
 * ROBOSANS
 * based on ThingSpeak Library example
 * 
 * https://www.robosans.com/
 */

#include "ESP8266WiFi.h"

// WiFi parameters to be configured
const char* ssid = "paya1"; // Write here your router's username
const char* password = "billu12345"; // Write here your router's passward

void setup(void)
{ 
  Serial.begin(9600);
  // Connect to WiFi
  WiFi.begin(ssid, password);

  // while wifi not connected yet, print '.'
  // then after it connected, get out of the loop
  while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
  }
  //print a new line, then print WiFi connected and the IP address
  Serial.println("");
  Serial.println("WiFi connected");
  // Print the IP address
  Serial.println(WiFi.localIP());

}
void loop() {
  // Nothing
}
