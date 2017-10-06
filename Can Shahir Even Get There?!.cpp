#include <bits/stdc++.h>
#define ll long long
#define MAXN 2010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, M, A, B, X, Y;
vi adj[MAXN];
bool vis[MAXN];

void DFS (int node) {
    if (vis[node]) return;
    vis[node] = 1;
    for (int &next : adj[node]) DFS(next);
}

int main () {
	scanf("%d %d %d %d", &N, &M, &A, &B);
	for (int i=0; i<M; i++) {
		scanf("%d %d", &X, &Y);
		adj[X].pb(Y);
		adj[Y].pb(X);
	}
	DFS(A);
	printf("%s\n", (vis[B]) ? "GO SHAHIR!" : "NO SHAHIR!");
	return 0;
}