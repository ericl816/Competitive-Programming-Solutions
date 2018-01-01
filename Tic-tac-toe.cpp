#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

int T, Os, Xs, arr[2], cnt;
string s;

// Brute Force
inline void Check () {
	// Check all horizontal lines
	if (s[0] == s[1] && s[1] == s[2] && s[0] != '.') arr[s[0] == 'O']++;
	if (s[3] == s[4] && s[4] == s[5] && s[3] != '.') arr[s[3] == 'O']++;
	if (s[6] == s[7] && s[7] == s[8] && s[6] != '.') arr[s[6] == 'O']++;

	// Check all vertical lines
	if (s[0] == s[3] && s[3] == s[6] && s[0] != '.') arr[s[0] == 'O']++;
	if (s[1] == s[4] && s[4] == s[7] && s[1] != '.') arr[s[1] == 'O']++;
	if (s[2] == s[5] && s[5] == s[8] && s[2] != '.') arr[s[2] == 'O']++;

	// Check both diagonal lines
	if (s[0] == s[4] && s[4] == s[8] && s[0] != '.') arr[s[0] == 'O']++;
	if (s[2] == s[4] && s[4] == s[6] && s[2] != '.') arr[s[2] == 'O']++;
	if ((arr[0] && arr[1]) || (arr[0] && Os == Xs) || (arr[1] && Os ^ Xs)) cout << "no" << endl; // Invalid - isn't more Xs than Os or both players won
	else cout << "yes" << endl;
}

int main () {
  cin.sync_with_stdio(0);
  cin.tie(0);
	cin >> T;
	while (T--) {
		Os = Xs = 0;
		memset(arr, 0, sizeof(arr));
		cin >> s;
		for (int i=0; i<9; i++) {
			if (s[i] == 'O') Os++;
			else if (s[i] == 'X') Xs++;
		}
		if (Os == Xs || Xs == Os + 1) Check(); // yes means only one person has won and there are more Xs than Os
		else cout << "no" << endl;
	}
	return 0;
}