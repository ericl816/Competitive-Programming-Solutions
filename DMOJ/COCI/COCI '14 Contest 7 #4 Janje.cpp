#include<bits/stdc++.h>
#define ull unsigned long long
ull N, K, cnt, arr[8][3] = {
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
  cnt = (ull) arr[N - 1][2] * (K) * (K - 1) * (K - 2) / 6;
  cnt += (ull) arr[N - 1][1] * (K) * (K - 1) / 2;
  cnt += (ull) arr[N - 1][0] * (K);
}

int main() {
    scanf("%llu %llu", &N, &K);
    Calc();
    printf("%llu\n", cnt);
}