#ifndef DoorsOpen_H
#define DoorsOpen_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "Switch.h"

/** \brief Synchronization
 *
 * While being in this state, the R phase is polled for a stable LOW level.
 * Once a LOW period is found, a transition to R_Low is triggered
 *
 * After polling the phase for TIMEOUT us without finding a stable LOW, a
 * transition to PhaseFailure is triggered
 *
 */


class R_Sync : public State
{
public:
    R_Sync(Fsm* fsm, ASi* asi);

    static R_Sync* Instance(Fsm* fsm, ASi* asi);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "Initial";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    PrecisionTimer m_periodTimer;
    Switch m_sw;
};
#endif

