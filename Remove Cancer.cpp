#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, x;
string s[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
	  cin >> s[i];
	  for (int j=0; j<s[i].size(); j++) {
	    if (s[i][j] != '0' && s[i][j] != '1') s[i][j] = '0';
	  }
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<s[0].size(); j++) cout << s[i][j];
		cout << endl;
	}
	return 0;
}