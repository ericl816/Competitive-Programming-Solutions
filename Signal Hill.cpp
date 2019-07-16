#include <bits/stdc++.h>
#define ll long long
#define MAXN 510
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

bool adj[MAXN][MAXN];
vector<pair<pii, int>> beacons;
int B, Q, x, y, r, a, b;

inline bool Dist (const int &x, const int &y, const int &r) {
	return x * x + y * y <= r * r;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> B >> Q;
	for (int i=0; i<B; i++) {
		cin >> x >> y >> r;
		beacons.pb(mp(mp(x, y), r));
	}
	for (int i=0; i<B; i++) {
		for (int j=0; j<B; j++) {
			adj[i][j] = Dist(beacons[i].f.f - beacons[j].f.f, beacons[i].f.s - beacons[j].f.s, beacons[i].s);
		}
	}
	for (int i=0; i<B; i++) {
		for (int j=0; j<B; j++) {
			for (int k=0; k<B; k++) {
				adj[j][k] |= adj[j][i] && adj[i][k];
			}
		}
	}
	for (int i=0; i<Q; i++) {
		cin >> a >> b;
		cout << (adj[--a][--b] ? "YES" : "NO") << endl;
	}
	return 0;
}