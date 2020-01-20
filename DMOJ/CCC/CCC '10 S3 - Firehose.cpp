// DEBUG
#include <bits/stdc++.h>


#include <iostream>

using namespace std;
int H, K, house[1000];
const int cir = 1000000;


int dist(int pivot, int nj)
{
	int dis;
	if (house[nj] >= house[pivot])
		dis = house[nj] - house[pivot];
	else
		dis = cir - house[pivot] + house[nj];
	return dis;
}


//returns the lowest number of hydrant required to statisfy all house with only a maximum of x hose
int hose(int x)
{
	int output = 0x3f3f3f3f;
	for (int i = 0; i < H; i++)
	{
		int cnt = 1;
		int pivot = i;
		
		for (int j = i; j - i < H; j++)
		{
			int nj = j % H;
			int dis;


			dis = ceil(dist(pivot, nj) / 2.0);
			if (dis > x)
			{
				cnt++;
				
				pivot = nj;
				j--;
				
			}
			
			
			
		}
		
		
		output = min(output, cnt);
	}
	return output;


}

//returns the first index x such that house(x) returns greater than key
int ub(int key)
{
	int lo = 1, hi = cir;
	while (lo <= hi)
	{
		int mid = (lo + hi) / 2;
		int tmp = hose(mid);
		if (tmp > key) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;

		}
	}
	return lo;
}



int main()
{

	cin >> H;
	for (int i = 0; i < H; i++)
	{
		cin >> house[i];
	}
	cin >> K;

	if (K >= H) {
		cout << 0;
		return 0;
	}

	sort(house, house + H);
	//cout << hose(5000);
	cout << ub(K);


}