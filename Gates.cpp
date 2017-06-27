#include<bits/stdc++.h>
using namespace std;
int G, P, arr[100002];

int Find(int x) { 
return x == arr[x] ? arr[x] : arr[x] = Find(arr[x]);
}

void Merge(int x, int y){ 
arr[x] = Find(y); 
}

int main(){
    scanf("%d %d", &G, &P);
    for(int i=0; i<=G; i++) arr[i] = i;
    for(int i=1, x; i<=P; i++){
        scanf("%d", &x);
        int fx = Find(x);
        if(fx == 0) { 
        printf("%d\n", i - 1); 
        return 0;
        }
        Merge(fx, fx-1);
    }
    printf("%d\n", P);
}
