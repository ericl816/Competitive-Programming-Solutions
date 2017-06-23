#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int T[MAXN];
string s, t;

int find() {
	for (int i = 0, j = 0; i < s.length(); i++, j++) {
		while (j >= 0 && s[i] != t[j]) 
			j = T[j];
		if (j == t.length() - 1) 
			return abs(i - j);
	}
	return -1;
}

int main() {
	cin >> s >> t;
	T[0] = -1;
	for (int i = 0, j = -1; i < t.length(); i++, j++, T[i] = j) {
		while (j >= 0 && t[i] != t[j]) 
			j = T[j];
	}
	printf("%d\n", find());
}
