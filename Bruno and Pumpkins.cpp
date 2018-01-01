#include <bits/stdc++.h>
#define ll long long
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

int N, T, x, res, a, b, val, ans = INF;
vi coor;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> T;
	for (int i=0; i<N; i++) {
		cin >> x;
		coor.pb(x);
	}
	sort(coor.begin(), coor.end());
	for (int i=0; i<=N - T; i++) {
		a = coor[i];
		b = coor[i + T - 1];
		ans = min(ans, (min(abs(a), abs(b))) - a + b);
	}
	cout << ans << endl;
	return 0;
}