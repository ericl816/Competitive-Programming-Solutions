#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int cnt;
string s;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	for (int i=0; i<s.size(); i++) {
		if (i < s.size() - 1 && s[i] == ':' && s[i + 1] == ')') cnt++;
	}
	cout << cnt << endl;
	return 0;
}