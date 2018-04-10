#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 15
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

int N, G, idx, ans;
umii sim;
bool grid[MAXN][MAXN];
string color;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> G;
	for (int i=0; i<G; i++) {
		for (int j=0; j<N; j++) {
			cin >> color;
			for (int k=0; k<N; k++) {
				grid[j][k] = color[k] == 'R';
			}
		}
		// Flip the colour in every cell
		for (int j=0; j<N - 1; j++) {
			for (int k=0; k<N - 1; k++) {
				if (grid[j][k]) {
					grid[j][k] ^= 1;
					grid[j + 1][k] ^= 1;
					grid[j][k + 1] ^= 1;
					grid[j + 1][k + 1] ^= 1;
				}
			}
		}
		idx = 0;
		for (int j=0; j<N; j++) {
			idx = (idx << 1) | grid[j][N - 1]; // Same as: idx = (idx << 1) + grid[j][N - 1];
			idx = (idx << 1) | grid[N - 1][j]; // Same as: idx = (idx << 1) + grid[N - 1][j];
		}
		ans += sim[idx]++;
	}
	cout << ans << endl;
	return 0;
}