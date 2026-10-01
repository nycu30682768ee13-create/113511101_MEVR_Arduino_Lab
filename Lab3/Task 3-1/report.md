課題報告：Advanced Task 3-1 Timer Interrupt vs Blocking Delay

學生姓名：耿同德

學生學號：113511101

完成日期：2026-10-01

---

1. 實驗目標

學習使用 TimerOne 外部函式庫於 Arduino 設定硬體計時器中斷（Timer Interrupt）。

實作並比較「計時器中斷」與「阻塞延遲（Blocking Delay）」在微控制器多工處理與任務排程上的差異。

探討並驗證在機器人或複雜電機控制系統開發中，應如何運用中斷機制來確保系統對外界感測訊號的即時反應能力。


2. 設備與元件

Arduino Uno 開發板 x 1

USB Type-B 傳輸線 x 1

個人電腦（已安裝 Arduino IDE）x 1

麵包版 x 1

按鈕 x 2

LED x 2

杜邦線 x 若干

電阻 x 若干


3. 操作說明與成果

硬體接線與燒錄：建立兩組「按鈕與 LED」配對電路。將 A 組按鈕與 LED 分別接至 Arduino 的數位腳位（Pin 2 與 Pin 13），B 組接至另外兩個數位腳位（Pin 4 與 Pin 12）。撰寫程式時，A 組使用 TimerOne 函式庫設定每 50ms 觸發一次計時器中斷，並在中斷服務常式（ISR）中讀取按鈕 A 並更新 LED A 的狀態；B 組則在主程式 loop() 中讀取按鈕 B 並更新 LED B，同時在迴圈尾端加入 1 秒的 delay(1000)。使用 USB 線連接 Arduino Uno 至電腦並上傳程式碼。

實驗成果：

A 組（Timer Interrupt）：無論何時按下或放開 A 按鈕，LED A 皆能即時同步亮滅。計時器中斷在背景精確獨立運作，完全不受主程式延遲的影響，反應極為靈敏。

B 組（Blocking Delay）：操作 B 按鈕時，系統反應極度遲鈍。因為 CPU 在 delay(1000) 執行期間處於徹底停擺狀態，必須長按按鈕或剛好在 1 秒延遲結束的瞬間按下，LED B 才會切換狀態，且放開時也會出現嚴重的延遲熄滅現象。

操作影片：請參閱同目錄下 DemoVideo/Advanced_3-1.mp4 之實際操作畫面。
