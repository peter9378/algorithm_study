/**
*	BOJ
*	No.6549	히스토그램에서 가장 큰 직사각형
*	@author	peter9378
*	@date		2019.11.11
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int arr[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	while (cin >> N)
	{
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		long long answer = 0;
		stack<int> s;
		for (int i = 0; i < N; i++)
		{
			while (!s.empty() && arr[s.top()] > arr[i])
			{
				long long temp = arr[s.top()];
				s.pop();

				long long width = i;
				if (!s.empty())
					width = i - s.top() - 1;
				answer = max(answer, width*temp);
			}
			s.push(i);
		}

		while (!s.empty())
		{
			long long temp = arr[s.top()];
			s.pop();
			long long width = N;
			if (!s.empty())
				width = N - s.top() - 1;
			answer = max(answer, width*temp);
		}
		cout << answer << "\n";
	}

	return 0;
}