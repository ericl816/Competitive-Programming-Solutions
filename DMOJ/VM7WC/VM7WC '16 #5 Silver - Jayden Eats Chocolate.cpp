#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

int N, X, Y, Z;
int DP[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X >> Y >> Z;
	for (int i=0; i<=N; i++) {
	  if (DP[i] == 0 && i) continue;
	  if (i + X <= N) DP[i + X] = max(DP[i + X], DP[i] + 1);
	  if (i + Y <= N) DP[i + Y] = max(DP[i + Y], DP[i] + 1);
	  if (i + Z <= N) DP[i + Z] = max(DP[i + Z], DP[i] + 1);
	}
	cout << DP[N] << endl;
	return 0;
}