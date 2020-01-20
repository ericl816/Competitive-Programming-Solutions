#include <bits/stdc++.h>
#define ll long long
#define MAXN 2010
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define SIZE 70
using namespace std;

ll K, N, t[MAXN], tables[MAXN][MAXN];
vector<ll> weight;
bool avail[MAXN], flag;

inline bool Valid (int n) {
	flag = 1;
	memset(avail, 0, sizeof(avail));
	if (weight.size() < (int) (n * (n + 1)) >> 1) flag = 0;
	else {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=i; j++) {
				tables[i][j] = (ll) (tables[i - 1][j] + tables[i - 1][j - 1]) >> 1;
				int idx = 0;
				for (; idx<N; idx++) {
					if (tables[i][j] <= weight[idx] && !avail[idx]) {
						avail[idx] = 1;
						// goto inner;
						break;
					}
				}
				// inner:
				if (idx == N) {
    				flag = 0;
    				goto outer;
    			}
    			tables[i][j] += K;
    		}
    	}
    	outer: 
    	if (flag) { }
    }
    return flag;
}

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> N;
	K <<= 1;
	for (int i=0; i<N; i++) {
	  cin >> t[i];
	  weight.pb((ll) t[i] << 1);
	}
	sort(weight.begin(), weight.end());
	for (int i=SIZE; i>=1; i--) {
		if (Valid(i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}