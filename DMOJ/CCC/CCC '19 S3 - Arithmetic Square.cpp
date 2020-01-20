#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 5
#define MOD 1000000007
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
#define allof(x) x.begin(), x.end()
#define DEBUG 1
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

string s[MAXN][MAXN];
int grid[MAXN][MAXN];

inline void PrintArr () {
	// if (DEBUG) cout << "Printing array\n";
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
}

inline void OneXs () {
	int T = 2;
	while (T--) {
		// Do rows
		for (int i=0; i<3; i++) {
			int countX = 0, col = 0;
			for (int j=0; j<3; j++) {
				if (s[i][j] == "X") {
					countX++;
					col = j;
				}
			}
			if (countX == 1) {
				if (col == 0) grid[i][0] = 2 * grid[i][1] - grid[i][2];
				else if (col == 1) grid[i][1] = (grid[i][0] + grid[i][2]) / 2;
				else if (col == 2) grid[i][2] = 2 * grid[i][1] - grid[i][0];
				s[i][col] = "$";
			}
		}
		// Do columns
		for (int i=0; i<3; i++) {
			int countX = 0, row = 0;
			for (int j=0; j<3; j++) {
				if (s[j][i] == "X") {
					++countX;
					row = j;
				}
			}
			if (countX == 1) {
				if (row == 0) grid[0][i] = 2 * grid[1][i] - grid[2][i];
				if (row == 1) grid[1][i] = (grid[0][i] + grid[2][i]) / 2;
				if (row == 2) grid[2][i] = 2 * grid[1][i] - grid[0][i];
				s[row][i] = "$";
			}
		}
		// PrintArr();
	}
}

inline void MoreXs (int row) {
	int countX = 0, notXcol = 0;
	for (int i=0; i<3; i++) {
		if (s[row][i] == "X") ++countX;
		else notXcol = i;
	}
	if (countX == 2) {
		for (int i=0; i<3; i++) {
			grid[row][i] = grid[row][notXcol];
			s[row][i] = "$";
		}
	}
	if (countX == 3) {
		for (int i=0; i<3; i++) {
			grid[row][i] = 0;
			s[row][i] = "$";
		}
	}
	// PrintArr();
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int countX = 0, notX = 0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cin >> s[i][j];
			if (s[i][j] == "X") {
				++countX;
				continue;
			}
			notX = stoi(s[i][j]);
			grid[i][j] = stoi(s[i][j]);
		}
	}
	if (countX == 9) { // 1st edge case
		countX = 0;
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				grid[i][j] = 1;
			}
		}
		PrintArr();
		return 0;
	}
	if (countX == 8) { // 2nd edge case
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				grid[i][j] = notX;
			}
		}
		PrintArr();
		return 0;
	}
	OneXs();
	MoreXs(1);
	OneXs();
	MoreXs(0);
	OneXs();
	PrintArr();
	return 0;
}

/*
X X 1
X X X
X 1 X

X X 1
X 14 X
X X X

X 1 X
X X X
2 X X
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */