/**
*	BOJ
*	No.1600	¸»ÀÌ µÇ°íÇÂ ¿ø¼þÀÌ
*	@author	peter9378
*	@date		2020.01.27
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

int arr[202][202];
int dp[202][202][33];
bool visit[202][303][33];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
int horse_x[] = { 1, 2, 1, 2, -1, -2, -1, -2 };
int horse_y[] = { 2, 1, -2, -1, 2, 1, -2, -1 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, W, H;
	cin >> K >> W >> H;

	if (W == 1 && H == 1)
		cout << 0;
	else
	{
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
				cin >> arr[i][j];
		}

		queue<tuple<int, int, int>> q;
		q.push({ 0, 0, K });
		visit[0][0][K] = true;

		while (!q.empty())
		{
			int x, y, current;
			tie(x, y, current) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int next_x = x + direction_x[i];
				int next_y = y + direction_y[i];

				if (next_x >= 0 && next_y >= 0 && next_x < H && next_y < W && !arr[next_x][next_y] && !visit[next_x][next_y][current] && current >= 0)
				{
					visit[next_x][next_y][current] = true;
					dp[next_x][next_y][current] = dp[x][y][current] + 1;
					q.push({ next_x, next_y, current });
				}
			}

			for (int i = 0; i < 8; i++)
			{
				int next_x = x + horse_x[i];
				int next_y = y + horse_y[i];

				if (next_x >= 0 && next_y >= 0 && next_x < H && next_y < W && !arr[next_x][next_y] && !visit[next_x][next_y][current - 1] && current > 0)
				{
					visit[next_x][next_y][current - 1] = true;
					dp[next_x][next_y][current - 1] = dp[x][y][current] + 1;
					q.push({ next_x, next_y, current - 1 });
				}
			}
		}

		vector<int> answer;
		int temp = 0;

		for (int i = 0; i <= K; i++)
		{
			if (dp[H - 1][W - 1][i])
			{
				temp++;
				answer.push_back(dp[H - 1][W - 1][i]);
			}
		}

		if (temp)
		{
			sort(answer.begin(), answer.end());

			for (int j = 0; j < answer.size(); j++)
			{
				if (answer[j])
				{
					cout << answer[j];
					break;
				}
			}
		}
		else
			cout << -1;
	}

	return 0;
}
