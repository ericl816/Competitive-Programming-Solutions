#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1000010
#define MAXN 200010
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f
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
#define allof(x) x.begin(), x.end()
#define DEBUG 0
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

int N, P, M, u, v, ans;
int a[MAXN], b[MAXN];
pii p[MAXN];
ll minn = INF;
ll PSA1[MAXM], PSA2[MAXM], sum1[MAXM], sum2[MAXM];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P >> M;
	for (int i=0; i<N; i++) {
		cin >> u >> v;
		p[i] = mp(u, v);
	}
	for (int i=0; i<P; i++) {
		cin >> a[i];
		sum1[a[i]]++;
	}
	for (int i=0; i<M; i++) {
		cin >> b[i];
		sum2[b[i]]++;
	}
	for (int i=MAXM - 2; i>=1; i--) {
		sum1[i] += sum1[i + 1];
		PSA1[i] += PSA1[i + 1] + sum1[i];
		sum2[i] += sum2[i + 1];
		PSA2[i] += PSA2[i + 1] + sum2[i];
	}
	for (int i=0; i<N; i++) {
		ll sum = PSA1[p[i].f + 1] + PSA2[p[i].s + 1];
		if (DEBUG) D("%d %lld\n", i, sum);
		if (minn > sum) {
			minn = sum;
			ans = i + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}