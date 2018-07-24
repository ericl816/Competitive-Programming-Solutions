#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 10010
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

int N, M;
ll minn = INF;
int page[MAXN], dist[MAXN];
bool vis[MAXN];
vi endpages;
vi adj[MAXN];
queue<int> q;
bool flag = 1;

inline void BFS (int src) {
	q.push(src);
	memset(dist, INF, sizeof(dist));
	vis[src] = 1;
	dist[src] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (size_t i=0; i<adj[curr].size(); i++) {
			int &next = adj[curr][i];
			if (!vis[next]) {
				vis[next] = 1;
				dist[next] = dist[curr] + 1;
				q.push(next);
			}
		}
	}
}

int main () {
	scan(N);
	for (int i=1; i<=N; i++) {
		scan(M);
		if (M == 0) endpages.pb(i);
		for (int j=1; j<=M; j++) {
			scan(page[j]);
			adj[i].pb(page[j]);
		}
	}
	BFS(1);
	for (int i=1; i<=N; i++) flag &= vis[i];
	printf("%s\n", flag ? "Y" : "N");
	for (size_t i=0; i<endpages.size(); i++) {
		int &next = endpages[i];
		minn = min(minn, dist[next] + 1);
	}
	return !printf("%lld\n", minn);
}