#ifndef SOFTWARE_DESIGN_BTEXCEPTION_H
#define SOFTWARE_DESIGN_BTEXCEPTION_H

#include <string>
#include <utility>
#include <exception>

class BTException {
public:
    BTException() = default;
    inline explicit BTException(const char *msg)
            : msg_(msg) {}

    const char *what() const {
        return msg_;
    }

protected:
    const char *msg_;
};

#endif //SOFTWARE_DESIGN_BTEXCEPTION_H
