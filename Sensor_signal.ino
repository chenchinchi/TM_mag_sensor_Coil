#define USE_LCD false  // ← 改為 true 可重新啟用 LCD

#if USE_LCD
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x27);
#endif

const int analogPin1 = A0;
const int analogPin2 = A1;
const float referenceVoltage = 5.0;

void setup() {
#if USE_LCD
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("  Voltage Meter ");
  lcd.setCursor(0, 1);
  lcd.print("    Ready...    ");
  delay(2000);
  lcd.clear();
#endif

  Serial.begin(9600);
}

void loop() {
  int raw1 = analogRead(analogPin1);
  int raw2 = analogRead(analogPin2);

  float voltage1 = raw1 * referenceVoltage / 1023.0;
  float voltage2 = raw2 * referenceVoltage / 1023.0;
  float diff = voltage1 - voltage2;

#if USE_LCD
  lcd.setCursor(0, 0);
  lcd.print("A0:");
  lcd.print(voltage1, 2);
  lcd.print("V");

  lcd.setCursor(9, 0);
  lcd.print("A1:");
  lcd.print(voltage2, 2);
  lcd.print("V");

  lcd.setCursor(0, 1);
  lcd.print("Diff:");
  lcd.print(diff, 2);
  lcd.print("V   ");
#endif
  Serial.print("A0: ");
  Serial.print(voltage1, 3);
  Serial.print(",");
  Serial.print("A1: ");
  Serial.print(voltage2, 3);
  Serial.print(",");
  Serial.print("diff: ");
  Serial.println(diff, 3);

  delay(300);
}
