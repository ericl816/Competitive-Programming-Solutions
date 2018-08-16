#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 500010
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

int N, M;
int A[MAXN], B[MAXN];

inline ll Travel_Times (int n) {
    ll minn = 0;
    for (int i=0; i<N; i++) minn += min(M - abs(A[i] - B[(i + n) % N]), abs(A[i] - B[(i + n) % N]));
    return minn;
}

void Do_Test_Cases () {
    int TEST_CASES = 10;
    while (TEST_CASES--) {
        cin >> N >> M;
        for (int i=0; i<N; i++) cin >> A[i];
        for (int i=0; i<N; i++) cin >> B[i];
        sort(A, A + N);
        sort(B, B + N);
        int lo = 0, hi = (N - 1) >> 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (Travel_Times(mid + 1) <= Travel_Times(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        ll ans1 = Travel_Times(lo);
        lo = N >> 1, hi = N;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (Travel_Times(mid + 1) <= Travel_Times(mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        ll ans2 = Travel_Times(lo);
        cout << min(ans1, ans2) << "\n";
    }
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    // freopen("DATA41.txt", "r", stdin);
    Do_Test_Cases();
    return 0;
}