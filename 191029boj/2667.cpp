/**
*	BOJ
*	No.2667	단지번호 붙이기
*	@author	peter9378
*	@date		2019.10.29
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int arr[30][30];
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++)
			arr[i][j] = s[j] == '0' ? 0 : 1;
	}

	vector<int> answer;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j])
			{
				int count = 0;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				arr[i][j] = 0;

				while (!q.empty())
				{
					count++;
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int next_x = x + direction_x[k];
						int next_y = y + direction_y[k];

						if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N && arr[next_x][next_y])
						{
							q.push(make_pair(next_x, next_y));
							arr[next_x][next_y] = 0;
						}
					}
				}
				answer.push_back(count);
			}
		}
	}

	cout << answer.size() << "\n";
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << "\n";


	return 0;
}