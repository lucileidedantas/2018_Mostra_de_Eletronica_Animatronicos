#include <EEPROM2.h>
#include <pinagem.h>
#include <robo_hardware2.h>
#include <Ultrasonic.h>
#include <Servo.h>

Servo myservo1;  

float valor_sonar;
int pos = 0;    

void setup() {
  
  Serial.begin(9600);
  robo.configurar(false);
  myservo1.attach(9);  
}

void loop() {
     
     valor_sonar = robo.lerSensorSonarFrontal();
     Serial.print("Valor do sensor frontal: ");
     Serial.println(valor_sonar);
     
     if(valor_sonar < 10 ){
        robo.acionarMotores(0, 0);
          for (pos = 30; pos <= 130; pos += 1) { 
               myservo1.write(pos);   
               delay(2);                      
          }
          delay(10);
     }
     else{
        robo.acionarMotores(40,40);
     }
     delay(1000);
}
