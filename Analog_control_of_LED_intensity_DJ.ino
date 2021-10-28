/*
  用可變電阻控制類比輸入
  透過PWM做類比輸出控制LED燈亮度
*/

int sensorPin = A0;    //類比輸入的PIN腳 ()
int LEDPin = D7;      // 類比輸出的PIN腳，接到LED的正極
//int BUTTON = D5;      // 數位輸入的PIN腳，接到按鍵的正極
int sensorValue = 0;  // 類比輸入得到的數值

void setup() {
   Serial.begin(115200);
   pinMode(LEDPin, OUTPUT);  //LED的PIN腳設為輸出
}

void loop() {
  sensorValue = analogRead(sensorPin);   //讀取類比輸入的值會得到0~1023
  sensorValue = map(sensorValue,0,1023,0,255);  //將0~1023轉化成0~255
  Serial.println(sensorValue);
  delay(10);
  analogWrite(LEDPin,sensorValue);  //將結果用PWM的方式輸出給LED，改變亮度
}
