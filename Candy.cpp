#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 610
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

int N, k, c, res1, res2;
int DP[2][MAXN];
vi candies;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> k >> c;
		while (k--) candies.pb(c);
	}
	for (size_t i=0; i<candies.size(); i++) {
		for (int j=MAXN - 1; j>=0; j--) {
			int val1 = j + candies[i], val2 = abs(j - candies[i]);
			// cout << val1 << " " << val2 << "\n";
			if (i == 0) DP[i & 1][j] = min(val1, val2);
			else {
				if (val1 >= MAXN) res1 = INF;
				else res1 = DP[(i & 1) ^ 1][val1];
				res2 = DP[(i & 1) ^ 1][val2];
				DP[i & 1][j] = min(res1, res2);
			}
			// cout << res1 << " " << res2 << "\n";
		}
	}
	cout << DP[(candies.size() - 1) & 1][0] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */