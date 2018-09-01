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

/* Note: unordered_map works better than map in this case due to its lookup time of O(N), compared to O(log(N)) for map
 * However, while unordered_map may seem to have a faster lookup time, it is still more memory-hungry than a map
 * Overall Time Complexity: O(N^0.75) with recursion and look-up table
 * Using only memoization (top-down approach) will result in 9/15 RTE
 */

int N;
unordered_map<int, ll> memo;

inline ll Recur (int n) {
	ll &val = memo[n];
	if (n == 1) return val = 1;
	if (val) return val;
	ll sum = 0;
	for (int i=2; i<=n; i++) {
		ll res = n / i;
		ll idx = n % i == 0 ? i : n / res;
		sum += (idx - i + 1) * Recur(res); // idx - i + 1 = the number of branches in the subtree, Recur(res) = val
		i = idx;
	}
	return val = sum;
}

/*
inline long long calc (int num) {
  if (num <= 2) return mem[num] = 1;
  if (mem.count(num)) return mem[num];
  int idx = num;
  long long sum = 0;
  while (idx >= 2) {
    int nex = num / idx;
    int next = num / (nex + 1);
    sum += (long long) (idx - next) * calc(nex);
    idx = next;
  }
  return mem[num] = sum;
}
*/

int main () {
	scan(N);
	return !printf("%lld\n", Recur(N));
}