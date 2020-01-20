#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
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

struct tnd {
	tnd *child[26];
	bool endi;
};

int cases, words;
string str;

tnd *make () {
	tnd *x = new tnd;
	for (int i=0; i<26; i++) x->child[i] = NULL;
	x->endi = 0;
	return x;
}

int insert (string word, tnd *cur) {
	int ans = word.size();
	for (size_t i=0; i<word.size(); i++) {
		int j = (int) word[i] - 'a';
		if (!cur->child[j]) {
			if (ans == word.size()) ans = i + 1;
			tnd *x = make();
			cur->child[j] = x;
		}
		cur = cur->child[j];
	}
	cur->endi = 1;
	return ans;
}

void reset (tnd * cur) {
	for (int i=0; i<26; i++) if (cur->child[i]) reset(cur->child[i]);
	delete[] cur;
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> cases;
	for (int z=1; z<=cases; z++) {
		cin >> words;
		tnd *root = make();
		ll sum = 0;
		for (int i=0; i<words; i++) {
			cin >> str;
			sum += insert(str, root);
		}
		cout << "Case #" << z << ": " << sum << "\n";
		reset(root);
	}
	return 0;
}