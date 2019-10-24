/**
*	BOJ
*	No.15656	N°ú M(7)
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

void dfs(int count)
{
	if (answer.size() == M)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
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

	return 0;
}