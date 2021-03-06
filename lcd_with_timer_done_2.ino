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
int HH_1,mm_1,ss_1=0;
int exit_1=0;
int p_1,p_2,p_3,p_4=0;
int exit_2=0;
int x,l;
int s,t;
int x_1;
int x_2;
int previous = LOW;
int previous_1=LOW;
int previous_2=LOW;
unsigned long time = 0;           // the last time the output pin was toggled
unsigned long debounce = 200L;
int count_1,count_2,count_3,count_4,count_5=0;
float count;
int new_1=0;
int m_1;

int mode(int,int,float,int,int,int,int,int,int,int,int,int, int, int, int);
int setting(int,int,int,int,int);
//int array_1[3]={0,1,2};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
lcd.begin(16, 2); // start the library
lcd.setCursor(0,0);
lcd.print('Temp:');
lcd.setCursor(0,1);
lcd.print(current_date);

}

void loop() {
  // put your main code here, to run repeatedly:
adc_key_in = analogRead(0);
Serial.println(adc_key_in);
//while(1)
//{
//adc_key_in = analogRead(0);
//}



if(adc_key_in<110 && adc_key_in>90)
{
      x=HIGH;
       }
else if(adc_key_in<260 && adc_key_in >240)
{
  x_1=HIGH; 
}

else if(adc_key_in>630 && adc_key_in <650)
{
  x_2=HIGH;
}

else
{
       x_1=LOW;
       x=LOW;
       x_2=LOW;
}

//else if (adc_key_in <790)
//{
//  x_1=HIGH;
//}

if(x==HIGH && millis()-time >debounce && l==1&&x_1==LOW&&x_2==LOW)
  {  if(x==HIGH && previous==LOW && l==1&&x_1==LOW&&x_2==LOW)
       {  delay(100);
          lcd.clear();
          lcd.setCursor(0,0);
          if (count>=100)
     {count=100;
     lcd.setCursor(0,0);
     lcd.print("Temperature");
     lcd.setCursor(0,1);
     lcd.print(count,1);
     }
     else{
     count=count+0.1;
     s=1;
     lcd.setCursor(0,0);
     lcd.print("Temperature");
     lcd.setCursor(0,1);
     lcd.print(count,1);
         }
     adc_key_in=1000;
     time = millis();
         }
     lcd.clear();
     lcd.setCursor(0,0);
     if (count>=100)
     {count=100;
     lcd.setCursor(0,0);
     lcd.print("Temperature");
     lcd.setCursor(0,1);
     lcd.print(count,1);
     }
     else{
     
     if (s==1)
        {count=count;
          lcd.setCursor(0,0);
        lcd.print("Temperature");
     
        lcd.setCursor(0,1);
        lcd.print(count,1);
        s=0;
        }
      
      else
        {count=count+1;
          lcd.setCursor(0,0);
        lcd.print("Temperature");
     
        lcd.setCursor(0,1);
        lcd.print(count,1);
        s=0;}
     }
     adc_key_in=1000;
     time = millis();
   }
else if(x_1==HIGH && millis()-time >debounce &&l==1&&x==LOW&&x_2==LOW)
  {  
if(x_1==HIGH && previous_1==LOW  && millis()-time >debounce && l==1&&x==LOW&&x_2==LOW)
       {  delay(100);
     lcd.clear();
     lcd.setCursor(0,0);
     if (count<=0)
     {count=0;
     lcd.setCursor(0,0);
     lcd.print("Temperature");
     lcd.setCursor(0,1);
     lcd.print(count,1);
     }
     else{
     count=count-0.1;
     t=1;
     lcd.setCursor(0,0);
     lcd.print("Temperature");
     lcd.setCursor(0,1);
     lcd.print(count,1);
         }
     adc_key_in=1000;
     time = millis();
         }
     lcd.clear();
     lcd.setCursor(0,0);
     if (count<=0)
     {count=0;
     lcd.setCursor(0,0);
     lcd.print("Temperature");
     lcd.setCursor(0,1);
     lcd.print(count,1);
     }
     else{
     
     if (t==1)
        {count=count;
          lcd.setCursor(0,0);
        lcd.print("Temperature");
     
        lcd.setCursor(0,1);
        lcd.print(count,1);
        t=0;
        }
      else
        { count=count-1;
          lcd.setCursor(0,0);
          lcd.print("Temperature");
     
          lcd.setCursor(0,1);
          lcd.print(count,1);}
     }
     adc_key_in=1000;
     time = millis();

   }

/*
else if(x_1==HIGH && millis()-time >debounce &&l==1&&x==LOW&&x_2==LOW)
  {  delay(100);
     lcd.clear();
     lcd.setCursor(0,0);
     if (count<=0.0)
     {count=0;
     lcd.setCursor(0,0);
     lcd.print("Temperature");
     lcd.setCursor(0,1);
     lcd.print(count,1);
     }
     else{
     count=count-0.10;
     lcd.setCursor(0,0);
     lcd.print("Temperature");
     lcd.setCursor(0,1);
     lcd.print(count,1);
     }
     
     adc_key_in=1000;
     time = millis();
   }
   */
else if(x==HIGH &&previous==LOW && millis()-time >debounce && l==2&&x_1==LOW&&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     if (count_1>=100)
     {count_1=100;
     lcd.setCursor(0,0);
     lcd.print("Fan Control");
     lcd.setCursor(0,1);
     lcd.print(count_1);
     }
     else{
     count_1=count_1+25;
     lcd.setCursor(0,0);
     lcd.print("Fan Control");
     lcd.setCursor(0,1);
     lcd.print(count_1);
     }
     
     
     adc_key_in=1000;
     time = millis();
   }
else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&l==2&&x==LOW&&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
      if (count_1<=0)
     {count_1=0;
     lcd.setCursor(0,0);
     lcd.print("Fan Control");
     lcd.setCursor(0,1);
     lcd.print(count_1);
     }
     else{
     count_1=count_1-25;
     lcd.setCursor(0,0);
     lcd.print("Fan Control");
     lcd.setCursor(0,1);
     lcd.print(count_1);
     }
     adc_key_in=1000;
     time = millis();
   }
