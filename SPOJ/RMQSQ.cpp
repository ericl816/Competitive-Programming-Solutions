#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 17 // log2(MAXN)
#define MAXN 100010
#define INF 0x3f3f3f3f
#define MOD 1000000007
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

// Sparse Table Approach

int N, Q, SIZE, minn;
int arr[MAXN];
int segmin[MAXM][MAXN];

int main () {
	scan(N);
	for (int i=1; i<=N; i++) {
		scan(arr[i]);
		segmin[0][i] = arr[i];
	}
	// Could use MAXM or: 32 - __builtin_clz(N) - same as: log2(N)
	for (int i=1; i<=(32 - __builtin_clz(N)); i++) {
		for (int j=1; j + (1 << i) - 1<=N; j++) {
			segmin[i][j] = min(segmin[i - 1][j], segmin[i - 1][j + (1 << (i - 1))]);
		}
	}
	scan(Q);
	for (int i=0, a, b; i<Q; i++) {
		scan(a); scan(b);
		a++, b++;
		SIZE = log(b - a + 1) / log(2);
		minn = min(segmin[SIZE][a], segmin[SIZE][b - (1 << SIZE) + 1]);
		printf("%d\n", minn);
	}
	return 0;
}