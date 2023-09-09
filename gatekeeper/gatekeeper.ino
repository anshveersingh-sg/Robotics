#include <Servo.h>

Servo gateServo;
int irSensorPin = 2; // Define the IR sensor pin
int irSensorThreshold = 500; // Adjust this value according to your setup
bool gateOpen = false;

void setup() {
  gateServo.attach(9); // Servo control pin
  pinMode(irSensorPin, INPUT);
  Serial.begin(9600);
  closeGate(); // Start with the gate closed
}

void loop() {
  int irValue = analogRead(irSensorPin);

  if (irValue < irSensorThreshold) {
    if (!gateOpen) {
      openGate();
    }
  } else {
    if (gateOpen) {
      closeGate();
    }
  }
}

void openGate() {
  gateServo.write(90); // Adjust the angle as needed
  delay(1000); // Adjust the delay to control the gate open time
  gateOpen = true;
  Serial.println("Gate Opened");
}

void closeGate() {
  gateServo.write(0); // Adjust the angle as needed
  delay(1000); // Adjust the delay to control the gate close time
  gateOpen = false;
  Serial.println("Gate Closed");
}
