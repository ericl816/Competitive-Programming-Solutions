#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long 
#define INF 0x3f3f3f3f
#define MAXN 200010
#define min(a, b) (a) < (b) ? (a) : (b)
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

int main () {
  scan(N);
  for (int i=0; i<N; i++) scan(arr[i]);
  Build(1, 1, N);
  for (int i=0; (i << 1)<N; i++) {
    Update(1, 1, arr[i], 1);
    Update(1, 1, arr[i << 1], -1);
    Update(1, 1, arr[i << 1 | 1], -1);
    if (tree[1].val >= 0) x = i + 1;
  }
  printf("%d\n", (flag ? 0 : x));
}
