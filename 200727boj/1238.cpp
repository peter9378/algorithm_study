/**
*	BOJ
*	No.1238	ÆÄÆ¼
*	@author	peter9378
*	@date		2020.7.27
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
using namespace std;

int N, M, X;
vector<pair<int, int>> arr[1001];

vector<int> dijk(int start, int target)
{
	vector<int> temp(target, 987654321);
	temp[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int time = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (temp[current] < time)
			continue;

		for (int i = 0; i < arr[current].size(); i++)
		{
			int neighbor = arr[current][i].first;
			int neighborTime = time + arr[current][i].second;

			if (temp[neighbor] > neighborTime)
			{
				temp[neighbor] = neighborTime;
				pq.push({ neighborTime, neighbor });
			}
		}
	}
	return temp;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++)
	{
		int start, end, time;
		cin >> start >> end >> time;

		arr[start].push_back({ end, time });
	}

	int answer = -1;
	for (int i = 1; i <= N; i++)
	{
		vector<int> a = dijk(i, N + 1);
		vector<int> b = dijk(X, N + 1);

		if (a[X] + b[i] >= 987654321 || a[X] < -b[i])
			continue;
		answer = max(answer, a[X] + b[i]);
	}

	cout << answer;

	return 0;
}