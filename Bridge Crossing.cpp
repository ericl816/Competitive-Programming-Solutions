#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 110
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int M, Q;
int a[MAXN], DP[MAXN], ptr[MAXN];
string names[MAXN];
stack<string> st;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> Q;
	for (int i=1; i<=Q; i++) cin >> names[i] >> a[i];
	memset(DP, INF, sizeof(DP));
	DP[0] = 0;
	for (int i=1; i<=Q; i++) {
		int maxx = a[i];
		for (int j=1; j<=M; j++) {
			// D("%d\n", a[i - j + 1]);
			if (DP[i - j] + maxx < DP[i]) {
				DP[i] = DP[i - j] + maxx;
				ptr[i] = i - j;
			}
			maxx = max(maxx, a[i - j]);
		}
	}
	cout << "Total Time: " << DP[Q] << "\n";
	int idx1 = ptr[Q], idx2 = Q;
	while (idx2) {
		string s = "";
		for (int i=idx1 + 1; i<=idx2; i++) s += names[i] + " ";
		st.push(s);
		idx2 = idx1;
		idx1 = ptr[idx1];
	}
	while (!st.empty()) {
		cout << st.top() << "\n";
		st.pop();
	}
	cout << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */