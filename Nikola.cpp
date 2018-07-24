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
int squares[MAXN];
int DP[MAXN][MAXN];

inline int Solve (int row, int jump) {
	if (row < 1 || row > N) return INF;
	if (row == N) return squares[row];
	int &res = DP[row][jump];
	if (~res) return res;
	int cost = squares[row];
	int nextcost = min(INF, Solve(row + jump + 1, jump + 1));
	if (jump) nextcost = min(nextcost, Solve(row - jump, jump));
	nextcost += cost;
	return res = nextcost;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	memset(DP, -1, sizeof(DP));
	for (int i=1; i<=N; i++) cin >> squares[i];
	cout << Solve(2, 1) << "\n";
	return 0;
}