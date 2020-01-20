#include<iostream>
using namespace std;
int n, a, b, sum = 0;
int main () {
  for (int i=0; i<6; i++) {
    scanf("%d", &n);
    sum += n;
  }
  scanf("%d\n%d", &a, &b);
  printf("%s\n", b <= (sum / 6.0 + a) ? "yes" : "no");
}