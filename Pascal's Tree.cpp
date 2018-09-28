#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
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
#ifdef DEBUG
  #define D(x...) printf(x)
#else
  #define D(x...)
#endif
using namespace std;

inline ll PowMod (ll a, ll b) {
  ll val = 1;
  while (b) {
    if (b & 1) val = (val * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return val;
}

int N, M;
int primes[MAXN];
mii freq;

struct Node {
  int l, r;
  ll val;
};

struct Seg {
private:
  int N;
  vector<Node> tree;

public:
  Seg (int N) : N(N), tree(N << 2) {
    for (int i=1; i<=N << 2; i++) tree[i].val = 1;
  }

  inline void Push_Up (int idx) {
    tree[idx].val = (tree[idx << 1].val * tree[idx << 1 | 1].val) % M;
  }

  inline void Build (int idx, int l, int r) {
    tree[idx].l = l, tree[idx].r = r;
    if (l == r) return;
    int mid = (l + r) >> 1;
    Build(idx << 1, l, mid);
    Build(idx << 1 | 1, mid + 1, r);
  }

  inline void Update (int idx, int l, int r, int ind) {
    if (l > ind || r < ind) return;
    if (l == r) {
      tree[idx].val = PowMod(ind, freq[ind], M);
      return;
    }
    int mid = (l + r) >> 1;
    Update(idx << 1, l, mid, ind);
    Update(idx << 1 | 1, mid + 1, r, ind);
    Push_Up(idx);
  }

  inline ll Query () {
    return tree[1].val;
  }
};

Seg tree(MAXN);

inline void Insert_Erase (int x, int y) {
  while (x > 1) {
    int res = primes[x];
    freq[res]++;
    tree.Update(1, 1, N, res);
    x /= res;
  }
  while (y > 1) {
    int res = primes[y];
    freq[res]--;
    tree.Update(1, 1, N, res);
    y /= res;
  }
}

int main () {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  primes[1] = 1;
  for (int i=2; i<=N; i++) if (!primes[i]) for (int j=i; j<=N; j+=i) primes[j] = i;
  // for (int i=2; i<=N; i++) cout << primes[i] << " ";
  // cout << endl;
  tree.Build(1, 1, N);
  cout << 1 << "\n";
  for (int i=1; i<=N; i++) {
    Insert_Erase(N - i + 1, i);
    cout << (tree.Query() + M) % M << "\n";
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