#define POT A0  // Define identifier POT to A0 (analog pin 0)
#define LED 13  // Define identifier LED to 13

int sensor_value = 0; // Set initial sensor variable to 0
int brightness;       // Initialize brightness variable

void setup() {
  pinMode(LED, OUTPUT); // Initialize LED pin as output
}

void loop() {
  sensor_value = analogRead(POT); // Read analog value from analog pin 0

  // map values 0->1023 to 0->255 (higher the value, higher the brightness)
  brightness = map(sensor_value, 0, 1023, 0, 255);
  analogWrite(LED, brightness);   // PWM LED pin to the brightness value
}
