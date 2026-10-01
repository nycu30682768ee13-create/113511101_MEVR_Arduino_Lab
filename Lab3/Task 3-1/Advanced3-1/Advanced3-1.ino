#include <TimerOne.h>

// --- A 組腳位與變數 ---
const int buttonPinA = 2;  
const int ledPinA = 13;

// --- B 組腳位與變數 ---
const int buttonPinB = 4;  
const int ledPinB = 12;

void setup() {
  pinMode(ledPinA, OUTPUT);
  pinMode(buttonPinA, INPUT); 
  
  pinMode(ledPinB, OUTPUT);
  pinMode(buttonPinB, INPUT);

  // --- Button A + LED A: Timer Interrupt (TimerOne) ---
  Timer1.initialize(50000); // 設定 50ms 中斷
  Timer1.attachInterrupt(timerISR);
}

// Timer1 ISR：每 50ms 執行一次
void timerISR() {
  bool currentButtonStateA = digitalRead(buttonPinA);
  
  // 按下為 HIGH，未按為 LOW
  if (currentButtonStateA == HIGH) {
    digitalWrite(ledPinA, HIGH); // 按下時：亮
  } else {
    digitalWrite(ledPinA, LOW);  // 放開時：滅
  }
}

void loop() {
  // --- Button B + LED B: Blocking Delay ---
  bool currentButtonStateB = digitalRead(buttonPinB);

  // 按下為 HIGH，未按為 LOW
  if (currentButtonStateB == HIGH) {
    digitalWrite(ledPinB, HIGH); // 按下時：亮
  } else {
    digitalWrite(ledPinB, LOW);  // 放開時：滅
  }
  
  // 1 秒鐘的阻塞延遲
  delay(1000);
}
