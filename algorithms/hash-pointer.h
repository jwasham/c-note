/**
 * @file hash-pointer.h
 *
 * Hash function for a generic (void) pointer.  See @ref pointer_hash.
 */

#ifndef ALGORITHM_HASH_POINTER_H
#define ALGORITHM_HASH_POINTER_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Generate a hash key for a pointer.  The value pointed at by the pointer
 * is not used, only the pointer itself.
 *
 * @param location        The pointer
 * @return                A hash key for the pointer.
 */

unsigned int pointer_hash(void *location);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef ALGORITHM_HASH_POINTER_H */


