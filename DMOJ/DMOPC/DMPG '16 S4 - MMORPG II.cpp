#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
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

int N;
int ability[MAXN];
bool basic[MAXN];
ll ans = 1;
ll subtree_size[MAXN], fac[MAXN], DP[MAXN];
vi adj[MAXN];

inline ll Fpow (ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	if (y & 1) return (x * (Fpow((x * x) % MOD, y >> 1) % MOD)) % MOD;
	return Fpow((x * x) % MOD, y >> 1) % MOD;
}

inline ll ModDiv (ll x, ll y) {
	return x * Fpow(y, MOD - 2) % MOD;
}

inline ll Choose (int n, int k) {
	return ModDiv(ModDiv(fac[n], fac[k]), fac[n - k]);
}

inline void DFS (int node, int prev) {
	subtree_size[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		DFS(next, node);
		subtree_size[node] += subtree_size[next];
	}
	int curr_size = subtree_size[node] - 1;
	ll res = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		res = (res * DP[next]) % MOD;
		res = (res * Choose(curr_size, subtree_size[next])) % MOD;
		curr_size -= subtree_size[next];
	}
	DP[node] = res;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int curr_size = N;
	fac[0] = 1;
	for (int i=1; i<=MAXN; i++) fac[i] = ((ll) fac[i - 1] * i) % MOD;
	for (int i=1; i<=N; i++) {
		cin >> ability[i];
		if (ability[i] == 0) basic[i] = 1;
		else adj[ability[i]].pb(i);
	}
	for (int i=1; i<=N; i++) {
		if (basic[i]) {
			DFS(i, -1);
			ans = (ans * DP[i]) % MOD;
			ans = (ans * Choose(curr_size, subtree_size[i]) % MOD) % MOD;
			curr_size -= subtree_size[i];
		}
	}
	cout << ans << "\n";
	return 0;
}