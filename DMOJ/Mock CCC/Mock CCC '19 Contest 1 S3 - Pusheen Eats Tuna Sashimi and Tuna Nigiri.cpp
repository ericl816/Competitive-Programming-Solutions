#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXQ 30
#define MAXM 15
#define MAXN 110
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

int X, Y, N, x, y, xs, ys, xe, ye;
int dist[MAXN][MAXN][MAXQ][MAXQ];
bool lattice[MAXN][MAXN];
bool vis[MAXN][MAXN][MAXQ][MAXQ];
int movex[5] = {0, 0, 0, -1, 1};
int movey[5] = {0, -1, 1, 0, 0};
queue<pair<pii, pii> > q;

inline bool Valid (int x, int y, int vx, int vy) {
	return x >= 0 && x <= X && y >= 0 && y <= Y && vx > -MAXM && vx < MAXM && vy > -MAXM && vy < MAXM;
}

inline bool isLattice (int x, int y, int x1, int y1) {
	if (x == x1 && y == y1) return lattice[x1][y1];
	int diffx = abs(x - x1), diffy = abs(y - y1);
	int gcd = GCD(diffx, diffy), horiz = (x1 - x) / gcd, vert = (y1 - y) / gcd;
	while (x ^ x1 || y ^ y1) {
	    if (lattice[x][y]) return 1;
	    x += horiz;
	    y += vert;
	}
	return lattice[x][y];
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> X >> Y >> N >> xs >> ys >> xe >> ye;
	memset(dist, INF, sizeof(dist));
	dist[xs][ys][MAXM][MAXM] = 0;
	vis[xs][ys][MAXM][MAXM] = 1;
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		lattice[x][y] = 1;
	}
	q.push(mp(mp(xs, ys), mp(0, 0)));
	while (!q.empty()) {
		pair<pii, pii> curr = q.front(); q.pop();
		int currx = curr.f.f, curry = curr.f.s, currvx = curr.s.f, currvy = curr.s.s;
		for (int i=0; i<5; i++) {
			int vx = currvx + movex[i], vy = currvy + movey[i], x = currx + vx, y = curry + vy;
			if (!Valid(x, y, vx, vy) || isLattice(currx, curry, x, y) || vis[x][y][vx + MAXM][vy + MAXM] || dist[currx][curry][currvx + MAXM][currvy + MAXM] == INF) continue;
			dist[x][y][vx + MAXM][vy + MAXM] = dist[currx][curry][currvx + MAXM][currvy + MAXM] + 1;
			vis[x][y][vx + MAXM][vy + MAXM] = 1;
			q.push(mp(mp(x, y), mp(vx, vy)));
		}
	}
	if (!vis[xe][ye][MAXM][MAXM]) {
		cout << -1 << "\n";
		return 0;
	}
	cout << (dist[xe][ye][MAXM][MAXM] == INF ? -1 : dist[xe][ye][MAXM][MAXM]) << "\n";
	return 0;
}

/*
1 0 0
0 0
1 0
Ans: 2
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */