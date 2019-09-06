/**
*	BOJ
*	No.1941	소문난 칠공주
*	@author	peter9378
*	@date		2019.09.07
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAX 5

string arr[MAX];
bool check[MAX*MAX];
int temp[MAX][MAX];
int answer = 0;
set<vector<pair<int, int>>> s;

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

bool isSomoon(vector<pair<int, int>> v)
{
	sort(v.begin(), v.end());
	if (s.find(v) != s.end())
		return false;
	int count = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (arr[v[i].first][v[i].second] == 'S')
			count++;
	}
	if (count < 4)
		return false;

	// check neighbor
	count = 1;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			temp[i][j] = 0;
	}
	for (int i = 1; i < v.size(); i++)
	{
		temp[v[i].first][v[i].second] = 1;
	}
	queue<pair<int, int>> q;
	q.push(make_pair(v[0].first, v[0].second));
	temp[v[0].first][v[0].second] = -1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int next_x = x + direction_x[k];
			int next_y = y + direction_y[k];

			if (next_x >= 0 && next_y >= 0 && next_x < 5 && next_y < 5)
			{
				if (temp[next_x][next_y] == 1)
				{
					q.push(make_pair(next_x, next_y));
					temp[next_x][next_y] = -1;
					count++;
				}
			}
		}
	}

	if (count == 7)
	{
		s.insert(v);
		return true;
	}
	return false;
}

void dfs(int index, int count)
{
	if (count == 7)
	{
		vector<pair<int, int>> v;
		for (int i = 0; i < MAX*MAX; i++)
		{
			if (check[i])
				v.push_back(make_pair(i / MAX, i%MAX));
		}
		isSomoon(v);
		return;
	}
	if (index == 25)
		return;

	check[index] = true;
	dfs(index + 1, count + 1);
	check[index] = false;
	dfs(index + 1, count);
}


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	for (int i = 0; i < MAX; i++)
		cin >> arr[i];

	dfs(0, 0);

	cout << s.size();

	return 0;
}