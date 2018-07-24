#include <bits/stdc++.h>
#define ll long long
#define MAXN 200010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int M, O, L, M1, O1, L1;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> O >> L >> M1 >> O1 >> L1;
	cout << min((M1 / M), min((O1 / O), (L1 / L))) << endl;
	return 0;
}