#define BUTTON 11  // Define identifier BUTTON to 11
#define LED 13     // Define identifier LED to 13

// Initialize a global integer variable `button_state` to 0
int button_state = 0;

void setup() {
  pinMode(LED, OUTPUT);    // Initialize LED pin as output
  pinMode(BUTTON, INPUT);  // Initialize BUTTON pin as input
}

void loop() {
  button_state = digitalRead(BUTTON);  // Read the current state of BUTTON pin

  if (button_state == HIGH) {  // If button_state is HIGH
    digitalWrite(LED, HIGH);   // Turn on the LED
  } else {                     // If not
    digitalWrite(LED, LOW);    // Turn off the LED
  }
}
