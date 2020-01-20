#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1010
#define MAXN 5010
#define MOD 360
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

#define F(x) cout << "1\n" << abs(x) << "\n";
#define CW cout << "2\n";
#define CCW cout << "3\n";

int n, op, x, dist, dir_conv, horiz, vert;

inline void Move () {
	if (dir_conv == 0) horiz += x;
	else if (dir_conv == 90) vert += x;
	else if (dir_conv == 180) horiz -= x;
	else if (dir_conv == 270) vert -= x;
}

inline void Commands () {
	if (horiz > 0 && vert > 0) {
		if (dir_conv == 0) {
			CW; F(vert); CW; F(horiz);
		}
		else if (dir_conv == 90) {
			CCW; F(horiz); CCW; F(vert);
		}
		else if (dir_conv == 180) {
			F(horiz); CCW; F(vert);
		}
		else {
			F(vert); CW; F(horiz);
		}
	}
	else if (horiz < 0 && vert > 0) {
		if (dir_conv == 0) {
			F(horiz); CW; F(vert);
		}
		else if (dir_conv == 90) {
			CW; F(horiz); CW; F(vert);
		}
		else if (dir_conv == 180) {
			CCW; F(vert); CCW; F(horiz);
		}
		else {
			F(vert); CCW; F(horiz);
		}
	}
	else if (horiz < 0 && vert < 0) {
		if (dir_conv == 0) {
			F(horiz); CCW; F(vert);
		}
		else if (dir_conv == 90) {
			F(vert); CW; F(horiz);
		}
		else if (dir_conv == 180) {
			CW; F(vert); CW; F(horiz);
		}
		else {
			CCW; F(horiz); CCW; F(vert);
		}
	}
	else if (horiz > 0 && vert < 0) {
		if (dir_conv == 0) {
			CCW; F(vert); CCW; F(horiz);
		}
		else if (dir_conv == 90) {
			F(vert); CCW; F(horiz);
		}
		else if (dir_conv == 180) {
			F(horiz); CW; F(vert);
		}
		else {
			CW; F(horiz); CW; F(horiz);
		}
	}
	else if (horiz > 0 && vert == 0) {
		if (dir_conv == 0) {
			CCW; CCW; F(horiz);
		}
		else if (dir_conv == 90) {
			CCW; F(horiz);
		}
		else if (dir_conv == 180) {
			F(horiz);
		}
		else {
			CW; F(horiz);
		}
	}
	else if (horiz == 0 && vert > 0) {
		if (dir_conv == 0) {
			CW; F(vert);
		}
		else if (dir_conv == 90) {
			CW; CW; F(vert);
		}
		else if (dir_conv == 180) {
			CCW; F(vert);
		}
		else {
			F(vert);
		}
	}
	else if (horiz < 0 && vert == 0) {
		if (dir_conv == 0) {
			F(horiz);
		}
		else if (dir_conv == 90) {
			CW; F(horiz);
		}
		else if (dir_conv == 180) {
			CW; CW; F(horiz);
		}
		else {
			CCW; F(horiz);
		}
	}
	else if (horiz == 0 && vert < 0) {
		if (dir_conv == 0) {
			CCW; F(vert);
		}
		else if (dir_conv == 90) {
			F(vert);
		}
		else if (dir_conv == 180) {
			CW; F(vert);
		}
		else {
			CCW; CCW; F(vert);
		}
	}
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (n--) {
		horiz = vert = 0;
		cin >> op;
		while (op) {
			if (op == 1) {
				cin >> x;
				Move();
			}
			// Turn right
			else if (op == 2) {
				dir_conv = (dir_conv - 90 + MOD) % MOD;
			}
			// Turn CCW
			else if (op == 3) {
				dir_conv = (dir_conv + 90) % MOD;
			}
			cin >> op;
		}
		dist = abs(horiz) + abs(vert);
		cout << "Distance is " << dist << "\n";
		Commands();
		cout << "\n";
	}
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */