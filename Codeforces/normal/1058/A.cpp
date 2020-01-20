#include<bits/stdc++.h>
using namespace std;
int n, a;
int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        cin >> a;
        if (a) {
            cout << "HARD\n";
            return 0;
        }
    }
    cout << "EASY\n";
    return 0;
}