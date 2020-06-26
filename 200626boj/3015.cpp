/**
*	BOJ
*	No.3015	오아시스 재결합
*	@author	peter9378
*	@date		2020.06.26
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
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	long long answer = 0;
	stack<pair<int, int>> s;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		pair<int, int> p = { temp, 1 };

		while (!s.empty())
		{
			if (s.top().first <= temp)
			{
				answer += s.top().second;
				if (s.top().first == temp)
					p.second += s.top().second;
				s.pop();
			}
			else
			{
				if (!s.empty())
					answer += 1;
				break;
			}
		}
		s.push(p);
	}

	cout << answer;

	return 0;
}
