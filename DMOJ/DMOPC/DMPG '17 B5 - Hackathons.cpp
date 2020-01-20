#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
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

int N, Q, T, maxx;
int t[MAXN], w[MAXN], DP[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> t[i] >> w[i];
		DP[t[i]] = max(DP[t[i]], w[i]);
	}
	for (int i=1; i<MAXN; i++) DP[i] = max(DP[i], DP[i - 1]);
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> T;
		cout << DP[T] << "\n";
	}
	return 0;
}