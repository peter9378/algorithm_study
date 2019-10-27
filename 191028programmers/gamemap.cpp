/**
*	Programmers
*	게임 맵 최단거리
*	@author	peter9378
*	@date		2019.10.28
*/
#include <vector>
#include <queue>
using namespace std;

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

int solution(vector<vector<int> > maps)
{
	int answer = 0;
	int N = maps.size();
	int M = maps[0].size();
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && maps[next_x][next_y] == 1)
			{
				q.push(make_pair(next_x, next_y));
				maps[next_x][next_y] = maps[x][y] + 1;
			}
		}
	}
	if (maps[N - 1][M - 1] == 1)
		return -1;
	return maps[N - 1][M - 1];
}