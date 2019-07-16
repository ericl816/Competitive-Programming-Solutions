#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
#define INF 0x3f3f3f3f
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

int L, n, depth, idx, cnt;
string recep[MAXN], par[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> L;
	while (L--) {
		cin >> n;
		for (int i=0; i<n; i++) cin >> recep[i];
		depth = 0;
		par[0] = recep[n - 1];
		idx = 0;
		for (int i=0; i<n; i++) {
			cnt = 0;
			while (cnt <= idx && par[cnt] != recep[i]) cnt++;
			par[cnt] = recep[i];
			idx = cnt;
			depth = max(depth, idx);
		}
		cout << (n * 10 - 20 * depth) << endl;
	}
	return 0;
}