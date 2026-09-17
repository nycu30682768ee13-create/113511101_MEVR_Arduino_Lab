課題報告：Advanced Task 1-2 用三種不同輸入控制RGB LED

學生姓名：耿同德

學生學號：113511101

完成日期：2026-09-17

---

1. 實驗目標

學習共陰極 RGB LED 之硬體電路配置與限流電阻連接方式。

掌握整合三種不同訊號來源（數位按鈕輸入、類比可變電阻輸入、序列埠輸入）之控制邏輯。

學習利用可變電阻控制藍光（B）、按鈕觸發紅光（R）疊加產生紫光，以及透過 Serial Monitor 輸入字元疊加綠光（G）呈現白光之混色原理。

熟練運用 digitalRead()、analogRead() 及 Serial.read() 進行多重感測輸入與即時燈色狀態控制。

2. 設備與元件

Arduino Uno 開發板 x 1
USB Type-B 傳輸線 x 1
個人電腦（已安裝 Arduino IDE）x 1
麵包版 x 1
可變電阻 x 1
按鈕 x 1
電阻 x 4
RGB LED x 1
杜邦線 x 11

3. 操作說明與成果

硬體接線與燒錄：將共陰極 RGB LED 之最長腳（GND）接地，R、G、B 腳位各串接一個限流電阻後分別連接至 Arduino 數位/PWM 腳位；按鈕模組連接至數位輸入腳位，可變電阻訊號腳連接至類比輸入腳位（如 A0）。使用 USB 線連接 Arduino Uno 至電腦並上傳。

開啟監控器：開啟 Arduino IDE 的 Serial Monitor，確認鮑率（Baud rate）設定為 9600 baud。

實驗成果：

旋轉可變電阻時，RGB LED 亮起藍光（Blue）。

在維持藍光狀態下按下按鈕，疊加紅光呈現紫光（Purple）。

接著在 Serial Monitor 輸入字元 "1" 並送出，疊加綠光呈現白光（White），成功完成三種輸入訊號的逐層疊加混色控制。

操作影片：請參閱同目錄下 DemoVideo/Advanced 1-2.mp4 之實際操作畫面。
