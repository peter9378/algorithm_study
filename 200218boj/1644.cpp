/**
*	BOJ
*	No.1644	소수의 연속합
*	@author	peter9378
*	@date		2020.02.18
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

bool arr[4444444];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++)
		arr[i] = true;

	for (int i = 2; i * i <= N; i++)
	{
		if (arr[i])
		{
			for (int j = i * i; j <= N; j += i)
				arr[j] = false;
		}
	}

	vector<int> v;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i])
			v.push_back(i);
	}

	int answer = 0;
	int left = 0, right = 0, mid = 0;
	while (true)
	{
		if (mid > N)
			mid -= v[left++];
		else if (right == v.size())
			break;
		else
			mid += v[right++];

		if (mid == N)
			answer++;
	}

	cout << answer;

	return 0;
}
