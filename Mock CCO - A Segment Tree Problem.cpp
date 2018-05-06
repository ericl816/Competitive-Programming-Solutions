#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
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

int N, M, C;
bool good;
deque<pii> minq, maxq;

int main () {
	scan(N); scan(M); scan(C);
	for (int i=1, a; i<=N; i++) {
		scan(a);
		while (!minq.empty() && minq.front().f <= i - M) minq.pop_front();
		while (!maxq.empty() && maxq.front().f <= i - M) maxq.pop_front();
		while (!minq.empty() && minq.back().s >= a) minq.pop_back();
		while (!maxq.empty() && maxq.back().s <= a) maxq.pop_back();
		minq.pb(mp(i, a));
		maxq.pb(mp(i, a));
		if (i >= M && maxq.front().s - minq.front().s <= C) {
			good = 1;
			printf("%d\n", i - M + 1);
		}
	}
	if (!good) return !printf("%s\n", "NONE");
	return 0;
}