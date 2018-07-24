#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define MAXN 30010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
char _;
using namespace std;

template<typename T>
void RemoveDuplicate(vector<T> &arr) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
}

int N, M, B, P, src, dest;
int dist[MAXN];
vi adj[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main () {
    scan(N); scan(M);
    for (int i=0; i<M; i++) {
        scan(B); scan(P);
        adj[B].pb(P);
        src = (i == 0) ? B : src;
        dest = (i == 1) ? B : dest;
    }
    memset(dist, INF, sizeof(dist));
    for (int i=0; i<N; i++) RemoveDuplicate(adj[i]);
    dist[src] = 0;
    pq.push(mp(0, src));
    while (!pq.empty()) {
      int cost = pq.top().f;
      int curr = pq.top().s;
      pq.pop();
      if (curr == dest) return !printf("%d\n", cost);
      else if (dist[curr] < cost) continue;
      for (int &next : adj[curr]) {
        // Go to skyscraper b + p
        for (int i=1; curr + i * next<N; i++) {
          int nextjumpforward = curr + i * next;
          if (cost + i < dist[nextjumpforward]) {
            dist[nextjumpforward] = cost + i;
            pq.push(mp(dist[nextjumpforward], nextjumpforward));
            if (binary_search(adj[nextjumpforward].begin(), adj[nextjumpforward].end(), next)) break;
          }
        }
        //Go to skyscraper b - p
        for (int i=1; curr - i * next>=0; i++) {
          int nextjumpback = curr - i * next;
          if (cost + i < dist[nextjumpback]) {
            dist[nextjumpback] = cost + i;
            pq.push(mp(dist[nextjumpback], nextjumpback));
            if (binary_search(adj[nextjumpback].begin(), adj[nextjumpback].end(), next)) break;
          }
        }
      }
    }
    return !printf("%d\n", -1);
}