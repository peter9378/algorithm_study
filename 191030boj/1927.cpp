/**
*	BOJ
*	No.1927	ÃÖ¼Ò Èü
*	@author	peter9378
*	@date		2019.10.30
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int> q;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (q.empty())
				cout << "0\n";
			else
			{
				cout << -q.top() << "\n";
				q.pop();
			}
		}
		else
			q.push(-x);
	}

	return 0;
}