else if(x==HIGH &&previous==LOW && millis()-time >debounce && l==3&&x_1==LOW&&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     if (count_2>=100)
     {count_2=100;
     lcd.setCursor(0,0);
     lcd.print("Ramp");
     lcd.setCursor(0,1);
     lcd.print(count_2);
     }
     else{
     count_2=count_2+25;
     lcd.setCursor(0,0);
     lcd.print("Ramp");
     lcd.setCursor(0,1);
     lcd.print(count_2);
     }
     adc_key_in=1000;
     time = millis();
   }
else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&l==3&&x==LOW &&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     if (count_2<=0)
     {count_2=0;
     lcd.setCursor(0,0);
     lcd.print("Ramp");
     lcd.setCursor(0,1);
     lcd.print(count_2);
     }
     else{
     count_2=count_2-25;
     lcd.setCursor(0,0);
     lcd.print("Ramp");
     lcd.setCursor(0,1);
     lcd.print(count_2);
     }
     adc_key_in=1000;
     time = millis();
   }
/*else if(x==HIGH &&previous==LOW && millis()-time >debounce && l==4&&x_1==LOW&&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     count_3=count_3+1;
     lcd.print("Timer");
     lcd.setCursor(0,1);
     lcd.print(count_3);
     adc_key_in=1000;
     time = millis();
   }
else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&l==4&&x==LOW&&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     count_3=count_3-1;
     lcd.print("Timer");
     lcd.setCursor(0,1);
     lcd.print(count_3);
     adc_key_in=1000;
     time = millis();
   }*/
