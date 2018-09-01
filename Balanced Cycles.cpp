#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
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

/*
 * The intended solution is centroid decomposition.
 * You have to store all "paths" in a sequence - red edges = 1, blue edges = -1
 * Look for paths that end up being -1/+1 at the end
 * We have to use a data structure to keep track of the information and pair it with everything you're looking at.
 * A frequency/lookup table will suffice

6
1 2 r
2 3 b
2 4 r
4 6 b
4 5 b
*/

int n, a, b;
char color;
int subtree_size[MAXN]; 
ll ans;
vector<pii> adj[MAXN];
vi centroids;
mii freq;
bool is_centroid[MAXN];

// This method recursively computes the subtree size
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

// This method actually computes and returns the actual centroid of the tree (is guaranteed to be one)
inline int Get_Centroid (int node, int prev, int sum) {
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (next.f == prev) continue;
        if (!is_centroid[next.f] && subtree_size[next.f] > (sum >> 1)) return Get_Centroid(next.f, node, sum);
    }
    return node;
}

// This method creates the new tree made out of centroids, using the frequency/look-up table
inline void Decompose_Tree (int node, int prev, int sum) {
    centroids.pb(sum);
    ans += freq[1 - sum] + freq[-(1 + sum)];
    for (size_t i=0; i<adj[node].size(); i++) {
        pii &next = adj[node][i];
        if (is_centroid[next.f] || next.f == prev) continue;
        Decompose_Tree(next.f, node, next.s + sum);
    }
}

// Now starting from the centroid root of the "Centroid Tree", start recursively computing the centroids for each subtree while decomposing the subtrees
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
    scanf("%d", &n);
    for (int i=1; i<n; i++) {
        scanf("%d %d %c", &a, &b, &color);
        // We label red roads as having weights of 1 and blue roads as having weights of -1 (shouldn't matter which value you assign)
        adj[a].pb(mp(b, color == 'r' ? 1 : -1)); 
        adj[b].pb(mp(a, color == 'r' ? 1 : -1));
    }
    Recur(1, -1);
    return !printf("%lld\n", ans - n + 1);
}