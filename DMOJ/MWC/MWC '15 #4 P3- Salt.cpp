#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
#define si set<int>
#define misi map<int, si>
using namespace std;

misi xcoor, ycoor;
int N, Q, X, Y, x, y, op, coor;
char op1;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i=0; i<N; i++) {
		cin >> X >> Y;
		xcoor[X].insert(Y);
		ycoor[Y].insert(X);
	}
	for (int i=0; i<Q; i++) {
		cin >> op;
		if (op == 1) {
			cin >> x >> y;
			cout << (xcoor.count(x) && xcoor[x].count(y) ? "salty" : "bland") << "\n";
		}
		else if (op == 2) {
			cin >> op1 >> coor;
			if (op1 == 'X') cout << (xcoor.count(coor) ? xcoor[coor].size() : 0) << "\n";
			else if (op1 == 'Y') cout << (ycoor.count(coor) ? ycoor[coor].size() : 0) << "\n";
		}
	}
	return 0;
}