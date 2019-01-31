/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


int ledE = 4;
int som;
int pos = 0;    // variable to store the servo position
int pos2 = 0;
void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(ledE, OUTPUT);
  pinMode(0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  som = analogRead(0);
  Serial.println(som);

  if (som >= 300)
  {
      digitalWrite(ledD, HIGH);
      digitalWrite(ledE, HIGH);
      for (pos2 = 0; pos2 <= 3; pos2 += 1){
        for (pos = 0; pos <= 45; pos += 1)
        { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
           myservo.write(pos);              // tell servo to go to position in variable 'pos'
           delay(15);                       // waits 15ms for the servo to reach the position
        }
        for (pos = 45; pos >= 0; pos -= 1)
        { // goes from 180 degrees to 0 degrees
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
      }
  }
  else
  {
    digitalWrite(ledE, LOW);
    myservo.write(0);
  }
}
