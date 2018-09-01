#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int A[3], B[3], C[3];
int ans = -INF;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i=0; i<3; i++) cin >> A[i];
	for (int i=0; i<3; i++) cin >> B[i];
	for (int i=0; i<3; i++) cin >> C[i];
	if (A[0] == B[1]) ans = max(ans, C[1]);
	if (A[1] == B[2]) ans = max(ans, C[2]);
	if (A[2] == B[0]) ans = max(ans, C[0]);
	if (A[0] == B[1] && A[1] == B[2]) ans = max(ans, C[1] + C[2]);
	if (A[0] == B[1] && A[2] == B[0]) ans = max(ans, C[0] + C[1]);
	if (A[1] == B[2] && A[2] == B[0]) ans = max(ans, C[0] + C[2]);
	if (A[0] == B[1] && A[1] == B[2] && A[2] == B[0]) ans = max(ans, C[0] + C[1] + C[2]);
	cout << (max(0, ans)) << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */