#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 510
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EPS 1e-5
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>w
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

typedef complex<double> point; 
#define x real() 
#define y imag()
#define PI 3.1415926535897932384626 

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

int N;
pii A, B;
pii a[MAXN];
  
inline point rotate (point P, point Q, double theta)  { 
	return (P - Q) * polar(1.0, theta) +  Q; 
}

inline ll dist (point P, point Q) {
	return (P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y);
}

inline long double getSlope (point P, point Q) {
	return 1.0 * (Q.y - P.y) / (Q.x - P.x);
}

inline bool Cmp (pii a, pii b) {
	point aa(a.f, a.s), bb(b.f, b.s), AA(A.f, A.s);
	return dist(AA, aa) < dist(AA, bb);
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> A.f >> A.s >> B.f >> B.s;
	point P(A.f, A.s), Q(B.f, B.s);
	for (int i=1; i<=N; i++) {
		cin >> a[i].f >> a[i].s;
	}
	if (A == B) {
		cout << 0 << "\n";
		return 0;
	}
	if (N == 1) {
		point M(a[1].f, a[1].s);
		ll dist1 = dist(P, M), dist2 = dist(Q, M);
		cout << (dist1 == dist2 ? 1 : -1) << "\n";
	}
	else {
		// sort(a + 1, a + N + 1, Cmp);
		point M(a[1].f, a[1].s), M1(a[2].f, a[2].s);

		ll dist1 = dist(P, M), dist2 = dist(Q, M), dist3 = dist(P, M1), dist4 = dist(Q, M1);
		if (dist1 ^ dist2 && dist3 ^ dist4) {
			for (double i=-360.0; i<=360.0; i+=0.1) {
				double ang = i * M_PI / 180.0;
				point rot = rotate(P, M, ang);
				int px = rot.x, py = rot.y;
				if (dist(P, rot) == dist(Q, rot)) {
					for (double j=-360.0; j<=360.0; j+=0.1) {
						double ang1 = j * M_PI / 180.0;
						point rot1 = rotate(rot, M1, ang1);
						int p1x = rot1.x, p1y = rot1.y;
						if (p1x == B.f && p1y == B.s) {
							cout << 2 << "\n";
							return 0;
						}
					}
				}
			}
			cout << -1 << "\n";
		}
		else if ((dist1 == dist2) || (dist3 == dist4)) cout << 1 << "\n";
		else cout << -1 << "\n";
	}
	return 0;	
}

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */