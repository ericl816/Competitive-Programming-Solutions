#include <bits/stdc++.h>
#include "inaho.h"
#define MAXN 500010
#define INF 0x3f3f3f3f
#define pii pair<int, int>
#define f first
#define s second
#define node pair<pii, int>
#define p push
#define mp make_pair
using namespace std;

int lead[MAXN], size[MAXN];
stack <node> al;
node tmp;

void Init(int N) {
    for (int i=0; i<=N; i++) {
        lead[i] = i;
        size[i] = 1;
    }
}

int Find(int i) {
    return (lead[i] == i)? i : Find(lead[i]);
}

void AddEdge(int U, int V) {
    int ru = Find(U), rv = Find(V);
    if(ru == rv) {
        al.p(mp(mp(ru, rv), 0));
        return;
    }
    al.p(mp(mp(ru, rv), 1));
    if (size[ru] > size[rv]) {
        size[ru] += size[rv];
        lead[rv] = lead[ru];
    }
    else {
        size[rv] += size[ru];
        lead[ru] = lead[rv];
    }
}

void RemoveLastEdge() {
    tmp = al.top(); al.pop();
    if (!tmp.s) return;
    pii next = tmp.f;
    if (lead[next.f] == next.f) {
        lead[next.s] = next.s;
        size[next.f] -= size[next.s];
    }
    else {
        lead[next.f] = next.f;
        size[next.s] -= size[next.f];
    }
}

int GetSize(int U) {
    return size[Find(U)];
}
