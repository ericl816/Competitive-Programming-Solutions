#include <bits/stdc++.h>
#define ll long long
#define MAXN 25
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
 * Given an undirected weighted graph where there is an edge between every pair of distinct vertices of nonnegative integer weight, let ai be the sum of the weights of the edges incident on vertex i.
 * Given a sequence of integers b1 through bN, determine if it is possible to construct a graph of n vertices such that ai=bi for every vertex in the graph. 

 * This problem is essentially equivalent to the "Array Problem." 
 * The criterion is that the maximum value cannot be the sum of the remaining items and the sum of all entries must be even.
 */

int N;
ll sum, maxx = -INF;
bool flag;
vi b;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0, x; i<N; i++) {
        cin >> x;
        b.pb(x);
        sum += x;
        maxx = max(maxx, x);
    }
    /*
    Much simpler version down below...
    if (sum & 1 || sum < maxx * 2) cout << "NO" << endl;
    else cout << "YES" << endl;
    */

    sum -= maxx;
    for (int i=0; i<N; i++) if (b[i] > sum) flag = 1;
    if ((sum + maxx) & 1) flag = 1;
	if (N == 1) flag = 1;
	if (N == 2 && b[0] ^ b[1]) flag = 1;
	cout << (flag ? "NO" : "YES") << endl;
    return 0;
}