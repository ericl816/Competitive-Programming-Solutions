#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
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

struct choc {
    string s = "";
    int a = 0, b = 0, c = 0;
    bool operator < (const choc &ch) const {
        int suma = a + b + c, sumb = ch.a + ch.b + ch.c;
        if (suma != sumb) return suma < sumb;
        if (c != ch.c) return c < ch.c;
        if (b != ch.b) return b < ch.b;
        return a < ch.a;
    }
    bool operator != (const choc &ch) const {
        return a != ch.a || b != ch.b || c != ch.c;
    }
};

int N, P, F, G, idx;
string name;
vector<choc> vec;

inline void Do_Test_Cases () {
    int TEST_CASES = 10;
    while (TEST_CASES--) {
        vec.clear();
        stack<string> st;
        cin >> N >> name;
        for (int i=0; i<N; i++) {
            choc cc;
            cc.s = name;
            string res;
            while (1) {
                cin >> res;
                if (res == "*") break;
                if (res == "J") {
                    cin >> P >> F >> G;
                    cc.a += P;
                    cc.b += F;
                    cc.c += G;
                }
                else {
                    name = res;
                    break;
                }
            }
            // cout << cc.s << endl;
            vec.pb(cc);
        }
        sort(allof(vec));
        choc winner = vec.back();
        st.push(winner.s);
        for (size_t i=vec.size() - 2; i>=0; i--) {
            if (vec[i] != winner) break;
            st.push(vec[i].s);
        }
        cout << st.top();
        st.pop();
        while (!st.empty()) {
          cout << ", " << st.top();
          st.pop();
        }
        cout << "\n";
        idx++;
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
    Do_Test_Cases();
    return 0;
}