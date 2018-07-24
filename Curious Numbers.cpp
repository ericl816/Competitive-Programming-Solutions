#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 10000000010
#define INF 0x3f3f3f3f
#define EPS 1e-10
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

ll Q, K, M, N;
vector<ll> palindromes;

inline ll Generate_Palindrome (int num, bool odd) {
	ll res = num;
	if (odd) num /= 10;
	while (num > 0) {
		res *= 10;
		res += (num % 10);
		num /= 10;
	}
	return res;
}

inline void Get_Palindrome () {
	ll res;
	ll idx = 1;
	res = Generate_Palindrome(idx, 0);
	while (res <= MAXN) {
		if (res % K == 0) palindromes.pb(res);
		idx++;
		res = Generate_Palindrome(idx, 0);
	}
	idx = 1;
	res = Generate_Palindrome(idx, 1);
	while (res <= MAXN) {
		if (res % K == 0) palindromes.pb(res);
		idx++;
		res = Generate_Palindrome(idx, 1);
	}
}

int main () {
	scan(Q); scan(K);
	Get_Palindrome();
	sort(palindromes.begin(), palindromes.end());
	for (int i=0; i<Q; i++) {
		scan(M); scan(N);
		printf("%lld\n", (upper_bound(palindromes.begin(), palindromes.end(), N) - lower_bound(palindromes.begin(), palindromes.end(), M)));
	}
	return 0;
}