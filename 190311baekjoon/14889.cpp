/**
*	baekjoon online judge
*	No. 14889	스타트와 링크
*	@author	peter9378
*	@date		2019.03.11
*/
#include <iostream>
#include <algorithm>
using namespace std;

int arr[21][21];
int N, answer = 1000000000;
bool flag[21];

// dfs
void dfs(int num)
{
	if (num == N + 1)
	{
		int team1 = 0, team2 = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!flag[i] && !flag[j])
					team1 += arr[i][j];
				else if (flag[i] && flag[j])
					team2 += arr[i][j];
			}
		}
		answer = min(answer, abs(team1 - team2));
		return;
	}

	flag[num] = false;
	dfs(num + 1);

	flag[num] = true;
	dfs(num + 1);
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	dfs(0);

	// print answer
	cout << answer;
	return 0;
}
