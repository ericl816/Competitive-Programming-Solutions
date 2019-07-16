#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (b) : (a)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define plli pair<ll, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

const ull MOD = 1000000007;

ull PowMod (ull a, ull b, ull MOD) {
	ull val = 1;
	while (b) {
		if (b & 1) val = (val * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return val;
}

int K;
ll M, cnt;
ull num, ans;
string s;

int main () {
	scan(K);
	scan(M);
	for (int i=0; i<1 << K; i++) {
		getline(cin, s);
		for (int j=0; j<s.length(); j++) cnt += s[j] == '#';
	}
	num = PowMod(2, PowMod(4, M, MOD - 1), MOD) - 1;
	ans = PowMod(num, cnt, MOD);
	printf("%llu\n", ans + MOD % MOD);
}