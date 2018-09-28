#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 11
#define MAXN 10000010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

/*
 * Problem Analysis: The solution to this problem is simply an NN-dimensional Binary Indexed Tree (BIT).
 * One needs an efficient method to sum an NxN-dimensional hypercuboid.
 * This means that the final code should have an extremely small constant factor.
 * For the summation formula, one should utilize the Inclusion-Exclusion Principle to determine which of the 2^N queried corners of the NN-dimensional hypercuboid to add, and which to subtract. 
 * That is, for corner i, the query consists of summing the density between (1 1… 1) to (xi1xi2…xiN). 
 * This can be done using N for loops (which is impractical), or a recursive function as seen by the Update and Query functions down below...

 * We need to be careful of the data type we're using so we don't RTE...
 * Using unsigned short seems to give AC
 * Not worth 25 points in my opinion, although this is the first time that I have seen a recursive BIT
 */

int N, Q, x, op;
ll l[MAXM], a[MAXM], b[MAXM], prefix_prod[MAXM], BIT[MAXN];
unsigned short dim[MAXN];
ll ans, prod = 1, idx;

inline void Update (int current_dimension, ll idx, ll val) {
	if (current_dimension == N) BIT[idx] += val;
	else for (int i=a[current_dimension]; i<=l[current_dimension]; i+=i & -i) Update(current_dimension + 1, idx + prefix_prod[current_dimension] * (i - 1), val);
}

/*
 * For each dimension, one needs to add the upperbound indices and then subtract the lowerbound indices
 * Doing this reduces the time complexity and is known as constant-optimization. However the space complexity still remains the same.
 */
inline ll Query (int current_dimension, ll idx) {
	ll sum = 0;
	if (current_dimension == N) sum += BIT[idx];
	else {
		for (int i=b[current_dimension]; i; i-=i & -i) sum += Query(current_dimension + 1, idx + prefix_prod[current_dimension] * (i - 1));
	  	for (int i=a[current_dimension] - 1; i; i-=i & -i) sum -= Query(current_dimension + 1, idx + prefix_prod[current_dimension] * (i - 1));
	}
	return sum;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	scan(N); scan(Q);
	for (int i=0; i<N; i++) scan(l[i]);
	for (int i=0; i<N; i++) {
		prefix_prod[i] = prod;
		prod *= l[i];
	}
	for (int i=0; i<Q; i++) {
		scan(op);
		if (op == 1) {
			idx = 0;
			for (int j=0; j<N; j++) {
				scan(a[j]);
				idx += prefix_prod[j] * (a[j] - 1);
			}
			scan(x);
			Update(0, 0, x - dim[idx]);
			dim[idx] = x;
		}
		else if (op == 2) {
			for (int j=0; j<N; j++) scan(a[j]);
			for (int j=0; j<N; j++) scan(b[j]);
			printf("%lld\n", Query(0, 0));
		}
	}
	return 0;
}