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

int N;
double xcoor[MAXN], ycoor[MAXN];
double radius = -INF, side1, side2, side3, semi_perimeter, diameter;


inline double Dist (double a, double b) {
    return sqrt(a * a + b * b);
}

inline double Get_Semi_Perimeter (double a, double b, double c) {
    return (a + b + c) / 2.0;
}

// Use Heron's Formula
inline double Herons (double a, double b, double c, double sp) {
    return sqrt((sp * (sp - a) * (sp - b) * (sp - c)));
}

// Get the diameter of the circle circumscribed about a triangle (circumcircle) via this formula: D = 2abc / 4A, where A = area of inscribred triangle
inline double Get_Diameter (double a, double b, double c, double sp) {
    return 2 * (a * b * c) / (4 * Herons(a, b, c, sp)); 
}

int main () {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%lf %lf", xcoor + i, ycoor + i);
    for (int i=0; i<N; i++) {
        for (int j=i + 1; j<N; j++) {
            for (int k=j + 1; k<N; k++) {
                side1 = Dist(xcoor[i] - xcoor[j], ycoor[i] - ycoor[j]);
                side2 = Dist(xcoor[k] - xcoor[i], ycoor[k] - ycoor[i]);
                side3 = Dist(xcoor[k] - xcoor[j], ycoor[k] - ycoor[j]);
                semi_perimeter = Get_Semi_Perimeter(side1, side2, side3);
                diameter = 0;
                if (semi_perimeter == 0 || side1 * side1 + side2 * side2 < side3 * side3 || side1 * side1 + side3 * side3 < side2 * side2 || side2 * side2 + side3 * side3 < side1 * side1) radius = max(radius, max(side1, max(side2, max(side3, diameter))));
                else diameter = Get_Diameter(side1, side2, side3, semi_perimeter);
                radius = max(radius, diameter); // Want the smallest diameter possible
            }
        }
    }
    if (N == 2) radius = Dist(xcoor[0] - xcoor[1], ycoor[0] - ycoor[1]);
    cout << setprecision(10) << fixed;
    cout << (radius == -INF ? 0 : radius / 2.0) << endl;
}