#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int K, N;
ll arr[MAXN], DP[MAXN];
bool flag;

inline ll Recur (int x) {
	if (~DP[x]) return DP[x];
	else if (x == 0) return arr[x];
	else if (x == 1) return max(arr[0], arr[x]);
	DP[x] = max(arr[x], Recur(x - 2) + arr[x - 1]);
	return DP[x];
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> N;
	if (N + 1 < K) {
		cout << "-1" << "\n";
		return 0;
	}
	memset(DP, -1, sizeof(DP));
	for (int i=0; i<N; i++) cin >> arr[i];
	if (K <= 2) cout << (max(arr[0], arr[1])) << "\n";
	else cout << (Recur(K - 1)) << "\n";
	return 0;
}