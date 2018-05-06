#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
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

int n, temp, maxx;
string s, ans;
vector< pair< string, int > >vec;

inline int Recur (string a, string b) {
	if (a.size() < b.size()) return 0;
	if (a.substr(0, b.size()) == b) return 1 + Recur(a.substr(1), b);
	return Recur(a.substr(1), b);
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i=0; i<s.size(); i++) {
		for (int j=1; j<=s.size() - i; j++) {
			if (s.substr(i, j).size() == 2) temp = Recur(s, s.substr(i, j));
			if (temp) vec.pb(mp(s.substr(i, j), temp));
		}
	}
	for (pair<string, int> next : vec) {
		if (maxx < next.s) {
			maxx = next.s;
			ans = next.f;
		}
	}
	cout << ans << "\n";
	return 0;
}