else if((x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&x==LOW&&x_2==LOW &&l==4)||(x==HIGH &&previous==LOW && millis()-time >debounce && l==4&&x_1==LOW&&x_2==LOW))
{
  if((x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&x==LOW&&x_2==LOW)||(x==HIGH &&previous==LOW && millis()-time >debounce &&x_1==LOW&&x_2==LOW))
   {//int HH_1,mm_1,ss_1=0;
    //int exit_1=0;
    while (1)
    
       {  adc_key_in = analogRead(0);
          Serial.println(adc_key_in);
          if(adc_key_in<110 && adc_key_in>90)
           {
            x=HIGH;
           }
          else if(adc_key_in<260 && adc_key_in >240)
           {
           x_1=HIGH; 
           }

          else if(adc_key_in>630 && adc_key_in <650)
          {
          x_2=HIGH;
          }
          else
         {
          x_1=LOW;
          x=LOW;
          x_2=LOW;
         }
       
        
        if(x==HIGH &&previous==LOW && millis()-time >debounce &&x_1==LOW &&x_2==LOW && exit_1==0)  
                         {lcd.clear();
                         lcd.setCursor(0,0);
                         //HH_1=HH_1+1;
                         lcd.print("Timer");
                         //lcd.setCursor(0,1);
                         //lcd.print(HH_1);
                         //lcd.setCursor(1,1);
                         //lcd.print("HH");
                         lcd.setCursor(4,1);
                         lcd.print(mm_1);
                         lcd.setCursor(6,1);
                         lcd.print("MM");
                         lcd.setCursor(8,1);
                         lcd.print(ss_1);
                         lcd.setCursor(10,1);
                         lcd.print("SS");
                         adc_key_in=1000;
                         time = millis();
                         if(HH_1>=60)
                           {
                            HH_1=60;
                            lcd.setCursor(0,1);
                            lcd.print(HH_1);
                            lcd.setCursor(2,1);
                            lcd.print("HH");

                            }
                         else
                            {
                            HH_1=HH_1+1;
                            lcd.setCursor(0,1);
                            lcd.print(HH_1);
                            lcd.setCursor(2,1);
                            lcd.print("HH");
                              
                            }
                         
                         
                         
                         
                         
                         }
           else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce&&x==LOW&&x_2==LOW && exit_1==0)
                      {
                         lcd.clear();
                         lcd.setCursor(0,0);
                         //HH_1=HH_1-1;
                          lcd.print("Timer");
                         //lcd.setCursor(0,1);
                         //lcd.print(HH_1);
                         //lcd.setCursor(1,1);
                         //lcd.print("HH");
                         lcd.setCursor(4,1);
                         lcd.print(mm_1);
                         lcd.setCursor(6,1);
                         lcd.print("MM");
                         lcd.setCursor(8,1);
                         lcd.print(ss_1);
                         lcd.setCursor(10,1);
                         lcd.print("SS");
                         adc_key_in=1000;
                         time = millis();
                         if(HH_1<=0)
                           {
                            HH_1=0;
                            lcd.setCursor(0,1);
                            lcd.print(HH_1);
                            lcd.setCursor(2,1);
                            lcd.print("HH");
                            }
                         else
                            {
                            HH_1=HH_1-1;
                            lcd.setCursor(0,1);
                            lcd.print(HH_1);
                            lcd.setCursor(2,1);
                            lcd.print("HH");
                              
                            }


                        
                      }
          else if(x==HIGH &&previous==LOW && millis()-time >debounce&&x_1==LOW&&x_2==LOW && exit_1==1)  
                         {lcd.clear();
                         lcd.setCursor(0,0);
                         //mm_1=mm_1+1;
                         lcd.print("Timer");
                         lcd.setCursor(0,1);
                         lcd.print(HH_1);
                         lcd.setCursor(2,1);
                         lcd.print("HH");
                         //lcd.setCursor(3,1);
                         //lcd.print(mm_1);
                         //lcd.setCursor(4,1);
                         //lcd.print("MM");
                         lcd.setCursor(8,1);
                         lcd.print(ss_1);
                         lcd.setCursor(10,1);
                         lcd.print("SS");
                         adc_key_in=1000;
                         time = millis();
                         if(mm_1>=60)
                           {
                            mm_1=60;
                            
                            lcd.setCursor(4,1);
                            //lcd.rightToLeft();
                            lcd.print(mm_1);
                            lcd.setCursor(6,1);
                            lcd.print("MM");
                            }
                         else
                            {
                            mm_1=mm_1+1;
                            lcd.setCursor(4,1);
                            //lcd.rightToLeft();
                            lcd.print(mm_1);
                            lcd.setCursor(6,1);
                            lcd.print("MM");
                              
                            }
                         
                         
                         
                         
                         }
          else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce&&x==LOW&&x_2==LOW && exit_1==1)
                      {
                         lcd.clear();
                         lcd.setCursor(0,0);
                         //mm_1=mm_1-1;
                         lcd.print("Timer");
                         lcd.setCursor(0,1);
                         lcd.print(HH_1);
                         lcd.setCursor(2,1);
                         lcd.print("HH");
                         //lcd.setCursor(3,1);
                         //lcd.print(mm_1);
                         //lcd.setCursor(4,1);
                         //lcd.print("MM");
                         lcd.setCursor(8,1);
                         lcd.print(ss_1);
                         lcd.setCursor(10,1);
                         lcd.print("SS");
                         adc_key_in=1000;
                         time = millis();
                         if(mm_1<=0)
                           {
                            mm_1=0;
                            
                            lcd.setCursor(4,1);
                            //lcd.rightToLeft();
                            lcd.print(mm_1);
                            lcd.setCursor(6,1);
                            lcd.print("MM");
                            }
                         else
                            {
                            mm_1=mm_1-1;
                            lcd.setCursor(4,1);
                            //lcd.rightToLeft();
                            lcd.print(mm_1);
                            lcd.setCursor(6,1);
                            lcd.print("MM");
                              
                            }
                        
                      }
          else if(x==HIGH &&previous==LOW && millis()-time >debounce&&x_1==LOW&&x_2==LOW && exit_1==2)  
                         {lcd.clear();
                         lcd.setCursor(0,0);
                         //ss_1=ss_1+1;
                         lcd.print("Timer");
                         lcd.setCursor(0,1);
                         lcd.print(HH_1);
                         lcd.setCursor(2,1);
                         lcd.print("HH");
                         lcd.setCursor(4,1);
                         lcd.print(mm_1);
                         lcd.setCursor(6,1);
                         lcd.print("MM");
                         //lcd.setCursor(6,1);
                         //lcd.print(ss_1);
                         //lcd.setCursor(7,1);
                         //lcd.print("SS");
                         adc_key_in=1000;
                         time = millis();
                         if(ss_1>=60)
                           {
                            ss_1=60;
                            
                            lcd.setCursor(8,1);
                            //lcd.rightToLeft();
                            lcd.print(ss_1);
                            lcd.setCursor(10,1);
                            lcd.print("SS");
                            }
                         else
                            {
                            ss_1=ss_1+1;
                            lcd.setCursor(8,1);
                            //lcd.rightToLeft();
                            lcd.print(ss_1);
                            lcd.setCursor(10,1);
                            lcd.print("SS");
                              
                            }
                         
                         
                         
                         
                         }
          else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce&&x==LOW&&x_2==LOW && exit_1==2)
                      {
                         lcd.clear();
                         lcd.setCursor(0,0);
                         
                         lcd.print("Timer");
                         lcd.setCursor(0,1);
                         lcd.print(HH_1);
                         lcd.setCursor(2,1);
                         lcd.print("HH");
                         lcd.setCursor(4,1);
                         lcd.print(mm_1);
                         lcd.setCursor(6,1);
                         lcd.print("MM");
                        // lcd.setCursor(6,1);
                        // lcd.print(ss_1);
                        // lcd.setCursor(7,1);
                        // lcd.print("SS");
                         if(ss_1<=0)
                           {
                            ss_1=0;
                            lcd.setCursor(8,1);
                            //lcd.rightToLeft();
                            lcd.print(ss_1);
                            lcd.setCursor(10,1);
                            lcd.print("SS");
                            }
                         else
                            {
                            ss_1=ss_1-1;
                            lcd.setCursor(8,1);
                            //lcd.rightToLeft();
                            lcd.print(ss_1);
                            lcd.setCursor(10,1);
                            lcd.print("SS");
                              
                            }

                         adc_key_in=1000;
                         time = millis();
                        
                      }
                       



          
          else if(x_2==HIGH &&previous_2==LOW && millis()-time >debounce&&x_1==LOW&&x==LOW)
             {
                exit_1=exit_1+1;
                if(exit_1==3)
                    { exit_1=0;
                      break;
                    }

              
             }
         if(adc_key_in<110 && adc_key_in>90)
            {
               previous=HIGH;
            }
         else if(adc_key_in<260 && adc_key_in >240)
           { previous_1=HIGH; }
         else if(adc_key_in>630 && adc_key_in <650)
           { previous_2=HIGH;}
         else
           {
           previous_1=LOW;
           previous=LOW;
           previous_2=LOW;
           }
      
       
       
       }
    
   }


}
else if(x==HIGH &&previous==LOW && millis()-time >debounce && l==5&&x_1==LOW&&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     //count_4=count_4+1;
     lcd.print("Delay Timer");
     lcd.setCursor(0,1);
     lcd.print("ON");
     adc_key_in=1000;
     time = millis();
   }
