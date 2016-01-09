#ifndef PRECISIONTIMER_H
#define PRECISIONTIMER_H

#include "ASi.h"

class PrecisionTimer
{
public:
    PrecisionTimer(ASi* asi, unsigned long timeout);
    virtual ~PrecisionTimer();

    virtual void stop();
    virtual void start();
    virtual void reset();

    virtual bool running() const;
    virtual bool stopped() const;
    virtual bool expired() const;

protected:

private:
    ASi*  m_asi;
    unsigned long m_timeStart;
    unsigned long m_timeElapsed;
    unsigned long m_timeout;
    bool m_active;
};

#endif // PRECISIONTIMER_H
