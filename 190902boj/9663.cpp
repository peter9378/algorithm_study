/**
*	BOJ
*	No.9663	N-Queen
*	@author	peter9378
*	@date		2019.09.02
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, answer;
int arr[15];

bool isPromise(int index)
{
	int temp = 1;
	bool flag = true;

	while (temp < index && flag)
	{
		if (arr[index] == arr[temp] || abs(arr[index] - arr[temp]) == index - temp)
			flag = false;
		temp++;
	}
	return flag;
}

void dfs(int index)
{
	if (isPromise(index))
	{
		if (index == N)
			answer++;
		else
		{
			for (int i = 1; i <= N; i++)
			{
				arr[index + 1] = i;
				dfs(index + 1);
			}
		}
	}
}

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	dfs(0);
	cout << answer;

	return 0;
}