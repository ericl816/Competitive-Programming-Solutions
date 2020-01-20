#include "game.h"
#define MAXN 1504
void initialize(int n) {}
int cnt[MAXN];
int hasEdge(int u, int v) {
    int w = (u > v ? u : v);
    return ++cnt[w] == w;
}