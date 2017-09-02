#include <bits/stdc++.h>
#define ull unsigned long long
#define MOD 42069900169420
ull a, b, c;

int main() {
    scanf("%llu %llu %llu", &a, &b, &c);
    printf("%llu\n", (a + b + c) % MOD);
}