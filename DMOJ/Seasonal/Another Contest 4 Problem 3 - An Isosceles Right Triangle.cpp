#include <bits/stdc++.h>
using namespace std;
int n;
bool f (int N) {
    return sqrt(N) == (int) sqrt(N);
}
int main() {
    cin >> n;
    cout << f(n) << "\n";
    return 0;
}