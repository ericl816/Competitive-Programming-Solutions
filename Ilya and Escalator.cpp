#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2010
#define INF 0x3f3f3f3f
#define MOD 1000000007
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

int n, t;
double p;
double DP[MAXN][MAXN];

inline double Calc (int time, int people) {
	if (time == 0 || people == 0) return 0;
	double &val = DP[time][people];
	if (val != -1) return val;
	return val = (p * (1.0 + Calc(time - 1, people - 1)) + (1.0 - p) * Calc(time - 1, people));
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i=0; i<MAXN; i++) for (int j=0; j<MAXN; j++) DP[i][j] = -1;
	cin >> n >> p >> t;
	cout << fixed << setprecision(6) << Calc(t, n) << "\n";
	return 0;
}