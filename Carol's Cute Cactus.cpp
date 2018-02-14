#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
using namespace std;

int N, M, ans;
ll minn, maxx, diff = -1;

inline bool isPalindrome (string s) {
    if (s.length() == 1) return 1;
    return (s == string(s.rbegin(), s.rend()));
}

inline bool isPalindrome1 (string s) {
	for (int i=0; i<(s.size() >> 1); i++) if (s[i] != s[s.size() - i - 1]) return 0;
	return 1;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=N; i<=M; i++) {
		if (isPalindrome1(to_string(i))) {
			if (diff <= min(abs(N - i), abs(M - i))) diff = min(abs(N - i), abs(M - i)), ans = i;
			else break;
		}
	}
	cout << ans << endl;
	return 0;
}