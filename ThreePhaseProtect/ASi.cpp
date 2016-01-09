#include "ASi.h"
#include "Platform.h"
#include "io_defs.h"

/*
    ASi: Actuator Sensor interface

*/

ASi::ASi(Platform* plat):m_platform(plat)
{
    m_platform->setPinMode(RTS_LED, PIN_OUTPUT);
    m_platform->setPinMode(RST_LED,PIN_OUTPUT);
    m_platform->setPinMode(ERR_LED,PIN_OUTPUT);
}

/*Outputs*/

void
ASi::setRSTIndicator (bool stat)
{
    m_platform->setPin(RST_LED, stat);
}

void
ASi::setRTSIndicator (bool stat)
{
    m_platform->setPin(RTS_LED, stat);
}

void
ASi::setErrorIndicator (bool stat)
{
    m_platform->setPin(ERR_LED, stat);
}


