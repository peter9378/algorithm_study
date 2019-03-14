/**
*	baekjoon online judge
*	No. 15684	사다리 조작
*	@author	peter9378
*	@date		2019.03.14
*/
#include <iostream>
#include <algorithm>
using namespace std;


int N, M, H, answer = 1e5;
int arr[33][11];

// checking function
bool check() 
{
	for (int i = 1, temp; i <= N; i++) 
	{
		temp = i;
		for (int j = 1; j <= H; j++) 
		{
			if (arr[j][temp] == 1)   
				temp++;
			else if (arr[j][temp - 1] == 1) 
				temp--;
		}
		if (i != temp) 
			return false;
	}
	return true;
}

// recursion
void recursion(int x, int y, int count) 
{
	if (count >= answer) 
		return;

	// check return true, count is answer
	if (check()) 
	{
		answer = count;
		return;
	}

	// max count, return
	if (count == 3) 
		return;

	// check every case
	for (int i = y; i <= H; i++, x = 1)
	{
		for (int j = x; j < N; j++)
		{
			if (arr[i][j]) 
			{
				j++;
				continue;
			}

			arr[i][j] = 1;
			recursion(j + 2, i, count+1);
			arr[i][j] = 0;
		}
	}
}

// main recursiontion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N >> M >> H;

	for (int i = 0, a, b; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
	}

	recursion(1, 1, 0);

	// print answer
	if (answer > 3)
		cout << -1;
	else
		cout << answer;
	return 0;
}
