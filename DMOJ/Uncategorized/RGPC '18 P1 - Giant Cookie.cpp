#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

int N, M, ans;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    if (N % M == 0) {
        cout << "yes " << N / M << endl;
        return 0;
    }
    for (int i=1; i<=10000; i++) {
        if (N % (M + i) == 0) {
            ans = i;
            goto outer;
        }
    }
    outer:
    cout << "no " << ans << endl;
    return 0;
}