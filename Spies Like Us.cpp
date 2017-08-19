#include <bits/stdc++.h>
#define MAXN 2010
#define pb push_back
using namespace std;

int N, M, K, i, j;
vector<int> vec[MAXN];
bool adj[MAXN][MAXN];

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int a=0; a<K; a++) {
		scanf("%d %d", &i, &j);
		for (int b=0; b<vec[i].size(); b++) {
			if (adj[j][vec[i][b]]) {
				printf("%s\n", "NO");
				return 0;
			}
			else {
				adj[j][vec[i][b]] = 1;
				adj[vec[i][b]][j] = 1;
			}
		}
		vec[i].pb(j);
	}
	printf("%s\n", "YES");
}
