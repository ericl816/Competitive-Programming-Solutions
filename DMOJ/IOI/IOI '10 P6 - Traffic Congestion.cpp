#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, P[MAXN], S[MAXN], D[MAXN], DP[MAXN], minn = INF, num;
vector<vi> adj = vector<vi>(MAXN);
bool vis[MAXN];

int DFS (int node, int par) {
	if (vis[node]) return 0;
	vis[node] = 1;
	int &sum = P[node];
	for (size_t i=0; i<adj[node].size(); i++) {
		int &curr = adj[node][i];
		if (curr == par) continue;
		if (!vis[curr]) {
			int next = DFS(curr, node);
			DP[node] = max(DP[node], next);
			sum += next;
		}
	}
	return P[node] = sum;
}

int LocateCentre (int N, int *P, int *S, int *D) {
	memset(vis, 0, sizeof(vis));
	for (int i=0; i<N - 1; i++) {
		adj[S[i]].pb(D[i]);
		adj[D[i]].pb(S[i]);
	}
	DFS(N >> 1, -1); //Root of the tree
	for (int i=0; i<N; i++) {
		DP[i] = max(DP[i], P[N >> 1] - P[i]);
		if (minn > DP[i]) {
		  num = i;
		  minn = DP[i];
		}
	}
	return num;
}

/*
int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> P[i];
	for (int i=0; i<N - 1; i++) {
		cin >> S[i] >> D[i];
		adj[S[i]].pb(D[i]);
		adj[D[i]].pb(S[i]);
	}
	memset(vis, 0, sizeof(vis));
	cout << LocateCentre(N, P, S, D) << endl;
	return 0;
}
*/