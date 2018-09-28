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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, IRcnt, WAcnt;
vector<string> codes;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (s == "WA") WAcnt++;
		codes.pb(s);
	}
	int num = floor(WAcnt * 0.3), tmp1 = 0;
	for (size_t i=0; i<codes.size(); i++) {
		string &next = codes[i];
		if (next == "AC") cout << "AC\n";
		else if (next == "WA") {
			if (num--> 0) cout << "AC\n";
			else cout << "WA\n";
		}
		else if (next == "IR") {
			if (++tmp1 <= 10) cout << "AC\n";
			else if (tmp1 <= 20) cout << "WA\n";
			else cout << "IR\n";
		}
		else cout << "WA\n";
	}
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */