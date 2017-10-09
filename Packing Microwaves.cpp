#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, X, Y, Z, A, B, C;
ll micros[3], ans;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> micros[0] >> micros[1] >> micros[2] >> A >> B >> C;
	sort(micros, micros + 3);
	do {
		ans = max(ans, (A / micros[0]) * (B / micros[1]) * (C / micros[2]));
	} while (next_permutation(micros, micros + 3));
	if (!ans) cout << "SCAMMED" << "\n";
	else if (N % ans) cout << ((ll) ((N / ans) + 1)) << "\n";
	else cout << ((ll) (N / ans)) << "\n";
	return 0;
}