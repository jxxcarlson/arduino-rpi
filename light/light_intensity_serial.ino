
/*
 *  Measure light intensity with a voltage divider.
 *  R1, a light-dependendent resistor (LDR) is connected
 *  to +5V and to pin A0, which is in turn connected to the
 *  analog-to-digital converter (ADC) of the Arduino.  A0
 *  is also connnected to GND through a 10 kOhm resistor R2.
 *  Let V1 be the voltage drop across R1, and let V2 be the
 *  voltage drop across R2. The value that the Arduino reads
 *  from A0 is an encoding of V2.  One uses Ohm's law to solve
 *  for R1, which is measure of light intensity, in terms of V2,
 *  which is measured at A0 and mapped to an integer value between
 *  0 and 1024.
 *  
 *  An empirical and rather innaccurate formula for the light
 *  intensity in terms of R1 is 
 *  
 *         lux = 500000/R1,
 *         
 *  where R1 is measured in Ohms.
 *  
 *  The lux value is sent out over the serial port.
 *  If lux < LowLightLimit, then the LED on pin 7 blinks.
 * 
 */
 
double k = 5.0/1024;
double luxFactor = 500000;
double R2 = 10000;
int LowLightLimit = 200; 

const int LED = 7;

int light_intensity (int RawADC0) {
   double V2 = k*RawADC0; 
   double R1 = (5.0/V2 - 1)*R2;
   int lux = luxFactor/R1;
   return lux;
}

void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
  }

void loop() {  
    int intensity = light_intensity(analogRead(0));
    if (intensity < LowLightLimit) {
        digitalWrite(LED, HIGH);  
      } else { 
        digitalWrite(LED, LOW);
      }
    Serial.println(intensity);
    delay(1000);
  }

