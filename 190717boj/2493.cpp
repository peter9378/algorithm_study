/**
*	BOJ
*	No.2493	탑
*	@author	peter9378
*	@date		2019.07.17
*/
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int arr[500005];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	stack<pair<int, int>> s;
	for (int i = 0; i < N; i++)
	{
		if (s.empty())
		{
			cout << "0 ";
			s.push(make_pair(i + 1, arr[i]));
		}
		else
		{
			while (s.top().second < arr[i])
			{
				s.pop();
				if (s.empty())
					break;
			}
			if (s.empty())
				cout << "0 ";
			else
				cout << s.top().first << " ";
			s.push(make_pair(i + 1, arr[i]));
		}
	}

	return 0;
}
