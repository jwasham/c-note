#include <limits.h>

#include "hash-pointer.h"

/* Hash function for a generic pointer */

unsigned int pointer_hash(void *location) {
    return (unsigned int) (unsigned long) location;
}

