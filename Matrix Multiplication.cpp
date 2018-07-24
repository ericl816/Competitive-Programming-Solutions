#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, M;
int deg[MAXN];
ll ans;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		int x, y;
		cin >> x >> y;
		deg[--x]++;
		deg[--y]++;
	}
	for (int i=0; i<N; i++) ans += deg[i] * deg[i];
	cout << ans << endl;
	return 0;
}