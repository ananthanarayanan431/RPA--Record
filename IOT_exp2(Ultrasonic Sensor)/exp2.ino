const int trigPin = 2;
const int echoPin = 3;
const int ledPin = 13; // LED for indication
const int buz=12;
int count = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buz,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert distance to centimeters

  if (distance < 50) { // Adjust this threshold according to your setup
    count++;
    digitalWrite(ledPin, HIGH); // Turn on LED for indication
    delay(500); // Give a delay to avoid multiple counting for one person
    digitalWrite(ledPin, LOW); // Turn off LED
    Serial.print("Count: ");
    Serial.println(count);
  }

  delay(500); // Delay between each measurement
}
