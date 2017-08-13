#include <bits/stdc++.h>
#define min(x, y) (x) < (y) ? (x) : (y)
#define ll long long
#define vll vector<long long>
#define pb push_back
using namespace std;

ll a, b, a1, gcd, ans;
vll vec;

inline ll GCD (ll a, ll b) {
	if (!b) return a;
	else return GCD(b, a % b);
}

int main () {
  scanf("%lld %lld", &a, &b);
  a1 = a;
    for (ll i=2; i*i<=a; i++) {
        if (!(a1 % i)) {
            vec.pb(i);
            while (!(a1 % i)) a1 /= i; //Factorize a
        }
    }
    if (a1 > 1) vec.pb(a1);
    while (b) {
        gcd = GCD(a, b);
        a /= gcd;
        b /= gcd;
        ll cnt = b;
        for (ll next : vec) {
          if (!(a % next)) cnt = min(cnt, b % next); //Pick min num of operations
        }
        ans += cnt;
        b -= cnt;
    }
    printf("%lld\n", ans);
}
