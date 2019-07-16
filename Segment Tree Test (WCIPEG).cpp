#include <bits/stdc++.h>
using namespace std;

int n, m, idx, x, y, z, ans, tree[400001], arr[100001];
char ch;

void build (int val, int l, int r) {
    if (l == r){
        tree[val] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;

    build(val * 2, l, mid);
    build(val * 2 + 1, mid + 1, r);

    tree[val] = min(tree[val * 2], tree[val * 2 + 1]);
    return;
}

void update (int val, int l, int r, int idx, int pos){
    if (l == r){
        tree[val] = pos;
        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid)
        update (val * 2, l, mid, idx, pos);
    else
        update (val * 2 + 1, mid + 1, r, idx, pos);
    tree[val] = min(tree[val * 2], tree[val * 2 + 1]);
    return;
}

int query (int val, int l, int r, int l1, int r1){
    if (l > r1 || r < l1)
      return 1000002;
    
    if (l1 <= l && r1 >= r) 
      return tree[val];

    int mid = (l + r) >> 1;

    return min(query(val * 2, l, mid, l1, r1), query(val * 2 + 1, mid + 1, r, l1, r1));
}

int main(){
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    build (1, 0, n - 1);
    for (int i=0; i<m; i++){
        scanf(" %c %d %d", &ch, &idx, &x);
       if (ch == 'M') update (1, 0, n - 1, idx, x);
       else if (ch == 'Q') {
        ans = query (1, 0, n - 1, idx, x);
        printf("%d\n", ans);
        }
    }
}
