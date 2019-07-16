#include <bits/stdc++.h>
using namespace std;
int lead[200001], rrank[200001];

//find
int fd(int x) {
    if (lead[x] == x)
        return x;
    lead[x] = fd(lead[x]);
    return lead[x];
}

//sameset
bool ss(int a, int b){
    return fd(a) == fd(b);
}

//merge
bool mer(int a, int b){
    a = fd(a);
    b = fd(b);
    if (a ^ b){
        if (rrank[a] > rrank[b]) lead[b] = a;
        else{
            lead[a] = b;
            if (rrank[a] == rrank[b]) rrank[b]++;
        }
        return true;
    }
    return false;
}

//make set
void make(int x) {
    lead[x] = x;
    rrank[x] = 1;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        make(i);
    for(int i = 0, a, b; i < q; i++){
        char qq; scanf(" %c", &qq);
        scanf("%d %d", &a, &b);
        if(qq == 'A')
            mer(a,b);
        else
            printf("%s\n", ss(a, b) ? "Y" : "N");
    }
    return 0;
}
