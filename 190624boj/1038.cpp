/**
*	BOJ
*	No.1038	감소하는 수
*	@author	peter9378
*	@date		2019.06.24
*/
#include <iostream>
#include <queue>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int N;
	cin >> N;

	queue<long long> q;
	bool flag = true;
	int count = -1;

	for (int i = 0; i < 10; i++)
	{
		q.push(i);
		count++;
		if (count == N)
			break;
	}

	while (true)
	{
		int front = q.front();
		int length = front % 10;
		if (front < 10)
		{
			for (int i = 0; i < front; i++)
			{
				if (count == N)
					break;
				q.push(front * 10 + i);
				count++;
			}
			q.pop();
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				if (count == N)
					break;
				q.push(q.front() * 10 + i);
				count++;
			}
			q.pop();
		}
		if (q.back() == 9876543210 && count != N)
		{
			flag = false;
			break;
		}
		if (count == N)
			break;
	}
	if (flag)
		cout << q.back();
	else
		cout << -1;

	return 0;
}