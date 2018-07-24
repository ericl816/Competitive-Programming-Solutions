#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 30
#define MAXN 100010
#define INF 0x3f3f3f3f
#define SEED 131
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
 * Your neighbourhood fox is given a long article of text, containing N words. 
 * He is then given M root words which he must research, and a range [l, r] in the text to use. 
 * Of the words from l to r, please help him count 
 * the number of words that either has the root word as a prefix or is a prefix of the root word.
 */

struct trie {
	trie *child[26];
	bool endi;
};

trie *make () {
	trie *x = new trie;
	for (int i=0; i<26; i++) x->child[i] = NULL;
	x->endi = 0;
	return x;
}

int insert (string word, trie *cur) {
	int ans = word.size();
	for (size_t i=0; i<word.size(); i++) {
		int j = (int) word[i] - 'a';
		if (!cur->child[j]) {
			if (ans == word.size()) ans = i + 1;
			trie *x = make();
			cur->child[j] = x;
		}
		cur = cur->child[j];
	}
	cur->endi = 1;
	return ans;
}

void reset (trie * cur) {
	for (int i=0; i<26; i++) if (cur->child[i]) reset(cur->child[i]);
	delete[] cur;
}

int N, M, l, r;
ll hashed, ans;
string root[MAXN], words[MAXN];
map<int, vector<ll> > prefix, word;

ll hashed, ans;
string root[MAXN], words[MAXN];
map<int, vector<ll> > prefix, word;

inline ll Query (vector<ll> &vec, int x, int y) {
	return upper_bound(vec.begin(), vec.end(), y) - upper_bound(vec.begin(), vec.end(), x - 1);
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=0; i<N; i++) {
		cin >> root[i];
		hashed = 1;
		for (size_t j=0; j<root[i].size(); j++) {
			int ch = (int) root[i][j] - 'a';
			hashed = (hashed * SEED + ch);
			prefix[hashed].pb(i);
		}
		word[hashed].pb(i);
	}
	for (int i=0; i<M; i++) {
		cin >> words[i] >> l >> r;
		hashed = 1; // Make sure to reset the hash value!
		ans = 0;
		--l, --r;
		int last = (int) words[i].back() - 'a';
		words[i].pop_back();
		for (size_t j=0; j<words[i].size(); j++) {
			int ch = (int) words[i][j] - 'a';
			hashed = (hashed * SEED + ch);
			ans += Query(word[hashed], l, r); // Check if the root word is a prefix of the word
		}
		hashed = (hashed * SEED + last);
		ans += Query(prefix[hashed], l, r); // Check if the word is a prefix of the root word
		cout << ans << "\n";
	}
	return 0;
}