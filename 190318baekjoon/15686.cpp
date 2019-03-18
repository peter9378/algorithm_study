/**
*	baekjoon online judge
*	No. 15686	치킨 배달
*	@author	peter9378
*	@date		2019.03.19
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer;
vector<pair<int, int>> customer;
vector<pair<int, int>> location;
int check[50];
int arr[51][51];

// dfs
int dfs(int index, int count)
{
	if (index > location.size())
		return 0;

	if (count == M)
	{
		int temp = 0;
		for (int i = 0; i < customer.size(); i++)
		{
			int distance = 999999999;
			for (int j = 0; check[j] != -1; j++)
			{
				int customerr = customer[i].first;
				int customerc = customer[i].second;
				int locationr = location[check[j]].first;
				int lcoationc = location[check[j]].second;

				distance = min(distance, abs(customerr - locationr) + abs(customerc - lcoationc));
			}
			temp += distance;
		}
		answer = min(answer, temp);
		return 0;
	}

	check[count] = index;
	dfs(index + 1, count + 1);
	check[count] = -1;

	dfs(index + 1, count);
	return 0;
}


// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N >> M;

	// init
	for (int i = 0; i < 50; i++)
		check[i] = -1;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
				customer.push_back(make_pair(i, j));
			else if (arr[i][j] == 2)
				location.push_back(make_pair(i, j));
		}
	}

	answer = 999999999;
	dfs(0, 0);

	// print answer
	cout << answer;

	return 0;
}