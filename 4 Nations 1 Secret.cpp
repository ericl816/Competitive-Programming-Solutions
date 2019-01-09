#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 25010
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

// Simply run Manacher's Longest Palindromic String Algorithm

int N, C, R, i, iMirror, maxLPSLength, maxLPSCenterPosition;
int L[MAXN << 1];
string text, ans;

inline void Manachers () {
    if (N == 0) return;
    N = N << 1 | 1, L[0] = 0, L[1] = 1, C = 1, R = 2;
    int start = -1, end = -1, diff = -1;
    for (i=2; i<N; i++) {
        iMirror = (C << 1) - i;
        L[i] = 0;
        diff = R - i;
        if (diff > 0) L[i] = min(L[iMirror], diff);
        while (((i + L[i]) < N && (i - L[i]) > 0) && (!((i + L[i] + 1) & 1) || (text[(i + L[i] + 1) >> 1] == text[(i - L[i] - 1) >> 1]))) L[i]++;
        if (L[i] > maxLPSLength) {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
        if (i + L[i] > R)  {
            C = i;
            R = i + L[i];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength) >> 1;
    end = start + maxLPSLength - 1;
    for (i=start; i<=end; i++) ans += text[i];
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> text;
	Manachers();
	cout << ans << "\n" << ans.size() << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */