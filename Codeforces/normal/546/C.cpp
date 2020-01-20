#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int c[1010], d[1010];
deque<int> dq1, dq2;
int main () {
    cin >> n >> a;
    for (int i=0; i<a; i++) {
        cin >> c[i];
        dq1.push_back(c[i]);
    }
    cin >> b;
    for (int i=0; i<b; i++) {
        cin >> d[i];
        dq2.push_back(d[i]);
    }
    for (int i=0; i<=4000000; i++) {
        if (dq1.empty()) {
            cout << i << " " << 2;
            return 0;
        }
        else if (dq2.empty()) {
            cout << i << " " << 1;
            return 0;
        }
        int curr1 = dq1.front(), curr2 = dq2.front();
        dq1.pop_front(); dq2.pop_front();
        if (curr1 > curr2) {
            dq1.push_back(curr2);
            dq1.push_back(curr1);
        }
        else {
            dq2.push_back(curr1);
            dq2.push_back(curr2);
        }
    }
    cout << -1;
}