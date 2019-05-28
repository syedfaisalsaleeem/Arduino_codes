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
int previous = LOW;
unsigned long time = 0;           // the last time the output pin was toggled
unsigned long debounce = 200UL;
int count=0;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2); // start the library
lcd.setCursor(0,0);
lcd.print("Push the buttons"); // print a simple message
}

void loop() {
  // put your main code here, to run repeatedly:
adc_key_in = analogRead(0);
if (adc_key_in<195)
{
    if(adc_key_in<195){
      x=HIGH;
       }
     else
      {
       x=LOW;
       }
}
//else if (adc_key_in <790)
//{
//  x_1=HIGH;
//}

 if(x==HIGH &&previous==LOW && millis()-time >debounce)
  { 
    
     lcd.setCursor(0,1);
     count=count+1;
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
adc_key_in = analogRead(0);
if (adc_key_in<195)
{
    if(adc_key_in<195){
      previous=HIGH;
       }
     else
      {
       previous=LOW;
       }

}
}
