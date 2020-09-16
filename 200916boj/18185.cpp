/**
*	BOJ
*	No.18185	라면 사기 (Small)
*	@author	peter9378
*	@date		2020.09.16
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
using namespace std;

int arr[10101];

// main funcntion
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int answer = 0;

	for (int i = 0; i < N; i++)
	{
		if (arr[i + 1] > arr[i + 2])
		{
			int temp = min(arr[i], arr[i + 1] - arr[i + 2]);
			answer += 5 * temp;
			arr[i] -= temp;
			arr[i + 1] -= temp;

			temp = min(arr[i], min(arr[i + 1], arr[i + 2]));
			answer += 7 * temp;
			arr[i] -= temp;
			arr[i + 1] -= temp;
			arr[i + 2] -= temp;
		}
		else
		{
			int temp = min(arr[i], min(arr[i + 1], arr[i + 2]));
			answer += 7 * temp;
			arr[i] -= temp;
			arr[i + 1] -= temp;
			arr[i + 2] -= temp;

			temp = min(arr[i], arr[i + 1]);
			answer += 5 * temp;
			arr[i] -= temp;
			arr[i + 1] -= temp;
		}

		answer += 3 * arr[i];
	}

	cout << answer;

	return 0;
}