const int potPin = A0; // 可變電阻連接至類比輸入 A0
const int enA = 9;     // L293D Enable 1 (接支援 PWM 的腳位控制速度)
const int in1 = 8;     // L293D Input 1 (控制方向)
const int in2 = 7;     // L293D Input 2 (控制方向)

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // 1. 讀取可變電阻的類比數值 (範圍 0 到 1023)
  int potValue = analogRead(potPin); 
  int motorSpeed = 0;

  // 2. 判斷電位器位置，並設立中間「停止區間」避免數值飄移導致馬達震動
  if (potValue >= 490 && potValue <= 530) {
    // 中間位置：停止馬達
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    motorSpeed = 0;
  } 
  else if (potValue > 530) {
    // 向右旋轉：設定為正轉 (順時針)
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // 將數值 530~1023 映射到 PWM 速度 0~255
    motorSpeed = map(potValue, 530, 1023, 0, 255);
  } 
  else if (potValue < 490) {
    // 向左旋轉：設定為反轉 (逆時針)
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // 將數值 490~0 映射到 PWM 速度 0~255 (注意：越接近 0 速度越快)
    motorSpeed = map(potValue, 490, 0, 0, 255);
  }

  // 3. 輸出 PWM 訊號控制馬達最終轉速
  analogWrite(enA, motorSpeed);
}
