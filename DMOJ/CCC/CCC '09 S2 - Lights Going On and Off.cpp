#include <bits/stdc++.h>
#define ll long long
#define MAXN 32
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

int R, L;
int lights[MAXN];
set<int> DP[MAXN];
bool light;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> L;
    for (int i=0; i<R; i++){
        for (int j=0; j<L; j++){
            cin >> light;
            if (!light) continue;
            lights[i] += (1 << j);
        }
    }
    DP[0].insert(lights[0]);
    for (int i=1; i<R; i++){
        DP[i].insert(lights[i]);
        for (set<int>::iterator it = DP[i - 1].begin(); it != DP[i - 1].end(); it++) DP[i].insert(lights[i] ^ (*it));
    }
    cout << DP[R - 1].size() << endl;
}