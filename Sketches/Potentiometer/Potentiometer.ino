#define POT A0
#define LED 13

int sensor_value = 0;
int brightness;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  sensor_value = analogRead(POT);
  brightness = map(sensor_value, 0, 1023, 0, 255);
  analogWrite(LED, brightness);
}
