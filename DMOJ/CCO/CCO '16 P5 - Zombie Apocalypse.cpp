#include <bits/stdc++.h>
#define ll long long
#define MAXN 4010
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

int N, M, K, r[MAXN], c[MAXN], Q, xidx, yidx;
short diff[MAXN][MAXN];
ll leftx[MAXN], rightx[MAXN], bottomy[MAXN], topy[MAXN], xseg[MAXN], yseg[MAXN];
ll ans, length, width;
vector<pii> coor;
set<pii> sp;

ll Query (int Q) {
	memset(diff, 0, sizeof(diff));
	ll val = 0;
	xidx = 0; yidx = 0;
	mii compressx, compressy;
	for (int i=0; i<K; i++) {
		leftx[i] = max(1, coor[i].f - Q);
		rightx[i] = min(M, coor[i].f + Q);
		bottomy[i] = max(1, coor[i].s - Q);
		topy[i] = min(N, coor[i].s + Q);
		compressx[leftx[i]] = compressx[rightx[i] + 1] = compressy[bottomy[i]] = compressy[topy[i] + 1] = 0;
	}
	for (mii::iterator it=compressx.begin(); it!=compressx.end(); it++) {
		xidx++;
		it->s = xidx;
		xseg[xidx] = it->f;
	}
	for (mii::iterator it=compressy.begin(); it!=compressy.end(); it++) {
		yidx++;
		it->s = yidx;
		yseg[yidx] = it->f;
	}
	for (int i=0; i<K; i++) {
		leftx[i] = max(1, coor[i].f - Q);
		rightx[i] = min(M, coor[i].f + Q);
		bottomy[i] = max(1, coor[i].s - Q);
		topy[i] = min(N, coor[i].s + Q);

		// Bottom left and top right corners
		diff[compressx[leftx[i]]][compressy[bottomy[i]]]++;
		diff[compressx[rightx[i] + 1]][compressy[topy[i] + 1]]++;

		// Top left and bottom right corners
		diff[compressx[leftx[i]]][compressy[topy[i] + 1]]--;
		diff[compressx[rightx[i] + 1]][compressy[bottomy[i]]]--;
	}
	for (int i=1; i<xidx; i++) {
		length = (xseg[i + 1] - xseg[i]);
		width = 0;
		for (int j=1; j<yidx; j++) {
			diff[i][j] += diff[i - 1][j];
			diff[i][j] += diff[i][j - 1];
			diff[i][j] -= diff[i - 1][j - 1];
			if (diff[i][j]) width += (yseg[j + 1] - yseg[j]);
		}
		val += length * width; // Get area
	}
	return val;
}

bool Cmp (pii &a, pii &b) {
	return a.f < b.f && a.s < b.s;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	coor.reserve(K);
	for (int i=0; i<K; i++) {
		cin >> r[i] >> c[i];
		swap(r[i], c[i]);
		coor.pb(mp(r[i], c[i]));
	}
	sort(coor.begin(), coor.end(), Cmp);
	cin >> Q;
	if (Q == 0) {
		cout << K << endl;
		return 0;
	}
	// Now compute the area, using the value for Q
	ans = Query(Q) - Query(Q - 1);
	cout << ans << endl;
	return 0;
}