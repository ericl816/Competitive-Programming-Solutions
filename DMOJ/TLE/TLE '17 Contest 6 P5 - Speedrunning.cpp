#include <bits/stdc++.h>
#define ll long long
#define MAXN 5010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int ,int>
#define umii unordered_map<int, int>
using namespace std;

struct Edge {
	int a, b, dist;
};

int N, u, v, t, sum, ans = INF;
vector<Edge> vec;
vector<pii> adj1[MAXN], adj2[MAXN];
queue<int> q;
bool vis[MAXN];
int length1[MAXN], length2[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0; i<N - 1; i++) {
		cin >> u >> v >> t;
		u--; v--;
		adj1[u].pb(mp(v, t));
		adj2[v].pb(mp(u, t));
		vec.pb((Edge) {u, v, t});
		sum += t;
	}
	cout << sum << endl;
	return 0;
}