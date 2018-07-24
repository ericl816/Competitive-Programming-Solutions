#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100
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

int N, x, d, a;
bitset<MAXN> adj[MAXN];
bool flag;
vi ans;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> x;
	for (int i=1; i<=N; i++) {
		cin >> d;
		for (int j=0; j<d; j++) {
			cin >> a;
			adj[i].set(a);
			adj[a].set(i);
		}
	}
	for (int i=1; i<=N; i++) {
		flag = 0;
		if (i == x || adj[i].test(x)) continue;
		for (int j=1; j<=N; j++) {
			flag |= (i ^ x && i ^ j && adj[i].test(j) && adj[j].test(x));
		}
		if (flag) ans.pb(i);
	}
	cout << ans.size() << "\n";
	for (auto i : ans) cout << i << "\n";
	return 0;
}