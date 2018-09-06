/**
*	baekjoon online judge
*	No. 1158	조세퍼스 문제
*	@author	peter9378
*	@date		2018.05.01
*/
#include <iostream>
#include <queue>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 입력
	int N, M;
	cin >> N >> M;

	queue<int> q;

	// 큐 초기화
	for (int i = 1; i <= N; i++)
		q.push(i);

	// 순열 출력 루프
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