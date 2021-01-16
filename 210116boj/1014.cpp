/**
*	BOJ
*	No.1014	да╢в
*	@author	peter9378
*	@date		2021.01.16
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

#define MAX 15


int N, M;
char arr[MAX][MAX];
int number[MAX][MAX];

vector<int> visit;
int visitCnt = 1;

vector<int> aMatch;
vector<int> bMatch;

vector<int> point;
vector<vector<int>> adj;
int direction_y[6] = { -1,-1,0,0,1,1 };
int direction_x[6] = { -1,1,-1,1,-1,1 };

bool dfs(int a)
{
	if (visit[a] == visitCnt)
		return false;

	visit[a] = visitCnt;

	for (int i = 0; i < adj[a].size(); i++)
	{
		int b = adj[a][i];

		if (bMatch[b] == -1 || dfs(bMatch[b]))
		{
			aMatch[a] = b;
			bMatch[b] = a;

			return true;
		}
	}
	return false;
}

int bipartiteMatch()
{
	int size = 0;

	visit = vector<int>(N*M + 1);
	aMatch = vector<int>(N*M + 1, -1);
	bMatch = vector<int>(N*M + 1, -1);

	for (int a = 0; a < point.size(); a++)
	{
		visitCnt++;
		size += dfs(point[a]);
	}

	return size;
}


// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C;
	cin >> C;

	while (C--)
	{
		cin >> N >> M;

		adj = vector<vector<int>>(N*M + 1);
		point.clear();

		int crash = 0;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == 'x')
					crash++;

				if (j % 2 == 0)
					point.push_back(cnt);

				number[i][j] = cnt++;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j += 2)
			{
				if (arr[i][j] == 'x')
					continue;

				for (int k = 0; k < 6; k++)
				{
					int x = j + direction_x[k];
					int y = i + direction_y[k];

					if (x < 0 || y < 0 || x >= M || y >= N || arr[y][x] == 'x')
						continue;

					adj[number[i][j]].push_back(number[y][x]);
				}
			}
		}

		int answer = bipartiteMatch();
		cout << N * M - answer - crash << "\n";
	}

	return 0;
}
