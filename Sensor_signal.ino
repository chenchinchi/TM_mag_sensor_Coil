const int analogPin = A0;               // 模擬輸入腳位
const float referenceVoltage = 3.3;     // Teensy 通常是 3.3V
const int adcMax = 1023;                // 10-bit ADC（根據型號可調整為 4095）

const int sampleRateHz = 10000;         // 採樣率 = 10kHz
const int averagingCount = 2000;        // 每 2000 筆取平均
const unsigned long sampleIntervalMicros = 1000000 / sampleRateHz;

unsigned long lastSampleTime = 0;
unsigned int sampleCounter = 0;
unsigned long sumADC = 0;

void setup() {
  Serial.begin(115200);                 // 使用 Teensy 高速序列傳輸
  analogReadResolution(10);            // 設定 ADC 為 10-bit（可改成12或16）
}

void loop() {
  unsigned long now = micros();
  if (now - lastSampleTime >= sampleIntervalMicros) {
    lastSampleTime = now;

    int adcValue = analogRead(analogPin);
    sumADC += adcValue;
    sampleCounter++;

    if (sampleCounter >= averagingCount) {
      float averageADC = sumADC / (float)averagingCount;
      float voltage = averageADC * referenceVoltage / adcMax;

      Serial.println(voltage, 4);      // 輸出平均電壓（保留4位小數）
      
      // 重置
      sumADC = 0;
      sampleCounter = 0;
    }
  }
}
