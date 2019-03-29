/**
*	baekjoon online judge
*	No. 11866	조세퍼스 문제 0
*	@author	peter9378
*	@date		2019.03.30
*/
#include <iostream>
#include <queue>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N, M;
	cin >> N >> M;

	queue<int> q;

	// init queue
	for (int i = 1; i <= N; i++)
		q.push(i);

	// print answer
	cout << '<';
	while (!q.empty())
	{
		if (q.size() == 1)
		{
			cout << q.front() << '>';
			q.pop();
			break;
		}
		for (int i = 1; i < M; i++)
		{
			q.push(q.front());
			q.pop();
		}
		cout << q.front() << ", ";
		q.pop();
	}

	return 0;
}