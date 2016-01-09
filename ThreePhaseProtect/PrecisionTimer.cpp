#include "PrecisionTimer.h"

PrecisionTimer::PrecisionTimer(ASi* asi, unsigned long timeout):m_asi(asi), m_timeStart(0), m_timeElapsed(0), m_timeout(timeout), m_active(false)
{
    //ctor
}

PrecisionTimer::~PrecisionTimer()
{

}

void
PrecisionTimer::start()
{
    if(!m_active)
    {
        m_active = true;
        m_timeStart = m_asi-> getSystemUpTimeMicros();
    }
}

bool
PrecisionTimer::running() const
{
    return m_active;
}

bool
PrecisionTimer::stopped() const
{
    return !m_active;
}

void
PrecisionTimer::stop()
{
    m_active = false;
    m_timeElapsed = m_asi-> getSystemUpTimeMicros() - m_timeStart;
}

void
PrecisionTimer::reset()
{
    m_active = false;
    m_timeStart = 0;
    m_timeElapsed = 0;

}

bool
PrecisionTimer::expired() const
{
    bool ret = false;

    unsigned long currently_elapsed = 0;

    if(m_active)
    {
        currently_elapsed = m_asi-> getSystemUpTimeMicros() - m_timeStart;
    }

    if (m_timeElapsed + currently_elapsed >= m_timeout)
    {
        ret = true;
    }


    return ret;
}


