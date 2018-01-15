#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
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

int N, A, B;
set<int> s;

int main () {
    s.insert(1);
    s.insert(2);
    s.insert(6);
    s.insert(20);
    s.insert(70);
    s.insert(252);
    s.insert(924);
    s.insert(3432);
    s.insert(12870);
    s.insert(48620);
    s.insert(184756);
    s.insert(705432);
    scanf("%d", &N);
    for (int i=1; i<=N; i++) {
        scanf("%d %d", &A, &B);
        if (s.count(i)) printf("%d\n", A - B);
        else printf("%d\n", A + B);
    }
    return 0;
}