#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 70
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int movex[4] = {-1, -1, 1, 1};
int movey[4] = {-1, 1, 1, -1};
ll x, y;
ll fib[MAXN], leftx[MAXN], rightx[MAXN], downy[MAXN], upy[MAXN]; // For precomputing the squares
    
inline void PreCompute () {
    fib[0] = fib[1] = 1;
    for (int i=2; i<MAXN; i++) fib[i] = fib[i - 1] + fib[i - 2];
    ll currx = 1, curry = 0, idx = 0; // Starts at the top-right corner of first unit square: (1, 0)
    for (int i=0; i<MAXN; i++) {
        leftx[i] = currx;
        downy[i] = curry;
        currx += fib[i] * movex[idx];
        curry += fib[i] * movey[idx];
        idx = (idx + 1) % 4;
        rightx[i] = currx;
        upy[i] = curry;
        if (leftx[i] > rightx[i]) swap(leftx[i], rightx[i]);
        if (downy[i] > upy[i]) swap(downy[i], upy[i]);
    }
}

inline void Solve () {
    cin >> x >> y;
    for (int i=0; i<MAXN; i++) {
        if (leftx[i] <= x && x <= rightx[i] && downy[i] <= y && y <= upy[i]) {
            cout << i + 1 << "\n";
            return;
        }
    }
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    // freopen("DATA41.txt", "r", stdin);
    int TEST_CASES = 10;
    PreCompute();
    while (TEST_CASES--) {
        Solve();
    }
    return 0;
}