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
#define DEBUG 1
#ifdef DEBUG
  #define D(x...) printf(x)
#else
  #define D(x...)
#endif
using namespace std;

int N, arr[MAXN], x;
bool flag;

struct Node {
public:
  int l, r, val, lazy;
} tree[MAXN << 2];

void Push_Down (int idx) {
  if (tree[idx].lazy ^ 0) {
    tree[idx << 1].lazy += tree[idx].lazy;
    tree[idx << 1 | 1].lazy += tree[idx].lazy;
    tree[idx << 1].val += tree[idx].lazy;
    tree[idx << 1 | 1].val += tree[idx].lazy;
    tree[idx].lazy = 0;
  }
}

void Push_Up (int idx) {
    tree[idx].val = min(tree[idx << 1].val, tree[idx << 1 | 1].val);
}

void Build (int idx, int l, int r) {
  tree[idx] = Node {l, r};
  if (l ^ r) {
    int mid = (l + r) >> 1;
    Build(idx << 1, l, mid);
    Build(idx << 1 | 1, mid + 1, r);
  }
}

void Update (int idx, int l, int r, int val) {
  Push_Down(idx);
  if (l <= tree[idx].l && r >= tree[idx].r) {
    tree[idx].lazy += val;
    tree[idx].val += val;
    Push_Down(idx);
    return;
  }
  else if (l > tree[idx].r || r < tree[idx].l) flag = 1;
  int mid = (tree[idx].l + tree[idx].r) >> 1;
  if (r <= mid) Update(idx << 1, l, r, val);
  else if (l > mid) Update(idx << 1 | 1, l, r, val);
  else {
    Update(idx << 1, l, mid, val);
    Update(idx << 1 | 1, mid + 1, r, val);
  }
  Push_Up(idx);
}

int main (int argc, char const *argv[]) {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  scan(N);
  for (int i=0; i<N; i++) scan(arr[i]);
  Build(1, 1, N);
  for (int i=0; (i << 1)<N; i++) {
    Update(1, 1, arr[i << 1], -1);
    Update(1, 1, arr[i << 1 | 1], -1);
    Update(1, 1, arr[i], 2);
    if (tree[1].val == 0) x = i + 1;
  }
  return !printf("%d\n", (flag ? 0 : x));
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */