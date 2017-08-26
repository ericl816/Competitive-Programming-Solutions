#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define pii pair<int, int>
#define ub upper_bound
#define mp make_pair
#define f first
#define s second
#define it iterator
using namespace std;

int n, R, arr[MAXN];
pii group;
set<pii> tree;

int main() {
	scanf("%d %d", &n, &R);
	tree.insert(mp(R, 0));
	for (int i=1; i<n; i++) {
		scanf("%d", &R);
		group = mp(R, i);
		set<pii>::it next = tree.ub(group);
		if (next == tree.begin()) {
			printf("%s\n", "NO");
			return 0;
		}
		arr[(--next)->s]++;
		if (arr[next->s] == 2) tree.erase(next);
		tree.insert(group);
	}
	printf("%s\n", "YES");
	return 0;
}
