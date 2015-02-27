// off-topic: http://www.5v.ru/ch340g.htm

//#define DEBUG
#ifdef DEBUG
  #define DEBUG_PRINT(x)     Serial.print (x)
  #define DEBUG_PRINTDEC(x)     Serial.print (x, DEC)
  #define DEBUG_PRINTLN(x)  Serial.println (x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTDEC(x)
  #define DEBUG_PRINTLN(x) 
#endif 


// HM-MOD-Re-8 HomeMatic 8-Kanal-Empfangsmodul 
// http://www.elv.de/homematic-8-kanal-empfangsmodul.html
const int OUT1pin = 2; //first OUT pin, others following 
const int channelCount = 8;
int channelStates[channelCount] = {-1, -1, -1, -1, -1, -1, -1, -1}; // invalid value (neither HIGH nor LOW), will force full update on startup


// operate remote radio controlled devices with 433MHz AM transmitter
// http://code.google.com/p/rc-switch
#include <RCSwitch.h>
RCSwitch rfModule = RCSwitch();
const int rfModulePin = 13;
char group[6] = "01110";
char sockets[8][6]={
  "10000",
  "01000",
  "00100",
  "00010",
  "11000",
  "01100",
  "00110",
  "10010",
};

//temporary variable
int newState;


void setup() {
  #ifdef DEBUG
  Serial.begin(9600);
  #endif
  
  for (int pin=OUT1pin; pin < OUT1pin + channelCount; pin++){
    pinMode(pin, INPUT_PULLUP);
  }
  
  rfModule.enableTransmit(rfModulePin);
}


void loop() {
  for (int i=0; i < channelCount; i++){
    newState = !digitalRead(OUT1pin + i);
    if (newState != channelStates[i]) {
      channelStates[i] = newState;
      
      DEBUG_PRINT("Homematic Channel "); DEBUG_PRINT(i + 1);
      DEBUG_PRINT(" new State "); DEBUG_PRINT(newState);
      DEBUG_PRINT(" -> "); DEBUG_PRINT(sockets[i]);
      
      if (newState == HIGH) {
        rfModule.switchOn(group, sockets[i]);
        DEBUG_PRINT(" switchOn");
      } else {
        rfModule.switchOff(group, sockets[i]);
        DEBUG_PRINT(" switchOff");
      }
      DEBUG_PRINT("\n");
    }
  }
}





