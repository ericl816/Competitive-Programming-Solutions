#include <bits/stdc++.h>
#define ll long long
#define MAXM 50
#define MAXN 300010
#define LOGN 20
#define INF 0x3f3f3f3f
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

int N, v, w, x, y, lca;
int depth[MAXN], st[MAXN];
int sparse[MAXN][MAXM];
char op;

inline int LCA (int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i=LOGN - 1; i>=0; i--) if (depth[sparse[x][i]] >= depth[y]) x = sparse[x][i];
	if (x == y) return x;
	for (int i=LOGN - 1; i>=0; i--) {
		if (sparse[x][i] ^ sparse[y][i]) {
			x = sparse[x][i];
			y = sparse[y][i];
		}
	}
	return sparse[x][0];
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> op;
		if (op == 'a') {
			cin >> v;
			x = st[v];
			st[i] = i;
			depth[i] = depth[x] + 1;
			sparse[i][0] = x;
			for (int j=1; j<LOGN; j++) sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
		}
		else if (op == 'b') {
			cin >> v;
			x = st[v];
			st[i] = sparse[x][0];
			cout << x << "\n";
		}
		else if (op == 'c') {
			cin >> v >> w;
			x = st[v];
			y = st[w];
			st[i] = x;
			lca = LCA(x, y);
			cout << depth[lca] << "\n";
		}
	}
	return 0;
}