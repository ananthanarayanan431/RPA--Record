const int analogPin = A0; // Pin connected to the analog output of the sensor
int sensorValue; // Variable to store the raw sensor value
float distance_cm; // Variable to store calculated distance in centimeters

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read the raw sensor value
  sensorValue = analogRead(analogPin);

  // Convert the raw sensor value to distance (in cm) using a formula
  // Replace the formula with the one specified in your sensor's datasheet
  distance_cm = 10650.08 * pow(sensorValue, -0.935) - 10;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(100); // Delay for stability
}
