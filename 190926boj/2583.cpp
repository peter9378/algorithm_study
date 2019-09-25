/**
*	BOJ
*	No.2583	영역 구하기
*	@author	peter9378
*	@date		2019.09.26
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visit[101][101];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

void print()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
			cout << visit[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N, K;
	cin >> M >> N >> K;

	vector<vector<int>> v;
	for (int i = 0; i < K; i++)
	{
		vector<int> temp;
		for (int j = 0; j < 4; j++)
		{
			int a;
			cin >> a;
			temp.push_back(a);
		}
		v.push_back(temp);
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int x = v[i][1]; x < v[i][3]; x++)
		{
			for (int y = v[i][0]; y < v[i][2]; y++)
				visit[x][y] = true;
		}
	}
	//print();

	vector<int> answer;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j])
				continue;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			visit[i][j] = true;

			int size = 1;
			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; k++)
				{
					int nx = x + direction_x[k];
					int ny = y + direction_y[k];

					if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visit[nx][ny])
					{
						visit[nx][ny] = true;
						size++;
						q.push(make_pair(nx, ny));
					}
				}
			}
			answer.push_back(size);
		}
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << " ";


	return 0;
}