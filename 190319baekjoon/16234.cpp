/**
*	baekjoon online judge
*	No. 16234	인구 인동
*	@author	peter9378
*	@date		2019.03.19
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 51

int arr[MAX][MAX];
bool visit[MAX][MAX];

vector<pair<int, int>> country;
int N, L, R, answer = 0;

int direction_x[] = { 1, -1, 0, 0 };
int direction_y[] = { 0, 0, 1, -1 };

bool flag = true;

bool isOpen(pair<int, int>& country_pair, int x, int y)
{
	// if country is not exist
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false;

	int difference = abs((arr[country_pair.first][country_pair.second] - arr[x][y]));

	// if difference is not fit with standard
	if (L > difference || difference > R)
		return false;

	return true;
}

// bfs
void bfs(int x, int y)
{
	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	country.push_back(make_pair(x, y));

	int civil = arr[x][y];
	int total = 1;

	while (!q.empty())
	{
		pair<int, int> country_pair = q.front();
		q.pop();

		// check 4 directions
		for (int i = 0; i < 4; i++)
		{
			int near_x = country_pair.first + direction_x[i];
			int near_y = country_pair.second + direction_y[i];

			if (!isOpen(country_pair, near_x, near_y))
				continue;
			if (visit[near_x][near_y])
				continue;

			// if the country is open
			q.push(make_pair(near_x, near_y));
			country.push_back(make_pair(near_x, near_y));
			visit[near_x][near_y] = true;

			// init
			civil += arr[near_x][near_y];
			total++;
		}
	}

	if (total == 1)
		return;

	int average = civil / total;

	for (int i = 0; i < country.size(); i++)
		arr[country[i].first][country[i].second] = average;

	flag = true;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N >> L >> R;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	// use bfs when country is more than 1
	if (N > 1)
	{
		while (flag)
		{
			flag = false;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (!visit[i][j])
					{
						visit[i][j] = true;
						bfs(i, j);
						country.clear();
					}
				}
			}

			if (!flag)
				break;

			answer++;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					visit[i][j] = false;
			}
		}
	}

	// print answer
	cout << answer;

	return 0;
}