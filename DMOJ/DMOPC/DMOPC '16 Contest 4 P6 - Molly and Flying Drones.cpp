#include <bits/stdc++.h>
#define scan(x) do{while((_n=getchar())<45);if(_n-45)x=_n;else x=getchar();for(x-=48;47<(_=getchar());x=(x<<3)+(x<<1)+_-48);if(_n<46)x=-x;}while(0)
char _, _n;
#define ll long long
#define MAXN 1000010
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define f first
#define s second
#define si stack<int>
using namespace std;

ll N, Q, x, y, arr[MAXN], num[MAXN];
stack<pll> st;
pll temp[MAXN];

inline void PSA() {
	for (int i=1; i<MAXN; i++) num[i] += num[i - 1];
}

inline ll Ans(ll x, ll y) {
	return (ll) num[y] - num[x - 1];
}

int main () {
	scan(N); scan(Q);
	for (int i=1; i<=N; i++) {
		scan(arr[i]);
		temp[i] = mp(i, arr[i]);
	}
	st.push(mp(0, -1));
	for (int i=1; i<=N; i++) {
		while (temp[i].s < st.top().s) {
			pll curr = st.top();
			ll idx = curr.f;
			ll res = curr.s; 
			st.pop();
			ll left = idx - st.top().f;
			ll right = i - idx;
			num[res] += left * right;
		}
		st.push(temp[i]);
	}
	while (~st.top().s) {
		pll curr = st.top();
		ll idx = curr.f;
		ll res = curr.s;
		st.pop();
		ll left = idx - st.top().f;
		ll right = N - idx + 1;
		num[res] += left * right;
	}
	PSA();
	for (int i=0; i<Q; i++) {
		scan(x); scan(y);
		printf("%lld\n", Ans(x, y));
	}
	return 0;
}