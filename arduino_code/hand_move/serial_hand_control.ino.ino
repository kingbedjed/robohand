#include<Servo.h>
Servo Myservos[6];

String message;
String pinStr;
String valueStr;

int mesgSplitInd, nextMsgInd;
int availablePins[] = {3, 5, 6, 9, 10, 11};
int numPins = 6;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  for (int i=0; i<numPins; i++) {
    Myservos[i].attach(availablePins[i]);
  }

}

void loop() {
// servoNum0,value0;servoNum1,value1;...
  if (Serial.available()) { // Check if data is available to read
    message = Serial.readString(); // Read the incoming message
    while (message.length() > 0) {
      Serial.println("Received: " + message); // Print the received message to the serial monitor
      mesgSplitInd = message.indexOf(',');  // finds location of first ,
      nextMsgInd = message.indexOf(';');
      pinStr = message.substring(0, mesgSplitInd);   //captures first data String
      valueStr = message.substring(mesgSplitInd+1, nextMsgInd);
      
//      Serial.println("mesgSplitInd: " + String(mesgSplitInd) + 
//                     " | pin: " + pinStr + 
//                     " | value: " + valueStr +
//                     " | nextMsgInd: " + String(nextMsgInd));
      
      if (pinStr.toInt()<numPins && valueStr.toInt()<180) {
        Myservos[pinStr.toInt()].write(valueStr.toInt());
      } else {
        Serial.println("Bad pin or value");
      }
      if (nextMsgInd < 0) { // no terminating ;
        break;
      }
      message = message.substring(nextMsgInd+1);
    }
  }
}
