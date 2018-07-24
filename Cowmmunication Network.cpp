#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 200010
#define INF 0x3f3f3f3f
#define SIZE 1e18
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

struct Edge {
	ll a, b, cost;

	bool operator < (const Edge &e) const {
	  return cost > e.cost;
	}
	
	bool operator > (const Edge &e) const {
	  return cost < e.cost;
	}
};

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint(int N) : N(N), lead(N + 1), rank(N + 1) { }

	void make_Set () {
		for (int i=1; i<=N; i++) {
		  lead[i] = i;
		  rank[i] = 0;
		}
	}
	
	int Find (int x) {
		while (lead[x] ^ x) {
		  lead[x] = lead[lead[x]];
		  x = lead[x];
		}
		return x;
	}

	bool Merge (int x, int y) {
		int c = Find(x);
		int d = Find(y);
		if (c ^ d) return 1;
		return 0;
	}

	void Union (int x, int y) {
		int c = Find(x);
		int d = Find(y);
		if (Merge(x, y)) {
			if (rank[c] > rank[d]) {
			  lead[d] = c;
			  rank[c] += rank[d];
			}
			else {
				lead[c] = d;
				rank[d] += rank[c];
			}
		}
	}
}; 

Disjoint ds(MAXN);
Disjoint ds1(MAXN);
int N, M, A, B, C;
int indeg[MAXN];
bool flag;
ll cnt;
vector<Edge> edgelist, edgelist1;
vector<pii> adj[MAXN];
priority_queue<Edge, vector<Edge>, greater<Edge>> pq, pq1;
ll totalcost, totalcost1;

inline void Check () {
	for (int i=1; i<=N; i++) {
		if (ds.Merge(1, i)) {
			flag = 1;
			break;
		}
	}
	if (flag) {
	  cout << "Impossible" << endl;
	  return;
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ds.make_Set();
	ds1.make_Set();
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> A >> B >> C;
		indeg[A]++;
		indeg[B]++;
		adj[A].pb(mp(B, C));
		adj[B].pb(mp(A, C));
		edgelist.pb((Edge) {A, B, C});
		edgelist1.pb((Edge) {B, A, C});
	}
	for (Edge next : edgelist) pq.push(next);
	for (Edge next : edgelist1) pq1.push(next);
	while (!pq.empty()) {
		Edge curr = pq.top();
		pq.pop();
		if (ds.Merge(curr.a, curr.b) || curr.cost > 0) {
			ds.Union(curr.a, curr.b);
			totalcost += curr.cost;
		}
	}
	while (!pq1.empty()) {
		Edge curr = pq1.top();
		pq1.pop();
		if (ds1.Merge(curr.a, curr.b) || curr.cost > 0) {
			ds1.Union(curr.a, curr.b);
			totalcost1 += curr.cost;
		}
	}
	Check();
	if (!flag) cout << (max(totalcost, totalcost1)) << endl;
	return 0;
}