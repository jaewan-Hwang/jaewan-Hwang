#include <SoftwareSerial.h>
SoftwareSerial Bt(10, 11);
int green = 8;
int red = 9;
void setup(){
    Serial.begin(9600);
    Bt.begin(9600);
    pinMode(green,OUTPUT);
    pinMode(red,OUTPUT);
}
void loop(){
    Serial.println(analogRead(A0));
    delay(500);
  if(analogRead(A0)>500){
      tone(4, 523, 500); 
      delay(500);
      tone(4, 587, 500);
      delay(500);
      tone(4, 659, 500); 
      delay(500);
     digitalWrite(red,HIGH);
     Bt.print("wake up");
     delay(1000);
  } 
  if(Bt.available()){
    String m =Bt.readString();
    if(m.indexOf("stop")==0){ 
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    exit(0);
    }
  }
}
