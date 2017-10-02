#include <bits/stdc++.h>
#define ll long long
#define MAXN 250010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
using namespace std;

int N, M, A, B, dials[10], tree[MAXN << 3][10], lazy[MAXN << 3];
string s;

void Shift (int arr[10], int idx) {
	for (int i=0; i<10; i++) dials[(i + idx) % 10] = arr[i];
	for (int i=0; i<10; i++) arr[i] = dials[i];
}

void Push_Down (int idx) {
	if (lazy[idx]) {
	    lazy[idx << 1] += lazy[idx];
	    lazy[idx << 1 | 1] += lazy[idx];
	    Shift(tree[idx << 1], lazy[idx]);
	    Shift(tree[idx << 1 | 1], lazy[idx]);
	    lazy[idx] = 0;
	}
}

void Push_Up (int idx) {
	for (int i=0; i<10; i++) tree[idx][i] = tree[idx << 1][i] + tree[idx << 1 | 1][i];
}

void Build (int idx, int l, int r) {
	if (l == r) {
		tree[idx][s[l] - '0']++;
		return;
	}
	else {
		int mid = (l + r) >> 1;
		Build(idx << 1, l, mid);
		Build(idx << 1 | 1, mid + 1, r);
	}
	Push_Up(idx);
}

void Update (int idx, int l, int r, int l1, int r1, int val) {
	Push_Down(idx);
	if (l == l1 && r == r1) {
		lazy[idx] += val;
		Shift(tree[idx], val);
		return;
	}
	int mid = (l + r) >> 1;
	if (r1 <= mid) Update(idx << 1, l, mid, l1, r1, val);
	else if (l1 > mid) Update(idx << 1 | 1, mid + 1, r, l1, r1, val);
	else {
		Update(idx << 1, l, mid, l1, mid, val);
		Update(idx << 1 | 1, mid + 1, r, mid + 1, r1, val);
	}
	Push_Up(idx);
}

int Query (int idx, int l, int r, int l1, int r1) {
	Push_Down(idx);
	int val = 0;
	if (l == l1 && r == r1) {
		for (int i=0; i<10; i++) val += tree[idx][i] * i;
			return val;
	}
	int mid = (l + r) >> 1;
	if (r1 <= mid) return Query(idx << 1, l, mid, l1, r1);
	else if (l1 > mid) return Query(idx << 1 | 1, mid + 1, r, l1, r1);
	else return Query(idx << 1, l, mid, l1, mid) + Query(idx << 1 | 1, mid + 1, r, mid + 1, r1);
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> s;
	s = " " + s;
	Build(1, 1, N);
	for (int i=0; i<M; i++) {
		cin >> A >> B;
		cout << (Query(1, 1, N, A, B)) << "\n";
		Update(1, 1, N, A, B, 1);
	}
	return 0;
}
