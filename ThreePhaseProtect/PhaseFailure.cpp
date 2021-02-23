#include "PhaseFailure.h"
#include "R_Sync.h"
#include "io_defs.h"

const long BLOCKING_PERIOD = 1000000; //one second in us

PhaseFailure::PhaseFailure(Fsm* fsm, ASi* asi):State(fsm), m_asi(asi),m_blockingPeriodTimer(asi->getPlatform(), BLOCKING_PERIOD), m_sw(R_PHASE, HIGH, asi)
{}

PhaseFailure*
PhaseFailure::Instance(Fsm* fsm, ASi* asi)
{
    static PhaseFailure PhaseFailure(fsm, asi);
    return &PhaseFailure;
}

void
PhaseFailure::execute()
{
    m_blockingPeriodTimer.start();

    m_asi->setRSTIndicator (false);
    m_asi->setRTSIndicator (false);
    m_asi->setErrorIndicator (true);

    if(m_blockingPeriodTimer.expired())
    {
        m_fsm->setState(R_Sync::Instance(m_fsm, m_asi));

        m_blockingPeriodTimer.reset();
        return;
    }
}

void
PhaseFailure::reset()
{
}

