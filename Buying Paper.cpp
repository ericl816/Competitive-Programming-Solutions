#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
using namespace std;

int D, val, Q, lod = INF, hid = 1, loq = INF, hiq = 1;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> D;
	for (int i=0; i<D; i++) {
		cin >> val;
		lod = min(lod, val);
		hid = max(hid, val);
	}
	cin >> Q;
	for (int i=0; i<Q; i++) {
		cin >> val;
		loq = min(loq, val);
		hiq = max(hiq, val);
	}
	if (hid * 25 < loq * 10) cout << "Dimes are better" << "\n";
	else if (hiq * 10 < lod * 25) cout << "Quarters are better" << "\n";
	else cout << "Neither coin is better" << "\n";
	return 0;
}