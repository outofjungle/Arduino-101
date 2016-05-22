#include <CapacitiveSensor.h>

#define LED 13
#define SEND_PIN 4
#define SENSOR_PIN 2
#define THRESHOLD 1000

int button_state;
int last_button_state = LOW;
int led_state = LOW;

long last_debounce_time = 0;
long debounce_delay = 50;

CapacitiveSensor sense = CapacitiveSensor(SEND_PIN, SENSOR_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  long raw_value =  sense.capacitiveSensor(30);
  Serial.println(raw_value);

  int reading = (raw_value > THRESHOLD) ? HIGH : LOW;


  if (reading != last_button_state) {
    last_debounce_time = millis();
  }

  if ((millis() - last_debounce_time) > debounce_delay) {
    if (reading != button_state) {
      button_state = reading;

      if (button_state == HIGH) {
        led_state = !led_state;
      }
    }
  }

  digitalWrite(LED, led_state);
  last_button_state = reading;

  delay(10);
}


