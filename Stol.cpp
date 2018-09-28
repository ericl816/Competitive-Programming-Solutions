#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 410
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
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int R, C, ans;
char op;
int hist[MAXN];
stack<int> st;

inline void Get_Max_Area (int n) {
	int idx = 0, area = 0;
	while (idx < n) {
		// If this bar is higher than the bar on the top of the stack, push it into stack
		if (st.empty() || hist[st.top()] <= hist[idx]) st.push(idx++);
		// If this bar is lower than top of stack, then calculate area of rectangle with stack 
		// top as the smallest (or minimum height) bar. 
		// 'i' is 'right index' for the top and element 
		// before top in stack is 'left index'
		else {
			int top_idx = st.top();
			st.pop();
			// Calculate the area with hist[top_idx] stack as smallest bar
			if (!hist[top_idx]) continue;
			if (st.empty()) area = 2 * (hist[top_idx] + idx);
			else area = 2 * (hist[top_idx] + (idx - st.top() - 1));
			ans = max(ans, area);
		}
	}
	while (!st.empty()) {
		int top_idx = st.top();
		st.pop();
		if (!hist[top_idx]) continue;
		if (st.empty()) area = 2 * (hist[top_idx] + idx);
		else area = 2 * (hist[top_idx] + (idx - st.top() - 1));
		ans = max(ans, area);
	}
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C;
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> op;
			if (op == '.') hist[j]++;
			else hist[j] = 0;
		}
		Get_Max_Area(R);
	}
	cout << ans - 1 << "\n";
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */