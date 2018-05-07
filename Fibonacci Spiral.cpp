#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 75
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

typedef struct {
  ull a, b;
} Matrix;

int movex[4] = {-1, -1, 1, 1};
int movey[4] = {-1, 1, 1, -1};
ll x, y;
ll leftx[MAXN], rightx[MAXN], downy[MAXN], upy[MAXN]; // For precomputing the squares

Matrix Fib (ull n) {
    if (!n) return (Matrix) { 0, 1 };
    else {
        ull a, b, c, d;
        Matrix ret = Fib (n >> 1);
        a = ret.a; 
        b = ret.b;
        c = (ull) (a * (b * 2ull % MOD - a + MOD) % MOD);
        d = (ull) (a * a % MOD + b * b % MOD);
        if (!(n & 1)) return (Matrix) { c % MOD, d % MOD };
        else if (n & 1) return (Matrix) { d % MOD, c % MOD + d % MOD};
    }
}
    
inline void PreCompute () {
    ll currx = 1, curry = 0, idx = 0; // Starts at the top-right corner of first unit square: (1, 0)
    for (int i=0; i<MAXN; i++) {
        leftx[i] = currx;
        downy[i] = curry;
        currx += Fib(i + 1).a * movex[idx];
        curry += Fib(i + 1).a * movey[idx];
        idx = (idx + 1) % 4;
        rightx[i] = currx;
        upy[i] = curry;
        if (leftx[i] > rightx[i]) swap(leftx[i], rightx[i]);
        if (downy[i] > upy[i]) swap(downy[i], upy[i]);
    }
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    // freopen("DATA11.txt", "r", stdin);
    int TEST_CASES = 10;
    PreCompute();
    while (TEST_CASES--) {
        cin >> x >> y;
        for (int i=0; i<MAXN; i++) {
            if (leftx[i] <= x && x <= rightx[i] && downy[i] <= y && y <= upy[i]) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }
    return 0;
}