#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 200010
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

int N, M, Q;
vector<pii> acc;

struct Disjoint {
private:
    int N;
    vi lead, rank;

public:
    Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

    void make_Set () {
        for (int i=0; i<N; i++) {
            lead[i] = i;
            rank[i] = 0;
        }
    }

    int Find (int x) {
        while (lead[x] ^ x) {
            lead[x] = lead[lead[x]];
            x = lead[x];
        }
        return x;
    }

    bool Merge (int x, int y) {
        return Find(x) ^ Find(y);
    }

    void Rank (int x, int y) {
        int a = Find(x);
        int b = Find(y);
        if (Merge(x, y)) {
            if (rank[a] > rank[b]) {
                lead[b] = a;
                rank[a] += rank[b];
            }
            else {
                lead[a] = b;
                rank[b] += rank[a];
            }
        }
    }

    void Rank (int bit, vector<pii> &vec) {
        if (!~bit || vec.size() < 2) {
            for (int i=1; i<vec.size(); i++) Rank(vec[0].f, vec[i].f);
            return;
        }
        if (M & (1 << bit)) {
            for (int i=1; i<vec.size(); i++) Rank(vec[0].f, vec[i].f);
            Rank(bit - 1, vec);
        }
        else {
            vector<pii> vec1, vec2;
            for (int i=0; i<vec.size(); i++) {
                if (vec[i].s & (1 << bit)) vec1.pb(vec[i]);
                else vec2.pb(vec[i]);
            }
            Rank(bit - 1, vec1);
            Rank(bit - 1, vec2);
        }
    }
};

Disjoint ds(MAXN);

int main () {
    scan(N); scan(M); scan(Q);
    ds.make_Set();
    for (int i=0, x; i<N; i++) {
        scan(x);
        acc.pb(mp(i, x));
    }
    ds.Rank(30, acc);
    for (int i=0, p, q; i<Q; i++) {
        scan(p); scan(q);
        printf("%s\n", ds.Merge(--p, --q) ? "NO" : "YES");
    }
    return 0;
}