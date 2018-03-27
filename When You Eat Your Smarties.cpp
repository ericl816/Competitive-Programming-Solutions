#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
#include <iostream>
#include <cstring>
#define ll long long
#define MAXN 10
#define vi vector<int>
using namespace std;

int test_cases = 1, N, ans;
string s;
int sum[MAXN];

inline int GetInd (int n) {
	return (n + 6) / 7 * 13;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	while (test_cases--) {
		cin >> s;
		memset(sum, 0, sizeof(sum));
		while (s != "end of box") {
			if (s == "red") sum[0]++;
			else if (s == "blue") sum[1]++;
			else if (s == "green") sum[2]++;
			else if (s == "yellow") sum[3]++;
			else if (s == "pink") sum[4]++;
			else if (s == "violet") sum[5]++;
			else if (s == "brown") sum[6]++;
			else if (s == "orange") sum[7]++;
			cin >> s;
		}
		cout << (sum[0] * 16 + GetInd(sum[1]) + GetInd(sum[2]) + GetInd(sum[3]) + GetInd(sum[4]) + GetInd(sum[5]) + GetInd(sum[6]) + GetInd(sum[7])) << "\n";
	}
	return 0;
}