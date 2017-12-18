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

int N, A[15];
ll x[MAXN], DP[2][MAXN], psa[MAXN];
ll prod = 1, p = 1, dimension = 1;

// Question is very similar to that of Contest Practice, as both questions use a "N-dimensional prefix sum array"

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> A[i];
		prod *= A[i];
	}
	for (int i=0; i<prod; i++) {
		cin >> x[i];
		DP[(N + 1) & 1][i] = x[i];
	}
	// memset(DP, -1, sizeof(DP));
	for (int i=N; i; i--) {
		memset(DP[i & 1], 0, sizeof(DP[i & 1]));
		dimension *= A[i];
		for (int j=0; j<prod; j++) {
			DP[i & 1][j] += DP[(i & 1) ^ 1][j];
			// Check to see if it's not out of bounds
			if (j - p >= 0 && (j - p) / dimension == j / dimension) DP[i & 1][j] += DP[(i & 1) ^ 1][j - p];
			if (j + p < prod && (j + p) / dimension == j / dimension) DP[i & 1][j] += DP[(i & 1) ^ 1][j + p];
		}
		p *= A[i];
	}
	// Subtract to get original values for adjacent cells
	for (int i=0; i<prod; i++) cout << (DP[1][i] - x[i]) << endl;
	return 0;
}