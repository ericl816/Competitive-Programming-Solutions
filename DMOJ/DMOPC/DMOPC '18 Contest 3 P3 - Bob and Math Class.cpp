#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
#define INF 0x3f3f3f3f
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

int N, cnt;
char cur;
ll val1, val2;
int dist[MAXN];
string s;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	for (int i=1; i<=N; i++) {
		if (s[i - 1] == cur) cnt++;
		else {
			if (cnt > 0) {
				// D("%d %d\n", cnt, i);
				for (int j=i - cnt; j<i; j++) dist[j] = cnt;
			}
			cur = s[i - 1];
			cnt = 1;
		}
	}
	if (cnt > 0) {
		for (int i=N - cnt + 1; i<=N; i++) dist[i] = cnt;
	}
	// for (int i=1; i<=N; i++) D("%d ", dist[i]);
	// D("\n");
	for (int i=1; i<=N; i++) {
		val1 += min(dist[i], min(i, N - i + 1));
		if (s[i] == s[i - 1]) val2 += min(dist[i], min(i, N - i));
		else val2 += min(max(dist[i], dist[i + 1]), min(i, N - i));
	}
	cout << val1 + val2 << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */