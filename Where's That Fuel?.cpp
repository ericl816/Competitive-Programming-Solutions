#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
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

int N, P, A, B, pos, ans = 1;
vector<pii> planets;

inline bool Cmp (pii &a, pii &b) {
	if (a.s ^ b.s) return a.s < b.s;
	return a.f < b.f;
}

int main () {
	scan(N); scan(P);
	for (int i=1; i<=N; i++) {
		scan(A); scan(B);
		if (i == P) pos = A;
		else if (B <= A) planets.pb(mp(A, B));
	}
	sort(planets.begin(), planets.end(), Cmp);
	for (size_t i=0; i<planets.size(); i++) {
		pii &next = planets[i];
		if (next.s <= pos && next.f - next.s >= 0) {
			pos += next.f - next.s;
			ans++;
		}
	}
	return !printf("%d\n%d\n", pos, ans);
}	