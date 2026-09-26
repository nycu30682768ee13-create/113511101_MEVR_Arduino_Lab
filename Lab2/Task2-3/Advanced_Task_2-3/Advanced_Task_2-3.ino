const int buttonPinA = 2;  
const int ledPinA = 13;
volatile bool ledStateA = 0;
const int buttonPinB = 4;  
const int ledPinB = 12;
bool ledStateB = 0;
bool lastButtonStateB = 1; 

void setup() {
  pinMode(ledPinA, OUTPUT);
  pinMode(buttonPinA, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPinA), buttonISR, FALLING);

  pinMode(ledPinB, OUTPUT);
  pinMode(buttonPinB, INPUT);
}

void buttonISR() {
  ledStateA = !ledStateA;
  digitalWrite(ledPinA, ledStateA);
}

void loop() {
  // --- Button B + LED B: 改用輪詢方式 ---
  // 持續檢查 Button B 的狀態，並偵測按壓轉換 (邊緣偵測)
  bool currentButtonStateB = digitalRead(buttonPinB);

  // 判斷按鈕狀態是否從 HIGH (未按) 變成 LOW (按下)
  if (lastButtonStateB == HIGH && currentButtonStateB == LOW) {
    // 當偵測到按壓時，切換 LED B 狀態
    ledStateB = !ledStateB;
    digitalWrite(ledPinB, ledStateB);
  }
  // 更新按鈕狀態紀錄，供下一次迴圈比對使用
  lastButtonStateB = currentButtonStateB;
  delay(2000);
}
