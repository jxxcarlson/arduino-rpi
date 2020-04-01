// [Reference (YouTube video)](https://www.youtube.com/watch?v=jIkQAUCc7Fk)int sensorValue ;
                                                   
int sensorValue ;
int threshold;

void setup () {
   Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A1);
  threshold = 215;
  Serial.println(sensorValue);
  if (sensorValue < threshold) {
    pinMode(A1, OUTPUT);
    digitalWrite(A1, HIGH);
    tone(9, 2900, 150);
    delay(200);
    pinMode(A1, INPUT);
  }
  delay(50);
}

