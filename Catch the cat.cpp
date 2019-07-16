#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
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

int X, Y;
int dist[MAXN];
bool vis[MAXN];
queue<pii> q;
vi adj[MAXN];

inline bool isValid (int x) {
	return x >= 1 && x <= 1e5;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> X >> Y;
	vis[X] = 1;
	q.push(mp(X, 0));
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		if (curr.f == Y) {
			cout << curr.s << "\n";
			return 0;
		}
		if (curr.f * 2 == Y || curr.f - 1 == Y || curr.f + 1 == Y) {
			cout << curr.s + 1 << "\n";
			return 0;
		}
		if (isValid(curr.f * 2) && !vis[curr.f * 2]) {
			vis[curr.f * 2] = 1;
			q.push(mp(curr.f * 2, curr.s + 1));
		}
		if (isValid(curr.f + 1) && !vis[curr.f + 1]) {
			vis[curr.f + 1] = 1;
			q.push(mp(curr.f + 1, curr.s + 1));
		}
		if (isValid(curr.f - 1) && !vis[curr.f - 1]) {
			vis[curr.f - 1] = 1;
			q.push(mp(curr.f - 1, curr.s + 1));
		}
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