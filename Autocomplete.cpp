#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 30
#define MAXN 1000010
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

/*
 * You have N distinct words that you'd like to send in a text message in order. 
 * Before sending each word, you add it to your phone's dictionary. 
 * Then, you write the smallest non-empty prefix of the word necessary for your phone to autocomplete the word. 
 * This prefix must either be the whole word, or a prefix which is not a prefix of any other word yet in the dictionary.
 * What's the minimum number of letters you must type to send all N words?
 */

int T, N;
int trie[MAXM][MAXN];
ll num, ans;
string s;

inline int Insert_Word () {
	int curr = 1, val = 0;
	bool flag = 0;
	for (size_t i=0; i<s.size(); i++) {
		int ch = (int) s[i] - 'a';
		val += !flag;
		if (!trie[ch][curr]) {
			trie[ch][curr] = ++num;
			flag = 1;
		}
		curr = trie[ch][curr];
	}
	return val;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int z=1; z<=T; z++) {
		memset(trie, 0, sizeof(trie));
		num = 1;
		ans = 0;
		cin >> N;
		for (int i=0; i<N; i++) {
			cin >> s;
			ans += Insert_Word();
		}
		cout << "Case #" << z << ": " << ans << "\n";
	}
	return 0;
}