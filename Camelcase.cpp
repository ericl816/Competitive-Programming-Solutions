#include <bits/stdc++.h>
#define ll long long
#define MAXN 2010
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

int SIZE = 10;
int N, DP[MAXN];
string s;
set<string> dict;

void Run () {
	while (SIZE--) {
		cin >> s;
		DP[0] = -1;
		// memset(DP, MAXN, sizeof(DP));
		for (int i=1; i<=s.length(); i++) DP[i] = MAXN;
		for (int i=0; i<s.length(); i++) {
			for (int j=1; j+i<=s.length(); j++) {
				// If word is already in dictionary
				if (dict.find(s.substr(i, j)) != dict.end()) DP[i + j] = min(DP[i + j], DP[i] + 1);
			}
		}
		cout << DP[s.length()] << endl;
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> s;
		dict.insert(s);
	}
	Run();
	return 0;
}