/**
*	baekjoon online judge
*	No. 10773	제로
*	@author	peter9378
*	@date		2019.06.30
*/
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int K;
	cin >> K;

	stack<int> s;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;

		if (temp)
			s.push(temp);
		else
			s.pop();
	}

	long long answer = 0;

	while(!s.empty())
	{
		answer += s.top();
		s.pop();
	}
	cout << answer;
	return 0;
}