/**
*	BOJ
*	No.17142	연구소 3
*	@author	peter9378
*	@date		2019.09.25
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int arr[51][51];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };
bool visit[51][51];
int temp[51][51];

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			visit[i][j] = false;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			temp[i][j] = arr[i][j];
	}
}

bool promise()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visit[i][j] && arr[i][j] != -1)
				return false;
		}
	}
	return true;
}

void print()
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << temp[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<pair<int, int>> bomb;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				arr[i][j] = -1;
			else if (arr[i][j] == 2)
			{
				arr[i][j] = 0;
				bomb.push_back(make_pair(i, j));
			}
		}
	}

	vector<int> check;
	for (int i = 0; i < M; i++)
		check.push_back(1);
	for (int i = M; i < bomb.size(); i++)
		check.push_back(0);

	sort(check.begin(), check.end());

	int answer = 987654321;
	do
	{
		queue<pair<int, int>> q;
		init();
		for (int i = 0; i < bomb.size(); i++)
		{
			if (check[i])
			{
				q.push(bomb[i]);
				visit[bomb[i].first][bomb[i].second] = true;
			}
		}

		int cnt = 0;
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int nx = x + direction_x[k];
				int ny = y + direction_y[k];

				if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[nx][ny] && temp[nx][ny] != -1)
				{
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
					temp[nx][ny] = temp[x][y] + 1;
					if (find(bomb.begin(), bomb.end(), make_pair(nx, ny)) == bomb.end())
						cnt = max(cnt, temp[nx][ny]);
				}
			}
		}
		//print();
		if (promise())
			answer = min(answer, cnt);

	} while (next_permutation(check.begin(), check.end()));

	if (answer == 987654321)
		cout << -1;
	else
		cout << answer;


	return 0;
}