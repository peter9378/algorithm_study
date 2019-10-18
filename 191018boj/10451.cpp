/**
*	BOJ
*	No.10451	순열 사이클
*	@author	peter9378
*	@date		2019.10.18
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int arr[1001];
bool check[1001];

void dfs(int target)
{
	if (check[target])
		return;
	check[target] = true;
	dfs(arr[target]);
}

void init()
{
	for (int i = 1; i < 1001; i++)
		check[i] = false;
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		init();
		int answer = 0;
		for (int i = 1; i <= N; i++)
		{
			if (!check[i])
			{
				dfs(arr[i]);
				answer++;
			}
		}
		cout << answer << "\n";
	}

	return 0;
}