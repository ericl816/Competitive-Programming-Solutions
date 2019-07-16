#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
using namespace std;

int T[MAXN];
string s, t;

inline int KMP () {
	for (int i=0, j=0; i<s.size(); i++, j++) {
		while (j>=0 && s[i]!=t[j]) j = T[j];
		if (j == t.size() - 1) return abs(i - j);
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	T[0] = -1;
	for (int i=0, j=-1; i<t.size(); i++, j++, T[i] = j) while (j>=0 && t[i]!=t[j]) j = T[j];
	cout << KMP() << endl;
}