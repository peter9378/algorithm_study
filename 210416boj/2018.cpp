/**
*	BOJ
*	No.2018	수들의 합 5
*	@author	peter9378
*	@date		2021.04.16
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
#include <unordered_map>
#include <cstring>
#include <iterator>
#include <numeric>
#include <complex>
using namespace std;

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int left = 1, right = 1, sum = 0, answer = 0;
	while (left <= right && right <= N + 1)
	{
		if (N < sum)
			sum -= left++;
		else if (sum < N)
			sum += right++;
		else
		{
			answer++;
			sum += right++;
		}
	}

	cout << answer;

	return 0;
}
