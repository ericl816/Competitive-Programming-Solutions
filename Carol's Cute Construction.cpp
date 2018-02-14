#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 100010
#define MAXN 210
#define MOD 1000000007
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

// The intended solution is network flow - the intuition here is to match up a C to an A, an A to an L, and an L to an I.
// Also known as Max-Bipartite Matching
// We connect each pair of adjacent letters that could be part of a valid match, and connect every C to the source and every I to the sink. 
// The final detail is to ensure that every node can only be used in one augmenting path.

struct Network {
	struct Edge {
		int dest, cost, next;
		Edge (int dest, int cost, int next) : dest(dest), cost(cost), next(next) {
		}
	};

	int N, src, sink;
	vector<int> last, dist;
	vector<Edge> e;

	Network (int N, int src, int sink) : N(N), src(src), sink(sink), last(N), dist(N) {
		fill(last.begin(), last.end(), -1);
	}

	void addEdge (int x, int y, int xy, int yx) {
		e.push_back(Edge(y, xy, last[x]));
		last[x] = e.size() - 1;
		e.push_back(Edge(x, yx, last[y]));
		last[y] = e.size() - 1;
	}

	bool getPath () {
		fill(dist.begin(), dist.end(), -1);
		queue<int> q;
		q.push(src);
		dist[src] = 0;

		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int i = last[curr]; i != -1; i = e[i].next) {
				if (e[i].cost > 0 && dist[e[i].dest] == -1) {
					dist[e[i].dest] = dist[curr] + 1;
					q.push(e[i].dest);
				}
			}
		}

		return dist[sink] != -1;
	}

	int dfs (int curr, int flow) {
		if (curr == sink) return flow;
		int ret = 0;
		for (int i = last[curr]; i != -1; i = e[i].next) {
			if (e[i].cost > 0 && dist[e[i].dest] == dist[curr] + 1) {
				int res = dfs(e[i].dest, min(flow, e[i].cost));
				ret += res;

				e[i].cost -= res;
				e[i ^ 1].cost += res;

				flow -= res;
				if (flow == 0) break;
			}
		}
		return ret;
	}

	int getFlow () {
		int res = 0;
		while (getPath()) res += dfs(src, 1 << 30);
		return res;
	}
};

int N, source, sink, id1, id2;
string seq = "CALI";
char grid[MAXN][MAXN];

inline int Get_ID (int a, int b) {
	return N * a + b;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int *movex = new int [4] {0, 0, -1, 1};
	int *movey = new int [4] {-1, 1, 0, 0};
	cin >> N;
	for (int i=0; i<N; i++) {
		string s;
		cin >> s;
		for (int j=0; j<N; j++) grid[i][j] = s[j];
	}	
	source = ((N * N) << 1) + 1;
	sink = source + 1;
	Network flow(MAXM, source, sink);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			id1 = Get_ID(i, j);
			int k = 0;
			while (grid[i][j] != seq[k]) k++;
			flow.addEdge(id1 << 1, id1 << 1 | 1, 1, 0);
			if (k == 0) flow.addEdge(source, id1 << 1, 1, 0);
			else if (k == 3) {
				flow.addEdge(id1 << 1 | 1, sink, 1, 0);
				continue;
			}
			for (int l=0; l<4; l++) {
				for (int m=0; m<4; m++) {
					int currx = i + movex[l];
					int curry = j + movey[m];
					if (currx < 0 || currx >= N || curry < 0 || curry >= N) continue;
					id2 = Get_ID(currx, curry);
					if (grid[currx][curry] == seq[k + 1]) flow.addEdge(id1 << 1 | 1, id2 << 1, 1, 0);
				}
			}
		}
	}
	cout << flow.getFlow() << endl;
	return 0;
}