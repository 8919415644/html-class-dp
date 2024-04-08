#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int x1;
float total=0;
String readString;
int g_led=4;
int r_led=5;
void setup()
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
  delay(2000);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  SMART RFID  ");
  lcd.setCursor(0,1);
  lcd.print(" SHOPING-TRALLY ");
  delay(3000);
}
void loop()
{
  x1=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" TOTAL: ");
  lcd.setCursor(0,1);
  lcd.print("SHOPING ");
  digitalWrite(4,HIGH);
  
  if (total<=0)
  {
    total=0;
  }
  else
  {
    total=total;
  }
   
  lcd.setCursor(10,0);
  lcd.print(total);
  delay(1000);
  
  while(Serial.available())
  {
    delay(1);
    char c = Serial.read();
    readString+=c;
    x1=x1+1;
    if (x1==12)
    {
     break;
    }
  }
  
  if(readString.length() >0)
  {
    Serial.println(readString);
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print (readString);
    lcd.setCursor(0,1);
    lcd.print("  ");
    delay(2000);
    else if(readString == "4C00212F7331")
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("WHEAT POWDER-70/");
      lcd.setCursor(0,1);
      lcd.print(readString);
      total=total+70; delay(3000);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      delay(3000);
      digitalWrite(5,LOW);
    }
     else if(readString == "4B00C531C17E")
  
    {
      lcd.clear();
      lcd.setCursor(0,0);
       
      lcd.print("BUTTER -80/- ");
      lcd.setCursor(0,1);
      lcd.print(readString);
      total=total+80;
      delay(3000);
      digitalWrite(4,LOW); 
      digitalWrite(5,HIGH);
      delay(3000); 
      digitalWrite(5,LOW);
    }
    else if(readString == "4C00212DA5E5")
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PANEER -110/-  ");
      lcd.setCursor(0,1); 
      lcd.print(readString);
      total=total+110;
      delay(3000);
      digitalWrite(4,LOW); 
      digitalWrite(5,HIGH);
      delay(3000);
      digitalWrite(5,LOW);
    }
    else if(readString == "4B00C50962E5")
    
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MILK PACKET-30/-");
      lcd.setCursor(0,1);
      lcd.print(readString);
      total=total+30;
      delay(3000);
      digitalWrite(4,LOW); 
      digitalWrite(5,HIGH);
      delay(3000); 
      digitalWrite(5,LOW);
    }
    else if(readString == "4B00C51E60F0")
    
    {
   
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("RICE IKg 60/- "); 
      lcd.setCursor(0,1);
      lcd.print(readString); 
      total=total+60;
      delay(1000);
      digitalWrite(4,LOW);
      digitalWrite(5,HIGH);
      delay(3000);
      digitalWrite(5,LOW);
    }
    else
    {
      delay(200);
    }
  readString = "";
  }
  readString = "";
}
 