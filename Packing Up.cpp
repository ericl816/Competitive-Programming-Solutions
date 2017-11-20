#include <bits/stdc++.h>
#define ll long long
#define MAXN 2000010
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

int N, L, last;
ll C[MAXN], x, DP[MAXN], psa[MAXN];

// Solution is same as APIO '10 P1

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> L;
	psa[0] = 0;
	for (int i=1; i<=N; i++) {
		cin >> C[i];
		psa[i] += psa[i - 1] + C[i];
	}
	memset(DP, INF, sizeof(DP));
	DP[0] = 0;
	for (int i=1; i<=N; i++) {
		for (int j=last; j<i; j++) {
			x = psa[i] - psa[j] + i - j - 1;
			if (DP[i] > DP[j] + pow((x - L), 2)) {
				DP[i] = DP[j] + pow((x - L), 2);
				last = j;
			}
		}
	}
	cout << DP[N] << endl;
	return 0;
}