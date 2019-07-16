#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
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
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

// Essentially 0-1 BFS but on states

int H, J, N, A, B;
int dist[MAXN][2];
bool vis[MAXN][2];
bool covered[MAXN];
deque<pii> dq;

// Consider moving to state (x, y) along a w-weight edge from distance d
// y = whether to drop or not
inline void Add_State (int x, int y, int d, int w) {
	x = min(H, x);
	if (!vis[x][y] && x >= 0 && (y || !covered[x]) && d + w < dist[x][y]) {
		vis[x][y] = 1;
		dist[x][y] = d + w;
		if (w) dq.pb(mp(x, y));
		else dq.push_front(mp(x, y));
	}
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> H >> J >> N;
	for (int i=0; i<N; i++) {
		cin >> A >> B;
		for (int j=A; j<=B; j++) covered[j] = 1;
	}
	memset(dist, INF, sizeof(dist));
	dist[0][0] = 0;
	vis[0][0] = 1;
	dq.pb(mp(0, 0));
	while (!dq.empty()) {
		pii curr = dq.front();
		dq.pop_front();
		if (vis[curr.f][curr.s]) continue;
		vis[curr.f][curr.s] = 1;
		int cost = dist[curr.f][curr.s];
		if (curr.f == H) {
			cout << cost << "\n";
			return 0;
		}
		if (curr.s) {
			// Continue dropping
			Add_State(curr.f - 1, 1, cost, 0);
			// Stop dropping
			Add_State(curr.f, 0, cost, 0);
		}
		else {
			// Jump
			Add_State(curr.f + J, 0, cost, 1);
			// Stop jumping
			Add_State(curr.f, 1, cost, 1);
		}
	}
	cout << -1 << "\n";
	return 0;
}

/*
12 5 2
2 4
10 10
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */