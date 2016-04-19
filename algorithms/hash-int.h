/**
 * @file hash-int.h
 *
 * Hash function for a pointer to an integer.  See @ref int_hash.
 */

#ifndef ALGORITHM_HASH_INT_H
#define ALGORITHM_HASH_INT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Generate a hash key for a pointer to an integer.  The value pointed
 * at is used to generate the key.
 *
 * @param location        The pointer.
 * @return                A hash key for the value at the location.
 */

unsigned int int_hash(void *location);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_HASH_INT_H */

