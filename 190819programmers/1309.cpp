/**
*	Programmers
*	2017 카카오 코드 예선	카카오프렌즈 컬러링북
*	@author	peter9378
*	@date		2019.08.19
*/
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<int> answer(2);
	int direction_x[] = { 0, 1, 0, -1 };
	int direction_y[] = { 1, 0, -1, 0 };

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (picture[i][j])
			{
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				int target = picture[i][j];
				picture[i][j] = 0;
				int count = 1;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int next_x = x + direction_x[k];
						int next_y = y + direction_y[k];

						if (next_x >= 0 && next_y >= 0 && next_x < m && next_y < n)
						{
							if (picture[next_x][next_y] == target)
							{
								q.push(make_pair(next_x, next_y));
								count++;
								picture[next_x][next_y] = 0;
							}
						}
					}
				}
				number_of_area++;
				max_size_of_one_area = max(max_size_of_one_area, count);
			}
		}
	}

	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}