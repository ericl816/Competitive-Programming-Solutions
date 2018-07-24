#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 200010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int len;
string s;

inline bool Solve (int currlen, int pos) {
	if (pos) { // Starting on the left side
		for (int i=0; i<(currlen >> 1); i++) {
			if (s[i] != s[currlen - i - 1]) return 0;
		}
		return 1;
	}
	else { // Starting on the right side
		for (int i=0; i<(currlen >> 1); i++) {
			if (s[len - currlen + i] != s[len - i - 1]) return 0;
		}
		return 1;
	}
	return 1;
}

void Do_Test_Cases () {
	int N = 10;
	while (N--) {
		cin >> s;
		len = s.size();
		for (int i=len; i>0; i--) {
			if (Solve(i, 1) || Solve(i, 0)) {
				cout << len - i << "\n";
				break;
			}
		}
	}
}

int main () {
    cin.tie(0);
    cin.sync_with_stdio(0);
    Do_Test_Cases();
    return 0;
}