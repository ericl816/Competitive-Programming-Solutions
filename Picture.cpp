#include <bits/stdc++.h>
#define ll long long
#define MAXN 5010
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

struct Coor {
	int x, y1, y2, val;

	bool operator < (const Coor &e) const {
		if (x == e.x) return val < e.val;
		return x < e.x;
	}
};

bool Cmp (Coor &a, Coor &b) {
  if (a.x ^ b.x) return a.x < b.x;
  return a.val > b.val;
}

int N, idx1, idx2, val1[MAXN], val2[MAXN], per;
vi xseg, yseg;
vector<Coor> xcoor, ycoor;
mii compressx, compressy;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		xseg.pb(x1);
		xseg.pb(x2);
		yseg.pb(y1);
		yseg.pb(y2);
		xcoor.pb((Coor) {y1, x1, x2, 1});
		xcoor.pb((Coor) {y2, x1, x2, -1});
		ycoor.pb((Coor) {x1, y1, y2, 1});
		ycoor.pb((Coor) {x2, y1, y2, -1});
	}
	sort(xseg.begin(), xseg.end());
	sort(yseg.begin(), yseg.end());
	
	xseg.erase(unique(xseg.begin(), xseg.end()), xseg.end());
	yseg.erase(unique(yseg.begin(), yseg.end()), yseg.end());
	
	sort(xcoor.begin(), xcoor.end(), Cmp);
	sort(ycoor.begin(), ycoor.end(), Cmp);

	for (size_t i=0; i<xseg.size(); i++) compressx[xseg[i]] = i;
	for (size_t i=0; i<yseg.size(); i++) compressy[yseg[i]] = i;

	for (size_t i=0; i<xcoor.size(); i++) {
	  idx1 = lower_bound(xseg.begin(), xseg.end(), xcoor[i].y1) - xseg.begin();
	  idx2 = lower_bound(xseg.begin(), xseg.end(), xcoor[i].y2) - xseg.begin();
	  for (int j=idx1 + 1; j<=idx2; j++) {
			if (val1[j] == 0 || (xcoor[i].val == -1 && val1[j] == 1)) per += (xseg[j] - xseg[j - 1]);
			val1[j] += xcoor[i].val;
		}
	}
	idx1 = idx2 = 0;
	for (size_t i=0; i<ycoor.size(); i++) {
	  idx1 = lower_bound(yseg.begin(), yseg.end(), ycoor[i].y1) - yseg.begin();
	  idx2 = lower_bound(yseg.begin(), yseg.end(), ycoor[i].y2) - yseg.begin();
	  for (int j=idx1 + 1; j<=idx2; j++) {
			if (val2[j] == 0 || (ycoor[i].val == -1 && val2[j] == 1)) per += (yseg[j] - yseg[j - 1]);
			val2[j] += ycoor[i].val;
		}
	}
	cout << per << endl;
	return 0;
}