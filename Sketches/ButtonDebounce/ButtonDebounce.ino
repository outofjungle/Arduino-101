#define BUTTON 11  // Define identifier BUTTON to 11
#define LED 13     // Define identifier LED to 13

// Initialize a global variables
//   `debounced_button_state` to 0 (debounced button state)
//   `last_button_state` to LOW (button not pressed)
//   `led_state` to LOW (LED off)
int debounced_button_state;
int last_button_state = LOW;
int led_state = LOW;

// Initialize a global variables
//   `last_debounce_time` to 0 (millis) since last change)
//   `debounce_delay` to 50 (millis before a change should be registered)
long last_debounce_time = 0;
long debounce_delay = 50;

void setup() {
  pinMode(LED, OUTPUT);           // Initialize LED pin as output
  pinMode(BUTTON, INPUT);         // Initialize BUTTON pin as input
  digitalWrite(LED, led_state);   // Set LED pin to led_state value
}

void loop() {
  // Read the current state of BUTTON pin
  int current_button_state = digitalRead(BUTTON);

  // If the button state has changed
  if (current_button_state != last_button_state) {
    // Set last_debounce_time to current millis
    last_debounce_time = millis();
  }

  // Set last_button_state to current_button_state value for next iteration
  last_button_state = current_button_state;

  // if difference between current millis and last_debounce_time > debounce_delay,
  // We have waited enough time for debouncing to stop.
  if ((millis() - last_debounce_time) > debounce_delay) {

    // If current button state is not the current_button_state, then it's time to register
    // the change of state and act on the button input
    if (debounced_button_state != current_button_state) {
      // Register the change of state
      debounced_button_state = current_button_state;

      // If the state changed from LOW to HIGH
      if (debounced_button_state == HIGH) {
        // Toggle the LED state variable
        led_state = !led_state;
      }
    }
  }

  digitalWrite(LED, led_state); // Set LED pin to led_state
}
