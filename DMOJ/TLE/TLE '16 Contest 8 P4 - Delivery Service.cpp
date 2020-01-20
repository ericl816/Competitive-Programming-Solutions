#include<bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define INF 0x3f3f3f3f
#define ll long long 
#define f first
#define s second
#define pb push_back
#define mp pair<ll, ll>
char _;
using namespace std;

const int MAXN = 100010, MOD = 1000000007;
int X, D, N, P, W, idx, temp;
ll DP[MAXN];
pair<ll, ll> planet[MAXN];
vector<pair<ll, ll>> v;

inline void Calc() {
  planet[P + 1] = mp(D, 0);
  sort(planet, planet + P + 2);
  DP[P + 1] = 1;
  for(int i=P; i>0; i--) {
    idx = upper_bound(planet, planet + P + 2, mp(planet[i].f + planet[i].s, INF)) - planet - 1;
    DP[i] += (DP[i + 1] << 1) % MOD - DP[idx + 1] % MOD;
    DP[i] %= MOD;
    if(DP[i] < 0) DP[i] += MOD;
  }
    DP[0] = DP[1] - DP[(int) (upper_bound(planet, planet + P + 2, mp(planet[0].f + planet[0].s, INF)) - planet)];
    DP[0] %= MOD;
    if(DP[0] < 0) DP[0] += MOD;
}

inline void Print() {
    v.pb(mp(!(W & 1) ? -1 : -2, W));
    temp = 0;
    while (1 < W) {
      temp++;
      if(!(W & 1)) {
        W >>= 1;
        v.pb(mp(-temp, W));
      }
      else if (W & 1) {
        W++;
        W >>= 1;
        v.pb(mp(-temp - 1, W));
      }
  }
        D = v.size();
        printf("%d %d %d\n", D, D, D - 1);
        for(int i=1; i<D; i++) printf("%d %lld\n", i, D + v[i].f);
}

int main() {
    scan(X);
    if(X == 1) {
        scan(D); scan(N); scan(P);
        planet[0] = mp(0, N);
        for(int i=1; i<=P; i++) {
          scan(planet[i].f); scan(planet[i].s); 
        }
        Calc();
        printf("%llu\n", DP[0]);
    }
    else {
        scan(W);
        if(W == 0) printf("3 1 1 \n 2 1");
        else if(W == 1) printf("2 1 1 \n 1 1");
        else if (W == 2) printf("2 2 1 \n 1 1");
        else Print();
    }
}