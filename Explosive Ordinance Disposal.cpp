#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 40
#define MAXN 210
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

int N, A, B, C;
ll ans = INF;
queue<int> q;
bool vis[MAXN];
ll DP[MAXN][MAXM]; // DP[i][j] = min sum of labels in node i's subtree with label j
vector<pii> adj[MAXN];

inline ll GCD (ll a, ll b) {
	return b ? GCD(b, a % b) : a;
}

inline ll Solve (int node, int par, int idx) {
	ll &res = DP[node][idx];
	if (res) return res;
	ll val = idx * 1LL;
	for (size_t i=0; i<adj[node].size(); i++) {
		pii &next = adj[node][i];
		int nextnode = next.f;
		int label = next.s;
		if (nextnode == par) continue;
		ll num = INF;
		for (int j=1; j<=30; j++) if ((label == 0 && GCD(idx, j) == 1) || (label == 1 && GCD(idx, j) ^ 1)) num = min(num, Solve(nextnode, node, j));
		val = min(INF, num + val);
	}
	return res = val;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=1; i<N; i++) {
		cin >> A >> B >> C;
		adj[A].pb(mp(B, C));
		adj[B].pb(mp(A, C));
	}
	for (int i=1; i<=30; i++) ans = min(ans, Solve(1, -1, i));
	cout << ans << endl;
	return 0;
}