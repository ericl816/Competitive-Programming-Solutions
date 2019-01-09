#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1000010
#define MAXN 20010
#define INF 0x3f3f3f3f
#define SEED 131
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

/* 
 * We can solve this question by using hashing and storing the frequency of each substring/hash value with a map
 * We have to binary search for the answer
 * The other approach is to use a suffix array
 */

int N, K;
int A[MAXN];
map<ll, ll> freq;
ll hashed[MAXN], qpow[MAXN];

inline ll Fpow (ll x, ll y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y & 1) return x * Fpow(x * x, y >> 1) % MOD;
    else return Fpow(x * x, y >> 1) % MOD;
}

inline bool Find (int size) {
    if (size == 0) return 1; // Corner case
    freq.clear();
    // freq[0] = 1;
    for (int i=size; i<=N; i++) {
        ll len = i - size + 1; // The length of the substring
        ll val = ((hashed[i] - (hashed[len - 1] * qpow[size]) % MOD) + MOD) % MOD;
        if (freq.find(val) == freq.end()) freq[val] = 1LL;
        else freq[val] += 1LL;
        if (freq[val] >= K) return 1; // Since the sequence with length equal to size occurs at least K times
    }
    return 0;
}

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    qpow[0] = hashed[0] = 1LL;
    for (int i=1; i<=MAXN; i++) qpow[i] = (((qpow[i - 1] * SEED) % MOD) + MOD) % MOD;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        hashed[i] = ((((hashed[i - 1] * SEED) + A[i]) % MOD) + MOD) % MOD;
    }
    int lo = 0, hi = N;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (Find(mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    if (Find(lo)) cout << lo << endl;
    else cout << lo - 1 << endl;
    return 0;
}