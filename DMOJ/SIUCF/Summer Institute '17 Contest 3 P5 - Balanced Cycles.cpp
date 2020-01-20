#include <bits/stdc++.h>
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

int n, a, b;
char color;
int subtree_size[MAXN]; 
ll ans;
vector<pii> adj[MAXN];
vi centroids;
mii freq;
bool is_centroid[MAXN];


inline void DFS (int node, int prev) {
    subtree_size[node] = 1;
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev) continue;
        if (!is_centroid[next.f]) {
            DFS(next.f, node);
            subtree_size[node] += subtree_size[next.f];
        }
    }
}

inline int Get_Centroid (int node, int prev, int sum) {
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev) continue;
        if (!is_centroid[next.f] && subtree_size[next.f] > (sum >> 1)) return Get_Centroid(next.f, node, sum);
    }
    return node;
}

inline void Decompose_Tree (int node, int prev, int sum) {
    centroids.pb(sum);
    ans += freq[1 - sum] + freq[-(1 + sum)];
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (is_centroid[next.f] || next.f == prev) continue;
        Decompose_Tree(next.f, node, next.s + sum);
    }
}

void Recur (int root, int prev) {
    DFS(root, -1);
    root = Get_Centroid(root, -1, subtree_size[root]);
    freq.clear(); 
    freq[0] = 1; 
    is_centroid[root] = 1;
    for (size_t i=0; i<adj[root].size(); i++) {
        pii &next = adj[root][i];
        if (is_centroid[next.f]) continue;
        centroids.clear();
        Decompose_Tree(next.f, root, next.s);
        for (size_t j=0; j<centroids.size(); j++) freq[centroids[j]]++;
    }
    for (size_t i=0; i<adj[root].size(); i++) {
        pii &next = adj[root][i];
        if (!is_centroid[next.f]) Recur(next.f, root);
    }
}
int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++) {
        cin >> a >> b >> color;
        // We label red roads as having weights of -1 and blue roads as having weights of 1
        adj[a].pb(mp(b, color == 'r' ? -1 : 1)); 
        adj[b].pb(mp(a, color == 'r' ? -1 : 1));
    }
    Recur(1, -1);
    cout << (ans - n + 1) << endl;
    return 0;
}