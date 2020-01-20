#include <bits/stdc++.h>
using namespace std;
int N;
string a, b;
inline int Conv (string s) {
	if (s == "zero" || s == "O") return 0;
	if (s == "one" || s == "un" || s == "?") return 1;
	if (s == "two" || s == "deux" || s == "?") return 2;
	if (s == "three" || s == "trois" || s == "?") return 3;
	if (s == "four" || s == "quatre" || s == "?") return 4;
	if (s == "five" || s == "cinq" || s == "?") return 5;
	if (s == "six" || s == "?") return 6;
	if (s == "seven" || s == "sept" || s == "?") return 7;
	if (s == "eight" || s == "huit" || s == "?") return 8;
	if (s == "nine" || s == "neuf" || s == "?") return 9;
	if (s == "ten" || s == "dix" || s == "?") return 10;
	return stoi(s);
}
int main () {
	cin >> N;
	while (N--) {
		cin >> a >> b;
		cout << Conv(a) + Conv(b) << "\n";
	}
	return 0;
}