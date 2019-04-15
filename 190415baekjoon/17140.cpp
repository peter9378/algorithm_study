/**
*	baekjoon online judge
*	No. 17140	이차원 배열과 연산
*	@author	peter9378
*	@date		2019.04.15
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 101

int arr[MAX][MAX];
int counting[MAX];
int width = -1, height = -1;

void get_size()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (arr[i][j] != 0)
				width = max(width, j);
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (arr[j][i] != 0)
				height = max(height, j);
		}
	}
}

void counting_init()
{
	for (int i = 0; i < MAX; i++)
		counting[i] = 0;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int r, c, k;
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}

	get_size();
	int answer = 0;
	while (arr[r][c] == 0)
	{
		if (answer > 100)
		{
			answer = -1;
			break;
		}
		answer++;
	}

	// print answer
	cout << answer;

	return 0;
}