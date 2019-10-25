/**
*	BOJ
*	No.15666	N°ú M(12)
*	@author	peter9378
*	@date		2019.10.25
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

void dfs(int index, int count)
{
	if (answer.size() == M)
	{
		for (int i = 0; i < M; i++)
			cout << answer[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = index; i < v.size(); i++)
	{
		answer.push_back(v[i]);
		dfs(i, count + 1);
		answer.pop_back();
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	set<int> se;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		se.insert(temp);
	}
	v.assign(se.begin(), se.end());
	sort(v.begin(), v.end());
	dfs(0, 0);

	return 0;
}