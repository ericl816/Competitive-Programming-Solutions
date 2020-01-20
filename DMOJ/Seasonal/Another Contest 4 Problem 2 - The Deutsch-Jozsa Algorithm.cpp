#include <bits/stdc++.h>
using namespace std;
int n;
bool f (int N) {
    return N & 1;
}
int main() {
    cin >> n;
    cout << f(n) << "\n";
    return 0;
}