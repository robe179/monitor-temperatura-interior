// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
const int lm35 = 0;
float tempCelsius; 
float tempFahrenheit;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Symbol grade
byte grade[8] = {
  B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};

void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.createChar(0, grade);
  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(5,0);
  lcd.write(byte(0));
  lcd.print("C");

  lcd.setCursor(8,0);
  lcd.print("raw:");

  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.print("F");
}

void loop() {

  int value = analogRead(lm35);
  //los 5k es por el voltaje
  float millivolts = (value / 1023.0) * 5000;
  tempCelsius = millivolts / 10; 
  Serial.print(value);
  Serial.print(" ");
  Serial.print(tempCelsius);
  Serial.println(" C");
  tempFahrenheit = ( tempCelsius * (9/5)) + 32;
   
  // Esperamos un tiempo para repetir el loop
  delay(1000);
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print(tempCelsius);

  lcd.setCursor(0, 1);
  lcd.print(tempFahrenheit);

  lcd.setCursor(12,0);
  lcd.print(value);
  
}
