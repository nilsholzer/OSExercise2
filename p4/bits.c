#include <stdint.h>

#include "bits.h"

/*
 * Returns the n'th bit of the array A.
 */
int getN(uint64_t *A, size_t n)
{
    uint64_t element = A[n / 64];
    uint64_t bit = n % 64;

    return (element & (1 << bit)) >> bit;
}

/*
 * Sets the n'th bit of the array A.
 */
void setN(uint64_t *A, size_t n)
{
    uint64_t element = A[n / 64];
    uint64_t bit = n % 64;

    A[n / 64] = element | (1 << bit);
}

/*
 * Clears the n'th bit of the array A.
 */
void clrN(uint64_t *A, size_t n)
{
    uint64_t element = A[n / 64];
    uint64_t bit = n % 64;

    A[n / 64] = element & ~(1 << bit);
}


/*
 * Rotates the integer i n bits to the right.
 */
uint64_t rot(uint64_t i, int n)
{
    if (n >= 0){
        n = n % 64;
        return (i >> n) | (i << (64 - n));
    } else {
        n = -n % 64;
        return (i << n) | (i >> (64 -n));
    }
}
