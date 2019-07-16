#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

/* 
 * Solution uses Miller-Rabin algorithm (Miller-Rabin primality test) to check if very large numbers are prime
 * See https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test for more details
 */

inline ull mulMod (ull a, ull b, ull mod) {
    ull x = 0, y = a % mod;
    while (b) {
        if (b & 1) x = (x + y) % mod;
        y = (y << 1) % mod;
        b >>= 1;
    }
    return x % mod;
}

inline ull powMod(ull base, ull pow, ull mod) {
    ull x = 1, y = base;
    while (pow) {
        if (pow & 1) x = mulMod(x, y, mod);
        y = mulMod(y, y, mod);
        pow >>= 1;
    }
    return x % mod;
}

inline bool isPrime(ull n, int iterations) {
    if (n < 2 || (n != 2 && n % 2 == 0)) return 0;
    ull s = n - 1;
    while (s % 2 == 0) s /= 2;
    srand(time(0));
    for (int i=0; i<iterations; i++) {
        ull temp = s, r = powMod(rand() % (n - 1) + 1, temp, n);
        while (temp != n - 1 && r != 1 && r != n - 1) {
            r = mulMod(r, r, n);
            temp *= 2;
        }
        if (r != n - 1 && temp % 2 == 0) return 0;
    }
    return 1;
}

ull N;

int main() {
    scanf("%llu", &N);
    while (!isPrime(N, 5)) N++;
    printf("%llu\n", N);
    return 0;
}