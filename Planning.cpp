#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

ull N;
const ull MOD = 998244353;

ull PowMod (ull a, ull b, ull MOD) {
	ull val = 1;
	while (b) {
		if (b & 1) val = (val * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return val;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	cout << ((PowMod(2, N * (N + 1) >> 1, MOD) + MOD) % MOD) << endl;
	return 0;
}