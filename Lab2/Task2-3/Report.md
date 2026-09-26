課題報告：Advanced Task 2-3 外部中斷與輪詢兩種控制方法的差異

學生姓名：耿同德

學生學號：113511101

完成日期：2026-09-24

---

1. 實驗目標

了解並實作輪詢（Polling）與外部中斷（External Interrupt）兩種硬體控制方法的差異。

學習如何在程式中透過邊緣觸發（Edge detection）來持續偵測按鈕狀態的改變。

透過模擬忙碌/阻塞系統（busy/blocking system），觀察並比較中斷與輪詢在執行效能與即時反應上的優劣，進而思考在開發機器人系統時較佳的應用選擇。


2. 設備與元件

Arduino Uno 開發板 x 1

USB Type-B 傳輸線 x 1

個人電腦（已安裝 Arduino IDE）x 1

麵包版 x 1

按鈕開關 (Push Button) x 2 

LED x 2

電阻 x 若干

杜邦線 x 若干


3. 操作說明與成果

硬體接線與燒錄：

在先前 Basic Task 2-3 的基礎上，於麵包板擴充第二組按鈕與 LED（即 Button B 與 LED B）。將按鈕與 LED 分別接至對應的 Arduino 數位腳位（其中 Button A 需接在支援外部中斷的腳位）。使用 USB 線連接 Arduino Uno 至電腦並上傳程式碼。

程式邏輯設定：

Button A 與 LED A：維持使用外部中斷（External interrupt）來控制 LED A 的開關狀態。

Button B 與 LED B：改為使用輪詢（Polling）方式，於程式中持續檢查 Button B 的狀態以偵測按壓變化，當偵測到按壓時切換 LED B 的狀態。

在程式的 void loop() 結尾處加入 delay(2000)，以模擬系統正處於忙碌或阻塞（busy/blocking）的狀態。

實驗成果：

受 delay(2000) 影響，當按下 Button B（輪詢）時，系統無法即時給予反應，導致 LED B 的切換發生遲滯或遺漏。

相反地，當按下 Button A（外部中斷）時，訊號能無視主程式的延遲阻塞，即時且準確地切換 LED A 的狀態。

成功對比出外部中斷與輪詢機制的差異，驗證了中斷機制在處理即時任務上的優勢。

操作影片：請參閱同目錄下 DemoVideo/Advanced 2-3.mp4 之實際操作畫面。
