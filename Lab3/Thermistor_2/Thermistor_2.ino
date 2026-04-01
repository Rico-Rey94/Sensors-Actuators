#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ThermistorPin = A0;
int Vo;
float logR2, R2, T, Tc, Tf;
float A = 1.009249522e-03, B = 2.378405444e-04, C = 2.019202697e-07;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}
void loop() {
  Vo = analogRead(ThermistorPin);
  R2 = (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (A + B*logR2 + C*logR2*logR2*logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0)/ 5.0 + 32.0;
 
  lcd.print("Temp: ");
  lcd.setCursor(0,1);
  lcd.print(Tc);
  lcd.print(" C; ");
  lcd.print(Tf);
  lcd.print(" F");  
  delay(500);
}