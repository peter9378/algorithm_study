/**
*	BOJ
*	No.1826	연료 채우기
*	@author	peter9378
*	@date		2020.04.04
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

pair<int, int> arr[10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + N);

	int L, P;
	cin >> L >> P;

	int index = 0, answer = 0;
	priority_queue<int> pq;
	while (P < L)
	{
		while (arr[index].first <= P)
		{
			if (index == N)
				break;
			pq.push(arr[index++].second);
		}

		if (!pq.size())
			break;
		answer++;
		P += pq.top();
		pq.pop();
	}

	if (P < L)
		cout << -1;
	else
		cout << answer;

	return 0;
}