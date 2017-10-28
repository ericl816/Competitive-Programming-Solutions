#include <bits/stdc++.h>
#define ll long long
#define MAXN 1010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int D, w[MAXN], F, i, j, T, ord[MAXN], times[MAXN];
vi adj[MAXN];
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> D;
	memset(ord, -INF, sizeof(ord));
	for (int i=1; i<=D; i++) cin >> w[i];
	cin >> F;
	for (int a=0; a<F; a++) {
		cin >> i >> j;
		adj[i].pb(j);
	}
	cin >> T;
	ord[1] = 0;
	for (int i=0; i<=T; i++) {
		for (int j=1; j<=D; j++) {
			if (i == ord[j]) times[j]++;
			else if (i < ord[j] || i > ord[j]) continue;
			for (size_t k=0; k<adj[j].size(); k++) {
				int &next = adj[j][k];
				if (i > ord[next]) ord[next] = i + w[next];
			}
		}
	}
	for (int i=1; i<=D; i++) cout << times[i] << "\n";
	return 0;
}