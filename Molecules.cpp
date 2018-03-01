#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, maxx;
string S;
map<char, int> freq;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	if (N & 1) {
		cout << "No" << endl;
		return 0;
	}
	for (int i=0; i<S.size(); i++) freq[S[i] - 'a']++;
	for (pii next : freq) maxx = max(maxx, next.s);
	if ((N >> 1) < maxx) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}