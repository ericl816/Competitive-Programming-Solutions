#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define MAXN 110
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define vi vector<int>
#define pb push_back
#define max(a, b) (a) < (b) ? (b) : (a)
#define min(a, b) (a) < (b) ? (a) : (b)

int n, k, M, t[MAXN];
ll amount, res, sum, ans = -INF;

ll Greedy (int time) {
	amount = (k + 1) * time;
	res = (time * sum);
	if (res > M) return 0;
	else if (res <= M) {
	for (int i=0; i<k; i++) {
		for (int j=time + 1; j<=n; j++) {
			if (res + t[i] <= M) {
				  amount++;
				  res += t[i];
			  }
		  }
	  }
	}
	return amount;
} 

ll Solve () {
	for (int i=0; i<=n; i++) {
		ll total = Recur(i);
		ans = max(ans, total);
	}
	return ans;
}

int main () {
	std::cin.sync_with_stdio(0);
	std::cin.tie(0);
	std::cin >> n >> k >> M;
	for (int i=0; i<k; i++) {
	  std::cin >> t[i];
		sum += t[i];
	}
	std::sort(t, t + k);
	std::cout << Solve() << "\n";
	return 0;
}