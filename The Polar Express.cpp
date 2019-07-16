#include <bits/stdc++.h>
#define ll long long
#define MAXM 20
#define MAXN 162

int ans, digit[MAXM];
ll L, R, DP[MAXM][MAXN + 1];

ll Recur (int pos, int s, bool flag) {
    if (s < 0) return 0;
    if (!pos) return !s;
    if (!flag && ~DP[pos][s]) return DP[pos][s];
    ll val = 0;
    int idx = !flag ? 9 : digit[pos];
    for (int i=0; i<=idx; i++) val += Recur(pos - 1, s - i, flag && (i == digit[pos]));
    if (!flag) return DP[pos][s] = val;
    else return val;
}

ll Solve (ll l, int s){
    int idx = 0;
    memset(digit, 0, sizeof digit);
    while (l) {
        idx++;
        digit[idx] = l % 10;
        l /= 10;
    }
    return Recur (idx, s, 1);
}

int main () {
    memset(DP, -1, sizeof DP);
    scanf("%lld %lld", &L, &R);
    for (int i=1; i<=MAXN; i++) ans += Solve(R, i) > Solve(L - 1, i);
    printf("%d\n", ans);
}