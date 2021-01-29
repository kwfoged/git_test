#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>

RF24 radio(8,10);

unsigned long task_time;

byte ackData[8];
//const byte AddressPipe0 = "0Node";
const byte wAddress[] =  "1Node" "2Node" "3Node" "4Node" "5Node";
const short RADIO_ADDR_LEN = 5;


struct telegram {
  byte nodeID;
  byte unitNo;
  byte msgNo;
  unsigned short temp1;
  unsigned short temp2;
  
} ;
telegram my_telegram; 


void loadAckData(byte pipeNum) {
  ackData[0] = my_telegram.msgNo;
  ackData[1] = map( analogRead(A0), 0, 1024, 0, 255);
  radio.writeAckPayload(pipeNum, &ackData, sizeof(ackData));
}


void setup_radio()
{
  
  radio.begin();
  radio.setDataRate( RF24_2MBPS ); // RF24_250KBPS, RF24_2MBPS
  radio.setAutoAck(true);
  radio.enableAckPayload();
  radio.enableDynamicPayloads();
  //radio.openReadingPipe(0, AddressPipe0);
  for (byte i = 0; i < 5; i++) {
    radio.openReadingPipe(i + 1, &wAddress[i * 5]);
  }
  radio.startListening();
  delay(1000);
}


