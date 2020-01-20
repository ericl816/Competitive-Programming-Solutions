#include <bits/stdc++.h>
using namespace std;

int N, a, dif=10000001, arr1[1000001], arr2[1000001],neg=0,pos=0;

int main () {
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        scanf("%d",&a);
        if (a < 0){arr1[neg] = a;neg++;}
        else if(a==0) arr1[neg]=a,arr2[pos]=a,neg++,pos++;
        else arr2[pos] = a,pos++;
    }
    sort(arr1, arr1 + neg);
    sort(arr2, arr2 + pos);
    for(int i = 1; i < neg; i++)
        dif = min(dif, abs(arr1[i]-arr1[i-1]));
    for(int i = 1; i < pos; i++)
        dif = min(dif, abs(arr2[i]-arr2[i-1]));
    
    printf("%d\n", dif);
    return 0;
}