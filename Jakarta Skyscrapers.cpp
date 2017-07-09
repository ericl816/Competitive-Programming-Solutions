#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define f first
#define s second
#define p push
#define pb push_back
char _;
using namespace std;

template<typename T>
void RemoveDuplicate(vector<T> &arr) {
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
}

const int MAXN = 30010;
int N, M, B, P, src, dest, dist[MAXN];
bool done = 0;
vector<int> arr[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    scan(N); scan(M);
    for (int i=0; i<M; i++) {
        scan(B); scan(P);
        arr[B].pb(P);
        src = (i == 0) ? B : src;
        dest = (i == 1) ? B : dest;
    }
    for (int i=0; i<N; i++) {
     dist[i] = INF;
     RemoveDuplicate(arr[i]);
    }
    dist[src] = 0;
    pq.p({0, src});
     while (!pq.empty()) {
        int cost = pq.top().f;
        int curr = pq.top().s;
        pq.pop();
        if (curr == dest) {
          printf("%d\n", cost);
          done = 1;
          return 0;
        }
        else if (dist[curr] < cost) continue;
        for (int next : arr[curr]) {
          //Go to skyscraper b + p
            for (int i=1; curr + i * next<N; i++) {
              int nextjumpforward = curr + i * next;
              if (cost + i < dist[nextjumpforward]) {
                dist[nextjumpforward] = cost + i;
                pq.p({dist[nextjumpforward], nextjumpforward});
                if (binary_search(arr[nextjumpforward].begin(), arr[nextjumpforward].end(), next)) break;
              }
            }
            //Go to skyscraper b - p
            for (int i=1; curr - i * next>=0; i++) {
              int nextjumpback = curr - i * next;
              if (cost+ i < dist[nextjumpback]) {
                dist[nextjumpback] = cost + i;
                pq.p({dist[nextjumpback], nextjumpback});
                if (binary_search(arr[nextjumpback].begin(), arr[nextjumpback].end(), next)) break;
                }
            }
        }
    }
    if (!done) printf("%d\n", -1);
}
