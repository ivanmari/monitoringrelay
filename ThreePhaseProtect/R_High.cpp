#include "R_High.h"
#include "RST_Detected.h"
#include "RTS_Detected.h"
#include "PhaseFailure.h"
#include "io_defs.h"


const int BLOCKING_PERIOD = 5000; // 5 milliseconds

R_High::R_High(Fsm* fsm, ASi* asi):State(fsm),  m_asi(asi), m_blockingPeriodTimer(asi->getPlatform(), BLOCKING_PERIOD),
                                         m_r_sw(asi->getPlatform(), R_PHASE, HIGH),
                                         m_s_sw(asi->getPlatform(), S_PHASE, HIGH),
                                         m_t_sw(asi->getPlatform(), T_PHASE, HIGH)
{}

R_High*
R_High::Instance(Fsm* fsm, ASi* asi)
{
    static R_High R_High(fsm, asi);
    return &R_High;
}

void
R_High::execute()
{
    m_blockingPeriodTimer.start();

    if(m_r_sw.isOn() && m_s_sw.isOn() && !m_t_sw.isOn())
    {
        m_fsm->setState(RTS_Detected::Instance(m_fsm, m_asi));

        m_blockingPeriodTimer.reset();
        return;
    }

    if(m_r_sw.isOn() && !m_s_sw.isOn() && m_t_sw.isOn() )
    {
        m_fsm->setState(RST_Detected::Instance(m_fsm, m_asi));

        m_blockingPeriodTimer.reset();
        return;
    }

    if(m_blockingPeriodTimer.expired())
    {
        m_fsm->setState(PhaseFailure::Instance(m_fsm, m_asi));

        m_blockingPeriodTimer.reset();
        return;
    }
}

void
R_High::reset()
{
    m_blockingPeriodTimer.reset();
}
