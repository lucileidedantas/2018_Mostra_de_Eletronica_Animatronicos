
#include <Servo.h>
Servo myservo;  

int pos = 0; 
   
void setup() {
myservo.attach(9); 
pinMode(8, OUTPUT);
pinMode(2, OUTPUT);
pinMode(5, OUTPUT);
pinMode(7, OUTPUT);

 Serial.begin(9600);
}

void loop() {
 Serial.print("valor do sensor de refletância   ----   ");
  Serial.println(analogRead(2));
 //delay(300);
 
  for (pos = 0; pos <= 95; pos += 1) { 
    myservo.write(pos);             
    delay(4);   
    int foto=analogRead(3);
  
  if (foto<=500 ){
  digitalWrite(8, HIGH);// acende LED
  digitalWrite(2, HIGH);   
   digitalWrite(5, HIGH);// acende LED
  digitalWrite(7, HIGH);   
      
 }
if (foto>=500){
 digitalWrite(8,LOW);  //apaga LED
 digitalWrite(2, LOW);  
 digitalWrite(5,LOW);  //apaga LED
 digitalWrite(7, LOW);  
}
  }

  for (pos = 95; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(4);  
    int foto=analogRead(3);
  
  if (foto<=500 ){
  digitalWrite(8, HIGH);// acende LED
  digitalWrite(2, HIGH);// acende LED   
  digitalWrite(5, HIGH);// acende LED
  digitalWrite(7, HIGH);// acende LED 
      
 }
if (foto>=500){
 digitalWrite(8,LOW);  //apaga LED
 digitalWrite(2, LOW); //apaga LED 
 digitalWrite(5,LOW);  //apaga LED
 digitalWrite(7, LOW); //apaga LED
}
 
  }
}
