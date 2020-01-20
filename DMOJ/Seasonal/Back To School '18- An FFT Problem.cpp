#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2010
#define INF 0x3f3f3f3f
#define MOD 998244353
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N;
ll arr[MAXN], DP[MAXN];


int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    DP[0] = 1LL;
    for (int i=0; i<N; i++) {
        for (int j=i; j>=0; j--) {
            DP[j + 1] = (DP[j + 1] + DP[j] * arr[i]) % MOD;
        }
    }
    for (int i=1; i<=N; i++) cout << (DP[i] + MOD) % MOD << " ";
    cout << "\n";
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */