#include "RTS_Verified.h"

#include "io_defs.h"
#include "PhaseFailure.h"
#include "R_Sync.h"

const long TIMEOUT = 1000000; //one second in us

RTS_Verified::RTS_Verified(Fsm* fsm, ASi* asi):State(fsm),  m_asi(asi), m_displayTimer(asi->getPlatform(), TIMEOUT)
{}

RTS_Verified*
RTS_Verified::Instance(Fsm* fsm, ASi* asi)
{
    static RTS_Verified RTS_Verified(fsm, asi);
    return &RTS_Verified;
}

void
RTS_Verified::execute()
{
    m_displayTimer.start();

    m_asi->setRSTIndicator (false);
    m_asi->setRTSIndicator (true);
    m_asi->setErrorIndicator (false);
    m_asi->setOutputRelay(false);

    if(m_displayTimer.expired())
    {
        m_fsm->setState(R_Sync::Instance(m_fsm, m_asi));

        m_displayTimer.reset();
        return;
    }
}

void
RTS_Verified::reset()
{
    m_displayTimer.reset();
}
