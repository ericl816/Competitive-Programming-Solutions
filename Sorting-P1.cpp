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

// DMOPC '18 Contest 1 P1 - Sorting

int N, minn = INF, maxx = -INF, val = -INF;
int A[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> A[i];
		if (A[i] == 0) {
			minn = min(minn, i);
			maxx = max(maxx, i);
		}
	}
	if (minn ^ INF && maxx ^ -INF) {
		for (int i=minn; i<=maxx; i++) val = max(val, A[i]);
		if (val == 0 && minn) val = A[minn - 1];
		for (int i=minn; i<=maxx; i++) {
			if (A[i] == 0) A[i] = val;
		}
	}
	// for (int i=0; i<N; i++) cout<<A[i]<<endl;
	cout << (is_sorted(A, A + N) ? "YES\n" : "NO\n");
	return 0;
}

// 10
// 0 1 2 0 0 0 4 5 0 0

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */