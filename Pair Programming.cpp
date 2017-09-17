#include <bits/stdc++.h>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define ll long long
#define vi vector <int>
#define pb push_back
#define pii pair <int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, v, ans1, ans2, expression[MAXN], num[MAXN];
char op;
string s, s1;
vi vec[MAXN];
pii DP[MAXN];
bool vis[MAXN], root;

void DFS(int node, int par) {
    if (vis[node]) return;
    vis[node] = 1;
    num[node] = 1;
    if (vec[node].size() == 0 && root) { 
        if (expression[node] == 1) DP[node] = mp(0, 1);
        else if (expression[node] == 2) DP[node] = mp(0, 0); 
        else DP[node] = mp(1, 1);
    } 
    else if (expression[node] == 1) {
        pii child1, child2;
        child2 = mp(1, 1);
        for (size_t i=0; i<vec[node].size(); i++) {
            int &next = vec[node][i];
            if (next == par) continue;
            if (!vis[next]) {
                DFS(next, node);
                num[node] += num[next];
                child1.f += DP[next].f;
                child1.s += DP[next].s;
                child2.f += (num[next] - DP[next].s); 
                child2.s += (num[next] - DP[next].f);
            }
     }
     DP[node].f = min(child1.f, child2.f);
     DP[node].s = max(child1.s, child2.s);
    } 
    else if (expression[node] == 2) {
        for (size_t i=0; i<vec[node].size(); i++) {
            int &next = vec[node][i];
            if (next == par) continue;
            if (!vis[next]) {
                DFS(next, node);
                num[node] += num[next];
                DP[node].f += DP[next].f;
                DP[node].s += DP[next].s;
          }
        }
    }
    else {
        DP[node] = mp(1, 1);
        for (size_t i=0; i<vec[node].size(); i++) {
            int &next = vec[node][i];
            if (next == par) continue;
            if (!vis[next]) {
              DFS(next, node);
              num[node] += num[next];
              DP[node].f += (num[next] - DP[next].s);
              DP[node].s += (num[next] - DP[next].f);
           }
        }
   }
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> op;
    if (op == 'C') {
      cin >> s;
      expression[i] = (s == "?" ? 1 : (s == "AC" ? 2 : 3));
      root = 1;
    } 
    else if (op == 'E') {
      cin >> v >> s1;
      vec[v].pb(i);
      expression[i] = (s1 == "?" ? 1 : (s1 == "AC" ? 2 : 3));
    }
  }
  expression[0] = 2;
  for (int i=1; i<=N; i++) if (root) vec[0].pb(i);
  DFS(0, -1);
  return 0 * printf("%d %d\n", DP[0].f, DP[0].s);
}
