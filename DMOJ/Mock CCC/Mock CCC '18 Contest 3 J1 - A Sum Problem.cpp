#include <bits/stdc++.h>
#define ll long long
#define MAXN 20
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

int N, x, sum;
vi arr;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	while (N--) {
		cin >> x;
		arr.pb(x); 
	}
	for (int next : arr) if (next > 0 || next < 0) sum += next;
	cout << sum << endl;
	return 0;
}