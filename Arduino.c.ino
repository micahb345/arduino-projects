#include "IRLibAll.h"

int inPin = 2;        // the number of the input pin
int outPin = 8;       // the number of the output pin

IRrecvPCI myReceiver(2); //create receiver and pass pin number
IRdecode myDecoder;   //create decoder

void setup() {
  // put your setup code here, to run once:
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  delay(0); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
}
void loop() {
  if(myReceiver.getResults()) {
    myDecoder.decode(); //print direction based on the IR codes from the Toshiba Remote
    if(myDecoder.value==0x22DDA857){
      Serial.println(" up "); 
    }
    if(myDecoder.value==0x22DD28D7){
      Serial.println(" down ");
    }
    if(myDecoder.value==0x22DDC837){
      Serial.println(" right ");
    }
    if(myDecoder.value==0x22DD9867){
      Serial.println(" left "); 
    }
      myReceiver.enableIRIn();
      digitalWrite(outPin, HIGH); //LED ON
      delay(0); //how long the led light stays on
      digitalWrite(outPin, LOW); //LED OFF
  }
  if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    //myDecoder.dumpResults(true);  //Now print results. Use false for less detail
    myReceiver.enableIRIn();      //Restart receiver
  }
}



 
  

