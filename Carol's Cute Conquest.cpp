#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1000000000
#define MAXN 1000010
#define MOD 1000000007
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

// Solution uses a 2-pointer approach to solve for the number of substrings that contain subsequences of "CCC"

ll N, K, rem_nums, back_nums, ans;
vector<ll> a;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i=0; i<K; i++) {
		ll x;
		cin >> x;
		a.pb(x);
	}
	for (ll i=0; i<K - 2; i++) {
		rem_nums = N - a[i + 2] + 1;
		if (i == 0) back_nums = a[i];
		else back_nums = a[i] - a[i - 1];
		ans += rem_nums * back_nums;
	}
	cout << ans << endl;
	return 0;
}