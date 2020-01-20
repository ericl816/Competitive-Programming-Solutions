#include <bits/stdc++.h>
#include "inaho.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define max(a,b) ((a) < (b) ? (b) : (a))
#define INF 0x3f3f3f3f
#define MAXN 500010
#define pii pair<int, int>
#define node pair<pii, int>
char _;
using namespace std;

int NN, lead[MAXN], size[MAXN];
stack <node> al;
node tmp;

void Init(int N) {
    NN = N;
    for (int i=0; i<=N; i++) {
        lead[i] = i;
        size[i] = 1;
    }
}

int Find(int i) {
    return (lead[i] == i) ? i : Find(lead[i]);
}

void AddEdge(int U, int V) {
    int ru = Find(U), rv = Find(V);
    if(ru == rv) {
        al.push(make_pair(make_pair(ru, rv), 0));
        return;
    }
    al.push(make_pair(make_pair(ru, rv), 1));
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
    tmp = al.top();
    al.pop();
    if (!tmp.second) return;
    pii fin = tmp.first;
    if (lead[fin.first] == fin.first) {
        lead[fin.second] = fin.second;
        size[fin.first] -= size[fin.second];
    }
    else {
        lead[fin.first] = fin.first;
        size[fin.second] -= size[fin.first];
    }
}

int GetSize(int U) {
    return size[Find(U)];
}