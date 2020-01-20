#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int n, m, a, b, carbon, hydrogen, energy, atoms[MAXN], bonds[MAXN][MAXN];
bool vis[MAXN], impossible;

void DFS(int node) {
  if (impossible) return;
	vis[node] = 1;
	if (atoms[node] == 4) carbon++;
	else if (atoms[node] == 1) hydrogen++;
	for (int i=1; i<=n; i++) {
	  if (!vis[i] && bonds[node][i]) {
	    if (bonds[node][i] == 1 && ((atoms[node] == 4 && atoms[i] == 1) || (atoms[node] == 1 && atoms[i] == 4))) energy += 413;
	    else if (bonds[node][i] == 1 && atoms[node] == 4 && atoms[i] == 4) energy += 346;
	    else if (bonds[node][i] == 2 && atoms[node] == 4 && atoms[i] == 4) energy += 615;
  	}
  }
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++) {
		scanf("%d %d", &a, &b);
		bonds[a][b]++;
		bonds[b][a]++;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) atoms[i] += bonds[i][j];
		if (atoms[i] ^ 1 && atoms[i] ^ 4) {
			impossible = 1;
			return 0 * printf("%s\n", "Impossible");
		}
	}
	for (int i=1; i<=n; i++) if (!vis[i]) DFS(i);
	if (!impossible) {
		printf("%d\n", energy);
		if (carbon == 1) printf("%s%s%d\n", "C", "H", hydrogen);
		else if (hydrogen == 1) printf("%s%d%s\n", "C", carbon, "H");
		else printf("%s%d%s%d\n", "C", carbon, "H", hydrogen);
		return 0;
	}
	return 0;
}