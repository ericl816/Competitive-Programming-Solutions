#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
#define INF 0x3f3f3f3f
#define MOD 1000000007
// #define min(a, b) (a) < (b) ? (a) : (b)
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

int n, k, d;
ll DP[2][MAXN];

inline ll DFS (int subtree_size, int D) {
	if (subtree_size == 0) return D;
	ll &val = DP[D][subtree_size];
	if (~val) return val;
	ll ans = 0;
	for (int i=1; i<=min(subtree_size, k); i++) ans = ((ans + DFS(subtree_size - i, i >= d ? 1 : D)) + MOD) % MOD;
	return val = ans;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	memset(DP, -1, sizeof(DP));
	cin >> n >> k >> d;
	cout << DFS(n, 0) << "\n";
	return 0;
}