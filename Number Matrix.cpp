#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, M;
int movex[4] = {0, 0, -1, 1}, movey[4] = {-1, 1, 0, 0};
int grid[MAXN][MAXN];
queue<pii> q;
bool vis[MAXN][MAXN];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) for (int j=0; j<N; j++) cin >> grid[i][j];
	for (int i=0; i<10; i++) {
		for (int j=i; j<10; j++) {
			for (int k=j; k<10; k++) {
				memset(vis, 0, sizeof(vis));
				for (int z=0; z<N; z++) {
					if (grid[0][z] == i || grid[0][z] == j || grid[0][z] == k) {
						vis[0][z] = 1;
						q.push(mp(0, z));
					}
				}
				while (!q.empty()) {
					pii curr = q.front();
					q.pop();
					if (curr.f == M - 1) {
						cout << i << " " << j << " " << k << "\n";
						return 0;
					}
					for (int l=0; l<4; l++) {
						int nextx = curr.f + movex[l], nexty = curr.s + movey[l];
						if (nextx < 0 || nexty < 0 || nextx >= M || nexty >= N || vis[nextx][nexty]) continue;
						if (grid[nextx][nexty] == i || grid[nextx][nexty] == j || grid[nextx][nexty] == k) {
							vis[nextx][nexty] = 1;
							q.push(mp(nextx, nexty));
						}
					}
				}
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */