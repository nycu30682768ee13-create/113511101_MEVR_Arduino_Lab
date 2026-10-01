const int ledPin = 13;
const int buttonPin = 2;
bool lastButtonState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // --- 1. 接收 C# 傳來的指令 (控制 LED) ---
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);
    }
  }

  // --- 2. 偵測實體按鈕並將狀態回傳給 C# ---
  bool currentButtonState = digitalRead(buttonPin);
  
  // 如果狀態發生改變
  if (currentButtonState != lastButtonState) {
    delay(50); // 簡易硬體去彈跳延遲
    currentButtonState = digitalRead(buttonPin); // 再次確認狀態
    
    if (currentButtonState != lastButtonState) {
      if (currentButtonState == HIGH) {
        Serial.println("Pressed"); 
      } else {
        // 放開時為 LOW
        Serial.println("Released"); 
      }
      lastButtonState = currentButtonState; // 更新狀態紀錄
    }
  }
}
