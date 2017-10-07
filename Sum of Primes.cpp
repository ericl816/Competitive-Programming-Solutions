#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umsi unordered_map<string, int>
#define msi map<string, int>
using namespace std;

int N;
ll sum;
bool isPrime[MAXN];

void SieveofEratosthenes (int N, bool isPrime[]) {
	if (N >= 2) isPrime[2] = 1;
	for (int i=3; i<=N; i+=2) isPrime[i] = 1;
	for (int i=3; i<=sqrt(N); i+=2) {
		if (isPrime[i]) for (int j=i*3; j<=N; j+=i<<1) isPrime[j] = 0;
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	for (int i=0; i<5; i++) {
		cin >> N;
		sum = 0;
		//memset(isPrime, 1, sizeof(isPrime));
		//isPrime[0] = isPrime[1] = 0;
		SieveofEratosthenes(N, isPrime);
		for (int j=0; j<=N; j++) {
			if (isPrime[j]) sum += j;
		}
		cout << sum << "\n";
	}
	return 0;
}