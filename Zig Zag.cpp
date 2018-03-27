#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
#define MOD 1000000007
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
 * A sequence of integers from 1 to N is said to be zig zag 
 * if the sequence contains each integer exactly once and, 
 * indexing from one, every element at an even index is greater 
 * than the preceding one, and every element at an odd index is 
 * less than the preceding one.
 * For each test case, output the number of unique zig zag sequences
 */

int N;
ll DP[MAXN][2];

void Do_Test_Cases () {
	int z = 10;
	while (z--) {
		memset(DP, 0, sizeof(DP));
		DP[1][1] = 1;
		DP[0][0] = DP[0][1] = 0;
		cin >> N;
		for (int i=2; i<=N; i++) {
			for (int j=1; j<=i; j++) {
				if (!(i & 1)) {
					DP[j][0] = (DP[j - 1][1] + DP[j - 1][0]) % MOD;
					DP[j + 1][0] = DP[j][0];
				}
				else {
					DP[j][1] = ((DP[i][0] - (DP[j - 1][0] - DP[j - 1][1])) + MOD) % MOD;
					DP[j + 1][1] = DP[j][1];
				}
			}
		}
		cout << (DP[N][N & 1] % MOD) << "\n";
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	Do_Test_Cases();
	return 0;
}