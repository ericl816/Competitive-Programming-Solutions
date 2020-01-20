#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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

struct Edge {
	int a, b;
	ll cost;
	bool flight;
	
	bool operator < (const Edge &e) const {
	  if (e.cost == cost) return flight < e.flight;
	  return cost < e.cost;
	}
	
	bool operator > (const Edge &e) const {
	  if (e.cost == cost) return flight > e.flight;
	  return cost > e.cost;
	}
};

vector<Edge> edgelist;
priority_queue<Edge, vector<Edge>, greater<Edge> > pq;

int N, M, P, Q, a, b, c, x, y, z;
int edgecnt1, edgecnt2;
ll totalcost, resedge;

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

	inline void make_Set () {
		for (int i=1; i<=N; i++) {
			lead[i] = i;
			rank[i] = 0;
		}
	}

	inline int Find (int x) {
		while (lead[x] ^ x) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	inline bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	inline void Union (int x, int y) {
		int a = Find(x);
		int b = Find(y);
		if (Merge(x, y)) {
			if (rank[a] > rank[b]) {
				lead[b] = a;
				rank[a] += rank[b];
			}
			else {
				lead[a] = b;
				rank[b] += rank[a];
			}
		}
	}
};

int main () {
	scan(N); scan(M); scan(P); scan(Q);
	edgecnt1 = N;
	edgecnt2 = M;
	Disjoint ds1(M), ds2(N);
	ds1.make_Set();
	ds2.make_Set();
	for (int i=1; i<=P; i++) {
		scan(a); scan(b); scan(c);
		totalcost += (ll) c * N;
		edgelist.pb((Edge) {a, b, c, 1});
	}
	for (int i=1; i<=Q; i++) {
		scan(x); scan(y); scan(z);
		totalcost += (ll) z * M;
		edgelist.pb((Edge) {x, y, z, 0});
	}
	for (Edge &next : edgelist) pq.push(next);
	while (!pq.empty()) {
		Edge curr = pq.top();
		pq.pop();
		if (curr.flight == 0 && ds2.Merge(curr.a, curr.b)) {
			resedge += (ll) curr.cost * edgecnt2;
			edgecnt1--;
			ds2.Union(curr.a, curr.b);
		}
		else if (curr.flight == 1 && ds1.Merge(curr.a, curr.b)) {
			resedge += (ll) curr.cost * edgecnt1;
			edgecnt2--;
			ds1.Union(curr.a, curr.b);
		}
	}
	return !printf("%lld\n", totalcost - resedge);
}