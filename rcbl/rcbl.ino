#include <AFMotor.h>
#include <Servo.h>
#include <stdlib.h>

#define servPin 10

Servo servo;
int richtung = 0; 
unsigned char geschw = 0;

char command;
String string;


AF_DCMotor motor1(2, MOTOR12_64KHZ);
AF_DCMotor motor2(1, MOTOR12_64KHZ);

void setup() {
  Serial.begin(9600);
  servo.attach(servPin);
  kill();
}

void loop() {
    while(Serial.available() > 0 && string.length() < 4)
    {
      command = ((byte)Serial.read());
      string += command;
      delay(1);
    }

    if(string.length() == 4) {
      Serial.println(string);
      if(string[0] == 's') {  //'s' geschwindigkeit 'r' richtung
        string.remove(0,1);
        updateSpeed(string.toInt() - 100); //-100 damit Zahl dreistellig ist
        string = "";
      } else if(string[0] == 'r') {
        string.remove(0,1);
        updatePosition(string.toInt() - 100);
        string = "";
      }
      string = "";
    }
}



void updatePosition(int rich) {
  servo.write(richtung);
  richtung = rich;
}
  
  
void updateSpeed(int ges) {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor1.setSpeed(ges);
  motor2.setSpeed(ges);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  geschw = ges;
  
}

void kill() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  servo.write(90);
  
}

