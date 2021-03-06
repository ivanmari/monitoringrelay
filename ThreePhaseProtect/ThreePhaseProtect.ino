/*
This application detects the phase sequence of a three phase 380V 50Hz system and signals also
a faulty phase. The circuit, for each phase is the same as the one for MainsDetector application.

In each of the three IO lines, R, S and T, there will be a square wave shifted 120 degs each. 
For sequence detection, we use the same principle used in quadrature encoders. There will be
two possible sequences: RST or RTS. So we start looking for R to be low a couple of us, then
look for the R phase to transition LOW->HIGH. Then check which of the remaining phases is HIGH.
If S is HIGH while R rises, then the sequence is RTS. But, if S is LOW while R rises, the
sequence is RST.
Once this is detected, the corresponding LED is lit for over a second, and then the cycle repeats.
There are timers in each state that control the timing of the transitions, and if some transition
does not occur within the correct period of time, then an alarm is displayed for a second. After
that time, the system enters in the initial state trying to detect phase sequence again.
*/


#include "ArduinoPlat.h"
#include "ASi.h"
#include "PrecisionTimer.h"
#include "Switch.h"
#include "io_defs.h"
#include "R_Sync.h"

ArduinoPlat plat;
ASi asi(&plat);
Fsm fsm;


void setup() {
  fsm.setState(R_Sync::Instance(&fsm, &asi));
}

void loop() {
   fsm.run();
}
