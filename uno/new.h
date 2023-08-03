#ifndef UNO_NEW_H_
#define UNO_NEW_H_

#include <stddef.h>

inline void* operator new(size_t, void *p) noexcept {
    return p;
}

#endif  //  UNO_NEW_H_
