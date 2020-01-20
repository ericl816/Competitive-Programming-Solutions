#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
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

int n, f, res;
ll ans;
bool prime[MAXN];

inline void Sieve(int n) {
    for (int a=2; a*a<=n; a++) if (prime[a]) for (int b=a*2; b<=n; b += a) prime[b] = 0;
}

int main () {
    cin >> n;
    memset (prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    Sieve (100000);
    while (n--) {
        cin >> f;
        if (prime[f]) ans++;
    }
    cout << ans << "\n";
    return 0;
}