#include <ctype.h>

#include "hash-string.h"

/* String hash function */

unsigned int string_hash(void *string) {
    /* This is the djb2 string hash function */

    unsigned int result = 5381;
    unsigned char *p;

    p = (unsigned char *) string;

    while (*p != '\0') {
        result = (result << 5) + result + *p;
        ++p;
    }

    return result;
}

/* The same function, with a tolower on every character so that
 * case is ignored.  This code is duplicated for performance. */

unsigned int string_nocase_hash(void *string) {
    unsigned int result = 5381;
    unsigned char *p;

    p = (unsigned char *) string;

    while (*p != '\0') {
        result = (result << 5) + result + (unsigned int) tolower(*p);
        ++p;
    }

    return result;
}

