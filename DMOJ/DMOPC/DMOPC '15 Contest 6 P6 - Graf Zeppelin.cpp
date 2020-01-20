#include <bits/stdc++.h>
#define ll long long
#define MAXN 1510
#define c count
using namespace std;

int N, M, K, x, y;
bitset<MAXN> bit[MAXN], cnt[MAXN], arr[MAXN];

void Initialize (int x, int y) {
	bit[x][y] = bit[y][x] = arr[x][y] = arr[y][x] = cnt[x][y] = cnt[y][x] = 1;
}

int main () {
	scanf("%d %d %d", &N, &M, &K);
	for (int i=0; i<M; i++) {
		scanf("%d %d", &x, &y);
		Initialize(x, y);
	}
	for (int i=1; i<K; i++) {
		for (int j=0; j<N; j++) {
			for (int k=0; k<N; k++) {
				if (arr[j + 1][k + 1]) cnt[j + 1] |= bit[k + 1];
			}
			arr[j + 1] |= cnt[j + 1];
		}
	}
	for (int i=0; i<N; i++) printf("%d\n", (!cnt[i + 1][i + 1] ? 1 : 0) + cnt[i + 1].c());
}