#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

ull mulMod (ull a, ull b, ull mod) {
    ull x = 0, y = a % mod;
    for (; b > 0; b /= 2) {
        if (b % 2 == 1) x = (x + y) % mod;
        y = (y * 2) % mod;
    }
    return x % mod;
}

ull powMod(ull base, ull pow, ull mod) {
    ull x = 1, y = base;
    for (; pow > 0; pow /= 2) {
        if (pow % 2 == 1) x = mulMod(x, y, mod);
        y = mulMod(y, y, mod);
    }
    return x % mod;
}

inline bool isPrime(ull n, int iterations) {
    if (n < 2 || (n != 2 && n % 2 == 0)) return 0;
    ull s = n - 1;
    while (s % 2 == 0) s /= 2;
    srand(time(0));
    for (int i = 0; i < iterations; i++) {
        ull temp = s, r = powMod(rand() % (n - 1) + 1, temp, n);
        while (temp != n - 1 && r != 1 && r != n - 1) {
            r = mulMod(r, r, n);
            temp *= 2;
        }
        if (r != n - 1 && temp % 2 == 0) return 0;
    }
    return 1;
}

int T;
ull N;

int main() {
    scanf("%llu", &T);
    while (T--) {
     scanf("%llu", &N);
     printf("%s\n", isPrime(N, 10) ? "PRIME" : "NOT");
    }
    return 0;
}