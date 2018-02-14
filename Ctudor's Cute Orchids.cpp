#include <bits/stdc++.h>
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
int n, m;
int cost[MAXN], deal_cost[MAXN];
int deals[MAXN][MAXN];

map<pair<int, vi>, int> memo;

inline int solve(int deal, const vector<int>& state) {
    auto key = mp(deal, state);
    if (memo.find(key) != end(memo)) return memo[key];
    int res = INF;
    if (deal >= 0) {
        int with_deal = deal_cost[deal];
        bool can_make = 1;
        vector<int> next_state(begin(state), end(state));
        for (int i=0; i<n; i++) {
            next_state[i] -= deals[deal][i];
            if (next_state[i] < 0) can_make = 0;
        }
        if (can_make) res = min(res, deal_cost[deal] + solve(deal - 1, next_state));
        res = min(res, solve(deal - 1, state));
    } 
    else {
        int score = 0;
        for (int i=0; i<n; i++) score += cost[i] * state[i];
        res = min(res, score);
    }
    return memo[key] = res;
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> cost[i];
    for (int i=0; i<m; i++) {
        cin >> deal_cost[i];
        for (int j=0; j<n; j++) cin >> deals[i][j];
    }
    vector<int> state(n);
    for (int i=0; i<n; i++) cin >> state[i];
    int ans = solve(m - 1, state);
    cout << ans << endl;
    return 0;
}