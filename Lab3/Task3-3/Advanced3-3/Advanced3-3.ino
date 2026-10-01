#include <SoftwareSerial.h>

// 建立軟體序列埠物件 (RX: 10, TX: 11)
SoftwareSerial BTSerial(10, 11); 

const int ledPin = 13;
const int buttonPin = 2; 
bool lastButtonState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
  BTSerial.begin(9600); 
}

void loop() {
  // --- 1. 接收 C# 透過藍牙傳來的指令 ---
  if (BTSerial.available() > 0) {
    char command = BTSerial.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
    } else if (command == '0') {
      digitalWrite(ledPin, LOW);
    }
  }

  // --- 2. 偵測實體按鈕並透過藍牙回傳 ---
  bool currentButtonState = digitalRead(buttonPin);
  
  if (currentButtonState != lastButtonState) {
    delay(50); 
    currentButtonState = digitalRead(buttonPin); 
    
    if (currentButtonState != lastButtonState) {
      if (currentButtonState == HIGH) {
        BTSerial.println("Pressed"); 
      } else {
        BTSerial.println("Released"); 
      }
      lastButtonState = currentButtonState; 
    }
  }
}
