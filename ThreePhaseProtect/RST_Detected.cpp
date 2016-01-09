#include "RST_Detected.h"
#include "io_defs.h"
#include "PhaseFailure.h"
#include "RST_Verified.h"

const long TIMEOUT = 10000; //ten ms in us

RST_Detected::RST_Detected(Fsm* fsm, ASi* asi):State(fsm),  m_asi(asi), m_periodTimer(asi->getPlatform(), TIMEOUT),
                                         m_r_sw(R_PHASE, HIGH, asi),
                                         m_s_sw(S_PHASE, HIGH, asi),
                                         m_t_sw(T_PHASE, HIGH, asi)
{}

RST_Detected*
RST_Detected::Instance(Fsm* fsm, ASi* asi)
{
    static RST_Detected RST_Detected(fsm, asi);
    return &RST_Detected;
}

void
RST_Detected::execute()
{
    m_periodTimer.start();

    if(m_r_sw.isOn() && m_s_sw.isOn() && !m_t_sw.isOn())
    {
        m_fsm->setState(RST_Verified::Instance(m_fsm, m_asi));

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
RST_Detected::reset()
{
    m_periodTimer.reset();
}
