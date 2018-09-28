#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 10010
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

int N;
int a[MAXN], freq[MAXN];
vi zeros, mid, misc;

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
		cin >> a[i];
		freq[a[i] % 3]++;
		if (a[i] % 3 == 0) zeros.pb(a[i]);
		else misc.pb(a[i]);
	}
	if (!zeros.empty()) {
		mid.pb(zeros[0]);
		for (size_t i=1; i<zeros.size(); i++) {
			int &next = zeros[i];
			if (misc.empty()) {
				cout << "impossible\n";
				return 0;
			}
			// cout << misc.back() << " " << next << endl;
			mid.pb(misc.back());
			misc.pop_back();
			mid.pb(next);
		}
	}
	if (freq[0] == 0 && freq[1] >= 1 && freq[2] >= 1) {
		cout << "impossible\n";
		return 0;
	}
	for (auto i : misc) {
		if (i % 3 == 1) cout << i << " ";
	}
	for (auto i : mid) cout << i << " ";
	for (auto i : misc) {
		if (i % 3 == 2) cout << i << " ";
	}
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