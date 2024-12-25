#define TRIG_PIN 10
#define ECHO_PIN 11
#define BUZZER_PIN 2

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600); // For debugging
}

void loop() {
  long duration;
  float distance;

  // Send a 10-microsecond pulse to trigger pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert time to distance in cm
  distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Activate the buzzer if the distance is less than 20 cm
  if (distance < 20.0) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(100); // Wait for a short time before the next reading
}
