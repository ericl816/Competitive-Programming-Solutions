#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 11
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
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N;
ll sour, bitter;
pair<ll, ll> res[MAXN];

inline ll Solve (int ind, ll prod, ll sum) {
	if (ind == N - 1) {
		if (prod == 1 && sum == 0) return abs(res[ind].f - res[ind].s);
		return min(abs(prod - sum), abs((res[ind].f * prod) - (res[ind].s + sum)));
	}
	return min(Solve(ind + 1, prod, sum), Solve(ind + 1, prod * res[ind].f, sum + res[ind].s));
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
	if (N == 1) {
		cin >> sour >> bitter;
		cout << abs(sour - bitter) << "\n";
		return 0;
	}
	for (int i=0; i<N; i++) {
		cin >> sour >> bitter;
		res[i] = mp(sour, bitter);
	}
	cout << Solve(0, 1LL, 0LL) << "\n";
	return 0;
}

/*
4
1 7
2 5
3 10
4 3
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */