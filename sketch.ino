#include <IRremote.h>

const byte recv_pin=6;
const byte r_pin=11;
const byte g_pin=10;
const byte b_pin=9;

IRrecv receiver(recv_pin);

void setup() {

  Serial.begin(9600);

  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);

  receiver.enableIRIn();

  receiver.blink13(true);

}

void loop() {

  if(receiver.decode()){
    int response=receiver.decodedIRData.command;
    action(response);
    Serial.println(response);
    receiver.resume();
  }
  
}

void action(int num){

  if(num== 48) 
    lit_led(255,0,0);
  else if(num == 24)
    lit_led(0,255,0);
  else if(num == 122)
    lit_led(0,0,255);
  else if(num == 16)
    lit_led(255,255,0);
  else if(num == 56)
    lit_led(0,255,255);
  else if(num == 90)
    lit_led(255,0,255);
  else
    lit_led(255,255,255);
  
}

void lit_led(int r,int g, int b){

    analogWrite(r_pin,r);
    analogWrite(g_pin,g);
    analogWrite(b_pin,b);

}

