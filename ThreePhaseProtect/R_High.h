#ifndef DoorsClosed_H
#define DoorsClosed_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "ASi.h"
#include "Switch.h"

/** \brief Sequence detection
 *
 * Once in a stable HIGH level for the R phase, there are only two possibilities for the S and T phases.
 *
 * Either:
 *
 * S is HIGH && T is LOW => RTS sequence
 *
 * OR
 *
 * S is LOW && T is HIGH => RST sequence
 *
 * Previous state: R_Low
 * Next states: RTS_Detected, RST_Detected, PhaseFailure
 *
 * \param
 * \param
 * \return
 *
 */

class R_High : public State
{
public:
    R_High(Fsm* fsm, ASi* asi);

    static R_High* Instance(Fsm* fsm, ASi* asi);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "R_State";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    PrecisionTimer m_blockingPeriodTimer;
    Switch m_r_sw;
    Switch m_s_sw;
    Switch m_t_sw;
};

#endif

