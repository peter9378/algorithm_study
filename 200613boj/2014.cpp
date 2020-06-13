/**
*	BOJ
*	No.2014	¼Ò¼öÀÇ °ö
*	@author	peter9378
*	@date		2020.06.13
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

long long arr[101];
unordered_set<long long> visit;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int K, N;
	cin >> K >> N;

	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < K; i++)
		cin >> arr[i];

	pq.push(1);
	long long result = 0;
	while (N--)
	{
		long long current = pq.top();
		pq.pop();

		for (int i = 0; i < K; i++)
		{
			long long next = current * arr[i];
			if (pq.size() > N && result < next)
				continue;

			if (visit.find(next) == visit.end())
			{
				result = max(result, next);
				visit.insert(next);
				pq.push(next);
			}
		}
	}

	cout << pq.top();

	return 0;
}