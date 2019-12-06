/**
*	BOJ
*	No.2580	½ºµµÄí
*	@author	peter9378
*	@date		2019.12.06
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

int arr[9][9];
vector<pair<int, int>> v;

void print()
{
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	cout << endl;
	return;
}

bool isEnd()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			if (arr[i][j] == 0)
				return false;
	}

	for (int i = 0; i < 9; i++)
	{
		set<int> x, y;
		for (int j = 0; j < 9; j++)
		{
			x.insert(arr[i][j]);
			y.insert(arr[j][i]);
		}
		if (x.size() != 9 || y.size() != 9)
			return false;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			set<int> s;
			for (int a = 0; a < 3; a++)
			{
				for (int b = 0; b < 3; b++)
					s.insert(arr[i * 3 + a][j * 3 + b]);
			}
			if (s.size() != 9)
				return false;
		}
	}
	return true;
}

bool check(int a, int b, int n)
{
	for (int i = 0; i < 9; i++)
	{
		if (i == a)
			continue;
		if (arr[i][b] == n)
			return false;
	}

	for (int i = 0; i < 9; i++)
	{
		if (i == b)
			continue;
		if (arr[a][i] == n)
			return false;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (3 * i <= a && a < 3 * i + 3 && 3 * j <= b && b < 3 * j + 3)
			{
				for (int p = 0; p < 3; p++)
				{
					for (int q = 0; q < 3; q++)
					{
						if (a == i * 3 + p && b == j * 3 + q)
							continue;
						if (arr[i * 3 + p][j * 3 + q] == n)
							return false;
					}
				}
			}
		}
	}
	return true;
}

void dfs(int index)
{
	if (index == v.size())
	{
		if (isEnd())
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					cout << arr[i][j] << " ";
				cout << "\n";
			}
			exit(0);
		}
		return;
	}
	for (int i = 1; i < 10; i++)
	{
		arr[v[index].first][v[index].second] = i;
		if (check(v[index].first, v[index].second, i))
			dfs(index + 1);
		arr[v[index].first][v[index].second] = 0;
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];
			if (!arr[i][j])
				v.push_back({ i, j });
		}
	}

	dfs(0);

	return 0;
}
