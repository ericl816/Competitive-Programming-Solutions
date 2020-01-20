#include <bits/stdc++.h>
#define ll long long
#define MAXN 35
#define INF 0x3f3f3f3f
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

string s;
bool flag = 1;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	getline(cin, s);
	for (int i=0; i<s.length(); i++) {
		for (int j=i + 1; j<=s.length(); j++) if (s.substr(i, j) == "CCC") flag = 0;
	}	
	cout << (flag ? "YES" : "NO") << endl;
	return 0;
}