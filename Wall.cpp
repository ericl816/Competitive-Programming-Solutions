#include <bits/stdc++.h>
using namespace std;

struct Node {
    int opmin, opmax; 
};

Node tree[5000005];

inline void Push_Down (int idx, int pos) {
    tree[idx].opmin = max(min(tree[idx].opmin, tree[pos].opmin), tree[pos].opmax);
    tree[idx].opmax = min(max(tree[idx].opmax, tree[pos].opmax), tree[pos].opmin);
}

inline void Push_Up (int idx, int op, int val) {
        if (op == 1) {
            tree[idx].opmin = max(tree[idx].opmin, val);
            tree[idx].opmax = max(tree[idx].opmax, val);
        } 
        else if (op == 2) {
            tree[idx].opmin = min(tree[idx].opmin, val);
            tree[idx].opmax = min(tree[idx].opmax, val);
        }
}	
	
inline void Update (int idx, int l1, int r1, int l, int r, int op, int val) {
    if (r < l1 || l > r1) return;
    if (l <= l1 && r >= r1)  {
        Push_Up(idx, op, val);
        return;
    }
    Push_Down(idx << 1, idx);
    Push_Down(idx << 1 | 1, idx);
    int mid = (l1 + r1) >> 1;
    tree[idx].opmin = 0x3f3f3f3f;
    tree[idx].opmax = 0;
    Update(idx << 1, l1, mid, l, r, op, val);
    Update(idx << 1 | 1, mid + 1, r1, l, r, op, val);
}

inline int Query (int idx, int l1, int r1, int l, int r) {
    if (r < l1 || l > r1) return 0x3f3f3f3f;
    if (l <= l1 && r >= r1) return min(tree[idx].opmin, tree[idx].opmax);
    Push_Down(idx << 1, idx);
    Push_Down(idx << 1 | 1, idx);
    int mid = (l1 + r1) >> 1;
    return min(Query(idx << 1, l1, mid, l, r), Query(idx << 1 | 1, mid + 1, r1, l, r));
}

void buildWall(int n, int k, int op[], int left[], int right[], int height[], int finalHeight[]) {
    for(int i=0; i<k; i++) Update(1, 1, n, left[i] + 1, right[i] + 1, op[i], height[i]);
    for(int i=0; i<n; i++) finalHeight[i] = Query(1, 1, n, i + 1, i + 1);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int op[k], left[k], right[k], height[k], finalHeight[n];
    for(int i=0; i<k; i++) scanf("%d %d %d %d", &op[i], &left[i], &right[i], &height[i]);
    buildWall(n, k, op, left, right, height, finalHeight);
    for(int i=0; i<n; i++) printf("%d\n", finalHeight[i]);
    return 0;
}
