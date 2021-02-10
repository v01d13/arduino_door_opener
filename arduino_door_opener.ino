// ---------------------------------------------------------------- //
#include <Servo.h>
#define echoPin 2 // setting up arduino pin 2 as echo pin for ultrasonic module HC-SR04
#define trigPin 3 //setting up arduino pin 3 as trigger pin for ultrasonic module  HC-SR04
int servoPin = 9; 
// Creating a servo object to write to it
Servo ServoMotor;

//long duration; // variable for the duration of time taken by the sound wave to return to the module
//int distance; // variable for the distance measurement

void setup() {
  ServoMotor.attach(servoPin); 
  pinMode(trigPin, OUTPUT); // sets the trigger pin as an OUTPUT
  pinMode(echoPin, INPUT); // sets the echo pin as an INPUT
  Serial.begin(9600); // // serial sommunication beginning with 9600 of baudrate speed
}
void loop() {
  delayMicroseconds(1000); // waits for 1000 milliseconds
  int distance = ultrasonic();
  Serial.println("Ultrasonic Sensor HC-SR04 Test");
  Serial.println(distance); // displays the distance on serial monitor
  // writes to the servo depending on the distance calculated by the HC-SR04 module
  if (distance <= 20) {
    ServoMotor.write(90);
    delay(1000);
    }
  else {
    Servo1.write(20);
    delay(1000);
    }
}
int ultrasonic() {
  // Clears the trigger pin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  // reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  // distance calculation
  int distance = duration * 0.034 / 2;
  // returns the distance
  return distance;
}
