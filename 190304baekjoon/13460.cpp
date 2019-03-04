/**
*	baekjoon online judge
*	No. 13460	구슬 탈출2
*	@author	peter9378
*	@date		2019.03.04
*/
#include <iostream>
#include <queue>
using namespace std;

#define MAX 11
// board array
char arr[MAX][MAX];
// visit array for bfs
int visit[MAX][MAX][MAX][MAX];
// direction array
int direction_x[] = { -1, 1, 0, 0 };
int direction_y[] = { 0, 0, -1, 1 };
bool flag;

// red/blue ball
queue<pair<int, int>> rb;
queue<pair<int, int>> bb;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, rx, ry, bx, by, ox, oy, answer = 0;

	// input variables
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'R')
			{
				rb.push(make_pair(i, j));
				rx = i;
				ry = j;
			}
			else if (arr[i][j] == 'B')
			{
				bb.push(make_pair(i, j));
				bx = i;
				by = j;
			}
			else if (arr[i][j] == 'O')
			{
				ox = i;
				oy = j;
			}
		}
	}

	// init
	visit[rx][ry][bx][by] = true;

	// bfs
	while (!rb.empty())
	{
		int len = rb.size();
		while (len--)
		{
			rx = rb.front().first;
			ry = rb.front().second;
			bx = bb.front().first;
			by = bb.front().second;
			rb.pop();
			bb.pop();

			// more than 10 will be return -1
			if (answer > 10)
				break;

			// if ball goes to O
			if (rx == ox && ry == oy)
			{
				flag = true;
				break;
			}

			// search each directions
			for (int i = 0; i < 4; i++)
			{
				int next_rx = rx + direction_x[i];
				int next_ry = ry + direction_y[i];
				int next_bx = bx + direction_x[i];
				int next_by = by + direction_y[i];

				// move red ball
				while (true)
				{
					if (arr[next_rx][next_ry] == '#')
					{
						next_rx -= direction_x[i];
						next_ry -= direction_y[i];
						break;
					}
					if (arr[next_rx][next_ry] == 'O')
						break;
					next_rx += direction_x[i];
					next_ry += direction_y[i];
				}

				// move blue ball
				while (true)
				{
					if (arr[next_bx][next_by] == '#')
					{
						next_bx -= direction_x[i];
						next_by -= direction_y[i];
						break;
					}
					if (arr[next_bx][next_by] == 'O')
						break;
					next_bx += direction_x[i];
					next_by += direction_y[i];
				}

				// blue ball goes to O, continue
				if (next_bx == ox && next_by == oy)
					continue;

				// if two ball is at the same position, update location
				if (next_rx == next_bx && next_ry == next_by)
				{
					switch (i)
					{
					case 0:
						rx > bx ? next_rx++ : next_bx++;
						break;
					case 1:
						rx < bx ? next_rx-- : next_bx--;
						break;
					case 2:
						ry > by ? next_ry++ : next_by++;
						break;
					case 3:
						ry < by ? next_ry-- : next_by--;
						break;
					}
				}

				// if it is non_visited location, push to queue
				if (visit[next_rx][next_ry][next_bx][next_by])
					continue;
				rb.push(make_pair(next_rx, next_ry));
				bb.push(make_pair(next_bx, next_by));
				visit[next_rx][next_ry][next_bx][next_by] = true;
			}
		}
		if (flag)
			break;
		else
			answer++;
	}
	if (flag)
		cout << answer;
	else
		cout << -1;
	return 0;
}