
/*
// TCS230 color recognition sensor 
// Sensor connection pins to Arduino are shown in comments

Color Sensor      Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                8
 s1                9
 s2                12
 s3                11
 OUT               10
 OE                GND
*/
#include <Servo.h>
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   
Servo servo01;
Servo servo02;
// LED pins connected to Arduino
int redLed = 2;  
// Variables  
int red = 0;  
int green = 0;  
int blue = 0;  
    
void setup()   
{  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  pinMode(redLed, OUTPUT);    
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);
  servo01.attach(7); 
  servo02.attach(6); 
}  
    
void loop() 
{  
  color(); 
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);  
  //Serial.println();  

  if (red < blue && red < green && red < 36)
  {  
   Serial.println(" - (Red Color)");  
   digitalWrite(redLed, HIGH); // Turn RED LED ON  
   //Servo motor 01 e 02
    for(int pos = 0;pos <= 180;pos++){
      servo01.write(pos);
      if(pos < 30){
        servo02.write(pos);
      }
      delay(10);
    }
    
    for(int pos = 180;pos >= 0;pos--){
      servo01.write(pos);
      if(pos > 150){
        servo02.write(pos - 160);
      }
      delay(10);
    } 
  }  

  else if (blue < red && blue < green && blue < 40)   
  {  
   
  }  

  else if (green < red && green < blue)  
  {  
  
  }  
  else{
  Serial.println();  
  }
  delay(300);   
  digitalWrite(redLed, LOW);   
 }  
    
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
