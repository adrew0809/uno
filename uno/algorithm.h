#ifndef UNO_UNO_ALGORITHM_H_
#define UNO_UNO_ALGORITHM_H_

#include "utility.h"

namespace uno {

template<class InputIt, class OutputIt, class UnaryOperation>
OutputIt transform(InputIt first1, InputIt last1,
                   OutputIt d_first, UnaryOperation&& unary_op) {
    while (first1 != last1)
        *d_first++ = forward<UnaryOperation>(unary_op)(*first1++);
 
    return d_first;
}

}  // namespace uno

#endif  // UNO_UNO_ALGORITHM_H_
