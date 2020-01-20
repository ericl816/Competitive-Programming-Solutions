#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define SEED 131
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

string s;

inline bool isPalindrome (int idx) {
    for (int i=0; i<idx; i++) if (s[i] ^ s[idx - i - 1]) return 0;
    return 1;
}

inline bool Hash (int idx) {
    ll hash1 = 0, hash2 = 0, res = 1;
    for (int i=0; i<idx; i++) {
        hash1 = (hash1 * SEED) % MOD;
        hash1 = (hash1 + s[i] - 'a' + 1) % MOD;
    }
    hash2 = hash1;
    for (int i=0; i<idx - 1; i++) res = (res * SEED) % MOD;
    for (int i=1; i + idx<=s.size(); i++) {
        hash1 = (hash1 - (res * (s[i - 1] - 'a' + 1)) % MOD + MOD) % MOD;
        hash1 = (hash1 * SEED) % MOD;
        hash1 = (hash1 + s[i + idx - 1] - 'a' + 1) % MOD;
        if (hash1 == hash2) return 1;
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
    getline(cin, s);
    for (int i=s.size() - 1; i>=1; i--) {
        if (isPalindrome(i) && Hash(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}