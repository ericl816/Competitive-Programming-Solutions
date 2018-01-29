#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
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

int n, a[MAXN], ans = -INF;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j*j<=a[i]; j++) {
			if (j * j == a[i]) a[i] = -INF;
		}
		ans = max(ans, a[i]);
	}
	cout << ans << endl;
	return 0;
}