#include <bits/stdc++.h>
#define scan(y) do{while((y=getchar())<'0'); for(y-='0'; '0'<=(_=getchar()); y=(y<<3)+(y<<1)+_-'0');}while(0)
char _;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f frist
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

const int MAXN = 1 << 13;

int N, Q, op, idx1, idx2, a, b, x, y;
int h[MAXN], tree[MAXN][MAXN];

/* Solution involves using a 2D BIT, is similar to that of Selective Cutting Problem (which uses 1D BIT only)
 * Really similar to Mobile Phones problem, since both involve the use of 2D BITs
 */ 

// [x, y] is inclusive, meaning x is 0, not 1
void Update (int x, int y, int val) {
	for (int a=x; a<MAXN; a += a & -a)
		for (int b=y; b<MAXN; b += b & -b) tree[a][b] += val;
}

int Query (int x, int y) {
	int sum = 0;
	for (int a=x; a; a -= a & -a)
		for (int b=y; b; b -= b & -b)
			sum += tree[a][b];
	return sum;
}

int Query(int x1, int y1, int x2, int y2){
    return Query(x2, y2) - Query(x2, y1 - 1) - Query(x1 - 1, y2) + Query(x1 - 1, y1 - 1);
}

int main () {
	scan(N);
	for (int i=0; i<N; i++) {
		scan(h[i]);
		Update(i + 1, h[i] + 1, 1);
	}
	scan(Q);
	for (int i=0; i<Q; i++) {
		scan(op);
		if (op == 2) {
			scan(x); scan(y);
			Update(x + 1, h[x] + 1, -1);
			h[x] = y;
			Update(x + 1, h[x] + 1, 1);
		}
		else if (op == 1) {
			scan(idx1); scan(idx2); scan(a); scan(b);
			idx1++; idx2++; a++; b++;
			printf("%d\n", Query(idx1, a, idx2, b));
		}
	}
	return 0;
}