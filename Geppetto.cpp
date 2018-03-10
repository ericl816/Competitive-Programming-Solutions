#include <bits/stdc++.h>
#define ll long long
#define MAXN 410
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

// Simply get the number of unique subsets, given the restrictions in the task

int N, M, a, b, ans;
int bit[MAXN];
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<M; i++) {
		cin >> a >> b;
		a--; b--;
		bit[a] |= (1 << b);
		bit[b] |= (1 << a);
	}
	for (int i=0; i<(1 << N); i++) {
		flag = 1;
		for (int j=0; j<N; j++) {
		  if (i & (1 << j) && (i & bit[j])) {
		  	flag = 0;
		  	break;
		  }
		}
		ans += flag;
	}
	cout << ans << endl;
	return 0;
}