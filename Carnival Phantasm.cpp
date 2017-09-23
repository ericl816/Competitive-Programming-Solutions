#include <bits/stdc++.h>
#define ll long long 
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define it iterator
#define lb lower_bound
#define ub upper_bound
#define si set<int>
using namespace std;

int N, S, dist[MAXN], s, a, Q, x, k;
set<pii> st[510];
si arr[MAXN];
char op;
bool flag;

int main () {
	scanf("%d %d", &N, &S);
	for (int i=1; i<=N; i++) scanf("%d", &dist[i]);
	for (int i=0; i<S; i++) {
		scanf("%d %d", &s, &a);
		st[a].insert(mp(dist[s], s));
		arr[s].insert(a);
	}
	scanf("%d", &Q);
	for (int i=0; i<Q; i++) {
		scanf(" %c", &op);
		if (op == 'A') {
			scanf("%d %d", &x, &k);
			pii temp = mp(dist[x], x);
			arr[x].insert(k);
			st[k].insert(temp);
		}
		else if (op == 'S') {
			scanf("%d %d", &x, &k);
			if (arr[x].count(k)) {
				pii temp = mp(dist[x], x);
				st[k].erase(st[k].lb(temp));
				arr[x].erase(arr[x].find(k));
			}
		}
		else if (op == 'E') {
			scanf("%d %d", &x, &k);
			for (int curr : arr[x]) {
				pii temp = mp(dist[x], x);
				st[curr].erase(st[curr].lb(temp));
			}
			dist[x] = k;
			arr[x].clear();
		}
		else if (op == 'Q') {
			scanf("%d", &k);
			if (!st[k].empty()) {
				set<pii>::it next = st[k].begin();
				printf("%d\n", next->s);
			}
			else printf("%d\n", -1);
		}
	}
	return 0;
}