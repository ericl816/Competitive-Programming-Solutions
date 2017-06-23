#include<iostream>
#include <stdio.h>
#include <string.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define min(a,b) ((a) > (b) ? (b) : (a))

char _;

using namespace std;

int n, a, ans, number, temp;
int cnt [100001];
int height [100001];

int main () {
  scan(n);
  for (int i=0; i<n; i++) {
  scan(a);
  cnt[a]++;
  }
  
  for (int i=1; i<=2000; i++) {
    for (int j=i; j<=2000; j++) {
      ans = i + j;
      if (i == j)
       number = cnt [i] >> 1;
      else 
      number = min(cnt[i], cnt[j]);
      height [ans] += number; 
    }
  }
  
  int count = temp = 0;
  for (int i=0; i<4002; i++) {
    if (height[i] == temp)
    count++;
    if (height[i] > temp) {
      temp = height[i];
      count = 1;
    }
  }
  printf("%d %d", temp, count);
}
