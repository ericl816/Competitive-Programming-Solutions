#include<bits/stdc++.h>
using namespace std;

int N, arr[110]; 

int main () {
  scanf("%d", &N);
  for (int i=0; i<N; i++) scanf("%d", &arr[i]);
 sort(arr, arr + N);
 if (!(N & 1)) {
     for (int i=(N - 1) >> 1; i >=0; i--)
    printf("%d %d ", arr[i], arr[N - i - 1]);
 }
 else if (N & 1) {
   printf("%d ", arr[(N - 1) >> 1]);
   for (int i=((N - 1) >> 1) + 1; i<N; i++)
    printf("%d %d ", arr[i], arr[N - i - 1]);
 }
}