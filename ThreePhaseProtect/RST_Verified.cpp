#include "RST_Verified.h"

#include "io_defs.h"
#include "PhaseFailure.h"
#include "R_Sync.h"

const long TIMEOUT = 1000000; //one second in us

RST_Verified::RST_Verified(Fsm* fsm, ASi* asi):State(fsm),  m_asi(asi), m_displayTimer(asi->getPlatform(), TIMEOUT)
{}

RST_Verified*
RST_Verified::Instance(Fsm* fsm, ASi* asi)
{
    static RST_Verified RST_Verified(fsm, asi);
    return &RST_Verified;
}

void
RST_Verified::execute()
{
    m_displayTimer.start();

    m_asi->setRSTIndicator (true);
    m_asi->setRTSIndicator (false);
    m_asi->setErrorIndicator (false);
    m_asi->setOutputRelay(true);

    if(m_displayTimer.expired())
    {
        m_fsm->setState(R_Sync::Instance(m_fsm, m_asi));

        m_displayTimer.reset();
        return;
    }
}

void
RST_Verified::reset()
{
    m_displayTimer.reset();
}
