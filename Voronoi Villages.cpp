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
using namespace std;

int N, A, B, maxx;
long double minn = INF, mid, diff, sum;
vi v;
vector<double> vec;

int main () {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i=0, V; i<N; i++) {
		cin >> V;
		v.pb(V);
	}
	sort(v.begin(), v.end());
	for (size_t i=0; i<v.size() - 1; i++) {
	  mid = (v[i] + v[i + 1]) / 2.0;
	  diff = 1.0 * abs(v[i] - mid);
	  vec.pb(diff);
	}
	for (int i=0; i<vec.size() - 1; i++) {
	  sum = vec[i] + vec[i + 1];
	  if (minn > sum) minn = sum;
	}
	cout << setprecision(1) << fixed;
	cout << minn << endl;
	return 0;
}