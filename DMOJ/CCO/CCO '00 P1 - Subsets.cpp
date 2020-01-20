#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, idx;
set<char> s, upper;
string con;
char a, b;
char ch[MAXN];
unordered_map<char, int> ind;
vi adj[MAXN];
bool vis[MAXN];

inline void DFS (int node, int prev) {
	if ((char) ch[node] >= 'a') s.insert(ch[node]);
	vis[node] = 1;
	for (size_t i=0; i<adj[node].size(); i++) {
		int &next = adj[node][i];
		if (next == prev) continue;
		if (!vis[next]) {
			vis[next] = 1;
			DFS(next, node);
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> a >> con >> b;
		if ((int) a >= 65 && (int) a <= 90) upper.insert(a);
		if ((int) b >= 65 && (int) b <= 90) upper.insert(b);
		if (!ind.count(a)) {
			ind[a] = idx;
			ch[idx++] = a;
		}
		if (!ind.count(b)) {
			ind[b] = idx;
			ch[idx++] = b;
		}
		adj[ind[a]].pb(ind[b]);
	}
	for (auto next : upper) {
		s.clear();
		memset(vis, 0, sizeof(vis));
		DFS(ind[next], -1);
		cout << next << " = {";
		set<char>::iterator it = s.begin();
		for (it; it != s.end(); it++) {
			if (it != s.begin()) cout << ",";
			cout << *it;
		}
		cout << "}" << "\n";
	}
	return 0;
}