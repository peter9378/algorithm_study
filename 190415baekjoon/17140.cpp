/**
*	baekjoon online judge
*	No. 17140	이차원 배열과 연산
*	@author	peter9378
*	@date		2019.04.15
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

int arr[MAX][MAX];
int counting[MAX];
int width = -1, height = -1;

// for debugging
void print()
{
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

// get height/width
void get_size()
{
	width = -1;
	height = -1;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (arr[i][j] == 0)
			{
				width = max(width, j);
				break;
			}
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (arr[j][i] == 0)
			{
				height = max(height, j);
				break;
			}
		}
	}
}

// initialize counting arr
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

	// init
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			arr[i][j] = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}

	int answer = 0;

	// change loop
	while (arr[r - 1][c - 1] != k)
	{
		if (answer > 100)
		{
			answer = -1;
			break;
		}

		// update height/width
		get_size();

		if (height >= width)
		{
			for (int i = 0; i < height; i++)
			{
				// init
				counting_init();

				// counting sort
				int counting_max = -1;
				for (int j = 0; j < width; j++)
				{
					if (arr[i][j])
					{
						counting_max = max(counting_max, arr[i][j]);
						counting[arr[i][j]]++;
					}
				}

				int index = 0;
				for (int count = 1; count <= width; count++)
				{
					for (int j = 1; j <= counting_max; j++)
					{
						if (counting[j] == count)
						{
							arr[i][index] = j;
							index++;
							arr[i][index] = count;
							index++;
						}
					}
				}

				for (int j = index; j < width; j++)
					arr[i][j] = 0;
			}
		}
		else
		{
			for (int i = 0; i < width; i++)
			{
				// init
				counting_init();

				// counting sort
				int counting_max = -1;
				for (int j = 0; j < height; j++)
				{
					if (arr[j][i])
					{
						counting_max = max(counting_max, arr[j][i]);
						counting[arr[j][i]]++;
					}
				}

				int index = 0;
				for (int count = 1; count <= height; count++)
				{
					for (int j = 1; j <= counting_max; j++)
					{
						if (counting[j] == count)
						{
							arr[index][i] = j;
							index++;
							arr[index][i] = count;
							index++;
						}
					}
				}

				for (int j = index; j < height; j++)
					arr[j][i] = 0;
			}
		}

		//print();
		answer++;
	}

	// print answer
	cout << answer;

	return 0;
}