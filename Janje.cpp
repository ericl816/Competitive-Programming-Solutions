#include<bits/stdc++.h>
#define ll long long
int N, K;
ll cnt, arr[8][3] = {
{0, 2, 1572858},
{0, 0, 96},
{0, 2, 18},
{0, 2, 24570},
{0, 0, 12},
{0, 0, 6},
{0, 0, 96},
{0, 2, 1073741820}
};

inline void Calc() {
  cnt = (ll) (K) * (K - 1) * (K - 2) / 6 * arr[N - 1][2];
  cnt += (ll) (K) * (K - 1) / 2 * arr[N - 1][1];
  cnt += (ll) (K) * arr[N - 1][0];
}

int main() {
    scanf("%d %d", &N, &K);
    Calc();
    printf("%lld\n", cnt);
}
