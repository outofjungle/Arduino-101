#define LDR A2
#define LED 13

int sensor_value = 0;
int brightness;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  sensor_value = analogRead(LDR);
  Serial.println(sensor_value);
  brightness = map(sensor_value, 150, 650, 255, 0);
  analogWrite(LED, brightness);
}
