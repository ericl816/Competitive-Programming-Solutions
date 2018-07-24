// #include <bits/stdc++.h>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#define ll long long
#define MAXN 110
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int DP[MAXN];
string s;
string arr[10] = {"ug", "oog", "ook", "mook", "ooga", "ugug", "oogam", "ookook", "oogum", "mookmook"};

inline void Solve () {
	memset(DP, 0, sizeof(DP));
	getline(cin, s);
	DP[0] = 1;
	for (int i=0; i<s.length(); i++) {
		for (int j=0; j<10; j++) {
			if (i + arr[j].length() <= s.length() && s.substr(i, i + arr[j].length()) == arr[j]) {
				DP[i + arr[j].length()] += DP[i];
			}
		}
	}
	cout << DP[s.length()] << "\n";
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int test_cases = 2;
	while (test_cases--) {
		Solve();
	}
	return 0;
}