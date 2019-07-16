#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
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

// Use suffix array!!!
// https://www.geeksforgeeks.org/substring-highest-frequency-length-product/

struct SuffixArray {
   const int L;
   string s;
   vector<vector<int> > P;
   vector<pair<pair<int,int>,int> > M;
   SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
      for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
      for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
        P.push_back(vector<int>(L, 0));
        for (int i = 0; i < L; i++) M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
        sort(M.begin(), M.end());
        for (int i = 0; i < L; i++) P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
      }    
  }
   vector<int> GetSuffixArray() { return P.back(); }
   inline int LongestCommonPrefix(int i, int j) {
      int len = 0;
      if (i == j) return L - i;
      for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
        if (P[k][i] == P[k][j]) {
          i += 1 << k;
          j += 1 << k;
          len += 1 << k;
       }
     }
     return len;
   }
};

vi hist;
stack<int> st;

inline int getMaxArea () {
    int n = hist.size();
    int max_area = 0, tp = 0, area_with_top = 0, i = 0;
    while (i < n) {
        if (st.empty() || hist[st.top()] <= hist[i]) st.push(i++);
        else {
            tp = st.top();
            st.pop();
            area_with_top = hist[tp] * (st.empty() ? i + 1 : i - st.top() );
            if (max_area < area_with_top) max_area = area_with_top;
       }
    }
    while (!st.empty()) {
        tp = st.top();
        st.pop();
        area_with_top = hist[tp] * (st.empty() ? i + 1 : i - st.top());
        if (max_area < area_with_top) max_area = area_with_top;
    }
    return max_area;
}

int ans;
string s;
vi v;
int a[MAXN];

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
  SuffixArray suffix(s);
  v = suffix.GetSuffixArray();
  // for (auto i : v) D("%d\n", i);
  for (size_t i=0; i<v.size(); i++) a[v[i]] = i;
  for (size_t i=0; i<s.size(); i++) {
    if (i + 1 < s.size()) hist.pb(suffix.LongestCommonPrefix(a[i], a[i + 1]));
  }
  ans = getMaxArea();
  cout << (ans > s.size() ? ans : s.size()) << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */