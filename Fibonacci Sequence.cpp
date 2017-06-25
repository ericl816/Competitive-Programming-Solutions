#include<bits/stdc++.h>
#define ull unsigned long long
#define MOD 1000000007
typedef struct {
  ull a, b;
} Matrix;
ull N, a, b, c, d;

Matrix Fib (ull n) {
    if (!n) return (Matrix) { 0, 1 };
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
    scanf("%llu", &N);
    printf("%llu\n", Fib(N).a);
}
