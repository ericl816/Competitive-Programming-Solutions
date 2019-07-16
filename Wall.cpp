#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 5000005
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
using namespace std;

struct Node {
    int opmin, opmax;
    // opmin = operation for adding and opmax = operation for removing
} tree[MAXN];

inline void Push_Down (int idx, int pos) {
    tree[idx].opmin = max(min(tree[idx].opmin, tree[pos].opmin), tree[pos].opmax);
    tree[idx].opmax = min(max(tree[idx].opmax, tree[pos].opmax), tree[pos].opmin);
}

inline void Push_Up (int idx, int op, int val) {
        if (op == 1) { // 1 = Adding phase
            tree[idx].opmin = max(tree[idx].opmin, val);
            tree[idx].opmax = max(tree[idx].opmax, val);
        } 
        else if (op == 2) { // 2 = Removing phase
            tree[idx].opmin = min(tree[idx].opmin, val);
            tree[idx].opmax = min(tree[idx].opmax, val);
        }
}
	
inline void Update (int idx, int l, int r, int l1, int r1, int op, int val) {
    if (l > r1 || r < l1) return;
    if (l >= l1 && r <= r1)  {
        Push_Up(idx, op, val);
        return;
    }
    Push_Down(idx << 1, idx);
    Push_Down(idx << 1 | 1, idx);
    int mid = (l + r) >> 1;
    tree[idx].opmin = INF;
    tree[idx].opmax = 0;
    Update(idx << 1, l, mid, l1, r1, op, val);
    Update(idx << 1 | 1, mid + 1, r, l1, r1, op, val);
}

inline int Query (int idx, int l, int r, int l1, int r1) {
    if (l > r1 || r < l1) return INF;
    if (l >= l1 && r <= r1) return min(tree[idx].opmin, tree[idx].opmax);
    Push_Down(idx << 1, idx);
    Push_Down(idx << 1 | 1, idx);
    int mid = (l + r) >> 1;
    return min(Query(idx << 1, l, mid, l1, r1), Query(idx << 1 | 1, mid + 1, r, l1, r1));
}

void buildWall (int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
    for (int i=0; i<k; i++) Update(1, 1, n, left[i] + 1, right[i] + 1, op[i], height[i]);
    for (int i=0; i<n; i++) finalHeight[i] = Query(1, 1, n, i + 1, i + 1);
}

int main () {
    int n, k;
    int op[k], left[k], right[k], height[k], finalHeight[n];
    scanf("%d %d", &n, &k);
    for (int i=0; i<k; i++) scanf("%d %d %d %d", &op[i], &left[i], &right[i], &height[i]);
    buildWall(n, k, op, left, right, height, finalHeight);
    for (int i=0; i<n; i++) printf("%d\n", finalHeight[i]);
    return 0;
}