#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1010
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

int N;
int A[MAXN], B[MAXN];
int DP[MAXN][MAXN];
string S, T;

inline int Solve (int x, int y) {
	if (x < 0 || y < 0) return 0;
	int &res = DP[x][y];
	if (~res) return res;
	if (S[x] !- T[y] && ((S[x] == 'W' && A[x] > B[y]) || (T[y] == 'W' && A[x] < B[y]))) res = Solve(x - 1, y - 1) + A[x] + B[y];
	return res = max(res, max(Solve(x - 1, y), Solve(x, y - 1)));
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i=0; i<N; i++) cin >> A[i];
	cin >> T;
	for (int i=0; i<N; i++) cin >> B[i];
	memset(DP, -1, sizeof(DP));
	cout << Solve(N - 1, N - 1) << "\n";
	return 0;
}