#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int W;
vector<string> v;
set<string> ss;

inline bool Cmp (string &a, string &b) {
	return a.size() < b.size();
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> W;
	for (int i=0; i<26; i++) {
		string a = string(1, i + 'a');
		ss.insert(a);
		for (int j=0; j<26; j++) {
			string b = string(1, j + 'a');
			ss.insert(a + b);
			for (int k=0; k<26; k++) {
				string c = string(1, k + 'a');
				ss.insert(a + c);
				ss.insert(b + c);
				ss.insert(a + b + c);
			}
		}
	}
	for (auto i : ss) v.pb(i);
	sort(v.begin(), v.end(), Cmp);
	for (int i=0; i<W; i++) cout << v[i] << " ";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */