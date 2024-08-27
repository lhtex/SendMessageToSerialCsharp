#include <LiquidCrystal_I2C.h>

char c;
String dataIn;

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();
  Serial.begin(57600);
  delay(200);

  Serial.println ("Read Serial Print LCD");
  Serial.println ("This Program Created by LHT") ;

  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Projeto #1");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("Read Serial ..."); // print message at (2, 1)
  delay(2000);                 // display the above for two seconds
  lcd.clear();                 // clear display
  lcd.print("Projeto #1");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("print LCD"); // print message at (2, 1)
  delay(2000);                 // display the above for two seconds
}

void loop()
{
  Receive_Serial_Data();
  //print LCD
}

void Receive_Serial_Data()
{
  while(Serial.available()>0)
  {
    c=Serial.read();
    if(c=='\n') {break;}
    else {dataIn+=c;}
  }

  if(c=='\n')
  {
    c=0;
    Serial.println((String)"Message: " + dataIn);
    lcd.clear();                 // clear display
    lcd.setCursor(3, 0);         // move cursor to   (0, 0)
    lcd.print("Message:");        // print message at (0, 0)
    lcd.setCursor(0, 1);         // move cursor to   (2, 1)
    lcd.print(dataIn); // print message at (2, 1)
    delay(2000);                 // display the above for two seconds
    dataIn="";
  }
}

//lcd.clear();                 // clear display
//    lcd.setCursor(3, 0);         // move cursor to   (0, 0)
//    lcd.print("Message:");        // print message at (0, 0)
//    lcd.setCursor(0, 1);         // move cursor to   (2, 1)
//    lcd.print(dataIn); // print message at (2, 1)
//    delay(2000);                 // display the above for two seconds
