#include <iostream> 
#include <bits/stdc++.h>
#include <vector>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int n, m, d, a, b, c, cnt, days, maxcost;
bool old = true;
int lead [100004];

struct Edge {
    int a, b, cost, vis;
    bool operator < (const Edge &E) const {
        return cost < E.cost || (cost == E.cost && vis < E.vis);
    }
}; 

vector <Edge> edges;

void make_Set () {
    for(int i=1; i<=n; i++)
    lead [i] = i;
}

int find (int x) {
    return lead[x] = (lead[x] == x ? x: find(lead[x]));
}

bool merge (int a, int b) {
    int x = find(a); int y = find(b);
    if (x ^ y) 
       return lead[x] = y;
    return 0;
}

bool oldedge (int a, int b) {
  return (find(a) == find(b)) ? true : false;
}

int main () {
    scan(n); 
    scan(m); 
    scan(d);
    for(int i=1; i<=m; i++) {
        scan(a); 
        scan(b); 
        scan(c);
        if(i <= n-1)
            edges.push_back( {a, b, c, 0} );
        else
            edges.push_back( {a, b, c, 1} );
    }
    
    sort(edges.begin(), edges.end());
    make_Set();
    for(int i=0; i<edges.size(); i++) {
          if(cnt == n - 1) break;
        auto x = edges[i];
        if(merge (x.a, x.b)) {
            cnt++;
            maxcost = x.cost;
            old = !x.vis;
            if(x.vis) days++;
        }
    }
    if (old) printf("%d\n", days);
       
        make_Set();
        for(int i=0; i<edges.size(); i++) {
            auto e = edges[i];
            if(!oldedge (e.a, e.b))
                if((e.cost == maxcost && !e.vis) || maxcost > e.cost)
                    merge(e.a, e.b);
                else if(e.cost <= d && !e.vis) {
                  days--;
                break;
    }
  }
  if (!old) printf("%d\n", days);
}
