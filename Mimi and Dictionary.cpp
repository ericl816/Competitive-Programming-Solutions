#include <bits/stdc++.h>
#define ll long long
#define MAXM 100010
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define SEED 31
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

string s;

/*
ll lookup[MAXM][MAXM];

// Function to find LRS of substrings X[0..m-1], X[0..n-1]
string LRS (string X, int m, int n) {
    if (m == 0 || n == 0) return string("");
    if (X[m - 1] == X[n - 1] && m != n) return LRS(X, m - 1, n - 1) + X[m - 1];
    else {
        if (lookup[m - 1][n] > lookup[m][n - 1]) return LRS(X, m - 1, n);
        else return LRS(X, m, n - 1);
    }
}

// Function to fill lookup table by finding the length of LRS of substring X[0..n-1]
void LRSLength (string X, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == X[j - 1] && i != j) lookup[i][j] = lookup[i - 1][j - 1] + 1;
            else lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
        }
    }
}

int count (string a, string b) {
  int cnt = 0, ans = 0;
  while (1) {
    cnt = a.find(b, cnt) + 1;
    if (cnt > 0) ans++;
    else return ans;
  }
}
*/

bool isPalindrome (string s) {
    if (s.length() == 1) return 1;
    return (s == string(s.rbegin(), s.rend()));
}

bool isPalindrome2 (int idx) {
    for (int i=0; i<idx; i++)
        if (s[i] ^ s[idx - i - 1]) return 0;
    return 1;
}

bool Hash (int idx) {
    ll hash1 = 0, hash2 = 0, res = 1;
    for (int i=0; i<idx; i++) {
        hash1 = (hash1 * SEED) % MOD;
        hash1 = (hash1 + s[i] - 'a' + 1) % MOD;
    }
    hash2 = hash1;
    for (int i=0; i<idx - 1; i++) res = (res * SEED) % MOD;
    for (int i=1; i+idx<=s.length(); i++) {
        hash1 = (hash1 - (res * (s[i - 1] - 'a' + 1)) % MOD + MOD) % MOD;
        hash1 = (hash1 * SEED) % MOD;
        hash1 = (hash1 + s[i + idx - 1] - 'a' + 1) % MOD;
        if (hash1 == hash2) return 1;
    }
    return 0;
}
    
int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    getline(cin, s);
    for (int i=s.length() - 1; i>=1; i--) {
        //if (isPalindrome(LRS(s, i, j)) && count(s, LRS(s, i, j)) >= 2) {
        if (isPalindrome2(i) && Hash(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}