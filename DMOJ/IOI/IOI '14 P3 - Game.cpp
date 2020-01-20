#include "game.h" 
void initialize(int n) {}int cnt[1504];int hasEdge(int u, int v) {return ++cnt[u > v ? u : v] == (u > v ? u : v);}