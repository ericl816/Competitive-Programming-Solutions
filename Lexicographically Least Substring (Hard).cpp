#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
#define SEED 131
#define MOD 1000000007
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

string s;
ll K, minn;
ll hashed[MAXN], qpow[MAXN];

inline ll Get_Hash_Substr (ll a, ll b) {
    if (a == 0) return hashed[b];
    else {
        ll len = b - a + 1;
        return ((hashed[b] - (hashed[a - 1] * qpow[len]) % MOD) + MOD) % MOD;
    }
    return -1;
}

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> K;
    ll curr = 0;
    qpow[0] = hashed[0] = 1LL;
    for (size_t i=0; i<s.size(); i++) {
        qpow[i + 1] = (((qpow[i] * SEED) % MOD) + MOD) % MOD;
        hashed[i] = ((((hashed[i - 1] * SEED) + s[i]) % MOD) + MOD) % MOD;
    }
    for (ll i=1; i + K<=s.size(); i++) {
        ll lo = 0;
        ll hi = K - 1;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (Get_Hash_Substr(minn, minn + mid) == Get_Hash_Substr(i, i + mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        if (s[i + lo] < s[minn + lo]) minn = i;
    }
    cout << s.substr(minn, K) << endl;
    return 0;
}