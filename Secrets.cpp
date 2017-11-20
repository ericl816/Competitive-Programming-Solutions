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

ll Fpow (int x, int y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	if (y & 1) return x * Fpow(x * x, y >> 1);
	return Fpow(x * x, y >> 1);
}


ll EuclideanDist (int x1, int y1, int x2, int y2) {
	return Fpow(abs(y2 - y1), 2) + Fpow(abs(x2 - x1), 2);
}


int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int x1, y1, x2, y2, xs, ys, D;
	cin >> x1 >> y1 >> x2 >> y2 >> xs >> ys >> D;
	if (EuclideanDist(x1, y1, xs, ys) <= Fpow(D, 2) || EuclideanDist(x2, y2, xs, ys) <= Fpow(D, 2)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}