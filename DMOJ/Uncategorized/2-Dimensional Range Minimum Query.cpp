#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 10
#define MAXN 1010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>w
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

int N;
int segmin[MAXM][MAXN][MAXM][MAXN];

void init (vector<vi> arr) {
	N = arr.size();
	int LOGN = 32 - __builtin_clz(N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			segmin[0][i][0][j] = arr[i][j];
		}
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<LOGN - 1; j++) {
			for (int k=0; k + (1 << j)<N; k++) {
				segmin[0][i][j + 1][k] = min(segmin[0][i][j][k], segmin[0][i][j][k + (1 << j)]);
			}
		}
	}
	for (int i=0; i<LOGN - 1; i++) {
		for (int j=0; j + (1 << i)<N; j++) {
			for (int k=0; k<LOGN; k++) {
				for (int l=0; l<N; l++) {
					segmin[i + 1][j][k][l] = min(segmin[i][j][k][l], segmin[i][j + (1 << i)][k][l]);
				}
			}
		}
	}
}

int query (int a, int b, int c, int d) {
	int SIZE1 = log2(b - a + 1), SIZE2 = log2(d - c + 1);
	return min(min(segmin[SIZE1][a][SIZE2][c], segmin[SIZE1][a][SIZE2][d - (1 << SIZE2) + 1]), min(segmin[SIZE1][b - (1 << SIZE1) + 1][SIZE2][c], segmin[SIZE1][b - (1 << SIZE1) + 1][SIZE2][d - (1 << SIZE2) + 1]));
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<vi> v{ {1, 2}, {3, 4} };
	init(v);
	D("%d\n", query(0, 1, 0, 1));
	D("%d\n", query(1, 1, 0, 1));
	D("%d\n", query(0, 0, 1, 1));
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