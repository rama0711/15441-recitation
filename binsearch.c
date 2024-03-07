/**
 * @file binsearch.c
 * @author (you) & (partner)
 * @brief Binary search implementation
 * @version 0.1
 * @date 2024-03-xx 
 */
#include <assert.h>
#include <stdio.h>

/**
 * @brief Specification function, linearly search in array A
 */
int linsearch(int A[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            return i;
        }
    }

    return -1;
}


/**
 * @brief Binary search for integer arrays
 * 
 *  @todo: 1a) fix bug plss
 *         2a) make generic.. (can we replace int with a macro at least..)
 * 
 *         1b) rename variables to something funky
 *         2b) add pre and post cond assertions
 * 
 * @bug: returns wrong answers..
 * 
 * @param A Array to search in
 * @param n len(A)
 * @param x element to search for
 * @return res >= 0 exists         -- res is idx of element
 *             < 0  does not exist -- (-n) - 1 is insertion position
 * 
 * @pre sizeof A / A[0] == n
 * @pre n >= 0
 * @post binsearch(A, n, x) == linsearch(A, n, x)
 */
int binsearch(int A[], int n, int x) {
    int lo = 0, hi = n, mid = 0; 
    int idx = 0;

    while (lo < hi) {
        mid = lo + (hi - lo)/2;

        if (A[mid] == x) {
            return mid;
        }

        if (A[mid] < x) {
            lo = mid+1;     // lo inclusive
        }

        if (A[mid] > x) {
            hi = mid;       // exclusive
        }
    }

    assert(lo == hi);
    return -lo - 1;  // need to return -1 to disambiguate
}


int main() {
    int A[] = { 0, 10, 203, 502, 703, 1230, 1430, 8390 };
    int n = (sizeof A) / (sizeof A[0]);

    /* Does this work?? */
    assert(binsearch(A, n, 502) == linsearch(A, n, 502));   /* Basic case */
    assert((-binsearch(A, n, -100) -1)  == 0);                     /* left boundary */
    assert((-binsearch(A, n, 100000) -1)  == n);                   /* right boundary */

    printf("All Tests passed :)\n");

    return 0;
}
