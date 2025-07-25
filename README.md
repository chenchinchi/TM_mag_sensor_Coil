---

# TM\_mag\_sensor\_Coil 使用說明

---

## 一、輸入訊號

* **輸入電壓**：5V（訊號若過大或過小，請優先調整）
* **建議頻率**：1000 Hz（頻率可調整，但需注意線圈與放大器負荷；例如：1 MHz / 10 V 時，輸出可能達振幅 34 V）
* **輸入端說明**：任一組線圈皆可輸入激勵訊號

---

## 二、訊號處理電路

<img src="https://github.com/user-attachments/assets/f1ecc6f4-8cae-4f4a-92ea-469d81243e49" width="800"/>

> 訊號經二極體整流後，透過低通濾波器濾除高頻（激勵）成分，保留瑕疵所產生的低頻訊號，以辨識缺陷。
> ※ Vs 上下限為 ±15V。

---

## 三、Teensy 端程式

* `Sensor_signal.ino`：
  適用於訊號處理電路正常運作時，將輸出電壓值取平均。

* `max_voltage.ino`：
  當訊號讀值異常時可用，直接採樣 2000 點並取最大振幅，以輔助瑕疵分析。

---

## 四、感測器結構

### ▍方形同心線圈

| 線圈類型     | 尺寸（長×寬）  | 匝數    |
| -------- | -------- | ----- |
| 外部線圈（紅黑） | 6 × 8 mm | 100 匝 |
| 內部線圈（黃綠） | 3 × 4 mm | 60 匝  |

<img src="https://github.com/user-attachments/assets/6d0915b4-47ad-4989-bf6c-7b47a9b626f3" width="500"/>

---

### ▍圓形同心線圈

| 線圈類型     | 尺寸（直徑） | 匝數   |
| -------- | ------ | ---- |
| 外部線圈（紅黑） | 14 mm  | 80 匝 |
| 內部線圈（黃綠） | 9 mm   | 50 匝 |

<img src="https://github.com/user-attachments/assets/7d20595a-1d43-4403-a56b-3bc8c62562db" width="500"/>

---

### ▍差分線圈結構

| 線圈類型     | 尺寸（長×寬）    | 匝數    |
| -------- | ---------- | ----- |
| 激勵線圈     | 14 × 16 mm | 120 匝 |
| 差分線圈（單個） | 3 × 7 mm   | 60 匝  |

<img src="https://github.com/user-attachments/assets/a1a2033d-2d3e-42c7-9879-d4a63d770ca6" width="500"/>

---

## 五、感測器接口（外觀圖）

### ▍上視圖

<img src="https://github.com/user-attachments/assets/c62f7803-c9ad-49c0-a165-46a7854cda16" width="300"/>

---

### ▍側視圖

<img src="https://github.com/user-attachments/assets/2bef0255-d781-408d-8d4d-251d47cf25c7" width="300"/>

---

