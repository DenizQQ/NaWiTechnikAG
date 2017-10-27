int pin = 2;
int de = 20;

void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}





void loop() {
  digitalWrite(2, HIGH);
  delay(de);
  digitalWrite(2, LOW);
  delay(de);

}
