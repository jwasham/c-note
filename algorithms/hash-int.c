#include "hash-int.h"

/* Hash function for a pointer to an integer */

unsigned int int_hash(void *vlocation)
{
	int *location;

	location = (int *) vlocation;

	return (unsigned int) *location;
}

