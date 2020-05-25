/**
*	BOJ
*	No.2921	µµ¹Ì³ë
*	@author	peter9378
*	@date		2020.05.24
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
#include <iterator>
#include <numeric>
using namespace std;

int arr[101];
int concent[101];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < K; i++)
		cin >> arr[i];

	int result = 0;
	for (int i = 0; i < K; i++)
	{
		bool flag = false;

		for (int j = 0; j < N; j++)
		{
			if (concent[j] == arr[i])
			{
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		for (int j = 0; j < N; j++)
		{
			if (!concent[j])
			{
				concent[j] = arr[i];
				flag = true;
				break;
			}
		}

		if (flag)
			continue;

		int target, index = -1;
		for (int j = 0; j < N; j++)
		{
			int last = 0;
			for (int k = i + 1; k < K; k++)
			{
				if (concent[j] == arr[k])
					break;
				last++;
			}

			if (last > index)
			{
				target = j;
				index = last;
			}
		}
		result++;
		concent[target] = arr[i];
	}

	cout << result;

	return 0;
}