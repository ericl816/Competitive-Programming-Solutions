#include <bits/stdc++.h>
using namespace std;
int n;
string f (int N) {
    return to_string(N * N)+to_string(1000000-N);
}