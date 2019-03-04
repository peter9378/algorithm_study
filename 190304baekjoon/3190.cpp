/**
*	baekjoon online judge
*	No. 3190	뱀
*	@author	peter9378
*	@date		2019.03.04
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 101
// board array
bool arr[MAX][MAX];
// turn array
int turn[101][2];
vector<pair<int, int>> snake;
// direction array. right - down - left - up
int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// check collision from snake's body and head
bool collision()
{
	int size = snake.size() - 1;
	int x = snake[size].first;
	int y = snake[size].second;

	for (int i = 0; i < size; i++)
	{
		if (snake[i].first == x && snake[i].second == y)
			return true;
	}
	return false;
}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, L;

	// input variables
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = true;
	}

	int current_direction = 0, answer = 0;
	bool flag = true;
	snake.push_back(make_pair(1, 1));
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x;
		char y;
		cin >> x >> y;

		// move before change the direction
		for (int j = answer; j < x; j++)
		{
			int head_x = snake.back().first + direction_x[current_direction];
			int head_y = snake.back().second + direction_y[current_direction];
			
			snake.push_back(make_pair(head_x, head_y));

			// check collision
			if ((head_x <= 0 || head_x > N || head_y <= 0 || head_y > N) || (collision() && snake.size() > 3))
			{
				i = L;
				flag = false;
				answer++;
				break;
			}

			if (arr[head_x][head_y])
				arr[head_x][head_y] = false;
			else
				snake.erase(snake.begin());

			answer++;
		}

		// change the direction
		switch (y)
		{
		case 'D':
			current_direction++;
			if (current_direction == 4)
				current_direction = 0;
			break;
		case 'L':
			current_direction--;
			if (current_direction == -1)
				current_direction = 3;
			break;
		}
	}

	// move forward without change direction
	while(flag)
	{
		answer++;
		int head_x = snake.back().first + direction_x[current_direction];
		int head_y = snake.back().second + direction_y[current_direction];

		snake.push_back(make_pair(head_x, head_y));
		// check collision
		if ((head_x <= 0 || head_x > N || head_y <= 0 || head_y > N) || (collision() && snake.size() > 3))
			break;
		if (arr[head_x][head_y])
			arr[head_x][head_y] = false;
		else
			snake.erase(snake.begin());
	}

	cout << answer;

	return 0;
}