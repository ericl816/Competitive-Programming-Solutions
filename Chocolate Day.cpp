#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
#define INF 0x3f3f3f3f
using namespace std;

int N, T, a, b, c, L, cnt;
ll cups[MAXN], chocolates[MAXN], psa[MAXN], arr[MAXN];

int main () {
    scan(N); scan(T);
    while (T--) {
        scan(a); scan(b); scan(c);
        cups[a] += c;
        cups[b + 1] -= c;
    }
    for (int i=1; i<MAXN; i++) chocolates[i] = chocolates[i - 1] + cups[i];
    scan(L);
    psa[0] = 0;
    for (int i=1; i<MAXN; i++) psa[i] = psa[i - 1] + chocolates[i];
    int left = 1;
    for (int right=1; right<=N; ) {
      if (psa[right] - psa[left - 1] <= L) {
        cnt = max(cnt, right - left + 1);
        right++;
      }
      else {
        if (left == right) right++;
        left++;
      }
    }
    return !printf("%d\n", cnt);
}
