#define trigPin 9
#define echoPin 10
#define buzzer 8

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance (in cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Check distance and alert
  if (distance < 50) { // adjust threshold as needed
    tone(buzzer, 1000); // 1kHz tone
    delay(100);
    noTone(buzzer);
    delay(100);
  } else {
    noTone(buzzer);
  }

  delay(100);
}

