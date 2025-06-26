#include<Servo.h>
int rainSensor = A0;
Servo s1;
Servo s2;
int pos=0;
#define DEG 180
void setup() 
{
  Serial.begin(9600);
  s1.attach(9);
  s1.write(0);
  s2.attach(10);
  s2.write(0); 
}

void loop() 
{
  int sensorData =  analogRead(rainSensor);
  Serial.print("ServoData : ");
  Serial.println(sensorData);



if(sensorData >=950){
  s1.write(0);
  s2.write(0);
  Serial.print("no rain");
} else if(sensorData >=650 && sensorData <950){
  servoCtrl(DEG,15);
  
  Serial.print("Medium rain");
  } 
else if(sensorData<650){
 servoCtrl(DEG,5);
 Serial.print("more rain");
}

}

void servoCtrl(int degree, int spd){
for(pos=0;pos<=180;pos++){
  s1.write(pos);
  s2.write(pos);
  delay(spd);
}
for(pos=180;pos>=0;pos--){
  s1.write(pos);
  s2.write(pos);
  delay(spd);
}
}
