#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
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
#define DEBUG 1
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

const ll INF = 1e20;

struct Square {
    ll minnx, minny, maxxx, maxxy;
};

int N;
ll X, Y;
vector<pair<ll, ll> > points, valid1, valid2;

inline vector<pair<ll, ll> > Get_Corners (Square &a) {
    vector<pair<ll, ll> > res;
    res.pb(mp(a.minnx, a.minny)); // Bottom-left
    res.pb(mp(a.maxxx, a.minny)); // Bottom-right
    res.pb(mp(a.minnx, a.maxxy)); // Top-left
    res.pb(mp(a.maxxx, a.maxxy)); // Top-right
    return res;
}

inline Square Get_Square (vector<pair<ll, ll> > &res) {
    Square sq;
    ll resx1 = INF, resx2 = -INF, resy1 = INF, resy2 = -INF;
    for (size_t i=0; i<res.size(); i++) {
        pair<ll, ll> &point = res[i];
        resx1 = min(resx1, point.f);
        resy1 = min(resy1, point.s);
        resx2 = max(resx2, point.f);
        resy2 = max(resy2, point.s);
    }
    // D("%lld %lld %lld %lld\n", resx1, resy1, resx2, resy2);
    sq.minnx = resx1;
    sq.minny = resy1;
    sq.maxxx = resx2;
    sq.maxxy = resy2;
    return sq;
}

inline bool Works (int L, pair<ll, ll> &point1, pair<ll, ll> &point2) {
    return abs(point1.f - point2.f) <= L && abs(point1.s - point2.s) <= L;
}

inline bool Check (int L) {
    Square square1 = Get_Square(points);
    vector<pair<ll, ll> > corners1 = Get_Corners(square1);
    for (size_t i=0; i<corners1.size(); i++) {
        pair<ll, ll> &corner1 = corners1[i];
        valid1.clear();
        for (auto &point1 : points) {
            if (Works(L, corner1, point1)) continue;
            valid1.pb(point1);
        }
        Square square2 = Get_Square(valid1);
        vector<pair<ll, ll> > corners2 = Get_Corners(square2);
        for (size_t j=0; j<corners2.size(); j++) {
            pair<ll, ll> &corner2 = corners2[j];
            valid2.clear();
            for (auto &point2 : valid1) {
                if (Works(L, corner2, point2)) continue;
                valid2.pb(point2);
            }
            Square square3 = Get_Square(valid2);
            if (abs(square3.minnx - square3.maxxx) <= L && abs(square3.minny - square3.maxxy) <= L) return 1;
        }
    }
    return 0;
}

void Do_Test_Cases () {
    int TEST_CASES = 10;
    while (TEST_CASES--) {
        cin >> N;
        points.clear();
        for (int i=0; i<N; i++) {
            cin >> X >> Y;
            points.pb(mp(X, Y));
        }
        ll lo = 0, hi = 2e9;
        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (Check((int) mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}

int main () {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    Do_Test_Cases();
    return 0;
}