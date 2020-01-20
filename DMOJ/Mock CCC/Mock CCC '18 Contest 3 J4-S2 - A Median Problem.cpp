#include <bits/stdc++.h>
#define ll long long
#define MAXN 25
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

int N, f;
double X, Y, d, e;
double xcoor[MAXN], ycoor[MAXN];

inline double dist (double a, double b) {
    return a * a + b * b;
}

int main () {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%lf %lf", &xcoor[i], &ycoor[i]);
        X += xcoor[i]; 
        Y += ycoor[i];
    }
    X /= N; 
    Y /= N;
    double P = 0.1;
    for (int i=0; i<75000; i++) {
        f = 0;
        d = dist(X - xcoor[0], Y - ycoor[0]);
        for (int j=1; j<N; j++) {
            e = dist(X - xcoor[j], Y - ycoor[j]);
            if (d < e) d = e, f = j;
        }
        X += (xcoor[f] - X) * P;
        Y += (ycoor[f] - Y) * P;
        P *= 0.999;
    }
    printf("%.10lf\n", sqrt(d));
}