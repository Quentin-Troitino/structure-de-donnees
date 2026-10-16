
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


bool is_prime_naive(int k) {
    for (int d = 2; d * d <= k; ++d) {
        if (k % d == 0) return false;
    }
    return true;
}

int count_primes_naive(int n) {
    int count = 0;
    for (int k = 2; k < n; ++k) {
        if (is_prime_naive(k)) count++;
    }
    return count;
}

int count_primes_sieve(int n) {
    bool *is_prime = malloc(n * sizeof(bool));

    for (int i = 0; i < n; ++i) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;

    for (int p = 2; p * p < n; ++p) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple < n; multiple += p) {
                is_prime[multiple] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (is_prime[i]) count++;
    }

    free(is_prime);
    return count;
}

int main(void) {
    int n = 1000000;

    clock_t start_naive = clock();
    int count_n = count_primes_naive(n);
    clock_t end_naive = clock();

    clock_t start_sieve = clock();
    int count_s = count_primes_sieve(n);
    clock_t end_sieve = clock();

    printf("N = %d\n", n);
    printf("Naif   : %d premiers en %f s\n", count_n, (double)(end_naive - start_naive) / CLOCKS_PER_SEC);
    printf("Crible : %d premiers en %f s\n", count_s, (double)(end_sieve - start_sieve) / CLOCKS_PER_SEC);

    return 0;
}