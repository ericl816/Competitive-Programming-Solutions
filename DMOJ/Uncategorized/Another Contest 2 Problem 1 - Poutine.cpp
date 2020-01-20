#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 110
#define INF 0x3f3f3f3f3f3f3f3f
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

int N, Q, w, s, t, d;
ll dist[MAXN][MAXN][MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(dist, INF, sizeof(dist));
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			cin >> w;
			if (i ^ j && w == 0) continue;
			else dist[1][i][j] = w;
		}
	}
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			for (int k=1; k<=N; k++) {
				if (dist[1][j][k] > dist[1][i][k] + dist[1][j][i]) dist[1][j][k] = dist[1][i][k] + dist[1][j][i];
			}
		}
	}
	for (int days=2; days<=N; days++) {
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=N; j++) {
				for (int k=1; k<=N; k++) {
					if (dist[days][j][k] > max(dist[days - 1][j][i], dist[1][i][k])) {
						dist[days][j][k] = max(dist[days - 1][j][i], dist[1][i][k]);
					}
				}
			}
		}
	}
	cin >> Q;
	while (Q--) {
		cin >> s >> t >> d;
		cout << (dist[d][s][t] == INF ? 0 : dist[d][s][t]) << "\n";
	}
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */