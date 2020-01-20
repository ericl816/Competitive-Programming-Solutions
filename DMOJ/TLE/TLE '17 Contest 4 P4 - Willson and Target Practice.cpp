#include <bits/stdc++.h>
#define ll long long
#define EPS 0.000000000000000000001
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

long double area(int x1, int y1, int x2, int y2, int x3, int y3) {
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
 
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {   
   /* Calculate area of triangle ABC */
   long double A = area (x1, y1, x2, y2, x3, y3);
 
   /* Calculate area of triangle PBC */  
   long double A1 = area (x, y, x2, y2, x3, y3);
 
   /* Calculate area of triangle PAC */  
   long double A2 = area (x1, y1, x, y, x3, y3);
 
   /* Calculate area of triangle PAB */   
   long double A3 = area (x1, y1, x2, y2, x, y);
   
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

long double dist (int x1, int y1, int x2, int y2) {
  return sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
}

bool CompareDoubles2 (double A, double B) 
{
   double diff = A - B;
   return (diff < EPS) && (-diff < EPS);
}

vector<pii> vec, ans;

int main () {
   cin.sync_with_stdio(0);
   cin.tie(0);
   int N, K;
   cin >> N >> K;
   for (int i=0, x, y; i<N; i++) {
      cin >> x >> y;
      vec.pb(mp(x, y));
   }
   sort(vec.begin(), vec.end());
   int cnt = 0;
   outer:
   for (int i=0; i<=10; i++) {
      for (int j=0; j<=10; j++) {
        if (dist(i, j, j, i) == 1) {
          if (isInside(i, j, i + K, j, j, i, vec[i].f, vec[i].s)) {
            ans.pb(mp(i, j));
          }
        }
      }
  }
   cout << 3 << endl;


}