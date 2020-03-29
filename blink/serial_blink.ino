String data="Hello From Arduino!";


const int PIN = 7;
const int DELAY = 120;

void setup() {
    Serial.begin(9600);
    pinMode(PIN, OUTPUT);
  }

int count = 0;

void loop() {
  count = count + 1;
  if (count % 2 == 1) {
      digitalWrite(PIN, HIGH);  
   } else { 
      digitalWrite(PIN, LOW);
  
   }
   
    Serial.println(data);
    delay(200);
  }
