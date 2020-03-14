/**
*	BOJ
*	No.1715	카드 정렬하기
*	@author	peter9378
*	@date		2020.03.14
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}

	int sum = 0;
	if (pq.size() == 1)
		cout << "0";
	else
	{
		while (!pq.empty())
		{
			int current = pq.top();
			pq.pop();
			int next = pq.top();
			pq.pop();

			sum += current + next;
			if (pq.empty())
				break;
			pq.push(current + next);
		}

		cout << sum;
	}

	return 0;
}
