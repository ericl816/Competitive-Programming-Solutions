#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 10
#define MAXN 5000010
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

int W, D, V;
ll digit, tar;
bool vis[MAXM][MAXN];
vector<ll> digits, vals;
set<ll> ss;

inline void Calc (int num, int val) {
	if (val > MAXN || vis[num][val]) return;
	vis[num][val] = 1;
	if (num == 0) ss.insert(val);
	else {
		for (size_t i=0; i<digits.size(); i++) {
			ll &next = digits[i];
			Calc(num - 1, val * next);
			Calc(num - 1, val + next);
		}
	}
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> W >> D;
	while (D--) {
		cin >> digit;
		digits.pb(digit);
	}
	cin >> V;
	while (V--) {
		cin >> tar;
		vals.pb(tar);
	}
	for (size_t i=0; i<digits.size(); i++) {
		ll &next = digits[i];
		Calc(W, next);
	}
	for (size_t i=0; i<vals.size(); i++) {
		ll &next = vals[i];
		cout << (ss.count(next) ? "Y" : "N") << "\n";
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