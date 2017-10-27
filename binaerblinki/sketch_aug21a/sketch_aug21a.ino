int pin = 9;
int de = 100;
char wort[] = "hallo";
int *p;


void setup() {
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}


int* toBinaer(char chr) {
  static int bArr[sizeof(wort)/ sizeof(wort[0])];
  for(int y = 0; y < 8; y++) {
    bArr[y] = !!((chr << y) & 0x80);
  }

  return bArr;
  
}

void loop() {
  for(int i = 0; i < sizeof(wort)/sizeof(wort[0]); i++) {
    int *p = toBinaer(wort[i]);
    for(int x = 0; x < 8; x++) {
      *(p + x) ? digitalWrite(pin, HIGH) : digitalWrite(pin, LOW);
      delay(de);
    }
  }
}

