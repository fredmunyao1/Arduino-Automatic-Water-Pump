// Define the pins for the ultrasonic sensor and the pump
const int trigPin = 4;
const int echoPin = 3;
const int pumpPin = 13;

// Define the maximum and minimum distances for the water level
const int maxDistance = 10; // in cm
const int minDistance = 4; // in cm

void setup() {
  // Initialize the serial communication for debugging
  Serial.begin(9600);

  // Set the trigPin as an output and the echoPin as an input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set the pumpPin as an output
  pinMode(pumpPin, OUTPUT);
}

void loop() {
  // Measure the distance using the ultrasonic sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if the distance is above the maximum distance
  if (distance > maxDistance) {
    // Turn on the pump
    digitalWrite(pumpPin, HIGH);
  } else if (distance < minDistance) {
    // Turn off the pump
    digitalWrite(pumpPin, LOW);
  }

  // Wait for a short time before taking another measurement
  delay(100);
}
