#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXM 15
#define MAXN 5010
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

int R, C, op, SIZE;
int flag[MAXM];
int DP[MAXM][MAXN];
vi vec;

int main() {
    scan(R); scan(C);
    SIZE = 1 << C;
    for (int i=1; i<=R; i++) {
        for (int j=0; j<C; j++) {
            scan(op);
            if (!op) flag[i] |= 1 << j;
        }
    }
    for (int i=0; i<SIZE; i++) if (!(i & (i << 1))) vec.pb(i);
    for (int i=0; i<SIZE; i++) DP[0][i] = 1;
    for (int i=1; i<=R; i++) {
        DP[i][SIZE - 1] = 0;
        for (int j=0; j<SIZE; j++) {
            if (~j & flag[i]) continue;
            for (size_t k=0; k<vec.size(); k++) {
                int &next = vec[k];
                if (next & j) continue;
                DP[i][j] += DP[i - 1][next | flag[i - 1]];
                DP[i][j] %= MOD;
            }
        }
    }
    return !printf("%d\n", DP[R][flag[R]]);
}