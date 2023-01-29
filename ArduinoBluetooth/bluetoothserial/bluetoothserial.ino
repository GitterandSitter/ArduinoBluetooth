// zoomkat 8-6-10 serial I/O string test
// type a string in serial monitor. then send or enter
// for IDE 0019 and later

#include <SoftwareSerial.h>


int ledPin = 13;
String readString;
const unsigned int MAX_MESSAGE_LENGTH = 12;

SoftwareSerial softser(10, 11); // RX | TX



void setup() {
  Serial.begin(9600);
  softser.begin(9600);
  pinMode(ledPin, OUTPUT); 
  Serial.println("serial on/off"); // so I can keep track
  softser.println("Handshake from arduino");
}

void loop() {

// Feed any data from bluetooth to Terminal.
  if (softser.available())
    Serial.write(softser.read());
 
  // Feed all data from termial to bluetooth
  if (Serial.available())
    softser.write(Serial.read());
  
  /*

  while (softser.available()) {
    //Create a char buffer of maximum 12 bytes
    static char message[MAX_MESSAGE_LENGTH];
    static unsigned int message_pos = 0;
    delay(3);  
    char c = softser.read();
    //readString += c; 
    
    if ( c != '\n' && (message_pos < MAX_MESSAGE_LENGTH - 1) )
   {
     //Add the incoming byte to our message
     message[message_pos] = c;
     message_pos++;
   }
   
  //Full message received...
   else
   {
     //Add null character to string
     message[message_pos] = '\0';

     //Print the message (or do other things)
     Serial.println(message);

     //Reset for the next message
     message_pos = 0;
   }*/

  /*if (readString.length() >0) {
    Serial.println(readString);

    if (readString == "on")     
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }
    if (readString == "off")
    {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
    readString="";*/
  } 
