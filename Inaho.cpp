#include <bits/stdc++.h>
#include "inaho.h"
using namespace std;

const int MAXN = 500010;
int lead[MAXN];
int size[MAXN];
int NN;
typedef pair<int, int> pii;
typedef pair<pii, int> node;
stack <node> al;
node tmp;
void Init(int N) {
    NN = N;
    for (int i = 0 ; i <= N; i++) {
        lead[i] = i;
        size[i] = 1;
    }
}
int Find(int i) {
    return (lead[i]==i)? i : Find(lead[i]);
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
