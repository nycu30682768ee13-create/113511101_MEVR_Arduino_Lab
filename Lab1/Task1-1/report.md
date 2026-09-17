課題報告：Advanced Task 1-1 用可變電阻調整LED亮度

學生姓名：耿同德

學生學號：113511101

完成日期：2026-09-17

---

1. 實驗目標

學習使用可變電阻進行分壓電路配置，並掌握 analogRead() 讀取類比輸入訊號之方法。

掌握利用類比讀取值控制 LED 亮度的技巧，實現訊號數值與 PWM 輸出（如 analogWrite()）之對應控制。

學習定時（每 1 秒）透過序列埠傳輸類比讀取數值，並於「序列埠監控器（Serial Monitor）」即時觀察與驗證數據變化。

理解 Arduino 內建類比數位轉換器（ADC）之解析度原理及其最大回傳值之成因。

2. 設備與元件

Arduino Uno 開發板 x 1
USB Type-B 傳輸線 x 1
個人電腦（已安裝 Arduino IDE）x 1
麵包版 x 1
可變電阻 x 1
電阻 x 1
LED x 1
杜邦線 x 6

### 3. 操作說明與成果
硬體接線與燒錄：將可變電阻兩端分別接至 5V 與 GND，中間訊號腳接至類比輸入腳位；將 LED 正極經限流電阻接至具 PWM 功能之數位腳位。使用 USB 線連接 Arduino Uno 至電腦並上傳。

開啟監控器：開啟 Arduino IDE 的 Serial Monitor，確認鮑率（Baud rate）設定為 9600 baud。

實驗成果：旋轉可變電阻時，LED 亮度隨讀取值增加而變亮、減小而變暗；同時 Serial Monitor 成功每隔 1 秒印出目前讀取到的數值（格式如 Data is xxx，數值介於 0 至 1023 之間）。

操作影片：請參閱同目錄下 DemoVideo/Advanced 1-1.mp4 之實際操作畫面。
