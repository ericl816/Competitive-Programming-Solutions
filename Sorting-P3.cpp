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

// DMOPC '18 Contest 1 P3 - Sorting

int N;
int P[MAXN];
bool vis[MAXN];
vi shift, inds;

int main () {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) {
    	cin >> P[i];
    	--P[i];
    	vis[i] = 0;
    }
    for (int i=0; i<N; i++) {
    	if (P[i] == i) vis[i] = 1;
    	if (!vis[i]) {
    		shift.pb(i + 1);
    		for (int j=i; !vis[j]; j=P[j]) {
    			inds.pb(j + 1);
    			vis[j] = 1;
    		}
    	}
    }
    if (shift.empty()) cout << 0 << "\n";
    else if (shift.size() == 1) {
    	cout << shift.size() << "\n";
    	cout << inds.size() << " ";
    	for (auto i : inds) cout << i << " ";
    	cout << "\n";
    }
    else {
    	cout << 2 << "\n";
    	cout << inds.size() << " ";
    	for (auto i : inds) cout << i << " ";
    	cout << "\n";
    	reverse(shift.begin(), shift.end());
    	cout << shift.size() << " ";
    	for (auto i : shift) cout << i << " ";
    	cout << "\n";
    }
    return 0;
}