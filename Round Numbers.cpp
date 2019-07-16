#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 35
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

int K;
ll DP[MAXN][MAXN][MAXN];
int digit[MAXN];

/*
 * @param x = # of 0s
 * @param y = # of 1s
 * @param limit = whether current digits range isn't restricted
 * @param zero = whether there is a 1 in front
 */
inline ll DFS (int ind, int x, int y, bool zero, bool limit) {
	if (ind == 0) return (zero && x >= y) || !zero;
	ll &res = DP[ind][x][y];
	if (limit && ~res) return res;
	int maxx = limit ? 1 : digit[ind];
	ll val = 0LL;
	for (int i=0; i<=maxx; i++) {
		if (!zero && i == 0) val += DFS(ind - 1, x, y, 0, limit || i < maxx);
		else val += DFS(ind - 1, x - i + 1, y + i, zero || i, limit || i < maxx);
	}
	if (limit && zero) res = val;
	return val;
}

inline ll Query (ll k) {
	if (k < 0) return 0LL;
    int ind = 0;
    while (k) {
        digit[++ind] = k % 2;
        k >>= 1;
    }
    return DFS(ind, 0, 0, 0, 0);
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(DP, -1, sizeof(DP));
	cin >> K;
	cout << "There are " << Query(K) - Query(0) << " round numbers less than or equal to " << K << ".\n";
	return 0;
}

// 19489

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */