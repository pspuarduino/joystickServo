#include <Servo.h>

Servo myservo;

const int SW_pin = 4; // присвоим переменной SW_pin значение 4 типа int
const int X_pin = A7; // X_pin присвоим аналоговому пину 7
const int Y_pin = A6; // Y_pin присвоим аналоговому пину 7
 
void setup()
{
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  myservo.attach(9); 
}

float getAngle(int y,int x){
  float x1 = (512 - x);
  float y1 = (512 - y);
  float g = sqrt(x1*x1 + y1*y1);
  float result = acos(x1/g)*57.2958;
  if(y1 < 0){
//    result = 360 - result;
    result = -result;
  }
  return result;
}
 
void servoslow( Servo num, int pos, int time, int start)  // robotday.ru *** Функция для управления скоростью сервопривода ***
{ 
  num.write(start);
    
  for ( int i=start; i<pos; i++) 
      {  num.write(i);
         delay(time);
      }
}
 
void loop() 
{ 
     
  int clicked = digitalRead(SW_pin);
  int xVal = analogRead(X_pin);
  int yVal = analogRead(Y_pin);
  float dir = abs(getAngle(xVal, yVal));
  Serial.println(dir);
  delay(500);
  
  myservo.write(dir);
 
} 
