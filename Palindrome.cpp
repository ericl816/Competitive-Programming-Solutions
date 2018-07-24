#include <bits/stdc++.h>
#define ll long long
#define MAXN 5010
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

// Given a string, determines the minimal number of characters to be inserted into the string in order to obtain a palindrome.

int N;
int DP[2][MAXN];
string s;

inline bool isPalindrome (string s) {
    if (s.length() == 1) return 1;
    return (s == string(s.rbegin(), s.rend()));
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> s;
	if (isPalindrome(s)) {
		cout << 0 << endl;
		return 0;
	}
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			if (s[N - j - 1] == s[i]) DP[i & 1][j] = DP[(i - 1) & 1][j - 1] + 1;
			else DP[i & 1][j] = max(DP[(i - 1) & 1][j], DP[i & 1][j - 1]);
		}
	}
	// The minimal answer should be the total length of the string, subtracted with the number of matching palindromic letters
	cout << (N - DP[(N - 1) & 1][N - 1]) << endl;
	return 0;
}