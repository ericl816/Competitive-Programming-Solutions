#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

int N, M, A, B, t, dist1[MAXN], dist2[MAXN], ans;
vector<pii> adj[MAXN];
bool vis1[MAXN], vis2[MAXN];
queue<int> q1, q2;
priority_queue<pii, vector<pii>, greater<pii>> pq1, pq2;

void SSSP1 () {
	memset(dist1, INF, sizeof(dist1));
	memset(vis1, 0, sizeof(vis1));
	dist1[0] = 0;
	vis1[0] = 1;
	q1.push(0);
	while (!q1.empty()) {
		int curr = q1.front(); q1.pop();
		vis1[curr] = 0;
		for (size_t i=0; i<adj[curr].size(); i++) {
			pii &next = adj[curr][i];
			int currnode = next.f;
			int currcost = next.s;
			int nextcost = dist1[curr] + currcost;
			if (nextcost <= dist1[currnode]) {
				dist1[currnode] = nextcost;
				if (!vis1[currnode]) {
					q1.push(currnode);
					vis1[currnode] = 1;
				}
			}
		}
	}
}

void SSSP2 (int src) {
	memset(dist2, INF, sizeof(dist2));
	memset(vis2, 0, sizeof(vis2));
	dist2[src] = 0;
	vis2[src] = 1;
	q2.push(src);
	while (!q2.empty()) {
		int curr = q2.front(); 
		q2.pop();
		vis2[curr] = 0;
		for (size_t i=0; i<adj[curr].size(); i++) {
			pii &next = adj[curr][i];
			int currnode = next.f;
			int currcost = next.s;
			int nextcost = dist2[curr] + currcost;
			if (nextcost <= dist2[currnode]) {
				dist2[currnode] = nextcost;
				if (!vis2[currnode]) {
					q2.push(currnode);
					vis2[currnode] = 1;
				}
			}
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> A >> B >> t;
		adj[A].pb(mp(B, t));
		adj[B].pb(mp(A, t));
	}
	SSSP1();
	SSSP2(N - 1);
	for (int i=0; i<N - 1; i++) ans = max(ans, dist1[i] + dist2[i]);
	cout << ans << "\n";
	return 0;
}