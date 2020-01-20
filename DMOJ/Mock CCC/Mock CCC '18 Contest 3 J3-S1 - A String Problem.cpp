#include <bits/stdc++.h>
#define ll long long
#define MAXN 110
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

ll sum;
vi v;
string s;
map<char, int> freq;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    v.reserve(s.size());
    for (int i=0; i<s.size(); i++) freq[s[i] - 'a']++;
    for (pii i : freq) v.pb(i.s);
    sort(v.begin(), v.end());
    if (v.size() <= 2) sum = 0;
    else {
        for (int i=0; i<v.size() - 2; i++) sum += v[i];
    }
    cout << sum << endl;
    return 0;
}