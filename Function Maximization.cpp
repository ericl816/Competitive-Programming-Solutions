#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 5010
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

// Keep in mind that the values for n range from [K, K + 5000]
// Using Wilson's theorem, the function f(x) reduces to x if x is prime, or −1 otherwise.

int N, Q, op, l, r, v;
ll K;
ll n[MAXN];
bitset<MAXM> primes;

inline ull mulMod (ull a, ull b, ull mod) {
    ull x = 0, y = a % mod;
    while (b) {
        if (b & 1) x = (x + y) % mod;
        y = (y << 1) % mod;
        b >>= 1;
    }
    return x % mod;
}

inline ull powMod(ull base, ull pow, ull mod) {
    ull x = 1, y = base;
    while (pow) {
        if (pow & 1) x = mulMod(x, y, mod);
        y = mulMod(y, y, mod);
        pow >>= 1;
    }
    return x % mod;
}

inline bool isPrime(ull n, int iterations) {
    if (n < 2 || (n != 2 && n % 2 == 0)) return 0;
    ull s = n - 1;
    while (s % 2 == 0) s /= 2;
    srand(time(0));
    for (int i=0; i<iterations; i++) {
        ull temp = s, r = powMod(rand() % (n - 1) + 1, temp, n);
        while (temp != n - 1 && r != 1 && r != n - 1) {
            r = mulMod(r, r, n);
            temp *= 2;
        }
        if (r != n - 1 && temp % 2 == 0) return 0;
    }
    return 1;
}

struct Node {
    int l, r;
    ll lazy;
    bitset<MAXM> val;
};

struct Seg {
private:
    int N;
    vector<Node> tree;

public:
    Seg(int N) : N(N), tree(N << 2) { }

    // Bitshift left if lazy > 0, right if lazy < 0
    inline void Push_Down (int idx) {
        if (tree[idx].lazy > 0) tree[idx].val <<= tree[idx].lazy;
        else if (tree[idx].lazy < 0) tree[idx].val >>= abs(tree[idx].lazy);
    	if (tree[idx].lazy && tree[idx].l ^ tree[idx].r) {
            tree[idx << 1].lazy += tree[idx].lazy;
            tree[idx << 1 | 1].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }

    inline void Push_Up (int idx) {
        tree[idx].val = tree[idx << 1].val | tree[idx << 1 | 1].val;
    }

    inline void Build (int idx, int l, int r) {
        tree[idx].l = l, tree[idx].r = r;
        if (l == r) {
            tree[idx].val.set(n[l] - K);
            return;
        }
        int mid = (l + r) >> 1;
        Build(idx << 1, l, mid);
        Build(idx << 1 | 1, mid + 1, r);
        Push_Up(idx);
    }

    inline void Update (int idx, int l, int r, int val) {
    	Push_Down(idx);
    	if (tree[idx].l > r || tree[idx].r < l) return;
    	if (tree[idx].l >= l && tree[idx].r <= r) {
            tree[idx].lazy = val;
            Push_Down(idx);
            return;
    	}
    	Update(idx << 1, l, r, val);
    	Update(idx << 1 | 1, l, r, val);
    	Push_Up(idx);
    }

    inline bitset<MAXM> Query (int idx, int l, int r) {
    	Push_Down(idx);
        if (tree[idx].l > r || tree[idx].r < l) return bitset<MAXM>();
        if (tree[idx].l >= l && tree[idx].r <= r) return tree[idx].val;
        return Query(idx << 1, l, r) | Query(idx << 1 | 1, l, r);
    }
};

Seg tree(MAXN);

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q >> K;
    for (int i=1; i<=N; i++) cin >> n[i];
    for (ll i=K; i<=K + MAXM; i++) {
        if (isPrime(i, 5)) primes[i - K] = 1;
    }
    tree.Build(1, 1, N);
    while (Q--) {
        cin >> op >> l >> r;
        if (op == 1) {
            bool prime = 0;
            bitset<MAXM> flag = tree.Query(1, l, r);
            flag &= primes;
            for (int i=MAXM; i>=0; i--) {
                if (flag[i]) {
                    cout << K + i << "\n";
                    prime = 1;
                    break;
                }
            }
            if (!prime || !flag.any()) cout << -1 << "\n";
        }
        else {
            cin >> v;
            tree.Update(1, l, r, v);
        }
    }
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */