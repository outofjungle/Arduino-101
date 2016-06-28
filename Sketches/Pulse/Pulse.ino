#define LED 13  // Define identifier LED to 13

int brightness = 0; // Initialize brightness variable
int slope = 1;      // Slope, either positive or negative

void setup() {
  pinMode(LED, OUTPUT); // Initialize LED pin as output
}

void loop() {

  // Add the product of 1, slope to brightness
  brightness += (1 * slope);

  if (brightness > 254) {       // Brightness is at MIN
    slope = -1;                 // Change slope to -1
  } else if (brightness < 1) {  // Brightness is at MIN
    slope = 1;                  // Change slope to +1
  }

  analogWrite(LED, brightness); // PWM LED pin to the brightness value
  delay(2);                     // Sleep for 2 milliseconds
}
