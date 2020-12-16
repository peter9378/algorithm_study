/**
*	BOJ
*	No.9328	¿­¼è
*	@author	peter9378
*	@date		2020.12.16
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

const int MAX = 100 + 2;

typedef struct
{
	int x, y;
}coor;

coor moveDir[4] = { {1, 0}, {-1, 0} , {0, 1}, {0, -1} };
int H, W;
string bluePrint[MAX];
bool visited[MAX][MAX];
bool key[26];
int document;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		if (curY < 0 || curY > H + 1 || curX < 0 || curX > W + 1)
			continue;

		if (visited[curY][curX] || bluePrint[curY][curX] == '*' || ('A' <= bluePrint[curY][curX] && bluePrint[curY][curX] <= 'Z'))
			continue;

		visited[curY][curX] = true;
		if (bluePrint[curY][curX] == '$')
		{
			document++;
			bluePrint[curY][curX] = '.';
		}

		if ('a' <= bluePrint[curY][curX] && bluePrint[curY][curX] <= 'z')
		{
			char door = (char)toupper(bluePrint[curY][curX]);
			bluePrint[curY][curX] = '.';

			if (key[(int)door - 65] == false)
			{
				key[(int)door - 65] = true;
				for (int y = 1; y <= H; y++)
				{
					for (int x = 1; x <= W; x++)
					{
						if (bluePrint[y][x] == door)
							bluePrint[y][x] = '.';
					}
				}
				memset(visited, false, sizeof(visited));

				while (!q.empty())
					q.pop();

				q.push(make_pair(curY, curX));
				continue;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + moveDir[i].x;
			int nextX = curX + moveDir[i].y;

			q.push(make_pair(nextY, nextX));
		}
	}
	return;
}

void init()
{
	memset(key, false, sizeof(key));
	memset(visited, false, sizeof(visited));
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		init();

		for (int j = 0; j < MAX; j++)
			bluePrint[j].clear();

		cin >> H >> W;

		for (int j = 0; j < W + 2; j++)
			bluePrint[0] += '.';

		for (int j = 1; j <= H; j++)
		{
			string temp;
			cin >> temp;
			bluePrint[j] += '.';
			bluePrint[j] += temp;
			bluePrint[j] += '.';
		}

		for (int j = 0; j < W + 2; j++)
			bluePrint[H + 1] += '.';

		string alphabet;
		cin >> alphabet;

		for (int j = 0; alphabet[j] != '0' && j < alphabet.length(); j++)
		{
			key[(int)alphabet[j] - 97] = true;

			for (int x = 1; x <= H; x++)
			{
				for (int y = 1; y <= W; y++)
				{
					if (bluePrint[x][y] == (char)toupper(alphabet[j]))
						bluePrint[x][y] = '.';
				}
			}
		}

		document = 0;
		bfs(0, 0);
		cout << document << "\n";
	}

	return 0;
}
