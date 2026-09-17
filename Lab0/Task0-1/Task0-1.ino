const int led_pin = 13;

void setup() {
  pinMode(led_pin, 1);
}

void loop() {
  digitalWrite(led_pin, 1);
  delay(1000);
  digitalWrite(led_pin, 0);
  delay(1000);
}
