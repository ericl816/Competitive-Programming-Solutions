#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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
using namespace std;

struct Node {
    int l, r, val, gcd, idx;
};

int N, M, x, y, arr[MAXN];
char ch;
Node seg[MAXN << 2];

inline int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

inline void Push_Up(int idx) {
    seg[idx].val = min(seg[idx << 1].val, seg[idx << 1 | 1].val);
    seg[idx].gcd = GCD(seg[idx << 1].gcd, seg[idx << 1 | 1].gcd);
    seg[idx].idx = 0;
    if (seg[idx].gcd == seg[idx << 1].gcd) seg[idx].idx += seg[idx << 1].idx;
    if (seg[idx].gcd == seg[idx << 1 | 1].gcd) seg[idx].idx += seg[idx << 1 | 1].idx;
}

inline void Build(int idx, int l, int r) {
    seg[idx].l = l, seg[idx].r = r;
    if (l == r) {
        seg[idx].val = arr[l];
        seg[idx].gcd = arr[l];
        seg[idx].idx = 1;
        return;
    }
    int mid = (l + r) >> 1;
    Build(idx << 1, l, mid);
    Build(idx << 1 | 1, mid + 1, r);
    Push_Up(idx);
}

inline void Update(int idx, int pos, int val) {
    int &l = seg[idx].l, &r = seg[idx].r;
    if (l == r) {
        seg[idx].val = val;
        seg[idx].gcd = val;
        seg[idx].idx = 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) Update(idx << 1, pos, val);
    else Update(idx << 1 | 1, pos, val);
    Push_Up(idx);
}

inline int QueryMin(int idx, int l1, int r1) {
    int &l = seg[idx].l, &r = seg[idx].r;
    int mid = (l + r) >> 1;
    if (l1 <= l && r1 >= r) return seg[idx].val;
    if (r1 <= mid) return QueryMin(idx << 1, l1, r1);
    if (l1 > mid) return QueryMin(idx << 1 | 1, l1, r1);
    return min(QueryMin(idx << 1, l1, mid), QueryMin(idx << 1 | 1, mid + 1, r1));
}

inline int QueryGCD(int idx, int l1, int r1) {
    int &l = seg[idx].l, &r = seg[idx].r;
    int mid = (l + r) >> 1;
    if (l == l1 && r == r1) return seg[idx].gcd;
    if (r1 <= mid) return QueryGCD(idx << 1, l1, r1);
    if (l1 > mid) return QueryGCD(idx << 1 | 1, l1, r1);
    return GCD(QueryGCD(idx << 1, l1, mid), QueryGCD(idx << 1 | 1, mid + 1, r1));
}

inline int QueryNum(int idx, int l1, int r1, int val) {
    int &l = seg[idx].l, &r = seg[idx].r;
    if (l == l1 && r == r1) return seg[idx].gcd ^ val ? 0 : seg[idx].idx;
    int mid = (l + r) >> 1;
    if (r1 <= mid) return QueryNum(idx << 1, l1, r1, val);
    if (l1 > mid) return QueryNum(idx << 1 | 1, l1, r1, val);
    return QueryNum(idx << 1, l1, mid, val) + QueryNum(idx << 1 | 1, mid + 1, r1, val);
}

int main () {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    Build(1, 1, N);
    for (int i = 0; i < M; i++) {
        scanf(" %c %d %d", &ch, &x, &y); 
        if (ch == 'C') Update(1, x, y);
        else if (ch == 'M') printf("%d\n", QueryMin(1, x, y));
        else if (ch == 'G') printf("%d\n", QueryGCD(1, x, y));
        else if (ch == 'Q') printf("%d\n", QueryNum(1, x, y, QueryGCD(1, x, y)));
    }
}