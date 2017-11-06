#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

struct Edge {
    int a, b, cost, vis;
    bool operator < (const Edge &E) const {
        return cost < E.cost || (cost == E.cost && vis < E.vis);
    }
}; 

struct Disjoint {
private:
    int N;
    vi lead;

public:
    Disjoint (int N) : N(N), lead(N + 1) { }

    void make_Set () {
        for(int i=1; i<=N; i++) lead[i] = i;
    }

    int Find (int x) {
        while (lead[x] ^ x) {
            lead[x] = lead[lead[x]]; // Path compression
            x = lead[x];
        }
        return x;
    }

    bool Merge (int a, int b) {
        int x = Find(a); int y = Find(b);
        if (x ^ y) return lead[x] = y;
        return 0;
    }

    bool OldEdge (int a, int b) {
      return Find(a) == Find(b);
    }
};

int n, m, d, a, b, c, cnt, days, maxcost;
bool old = 1;
vector <Edge> edges;
Disjoint ds (MAXN + 1);

int main () {
    scan(n); 
    scan(m); 
    scan(d);
    for(int i=1; i<=m; i++) {
        scan(a); 
        scan(b); 
        scan(c);
        if(i <= n - 1) edges.pb((Edge) {a, b, c, 0} );
        else edges.pb((Edge) {a, b, c, 1} );
    }
    
    sort(edges.begin(), edges.end());
    ds.make_Set();
    for(size_t i=0; i<edges.size(); i++) {
        Edge &x = edges[i];
        if (cnt == n - 1) break;
        if (ds.Merge(x.a, x.b)) {
            cnt++;
            maxcost = x.cost;
            old = !x.vis;
            if(x.vis) days++;
        }
    }
    ds.make_Set();
    for (size_t i=0; i<edges.size(); i++) {
        Edge &e = edges[i];
        if (!ds.OldEdge (e.a, e.b))
            if ((e.cost == maxcost && !e.vis) || maxcost > e.cost)
                ds.Merge(e.a, e.b);
        else if (e.cost <= d && !e.vis) {
            days--;
            break;
        }
    }
    printf("%d\n", days);
}