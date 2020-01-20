#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 500010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

int N, M, src, dest, S, P, idx, cnt;
int ans[MAXN], coins[MAXN], low[MAXN], DFN[MAXN], comp[MAXN];
vi adj[MAXN], DAG[MAXN];
bool processed[MAXN], endd[MAXN], vis[MAXN];
stack<int> SCC;
queue<int> q;
priority_queue<pii, vector<pii>, greater<pii> > pq;

inline void TarjansDFS (int node, int prev) {
    low[node] = DFN[node] = idx++;
    SCC.push(node);
    processed[node] = 1;
    for (auto &next : adj[node]) {
        if (DFN[next] == -1) {
            TarjansDFS(next, node);
            low[node] = min(low[node], low[next]);
        }
        else if (processed[next]) low[node] = min(low[node], DFN[next]);
    }
    if (low[node] == DFN[node]) {
        while (SCC.top() ^ node) {
            int curr = SCC.top();
            comp[curr] = cnt;
            processed[curr] = 0;
            SCC.pop();
        }
        int curr = SCC.top();
        comp[curr] = cnt++;
        processed[curr] = 0;
        SCC.pop();
    }
}

inline void Reconstruct_DAG () {
    for (int i=1; i<=N; i++) {
        for (auto j : adj[i]) {
          if (comp[i] ^ comp[j]) DAG[comp[i]].pb(comp[j]);
        }
        adj[i].clear();
    }
}

inline int Solve1 (int src) {
	ans[src] = coins[src];
	int maxx = 0;
	pq.push(mp(coins[src], src));
	while (!pq.empty()) {
		pii curr = pq.top();
		pq.pop();
		if (endd[curr.s]) maxx = max(maxx, curr.f);
		for (auto i : DAG[curr.s]) {
			if (ans[i] < curr.f + coins[i]) {
				ans[i] = curr.f + coins[i];
				pq.push(mp(ans[i], i));
			}
		}
	}
	return maxx;
}

inline int Solve2 (int src) {
	ans[src] = coins[src];
	int maxx = 0;
	vis[src] = 1;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = 0;
		if (endd[curr]) maxx = max(maxx, ans[curr]);
		for (auto i : DAG[curr]) {
			if (ans[i] >= ans[curr] + coins[i]) continue;
			ans[i] = ans[curr] + coins[i];
			if (!vis[i]) {
				vis[i] = 1;
				q.push(i);
			}
		}
	}
	return maxx;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("txt.in", "r", stdin);
	freopen("txt.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(DFN, -1, sizeof(DFN));
	memset(low, -1, sizeof(low));
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> src >> dest;
		adj[src].pb(dest);
	}
	for (int i=1; i<=N; i++) {
		if (DFN[i] == -1) TarjansDFS(i, -1);
	}
	Reconstruct_DAG();
	for (int i=1, x; i<=N; i++) {
		cin >> x;
		coins[comp[i]] += x;
	}
	cin >> S >> P;
	for (int i=1, x; i<=P; i++) {
		cin >> x;
		endd[comp[x]] = 1;
	}
	cout << Solve2(comp[S]) << "\n";
	return 0;
}

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */