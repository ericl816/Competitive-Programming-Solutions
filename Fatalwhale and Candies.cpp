#include <bits/stdc++.h>
#define ll long long
#define MAXN 5000
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, P, s[MAXN], rem[MAXN], res;
ll psa[MAXN], DP[MAXN][2];
vi candies;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> P;
	for (int i=1; i<=N; i++) {
		cin >> s[i];
		rem[i] = s[i] % P;
	}
	DP[0][0] = 0;
	for (int i=1; i<P; i++) DP[i][0] = -INF;
	for (int i=1; i<=N; i++) {
		for (int j=0; j<P; j++) DP[j][1] = max(DP[j][0], DP[(j - rem[i] + P) % P][0] + s[i]);
		if (i ^ N) for (int j=0; j<P; j++) DP[j][0] = DP[j][1];
	}
	cout << DP[0][1] << "\n";
	for (int i=N, res = 0; i>=1; i--) {
		// res = 0;
		for (int j=0; j<P; j++) {
			if (DP[res][1] == DP[(j - rem[i] + P) % P][0] + s[i] && DP[res][1] ^ DP[res][0]) {
				res = (j - rem[i] + P) % P;
				candies.pb(i);
				goto outer;
			}
		}
		outer:
	  		for (int j=0; j<P; j++) DP[j][1] = DP[j][0];
	  		for (int j=0; j<P; j++) DP[(j - rem[i - 1] + P) % P][0] = DP[j][1] - s[i - 1];
	}
	cout << candies.size() << "\n";
	sort(candies.begin(), candies.end());
	for (auto i : candies) cout << i << " ";
	/*
		psa[i] += s[i] + psa[i - 1];
		if (psa[i] % P == 0) {
			temp ^= 1;
			candies.pb(mp(psa[i], i));
		}
		DP[i][temp] = max(DP[i][temp], psa[i]);
	}
	cout << DP[P][temp] << endl;
	cout << candies.size() << endl;
	for (pii next : candies) cout << next.s << " ";
	*/
	return 0;
}