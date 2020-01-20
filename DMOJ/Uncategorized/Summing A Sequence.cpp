#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N;
ll arr[1000010], DP[1000010];
inline ll Solve (int i) {
    if (i <= 0) return 0;
    ll &res = DP[i];
    if (~res) return res;
    return res = max(0LL, max(Solve(i - 1), Solve(i - 2) + arr[i]));
}
int main() {
    cin >> N;
    for (int i=1; i<=N; i++) cin >> arr[i];
    memset(DP, -1, sizeof(DP));
    cout << Solve(N) << "\n";
    return 0;
}