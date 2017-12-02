#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 300010
#define INF 0x3f3f3f3f3f3f
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

int N, M, t, R, r, query[MAXN];
vi adj[MAXN];

ll DFS (int node, int par) {
	ll ans = INF;
	for (int &next : adj[node]) {
		if (next == par) continue;
		ans = min(ans, DFS(next, node));
	}
	if (ans == INF) return query[node];
	return ans + query[node];
}

int main () {
	scan(N); scan(M);
	for (int i=1; i<=M; i++) {
		scan(t); scan(R);
		for (int j=1; j<=R; j++) {
			scan(r);
			adj[t].pb(r);
		}
	}
	for (int i=1; i<=N; i++) scan(query[i]);
	printf("%lld\n", DFS(1, -1));
	return 0;
}