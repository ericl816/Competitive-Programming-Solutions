#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000010
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

ll K, u[MAXN], N, f[MAXN], psa[MAXN], last;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> K;
	for (int i=0; i<K; i++) {
	    cin >> u[i];
	    psa[u[i]] = 1;
	}
	for (int i=1; i<MAXN; i++) psa[i] += psa[i - 1];
	cin >> N;
	for (int i=0; i<N; i++) {
	    cin >> f[i];
	    cout << (f[i] - psa[f[i]]) << "\n";
	}
  return 0;
}