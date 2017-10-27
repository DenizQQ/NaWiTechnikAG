char command;
String string;
boolean ledon = false;
#define led 4 

  void setup()
  {
    Serial.begin(9600);
    Serial.println("TEST");
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
      Serial.println(string);
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
 

    
