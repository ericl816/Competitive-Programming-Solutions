#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 5010
#define MAXN 100010
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

struct Event {
	int r, c, val;
};

struct Queries {
	char ch;
	int r1, r2, c1, c2, t, idx;

	inline bool operator < (const Queries &q) const {
		return t < q.t;
	}
};

int BIT[MAXM][MAXM];

inline int Query (int x, int y) {
    int sum = 0;
    for (; x>0; x -= x & -x) {
        for (int y1=y; y1>0; y1 -= y1 & -y1) {
            sum += BIT[x][y1];
        }
    }
    return sum;
}


inline void Update (int x, int y, int val) {
    for (; x<MAXM; x += x & -x) {
        for (int y1=y; y1<MAXM; y1 += y1 & -y1) {
            BIT[x][y1] += val;
        }
    }
}

inline int Query (int x1, int y1, int x2, int y2) {
    return Query(x2, y2) - Query(x2, y1 - 1) - Query(x1 - 1, y2) + Query(x1 - 1, y1 - 1);
}

int N, M, Q, R, C, L, D, a, b, c, d, t;
char op;
map<int, vector<Event> > snowflakes;
vector<Queries> queries;
int ans[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> Q;
	for (int i=0; i<M; i++) {
		cin >> R >> C >> L >> D;
		snowflakes[L].pb((Event) {R, C, 1});
		snowflakes[D].pb((Event) {R, C, -1});
	}
	for (int i=0; i<Q; i++) {
		cin >> op;
		if (op == 'R') {
			cin >> a >> b >> t;
			queries.pb((Queries) {op, a, b, 0, 0, t, i});
		}
		else if (op == 'C') {
			cin >> a >> b >> t;
			queries.pb((Queries) {op, a, b, 0, 0, t, i});
		}
		else {
			cin >> a >> b >> c >> d >> t;
			queries.pb((Queries) {op, a, b, c, d, t, i});
		}
	}
	sort(allof(queries));
	map<int, vector<Event> >::iterator it=snowflakes.begin();
	for (auto &i : queries) {
		// D("%c %d %d %d %d\n", i.ch, i.r1, i.r2, i.c1, i.c2, i.t, i.idx);
		while (it!=snowflakes.end() && it->f <= i.t) {
			for (auto j : it->s) {
				// D("%c %d %d %d\n", 'D', j.r, j.c, j.val);
				Update(j.r, j.c, j.val);
			}
			it++;
		}
		if (i.ch == 'R') ans[i.idx] = Query(i.r1, 0, i.r2, 5000);
		else if (i.ch == 'C') ans[i.idx] = Query(0, i.r1, 5000, i.r2);
		// Use inclusion-exclusion principle
		else ans[i.idx] = Query(i.r1, 0, i.r2, 5000) + Query(0, i.c1, 5000, i.c2) - Query(i.r1, i.c1, i.r2, i.c2);
	}
	for (int i=0; i<Q; i++) cout << ans[i] << "\n";
	return 0;
}

/*
6 7 3
2 3 3 9
2 4 4 5
4 4 5 10
4 4 2 8
2 3 1 5
4 5 9 10
2 4 7 9
V 2 3 5 5 7
R 3 4 4
C 4 5 4

Ans:
2
1
2
*/

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */