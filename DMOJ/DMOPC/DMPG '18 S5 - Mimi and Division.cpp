#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 510
#define MAXN 200010
#define INF 0x3f3f3f3f
#define SIZE 450
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

int N, Q, op, l, r, x, u, v, cnt;
int A[MAXN], blocks[MAXN];
int good[MAXN][MAXM];

int main () {
    scan(N); scan(Q);
    for (int i=0; i<N; i++) {
        scan(A[i]);
        blocks[i] = i / ceil(sqrt(N));
        for (int j=1; j<=sqrt(A[i]); j++) {
            if (A[i] % j == 0) {
                good[j][blocks[i]]++;
                if (j * j ^ A[i]) good[A[i] / j][blocks[i]]++;
            }
        }
    }
    while (Q--) {
        scan(op);
        if (op == 1) {
            cnt = 0;
            scan(l); scan(r); scan(x);
            if (blocks[--l] == blocks[--r]) {
                for (l; l<=r; l++) {
                    if (A[l] % x == 0) cnt++;
                }
            }
            else {
                while (l && blocks[l - 1] == blocks[l]) {
                    if (A[l] % x == 0) cnt++;
                    l++;
                }
                while (blocks[r] == blocks[r + 1]) {
                    if (A[r] % x == 0) cnt++;
                    r--;
                }
                for (int i=blocks[l]; i<=blocks[r]; i++) cnt += good[x][i];
            }
            printf("%d\n", cnt);
        }
        else if (op == 2) {
            scan(u); scan(v);
            for (int i=1; i<=sqrt(A[--u]); i++) {
                if (A[u] % i == 0) {
                    good[i][blocks[u]]--;
                    if (i * i ^ A[u]) good[A[u] / i][blocks[u]]--;
                }
            }
            A[u] = v;
            for (int i=1; i<=sqrt(A[u]); i++) {
                if (A[u] % i == 0) {
                    good[i][blocks[u]]++;
                    if (i * i ^ A[u]) good[A[u] / i][blocks[u]]++;
                }
            }
        }
    }
    return 0;
}