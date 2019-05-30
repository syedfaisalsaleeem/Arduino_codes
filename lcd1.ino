//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
/*******************************************************
This program will test the LCD panel and the buttons
Mark Bramwell, July 2010
********************************************************/
// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// define some values used by the panel and buttons
int lcd_key = 0;
int adc_key_in = 0;
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
int x;
int x_1;
int previous = LOW;
int previous_1=LOW;
unsigned long time = 0;           // the last time the output pin was toggled
unsigned long debounce = 200UL;
int count=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16, 2); // start the library
lcd.setCursor(0,0);
lcd.print("TEMP:"); // print a simple message
}

void loop() {
  // put your main code here, to run repeatedly:
adc_key_in = analogRead(0);
Serial.println(adc_key_in);
if(adc_key_in<110 && adc_key_in>90){
      x=HIGH;
       }
else if(adc_key_in<260 && adc_key_in >240)
{
  x_1=HIGH;
}
else
{
       x_1=LOW;
       x=LOW;
}

//else if (adc_key_in <790)
//{
//  x_1=HIGH;
//}

 if(x==HIGH &&previous==LOW && millis()-time >debounce)
  {
     lcd.clear();
     lcd.setCursor(0,0);
     count=count+1;
     lcd.print("TEMP:");
     lcd.setCursor(0,1);
     lcd.print(count);
     adc_key_in=1000;
     time = millis();
   }
else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce)
  {
     lcd.clear();
     lcd.setCursor(0,0);
     count=count-1;
     lcd.print("TEMP:");
     lcd.setCursor(0,1);
     lcd.print(count);
     adc_key_in=1000;
     time = millis();
   }
/* if(adc_key_in<195){
  previous=HIGH;
}
else
{
  previous=LOW;
}*/
if(adc_key_in<110 && adc_key_in >90){
      previous=HIGH;
       }
else if(adc_key_in<260 && adc_key_in >240)
{ previous_1=HIGH; }
     else
      {
        previous_1=LOW;
       previous=LOW;
       }


}
