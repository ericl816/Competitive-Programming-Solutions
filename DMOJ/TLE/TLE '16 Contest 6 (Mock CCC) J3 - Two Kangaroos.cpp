#include<bits/stdc++.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
int main() {
    int x1, y1, k, x2, y2, l;
    scanf("%d %d %d %d %d %d", &x1, &y1, &k, &x2, &y2, &l);
    int dx = max(k - l, l - 1);
    int x = abs(x2 - x1) / dx;
    int y = abs(y2 - y1) / dx;
    if ((x2 - x1) % dx) x++;
    if ((y2 - y1) % dx) y++;
    printf("%d\n", x + y);
}