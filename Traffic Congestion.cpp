#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 1000010
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

int N, P[MAXN], S[MAXN], D[MAXN], DP[MAXN], minn = INF, num = 0;
vector<vi> adj = vector<vi>(MAXN);
bool vis[MAXN];

void DFS (int node, int par) {
	if (vis[node]) return;
	vis[node] = 1;
	int sum = P[node];
	for (int curr : adj[node]) {
		if (curr == par) continue;
		if (!vis[curr]) {
		    int next = DFS(curr, node);
		    sum += next;
		    DP[node] = max(DP[node], next);
	    }
	}
	P[node] = sum;
}

int LocateCentre(int N, int P[MAXN], int S[MAXN], int D[MAXN]) {
	for (int i=0; i<N - 1; i++) {
		adj[S[i]].pb(D[i]);
		adj[D[i]].pb(S[i]);
	}
	DFS(0, -1); 
	for (int i=0; i<N; i++) {
		DP[i] = max(DP[i], P[0] - P[i]);
		if (minn > DP[i]) {
			num = i;
			minn = DP[i];
		}
	}
	return num;
}

int main () {
	scan(N);
	for (int i=0; i<N; i++) scan(P[i]);
	for (int i=0; i<N - 1; i++) scan(S[i], D[i]);
	memset(vis, 0, sizeof(vis));
	return 0 * printf("%d\n", LocateCentre(N, P, S, D));
}