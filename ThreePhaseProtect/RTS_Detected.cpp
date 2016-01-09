#include "RTS_Detected.h"
#include "io_defs.h"
#include "PhaseFailure.h"
#include "RTS_Verified.h"

const long TIMEOUT = 10000; //ten ms in us

RTS_Detected::RTS_Detected(Fsm* fsm, ASi* asi):State(fsm),  m_asi(asi), m_periodTimer(asi, TIMEOUT),
                                         m_r_sw(R_PHASE, HIGH, asi),
                                         m_s_sw(S_PHASE, HIGH, asi),
                                         m_t_sw(T_PHASE, HIGH, asi)
{}

RTS_Detected*
RTS_Detected::Instance(Fsm* fsm, ASi* asi)
{
    static RTS_Detected RTS_Detected(fsm, asi);
    return &RTS_Detected;
}

void
RTS_Detected::execute()
{
    m_periodTimer.start();

    if(m_r_sw.isOn() && !m_s_sw.isOn() && m_t_sw.isOn())
    {
        m_fsm->setState(RTS_Verified::Instance(m_fsm, m_asi));

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
RTS_Detected::reset()
{
    m_periodTimer.reset();
}
