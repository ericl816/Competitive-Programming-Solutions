#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define umii unordered_map<int, int>
#define mii map<int, int>
#define umiumii unordered_map<int, umii>
#define mimii map<int, mii>
#define si set<int>
#define umisi unordered_map<int, si>
#define misi map<int, si>
using namespace std;

ll N, m[MAXN], b[MAXN];
ll weird;
map<ll, ll> slope;
map<pair<ll, ll>, ll> point;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    weird = (N - 1) * N / 2;
    for (int i=0; i<N; i++) {
        cin >> m[i] >> b[i];
        slope[m[i]]++;
        point[mp(m[i], b[i])]++;
    }
    for (auto i : slope) weird -= (i.s - 1) * i.s / 2;
    for (auto i : point) weird += (i.s - 1) * i.s / 2;
    cout << weird << "\n";
    return 0;
}