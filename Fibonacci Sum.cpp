#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

typedef struct {
  ull a, b;
} Matrix;
ull T, a, b, c, d, N, M;

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

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    scan(T);
    while (T--) {
        scan(N); scan(M);
        if (N == 0) printf("%llu\n", (((Fib(M + 2).a - 1LL) + MOD) % MOD));
        else printf("%llu\n", ((((Fib(M + 2).a - 1LL) + MOD) % MOD - ((Fib(N + 1).a - 1LL) + MOD) % MOD) + MOD) % MOD);
    }
}