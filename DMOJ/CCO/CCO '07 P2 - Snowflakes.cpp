#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
using namespace std;

int N, k;
set<vector<int>> s;
int main() {
    scan(N);
    for (int i = 0; i < N; i++) {
        vector<int> flakes;
        for (int j = 0; j < 6; j++) {
            scan(k);
            flakes.pb(k);
        }
        sort(flakes.begin(), flakes.end());
        s.insert(flakes);
    }

    if (s.size() == N) printf("No two snowflakes are alike.");
    else printf("Twin snowflakes found.");
}