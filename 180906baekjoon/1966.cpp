/**
*	baekjoon online judge
*	No. 1966	프린터 큐
*	@author	peter9378
*	@date		2018.09.06
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		int N, M;
		cin >> N >> M;

		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int result = 0;

		for (int i = 0; i < N; i++)
		{
			int temp;
			cin >> temp;
			q.push({ temp, i });
			pq.push(temp);
		}

		while (q.size())
		{
			int here = q.front().first;
			int next = q.front().second;

			q.pop();
			if (pq.top() == here)
			{
				result++;
				pq.pop();
				if (next == M)
					break;
			}
			else
				q.push({ here, next });
		}
		cout << result << "\n";
	}

	return 0;
}