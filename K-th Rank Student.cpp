#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;
using namespace __gnu_pbds;
template <typename T> using bst = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bst<int> t[MAXN];
int N, M, a, b, ranking[MAXN], order[MAXN], B, x, y, Q, k;
char op;

struct Disjoint {

private:
    int N;
    vi lead, rank;

public:
    Disjoint (int N) : N(N), lead(N + 1), rank(N + 1) { }

    void make_Set (int i, int k) {
        lead[i - 1] = i - 1;
        rank[i - 1] = 1;
        t[i - 1].insert(k);
        order[k] = i;
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

    void Union (int x, int y) {
        int c = Find(x);
        int d = Find(y);
        if (Merge(x, y)) {
            for (int i=0; i<rank[c]; i++) {
                t[d].insert(*t[c].find_by_order(0));
                t[c].erase(t[c].find_by_order(0));
            }
            if (rank[c] > rank[d]) {
                lead[d] = c;
                rank[c] += rank[d];
            }
            else {
                lead[c] = d;
                rank[d] += rank[c];
            }
        }
    }
    
    int size (int N) {
        return rank[N];
    }
};

Disjoint ds(MAXN);

int main() {
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) {
        scanf("%d", &k);
        ds.make_Set(i, k);
    }
    for (int i=0; i<M; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        ds.Union(a, b);
    }
    scanf("%d", &Q);
    for (int i=0; i<Q; i++) {
        scanf(" %c %d %d", &op, &x, &y);
        x--; y--;
        if (op == 'B') ds.Union(x, y);
        else if (op == 'Q') {
            if (y > ds.size(ds.Find(x))) printf("%d\n", -1);
            else printf("%d\n", order[*t[ds.Find(x)].find_by_order(y)]);
        }
    }
    return 0;
}