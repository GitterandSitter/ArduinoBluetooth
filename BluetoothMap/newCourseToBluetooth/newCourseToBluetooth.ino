#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
SoftwareSerial softser(8, 9); // RX | TX

double LAT = 44.88285;
double LNG = -68.67253;

String inString = "";

unsigned long lastUpdateTime = 0;




void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);
  softser.begin(GPSBaud);

  
  Serial.println("Initializing program");
  
}

void loop()
{
 
  
  if (inString.length()==0){
  Serial.println("Send coordinates to proceed");
  while (softser.available() > 0){ 
    char inChar = softser.read();
    if(isDigit(inChar)||inChar==','||inChar=='.'){
    inString += inChar;
    }
   }
  int splitIndex = inString.indexOf(",");
  LAT = (double) inString.substring(0, splitIndex).toDouble();  //split indexshifted, substring counted normally
  LNG = (double) inString.substring(++splitIndex, inString.length()).toDouble();

  Serial.println(" inString: ");
  Serial.println(inString);

  Serial.println(" ");
  Serial.println("  Latitude: ");
  Serial.println(LAT, 14);
  Serial.println(" ");

  Serial.println("  Longitude: ");
  Serial.println(LNG, 14);
  }
 

   else {
  Serial.println("Calculating distance and heading");
  ss.listen();
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    if (gps.encode(ss.read())){
      
      displayHeading();}
      
  }
   }
 
}

void displayHeading()
{

    Serial.println();

    // Establish our current status
    double distanceToDestination = TinyGPSPlus::distanceBetween(
      gps.location.lat(), gps.location.lng(), LAT, LNG);
    double courseToDestination = TinyGPSPlus::courseTo(
      gps.location.lat(), gps.location.lng(), LAT, LNG);
    

    Serial.print("Course to Destination: ");
    Serial.print(courseToDestination);
    Serial.print("  Distance: ");
    Serial.print(distanceToDestination);
    
  Serial.println();
  
}
