// Define the LED pins
int ledPins[] = {2, 3, 4, 5}; // Adjust according to your wiring (e.g., pins 2,3,4,5)
int numLEDs = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  // Set LED pins as OUTPUT
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Blink each LED in sequence with a 1000ms delay
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);  // Turn LED ON
    delay(1000);
    digitalWrite(ledPins[i], LOW);   // Turn LED OFF
  }
}