#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 110
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

int S, L, ans;
string s;
bool islocation1, islocation2;
char grid[MAXN][MAXN];

void Do_Test_Cases () {
	int N = 10;
	while (N--) {
		cin >> S >> L;
		for (int i=0; i<S; i++) {
			cin >> s;
			for (int j=0; j<S; j++) {
				grid[i][j] = s[j];
			}
		}
		islocation1 = islocation2 = 0;
		ans = 0;
		for (int i=0; i<S; i++) {
			for (int j=0; j + L<=S; j++) {
				islocation1 = islocation2 = 1;
				if (L == 1) islocation2 = 0;
				for (int k=j; k<j + L && (islocation1 || islocation2); k++) {
					if (grid[i][k] == 'm') islocation1 = 0;
					if (grid[k][i] == 'm') islocation2 = 0;
				}
				if (grid[i][j - 1] == 'h' || grid[i][j + L] == 'h') islocation1 = 0;
				if (grid[j - 1][i] == 'h' || grid[j + L][i] == 'h') islocation2 = 0;
				for (int k=j - 1; k<=j + L && (islocation1 || islocation2); k++) {
					if (grid[i - 1][k] == 'h' || grid[i + 1][k] == 'h') islocation1 = 0;
					if (grid[k][i - 1] == 'h' || grid[k][i + 1] == 'h') islocation2 = 0;
				}
				ans += islocation1 + islocation2;
			}
		}
		cout << ans << "\n";
	}
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    Do_Test_Cases();
    return 0;
}