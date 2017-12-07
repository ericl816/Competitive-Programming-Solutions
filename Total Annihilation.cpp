#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 40
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (b) : (a)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int N, M;
ll arr[MAXN], sum, ans;
map<ll, ll> subsetsums;

int main () {
	scan(N);
	scan(M);
	for (int i=0; i<N + M; i++) scan(arr[i]);
	int half1 = (N + M) >> 1;
	int half2 = N + M - half1;
	for (int i=0; i<(1 << half1); i++) {
		sum = 0;
		for (int j=0; j<half1; j++) {
			if ((i & 1 << j) > 0) sum += j >= N ? -arr[j] : arr[j];
		}
		// map<ll, ll>::iterator it = subsetsums.find(sum);
		if (!subsetsums.count(sum)) subsetsums[sum] = 0;
		subsetsums[sum]++;
	}
	for (int i=0; i<(1 << half2); i++) {
		sum = 0;
		for (int j=0; j<half2; j++) {
			if ((i & 1 << j) > 0) sum += half1 + j >= N ? -arr[half1 + j] : arr[half1 + j];
		}
		// map<ll, ll>::iterator it = subsetsums.find(-sum);
		if (subsetsums.count(-sum)) ans += subsetsums[-sum];
	}
	printf("%lld\n", ans - 1);

}