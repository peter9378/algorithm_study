/**
*	BOJ
*	No.17298	¿ÀÅ«¼ö
*	@author	peter9378
*	@date		2019.12.06
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
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	stack<int> s;
	vector<int> answer(N);
	s.push(0);
	for (int i = 1; i < N; i++)
	{
		if (s.empty())
			s.push(i);

		while (!s.empty() && v[i] > v[s.top()])
		{
			answer[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; i++)
	{
		if (answer[i])
			cout << answer[i] << " ";
		else
			cout << "-1 ";
	}

	return 0;
}
