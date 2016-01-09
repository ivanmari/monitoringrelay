#ifndef R_LOW_STATE_H
#define R_LOW_STATE_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "ASi.h"
#include "Switch.h"

/** \brief Edge detection
 *
 * The R phase is being polled to find a stable HIGH level.
 * As this state was reached after a period with a stable LOW level, it is clear
 * that after finding a HIGH level, a rising edge occurred, so the zero crossing
 * of the phase took place and we can transition to the R_HIGH state.
 *
 */


class R_Low : public State
{
public:
    R_Low(Fsm* fsm, ASi* asi);

    static R_Low* Instance(Fsm* fsm, ASi* asi);

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

#endif // R_LOW_STATE_H
