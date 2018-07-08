/*
 * HC-SR04 Basic Usage
 * Testing functions of HC-SR04 Ultrasonic Range Finder
 * Displays results on Serial Monitor 
 * 
 * Paulo RT Valle
 * http://yvrca.com
 */

#define trigPin 10
#define echoPin 13

float duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  // Write a 10 microseconds pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);

  // Determine distance from duration
  // Speed of sound is 343 metres per second
  distance = (duration / 2) * 0.0343;

  // Print result on Serial Monitor
  Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2){
    Serial.println("Out of range"); 
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Wait for the next reading
  delay(1000);
}
