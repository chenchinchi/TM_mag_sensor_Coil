const int analogPin = A0;               // 模擬輸入腳位
const float referenceVoltage = 3.3;     // 依據你板子的實際電壓
const int adcMax = 1023;                // 若用 analogReadResolution(10)，就是 1023

const int bufferSize = 2000;            // 要記錄的樣本數
int buffer[bufferSize];
int index = 0;
bool bufferFilled = false;

void setup() {
  Serial.begin(115200);                 // Teensy 序列速度可再調高
  analogReadResolution(10);            // 10-bit 精度，最快
}

void loop() {
  buffer[index] = analogRead(analogPin);
  index++;

  if (index >= bufferSize) {
    index = 0;
    bufferFilled = true;
  }

  // 當資料填滿一次後，才開始輸出
  if (bufferFilled) {
    int maxValue = 0;
    for (int i = 0; i < bufferSize; i++) {
      if (buffer[i] > maxValue) {
        maxValue = buffer[i];
      }
    }

    float maxVoltage = maxValue * referenceVoltage / adcMax;
    Serial.println(maxVoltage, 4);  // 輸出最大電壓
    bufferFilled = false;           // 下一輪再收集2000筆
  }
}
