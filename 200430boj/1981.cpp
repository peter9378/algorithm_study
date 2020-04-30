/**
*	BOJ
*	No.1981	배열에서 이동
*	@author	peter9378
*	@date		2020.04.30
*/
#define _USE_MATH_DEFINES
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
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

int arr[101][101];
bool visit[101][101];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			v.push_back(arr[i][j]);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int answer = 987654321;
	int left = 0, right = 0;
	while (left < v.size())
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				visit[i][j] = false;
		}
		queue<pair<int, int>> q;

		if (v[left] <= arr[0][0] && v[right] >= arr[0][0])
		{
			visit[0][0] = true;
			q.push({ 0, 0 });
		}

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int next_x = x + direction_x[k];
				int next_y = y + direction_y[k];

				if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && !visit[next_x][next_y])
				{
					if (v[left] <= arr[next_x][next_y] && v[right] >= arr[next_x][next_y])
					{
						visit[next_x][next_y] = true;
						q.push({ next_x, next_y });
					}
				}
			}
		}

		if (visit[N - 1][N - 1])
		{
			answer = min(answer, v[right] - v[left]);
			left++;
		}
		else if (right < v.size() - 1)
			right++;
		else
			break;
	}

	cout << answer;

	return 0;
}