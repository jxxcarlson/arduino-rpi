// [Reference (YouTube video)](https://www.youtube.com/watch?v=jIkQAUCc7Fk)int sensorValue ;

/*
* CIRCUIT: LED positive to 330 ohm resitor to pin 7
*          LED negative to ground
*          Buzzer to ground and pin 9
*
* PARAMETER: I played around with these,  When I bring 
* hand hear the LED, it turns on, the rapidly off and on
* since the reflected light is enough to raise the 
* incident light intensity above the threshold. Because
* delay and the buzzer interval are short, the light
* and sound pulse rapidly.  Fun!
*/
                                                   
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

