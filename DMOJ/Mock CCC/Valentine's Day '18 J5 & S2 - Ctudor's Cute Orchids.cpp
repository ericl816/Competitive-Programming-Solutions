#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 210
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

int N, M, minn = INF, cost;
int C[MAXN], D[MAXN], orchids[MAXN], num[MAXN];
int Q[MAXN][MAXN];

int main () {
    scan(N); scan(M);
    for (int i=1; i<=N; i++) scan(C[i]);
    for (int i=0; i<M; i++) {
        scan(D[i]);
        for (int j=1; j<=N; j++) scan(Q[i][j]);
    }
    for (int i=1; i<=N; i++) scan(orchids[i]);
    for (int i=0; i<(1 << M); i++) {
        memset(num, 0, sizeof(num));
        cost = 0;
        for (int j=0; j<M; j++) {
            if (i & (1 << j)) {
                cost += D[j];
                for (int k=1; k<=N; k++) num[k] += Q[j][k];    
            }
        }
        for (int j=1; j<=N; j++) {
            if (num[j] > orchids[j]) goto outer;
            cost += C[j] * (orchids[j] - num[j]);
        }
        minn = min(minn, cost);
        outer: continue;
    }
    return !printf("%d\n", minn);
}