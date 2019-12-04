// describe what this is supposed to do overall

#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// constants
const int threshold = 500;
const int midiChannel = 1;

// class declaration to make multiple instances of
class Piezo {
  private:
    int pinNum, midiNote;
  public:
    void listen_analog();
    Piezo(int x, int y) {
      pinNum = x;
      midiNote = y;
    }
};

/*******************************
 * Begin function declarations *
 *******************************/

// sends the midi message; global scope
void send_message(int note, int velocity) {
  MIDI.sendNoteOn(note, velocity, midiChannel);
}

// maps analog value to velocity value; global scope
int map_midi(int sensorVal) {
  int velocity = map(sensorVal,threshold,1023,0,127);
  return velocity;
}

// listens for input; belongs to the class scope
void Piezo::listen_analog() {
  int sensorReading = analogRead(pinNum);
  if (sensorReading >= threshold) {
    int sensorVelocity = map_midi(sensorReading);
    send_message(midiNote, sensorVelocity);
   
  }
}

/*****************************
 * End function declarations *
 *****************************/

// declare all the analog pins as Piezo class instances w/
// pin numbers and midi note values
Piezo piezo0(A0, 10);
/*Piezo piezo1(A1, 20);
Piezo piezo2(A2, 30);
Piezo piezo3(A3, 40);
Piezo piezo4(A4, 50);
Piezo piezo5(A5, 60);
Piezo piezo6(A6, 70);
Piezo piezo7(A7, 80);
Piezo piezo8(A8, 90);
Piezo piezo9(A9, 100);
Piezo piezo10(A10, 110);
Piezo piezo11(A11, 120);
Piezo piezo12(A12, 130);
Piezo piezo13(A13, 140);
Piezo piezo14(A14, 150);
Piezo piezo15(A15, 160);*/

void setup() {
  Serial.begin(31250);
}

void loop() {
  piezo0.listen_analog();  
}
