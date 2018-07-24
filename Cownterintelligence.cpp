#include <bits/stdc++.h>
using namespace std;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b; cin >> a >> b;
	for(int i = 1,c; i<=a; i++){
		cin >> c;
		if (c == b) continue;
		double d = log2(c / b);
		if ((c % b)==0 && (int)d == d) continue;
		cout << i << endl;
	}
	return 0;
}