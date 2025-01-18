#include <Arduino.h>
#include "MPXV7002DP.h"


#define PRESSURE_SENSOR_PIN 34
#define INTERVAL 1000 // 1 sec
#define airDensity 1.204


uint32_t _interval = 0;

PressureSensor pressureSensor(PRESSURE_SENSOR_PIN, airDensity);

void setup() {
    Serial.begin(9600);
    pressureSensor.begin();

}

void loop() {

  	if(millis() - _interval > INTERVAL ){
		  Serial.print("Speed = ");
      Serial.println(pressureSensor.airspeed());
      Serial.print("m/s");
      _interval = millis();
  }
}
