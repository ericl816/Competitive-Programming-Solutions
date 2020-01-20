#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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

int N;
ll A[MAXN];
ll gcd, ans = 1;

inline ll GCD (ll n1, ll n2) {
    return n2 == 0 ? n1 : GCD(n2, n1 % n2);
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        gcd = GCD(gcd, A[i]);
    }
    for (ll i=2; i<=(ll) sqrt(gcd); i++) {
        if (gcd % i == 0) ans = max(ans, i);
        while (gcd % i == 0) gcd /= i;
    }
    ans = max(ans, gcd);
    if (ans == 1) cout << "DNE" << endl;
    else cout << ans << endl;
    return 0;
}