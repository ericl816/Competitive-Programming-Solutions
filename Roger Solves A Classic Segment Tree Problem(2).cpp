#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXM 16 // log2(50010) or 32 - __builtin_clz(50010)
#define MAXN 50010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

// Sparse Table Approach

int N, Q, SIZE, maxx, minn;
int arr[MAXN];
int segmin[MAXM][MAXN], segmax[MAXM][MAXN];

int main () {
	scan(N); scan(Q);
	for (int i=1; i<=N; i++) {
		scan(arr[i]);
		segmin[0][i] = segmax[0][i] = arr[i];
	}
	// Could use MAXM or: 32 - __builtin_clz(N) - same as: log2(N)
	for (int i=1; i<=(32 - __builtin_clz(N)); i++) {
		for (int j=1; j + (1 << i) - 1<=N; j++) {
			segmin[i][j] = min(segmin[i - 1][j], segmin[i - 1][j + (1 << (i - 1))]);
			segmax[i][j] = max(segmax[i - 1][j], segmax[i - 1][j + (1 << (i - 1))]);
		}
	}
	for (int i=0, a, b; i<Q; i++) {
		scan(a); scan(b);
		SIZE = log(b - a + 1) / log(2);
		maxx = max(segmax[SIZE][a], segmax[SIZE][b - (1 << SIZE) + 1]);
		minn = min(segmin[SIZE][a], segmin[SIZE][b - (1 << SIZE) + 1]);
		printf("%d\n", maxx - minn);
	}
	return 0;
}