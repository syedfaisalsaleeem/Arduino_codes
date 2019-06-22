import serial
import RPi.GPIO as IO            # calling header file for GPIO’s of PI
import time
from pandas import DataFrame

previous_error=0
integral=0
setpoint=100
KP=4
KI=0.7
KD=2 #0.2
previous_error_off=0
integral_off=0
k_1=0
KP_off=20
KI_off=0 #0.1
KD_off=2
Dt=40
ser = serial.Serial('/dev/ttyACM0',9600)
IO.setmode (IO.BOARD)       # programming the GPIO by BOARD pin numbers, GPIO21 is called as PIN40

list_temperature=[0]
list_time=[None]
l_1=[]
i=0
m_1=0
n=0
#s = [0,1]
def call_temp(temp):
    return temp
while True:
        read_serial=ser.readline()
        t=time.localtime()
        current_time=time.strftime("%H%M%S",t)

        x=l_1.append(str(read_serial))
        
        x=l_1[i][2:7]
        i=i+1
        print(x)
        temp=float(x)

        if temp!=None and temp <200:
            #if(temp>list_temperature[-1]):
              #KI=0

            list_time.append(current_time)
            list_temperature.append(temp)
            Value={'Time':list_time , 'Temperature':list_temperature}
            df=DataFrame(Value,columns=['Time','Temperature'])
            export_csv=df.to_csv(r'pid_100.csv',index=None,header=True)
            presentvalue=temp
            #print(presentvalue)
            error=setpoint-presentvalue
            integral=integral+error
            derivative=(error-previous_error)
            output=(KP*error)+(KI*integral)+(KD*derivative)
            previous_error=error
            output=int(output)
            if(output>60 or output==60):
                output=60
                integral=0
            
                
            print(output, derivative,integral,KI,"output","derivative","integral")
            #print(error,"error")
            error_off=setpoint-presentvalue
            integral_off=integral_off+error_off
            derivative_off=(error_off-previous_error_off)
            output_off=(KP_off*error_off)+(KI_off*integral_off)+(KD_off*derivative_off)
            previous_error_off=error_off
            output_off=int(output_off)
            print(output_off, derivative_off,integral_off,"output off","derivative_off","integral_off")
            if(output_off>60 or output_off==60 or output_off<0):
                output_off=59
                integral_off=0
                        
            if (temp<70):
               print('Heating')
               
               t=time.localtime()
               current_time=time.strftime("%H%M%S",t)
               read_serial_1=ser.readline()
               y=l_1.append(str(read_serial_1))
               y=l_1[i][2:7]
               i=i+1
               print(y)
               #print(new_1)
               m=float(y)
               list_time.append(current_time)
               list_temperature.append(m)
               IO.setmode (IO.BOARD)
               IO.setup(7,IO.OUT)
               IO.output(7,1)
            else:
                
                for new_1 in range(0,output):
                   print('Heating')
                   t=time.localtime()
                   current_time=time.strftime("%H%M%S",t)
                   read_serial_1=ser.readline()
                   y=l_1.append(str(read_serial_1))
                   y=l_1[i][2:7]
                   i=i+1
                   print(y)
                   print(new_1)
                   m=float(y)
                   list_time.append(current_time)
                   list_temperature.append(m)

                   IO.setmode (IO.BOARD)
                   IO.setup(7,IO.OUT)
                   IO.output(7,1)
                   
                   if (m>setpoint):
                      print(setpoint,'break')
                      integral=0
                      integral_off=0
                      break 

   
                for t_1 in range(60,output_off,-1): 
                        read_serial_1=ser.readline()
                        t=time.localtime()
                        current_time=time.strftime("%H%M%S",t)
                        y=l_1.append(str(read_serial_1))
                        y=l_1[i][2:7]
                        i=i+1
                        print(y)
                        print(t_1)
                        m=float(y)
                        list_time.append(current_time)
                        list_temperature.append(m)
                        IO.setmode (IO.BOARD)
                        IO.setup(7,IO.OUT)
                        IO.output(7,0)
                        if (m>setpoint):
                          print(setpoint,'break')
                          integral=0
                          integral_off=0
                          break 
                #IO.cleanup()
            #IO.setup(7,IO.OUT)
            #IO.output(7,1)
            
            #time.sleep(error)
            #IO.output(7,0)
            #time.sleep(60-error)
            #print(error)
    
        #while (m_1<1):
        #IO.setup(7,IO.OUT)            # initialize digital pin40 as an output.
        #IO.output(7,0)
        #time.sleep(1)
        #IO.output(7,0)
        m_1=m_1+1
            
           # time.sleep(60)# turn the LED on (making the voltage level HIGH)
##
        #if(temp>100  and temp <110):
            #break
##    
IO.cleanup() 
        
        
