/**
*	BOJ
*	No.1018	체스판 다시 칠하기
*	@author	peter9378
*	@date		2019.06.25	- Remember 6.25 -
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[51][51];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < M; j++)
		{
			if (s[j] == 'W')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}

	int answer = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// check border
			if (i + 8 > N || j + 8 > M)
				continue;

			int count = 0;
			for (int a = 0; a < 8; a++)
			{
				for (int b = 0; b < 8; b++)
				{
					if (a % 2)
					{
						if (b % 2)
						{
							if (arr[a + i][b + j] == 1)
								count++;
						}
						else
						{
							if (arr[a + i][b + j] == 0)
								count++;
						}
					}
					else
					{
						if (b % 2)
						{
							if (arr[a + i][b + j] == 0)
								count++;
						}
						else
						{
							if (arr[a + i][b + j] == 1)
								count++;
						}
					}
				}
			}
			answer = min(answer, min(count, 64 - count));
		}
	}

	cout << answer;

	return 0;
}