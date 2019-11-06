
/*#include <MIDIUSB.h>*/


// these constants won't change:
const int knockSensor1 = A0; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin

void setup() {

  Serial.begin(31250);       // use the serial port 
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor1);

  int val1 = analogRead(knockSensor1);
  val1 = map(val1,0,1023,0,127);

  // if the sensor reading is greater than the threshold:
  /*if (sensorReading >= threshold) {
    int note=50
    int velocity = val1
    MIDImessage(noteON, note, velocity);
  } */
}
/*
void MIDImessage(int command, int MIDInote, int MIDIvelcoity) {
    Serial.write (command);
    Serial.write (MIDInote);
    Serial.write (MIDIvelocity);
    
   
} */
