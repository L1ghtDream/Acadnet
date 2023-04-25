#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------- Defining a set -------------------------------- */

#define MAX_NR 10000000
#define SET_SIZE ((MAX_NR + 1) / 8)
typedef unsigned char SET[SET_SIZE];

SET my_set = {0};

/* ------------------------- Helper functions! ------------------------------ */

static inline void insert_in_set(SET s, unsigned int n) {
    // Find the corresponding cell and set one of its bits
    s[n / 8] |= 1 << n % 8;
}

static inline int is_in_set(SET s, unsigned int n) {
    // Find the corresponding cell and test one of its bits
    return (s[n / 8] & (1 << n % 8)) > 0;
}

/* ------------------------ Sieve functions! -------------------------------- */

unsigned int find_next_prime(SET sieve, unsigned int x) {
    while (is_in_set(sieve, ++x));

    return x;
}

void init_seive(SET sieve) {
    unsigned int i, d;

    insert_in_set(sieve, 0);


    for (d = 2; d <= MAX_NR; d++) {
        if (!is_in_set(sieve, d)) {              // if d is prime
            for (i = d * d; i <= MAX_NR; i += d) { // we'll jump d steps and mark
                insert_in_set(sieve, i);
            }
        }
    }
}


int main() {
    unsigned int n, x;

    init_seive(my_set);

    scanf("%u", &n);
    while (n--) {
        scanf("%u", &x);
        printf("%u\n", find_next_prime(my_set, x));
    }

    return 0;
}

// 5 1 2009 10 7 92