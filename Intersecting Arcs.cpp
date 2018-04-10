#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 510
#define INF 0x3f3f3f3f
#define MOD 1000000007
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

int N, K, idx;
ll DP[2][MAXN][MAXN];

// DP[a][b][c] = DP array where a = the first a dots, b = number of open arcs, c = number of ways to draw the arcs in the first a dots to have exactly c intersections
// There are 3 cases to consider: 
// 		1) Not putting any endpoints on the dot 
// 		2) Putting a left endpoint on the dot
// 		3) Putting a right endpoint on the dot
// This way is naive and will only pass the second subtask
// To optimize the solution, make the first dimension of the array store only 2 numbers: 1 or 0. Thus, the DP table can be compressed into: DP[2][N + 1][k + 1]
// The time complexity should be: O(N^2 * K), since we can use a PSA. The naive time complexity, however, is only: O(N^3 * K)

inline ll PSA_Query (int idx1, int idx2, int l, int r) {
    if (idx2 >= 0 && idx2 <= N) {
        if (r >= 0 && r <= K) {
            if (l - 1 >= 0) return (DP[idx1][idx2][r] - DP[idx1][idx2][l - 1] + MOD) % MOD;
            else return DP[idx1][idx2][r];
        }
    }
    return 0;
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    DP[0][0][0] = 1;
    for (int i=0; i<=N; i++) { // i = number of dots
        idx = i & 1;
        for (int j=0; j<=N; j++) { // j = number of open arcs
            for (int k=0; k<=K; k++) { // k = number of ways to draw arcs in exactly k intersections
                if (i == 0) {
                    if (j && k) DP[0][j][k] = 0;
                }
                else if (i && i < j) DP[idx][j][k] = 0;
                // For putting any endpoint on the dot, putting a right endpoint on the dot, and putting a left endpoint on the dot, respectively
                else DP[idx][j][k] = ((PSA_Query(idx ^ 1, j, k, k) % MOD + PSA_Query(idx ^ 1, j - 1, k, k) % MOD + PSA_Query(idx ^ 1, j + 1, k - j, k) % MOD) + MOD) % MOD;
                if (k) {
                    DP[idx][j][k] += DP[idx][j][k - 1]; // PSA
                    DP[idx][j][k] %= MOD;
                }
            }
        }
    }
    cout << (PSA_Query(N & 1, 0, K, K) + MOD) % MOD << endl;
    return 0;
}