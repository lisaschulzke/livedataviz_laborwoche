int VRx = A0;
int VRy = A1;
int SW = 2;

int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;


#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; // I2C
//Adafruit_BME680 bme(BME_CS); // hardware SPI
//Adafruit_BME680 bme(BME_CS, BME_MOSI, BME_MISO,  BME_SCK);

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 


  while (!Serial);
  Serial.println(F("BME680 test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }
  
}

void loop() {
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  
  

  //Serial.print("Temperature = ");
  Serial.print(bme.temperature);
  //Serial.println(" *C");
  Serial.print(",");

  //Serial.print("Pressure = ");
  Serial.print(bme.pressure / 100.0);
  //Serial.println(" hPa");
  Serial.print(",");

  //Serial.print("Humidity = ");
  Serial.print(bme.humidity);
  //Serial.println(" %");
  Serial.print(",");

  //Serial.print("Gas = ");
  Serial.print(bme.gas_resistance / 1000.0);
  //Serial.println(" KOhms");
  Serial.print(",");
  
  //Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  
  //Serial.println(" m");
  Serial.print(",");
  //Serial.print("X: ");
  Serial.print(mapX);
  //Serial.print(" | Y: ");
  Serial.print(",");
  Serial.print(mapY);
  //Serial.print(" | Button: ");
  Serial.print(",");
  Serial.print(SW_state);
  Serial.print(",");


  Serial.println();
  //delay(20);
  
}
