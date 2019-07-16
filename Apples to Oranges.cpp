#include <bits/stdc++.h>
#define MAXN 510
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pild pair<int, ld>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
#define umsi unordered_map<string, int>
#define msi map<string, int>
using namespace std;

int N, M;
string s, a, b;
ld c, maxx[MAXN];
vector<pild> adj[MAXN];
umsi fruits;
queue<int> q;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> s;
		fruits[s] = i;
	}
	for (int i=0; i<M; i++) {
		cin >> a >> b >> c;
		int x = fruits[a];
		int y = fruits[b];
		adj[x].pb(mp(y, c));
	}
	int src = fruits["APPLES"];
	maxx[src] = 1.0;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (maxx[curr] - 1.0 > 1e-6 && curr == src) { // Impossible case
			cout << "YA" << "\n";
			return 0;
		} 
		for (pild &next : adj[curr]) {
			if (maxx[next.f] < maxx[curr] * next.s) {
				maxx[next.f] = maxx[curr] * next.s;
				q.push(next.f);
			}
		}
	}
	cout << "NAW" << "\n";
	return 0;
}