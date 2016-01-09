#ifndef DETECTIONCOMPLETE_H
#define DETECTIONCOMPLETE_H


#include "Fsm.h"
#include "PrecisionTimer.h"
#include "ASi.h"
#include "Switch.h"

/** \brief All Phases Verified in RTS sequence
 *
 * Once this state is entered, the 3 phases were checked to be in RTS sequence
 * so the LED for that sequence is set to ON and the OUTPUT Relay is set to OFF
 *
 * \param
 * \param
 * \return
 *
 */


class RTS_Verified : public State
{
public:
    RTS_Verified(Fsm* fsm, ASi* asi);

    static RTS_Verified* Instance(Fsm* fsm, ASi* asi);

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
    PrecisionTimer m_displayTimer;
};

#endif // DETECTIONCOMPLETE_H
