/*
  Blink an ESP8266 NodeMCU board
  Turns flashes an LED for one second delay.
  
  This program needs no circuit. It will use a built-in LED
  
  by Eng. Alaa Al Nassan
 */


# define LED D4 // Use built-in LED which connected to D4 pin or GPIO 2
# define MOTOR_POWER D6 // Motor power
# define SENSE_DIGITAL D5 // Sensor Digital
# define SENSE_ANALOG A0 // Sensor Analog

int delayPeriod = 2000;
int sensorValueA = 0;
int sensorValueD = HIGH;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(MOTOR_POWER, OUTPUT);
  pinMode(SENSE_DIGITAL, INPUT);
  pinMode(SENSE_ANALOG, INPUT);
  
  Serial.begin(115200);
}

void loop() {
  //Read and display sensor values
  readSensor();

  //Flash Led
  ledOff();
  //analogWrite(MOTOR_POWER, 0); //Motor off
  digitalWrite(MOTOR_POWER, LOW); //Motor off
  delay(delayPeriod);              // Wait a second

  ledOn();
  //analogWrite(MOTOR_POWER, 255); //Motor on
  digitalWrite(MOTOR_POWER, HIGH); //Motor on
  delay(delayPeriod);              // Wait a second
}

void readSensor()
{
  sensorValueD = analogRead(SENSE_DIGITAL);
  sensorValueA = analogRead(SENSE_ANALOG);
  Serial.print("Sensor reading: ");
  Serial.print(sensorValueD);
  Serial.print(", ");
  Serial.println(sensorValueA);
}

void ledOff()
{
  digitalWrite(LED, HIGH);  // Turn the LED off because the LED is active low
  Serial.println("OFF");
}

void ledOn()
{
  digitalWrite(LED, LOW);   // Turn the LED on because the LED is active low
  Serial.println("ON");
}
