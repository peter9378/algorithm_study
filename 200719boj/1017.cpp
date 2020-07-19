/**
*	BOJ
*	No.1017	¼Ò¼ö ½Ö
*	@author	peter9378
*	@date		2020.07.19
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

#define MAX 50

int N, atemp, btemp;
bool flag = false;
bool prime[2222];
int parent[2222];
int check[2222];

vector<int> arr[2222];
vector<int> a, b, answer;

void init()
{
	for (int i = 2; i < 2222; i++)
		prime[i] = true;
	for (int i = 1; i < 2222; i++)
	{
		if (!prime[i])
			continue;
		for (int j = i * 2; j < 2222; j += i)
			prime[j] = false;
	}
	return;
}

bool dfs(int target)
{
	for (auto i : arr[target])
	{
		if (check[i])
			continue;
		if (i == atemp || i == btemp)
			continue;

		check[i] = true;

		if (!prime[a[target] + b[i - MAX]])
			continue;
		if (parent[i] == -1 || dfs(parent[i]))
		{
			parent[i] = target;
			return true;
		}
	}
	return false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	init();
	for (int i = 1; i <= N; i++)
	{
		int n;
		cin >> n;
		if (i == 1 && n % 2 == 0)
			flag = true;
		if (n & 1)
			a.push_back(n);
		else
			b.push_back(n);
	}

	if (a.size() != b.size())
	{
		cout << -1;
	}
	else
	{
		if (flag)
			swap(a, b);
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				if (prime[a[i] + b[j]])
					arr[i].push_back(j + MAX);
			}
		}

		for (int i = 0; i < b.size(); i++)
		{
			for (int k = 0; k < 2222; k++)
				parent[k] = -1;

			if (!prime[a[0] + b[i]])
				continue;

			int result = 1;
			parent[i + MAX] = 0;
			atemp = 0;
			btemp = i + MAX;

			for (int j = 1; j < a.size(); j++)
			{
				for (int k = 0; k < 2222; k++)
					check[k] = false;
				check[0] = check[i + MAX] = true;
				result += dfs(j);
			}

			if (result != b.size())
				continue;

			answer.push_back(b[i]);
		}

		if (answer.size())
		{
			sort(answer.begin(), answer.end());
			for (int i = 0; i < answer.size(); i++)
				cout << answer[i] << " ";
		}
		else
			cout << -1;
	}

	return 0;
}