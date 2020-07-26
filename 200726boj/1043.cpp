/**
*	BOJ
*	No.1043	°ÅÁþ¸»
*	@author	peter9378
*	@date		2020.7.26
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

vector<int> arr[55];
bool known[55];
bool realparty[55];
bool joinparty[55][55];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, truth;
	cin >> N >> M >> truth;

	for (int i = 0; i < truth; i++)
	{
		int temp;
		cin >> temp;

		known[temp]++;
	}

	queue<int> q;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;

		for (int j = 0; j < temp; j++)
		{
			int target;
			cin >> target;

			joinparty[i][target] = true;
			if (known[target] && realparty[i] == false)
			{
				realparty[i] = true;
				q.push(i);
			}

			for (int k = 0; k < i; k++)
			{
				if (joinparty[k][target])
				{
					arr[k].push_back(i);
					arr[i].push_back(k);
				}
			}
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < arr[cur].size(); i++)
		{
			int temp = arr[cur][i];
			if (!realparty[temp])
			{
				realparty[temp] = true;
				q.push(temp);
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		if (!realparty[i])
			answer++;
	}

	cout << answer;

	return 0;
}