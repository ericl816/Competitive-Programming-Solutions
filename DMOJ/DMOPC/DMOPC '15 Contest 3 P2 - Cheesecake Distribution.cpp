#include<iostream>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
using namespace std;
int N;
ll arr [100005], temp1 = 0, temp2 = 0;
int main () {
  scan(N);
  for (int i=0; i<N; i++) { 
  scan(arr[i]);
  temp1 += arr[i];
  }
  if (temp1 % N ^ 0) printf("%s\n", "Impossible");
  else {
    for (int i=0; i<N; i++) temp2 += abs(temp1 / N - arr[i]);
    printf("%lld\n", temp2 >> 1);
  }
}