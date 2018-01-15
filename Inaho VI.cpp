#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define PI M_PI
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

ll x;
complex<long double> base(0.000000, 1.000000);
complex<long double> exponent(0.000000, 1.000000);

int main () {
    scan(x);
    if (x > 140) printf("0.438283\n0.360592\n"); // Eventually converges to 0.438283 and 0.360592i
    else if (!x) printf("1\n0\n");
    else {
        for (int i=1; i<x; i++) exponent = pow(base, exponent);
        printf("%.6Lf\n%.6Lf\n", exponent.real(), exponent.imag());
    }
}