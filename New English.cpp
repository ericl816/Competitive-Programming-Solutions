#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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

int N, M, x, ind;
char c;
string ans;
vector<pair<char, pii> > queries;
pii freq[MAXN];

inline bool Cmp (pair<char, pii> &a, pair<char, pii> &b) {
	return a.s.s < b.s.s;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) ans += "$";
	for (int i=0; i<M; i++) {
		cin >> c >> x >> ind;
		queries.pb(mp(c, mp(x, --ind)));
	}
	sort(queries.begin(), queries.end(), Cmp);
	for (size_t i=0; i<queries.size(); i++) {
		pair<char, pii> &next = queries[i];
		int ch = next.f - 'a';
		if (freq[ch].f > next.s.f) {
			cout << -1 << "\n";
			return 0;
		}
		else if (freq[ch].f == next.s.f) {
			freq[ch].s = next.s.s + 1;
		}
		else {
			for (int j=freq[ch].s; j<=next.s.s && freq[ch].f<next.s.f; j++) {
				if (ans[j] == '$') {
					freq[ch].f++;
					ans[j] = next.f;
				}
			}
			if (freq[ch].f < next.s.f) {
				cout << -1 << "\n";
				return 0;
			}
			freq[ch].s = next.s.s + 1;
		}
	}
	for (int i=0; i<N; i++) {
		if (ans[i] == '$') {
			for (int j=0; j<26 && ans[i] == '$'; j++) {
				if (freq[j].s <= i) {
					ans[i] = j + 'a';
				}
			}
		}
		if (ans[i] == '$') {
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */