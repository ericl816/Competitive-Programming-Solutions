#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int len;
string s;

inline bool Solve (int currlen, int pos) {
	if (pos) {
		for (int i=0; i<(currlen >> 1); i++) {
			if (s[i] != s[currlen - i - 1]) return 0;
		}
		return 1;
	}
	else {
		for (int i=0; i<(currlen >> 1); i++) {
			if (s[len - currlen + i] != s[len - i - 1]) return 0;
		}
		return 1;
	}
	return 1;
}

void Do_Test_Cases () {
	int N = 10;
	while (N--) {
		cin >> s;
		len = s.size();
		for (int i=len; i>0; i--) {
			if (Solve(i, 1) || Solve(i, 0)) {
				cout << len - i << "\n";
				break;
			}
		}
	}
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    Do_Test_Cases();
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */