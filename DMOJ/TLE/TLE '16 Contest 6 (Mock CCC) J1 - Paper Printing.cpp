// APlusB.cpp : Defines the entry point for the console application.
//


#include <bits/stdc++.h>
using namespace std;

int val[2010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, A;
	cin >> N >> M >> A;
	for (int i = 0; i < A; i++)
	{
		int index, value;
		cin >> index >> value;
		val[index] = value;
	}
    for (int i=0; i<0x3f3f3f3f; i++)
	{
		N += val[i];
		if (N <= 0)
		{
			cout << "The printer melts at " << i + 1 << " second(s).";
			break;
		}
		if (N > M)
		{
			cout << "The printer jams at " << i << " second(s).";
			break;
		}
		N--;
	}
	return 0;
}