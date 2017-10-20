#include <bits/stdc++.h>
#define ll long long
#define MAXN 2010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

struct Edge {
  int nodex, nodey, cost;
};

int N, X, Y, memo[MAXN], dist[MAXN], dist1[MAXN];
vector<pii> loc;
vector<Edge> edges;

int EuclideanDist(pii &a, pii &b){
    return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}
bool Compare (Edge &a, Edge &b){
    return a.cost < b.cost;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
      cin >> X >> Y;
      loc.pb(mp(X, Y));
    }
    pii orig = mp(0, 0);
    for (int i=0; i<N; i++) edges.pb((Edge) {N, i, EuclideanDist(loc[i], orig)});
    for (int i=0; i<N; i++) 
      for (int j=i + 1; j<N; j++)
            edges.pb((Edge) {i, j, EuclideanDist(loc[i], loc[j])});
    sort(edges.begin(), edges.end(), Compare);
    for (int i=0; i<edges.size(); i++) {
        Edge &next = edges[i];
        if (next.cost > dist[next.nodex]) {
          dist[next.nodex] = next.cost;
          dist1[next.nodex] = memo[next.nodex];
        }
        if (next.cost > dist[next.nodey]) {
          dist[next.nodey] = next.cost;
          dist1[next.nodey] = memo[next.nodey];
        }
        if (next.nodex == N) memo[N] = max(memo[N], dist1[next.nodey] + 1);
        else if (next.nodey == N) memo[N] = max(memo[N], dist1[next.nodex] + 1);
        else {
            memo[next.nodex] = max(memo[next.nodex], dist1[next.nodey] + 1);
            memo[next.nodey] = max(memo[next.nodey], dist1[next.nodex] + 1);
        }
    }
    cout << memo[N] << "\n";
    return 0;
}