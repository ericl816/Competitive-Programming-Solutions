#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define f first 
#define s second
using namespace std;

pair<ll, ll> pii[100005];
ll N, M, r, c, temp, num;

ll Calc(ll n) {
  return n * (n + 1) >> 1;
}

int main() {
    scan(N); 
    scan(M);
    for(ll i=0; i<M; i++) {
        scan(r);
        scan(c);
        pii[i] = {c, N - r + 1};
    }
    sort(pii, M + pii);
    for(ll i=0; i<M - 1; i++) {
        temp = pii[i].s - (pii[i + 1].f - pii[i].f);
        if(pii[i + 1].s <= temp) {
            pii[i + 1] = pii[i];
            continue;
        }
            if(0 > temp) temp = 0;
            num += Calc(pii[i].s);
            num -= Calc(temp);
    }
    printf("%lld\n", (num + Calc(pii[M - 1].s)));
}
