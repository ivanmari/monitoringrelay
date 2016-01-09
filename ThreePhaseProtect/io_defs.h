#ifndef IO_DEFS
#define IO_DEFS

#ifdef X86_PLAT
const int RTS_LED = 2;
const int RST_LED = 3;
const int ERR_LED = 13;
const int R_PHASE = 5;
const int S_PHASE = 6;
const int T_PHASE = 7;

const bool HIGH = true;
const bool LOW = false;

#else

#include <Arduino.h>

const int RTS_LED = 2;
const int RST_LED = 3;
const int ERR_LED = 13;
const int R_PHASE = 5;
const int S_PHASE = 6;
const int T_PHASE = 7;


void initIO();

#endif // x86_PLAT


#endif //IO_DEFS
