#include <bits/stdc++.h>
#define ll long long
#define MAXN 400010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, a, b;
vi adj[MAXN];
ll len, cnt;
ll num[MAXN], sum[MAXN];

inline void DFS (int node, int prev) {
	num[node] = 0;
	sum[node] = 1;
	for (int &next : adj[node]) {
		if (next == prev) continue;
		DFS(next, node);
		if (len < num[node] + num[next] + 1) {
			len = num[node] + num[next] + 1;
			cnt = sum[node] * sum[next];
		}
		else if (len == num[node] + num[next] + 1) cnt += sum[node] * sum[next];
		if (num[node] < num[next] + 1) {
			num[node] = num[next] + 1;
			sum[node] = sum[next];
		}
		else if (num[node] == num[next] + 1) sum[node] += sum[next];
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=1; i<N; i++) {
		cin >> a >> b;
		a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	DFS(0, -1);
	cout << len + 1 << " " << cnt << endl;
	return 0;
}