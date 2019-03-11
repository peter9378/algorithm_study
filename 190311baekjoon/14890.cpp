/**
*	baekjoon online judge
*	No. 14890	경사로
*	@author	peter9378
*	@date		2019.03.11
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	int answer = 0;
	bool flag;

	for (int i = 0; i < N; i++)
	{
		flag = true;
		for (int j = 0; j < N - 1; j++)
		{
			// if height is same
			if (arr[i][j] == arr[i][j + 1])
				continue;
			// height difference should max 1
			if (abs(arr[i][j] - arr[i][j + 1]) == 1)
			{
				if (arr[i][j] > arr[i][j + 1])
				{
					int count = 0;
					for (int k = 1; j + k < N; k++)
					{
						if (arr[i][j + 1] == arr[i][j + k])
							count++;
						else
							break;
					}
					if (count < L)
					{
						flag = false;
						j = N;
						break;
					}
					else
					{
						for (int k = 1; k <= L; k++)
							arr[i][j + k]+=100;
						j += L;
						if ((arr[i][j] - 100) < arr[i][j + 1])
						{
							flag = false;
							j = N;
							break;
						}
					}
				}

				else
				{
					int count = 0;
					for (int k = 0; j >= k; k++)
					{
						if (arr[i][j] == arr[i][j - k])
							count++;
						else
							break;
					}
					if (count < L)
					{
						flag = false;
						j = N;
						break;
					}
				}
			}
			else
			{
				// fail
				flag = false;
				j = N;
				break;
			}
		}
		if (flag)
			answer++;
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] > 100)
				arr[i][j] -= 100;
		}


		flag = true;
		for (int j = 0; j < N - 1; j++)
		{
			// if height is same
			if (arr[j][i] == arr[j + 1][i])
				continue;
			// height difference should max 1
			if (abs(arr[j][i] - arr[j + 1][i]) == 1)
			{
				if (arr[j][i] > arr[j + 1][i])
				{
					int count = 0;
					for (int k = 1; j + k < N; k++)
					{
						if (arr[j + 1][i] == arr[j + k][i])
							count++;
						else
							break;
					}
					if (count < L)
					{
						flag = false;
						j = N;
						break;
					}
					else
					{
						for (int k = 1; k <= L; k++)
							arr[j + k][i] += 100;
						j += L;
						if ((arr[j][i] - 100) < arr[j + 1][i])
						{
							flag = false;
							j = N;
							break;
						}
					}
				}
				else
				{
					int count = 0;
					for (int k = 0; j >= k; k++)
					{
						if (arr[j][i] == arr[j - k][i])
							count++;
						else
							break;
					}
					if (count < L)
					{
						flag = false;
						j = N;
						break;
					}
				}
			}
			else
			{
				// fail
				flag = false;
				j = N;
				break;
			}
		}
		if (flag)
			answer++;
		for (int j = 0; j < N; j++)
		{
			if (arr[j][i] > 100)
				arr[j][i] -= 100;
		}
	}

	// print answer
	cout << answer;
	return 0;
}
