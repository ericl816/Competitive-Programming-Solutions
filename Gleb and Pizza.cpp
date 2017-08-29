#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define EPS 1e-12
using namespace std;

int r, d, n, x, y, r1, cnt;
double dist;

int main () {
  scanf("%d %d %d", &r, &d, &n);
  d = r - d;
  for (int i=0; i<n; i++) {
  	scanf("%d %d %d", &x, &y, &r1);
  	dist = sqrt(pow(x, 2) + pow(y, 2));
  	if (d + r1 <= dist + EPS && r - r1 >= dist - EPS) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}