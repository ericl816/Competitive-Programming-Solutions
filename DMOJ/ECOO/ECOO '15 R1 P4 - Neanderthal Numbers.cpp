#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
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

string s;
string arr[10] = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};

inline int Solve () {
	getline(cin, s);
	int DP[s.size() + 1];
	memset(DP, 0, sizeof(DP));
	DP[0] = 1;
	for (size_t i=0; i<s.size(); i++) {
		for (int j=0; j<10; j++) {
			if (i + arr[j].size() <= s.size() && s.substr(i, arr[j].size()) == arr[j]) {
			    DP[i + arr[j].size()] += DP[i];
			}
		}
	}
	return DP[s.size()];
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test_cases = 10;
	while (test_cases--) cout << Solve() << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */