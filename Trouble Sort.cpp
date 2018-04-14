#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
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
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

// Time Complexity: O(N*T)

int T, N, idx = -1;
vi even, odd, vec;

int main () {
	scan(T);
	for (int z=1; z<=T; z++) {
		even.clear();
		odd.clear();
		vec.clear();
		cin >> N;
		for (int i=0, x; i<N; i++) {
			cin >> x;
			if (i & 1) odd.pb(x);
			else even.pb(x);
		}
		// Only O(logN) sorting passes, not O(N^2)
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		for (size_t i=0; i<even.size(); i++) {
			int &next = even[i];
			vec.pb(next);
			if (i < odd.size()) vec.pb(odd[i]);
		}
		idx = -1;
		for (size_t i=0; i<vec.size() - 1; i++) {
			if (vec[i] > vec[i + 1]) {
				idx = i;
				break;
			}
		}
		cout << "Case #" << z << ": ";
		if (~idx) cout << idx << "\n";
		else cout << "OK" << "\n";
	}
	return 0;
}

/*
1
3
8 9 7
*/
