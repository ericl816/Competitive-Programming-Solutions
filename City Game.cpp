#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 1010
#define INF 0x3f3f3f3f
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
 * Problem involves finding the maximum area of a rectangle, using a histogram.
 * For more information, see the template code
 */

int K, M, N, ans;
int hist[MAXN];
char op;
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
			if (st.empty()) area = hist[top_idx] * idx;
			else area = hist[top_idx] * (idx - st.top() - 1);
			ans = max(ans, area);
		}
	}
	while (!st.empty()) {
		int top_idx = st.top();
		st.pop();
		if (st.empty()) area = hist[top_idx] * idx;
		else area = hist[top_idx] * (idx - st.top() - 1);
		ans = max(ans, area);
	}
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> K;
	while (K--) {
		ans = 0;
		cin >> M >> N;
		memset(hist, 0, sizeof(hist));
		for (int i=0; i<M; i++) {
			for (int j=0; j<N; j++) {
			  cin >> op;
			  if (op == 'F') hist[j]++;
			  else hist[j] = 0;
			}
			Get_Max_Area(N);
		}
		cout << ans * 3 << "\n";
	}
	return 0;
}