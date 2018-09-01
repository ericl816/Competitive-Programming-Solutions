#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
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
#define println cout << "\n";
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

struct Student {
	int ind, a, b;
	bool operator < (const Student &s) const {
		if (s.b == b) return a < s.a;
		return b < s.b;
	}
};

int N, A, B, idx;
char op;
bool flag;
vector<Student> vec;
set<Student> st;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i=0, ind; i<N; i++) {
		cin >> op;
		flag = 0;
		if (op == 'D') {
			cin >> A >> B;
			vec.pb((Student) {++idx, A, B});
			st.insert((Student) {idx, A, B});
			// for (auto i : vec) cout << "A " << i.a << " B " << i.b << endl;
		}
		else if (op == 'P') {
			cin >> ind;
			auto next = vec[--ind];
			st.erase(next);
			set<Student>::iterator it = st.lower_bound(next);
			for (it; it!=st.end(); it++) {
				if (it->a >= next.a) {
					flag = 1;
					break;
				}
			}
			if (!flag) cout << "NE\n";
			else cout << it->ind << "\n";
			st.insert(next);
		}
	}
	return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */