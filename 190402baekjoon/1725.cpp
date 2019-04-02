/**
*	baekjoon online judge
*	No. 1725	히스토그램
*	@author	peter9378
*	@date		2019.04.02
*/
#include <iostream>
#include <stack>
using namespace std;

int arr[100001];

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	stack<int> s;
	int answer = 0;
	
	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && arr[s.top()] > arr[i])
		{
			int height = arr[s.top()];
			s.pop();

			int width = i;
			if (!s.empty())
				width = (i - s.top() - 1);

			if (answer < width*height)
				answer = width*height;
		}
		s.push(i);
	}

	while (!s.empty())
	{
		int height = arr[s.top()];
		s.pop();
		int width = N;

		if (!s.empty())
			width = N - s.top() - 1;

		if (answer < width*height)
			answer = width*height;
	}

	cout << answer;

	return 0;
}