#include "R_Sync.h"
#include "R_Low.h"
#include "PhaseFailure.h"
#include "io_defs.h"

const int TIMEOUT = 20000; //20 milliseconds

R_Sync::R_Sync(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi), m_periodTimer(asi->getPlatform(), TIMEOUT), m_sw(R_PHASE, LOW, asi)
{}

R_Sync*
R_Sync::Instance(Fsm* fsm, ASi* asi)
{
    static R_Sync R_Sync(fsm, asi);
    return &R_Sync;
}

void
R_Sync::execute()
{
    m_periodTimer.start();

    m_asi->setRSTIndicator (false);
    m_asi->setRTSIndicator (false);
    m_asi->setErrorIndicator (false);

    if(m_sw.isOn()) /*active LOW*/
    {
        m_fsm->setState(R_Low::Instance(m_fsm, m_asi));

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
R_Sync::reset()
{
}
