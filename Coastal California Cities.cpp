#include <bits/stdc++.h>
#define ll long long
#define MAXN 200010
#define INF 0x3f3f3f3f
#define MOD 1000000007
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

int N, p;
vi adj[MAXN];
ll prod[MAXN];

inline ll MultMod (const int &a, const int &b) {
  return 1LL * ((ll) a * b) % MOD;
}

inline ll DFS (int node, int prev) {
	ll prod_children = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		prod_children = MultMod(prod_children, DFS(next, node));
	}
	return MultMod(adj[node].size() + 1, MultMod(prod_children, prod[adj[node].size()]));
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	prod[0] = 1;
	for (int i=1; i<MAXN; i++) prod[i] = MultMod(i, prod[i - 1]);
	cin >> N;
	for (int i=1; i<N; i++) {
		cin >> p;
		adj[p].pb(i);
	}
	cout << DFS(0, -1) << endl;
	return 0;
}