else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&l==5&&x==LOW&&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     //count_4=count_4-1;
     lcd.print("Delay Timer");
     lcd.setCursor(0,1);
     lcd.print("OFF");
     adc_key_in=1000;
     time = millis();
   }
/*else if(x==HIGH &&previous==LOW && millis()-time >debounce && l==6&&x_1==LOW&&x_2==LOW)
  {       lcd.clear();
     lcd.setCursor(0,0);
     count_5=count_5+1;
     lcd.print("Cal Password");
     lcd.setCursor(0,1);
     lcd.print(count_5);
     adc_key_in=1000;
     time = millis();
    
    
    
    if(x_2==HIGH &&previous_2==LOW && millis()-time >debounce&&x_1==LOW&&x==LOW)
     lcd.clear();
     lcd.setCursor(0,0);
     count_5=count_5+1;
     lcd.print("Cal Password");
     lcd.setCursor(0,1);
     lcd.print(count_5);
     adc_key_in=1000;
     time = millis();
   }*/
/*
else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&l==6&&x==LOW&&x_2==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     count_5=count_5-1;
     lcd.print("Cal Password");
     lcd.setCursor(0,1);
     lcd.print(count_5);
     adc_key_in=1000;
     time = millis();
   }
   */
else if((x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&x==LOW&&x_2==LOW &&l==6)||(x==HIGH &&previous==LOW && millis()-time >debounce && l==6&&x_1==LOW&&x_2==LOW))
{
  if((x_1==HIGH &&previous_1==LOW && millis()-time >debounce &&x==LOW&&x_2==LOW)||(x==HIGH &&previous==LOW && millis()-time >debounce &&x_1==LOW&&x_2==LOW))

  {

         while (1)
         {
          adc_key_in = analogRead(0);
          Serial.println(adc_key_in);
          if(adc_key_in<110 && adc_key_in>90)
           {
            x=HIGH;
           }
          else if(adc_key_in<260 && adc_key_in >240)
           {
           x_1=HIGH; 
           }

          else if(adc_key_in>630 && adc_key_in <650)
          {
          x_2=HIGH;
          }
          else
         {
          x_1=LOW;
          x=LOW;
          x_2=LOW;
         }//password working
          //int p_1,p_2,p_3,p_4,exit_2;
                 if(x==HIGH &&previous==LOW && millis()-time >debounce &&x_1==LOW &&x_2==LOW && exit_2==0)  
                         {
                          lcd.clear();
                          lcd.setCursor(0,0);
                         //HH_1=HH_1+1;
                          lcd.print("Service Password");
                          lcd.setCursor(1,1);
                          lcd.print(p_2);
                          lcd.setCursor(2,1);
                          lcd.print(p_3);
                          lcd.setCursor(3,1);
                          lcd.print(p_4);
                          adc_key_in=1000;
                          time = millis();
                          if(p_1>=9)
                            {
                            p_1=9;
                            lcd.setCursor(0,1);
                            lcd.print(p_1);
                            }
                          else
                            {
                            p_1=p_1+1;
                            lcd.setCursor(0,1);
                            lcd.print(p_1);    
                            } 
                         
                         }
                 else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce&&x==LOW&&x_2==LOW && exit_2==0)
                         {
                         lcd.clear();
                         lcd.setCursor(0,0);
                         lcd.print("Service Password");
                          lcd.setCursor(1,1);
                          lcd.print(p_2);
                          lcd.setCursor(2,1);
                          lcd.print(p_3);
                          lcd.setCursor(3,1);
                          lcd.print(p_4);
                         adc_key_in=1000;
                         time = millis();
                         if(p_1<=0)
                           {
                            p_1=0;
                            lcd.setCursor(0,1);
                            lcd.print(p_1);
                            }
                         else
                            {
                            p_1=p_1-1;
                            lcd.setCursor(0,1);
                            lcd.print(p_1);
                            }      
  
                        }
                 else if(x==HIGH &&previous==LOW && millis()-time >debounce&&x_1==LOW&&x_2==LOW && exit_2==1)
                         {
                         lcd.clear();
                         lcd.setCursor(0,0);
                         lcd.print("Service Password");
                          lcd.setCursor(0,1);
                          lcd.print(p_1);
                          lcd.setCursor(2,1);
                          lcd.print(p_3);
                          lcd.setCursor(3,1);
                          lcd.print(p_4);
                         adc_key_in=1000;
                         time = millis();
                         if(p_2>=9)
                           {
                            p_2=9;
                            lcd.setCursor(1,1);
                            lcd.print(p_2);
                            }
                         else
                            {
                            p_2=p_2+1;
                            lcd.setCursor(1,1);
                            lcd.print(p_2);
                            }      
  
                        }
                  else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce&&x==LOW&&x_2==LOW && exit_2==1)
                         {
                         lcd.clear();
                         lcd.setCursor(0,0);
                         lcd.print("Service Password");
                         adc_key_in=1000;
                          lcd.setCursor(0,1);
                          lcd.print(p_1);
                          lcd.setCursor(2,1);
                          lcd.print(p_3);
                          lcd.setCursor(3,1);
                          lcd.print(p_4);
                         time = millis();
                         if(p_2<=0)
                           {
                            p_2=0;
                            lcd.setCursor(1,1);
                            lcd.print(p_2);
                            }
                         else
                            {
                            p_2=p_2-1;
                            lcd.setCursor(1,1);
                            lcd.print(p_2);
                            }      
  
                        }
                  else if(x==HIGH &&previous==LOW && millis()-time >debounce &&x_1==LOW &&x_2==LOW && exit_2==2)  
                         {
                          lcd.clear();
                          lcd.setCursor(0,0);
                         //HH_1=HH_1+1;
                          lcd.print("Service Password");
                          lcd.setCursor(0,1);
                          lcd.print(p_1);
                          lcd.setCursor(1,1);
                          lcd.print(p_2);
                          lcd.setCursor(3,1);
                          lcd.print(p_4);
                          adc_key_in=1000;
                          time = millis();
                          if(p_3>=9)
                            {
                            p_3=9;
                            lcd.setCursor(2,1);
                            lcd.print(p_3);
                            }
                          else
                            {
                            p_3=p_3+1;
                            lcd.setCursor(2,1);
                            lcd.print(p_3);    
                            } 
                         
                         }
                 else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce&&x==LOW&&x_2==LOW && exit_2==2)
                         {
                         lcd.clear();
                         lcd.setCursor(0,0);
                         lcd.print("Service Password");
                         lcd.setCursor(0,1);
                         lcd.print(p_1);
                         lcd.setCursor(1,1);
                         lcd.print(p_2);
                         lcd.setCursor(3,1);
                         lcd.print(p_4);
                         adc_key_in=1000;
                         time = millis();
                         if(p_3<=0)
                           {
                            p_3=0;
                            lcd.setCursor(2,1);
                            lcd.print(p_3);
                            }
                         else
                            {
                            p_3=p_3-1;
                            lcd.setCursor(2,1);
                            lcd.print(p_3);
                            }
                         }
                 else if(x==HIGH &&previous==LOW && millis()-time >debounce &&x_1==LOW &&x_2==LOW && exit_2==3)  
                         {
                          lcd.clear();
                          lcd.setCursor(0,0);
                         //HH_1=HH_1+1;
                          lcd.print("Service Password");
                          lcd.setCursor(0,1);
                          lcd.print(p_1);
                          lcd.setCursor(1,1);
                          lcd.print(p_2);
                          lcd.setCursor(2,1);
                          lcd.print(p_3);
                          adc_key_in=1000;
                          time = millis();
                          if(p_4>=9)
                            {
                            p_4=9;
                            lcd.setCursor(3,1);
                            lcd.print(p_4);
                            }
                          else
                            {
                            p_4=p_4+1;
                            lcd.setCursor(3,1);
                            lcd.print(p_4);    
                            } 
                         
                         }
                 else if(x_1==HIGH &&previous_1==LOW && millis()-time >debounce&&x==LOW&&x_2==LOW && exit_2==3)
                         {
                         lcd.clear();
                         lcd.setCursor(0,0);
                         lcd.print("Service Password");
                         lcd.setCursor(0,1);
                         lcd.print(p_1);
                         lcd.setCursor(1,1);
                         lcd.print(p_2);
                         lcd.setCursor(2,1);
                         lcd.print(p_3);
                         adc_key_in=1000;
                         time = millis();
                         if(p_4<=0)
                           {
                            p_4=0;
                            lcd.setCursor(3,1);
                            lcd.print(p_4);
                            }
                         else
                            {
                            p_4=p_4-1;
                            lcd.setCursor(3,1);
                            lcd.print(p_4);
                            }      
  
                        }

             else if(x_2==HIGH &&previous_2==LOW && millis()-time >debounce&&x_1==LOW&&x==LOW)
               {
                exit_2=exit_2+1;
                if(exit_2==4)
                    { exit_2=0;
                      break;
                    }

              
               }
  
                        
                   
                  
                  











          if(adc_key_in<110 && adc_key_in>90)
            {
               previous=HIGH;
            }
         else if(adc_key_in<260 && adc_key_in >240)
           { previous_1=HIGH; }
         else if(adc_key_in>630 && adc_key_in <650)
           { previous_2=HIGH;}
         else
           {
           previous_1=LOW;
           previous=LOW;
           previous_2=LOW;
           }
      




          

          
         }



         
    
  }


}



  
else if(x_2==HIGH &&previous_2==LOW && millis()-time >debounce&&x_1==LOW&&x==LOW)
  { 
     lcd.clear();
     lcd.setCursor(0,0);
     new_1=new_1+1;
     adc_key_in=1000;
     time = millis();
     if(new_1==7)
        { new_1=1;}
     else
     { new_1=new_1;}
     l=mode(new_1,l,count,count_1,count_2,count_3,count_4,count_5,HH_1,mm_1,ss_1,p_1,p_2,p_3,p_4);
     /*if (array_1[0]== 0)
        { lcd.print("TEMP:"); }
     else if (array_1[1]==1)
        {lcd.print("FAN CONTROL:");}
     else if(array_2[2]==2)
        {lcd.print("mode control:");}
        */
     
   }
