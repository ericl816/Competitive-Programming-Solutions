#include <bits/stdc++.h>
#define ll long long
#define MAXN 55
#define INF 0x3f3f3f3f
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

int n;
char s[MAXN];
int DP[MAXN][2][2];

// Original problem: https://open.kattis.com/problems/spinningup
int Solve (int l,  bool left_make, bool right_get) {
    int r = n - l - 1;
    if (l == r) {
        int x = s[l] - '0' + right_get;
        if (left_make) {
            return 10 - x;
        } else {
            return x == 10 ? INF : 0;
        }
    }
    if (l > r) {
        return (left_make == right_get) ? 0 : INF;
    }

    if (~DP[l][left_make][right_get])
        return DP[l][left_make][right_get];

    int res = INF;
    for (int left_rot=0; left_rot<=10; left_rot++) {
        for (int right_rot=0; right_rot<=10; right_rot++) {
            int left_dig = (s[l] - '0' + left_rot) % 10;
            bool did_left = (s[l] - '0' + left_rot) >= 10;

            int right_dig = (s[r] - '0' + right_get + right_rot) % 10;
            bool did_right = (s[r] - '0' + right_get + right_rot) >= 10;

            if ((left_dig == right_dig) && (left_make == did_left)) {
                res = min(res, left_rot + right_rot + Solve(l + 1, 0, did_right));

                if (left_rot > 0) res = min(res, left_rot - 1 + right_rot + Solve(l + 1, 1, did_right));
            }
        }
    }
    return DP[l][left_make][right_get] = res;
}

int main () {
    scanf("%s", s);
    n = strlen(s);
    memset(DP, -1, sizeof(DP));
    return !printf("%d\n", min(Solve(0, 0, 0), Solve(0, 1, 0)));
}