#include "R_Low.h"
#include "R_High.h"
#include "PhaseFailure.h"
#include "io_defs.h"

const int BLOCKING_PERIOD = 15000; //15 milliseconds

R_Low::R_Low(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi), m_periodTimer(asi->getPlatform(), BLOCKING_PERIOD), m_sw(R_PHASE, HIGH, asi)
{}

R_Low*
R_Low::Instance(Fsm* fsm, ASi* asi)
{
    static R_Low R_Low(fsm, asi);
    return &R_Low;
}

void
R_Low::execute()
{
    m_periodTimer.start();

    m_asi->setRSTIndicator (false);
    m_asi->setRTSIndicator (false);
    m_asi->setErrorIndicator (false);

    if(m_sw.isOn())
    {
        m_fsm->setState(R_High::Instance(m_fsm, m_asi));

        m_periodTimer.reset();
        return;
    }

    if(m_periodTimer.expired())
    {
        m_fsm->setState(PhaseFailure::Instance(m_fsm, m_asi));

        m_periodTimer.reset();
        return;
    }
}

void
R_Low::reset()
{
}
