#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int N, cnt = 1;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	// Calculate instead of brute-force
	cout << (3 - (abs(5 - N) >> 1)) << endl;
	return 0;
}
