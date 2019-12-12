// describe what this is supposed to do overall

#include <MIDI.h>

// activate the midi library
MIDI_CREATE_DEFAULT_INSTANCE();

// constants
const int threshold = 1023;
const int midiChannel = 1;

// Variables
char* names[9];

// class declaration to make multiple instances of
class Piezo {
  private:
    int pinNum, midiNote;
  public:
    bool armed = true;
    void listen_analog();
    Piezo(int x, int y) {
      pinNum = x;
      midiNote = y;
    }
};

/*******************************
 * Begin function declarations *
 *******************************/

// send the midi message; global scope
void send_message(int note, int velocity) {
  MIDI.sendNoteOn(note, velocity, midiChannel);
}

// map analog value to velocity value; global scope
int map_midi(int sensorVal) {
  int velocity = map(sensorVal,threshold,1023,1,127);
  return velocity;
}

// listen for input; class scope
void Piezo::listen_analog() {
  int sensorReading = analogRead(pinNum);
  if (sensorReading >= threshold && armed == true) {
    //armed = false;
    int sensorVelocity = 127; //map_midi(sensorReading);
    send_message(midiNote, sensorVelocity);
  }
}

class StopPiezo : public Piezo {
  public:
    void arm_all();
};

// Re-arms all messages
void StopPiezo::arm_all() {
  for (int i = 0; i <= 9; i++) {
    names[i].armed = true;
  }
}

/*****************************
 * End function declarations *
 *****************************/

// declare all the analog pins as Piezo class instances w/
// pin numbers and midi note values

// Using pins 7-15

Piezo piezo1(A11, 10);
Piezo piezo2(A12, 20);
Piezo piezo3(A13, 30);
Piezo piezo4(A14, 40);
Piezo piezo5(A15, 50);
Piezo piezo6(A7, 60);
Piezo piezo7(A8, 70);
Piezo piezo8(A9, 80);
StopPiezo piezo9(A10, 90);

names[] = {
    &piezo1,
    &piezo2,
    &piezo3,
    &piezo4,
    &piezo5,
    &piezo6,
    &piezo7,
    &piezo8,
    &piezo9,
    &piezo10
  };

// code that runs once at power on
void setup() {
  // midi won't send without this
  Serial.begin(31250);
}

// code that loops forever
void loop() {
  piezo1.listen_analog();
  piezo2.listen_analog();
  piezo3.listen_analog();
  piezo4.listen_analog();
  piezo5.listen_analog();
  piezo6.listen_analog();
  piezo7.listen_analog();
  piezo8.listen_analog();
  piezo9.listen_analog();
}
