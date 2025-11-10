#ifndef USER_MACROS_CPP
#define USER_MACROS_CPP

#include <cassert>

// Add a custom message to asserts
#define ASSERT(condition, message) \
do { \
    assert(condition && message); \
} while (0)

#endif