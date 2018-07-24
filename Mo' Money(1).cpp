#include <bits/stdc++.h>
#define ll long long
#define MAXM 20
#define MAXN 1000010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int n, t, coins[MAXM], ans, val;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i=0; i<n; i++) cin >> coins[i];
    for (int i=0; i<1 << n; i++) {
        val = 0;
        for (int j=0; j<n; j++) if (i & (1 << j)) val += coins[j];
        if (val == t) ans++;
    }
    cout << ans << endl;
    return 0;
}