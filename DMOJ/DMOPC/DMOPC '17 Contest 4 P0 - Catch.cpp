#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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

int a, b, c, d, e, f;
ll minn1, minn2, minn3, D;

inline ll Dist (int a, int b, int c, int d) {
	return ((d - b) * (d - b) + (c - a) * (c - a));
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
    cin >> a >> b >> c >> d >> e >> f;
    minn1 = Dist(a, b, c, d);
    minn2 = Dist(a, b, e, f);
    minn3 = Dist(c, d, e, f);
    D = min(minn1, min(minn2, minn3)) * min(minn1, min(minn2, minn3));
    cout << D << endl;
    return 0;
}