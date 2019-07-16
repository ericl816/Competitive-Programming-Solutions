#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2010
#define MAXM 210
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

// Time Complexity: O(K(M + NlogN))

struct Edge {
	int dest, cost, h;
};

int K, N, M, a, b, t, h, A, B;
int dist[MAXN][MAXM];
bool vis[MAXN];
queue<int> q;
vector<Edge> adj[MAXN];

int main () {
	scan(K); scan(N); scan(M);
	for (int i=0; i<M; i++) {
		scan(a); scan(b); scan(t); scan(h);
		adj[a].pb((Edge) {b, t, h});
		adj[b].pb((Edge) {a, t, h});
	}
	memset(dist, INF, sizeof(dist));
	scan(A); scan(B);
	for (int i=0; i<=K; i++) dist[A][i] = 0;
	vis[A] = 1;
	q.push(A);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = 0;
		for (Edge &next : adj[curr]) {
			for (int j=0; j+next.h<=K; j++) {
				if (dist[next.dest][j + next.h] > dist[curr][j] + next.cost) {
					dist[next.dest][j + next.h] = dist[curr][j] + next.cost;
					if (!vis[next.dest]) {
						vis[next.dest] = 1;
						q.push(next.dest);
					}
				}
			}
		}
	}
	return !printf("%d\n", (dist[B][K - 1] == INF ? -1 : dist[B][K - 1]));
}