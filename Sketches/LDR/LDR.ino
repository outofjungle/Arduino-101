#define LDR A2  // Define identifier LDR to A2 (analog pin 2)
#define LED 13  // Define identifier LED to 13

int sensor_value = 0; // Set initial sensor variable to 0
int brightness;       // Initialize brightness variable

void setup() {
  Serial.begin(9600);   // Enable serial communication back to the computer
  pinMode(LED, OUTPUT); // Initialize LED pin as output
}

void loop() {
  sensor_value = analogRead(LDR); // Read analog value from analog pin 2
  Serial.println(sensor_value);   // Print the read value onto the serial bus

  // map values 150->650 to 255->0 (higher the value, lower the brightness)
  brightness = map(sensor_value, 0, 1024, 254, 0);
  analogWrite(LED, brightness);   // PWM LED pin to the brightness value
}
