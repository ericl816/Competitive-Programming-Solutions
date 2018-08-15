#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1010
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPS 1e=9
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

int T, N, cnt;
string s;
char grid[3][MAXN];
ll ans;

int main () {
	// #ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	// #endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int z=1; z<=T; z++) {
		cin >> N;
		for (int i=0; i<3; i++) {
			cin >> s;
			for (int j=0; j<N; j++) grid[i][j] = s[j];
		}
		cout << "Case #" << z << ": ";
		if (N & 1) cout << 0 << "\n";
		else {
			if (grid[0][0] == '#' || grid[2][N - 1] == '#' || grid[1][0] == '#' || grid[1][N - 1] == '#') cout << 0 << "\n";
			else {
				ans = 1LL;
				for (int i=0; i<N / 2 - 1; i++) {
					int ind = i * 2 + 1;
					if (grid[1][ind] == '#' || grid[1][ind + 1] == '#') ans = 0;
					else {
						bool flag1 = (grid[0][ind] == '.' && grid[0][ind + 1] == '.');
						bool flag2 = (grid[2][ind] == '.' && grid[2][ind + 1] == '.');
						cnt = (flag1 + flag2);
						ans *= cnt;
					}
					ans %= MOD;
				}
				cout << ((ans + MOD) % MOD) << "\n";
			}
		}
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