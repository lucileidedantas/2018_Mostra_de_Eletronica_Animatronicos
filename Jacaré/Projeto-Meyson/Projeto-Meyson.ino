#include <Servo.h>

Servo myservo;
int objeto = 0;
int pos = 9;  
   
void setup()  
{  
  pinMode(0, INPUT); 
  pinMode(9, OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);  
}  
   
void loop()  
{
    
  objeto = analogRead(0);  
  if (objeto < 840
  
  
  ){  
    Serial.println("Objeto : Detectado");
    Serial.println(objeto);  
    for (pos = 0; pos <= 90; pos += 1) { 
    myservo.write(pos);              
    delay(60);                       
  } 
  }else  
  {  
    Serial.println("Objeto : Ausente !");
    Serial.println(objeto); 
    delay(200);
     }
  }
