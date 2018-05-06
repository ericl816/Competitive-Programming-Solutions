#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 2010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define sqr(a) (a * a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int M, N;
string s;
char grid[MAXN][MAXN];
bitset<MAXN> black[MAXN];
bool flag;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N;
	for (int i=0; i<M; i++) {
		cin >> s;
		for (int j=0; j<N; j++) {
			grid[i][j] = s[j];
			if (grid[i][j] == '#') {
				black[i].set(j);
			}
		}
	}
	for (int i=0; i<M; i++) {
		for (int j=0; j<i; j++) {
			// The black squares don't form a rectangle that's parallel to the axes
			if ((black[i] & black[j]).count() >= 2) {
				flag = 1;
				cout << "no" << "\n";
				return 0;
			}
		}
	}
	cout << "yes" << "\n";
	return 0;
}