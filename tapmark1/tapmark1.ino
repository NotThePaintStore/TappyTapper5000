// describe what this is supposed to do overall

#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

// constants
const int threshold = 100;
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
Piezo piezo0(A0, 1);
/*Piezo piezo0(A1, 2);
Piezo piezo0(A2, 3);
Piezo piezo0(A3, 4);
Piezo piezo0(A4, 5);
Piezo piezo0(A5, 6);
Piezo piezo0(A6, 7);
Piezo piezo0(A7, 8);
Piezo piezo0(A8, 9);
Piezo piezo0(A9, 10);
Piezo piezo0(A10, 11);
Piezo piezo0(A11, 12);
Piezo piezo0(A12, 13);
Piezo piezo0(A13, 14);
Piezo piezo0(A14, 15);
Piezo piezo0(A15, 16);*/

void setup() {
  
}

void loop() {
  piezo0.listen_analog();
  
}
