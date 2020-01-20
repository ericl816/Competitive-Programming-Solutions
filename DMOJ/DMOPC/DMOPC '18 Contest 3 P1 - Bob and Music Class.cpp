#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

int ind;
string a, b, c;
string m[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
map<string, int> mm;
map<int, string> mmmm;
vector<pair<int, pii> > v;

inline pii Calc () {
	return mp(((v[0].s.f - v[0].f + 12) % 12), (v[0].s.s - v[0].s.f + 12) % 12);
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c;
	for (int i=0; i<12; i++) {
		mm[m[i]] = i + 1;
	}
	mmmm[0] = "root position";
	mmmm[1] = "first inversion";
	mmmm[2] = "second inversion";
	int A = mm[a], B = mm[b], C = mm[c];
	v.pb(mp(A, mp(B, C)));
	while (1) {
		int huh = Calc().f, huhh = Calc().s;
		// D("%d %d\n", huh, huhh);
		if (huh == 4 && huhh == 3) {
			cout << m[v[0].f - 1] << "\n";
			cout << "major\n";
			cout << mmmm[ind] << "\n";
			break;
		}
		else if (huh == 3 && huhh == 4) {
			cout << m[v[0].f - 1] << "\n";
			cout << "minor\n";
			cout << mmmm[ind] << "\n";
			break;
		}
		else if (huh == 4 && huhh == 4) {
			cout << m[v[0].f - 1] << "\n";
			cout << "augmented\n";
			cout << mmmm[ind] << "\n";
			break;
		}
		else if (huh == 3 && huhh == 3) {
			cout << m[v[0].f - 1] << "\n";
			cout << "diminished\n";
			cout << mmmm[ind] << "\n";
			break;
		}
		else {
			--ind;
			ind = ((ind % 3) + 3) % 3;
			// D("%d %d %d\n", v[0].f, v[0].s.f, v[0].s.s);
			int tmp1 = v[0].f, tmp2 = v[0].s.f, tmp3 = v[0].s.s;
			v[0].f = tmp2;
			v[0].s.f = tmp3;
			v[0].s.s = tmp1;
			// D("%d %d %d\n", v[0].f, v[0].s.f, v[0].s.s);
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