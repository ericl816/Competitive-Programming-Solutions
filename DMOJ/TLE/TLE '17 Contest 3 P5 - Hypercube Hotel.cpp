#include <bits/stdc++.h>
#define ll long long
#define MAXN 2000010 // 5 ^ 9
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, A[15], idx, flag;
ll x[MAXN], DP[2][MAXN], psa[MAXN];
ll prod = 1, p = 1, dimension = 1;

int main () {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%d", &A[i]), prod *= A[i];
	for (int i=0; i<prod; i++) {
		scanf("%lld", &x[i]);
		DP[(N + 1) & 1][i] = x[i];
	}
	for (int i=N; i>=0; i--) {
		idx = i & 1;
		flag = idx ^ 1;
		memset(DP[idx], 0, sizeof(DP[idx]));
		dimension *= A[i];
		for (int j=0; j<prod; j++) {
			DP[idx][j] += DP[flag][j];
			// Check to see if the neighbours are not out of bounds
			if (j - p >= 0 && j / dimension == (j - p) / dimension) DP[idx][j] += DP[flag][j - p];
			if (j + p < prod && j / dimension == (j + p) / dimension) DP[idx][j] += DP[flag][j + p];
		}
		p *= A[i];
	}
	// Subtract to get original values for adjacent cells
	for (int i=0; i<prod; i++) printf("%lld\n", DP[1][i] - x[i]);
	return 0;
}