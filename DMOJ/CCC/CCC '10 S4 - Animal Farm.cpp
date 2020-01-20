#include <bits/stdc++.h>
#define ll long long
#define MAXN 110
#define MAXM 20
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

struct Disjoint {
private:
	int N;
	vi lead, rank;

public:
	Disjoint(int N) : N(N), lead(N + 1), rank(N + 1) { } 
  
	void make_Set () {
		for (int i=0; i<=N; i++) lead[i] = i, rank[i] = 1;
	}

	int Find (int x) {
		while (lead[x] ^ x) {
			lead[x] = lead[lead[x]];
			x = lead[x];
		}
		return x;
	}

	bool Merge (int x, int y) {
		return Find(x) ^ Find(y);
	}

	void Union (int x, int y) {
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

Disjoint ds(MAXN);
int N, S, corners[MAXM], price[MAXM];
ll ans1, ans2;
set<pii> outsidepoints;
map<pii, int> nodes, cost;
vector<pair<int, pii>> adj, edgelist;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=1; i<=N; i++) {
		cin >> S;
		for (int j=0; j<S; j++) cin >> corners[j];
		for (int j=0; j<S; j++) cin >> price[j];
		for (int j=0; j<S; j++) {
			int corner1 = corners[j], corner2 = corners[(j + 1) % S];
			if (corner1 > corner2) swap(corner1, corner2);
			pii curr = pii(corner1, corner2);
			if (outsidepoints.count(curr)) {
				adj.pb(mp(price[j], mp(i, nodes[curr])));
				outsidepoints.erase(curr);
				edgelist.pb(mp(price[j], mp(i, nodes[curr])));
			}
			else {
				outsidepoints.insert(curr);
				nodes[curr] = i;
				cost[curr] = price[j];
			}
		}
	}
	for (set<pii>::iterator it=outsidepoints.begin(); it!=outsidepoints.end(); it++) edgelist.pb(mp(cost[*it], mp(0, nodes[*it])));
	sort(adj.begin(), adj.end());
	sort(edgelist.begin(), edgelist.end());

	ds.make_Set();
	for (auto &next : adj) {
		if (ds.Merge(next.s.f, next.s.s)) {
		    ds.Union(next.s.f, next.s.s);
			ans1 += next.f;
		}
	}
	ds.make_Set();
	for (auto &next : edgelist) {
		if (ds.Merge(next.s.f, next.s.s)) {
		    ds.Union(next.s.f, next.s.s);
			ans2 += next.f;
		}
	}
	cout << (min(ans1, ans2)) << endl;
	return 0;
}