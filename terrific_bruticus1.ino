
#include <Servo.h>
Servo servo1;
int trigPin = 6;
int echoPin = 5;
int red = 4;
int pinpot=1;
int blue = 3;
int val;
int green = 2;
long distance;
long duration;
void setup() 
{
servo1.attach(9); 
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
}
 
void loop() {
  ultra();
  servo1.write(0);
  val=analogRead(pinpot);
  val=map(val,0,1023,0,180);
  servo1.write(val);
  if(distance <=20){
    digitalWrite(red,HIGH);
    delay(1000);
    digitalWrite(red,LOW);
    delay(1000);
    servo1.write(60);}
  else{servo1.write(0);
      }


if(distance <=15){
    digitalWrite(blue,HIGH);
    delay(1000);
    digitalWrite(blue,LOW);
    delay(1000);
    servo1.write(120);
}
  else{servo1.write(0);}
  
  
if(distance <=10){
    digitalWrite(green,HIGH);
    delay(1000);
    digitalWrite(green,LOW);
    delay(1000);
    servo1.write(180);}
else{servo1.write(0);} 
  }

void ultra(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
}
