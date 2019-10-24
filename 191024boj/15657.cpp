/**
*	BOJ
*	No.15657	N°ú M(8)
*	@author	peter9378
*	@date		2019.10.24
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <functional>

using namespace std;

int N, M;
vector<int> v;
vector<int> answer;
set<vector<int>> s;

void dfs(int count)
{
	if (answer.size() == M)
	{
		for (int i = 0; i < M - 1; i++)
		{
			if (answer[i] > answer[i + 1])
				return;
		}
		s.insert(answer);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		answer.push_back(v[i]);
		dfs(count + 1);
		answer.pop_back();
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	dfs(0);

	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		for (int i = 0; i < M; i++)
			cout << iter->at(i) << " ";
		cout << "\n";
	}

	return 0;
}