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
int G, P, g;
int arr[MAXN];

struct Disjoint {
private:
    int N;
    vi lead, rank;

public:
    Disjoint(int N) : N(N), lead(N + 1), rank(N + 1) { }

    void make_Set () {
        for (int i=1; i<=N; i++) {
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
        int c = Find(x);
        int d = Find(y);
        if (c ^ d) return 1;
        return 0;
    }

    void Union (int x, int y) {
        int c = Find(x);
        int d = Find(y);
        if (Merge(x, y)) {
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
}; 

Disjoint ds(MAXN);

int main() {
    scan(G); scan(P);
    ds.make_Set();
    for(int i=1; i<=P; i++) {
        scanf("%d", &g);
        if(!ds.Find(g)) return !printf("%d\n", --i); 
        ds.Union(ds.Find(g), ds.Find(g) - 1);
    }
    return !printf("%d\n", P);
}