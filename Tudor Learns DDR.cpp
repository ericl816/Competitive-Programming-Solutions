#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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

string s;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	getline(cin, s);
	if ((s[0] == 'U' && s[2] == 'D') || (s[0] == 'D' && s[2] == 'U') || (s[0] == 'L' && s[2] == 'R') || (s[0] == 'R' && s[2] == 'L')) {
		if (s[0] != s[1] && s[0] != s[2] && s[1] != s[2]) {
			if (s[0] == 'L' || s[0] == 'R') {
				cout << "Crossover" << endl;
				return 0;
			}
			if (s[0] == 'U' || s[0] == 'D') {
				cout << "Candle" << endl;
				return 0;
			}
		}
		else {
			cout << "Neither" << "\n";
			return 0;
		}
	}
	cout << "Neither" << endl;
	return 0;
}