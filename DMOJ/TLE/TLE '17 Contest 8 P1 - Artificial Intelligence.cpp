#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define INF 0x3f3f3f3f
#define EPS 1e-10
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

int N, x, y;
bool flag = 1;
double c = INF;

int main () {
	scan(N);
	for (int i=0; i<N; i++) {
		scan(x); scan(y);
		if (x == 0 && y == 0) continue;
		else if (x == 0 && y) flag = 0;
		else if (c == INF) c = 1.0 * y / x;
		else if (abs(c - (1.0 * y / x)) > EPS) flag = 0;
	}
	return !printf("%s\n", flag ? "yes" : "no");
}