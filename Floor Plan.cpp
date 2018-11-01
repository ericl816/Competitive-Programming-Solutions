#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 30
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
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

int n, r, c, cnt, ans1, ans2;
vi flooring;
string s;
char grid[MAXN][MAXN];
bool vis[MAXN][MAXN];
int movex[4] = {0, 0, -1, 1};
int movey[4] = {-1, 1, 0, 0};

inline void DFS (int a, int b) {
    vis[a][b] = 1;
    cnt++;
    for (int i=0; i<4; i++) {
        int nextx = movex[i] + a, nexty = movey[i] + b;
        if (vis[nextx][nexty] || nextx < 0 || nextx >= r || nexty < 0 || nexty >= c || grid[nextx][nexty] == 'I') continue;
        DFS(nextx, nexty);
    }
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r >> c;
    for (int i=0; i<r; i++) {
        cin >> s;
        for (int j=0; j<c; j++) {
            grid[i][j] = s[j];
        }
    }
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                cnt = 0;
                DFS(i, j);
                flooring.pb(cnt);
            }
        }
    }
    sort(flooring.begin(), flooring.end());
    reverse(flooring.begin(), flooring.end());
    for (size_t i=0; i<flooring.size(); i++) {
        if (n - flooring[i] >= 0) {
            n -= flooring[i];
            ans1++;
        }
        else {
            if (ans1 == 1) cout << "1 room, " << n << " square metre(s) left over\n";
            else cout << ans1 << " rooms, " << n << " square metre(s) left over\n";
            return 0;
        }
    }
    if (ans1 == 1) cout << "1 room, " << n << " square metre(s) left over\n";
    else cout << ans1 << " rooms, " << n << " square metre(s) left over\n";
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */