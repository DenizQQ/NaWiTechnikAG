char command;
String string;
boolean ledon = false;
#define led 13

  void setup()
  {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
  }

  void loop()
  {
    if (Serial.available() > 0) {
      string = "";
    }
    
    while(Serial.available() > 0)
    {
      command = ((byte)Serial.read());
      string += command;
      delay(1);
    }
    
    if(string == "an")
    {
        ledOn();
        ledon = true;
    }
    
    if(string =="aus")
    {
        ledOff();
        ledon = false;
        Serial.println(string);
    }
 }
 
void ledOn()
   {
      analogWrite(led, 255);
      delay(10);
    }
 
 void ledOff()
 {
      analogWrite(led, 0);
      delay(10);
 }
 

    
