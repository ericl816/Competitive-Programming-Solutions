#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 20010
#define MOD 100000000
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

// Problem Statement: http://poj.org/problem?id=3261
// Use LCP and Suffix Array!!!

int len, r, i, j, k, ans;
int st[MAXN], ls[MAXN], nextt[MAXN];

inline bool Cmp (const int &a, const int &b) {
    if (a == b) return 0;
    int i = a, j = b;
    while (st[i] == st[j]) {
        int d = min(nextt[i] - i, nextt[j] - j);
        i += d;
        j += d;
    }
    return st[i] < st[j];
}

int main () {
    scan(len); scan(r);
    for (i=0; i<len; i++) {
        scan(st[i]);
        ls[i] = i;
    }
    nextt[len - 1] = len;
    for (i=len - 2; i>=0; i--) nextt[i] = (st[i] == st[i + 1]) ? nextt[i + 1] : i + 1;
    sort(ls, ls + len, Cmp);
    for (i=0; i<len - r + 1; i++) {
        j = ls[i];
        k = ls[i + r - 1];
        while (st[j] == st[k]) {
            int d = min(nextt[j] - j, nextt[k] - k);
            j += d;
            k += d;
        }
        ans = max(ans, j - ls[i]);
    }
    return !printf("%d\n", ans);
}