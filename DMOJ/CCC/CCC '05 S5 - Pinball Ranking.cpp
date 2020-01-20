#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
using namespace std;

int t, a[100010];
ll ans;

void merge_sort(int l, int r) {
    if(l==r) return;
    else {
        int b[100010];
        int m = (l+r)/2;
        merge_sort(l, m);
        merge_sort(m+1, r);
        int s = l, e = m+1;
        int cnt = l;
        while(s<=m && e<=r) {
            if(a[s]<=a[e]) {
                b[cnt++] = a[s];
                s++;
            }
            else {
                b[cnt++] = a[e];
                ans = ans + m-s+1;
                e++;
            }
        }
        while(s<=m) b[cnt++] = a[s++];
        while(e<=r) b[cnt++] = a[e++];
        for(int i=l; i<=r; i++) a[i] = b[i];
    }
}

int main() {
    scan(t);
    for(int i=0; i<t; i++) scan(a[i]);
    ans = 0;
    merge_sort(0, t - 1);
    ans += t;
    printf("%.2lf\n", ans *1.0 / t);
    return 0;
}