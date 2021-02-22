Monitoring Relay for Three Phase Motors

This application detects the phase sequence of a three phase 380V 50Hz system and signals also
a faulty phase.
![](https://github.com/ivanmari/monitoringrelay/blob/master/ThreePhaseProtect/Resources/MonitoringRelayApp.png)


Hardware

The circuit, for each phase is the same as the one depicted here https://smartsolutions4home.com/detecting-mains-voltage-with-microcontroller/.


Logic

In each of the three IO lines, R, S and T, there will be a square wave shifted 120 degs each. 
For sequence detection, we use the same principle used in quadrature encoders. There will be
two possible sequences: RST or RTS. So we start looking for R to be low a couple of us, then
look for the R phase to transition LOW->HIGH. Then check which of the remaining phases is HIGH.
If S is HIGH while R rises, then the sequence is RTS. But, if S is LOW while R rises, the
sequence is RST.

![Detectors Waveform](https://github.com/ivanmari/monitoringrelay/blob/master/ThreePhaseProtect/Resources/phase_rotation_detect.png)

Once this is detected, the corresponding LED is lit for over a second, and then the cycle repeats.
There are timers in each state that control the timing of the transitions, and if some transition
does not occur within the correct period of time, then an alarm is displayed for a second, and the 
motor contactor is opened. After that time, the system enters in the initial state trying to detect
phase sequence again. But the contactor remains open until Start is pressed.


