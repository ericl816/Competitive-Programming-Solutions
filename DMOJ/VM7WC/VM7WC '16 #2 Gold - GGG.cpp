#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1000010
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

int N, M, a, val, len;
int DP[MAXN];
umii um;
vi v;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++) cin >> a, um[a] = i;
    cin >> M;
    for (int i=0; i<M; ++i){
      cin >> val;
      if (um.count(val)) v.pb(um[val]);
    }
    for (size_t i=0; i<v.size(); ++i){
        int lo = 1;
        int hi = len;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (v[i] <= v[DP[mid]]) hi = mid - 1;
            else lo = mid + 1;  
        }
        DP[lo] = i;
        len = max(len, lo);
    }
    cout << len << endl;
}