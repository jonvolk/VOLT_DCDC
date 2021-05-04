#include <Arduino.h>
#include <FlexCAN.h> //https://github.com/teachop/FlexCAN_Library 


unsigned char mes[8] = {0, 0, 0, 0, 0, 0, 0, 0};
char msgString[128];                        // Array to store serial string

const int led = 13;


CAN_message_t msg;
CAN_message_t inMsg;
CAN_filter_t filter;

void setup() {

  pinMode(led, OUTPUT);
  Can0.begin(500000);

  CAN_filter_t allPassFilter;
  allPassFilter.ext = 1;
  for (uint8_t filterNum = 8; filterNum < 16;filterNum++) { //only use half the available filters for the extended IDs
      Can0.setFilter(allPassFilter, filterNum);
  }

  digitalWrite(led, HIGH);

  
}

void loop() {
  
  while (Can0.available())
  {

  dcdc();
 
  }
}





void dcdc() {
   
    
        msg.id = 0x1D4;
        msg.len = 2;
        msg.buf[0] = 0xA0;
        msg.buf[1] = 0xBA; //0xBA 14.7v   0xAB 13.5v

        Can0.write(msg);
  
}






