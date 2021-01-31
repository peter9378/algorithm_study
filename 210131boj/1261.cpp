/**
*	BOJ
*	No.1261	¾Ë°í½ºÆÌ
*	@author	peter9378
*	@date		2021.01.31
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

#define MAX 100


int M, N;
string arr[MAX];
bool visited[MAX][MAX];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

int bfs(void)
{
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {0, 0} });
	visited[0][0] = true;

	while (!pq.empty())
	{
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int block = pq.top().first;
		pq.pop();

		if (x == N - 1 && y == M - 1)
			return block;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M)
			{
				if (!visited[next_x][next_y])
				{
					if (arr[next_x][next_y] == '1')
						pq.push({ block + 1,{ next_x, next_y } });
					else
						pq.push({ block, {next_x, next_y} });

					visited[next_x][next_y] = true;
				}
			}
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cout << bfs();

	return 0;
}
