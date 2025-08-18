// 硬體部分 teensy 4.0
const int analogPin = A0; 
const float Vref = 3.3; 
const int ADC_resolution = 1023;

// 平滑參數
const int smoothWindow = 5;   // 平滑窗口大小 (可調整)
float smoothBuffer[smoothWindow];
int bufferIndex = 0;
float smoothSum = 0;
float smoothVoltage = 0;       // 平滑後的電壓值
float prev_smoothVoltage = 0;
// 原始電壓
float voltage = 0;
//////////////////////////////////////////////////
IntervalTimer myTimer;
void outputFunction() {
  // 輸出原始值 + 平滑後的結果
  Serial.print(smoothVoltage, 3);
  //Serial.print(" ");
  //Serial.print(abs(smoothVoltage-prev_smoothVoltage), 3);
  Serial.print(" ");
  Serial.println(1);
  prev_smoothVoltage = smoothVoltage;
}
/////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  analogReadResolution(10);
  analogReadAveraging(5);   // 硬體平均
  myTimer.begin(outputFunction, 100000);  // 每 50 ms 輸出一次
  
  // 初始化平滑緩衝區
  for (int i = 0; i < smoothWindow; i++) {
    smoothBuffer[i] = 0;
  }
}

void loop() {
  // 讀取新的 ADC 值
  int adcValue = analogRead(analogPin);
  voltage = adcValue * Vref / ADC_resolution;

  // 更新移動平均 (滑動窗口)
  smoothSum -= smoothBuffer[bufferIndex];    // 移除舊值
  smoothBuffer[bufferIndex] = voltage;       // 放入新值
  smoothSum += voltage;                      // 累加新值
  bufferIndex = (bufferIndex + 1) % smoothWindow;

  smoothVoltage = smoothSum / smoothWindow;  // 平滑後的電壓
}
