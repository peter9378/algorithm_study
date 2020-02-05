/**
*	BOJ
*	No.10830	Çà·Ä Á¦°ö
*	@author	peter9378
*	@date		2020.02.05
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

int arr[55][6][6];
int temp[6][6];
int id[6][6];
bool visit[55];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	long long B;
	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[0][i][j];
	}

	int power = 0;
	while (B > 1)
	{
		if (B % 2)
			visit[power] = true;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				temp[i][j] = 0;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					temp[i][j] += arr[power][i][k] * arr[power][k][j];
					temp[i][j] %= 1000;
				}
			}
		}

		power++;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				arr[power][i][j] = temp[i][j];
		}

		B /= 2;
	}

	visit[power] = true;

	for (int i = 0; i < N; i++)
		id[i][i] = 1;

	for (int p = 0; p <= power; p++)
	{
		if (visit[p])
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					temp[i][j] = 0;
			}

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					for (int k = 0; k < N; k++)
					{
						temp[i][j] += id[i][k] * arr[p][k][j];
						temp[i][j] %= 1000;
					}
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					id[i][j] = temp[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << id[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
