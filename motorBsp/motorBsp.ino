#include <AFMotor.h>

//Fuer Motor 1 2
//MOTOR12_64KHZ MOTOR12_8KHZ
//MOTOR12_2KHZ MOTOR12_1KHZ
//
//3 4 nur 1KHZ


AF_DCMotor motor(2, MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600);
  Serial.println("TEST");

  motor.setSpeed(255); //0,255
}

void loop() {
  Serial.println("Vor");

  for(int i = 0; i<=255; i++) {
    motor.setSpeed(i);
    motor.run(FORWARD);
    Serial.println(i);
    delay(10);
  }
  for(int i = 255; i>=0; i--) {
     motor.setSpeed(i);
     motor.run(FORWARD);
     Serial.println(i);
     delay(10);
  }

  motor.release()

 


  
}
