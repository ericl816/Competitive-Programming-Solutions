#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ull unsigned long long
#define MOD 1000000007

typedef struct {
  ull a, b;
} Matrix;
ull N, a, b, c, d;

Matrix Fib (ull n) {
    if (!n) return (Matrix) {0, 1};
    else {
        Matrix ret = Fib (n >> 1);
        a = ret.a; 
        b = ret.b;
        c = (ull) (a * (b * 2ull % MOD - a + MOD) % MOD);
        d = (ull) (a * a % MOD + b * b % MOD);
        if (!(n & 1)) return (Matrix) { c % MOD, d % MOD };
        else if (n & 1) return (Matrix) { d % MOD, c % MOD + d % MOD};
    }
}

int main() {
    scan(N);
    return !printf("%llu\n", Fib(N).a);
}