/**
*	baekjoon online judge
*	No. 1697	숨바꼭질
*	@author	peter9378
*	@date		2019.04.29
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool visit[100001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));

	while (!q.empty())
	{
		int current = q.front().first;
		int count = q.front().second;
		q.pop();

		if (current < 0 || current>100000)
			continue;
		if (visit[current])
			continue;

		visit[current] = true;
		if (current == K)
		{
			// print answer
			cout << count;
			break;
		}

		q.push(make_pair(current * 2, count + 1));
		q.push(make_pair(current + 1, count + 1));
		q.push(make_pair(current - 1, count + 1));
	}

	return 0;
}