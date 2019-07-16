#include "game.h"
#include <bits/stdc++.h>
#define MAXN 1504
using namespace std;
int cnt[MAXN];

int main(){

}

void initialize(int n) {

}

int hasEdge(int u, int v) {
    int w = (u > v ? u : v);
    return cnt[w]++ == w;
}
