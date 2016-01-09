#ifndef RST_VERIFY_H
#define RST_VERIFY_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "ASi.h"
#include "Switch.h"

/** \brief All Phases Verified in in RST sequence
 *
 * \param
 * \param
 * \return
 *
 */


class RST_Verified : public State
{
public:
    RST_Verified(Fsm* fsm, ASi* asi);

    static RST_Verified* Instance(Fsm* fsm, ASi* asi);

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

#endif // RST_VERIFY_H
