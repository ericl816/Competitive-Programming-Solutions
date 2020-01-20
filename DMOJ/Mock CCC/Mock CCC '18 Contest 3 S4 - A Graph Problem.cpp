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
    if (sum & 1 || sum < maxx * 2) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}