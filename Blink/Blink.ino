/*
  Blink an ESP8266 NodeMCU board
  Turns flashes an LED for one second delay.
  
  This program needs no circuit. It will use a built-in LED
  
  by Eng. Alaa Al Nassan
 */


# define LED D4 // Use built-in LED which connected to D4 pin or GPIO 2
# define MP D6 // Motor power
# define SENSE_DIGITAL D6 // Sensor Digital
# define SENSE_ANALOG D6 // Sensor Analog

int delayPeriod = 2000;

void setup() {
  pinMode(LED, OUTPUT);     // Initialize the LED as an output
  pinMode(MP, OUTPUT);     // Initialize the LED as an output
  Serial.begin(115200);
}


void loop() {
  digitalWrite(LED, HIGH);  // Turn the LED off because the LED is active low
  analogWrite(MP, 800);
  Serial.println("ON");
  delay(delayPeriod);            // Wait a second
  digitalWrite(LED, LOW);   // Turn the LED on because the LED is active low
  analogWrite(MP, 0);
  Serial.println("OFF");
  delay(delayPeriod);              // Wait a second
}
