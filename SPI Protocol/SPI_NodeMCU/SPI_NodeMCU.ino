#include<SPI.h>                             //Library for SPI 

int x;
void setup(void) {
    Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200 


    SPI.begin();                            //Begins the SPI commnuication
    SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
    digitalWrite(SS, HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}

void loop(void)
{
    int Mastersend;
    float Mastereceive;

    Mastersend = x;
    Mastereceive = SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave

    Serial.println(Mastereceive);

    delay(100);
}