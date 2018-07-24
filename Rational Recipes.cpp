#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
#define INF 0x3f3f3f3f
#define MOD 10007
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

int N;
ll ans;
ll F[110];

inline ll Calc (int res) {
	ll val = 1;
	for (int i=1; i<N; i++) val = (val * ((F[i] / res) % MOD)) % MOD;
	return val;
}

int main () {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> F[i];
	for (int i=1; i * i<=F[0]; i++) {
		if (F[0] % i == 0) {
			ans = (ans + (Calc(i) % MOD)) % MOD;
			// Corner case of when i^2 = F[0]
			if (F[0] / i != i) ans = (ans + (Calc(F[0] / i) % MOD)) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}