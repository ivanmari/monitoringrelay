#ifndef ASI_H
#define ASI_H

#include "Platform.h"


class ASi
{
public:

    ASi(Platform*);

    /*Outputs*/

    virtual void setRSTIndicator (bool stat);
    virtual void setRTSIndicator (bool stat);
    virtual void setErrorIndicator (bool stat);

private:

    Platform* m_platform;
};

#endif //ASI_H
