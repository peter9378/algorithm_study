/**
*	baekjoon online judge
*	No. 12100 2048(Easy)
*	@author	peter9378
*	@date		2019.03.04
*/
#include <iostream>
#include <queue>
using namespace std;

int arr[21][21];
int N, answer;

// 방향으로 합칠 때
void merge(int direction)
{
	queue<int> q;
	int count = 0;

	switch (direction)
	{
	// 위쪽
	case 0:
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[j][i] != 0)
					q.push(arr[j][i]);
				arr[j][i] = 0;
			}

			int index = 0;
			int temp;

			while (!q.empty()) {
				temp = q.front();
				q.pop();

				if (arr[index][i] == 0)
					arr[index][i] = temp;
				else if (arr[index][i] == temp)
				{
					arr[index][i] *= 2;
					index++;
				}
				else
					arr[++index][i] = temp;
			}

		}
		break;
	// 아래쪽
	case 1:
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (arr[j][i] != 0) q.push(arr[j][i]);
				arr[j][i] = 0;
			}

			int index = N - 1;
			int temp;

			while (!q.empty())
			{
				temp = q.front();
				q.pop();

				if (arr[index][i] == 0)
					arr[index][i] = temp;
				else if (arr[index][i] == temp)
				{
					arr[index][i] *= 2;
					index--;
				}
				else
					arr[--index][i] = temp;
			}
		}
		break;
	// 왼쪽
	case 2:
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] != 0)
					q.push(arr[i][j]);
				arr[i][j] = 0;
			}

			int index = 0;
			int temp;

			while (!q.empty())
			{
				temp = q.front();
				q.pop();

				if (arr[i][index] == 0)
					arr[i][index] = temp;
				else if (arr[i][index] == temp)
				{
					arr[i][index] *= 2;
					index++;
				}
				else
					arr[i][++index] = temp;
			}

		}
		break;
	// 오른쪽
	case 3:
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (arr[i][j] != 0)
					q.push(arr[i][j]);
				arr[i][j] = 0;
			}

			int index = N - 1;
			int temp;

			while (!q.empty())
			{
				temp = q.front();
				q.pop();

				if (arr[i][index] == 0)
					arr[i][index] = temp;
				else if (arr[i][index] == temp)
				{
					arr[i][index] *= 2;
					index--;
				}
				else
					arr[i][--index] = temp;
			}
		}
		break;
	}
}


// 보드 복사
void copy_arr(int(*arr)[21], int(*arr2)[21])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			arr[i][j] = arr2[i][j];
	}
}

// dfs
void dfs(int direction)
{
	if (direction == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] > answer)
					answer = arr[i][j];
			}
		}
		return;
	}

	int temp_arr[21][21];
	copy_arr(temp_arr, arr);

	for (int i = 0; i < 4; i++)
	{
		merge(i);
		dfs(direction + 1);

		copy_arr(arr, temp_arr);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	dfs(0);

	cout << answer;
	return 0;
}
