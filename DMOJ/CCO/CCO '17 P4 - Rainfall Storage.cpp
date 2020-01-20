#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 510
#define MAXN 26010
#define MOD 1000000007
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
#define umii unordered_map<int, int>w
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int N, idx;
vi h = vi(MAXM);
bool DP[MAXN][2];
set<int> pillars;

int main () {
	scan(N);
	int SZ = 50 * N;
	for (int i=0; i<N; i++) scan(h[i]);
	sort(allof(h));
	reverse(allof(h));
	DP[0][1] = 1;
	for (int i=1; i<N; i++) {
		for (int j=0; j<=SZ; j++) {
			idx = i & 1;
			if (DP[j][idx]) DP[j][idx ^ 1] = 1;
			for (int next : pillars) {
				int val = next - h[i];
				if (j - val < 0) continue;
				if (DP[j - val][idx]) DP[j][idx ^ 1] = 1;
			}
		}
		pillars.insert(h[i]);
	}
	for (int i=0; i<=SZ; i++) if (DP[i][(N & 1)]) printf("%d ", i);
	printf("\n");
	return 0;
}