#ifndef R_T_H
#define R_T_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "ASi.h"
#include "Switch.h"


/** \brief RTS Sequence Detected
 *
 *  Once in this state, we know that after R came T, but we must still
 *  verify that S is going High so as to be sure that the 3 phases are
 *  working OK.
 *
 *  Previous state: R_High
 *  Next states: RTS_Verified, PhaseFailure
 *
 * \param
 * \param
 * \return
 *
 */

class RTS_Detected : public State
{
public:
    RTS_Detected(Fsm* fsm, ASi* asi);

    static RTS_Detected* Instance(Fsm* fsm, ASi* asi);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "R_T_State";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    PrecisionTimer m_periodTimer;
    Switch m_r_sw;
    Switch m_s_sw;
    Switch m_t_sw;
};


#endif // R_T_H
