#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 11
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

int m, n;
vector<string> A, B;
vi seq;

inline bool Recur (int m, vector<int> &seq){
    if (!seq.empty()) {
        string strA = "", strB = "";
        for (size_t i=0; i<seq.size(); i++) {
            int &idx = seq[i];
            strA += A[idx];
            strB += B[idx];
        }
        if (strA == strB && strA != ""){
            cout << seq.size() << endl;
            for (int i : seq) cout << i + 1 << endl;
            return 1;
        }
    }
    if (m == 1) return 0;
    for (size_t i=0; i<A.size(); i++) {
        vi temp = seq;
        temp.pb(i);
        if (Recur(m - 1, temp)) return 1;
    }
    return 0;
}

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    A.resize(n);
    B.resize(n);
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) cin >> B[i];
    if (!Recur(m, seq)) cout << "No solution." << endl;
    return 0;
}