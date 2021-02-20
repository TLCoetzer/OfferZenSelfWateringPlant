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

# define SHORT_WAIT 2000
# define LONG_WAIT 10000

int delayPeriod = 2000;

int pumpPeriod = SHORT_WAIT;
int waitPeriod = LONG_WAIT;

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

  //If dry pump a quick short burst of water
  if (sensorValueA > 400)
    pumpQuick();

  //Flash Led if not pumping just to show something still happening
  if (waitPeriod == SHORT_WAIT)
    ledOn();
    
  delay(waitPeriod);  // Wait a bit... Long of it just pumped, short otherwise
  ledOff();

  //If done waiting for sensor reading change after pumping, then reset to short wait
  if (waitPeriod == LONG_WAIT)
    waitPeriod = SHORT_WAIT;
  else //If not just pumped then wait another short while with led off, to create blinking effect
    delay(waitPeriod); // Wait a bit
}

void pumpQuick()
{
  Serial.println("Pump quickly");
  digitalWrite(MOTOR_POWER, HIGH); //Motor on
  ledOn();
  delay(pumpPeriod);              // Wait a second

  //analogWrite(MOTOR_POWER, 0); //Motor off
  digitalWrite(MOTOR_POWER, LOW); //Motor off
  ledOff();

  Serial.println("Wait a couple of seconds before trying next reading");
  waitPeriod = LONG_WAIT; //Set waiting period long to allow water to distribute and sensor reading to change
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
