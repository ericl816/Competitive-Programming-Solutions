#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, M, idx;
int seq[MAXN], delay[MAXN], ans[MAXN], DP[MAXN << 1];

int main () {
	scan(N); scan(M);
	for (int i=1; i<=N; i++) scan(seq[i]);
	for (int i=1; i<=M; i++) scan(delay[i]);
	for (int i=1; i<=N; i++) {
		idx = seq[i];
		ans[idx] = max(ans[idx] + 1, DP[i + delay[idx] + 1] + 1);
		DP[i] = max(DP[i + 1], ans[idx]);
	}
	return !printf("%d\n", DP[N]);
}