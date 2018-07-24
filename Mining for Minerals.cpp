#include <bits/stdc++.h>
#define ll long long
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MAXN 20010
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

// Problem Statement: http://poj.org/problem?id=3253
// Analysis: http://contest.usaco.org/TESTDATA/NOV06.plank.htm

priority_queue<ll, vector<ll>, greater<ll> > pq;
int N, L;
ll ans;

int main() {
    scan(N);
    for (int i=0; i<N; i++) {
        scan(L);
        pq.push(L);
    }
    while (pq.size() > 1) {
        ll curr1 = pq.top();
        pq.pop();
        ll curr2 = pq.top();
        pq.pop();
        ans += curr1 + curr2;
        pq.push(curr1 + curr2);
    }
    return !printf("%lld\n", ans);
}