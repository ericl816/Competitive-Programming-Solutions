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

struct Tmp {
	int num, b, d, c;
};

int S, N, B, D, C, Q, ind;
vector<Tmp> vec;

inline bool Cmp (Tmp &a, Tmp &b) {
	if (a.b == b.b) {
		if (a.b >= S) return a.c > b.c;
		else if (a.b < S) return a.d > b.d;
		else return a.num > b.num;
	}
	else return a.b > b.b;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> S >> N;
	for (int i=1; i<=N; i++) {
		cin >> B >> D >> C;
		vec.pb((Tmp) {i, B, D, C});
	}
	sort(vec.begin(), vec.end(), Cmp);
	cin >> Q;
	while (Q--) {
		cin >> ind;
		cout << vec[--ind].num << "\n";
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