/* if(adc_key_in<195){
  previous=HIGH;
}
else
{
  previous=LOW;
}*/

if(adc_key_in<110 && adc_key_in>90)
{
      previous=HIGH;
       }
else if(adc_key_in<260 && adc_key_in >240)
{ previous_1=HIGH; }
else if(adc_key_in>630 && adc_key_in <650)
{ previous_2=HIGH;}
     else
      {
        previous_1=LOW;
       previous=LOW;
       previous_2=LOW;
       }


}
int mode(int m_1,int def,float count,int count_1,int count_2,int count_3,int count_4,int count_5,int HH_1,int mm_1,int ss_1,int p_1,int p_2,int p_3,int p_4)
{ 
  if(m_1==1)
  { //lcd.clear(0,0);
    def=1;
    lcd.setCursor(0,0);
    lcd.print("Temperature");
    lcd.setCursor(0,1);
    lcd.print(count,1);
    return def;
  
  }
   else if(m_1==2)
  { //lcd.clear(0,0);
    def=2;
    lcd.setCursor(0,0);
    lcd.print("Fan Control");
    lcd.setCursor(0,1);
    lcd.print(count_1);
    return def;
  
  }
      else if(m_1==3)
  { //lcd.clear(0,0);
    def=3;
    lcd.setCursor(0,0);
    lcd.print("Ramp");
    lcd.setCursor(0,1);
    lcd.print(count_2);
    return def;
  
  }
        else if(m_1==4)
  { //lcd.clear(0,0);
    def=4;
    lcd.setCursor(0,0);
                         lcd.print("Timer");
                         lcd.setCursor(0,1);
                         lcd.print(HH_1);
                         lcd.setCursor(0,1);
                         lcd.print("HH");
                         lcd.setCursor(4,1);
                         lcd.print(mm_1);
                         lcd.setCursor(6,1);
                         lcd.print("MM");
                         lcd.setCursor(8,1);
                         lcd.print(ss_1);
                         lcd.setCursor(10,1);
                         lcd.print("SS");
    return def;
  
  }
        else if(m_1==5)
  { //lcd.clear(0,0);
    def=5;
    lcd.setCursor(0,0);
    lcd.print("Delay Timer");
    lcd.setCursor(0,1);
    lcd.print("ON");
    return def;
  
  }
          else if(m_1==6)
  { //lcd.clear(0,0);
    def=6;
    lcd.setCursor(0,0);
    lcd.print("Service Password");
    lcd.setCursor(0,1);
    lcd.print(p_1);
    lcd.setCursor(1,1);
    lcd.print(p_2);
    lcd.setCursor(2,1);
    lcd.print(p_3);
    lcd.setCursor(3,1);
    lcd.print(p_4);
    return def;
  
  }
  }
