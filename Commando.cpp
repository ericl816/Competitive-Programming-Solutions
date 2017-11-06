#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

ll n, a, b, c, x[MAXN], psa[MAXN], DP[MAXN], eff;

inline ll Calc (ll x) {
	return a * pow(x, 2) + b * x + c;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b >> c;
	memset(DP, -INF, sizeof(DP));
	DP[0] = 0;
	ll prev = 0;
	for (int i=1; i<=n; i++) {
		cin >> x[i];
		psa[i] += psa[i - 1] + x[i];
		for (int j=prev; j<i; j++) {
			eff = Calc(psa[i] - psa[j]) + DP[j];
			if (eff > DP[i]) {
				DP[i] = eff;
				prev = j;
			}
		}
	}
	cout << DP[n] << "\n";
	return 0;
}