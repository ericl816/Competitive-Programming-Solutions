#include <stdio.h>
#include <string.h>
#include <iostream>
#define ll long long
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pq priority_queue<int>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define p push
#define b begin
#define e end

using namespace std;

int n, k, arr[26];
string s;

int main () {
	cin >> n >> k >> s;
	for (int i=0; i<n; i++) {
		arr[s[i] - 'a']++;
		if (k < arr[s[i] - 'a']) {
			cout << "NO" << "\n";
			return 0;
		}
	}
	cout << "YES" << "\n";
return 0;	
}
