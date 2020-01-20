#include <bits/stdc++.h>
using namespace std;

int w, l, side;

int main () {
	scanf("%d %d %d", &w, &l, &side);
	printf("%d\n", (int) round((w / side * 1.0) * (l / side * 1.0) * 1.0));
	return 0;
}