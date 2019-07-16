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

ll K, u[MAXN], N, f[MAXN], arr[MAXN], last;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> K;
	for (int i=0; i<K; i++) cin >> u[i];
	cin >> N;
	sort(u, u + K);
	for (int i=0; i<K; i++) {
		for (int j=last; j<u[i]; j++) arr[j] = i;
		last = u[i];
	}
	for (int i=0; i<N; i++) {
	    cin >> f[i];
		if (u[K - 1] < f[i]) cout << abs(f[i] - K) << "\n";
		else cout << abs(f[i] - arr[f[i]]) << "\n";
	}
  return 0;
}