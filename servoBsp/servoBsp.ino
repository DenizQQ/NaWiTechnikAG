#include <AFMotor.h>
#include <Servo.h>
#include <stdlib.h>

#define pin 10



Servo servo; 

int angle = 0;



void setup() {
  servo.attach(pin);

}

void loop() {
  for(angle = 0; angle <= 180; angle++) {
    servo.write(angle);
    delay(5);
  }
  for(angle = 180; angle >= 0; angle--) {
    servo.write(angle);
    delay(5);
  }
  
  
}
