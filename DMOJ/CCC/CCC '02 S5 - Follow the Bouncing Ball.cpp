#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
double p, q;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> p >> q;
  double slope = 1.0 * q / (n - p);
  double b = -slope * p;
  int width = 2 * n;
  while (1) {
    double y = slope * width + b;
    double dist = y - (floor(1.0 * y / m) * m);
    if (abs(dist - q) < 1e-12) {
      cout << 0 << "\n";
      return 0;
    }
    if (dist < 5.0) {
      if (dist < 1e-12) {
        cout << (width / n) + floor(y / m) - 2 << "\n";
      }
      else {
        cout << (width / n) + floor(y / m) - 1 << "\n";
      }
      return 0;
    }
    width += n;
  }
}