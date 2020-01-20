#include<iostream>
#define ll long long 
using namespace std;

ll N, K, D;

int main () {
scanf("%lld %lld %lld", &N, &K, &D);
ll temp = 0;
for (int i=0; i<D; i++) {
    temp += N % K;
    N /= K;
  }
  temp += N;
printf("%lld\n", temp);
}