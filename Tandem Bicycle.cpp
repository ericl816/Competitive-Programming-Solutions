#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 110
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

// Greedily compute the answer, after sorting the array

int N, type, ans;
int dmoj[MAXN], peg[MAXN];

int main () {
    scan(type); scan(N);
    for (int i=0; i<N; i++) scan(dmoj[i]);
    for (int i=0; i<N; i++) scan(peg[i]);
    sort(dmoj, dmoj + N);
    sort(peg, peg + N);
    // Minimum total speed
    if (type == 1) {
        for (int i=0; i<N; i++) ans += max(dmoj[i], peg[i]);
        printf("%d\n", ans);
    }
    // Maximum total speed
    else {
        for (int i=0; i<N; i++) ans += max(dmoj[i], peg[N - i - 1]);
        printf("%d\n", ans);
    }
    return 0;
}