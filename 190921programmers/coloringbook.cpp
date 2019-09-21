#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (picture[i][j])
			{
				int target = picture[i][j];
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				number_of_area++;
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

						if (nx >= 0 && ny >= 0 && nx < m && ny < n && picture[nx][ny] == target)
						{
							cnt++;
							picture[nx][ny] = 0;
							q.push(make_pair(nx, ny));
						}
					}
				}
				max_size_of_one_area = max(max_size_of_one_area, cnt);
			}
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	return answer;
}