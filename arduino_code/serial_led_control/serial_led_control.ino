String message;
String pinStr;
String valueStr;

int startIndex;
int endIndex;
int indComma;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    message = Serial.readString(); // Read the incoming message
    Serial.println("Received: " + message); // Print the received message to the serial monitor
    
    startIndex = 0;
    while (startIndex < message.length()) {
      indComma = message.indexOf(',', startIndex);  //finds location of ,
      pinStr = message.substring(startIndex, indComma);   //captures first data String
      endIndex = message.indexOf(':', indComma);
      if (endIndex == -1) {
        endIndex = message.length();
      }
      valueStr = message.substring(indComma+1, endIndex);
      Serial.println("pin: " + pinStr + "|  value: " + valueStr);
      if (valueStr.toInt()<255) {
        analogWrite(pinStr.toInt(), valueStr.toInt());
      } else {
        Serial.println("Bad value");
        break;
      }
      startIndex = endIndex + 1;
    }
  }
}
