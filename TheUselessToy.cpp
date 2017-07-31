#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int idx (string ch) {
  	if (ch == "^") return 0;
	else if (ch == ">") return 1;
	else if (ch == "v") return 2;
	else if (ch == "<") return 3;
}

string a, b;
ll n;
bool cw, ccw;

int main () {
	cin >> a >> b >> n;
	cw = (idx(a) + n) % 4 == idx(b);
	ccw = (idx(a) + 3 * n) % 4 == idx(b);
	cout << ((cw && ccw) ? "undefined" : ccw ? "ccw" : "cw") << "\n";
}