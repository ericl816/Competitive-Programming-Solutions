#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#define ll long long
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

int N, t;
ll maxx, sum;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> t;
		maxx = max(maxx, t);
		sum += t;
	}
	if (maxx <= (sum >> 1)) cout << sum << endl;
	else cout << (maxx << 1) << endl;
	return 0;
}