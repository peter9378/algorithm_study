/**
*	BOJ
*	No.18290	NM°ú K(1)
*	@author	peter9378
*	@date		2020.03.09
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

int N, M, K;
long long answer = -987654321;
int arr[111];

void dfs(vector<pair<int, int>>& v)
{
	if (v.size() == K)
	{
		long long sum = 0;
		for (pair<int, int> p : v)
			sum += p.second;
		answer = max(answer, sum);
		return;
	}

	for (int i = v.back().first + 1; i < N*M; i++)
	{
		bool flag = true;
		for (pair<int, int> p : v)
		{
			if ((i%M == p.first % M && abs(i / M - p.first / M) == 1) || (abs(i - p.first) == 1 && i / M == p.first / M))
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			v.push_back({ i, arr[i] });
			dfs(v);
			v.pop_back();
		}
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N*M; i++)
		cin >> arr[i];

	for (int i = 0; i < N*M; i++)
	{
		vector<pair<int, int>> v;
		v.push_back({ i, arr[i] });
		dfs(v);
	}

	cout << answer;

	return 0;
}
