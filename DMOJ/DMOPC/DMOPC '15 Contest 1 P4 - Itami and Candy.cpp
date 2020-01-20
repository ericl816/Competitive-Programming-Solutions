#include <bits/stdc++.h>
#define ll long long
#define MAXN 150010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

int N, X;
ll num;
bool isPrime[MAXN];
vi primes;

void SieveofEratosthenes (int N) {
	for (int i=2; i<=N; i++) {
		if (isPrime[i]) {
			for (int j=i*i; j<N; j+=i) isPrime[j] = 0;
			primes.pb(i);
		}
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> X;
	memset(isPrime, 1, sizeof(isPrime));
	SieveofEratosthenes(N + 1);
	for (size_t i=0; i<primes.size(); i++) {
		if (primes[i] <= N) {
			if ((N - primes[i]) % X == 0) num += (((N - primes[i]) / X + 1) << 1) - 1; //Rory takes
			else num += ((N - primes[i]) / X + 1) << 1;
		}
	}
	cout << num << "\n";
	return 0;
}