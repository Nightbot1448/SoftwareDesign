#ifndef SOFTWARE_DESIGN_EMPYERRORBT_H
#define SOFTWARE_DESIGN_EMPYERRORBT_H

#include "BTException.h"

class EmptyErrorBT : public BTException {
public:
    inline explicit EmptyErrorBT(const char *msg)
            : BTException(msg) {}
};

#endif //SOFTWARE_DESIGN_EMPYERRORBT_H
