#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

int N, idx, val1, val2;
ll a[MAXN];
vi ans;
bool flag;

inline void Toggle (int x, int y) {
	for (int i=x; i<y; i++) a[i] ^= 1;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> a[i];
	idx = (N % 3 + 1) & 1;
	for (idx; idx<N; idx++) {
		val1 = max(0, idx - 1);
		val2 = min(N, idx + 2);
		if (a[val1]) { // Occupied tower here
			Toggle(val1, val2); // Toggle occupied tower
			ans.pb(idx);
		}
	}
	val1 = val2 = 0;
	if (a[N - 1]) { // If last tower is occupied
		idx = N - 3;
		for (idx; idx>=0; idx-=3) {
			val1 = max(0, idx - 1);
			val2 = min(N, idx + 2);
			Toggle(val1, val2); // Toggle occupied tower
			ans.pb(idx);
		}
		idx = (N % 3 + 1) & 1;
		val1 = val2 = 0;
		for (idx; idx<N; idx+=3) {
			val1 = max(0, idx - 1);
			val2 = min(N, idx + 2);
			Toggle(val1, val2); // Toggle occupied tower
			ans.pb(idx);
		}
	}
	for (int i=0; i<N; i++) flag ^= a[i];
	assert(!flag);
	cout << ans.size() << endl;
	for (int &next : ans) cout << next + 1 << endl;
	return 0;
}