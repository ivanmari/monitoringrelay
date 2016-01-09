#ifndef R_T_H
#define R_T_H

#include "Fsm.h"
#include "PrecisionTimer.h"
#include "ASi.h"
#include "Switch.h"


/** \brief RTS Sequence Detected
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
