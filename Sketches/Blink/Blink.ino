// Define identifier LED to 13. Wherever the string 'LED' occurs
// in this sketch, it will be replaced by string '13'
#define LED 13

void setup() {
  pinMode(LED, OUTPUT);    // Initialize LED pin as output
}

void loop() {
  digitalWrite(LED, HIGH); // Pull the LED pin to HIGH
  delay(1000);             // Sleep for 1000 milliseconds (1 second)
  digitalWrite(LED, LOW);  // Pull the LED pin to LOW
  delay(1000);             // Sleep for 1000 milliseconds
}
