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

/*
        Given p, convert every inputted number to num-p, and test for if the subsequence 
        sums to >= 0. Use integers, no decimals needed.
        Using naive for loops, it will take O(n^2).
        
        But.
        We get prefix sum array instead. 
        To check if from ai to aj the sum is >= 0, just check if pref[j]-pref[i-1]>=0.
        Check at sj, is there anything before it that's <= sj? If there is, add 1 to the total.
        Remember to add 1 to the total if sj is already 0.
        
        Inversion: Given array a, if i<j and ai>aj, it's an inversion.
        This can be done using bit.
        For a 3 2 1 4
        bit
        3: check how many after it is in the bit. None? Inversion = 0. Add 1 to 3 in bit.
        2: check. 1 after it. Inversion = 1. Add 1 to 2 in bit.
        1: check. 2 after it. Inversion = 2. Add 1 to 1 in bit.
        4: check. None after it. Inversion = 0. Add 1 to 4 in bit.
        Sum into a total to find total inversions. 
        This takes O(logn) time.
        
        Vudu takes a similar principle. For any sj, its "inversion" is the total number
        of elements before it minus all those that are larger than it. This will give 
        the total number of elements that are <= it.
        For the bit index, use p+sj.
*/

ll N, P, cnt, sum, num, val;
ll arr[MAXN], psa[MAXN];
mii map;
pair<ll, int> seq[MAXN];

struct BIT {
private:
	int N;
	vector<ll> tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, int size) {
		for (; idx<=size; idx += idx & -idx) tree[idx]++;
	}

	ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}
};

BIT tree(MAXN);

bool Cmp (const pair<ll, int> &x, const pair<ll, int> &y) {
  if (x.f ^ y.f) return x.f < y.f;
  if (x.s ^ y.s) return x.s < y.s;
  return x.f < y.f && x.s < y.s;
}

int main () {
	scan(N);
	seq[N] = mp(0, -1);
	for (int i=0; i<N; i++) scan(psa[i]);
	scan(P);
	for (int i=0; i<N; i++) {
		psa[i] += psa[i - 1] - P;
		seq[i] = mp(psa[i], i);
	}
	sort(seq, seq + N + 1, Cmp);
	ll prev = -INF;
	for (int i=0; i<=N; i++) {
		if (seq[i].f ^ prev) val++;
		psa[seq[i].s + 1] = val;
		prev = seq[i].f;
	}
	for (int i=0; i<=N; i++) {
		num += tree.Query(psa[i]);
		tree.Update(psa[i], val);
	}
	return !printf("%lld\n", num);
}