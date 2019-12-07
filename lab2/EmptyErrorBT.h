//
// Created by dmo on 09.10.2019.
//

#ifndef SOFTWARE_DESIGN_EMPYERRORBT_H
#define SOFTWARE_DESIGN_EMPYERRORBT_H

#include "BTException.h"

class EmptyErrorBT : public BTException {
public:
    inline explicit EmptyErrorBT(const char *msg)
            : BTException(msg) {}
};

class NonBTElement : public BTException {
public:
    inline explicit NonBTElement(const char *msg)
            : BTException(msg) {}
};

#endif //SOFTWARE_DESIGN_EMPYERRORBT_H
