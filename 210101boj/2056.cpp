/**
*	BOJ
*	No.2056	ÀÛ¾÷
*	@author	peter9378
*	@date		2021.01.01	Greetings, 2021
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
#include <complex>
using namespace std;

vector<int> v[10001];
int arr[10001];
int time[10001];
int temp[10001];
queue<int> q;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int a, b, c;
		cin >> a >> b;
		temp[i] = time[i] = a;
		if (b)
		{
			for (int j = 0; j < b; j++)
			{
				cin >> c;
				v[c].push_back(i);
				arr[i]++;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (!arr[i])
			q.push(i);
	}

	int answer = 0;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i];

			time[next] = max(time[next], temp[next] + time[current]);
			arr[next]--;

			if (!arr[next])
				q.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
		answer = max(answer, time[i]);

	cout << answer;

	return 0;
}
