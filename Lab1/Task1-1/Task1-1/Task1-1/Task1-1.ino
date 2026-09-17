const int ledPin = 11;
const int anaPin = A0;
int val;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(anaPin);
  analogWrite(ledPin, val/4);
  Serial.print("Data is ");
  Serial.print(val);
  Serial.println();
  delay(1000);
}
