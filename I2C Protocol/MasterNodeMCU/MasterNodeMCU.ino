#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "paya"; //Enter your WIFI ssid
const char* password = "mishtynaina";
ESP8266WebServer server(80);
void handleRoot() {
    server.send(200, "text/html", "<form action=\"/LED_BUILTIN_on\" method=\"get\" id=\"form1\"></form><button type=\"submit\" form=\"form1\" value=\"On\">On</button><form action=\"/LED_BUILTIN_off\" method=\"get\" id=\"form2\"></form><button type=\"submit\" form=\"form2\" value=\"Off\">Off</button>");
}
void handleSave() {
    if (server.arg("pass") != "") {
        Serial.println(server.arg("pass"));
    }
}


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    delay(3000);
    Serial.begin(9600); /* begin serial for debug */

    Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */

    Serial.println();
    Serial.print("Configuring access point...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    server.on("/", handleRoot);
    server.on("/save", handleSave);
    server.begin();
    Serial.println("HTTP server started");

    //Wire.beginTransmission(8);


    server.on("/LED_BUILTIN_on", []() {
        Wire.beginTransmission(8);
        digitalWrite(LED_BUILTIN, 1);
        Serial.println("on");
        Wire.write(digitalRead(LED_BUILTIN));
        //Wire.write("on");
        Wire.endTransmission();
        handleRoot();
        });
    server.on("/LED_BUILTIN_off", []() {
        Wire.beginTransmission(8);
        digitalWrite(LED_BUILTIN, 0);
        Serial.println("off");
        Wire.write(digitalRead(LED_BUILTIN));
        //Wire.write("off");
        Wire.endTransmission();
        handleRoot();
        });

    //Wire.endTransmission(); 



}

void loop() {
    server.handleClient();

    //Wire.beginTransmission(8); /* begin with device address 8 */
    //Wire.write("Hello Arduino");  /* sends hello string */
    //Wire.endTransmission();   /* stop transmitting */

    Wire.requestFrom(8, 13); /* request & read data of size 13 from slave */
    while (Wire.available()) {
        char c = Wire.read();
        Serial.print(c);
    }
    Serial.println();
    delay(1000);
}