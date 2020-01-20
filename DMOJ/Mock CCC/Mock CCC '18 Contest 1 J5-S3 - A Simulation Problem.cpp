#include <bits/stdc++.h>
#define ll long long
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

ll N, cnt, K = 1, L, threshold, root;
double a = -0.5, b, c;
vector<ll> vec;

inline ll Compute () {
	return root = ceil((-1.0 * b + sqrt(b * b - 4 * a * c)) / (a * 2.0));
}

int main () {
    scanf("%lld", &N);
    if (N == 2) return !printf("%d\n", 1);
    b = N + a;
    c = -1 * N * (N - 1) / 4.0;
    printf("%lld\n", Compute());
    return 0;   
}