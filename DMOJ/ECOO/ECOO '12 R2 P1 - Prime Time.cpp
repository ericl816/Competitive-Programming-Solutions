#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 500010
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

int TEST_CASES = 5;
int N, x, gcd;
bool isPrime[MAXN];
vi vec, primes;
string s, ss = " ABCDEFGHIJKLMNOPQRSTUVWXYZ.,!?";

inline void Sieve () {
	memset(isPrime, 1, sizeof(isPrime));
	for (int i=2; i<MAXN; i++) {
		if (isPrime[i]) {
			for (int j=i * 2; j<MAXN; j += i) isPrime[j] = 0;
			primes.pb(i);
		}
	}
}

inline void Do_Test_Cases () {
    while (TEST_CASES--) {
        // Put code here...ECOO
        vec.clear();
        cin >> N;
        s = "";
        while (N--) {
        	cin >> x;
        	vec.pb(x);
        }
        gcd = vec[0];
        for (size_t i=1; i<vec.size(); i++) gcd = GCD(gcd, vec[i]);
        for (auto i : primes) {
        	if (gcd % i == 0) {
        		for (auto j : vec) {
        			int res = j / i;
        			int idx1 = res / 100, idx2 = res % 100;
        			if (0 <= idx1 && idx1 <= 30 && 0 <= idx2 && idx2 <= 30) {
        				// cout << idx1 << " " << idx2 << " " << ss[idx1] << " " << ss[idx2] << endl;
        				s += ss[idx1];
        				s += ss[idx2];
        			}
        			else break;
        		}
        	}
        }
        cout << s << "\n";
        fflush(stdout);
    }
}

int main () {
    #ifdef NOT_DMOJ
    freopen("DATA11.txt", "r", stdin);
    freopen("DATA11out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Sieve();
    Do_Test_Cases();
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