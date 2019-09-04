/**
*	BOJ
*	No.17136	색종이 붙이기
*	@author	peter9378
*	@date		2019.09.05
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define MAX 10

int arr[11][11];
bool visit[11][11];
int answer, counting;
vector<int> v;

void print()
{
	cout << endl;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void dfs(int i, int j)
{
	if (j == MAX)
	{
		dfs(i + 1, 0);
		return;
	}

	if (i == MAX)
	{
		answer = min(answer, counting);
		return;
	}

	if (!arr[i][j])
	{
		dfs(i, j + 1);
		return;
	}

	for (int size = 5; size > 0; size--)
	{
		if (v[size] == 0 || i + size > MAX || j + size > MAX)
			continue;

		bool find = true;
		for (int a = 0; a < size; a++)
		{
			for (int b = 0; b < size; b++)
			{
				if (!arr[i + a][j + b])
				{
					find = false;
					a = size;
					b = size;
					break;
				}
			}
		}

		if (!find)
			continue;

		for (int a = 0; a < size; a++)
		{
			for (int b = 0; b < size; b++)
				arr[i + a][j + b] = 0;
		}

		v[size]--;
		counting++;
		dfs(i, j + size);

		for (int a = 0; a < size; a++)
		{
			for (int b = 0; b < size; b++)
				arr[i + a][j + b] = 1;
		}

		v[size]++;
		counting--;
	}

}

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cin >> arr[i][j];
	}


	for (int i = 0; i < 6; i++)
		v.push_back(5);

	answer = 999999999;
	dfs(0, 0);
	if (answer == 999999999)
		cout << -1;
	else
		cout << answer;


	return 0;
}