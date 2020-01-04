/**
*	BOJ
*	No.1300	K¹øÂ° ¼ö
*	@author	peter9378
*	@date		2020.01.04
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

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	int left = 1, right = K, answer = -1;
	while (left <= right)
	{
		int temp = 0, mid = left + (right - left) / 2;
		for (int i = 1; i <= N; i++)
			temp += min(mid / i, N);

		if (temp < K)
			left = mid + 1;
		else
		{
			answer = mid;
			right = mid - 1;
		}
	}

	cout << answer;

	return 0;
}
