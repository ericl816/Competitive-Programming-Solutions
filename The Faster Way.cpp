#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 100010
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

int N, R, M, rocket, regular;
int stops[MAXN];
bool fast[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> R >> M;
	for (int i=0, a; i<R; i++) {
		cin >> a;
		fast[a] = 1;
	}
	for (int i=0; i<M; i++) {
		cin >> stops[i];
		if (fast[stops[i]]) rocket++;
		else regular++;
	}
	while (rocket > regular) --rocket, ++regular;
	cout << ((rocket * (rocket + 1) / 2) + (regular * (regular + 1) / 2)) << "\n";
	return 0;
}