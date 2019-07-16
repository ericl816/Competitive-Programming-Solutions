#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 110
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
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

int A, B;

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> B;
	if (A >= 90 && A <= 100) {
		if (B >= 80 && B <= 89) cout << "Different\n";
		else if (B >= 70 && B <= 79) cout << "Different\n";
		else if (B >= 60 && B <= 69) cout << "Different\n";
		else if (B >= 0 && B <= 59) cout << "Different\n";
		else cout << "Same\n";
	}
	if (A >= 80 && A <= 89) {
		if (B >= 70 && B <= 79) cout << "Different\n";
		else if (B >= 60 && B <= 69) cout << "Different\n";
		else if (B >= 0 && B <= 59) cout << "Different\n";
		else if (B >= 90 && B <= 100) cout << "Different\n";
		else cout << "Same\n";
	}
	if (A >= 70 && A <= 79) {
		if (B >= 80 && B <= 89) cout << "Different\n";
		else if (B >= 60 && B <= 69) cout << "Different\n";
		else if (B >= 0 && B <= 59) cout << "Different\n";
		else if (B >= 90 && B <= 100) cout << "Different\n";
		else cout << "Same\n";
	}
	if (A >= 60 && A <= 69) {
		if (B >= 0 && B <= 59) cout << "Different\n";
		else if (B >= 90 && B <= 100) cout << "Different\n";
		else if (B >= 80 && B <= 89) cout << "Different\n";
		else if (B >= 70 && B <= 79) cout << "Different\n";
		else cout << "Same\n";
	}
	if (A >= 0 && A <= 59) {
		if (B >= 80 && B <= 89) cout << "Different\n";
		else if (B >= 70 && B <= 79) cout << "Different\n";
		else if (B >= 60 && B <= 69) cout << "Different\n";
		else if (B >= 90 && B <= 100) cout << "Different\n";
		else cout << "Same\n";
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