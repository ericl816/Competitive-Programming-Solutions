#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, cnt;

void Check () {
  for (int i=1; i<=N; i++) if (N % i == 0) cnt++;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i=0; i<5; i++) {
		cin >> N;
		cnt = 0;
		Check();
		if (cnt == 3 || cnt == 4) cout << "semiprime" << "\n";
		else cout << "not" << "\n";
	}
	return 0;
}