#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
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

string s;

void find_and_replace (string& source, string const& find, string const& replace) {
    for (string::size_type i=0; (i=source.find(find, i)) != string::npos;) {
        source.replace(i, find.size(), replace);
        i += replace.size();
    }
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    find_and_replace(s, "0", "O");
    find_and_replace(s, "1", "l");
    find_and_replace(s, "3", "E");
    find_and_replace(s, "4", "A");
    find_and_replace(s, "5", "S");
    find_and_replace(s, "6", "G");
    find_and_replace(s, "8", "B");
    find_and_replace(s, "9", "g");
    cout << s << endl;
    return 0;
}