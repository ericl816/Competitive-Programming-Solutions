#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define MAXM 200010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define msll map<string, ll>
#define psll pair<string, ll>
using namespace std;

struct Edge {
	int a, b, c;
};

int N, M, X, Y, A, B, C, Q, F, L;
int *earliest, *late;
vector<pii> adj[MAXN];
Edge edges[MAXM];
vi vec;
bool vis[MAXN], isnode, ischannel, flag1, flag2, flag3;
int dist1[MAXN], dist2[MAXN];
queue<int> q;
priority_queue<pii, vector<pii>, greater<pii>> pq;

// NOTE: The priority queue version of Dijkstra's seem to be slower than the normal version for some reason
void SPFA (int src, int dist[MAXN]) {
	memset(vis, 0, sizeof(vis));
	q.push(src);
	pq.push(mp(0, src));
	dist[src] = 0;
	vis[src] = 1;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		vis[curr] = 0;
		for (pii &next : adj[curr]) {
			int nextcost = dist[curr] + next.s;
			if (nextcost < dist[next.f]) {
				dist[next.f] = nextcost;
				if (!vis[next.f]) {
					vis[next.f] = 1;
					q.push(next.f);
				}
			}
		}
	}
}

void Check_Cases (int node1, int node2) {
	// Case 1:
	flag1 = ((dist1[node1] < dist2[node1] && dist1[node2] < dist2[node2]) || (dist2[node1] < dist1[node1] && dist2[node2] < dist1[node2]) || (dist1[node2] < dist2[node2] && dist1[node1] < dist2[node1]) || (dist2[node2] < dist1[node2] && dist2[node1] < dist1[node1]));
	// Case 2:
	flag2 = ((dist1[node1] < dist2[node1] && dist1[node2] == dist2[node2]) || (dist2[node1] < dist1[node1] && dist2[node2] == dist1[node2]) || (dist1[node2] < dist2[node2] && dist1[node1] == dist2[node1]) || (dist2[node2] < dist1[node2] && dist2[node1] == dist1[node1]));
	// Case 3:
	flag3 = ((dist1[node1] < dist2[node1] && dist1[node2] > dist2[node2]) || (dist2[node1] < dist1[node1] && dist2[node2] > dist1[node2]));
}

// Get the air body that arrives eariler than the other
void Get_Earliest (int node1, int node2) {
	if (dist1[node1] < dist2[node1]) {
		earliest = dist1;
		late = dist2;
	}
	else {
		earliest = dist2;
		late = dist1;
	}
}

int main () {
	scanf("%d %d %d %d", &N, &M, &X, &Y);
	for (int i=1; i<=M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		//A--; B--;
		adj[A].pb(mp(B, C));
		adj[B].pb(mp(A, C));
		edges[i] = (Edge) {A, B, C};
	}
	memset(dist1, INF, sizeof(dist1));
	memset(dist2, INF, sizeof(dist2));
	SPFA(X, dist1); // dist1 = Warm air
	SPFA(Y, dist2); // dist2 = Cold air
	scanf("%d", &Q);
	//for (int i=0; i<N; i++) for (pii &next : adj1[i]) vec.pb(dist1[i] + dist2[next.f] + next.s);
	//sort(vec.begin(), vec.end());
	for (int i=0; i<Q; i++) {
		scanf("%d %d", &F, &L);
		if (F == 1) {
			if (dist1[L] == dist2[L]) printf("%d\n", dist1[L]);
			else printf("%d\n", -1);
		}
		else {
			int node1 = edges[L].a;
			int node2 = edges[L].b;
			int cost = edges[L].c;
			Check_Cases(node1, node2);
			if (flag1) printf("%d\n", -1);
			else if (flag2) {
				if (dist1[node1] == dist2[node1]) swap(node1, node2);
				Get_Earliest(node1, node2);
				if (earliest[node2] == earliest[node1] + cost) printf("%d\n", -1);
				else printf("%d\n", earliest[node2]);
			}
			else if (flag3) {
				Get_Earliest(node1, node2);
				printf("%f\n", ((earliest[node1] + late[node2] + cost) / 2.0));
			}
			else printf("%d\n", min(dist1[node1], dist1[node2]));
		}
		/*
		if (dist1[L] ^ INF && dist2[L] ^ INF) {
			//F == 1 is a node, F == 2 is a channel
			if (dist1[L] == dist2[L]) printf("%d\n", dist1[L]);
			else if (dist1[L] ^ dist2[L]) printf("%.5f\n", (dist1[L] + dist2[L]) / (double) 2.0);
			else {
				int idx = upper_bound(vec.begin(), vec.end(), L) - vec.begin();
				printf("%d\n", idx ? vec[idx - 1] : -1);
			}
		}
		else printf("%d\n", -1);
		*/
	}
	return 0;
}