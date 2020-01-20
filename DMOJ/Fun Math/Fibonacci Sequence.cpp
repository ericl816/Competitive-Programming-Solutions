// DEBUG
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
#define LSB(n) ((n) & -(n))
#define pow2(n) (1 << (n))
#define mid(n, m) (((m)+(n))/2)
#define _log2(n) sizeof(int) * 8 - __builtin_clz(n) - 1
#define sl(x) (2*(x))
#define sr(x) (sl(x)+1)
typedef pair<int, int> ip;
typedef long long ll;
typedef unsigned long long ull;

ull N;

#define MD(x) ((x) % 1000000007)
#define MMD(x) (MD(x) % 1000000007)

void mult(ull F[2][2], ull M[2][2])
{
	ull x = MMD(MD(F[0][0]) * MD(M[0][0])) + MMD(MD(F[0][1]) * MD(M[1][0]));
	ull y = MMD(MD(F[0][0]) * MD(M[0][1])) + MMD(MD(F[0][1]) * MD(M[1][1]));
	ull z = MMD(MD(F[1][0]) * MD(M[0][0])) + MMD(MD(F[1][1]) * MD(M[1][0]));
	ull w = MMD(MD(F[1][0]) * MD(M[0][1])) + MMD(MD(F[1][1]) * MD(M[1][1]));
	
	F[0][0] = MD(x);
	F[0][1] = MD(y);
	F[1][0] = MD(z);
	F[1][1] = MD(w);
}

void powe(ull F[2][2], ull n)
{
	if(n == 0 || n == 1) return;
	ull M[2][2] = {{1, 1}, {1, 0}};
	powe(F, n / 2);
	mult(F, F);
	if(n % 2 != 0)
		mult(F, M);
}

ull fib(ull n)
{
	ull F[2][2] = {{1, 1}, {1, 0}};
	if(n == 0) return 0;
	powe(F, n - 1);
	return F[0][0];
}

int main()
{
	scanf("%llu", &N);
	printf("%llu\n", MD(fib(N)));
}