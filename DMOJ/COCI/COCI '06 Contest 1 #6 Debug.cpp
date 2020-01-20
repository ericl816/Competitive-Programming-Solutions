#include <bits/stdc++.h>
using namespace std;

char matrix[300][300];
int good[300][300];

int main(void)
{
	int r, c;
	scanf("%d %d", &r, &c);

	for(int i = 0; i < r; i++)
		scanf("%s", matrix[i]);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			for(int k = 0; k <= min(i, j); k++)
				if(matrix[i][j - k] == matrix[i - k][j])
					good[i][j]++;
				else
					break;
	int ans = 0;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			for(int k = 0; i + k < r && i + j < c; k++)
				if(good[i + k][j + k] > k)
					ans = max(ans, k+1);

	printf("%d\n", ans == 1? -1 : ans);
}