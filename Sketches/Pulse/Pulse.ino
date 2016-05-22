#define LED 13

int brightness = 0;
int slope = 1;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  brightness += (1 * slope);

  if (brightness > 254) {
    slope = -1;
  } else if (brightness < 1) {
    slope = 1;
  }
  
  analogWrite(LED, brightness);
  delay(2);
}
