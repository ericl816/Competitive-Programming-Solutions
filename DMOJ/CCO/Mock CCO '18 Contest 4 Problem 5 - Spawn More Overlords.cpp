#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXM 110
#define MAXN 15010
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

int N, T, M, S, coins, h, ans;
int V[MAXM], C[MAXM];
int dp1[MAXN], dp2[MAXN], nextt[MAXN], value[MAXN];

int main () {
    scan(N); scan(T);
    int i, j, k, lo, hi;
    for (i=0; i<N; i++) scan(V[i]);
    for (i=0; i<N; i++) scan(C[i]);
    for (i=0; i<N; i++) M = max(M, V[i] * V[i]);
    // memset(dp1, INF, sizeof(dp1));
    // memset(dp2, INF, sizeof(dp2));
    for (i=1; i<=M; i++) dp1[i] = dp2[i] = INF;
    for (i=0; i<N; i++) {
        for (j=0; j<V[i]; j++) {
            S = coins = 0;
            for (k=j; k<=M; k += V[i]) {
                value[S++] = dp1[k] - coins;
                coins++;
            }
            for (k=S - 1; k>=0; k--) {
                for (h = k + 1; h < S && value[h] > value[k]; h = nextt[h]);
                nextt[k] = h;
            }
            for (lo=hi=0; hi<S; hi++) {
                if (hi - lo > C[i]) lo++;
                while (nextt[lo] <= hi) lo = nextt[lo];
                dp1[hi * V[i] + j] = value[lo] + hi;
            }
        }
    }
    for (i=0; i<N; i++) for (j=V[i]; j<=M; j++) dp2[j] = min(dp2[j], dp2[j - V[i]] + 1);
    ans = INF;
    for (i=T; i<=M; i++) ans = min(ans, dp1[i - T] + dp2[i]);
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}