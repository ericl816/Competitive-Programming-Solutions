#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
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
using namespace std;

int n;
vi a, DP;

inline ll LIS () {
	if (a.empty()) return 0;
	DP.pb(a[0]);
	for (size_t i=1, idx=0; i<a.size(); i++) {
		if (DP[idx] < a[i]) {
			DP.pb(a[i]);
			++idx;
		}
		else {
			int ind = lower_bound(DP.begin(), DP.end(), a[i]) - DP.begin();
			DP[ind] = a[i];
		}
	}
	return DP.size();
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i=0, x; i<n; i++) {
		cin >> x;
		a.pb(x);
	}
	cout << LIS() << "\n";
	return 0;
}