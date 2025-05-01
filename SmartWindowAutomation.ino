#include <Servo.h>
int redLed = 13;
int smoke = A5;
int rain = 2;
Servo s1;

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(smoke, INPUT);
  pinMode(rain,INPUT);
  s1.attach(9);
  s1.write(0);
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available()>0)
  {
    char a = Serial.read();
    Serial.println(a);
    if(a == '1')
    s1.write(0);
    if(a == '2')
    s1.write(90);
    if(a == '3')
    s1.write(180);
  }
  int smokeSensor = analogRead(smoke);
  int rainSensor = digitalRead(rain);
  Serial.print("Pin A5: ");
  Serial.println(smokeSensor);
  Serial.print("Pin 2: ");
  Serial.println(rainSensor);
  delay(100);
  // Checks if it has reached the threshold value
  if (smokeSensor > 40)
  {
    digitalWrite(redLed, HIGH);
    s1.write(0);
  }
  else
  {
     digitalWrite(redLed, LOW);
     s1.write(90);
    }
    if (rainSensor == 1)
  {
    digitalWrite(redLed, HIGH);
    s1.write(90);
  }
  else
  {
     digitalWrite(redLed, LOW);
     s1.write(0);
    }
}
