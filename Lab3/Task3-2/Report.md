課題報告：Advanced Task 3-2 C# 與 Arduino 序列通訊 (USB 雙向控制)

學生姓名：耿同德

學生學號：113511101

完成日期：2026-10-01

---

1. 實驗目標

學習透過 USB 實體傳輸線建立個人電腦（C# 應用程式）與 Arduino 之間的 UART 序列通訊。

掌握 C# Windows Forms 圖形化介面設計，以及 System.IO.Ports.SerialPort 類別的應用，並學習處理跨執行緒（Invoke）更新 UI 的技術。

實現雙向通訊邏輯：由 PC 端發送字串指令控制 Arduino 的硬體（LED），同時由 Arduino 偵測實體電路（按鈕）狀態並即時回傳顯示於 PC 端。


2. 設備與元件

Arduino Uno 開發板 x 1

USB Type-B 傳輸線 x 1

個人電腦（已安裝 Arduino IDE）x 1

麵包版 x 1

按鈕 x 1

LED x 1

杜邦線 x 若干

電阻 x 若干


3. 操作說明與成果

硬體接線與燒錄：將 LED 接至數位腳位（Pin 13），並將按鈕搭配下拉電阻接至另一數位腳位（Pin 2）。撰寫 Arduino 程式，設定 Serial.begin(9600) 以讀取序列埠指令控制 LED，並在主迴圈加入邊緣偵測與去彈跳邏輯來發送按鈕狀態。
接著於 Visual Studio 建立 C# Windows Forms 專案，透過 NuGet 安裝缺少之 System.IO.Ports 套件。設計包含 On/Off 按鈕與狀態 Label 的介面，並將 SerialPort 初始化綁定至 Arduino 對應的 USB COM 埠（COM3），最後處理接收事件的跨執行緒 UI 更新。

實驗成果：

由電腦控制硬體：於 C# 介面點擊「On」按鈕時，程式成功透過 USB 傳送字元 '1'，Arduino 接收後點亮 LED；點擊「Off」按鈕時，傳送字元 '0'，Arduino 接收後隨即熄滅 LED。

由硬體回傳狀態至電腦：當按下麵包板上的實體按鈕時，Arduino 偵測到腳位轉為 HIGH，並透過序列埠印出 "Pressed"，C# 應用程式接收後，介面上的 Label 成功同步更新為「Arduino 狀態: Button Pressed!」。當放開實體按鈕時，Arduino 偵測腳位轉為 LOW，回傳 "Released"，C# 介面即時切換顯示為「Arduino 狀態: Button Released!」。

操作影片：請參閱同目錄下 DemoVideo/Advanced_3-2.mp4 之實際操作畫面。
