// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
const int lm35 = 0;
float temperatura; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Symbol grade
byte grade[8] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000
}

void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.createChar(0, grade);
  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("C");
  lcd.write(byte(0));
  lcd.print(":");

  lcd.setCursor(5,0)
  lcd.print("raw:")
}

void loop() {

  int value = analogRead(lm35);
  //los 5k es por el voltaje, por ahora me da un voltaje de 4.3
  //float millivolts = (value / 1023.0) * 5000;
  float millivolts = (value / 1023.0) * 4990;
  temperatura = millivolts / 10; 
  Serial.print(value);
  Serial.print(" ");
  Serial.print(temperatura);
  Serial.println(" C");
   
  // Esperamos un tiempo para repetir el loop
  delay(1000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(3, 0);
  lcd.print(temperatura);

  lcd.setCursor(14,0);
  lcd.print(value);
  
}
