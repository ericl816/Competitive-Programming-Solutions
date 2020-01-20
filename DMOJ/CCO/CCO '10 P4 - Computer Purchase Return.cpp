#include <bits/stdc++.h>
#define ll long long
#define MAXN 3010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int T, N, c[MAXN], v[MAXN], t[MAXN], B, DP[MAXN][6];
vector<pii> parts[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> T >> N;
	for (int i=0; i<N; i++) {
		cin >> c[i] >> v[i] >> t[i];
		parts[t[i]].pb(mp(c[i], v[i]));
	}
	cin >> B;
	for (int i=1; i<=T; i++) {
		for (size_t j=0; j<parts[i].size(); j++) {
			pii &next = parts[i][j];
			int cost = next.f;
			int val = next.s;
			for (int k=0; k<=B; k++) if (cost <= k && ~DP[k - cost][i - 1]) DP[k][i] = max(DP[k][i], max(DP[k][i - 1], val + DP[k - cost][i - 1]));
		}
	}
	cout << DP[B][T] << "\n";
	return 0;
}