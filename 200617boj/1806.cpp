/**
*	BOJ
*	No.1806	ºÎºÐÇÕ
*	@author	peter9378
*	@date		2020.06.17
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

int arr[1000001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int left = 0, right = 0, sum = arr[0], answer = N + 1;
	while (left <= right && right < N)
	{
		if (sum < S)
			sum += arr[++right];
		else if (sum == S)
		{
			answer = min(answer, right - left + 1);
			sum += arr[++right];
		}
		else
		{
			answer = min(answer, right - left + 1);
			sum -= arr[left++];
		}
	}

	cout << (answer == (N + 1) ? 0 : answer);

	return 0;
}
