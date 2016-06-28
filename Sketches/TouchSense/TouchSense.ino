#include <CapacitiveSensor.h>

#define LED 13        // Define identifier LED to 13
#define SEND_PIN 4    // Define SEND_PIN to 4
#define SENSOR_PIN 2  // Define SENSOR_PIN to 2
#define THRESHOLD 500 // Define THRESHOLD to 500

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

// Initialize a CapacitiveSensor object with SEND_PIN, SENSOR_PIN
CapacitiveSensor sense = CapacitiveSensor(SEND_PIN, SENSOR_PIN);

void setup() {
  Serial.begin(9600); // Enable serial communication back to the computer
}

void loop() {
  // Sense 30 samples and return the sum of the sensed capacitance
  long raw_value =  sense.capacitiveSensor(30);
  Serial.println(raw_value);

  // If the sensed value is above the THRESHOLD, consider
  // the current button state as HIGH
  int current_button_state = (raw_value > THRESHOLD) ? HIGH : LOW;

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
