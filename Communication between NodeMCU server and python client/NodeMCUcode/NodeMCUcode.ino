
#include <ESP8266WiFi.h>

byte ledPin = 2;
// WiFi parameters to be configured
const char* ssid = "paya1"; // Write here your router's username
const char* password = "billu12345"; // Write here your router's passward
WiFiServer server(80);

void setup() {
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
    server.begin();                         // starts the server
  /*  Serial.println("Connected to wifi");
    Serial.print("Status: "); Serial.println(WiFi.status());  // some parameters from the network
    Serial.print("IP: ");     Serial.println(WiFi.localIP());
    Serial.print("Subnet: "); Serial.println(WiFi.subnetMask());
    Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP());
    Serial.print("SSID: "); Serial.println(WiFi.SSID());
    Serial.print("Signal: "); Serial.println(WiFi.RSSI());
    Serial.print("Networks: "); Serial.println(WiFi.scanNetworks());*/
    pinMode(ledPin, OUTPUT);
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        if (client.connected()) {
            digitalWrite(ledPin, LOW);  // to show the communication only (inverted logic)
            Serial.println(".");
            String request = client.readStringUntil('\r');    // receives the message from the client
            Serial.print("From client: "); Serial.println(request);
            client.flush();
            client.println("Hi client! No, I am listening.\r"); // sends the answer to the client
            digitalWrite(ledPin, HIGH);
        }
        client.stop();                // tarminates the connection with the client
    }
}