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

int n;
string s;
bool flag, flag1 = 1;

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> s;
	for (int i=1; i<=n; i++) {
		flag = 0, flag1 = 0;
		if (s[i - 1] == '0') {
			if (i == 1 || s[i - 2] == '0') flag = 1;
			if (i == n || s[i] == '0') flag1 = 1;
			if (flag && flag1) {
				cout << "No" << endl;
				return 0;
			}
		}
		if (s[i - 1] == '1') {
			if (i >= 2 && s[i - 2] == '1') {
				cout << "No" << endl;
				return 0;
			}
			if (i < n && s[i] == '1') {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}