#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

ull N;

inline ull FPow (ull x, ull y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	if (y & 1) return x * FPow((x * x) % MOD, y >> 1) % MOD;
	return FPow((x * x) % MOD, y >> 1) % MOD;
}

inline ull Calc (ull x) {
	return (ull) (FPow(2, x + 3) - 5 + MOD) % MOD;
}

int main () {
	scanf("%llu", &N);
	return 0 * printf("%llu\n", Calc(N));
}