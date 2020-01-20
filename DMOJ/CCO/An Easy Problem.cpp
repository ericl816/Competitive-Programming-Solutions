#include <bits/stdc++.h>
#define MAXM 55
#define MAXN 100010
#define INF 0x3f3f3f3f
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, cnt, ans;
int a[MAXN], DP[MAXM];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> a[i];
	for (int i=0; i<N; i++) {
		cnt = 1;
		for (int j=0; j<ceil(log(1e9)/log(2)); j++) if (a[i] & (1 << j)) cnt = max(cnt, DP[j] + 1);
		for (int j=0; j<ceil(log(1e9)/log(2)); j++) if (a[i] & (1 << j)) DP[j] = max(DP[j], cnt);
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}