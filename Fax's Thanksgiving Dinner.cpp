#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1000010
#define MAXN 1010
#define INF 0x3f3f3f3f
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

int N, C;
int n[MAXN], c[MAXN];
bool isPrime[MAXM];
bool flag = 1;
vi primes;
set<int> cuts;

inline void Sieve () {
	memset(isPrime, 1, sizeof(isPrime));
	for (ll i=2; i<=1000001; i++) {
		if (isPrime[i]) {
			for (ll j=i * i; j<1000001; j += i) isPrime[j] = 0;
			primes.pb(i);
		}
	}
}

int main () {
	Sieve();
    scan(N); scan(C);
	for (int i=0; i<C; i++) {
		scan(c[i]);
		for (int j=0; j<primes.size(); j++) {
			if (c[i] % primes[j] == 0) {
				cuts.insert(primes[j]);
				while (c[i] % primes[j] == 0) c[i] /= primes[j];
			}
			if (c[i] == 1) break;
		}
	}
	for (int i=0; i<N; i++) {
		scan(n[i]);
		for (int j=0; j<primes.size(); j++) {
			if (n[i] % primes[j] == 0) {
				if (!cuts.count(primes[j])) return !printf("N\n");
				while (n[i] % primes[j] == 0) n[i] /= primes[j];
			}
			if (n[i] == 1) break;
		}
	}
	return !printf("Y\n");
}