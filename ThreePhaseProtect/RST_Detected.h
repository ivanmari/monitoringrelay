#ifndef R_S_H
#define R_S_H

#include "ASi.h"
#include "PrecisionTimer.h"
#include "Switch.h"
#include "Fsm.h"

/** \brief RST Sequence Detected
 *
 * \param
 * \param
 * \return
 *
 */


class RST_Detected : public State
{
public:
    RST_Detected(Fsm* fsm, ASi* asi);

    static RST_Detected* Instance(Fsm* fsm, ASi* asi);

    void execute();
    void reset();
#ifdef X86_PLAT
    std::string getName() const
    {
        return "R_S_State";
    }
#endif // X86_PLAT
private:

    ASi* m_asi;
    PrecisionTimer m_periodTimer;
    Switch m_r_sw;
    Switch m_s_sw;
    Switch m_t_sw;
};

#endif // R_S_H
