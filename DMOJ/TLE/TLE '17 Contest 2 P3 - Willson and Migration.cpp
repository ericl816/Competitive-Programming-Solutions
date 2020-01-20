#include <bits/stdc++.h>
#include <math.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define M_PI 3.14159265358979323846264338327950288319716939937510
#define MAXN 10010
#define INF (double) 0x3f3f3f3f
#define EPS 1e-9
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
using namespace std;

struct Family {
	double a, b, vx, vy;
};

int N;
double R, tim, deltax, deltay, theta;
double x[MAXN], y[MAXN], x2[MAXN], y2[MAXN], v[MAXN];
Family arr[MAXN];
vector<Family> vec, src;
double velx, vely;
bool flag;

inline double Collision (int i, int x, int y, int vx, int vy) {
	double deltax = vec[i].a - vec[0].a;
	double deltay = vec[i].b - vec[0].b;
	double deltavelx = vec[i].vx - vec[0].vx;
	double deltavely = vec[i].vy - vec[0].vy;
	double dot = deltax * deltavelx + deltay * deltavely;
	double hyp = pow(deltax, 2) + pow(deltay, 2);
	if (pow(R, 2) + EPS >= hyp) return 0.0; 
	double deltavel1 = pow(deltavelx, 2) + pow(deltavely, 2);
	double delta = pow(dot, 2) - deltavel1 * (hyp - pow(R, 2));
	if (abs(deltavely) < EPS && abs(deltavelx) < EPS) {
		if (hyp <= pow(R, 2) + EPS) return 0.0;
		else return -INF;
	}
	if (dot > EPS) return -INF;
	return delta >= -EPS ? abs((dot + sqrt(delta)) / deltavel1) : -INF;
}

int main() {
	scanf("%d %lf", &N, &R);
	for (int i=0; i<N; i++) {
	    scanf("%lf %lf %lf %lf %lf", &x[i], &y[i], &x2[i], &y2[i], &v[i]);
		deltax = x2[i] - x[i];
		deltay = y2[i] - y[i];
		theta = atan2(deltay, deltax);
		velx = v[i] * cos(theta);
		vely = v[i] * sin(theta);
		vec.pb((Family) {x[i], y[i], velx, vely});
	}
    double tim = 0;
    for (int i=1; i<N; i++) {
        tim = Collision(i, vec[i].a, vec[i].b, vec[i].vx, vec[i].vy);
        if (tim > -INF) printf("%d\n", i + 1);
    }
    return 0;
}