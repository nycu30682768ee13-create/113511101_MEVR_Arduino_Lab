using System;
using System.Windows.Forms;
using System.IO.Ports;

namespace MEVR_Arduino_3_2 
{
    public partial class Form1 : Form
    {
        SerialPort mySerialPort;

        public Form1()
        {
            InitializeComponent();
            mySerialPort = new SerialPort("COM3", 9600);  
            //mySerialPort = new SerialPort("COM8", 9600);  //BlueTooth

            // 註冊 DataReceived 事件，當 Arduino 傳資料來時會自動觸發
            mySerialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            // 建議在程式啟動時就開啟通訊埠
            try
            {
                if (!mySerialPort.IsOpen) mySerialPort.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show("通訊埠開啟失敗: " + ex.Message);
            }
        }

        // On 按鈕事件
        private void button1_Click(object sender, EventArgs e)
        {
            if (mySerialPort.IsOpen) mySerialPort.Write("1");
        }

        // Off 按鈕事件
        private void button2_Click(object sender, EventArgs e)
        {
            if (mySerialPort.IsOpen) mySerialPort.Write("0");
        }

        // 當接收到 Arduino 資料時會執行的函式
        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;

            // 讀取 Arduino 傳來的一整行文字 (直到換行符號)
            string inData = sp.ReadLine().Trim();

            // 使用 Invoke 將更新 UI 的動作推回主執行緒執行
            this.Invoke((MethodInvoker)delegate
            {
                if (inData == "Pressed")
                {
                    labelStatus.Text = "Arduino 狀態: Button Pressed!";
                }
                else if (inData == "Released")
                {
                    labelStatus.Text = "Arduino 狀態: Button Released!";
                }
            });
        }

        // 程式關閉時確保釋放通訊埠資源
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (mySerialPort != null && mySerialPort.IsOpen)
            {
                mySerialPort.Close();
            }
        }
    }
}