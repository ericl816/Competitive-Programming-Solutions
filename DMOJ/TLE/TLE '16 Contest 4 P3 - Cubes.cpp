#include <bits/stdc++.h>
#define ll long long
#define MAXN 28
#define vi vector<int>
#define pb push_back
using namespace std;

int N, u, v;
int edges[] = {1, 2, 3, 4, 5, 6, 7, 8};
vi vec[MAXN];
bool flag[MAXN][MAXN], good;


void Permute () {
    while(next_permutation(edges, edges + 8)) {if (flag[edges[0]][edges[1]] && flag[edges[0]][edges[3]] && flag[edges[1]][edges[2]] && flag[edges[2]][edges[3]] && flag[edges[0]][edges[5]] && flag[edges[1]][edges[4]] && flag[edges[2]][edges[7]] && flag[edges[3]][edges[6]] && flag[edges[4]][edges[5]] && flag[edges[4]][edges[7]] && flag[edges[5]][edges[6]] && flag[edges[6]][edges[7]]) good = 1;} 
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
	  scanf("%d %d", &u, &v);
	  //vec[u].pb(v);
	  //vec[v].pb(u);
	  flag[u][v] = flag[v][u] = 1;
	}
	Permute();
	printf("%s\n", (good ? "Ja" : "Nej"));
	return 0;
}