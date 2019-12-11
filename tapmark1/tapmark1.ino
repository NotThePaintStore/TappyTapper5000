// describe what this is supposed to do overall

#include <MIDI.h>

// activate the midi library
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

// send the midi message; global scope
void send_message(int note, int velocity) {
  MIDI.sendNoteOn(note, velocity, midiChannel);
}

// map analog value to velocity value; global scope
int map_midi(int sensorVal) {
  int velocity = map(sensorVal,threshold,1023,1,127);
  return velocity;
}

// we need to wait to send another message until value of
// piezo returns below threshold

// listen for input; class scope
/*void Piezo::listen_analog() {
  int sensorReading = analogRead(pinNum);
  bool triggered = false;
  if (sensorReading >= threshold) {
    int sensorVelocity = 127; //map_midi(sensorReading);
    send_message(midiNote, sensorVelocity);
    triggered = true;
  }
  while (triggered) {
    
  }
}
*/
void Piezo::listen_analog() {
  int sensorReading = analogRead(pinNum);
  bool triggered = false;
  if (sensorReading >= threshold) {
    int sensorVelocity = 127; //map_midi(sensorReading);
    send_message(midiNote, sensorVelocity);
    triggered = true;
  }
}

/*****************************
 * End function declarations *
 *****************************/

// declare all the analog pins as Piezo class instances w/
// pin numbers and midi note values

// Can't use pins 0 or 6 so we need to use 1-5 + 7-10

Piezo piezo1(A1, 10);
Piezo piezo2(A2, 20);
Piezo piezo3(A3, 30);
Piezo piezo4(A4, 40);
Piezo piezo5(A5, 50);
Piezo piezo6(A7, 60);
Piezo piezo7(A8, 70);
Piezo piezo8(A9, 80);
Piezo piezo9(A10, 90);

void setup() {
  
}

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
