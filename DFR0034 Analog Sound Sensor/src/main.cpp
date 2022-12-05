#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"
#include <SPI.h>

void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  pinMode(4, OUTPUT);
  wifiConnect();                  //Branchement au réseau WIFI
  MQTTConnect();                  //Branchement au broker MQTT
}
void loop()
{
      int val;
      val=analogRead(A0);   //connect mic sensor to Analog 0
      Serial.println(val,DEC);//print the sound value to serial

    if(analogRead(A0) > 25){
      digitalWrite(4, HIGH);
    }
     if(analogRead(A0) < 25){
      digitalWrite(4, LOW);
    }

      appendPayload("Sound Intensity", val);  //Ajout de la donnée température au message MQTT
      sendPayload();   
      delay(200);
}