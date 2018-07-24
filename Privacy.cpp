#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
#define INF 0x3f3f3f3f
#define MOD 10007
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

int N, K;
int C[410];
int DP[410][410]; // DP[i][j] where i = number of cows, j = number of troughs

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for (int i=0; i<N; i++) cin >> C[i];
	memset(DP, INF, sizeof(DP));
	DP[0][0] = 0;
	for (int i=0; i<N; i++) {
		for (int j=i; j<N; j++) {
			int len = j - i + 1;
			int val = 0; // Num treats
			for (int k=i; k<=j; k++) val += max(0, len - C[k] - 1);
			for (int k=0; k<=K; k++) DP[j + 1][k + 1] = min(DP[j + 1][k + 1], DP[i][k] + val);
		}
	}
	cout << DP[N][K + 1] << endl; // Since there are's K + 1 troughs in total
	return 0;
}