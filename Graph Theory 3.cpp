#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 40010
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

struct Network {
	struct Edge {
		int dest, cost, next;
		Edge (int dest, int cost, int next) : dest(dest), cost(cost), next(next) {
		}
	};

	int N, src, sink;
	vector<int> last;
	vector<bool> vis;
	vector<Edge> e;

	Network (int N, int src, int sink) : N(N), src(src), sink(sink), last(N), vis(N) {
		fill(last.begin(), last.end(), -1);
	}

	void addEdge (int x, int y, int xy, int yx) {
		e.push_back(Edge(y, xy, last[x]));
		last[x] = e.size() - 1;
		e.push_back(Edge(x, yx, last[y]));
		last[y] = e.size() - 1;
	}

	int dfs (int curr, int flow) {
		vis[curr] = 1;

		if (curr == sink) {
			return flow;
		}

		for (int i = last[curr]; i != -1; i = e[i].next) {
			if (e[i].cost > 0 && !vis[e[i].dest]) {
				int res = dfs(e[i].dest, min(flow, e[i].cost));
				if (res > 0) {
					e[i].cost -= res;
					e[i ^ 1].cost += res;
					return res;
				}
			}
		}
		return 0;
	}

	int getFlow () {
		int res = 0, curr;
		fill(vis.begin(), vis.end(), 0);
		while ((curr = dfs(src, INF))) {
			res += curr;
			fill(vis.begin(), vis.end(), 0);
		}
		return res;
	}
};

int N, M, A, B, a, b, res;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> A >> B;
	Network nf(MAXN, A, B);
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		nf.addEdge(a, b, 1, 0);
	}
	res = nf.getFlow();
	// No path from src to sink
	if (res == 0) cout << "NO PATH\n";
	// Path from src to sink, but no multiple paths
	else if (res == 1) cout << "NO\n";
	// Multiple paths from src to sink
	else cout << "YES\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */