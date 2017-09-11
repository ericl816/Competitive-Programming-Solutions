#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int N, cnt;
string s;

int main () {
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> s;
		if ((int) s.length() <= 10) cnt++;
	}
	printf("%d\n", cnt);
}