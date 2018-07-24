#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
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

int n, k;
int a[MAXN];
set<int> s;
vi v;
vi ans;
map<int, int> mm;

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        v.pb(a[i]);
        mm[a[i]] = i;
    }
    int cnt = 0;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    // for (auto i : v) cout << i << endl;
    for (size_t i=0; i<v.size(); i++) {
        if (++cnt > k) break;
        ans.pb(mm[v[i]]);
    }
    if (ans.empty() || ans.size() ^ k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}
