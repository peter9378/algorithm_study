/**
*	BOJ
*	No.1525	∆€¡Ò
*	@author	peter9378
*	@date		2021.02.17
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

#define TARGET 123456789

int direction_x[] = { 0, 1, 0, -1 };
int direction_y[] = { 1, 0, -1, 0 };

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int start = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int num;
			cin >> num;

			if (num == 0)
				num = 9;
			start = start * 10 + num;
		}
	}

	queue<int> q;
	map<int, int> m;
	q.push(start);
	m[start] = 0;

	while (!q.empty())
	{
		int current = q.front();
		string s = to_string(current);
		q.pop();

		if (current == TARGET)
			break;

		int target = s.find('9');
		int x = target / 3;
		int y = target % 3;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + direction_x[i];
			int next_y = y + direction_y[i];

			if (0 <= next_x && next_x < 3 && 0 <= next_y && next_y < 3)
			{
				string temp = s;
				swap(temp[x * 3 + y], temp[next_x * 3 + next_y]);

				int next = stoi(temp);
				if (!m.count(next))
				{
					m[next] = m[current] + 1;
					q.push(next);
				}
			}
		}
	}

	if (m.count(TARGET))
		cout << m[TARGET];
	else
		cout << -1;

	return 0;
}
