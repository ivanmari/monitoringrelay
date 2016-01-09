#ifndef PHASEFAILURE_STATE_H
#define PHASEFAILURE_STATE_H

#include "ASi.h"
#include "PrecisionTimer.h"
#include "Switch.h"
#include "Fsm.h"

class PhaseFailure: public State
{
public:
    PhaseFailure(Fsm* fsm, ASi* asi);

    static PhaseFailure* Instance(Fsm* fsm, ASi* asi);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "PhaseFailure_State";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    PrecisionTimer m_blockingPeriodTimer;
    Switch m_sw;
};

#endif // PHASEFAILURE_STATE_H
