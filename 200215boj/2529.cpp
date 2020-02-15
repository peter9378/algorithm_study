/**
*	BOJ
*	No.2529	∫ŒµÓ»£
*	@author	peter9378
*	@date		2020.02.15
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
using namespace std;

int K;
int arr[11];
char carr[11];
bool visit[11];
vector<char> v;
vector<string> answer;

bool check(int index, char c)
{
	if (c == '<')
	{
		if (v[index] - '0' < v[index + 1] - '0')
			return true;
		return false;
	}
	else if (c == '>')
	{
		if (v[index] - '0' > v[index + 1] - '0')
			return true;
		return false;
	}
}

void dfs(int count)
{
	if (count - 1 == K)
	{
		for (int i = 0; i < K; i++)
		{
			if (!check(i, carr[i]))
				return;
		}
		string s = "";
		for (int i = 0; i < v.size(); i++)
			s += v[i];
		answer.push_back(s);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		v.push_back(arr[i] + '0');
		dfs(count + 1);
		v.pop_back();
		visit[i] = false;
	}
	return;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		char c;
		cin >> c;
		carr[i] = c;
	}

	for (int i = 0; i < 10; i++)
		arr[i] = i;

	dfs(0);
	sort(answer.begin(), answer.end());
	cout << answer.back() << "\n" << answer.front();

	return 0;
}
