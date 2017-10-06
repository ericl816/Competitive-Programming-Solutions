#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int count = 0;
	while (N ^ 1) {
	  N = (N & 1) ? 3 * N + 1 : N >> 1;
	  count++;
	}
	cout << count << "\n";
	return 0;
}