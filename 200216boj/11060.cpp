/**
*	BOJ
*	No.11060	점프 점프
*	@author	peter9378
*	@date		2020.02.16
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

int arr[1111];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	arr[1] = 1;
	for (int i = 1; i <= N; i++)
	{
		int a;
		cin >> a;

		if (!arr[i])
			break;

		for (int j = 1; j <= a; j++)
		{
			if (i + j > 1000)
				break;
			if (arr[i + j] > arr[i] + 1 || !arr[i + j])
				arr[i + j] = arr[i] + 1;
		}
	}

	if (arr[N])
		cout << arr[N] - 1;
	else
		cout << -1;

	return 0;
}
