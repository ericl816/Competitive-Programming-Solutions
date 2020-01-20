#include <bits/stdc++.h>
#define ll long long 
#define MAXN 30
#define INF 0x3f3f3f3f
#define mii map<int, int>
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define f first
#define s second
#define min(a, b) (a) < (b) ? (b) : (a)
#define max(a, b) (a) < (b) ? (b) : (a)
using namespace std;

int val;
int arr[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
int num[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
string s;
mii arr1;

int main () {
	for (int i=0; i<9; i++) {
		cin >> val;
		arr1[val] = i + 1;
	}
	cin >> s;
	int prev;
	for (int i=0; i<s.length(); i++) {
		int times = num[s[i] - 'a'];
		int nextdig = arr1[arr[s[i] - 'a']];
		if (prev == nextdig) {
			cout << "#";
		}
		prev = nextdig;
		for (int j=0; j<times; j++) cout << nextdig;
	}
	cout << "\n";
	return 0;
}