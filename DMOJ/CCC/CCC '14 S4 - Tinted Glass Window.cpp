#include <bits/stdc++.h>
#define ll long long
#define MAXN 2010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

struct Coor {
	int x, y1, y2, tint;

	bool operator < (const Coor &a) const {
		return x < a.x;
	}
};

int N, T;
ll area, sweep[MAXN];
vector<Coor> coor;
vi yseg;
mii compress;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> T;
	for (int i=0; i<N; i++) {
	  int x1, y1, x2, y2, t;
		cin >> x1 >> y1 >> x2 >> y2 >> t;
		coor.pb((Coor) {x1, y1, y2, t});
		coor.pb((Coor) {x2, y1, y2, -t});
		yseg.pb(y1);
		yseg.pb(y2);
	}
	sort(coor.begin(), coor.end());
	sort(yseg.begin(), yseg.end());
	
	// Remove duplicates
	yseg.erase(unique(yseg.begin(), yseg.end()), yseg.end());
	
	// Coordinate compress
	for (size_t i=0; i<yseg.size(); i++) compress[yseg[i]] = i;
	for (size_t i=0; i<coor.size(); i++) {
		for (int j=compress[coor[i].y1]; j<compress[coor[i].y2]; j++) sweep[j] += coor[i].tint;
		for (int j=0; j<yseg.size(); j++) if (sweep[j] >= T) area += (ll) (coor[i + 1].x - coor[i].x) * (yseg[j + 1] - yseg[j]);
	}
	cout << area << endl;
	return 0;
}