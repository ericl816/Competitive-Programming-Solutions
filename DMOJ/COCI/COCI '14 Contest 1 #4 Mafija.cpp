#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 500010
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

int N;
int accus[MAXN], ind[MAXN];
ll ans;
bool vis[MAXN];

inline void DFS (int player, bool accused) {
	if (vis[player]) return;
	vis[player] = 1;
	ans += accused ^ 1;
	if (--ind[accus[player]] == 0 || !accused) DFS(accus[player], accused ^ 1);
}

int main () {
	scan(N);
	for (int i=1; i<=N; i++) {
		scan(accus[i]);
		++ind[accus[i]];
	}
	for (int i=1; i<=N; i++) if (!ind[i]) DFS(i, 0);
	for (int i=1; i<=N; i++) DFS(i, 1);
	return !printf("%lld\n", ans);
}