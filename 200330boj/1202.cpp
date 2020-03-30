/**
*	BOJ
*	No.1202	보석 도둑
*	@author	peter9378
*	@date		2020.03.30
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

pair<int, int> arr[300003];
int bag[300003];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < K; i++)
		cin >> bag[i];

	sort(arr, arr + N);
	sort(bag, bag + K);

	long long answer = 0;
	priority_queue<int> pq;
	for (int i = 0, j = 0; i < K; i++)
	{
		while (j < N && arr[j].first <= bag[i])
			pq.push(arr[j++].second);

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;

	return 0;
}