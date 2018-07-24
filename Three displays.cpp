#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 3010
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

/*
 * Codeforces Round 485 Division 2 Problem C.
 * There are n displays placed along a road, and the i -th of them can display a text with font sizes i only. Maria Stepanovna wants to rent such three displays with indices 
 * i < j < k
 * that the font size increases if you move along the road in a particular direction. Namely, the condition 
 * si < sj < sk should be held.
 * The rent cost is for the i-th display is ci.
 * Please determine the smallest cost Maria Stepanovna should pay.
 */ 

int n;
int s[MAXN], c[MAXN];
int DP[MAXN][4];
ll ans = INF;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> s[i];
	for (int i=1; i<=n; i++) cin >> c[i];
	memset(DP, INF, sizeof(DP));
	for (int i=1; i<=n; i++) DP[i][1] = c[i];
	for (int i=2; i<=3; i++) {
		for (int j=1; j<=n; j++) {
			for (int k=1; k<=j - 1; k++) {
				if (s[j] > s[k]) {
					DP[j][i] = min(DP[j][i], DP[k][i - 1] + c[j]);
				}
			}
		}
	}
	for (int i=1; i<=n; i++) ans = min(ans, DP[i][3]);
	cout << (ans == INF ? -1 : ans) << "\n";
	return 0;
}