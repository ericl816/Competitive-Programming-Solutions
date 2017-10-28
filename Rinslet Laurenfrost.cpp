#include <bits/stdc++.h>
#define MAXN 26
#define ll long long
using namespace std;

string a, b;
int sum, ind[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	getline(cin, a);
	getline(cin, b);
	for (int i=0; i<a.length(); i++) ind[a[i] - 'a']++;
	for (int i=0; i<b.length(); i++) ind[b[i] - 'a']--;
	for (int i=0; i<MAXN; i++) sum += abs(ind[i]);
	cout << sum << "\n";
	return 0;
}