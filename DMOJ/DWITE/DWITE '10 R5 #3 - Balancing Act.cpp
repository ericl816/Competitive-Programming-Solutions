#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 30010
#define MAXN 35
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

int T = 5, N, sum;
int arr[MAXN];
bool DP[MAXN][MAXM];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (T--) {
		cin >> N;
		int bit1 = -1, bit2 = -1, minndiff = INF, sum = 0;
		memset(DP, 0, sizeof(DP));
		for (int i=0; i<N; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		for (int i=0; i<=N; i++) DP[i][0] = 1;
		for (int i=1; i<=sum; i++) DP[0][i] = 0;
		for (int i=1; i<=N; i++) {
			for (int j=1; j<=sum; j++) {
				DP[i][j] = DP[i - 1][j];
				if (j >= arr[i - 1]) DP[i][j] |= DP[i - 1][j - arr[i - 1]];
			}
		}
		for (int i=sum / 2; i>=0; i--) {
			if (DP[N][i]) {
				minndiff = sum - i * 2;
				break;
			}
		}
		cout << minndiff << "\n";
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