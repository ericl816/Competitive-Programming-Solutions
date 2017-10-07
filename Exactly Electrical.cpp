#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, dist, t;

int main() {
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &t);
    dist = abs(a - c) + abs(b - d);
    if (dist <= t && !((t - dist) & 1)) printf("%s\n", "Y");
    else printf("%s\n", "N");
    return 0;
}