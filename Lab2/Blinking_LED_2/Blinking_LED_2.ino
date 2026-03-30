// Define the LED pins
int ledPins[] = {2, 3, 4, 5};
int numLEDs = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 bps
  // Set LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int sensorValue = analogRead(A0); // Read potentiometer value (0-1023)
  Serial.println(sensorValue);      // Print value to serial monitor
  delay(100);                       // Small delay for stability
  // Blink each LED in sequence with a 1000ms delay
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);  // Turn LED ON
    delay(1000);
    digitalWrite(ledPins[i], LOW);   // Turn LED OFF
  }
}