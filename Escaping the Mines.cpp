#include <bits/stdc++.h>
#define ll long long
#define MAXN 10
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

int N, M, num1, num2;
int J[MAXN];

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> J[i];
		if (J[i] >= M) num1++;
		else num2++;
	}
	cout << num1 + min(num1, num2) << endl;
	return 0;
}