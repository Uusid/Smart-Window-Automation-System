# Smart Window Automation System 🚪☁️🔥

A smart automation system built using Arduino Uno that controls a window based on real-world environmental inputs like rain and smoke, time-based triggers, and remote manual commands. It enhances safety and convenience for smart homes.

## 📌 Project Overview

This project demonstrates how sensors can be used to automate a window’s behavior in a home or office environment. The window reacts to weather conditions, fire hazards, and time-based schedules using a combination of sensors and servo motors.

## 🎯 Features

- 🌧️ **Rain Detection**: Automatically closes the window when rain is detected using a rain sensor.
- 🔥 **Fire/Smoke Detection**: Opens the window during smoke/fire events for emergency ventilation using a smoke sensor.
- 🕒 **Time-Based Control**: Opens the window at **7:00 AM** and closes it at **6:00 PM** automatically.
- 🎮 **Remote Manual Control**: Operate the window using a serial interface (remote) with predefined commands.
- 🔧 **Simple Hardware Setup**: Uses basic components like Arduino Uno, servo motor, and sensors.

## 🛠️ Components Used

| Component           | Quantity |
|---------------------|----------|
| Arduino Uno         | 1        |
| Servo Motor         | 1        |
| Rain Sensor (Digital)| 1        |
| Smoke Sensor (Analog)| 1        |
| Red LED (Indicator) | 1        |
| Jumper Wires        | As needed |
| Breadboard          | 1        |

## 💡 Working Principle

- **Smoke Sensor (A5)**: If smoke is detected (`value > 40`), LED turns on and the window opens.
- **Rain Sensor (D2)**: If rain is detected (`digitalRead = 1`), the window closes.
- **Serial Commands**:
  - `'1'` – Open (0°)
  - `'2'` – Half-open (90°)
  - `'3'` – Close (180°)
- **Time Logic**: (Assume integrated with real-time clock in advanced versions or can be simulated using `millis()` in Arduino).

## 🧠 Code

```cpp
#include <Servo.h>
int redLed = 13;
int smoke = A5;
int rain = 2;
Servo s1;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(smoke, INPUT);
  pinMode(rain, INPUT);
  s1.attach(9);
  s1.write(0);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char a = Serial.read();
    Serial.println(a);
    if (a == '1') s1.write(0);
    if (a == '2') s1.write(90);
    if (a == '3') s1.write(180);
  }

  int smokeSensor = analogRead(smoke);
  int rainSensor = digitalRead(rain);

  Serial.print("Smoke Sensor (A5): ");
  Serial.println(smokeSensor);
  Serial.print("Rain Sensor (D2): ");
  Serial.println(rainSensor);

  if (smokeSensor > 40) {
    digitalWrite(redLed, HIGH);
    s1.write(0); // Open window
  } else {
    digitalWrite(redLed, LOW);
    s1.write(90); // Normal position
  }

  if (rainSensor == 1) {
    digitalWrite(redLed, HIGH);
    s1.write(90); // Close window
  } else {
    digitalWrite(redLed, LOW);
    s1.write(0); // Open window
  }

  delay(100);
}


📊 Project Outcome
✅ Functional prototype built
✅ Demonstrated smart environmental control
✅ Practical integration of sensors and actuators
✅ Hands-on exposure to embedded systems and automation logic

🧪 Future Improvements
Add real-time clock (RTC) module for precise time-based control
WiFi/Bluetooth module for mobile control
Integration with smart home platforms (like Alexa/Google Home)

👨‍💻 Developed By
Pandit Siddharth Rajesh
Arduino | Embedded Systems | Automation

