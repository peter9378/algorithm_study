/**
*	BOJ
*	No.1021	회전하는 큐
*	@author	peter9378
*	@date		2019.07.29
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> v;
	int temp;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		v.push_back(temp - 1);
	}

	deque<int> d;
	for (int i = 0; i < N; i++)
		d.push_back(i);

	int index = 0;
	int answer = 0;
	while (index != v.size())
	{
		if (v[index] != d[0])
		{
			int r = 999, l = 999;
			// find nearest value
			for (int i = 1;; i++)
			{
				if (d[i] == v[index])
				{
					r = i;
					break;
				}
			}
			for (int i = d.size() - 1;; i--)
			{
				if (d[i] == v[index])
				{
					l = d.size() - i;
					break;
				}
			}
			if (r > l)
			{
				answer += l;
				while (l--)
				{
					d.push_front(d[d.size() - 1]);
					d.pop_back();
				}
			}
			else
			{
				answer += r;
				while (r--)
				{
					d.push_back(d[0]);
					d.pop_front();
				}
			}
		}
		index++;
		d.pop_front();
	}
	cout << answer;


	return 0;
}