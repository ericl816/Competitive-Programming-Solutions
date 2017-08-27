#include <bits/stdc++.h>
#define ll long long 
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define pb push_back
#define mii map<int, int>
#define f first
#define s second
#define min(a, b) (a) < (b) ? (b) : (a)
#define max(a, b) (a) < (b) ? (b) : (a)
using namespace std;

int val;
ll N, P, cnt, sum, num, arr[MAXN], psa[MAXN], BIT[MAXN];
mii map;
pair<ll, int> seq[MAXN];

/*
bool flag;
vector<ll> vec1;
pll group[MAXN];
long double avg[MAXN];
*/

bool compare (const pair<ll, int> x, const pair<ll, int> y) {
  if (x.f != y.f) return x.f < y.f;
  if (x.s != y.s) return x.s < y.s;
  return x.f < y.f && x.s < y.s;
}


void Update (int idx, int size) {
	for (; idx<=size; idx += idx & -idx) BIT[idx]++;
}

int Query (int idx) {
	int sum = 0;
	for (; idx>0; idx -= idx & -idx) sum += BIT[idx];
	return sum;
}

/*
void Generate (ll n, ll x) {
	int cap = pow(2, x);
	for (int i=1; i<cap; i++) {
		for (int j=i; j<x; j++) {
				if (i & (1 << j)) { //If bit is set
					pll next = vec[j][j];
				  ll val = next.f;
				  ll idx = next.s;
					vec1.push_back(next.first);
				}
		}
	}
	for (size_t i=0; i<vec1.size(); i++) {
		ll next = vec1[i];
		sum += next;
		avg[i] = (long double) sum / i;
	}
	for (size_t i=0; i<vec1.size(); i++) {
	  	if (avg[i] >= n) { //If avg is greater
		  	flag = 1;
			  num++;
			  continue;
		  }
	  }
}
*/

int main () {
	scan(N);
	seq[N] = mp(0, -1);
	for (int i=0; i<N; i++) scan(psa[i]);
	scan(P);
	for (int i=0; i<N; i++) {
		psa[i] += psa[i - 1] - P;
		seq[i] = mp(psa[i], i);
	}
	sort(seq, seq + N + 1, compare);
	ll prev = -INF;
	for (int i=0; i<=N; i++) {
		if (seq[i].f != prev) val++;
		psa[seq[i].s + 1] = val;
		prev = seq[i].f;
	}
	for (int i=0; i<=N; i++) {
		num += Query(psa[i]);
		Update(psa[i], val);
	}
	printf("%lld\n", num);
}
