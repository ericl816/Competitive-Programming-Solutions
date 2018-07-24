#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
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

int t;
ull N;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scan(t);
	while (t--) {
    	scan(N);
    	printf("%s\n", isPrime(N, 5) ? "YES" : "NO");
    }
    return 0;
}