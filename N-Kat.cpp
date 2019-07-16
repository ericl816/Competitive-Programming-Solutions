#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 25
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

int N, bit1 = -1, bit2 = -1, minndiff = INF;
int arr[MAXN];
vector<pii> vec;

inline bool Cmp (pii &a, pii &b) {
	return a.s < b.s;
}

inline void Recur (int bit, int iter, ll val) {
	if (iter >= N) {
		vec.pb(mp(bit, val));
		return;
	}
	Recur(bit | (1 << iter), iter + 1, val + arr[iter]);
	Recur(bit, iter + 1, val);
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> arr[i];
	Recur(0, 0, 0);
	sort(vec.begin(), vec.end(), Cmp);
	for (size_t i=0; i<vec.size() - 1; i++) {
		int diff = abs(vec[i].s - vec[i + 1].s);
		if (diff < minndiff) {
			minndiff = diff;
			bit1 = vec[i].f;
			bit2 = vec[i + 1].f;
		}
	}
	// cout << bit1 << " " << bit2 << endl;
	for (int i=0; i<N; i++) if (~bit1 && bit1 & (1 << i)) cout << i + 1 << " ";
	cout << "\n";
	for (int i=0; i<N; i++) if (~bit2 && bit2 & (1 << i)) cout << i + 1 << " ";
	cout << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */