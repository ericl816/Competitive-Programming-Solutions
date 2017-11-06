#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define usi unordered_set<int>
using namespace std;

int N, M, K, A, B, minn, maxx;
int lead[MAXN], par[MAXN], size[MAXN], edge[MAXN];
bool vis[MAXN], cut[MAXN];
vector<pii> adj;
usi nodes;
bool isCycle;

void make_Set () {
	for (int i=0; i<N; i++) {
		lead[i] = i;
		par[i] = 0;
		edge[i] = 0;
		size[i] = 1;
	}
}

int Find (int x) {
	while (x ^ lead[x]) {
		lead[x] = lead[lead[x]]; // Path Compression
		x = lead[x];
	}
	return x;
	}

bool Merge (int x, int y) {
	return Find(x) == Find(y);
}

void Union (int x, int y) {
	int c = Find(x);
	int d = Find(y);
	if (!Merge(x, y)) {
		// Only merge the set with a smaller rank
		if (par[d] <= par[c]) {
			lead[d] = c;
			size[c] += size[d];
			edge[c] += edge[d] + 1;
			if (par[c] == par[d]) par[c]++;
		}
		else {
			lead[c] = d;
			size[d] += size[c];
			edge[d] += edge[c] + 1;
		}
	}
	else edge[c]++;
}
	
int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	memset(vis, 0, sizeof(vis));
	make_Set();
	for (int i=0; i<M; i++) {
		cin >> A >> B;
		A--; B--;
		Union(A, B);
		adj.pb(mp(A, B));
	}
	for (int i=0; i<N; i++) {
		int x = Find(i);
		if (!vis[x]) {
	  		if (size[x] >= K) {
	  			maxx += size[x] - size[x] % K;
	  			minn += (size[x] - 1) / K + (size[x] ^ K && size[x] == edge[x]);
	  		}
	  		vis[x] = 1;
		}
	}
	cout << maxx << " " << minn << "\n";
	return 0;	
}