#include <bits/stdc++.h>
#define ll long long
#define MAXN 35
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

int N, maxx, ans = INF;
vi a;
mii freq;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0, x; i<N; i++) {
		cin >> x;
		a.pb(x);
		freq[x]++;
	}
	for (int i=0; i<N; i++) maxx = max(maxx, freq[a[i]]);
	for (int i=0; i<N; i++) {
		if (freq[a[i]] == maxx) {
			ans = min(ans, a[i]);
		}
	}
	cout << ans << endl;
	return 0;
}