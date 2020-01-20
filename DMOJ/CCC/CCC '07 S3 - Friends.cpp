#include <bits/stdc++.h>
#define ll long long
#define MAXN 10010
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

int n, x, y, dist;
int friends[MAXN];
bool vis[MAXN];

int main () {
    scanf("%d", &n);
    for (int i=0, a, b; i<n; i++) {
        scanf("%d %d", &a, &b);
        friends[a] = b;
    }
    while (scanf("%d %d", &x, &y), x && y) {
        dist = -1;
        memset(vis, 0, sizeof(vis));
        while (x ^ y && !vis[x]) {
            vis[x]=1;
            x = friends[x];
            dist++;
        }
        if (x == y) printf("%s %d\n", "Yes", dist);
        else printf("%s\n", "No");
    }
}