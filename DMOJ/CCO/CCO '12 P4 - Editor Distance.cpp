#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 80
#define MAXN 100000
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

int N, Rs, Cs, Re, Ce;
int a[MAXN];
queue<pii> q;
bool vis[MAXN][MAXM];
int dist[MAXN][MAXM];

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0; i<N; i++) cin >> a[i];
	cin >> Rs >> Cs >> Re >> Ce;
	--Rs, --Cs, --Re, --Ce;
	q.push(mp(Rs, Cs));
	vis[Rs][Cs] = 1;
	memset(dist, INF, sizeof(dist));
	dist[Rs][Cs] = 0;
	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		vis[curr.f][curr.s] = 0;
		if (curr.f > 0) {
			int temp = curr.s;
			if (curr.s >= a[curr.f - 1]) temp = a[curr.f - 1] - 1;
			if (dist[curr.f - 1][temp] > dist[curr.f][curr.s] + 1) {
				dist[curr.f - 1][temp] = dist[curr.f][curr.s] + 1;
				if (!vis[curr.f - 1][temp]) {
					vis[curr.f - 1][temp] = 1;
					q.push(mp(curr.f - 1, temp));
				}
			}
		}
		if (curr.f < N - 1) {
			int temp = curr.s;
			if (curr.s >= a[curr.f + 1]) temp = a[curr.f + 1] - 1;
			if (dist[curr.f + 1][temp] > dist[curr.f][curr.s] + 1) {
				dist[curr.f + 1][temp] = dist[curr.f][curr.s] + 1;
				if (!vis[curr.f + 1][temp]) {
					vis[curr.f + 1][temp] = 1;
					q.push(mp(curr.f + 1, temp));
				}
			}
		}
		if (curr.f > 0 || curr.s > 0) {
			int temp1 = curr.f, temp2 = curr.s - 1;
			if (curr.s == 0) {
				--temp1;
				temp2 = a[temp1] - 1;
			}
			if (dist[temp1][temp2] > dist[curr.f][curr.s] + 1) {
				dist[temp1][temp2] = dist[curr.f][curr.s] + 1;
				if (!vis[temp1][temp2]) {
					vis[temp1][temp2] = 1;
					q.push(mp(temp1, temp2));
				}
			}
		}
		if (curr.s == a[curr.f] - 1) {
			if (curr.f < N - 1) {
				if (dist[curr.f + 1][0] > dist[curr.f][curr.s] + 1) {
					dist[curr.f + 1][0] = dist[curr.f][curr.s] + 1;
					if (!vis[curr.f + 1][0]) {
						vis[curr.f + 1][0] = 1;
						q.push(mp(curr.f + 1, 0));
					}
				}
			}
		}
		else {
			if (dist[curr.f][curr.s + 1] > dist[curr.f][curr.s] + 1) {
				dist[curr.f][curr.s + 1] = dist[curr.f][curr.s] + 1;
				if (!vis[curr.f][curr.s + 1]) {
					vis[curr.f][curr.s + 1] = 1;
					q.push(mp(curr.f, curr.s + 1));
				}
			}
		}
		
	}
	cout << dist[Re][Ce] << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */