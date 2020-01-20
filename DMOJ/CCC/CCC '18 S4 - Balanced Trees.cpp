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

int N;
unordered_map<int, ll> memo;

inline ll Recur (int num) {
  if (num <= 2) return memo[num] = 1;
  if (memo.count(num)) return memo[num];
  int idx = num;
  ll sum = 0;
  while (idx >= 2) {
    int nex = num / idx;
    int next = num / (nex + 1);
    sum += (long long) (idx - next) * Recur(nex);
    idx = next;
  }
  return memo[num] = sum;
}

int main () {
	scan(N);
	return !printf("%lld\n", Recur(N));
}