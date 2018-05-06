// http://codeforces.com/blog/entry/59281
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
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
 * The max. element of dp will be the value of ans
 * We need to find any ai such that dp[ai] = ans
 * We call this value lst. To obtain the subseqnece, we iterate over all elements of the array in reverse order.
 * If the current element ak = lst, then push k to the array of positions of our subsequence and decrement lst by 1
 */

int n, ans, lst;
vi res;
mii dp; // dp[x] = answer if last element of our subsequence equals to x

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vi a(n + 1);
    a.resize(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) {
        int next = a[i];
        dp[next] = dp[next - 1] + 1;
        if (ans < dp[next]) {
            ans = dp[next];
            lst = next;
        }
    }
    for (int i=n - 1; i>=0; --i) {
        if (a[i] == lst) {
            cout << lst << "\n";
            res.pb(i);
            --lst;
        }
    }
    reverse(res.begin(), res.end());
    cout << ans << "\n";
    for (auto it : res) cout << it + 1 << " ";
    cout << "\n";
    return 0;
}