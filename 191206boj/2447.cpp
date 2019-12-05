/**
*	BOJ
*	No.2447	º° Âï±â - 10
*	@author	peter9378
*	@date		2019.12.06
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;

char arr[3333][3333];

void recursive(int n, int a, int b)
{
	if (n == 1)
	{
		arr[a][b] = '*';
		return;
	}

	int next = n / 3;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
				continue;
			recursive(next, a + next * i, b + next * j);
		}
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			arr[i][j] = ' ';
	}

	recursive(N, 0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j];
		cout << "\n";
	}


	return 0;
}
