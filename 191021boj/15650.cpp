/**
*	BOJ
*	No.15650	N��  M(2)
*	@author	peter9378
*	@date		2019.10.21
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;
int arr[11];
bool visit[11];
set<vector<int>> s;

// dfs
void dfs(int count)
{
	if (count == M)
	{
		vector<int> temp;
		for (int i = 0; i < M; i++)
			temp.push_back(arr[i]);
		sort(temp.begin(), temp.end());
		s.insert(temp);
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				arr[count] = i + 1;
				dfs(count + 1);
				visit[i] = false;
			}
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	cin >> N >> M;

	dfs(0);

	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		for (int i = 0; i < iter->size(); i++)
			cout << iter->at(i) << " ";
		cout << "\n";
	}

	return 0;
}