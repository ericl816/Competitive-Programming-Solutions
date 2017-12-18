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

int N, a[MAXN], idx[MAXN], DP[MAXN], len;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	memset(idx, -1, sizeof(idx));
	for (int i=0; i<N; i++) {
		cin >> a[i];
		DP[i] = 1;
		for (int j=0; a[i]; j++, a[i] >>= 1) {
			if (a[i] & 1) {
				if (~idx[j]) DP[i] = max(DP[i], DP[idx[j]] + 1);
				idx[j] = i;
			}
		}
		len = max(len, DP[i]);
	}
	cout << len << endl;
	return 0;
}