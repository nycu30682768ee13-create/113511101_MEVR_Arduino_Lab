const int buttonPin = 2;
const int RPin = 8;
const int GPin = 9;
const int BPin = 10;
const int anaPin = A0;

int buttonState = 0;
int val;
int greenon = 0;

void setup() {
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(RPin, HIGH);
  } else {
    digitalWrite(RPin, LOW);
  }

  if (Serial.available() > 0){
    char input = Serial.read();
    if (input == '1'  ){
      greenon = 1;
    }else if(input == '0'){
      greenon = 0;
    }
  }
  digitalWrite(GPin, greenon);

  val = analogRead(anaPin);
  analogWrite(BPin, val/4);
  Serial.print("Blue Light Brightness is ");
  Serial.print(val/4);
  Serial.println();
  delay(1000);
}
