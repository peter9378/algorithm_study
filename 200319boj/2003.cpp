/**
*	BOJ
*	No.2003	수들의 합 2
*	@author	peter9378
*	@date		2020.03.19
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

int arr[10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int left = 0, right = 0, answer = 0, sum = arr[0];
	while (left <= right && right < N)
	{
		if (sum < M)
			sum += arr[++right];
		else if (sum == M)
		{
			sum += arr[++right];
			answer++;
		}
		else
		{
			sum -= arr[left++];

			if (left > right && left < N)
			{
				right = left;
				sum = arr[left];
			}
		}
	}

	cout << answer;

	return 0;
}