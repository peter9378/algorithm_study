/**
*	BOJ
*	No.1689	°ãÄ¡´Â ¼±ºÐ
*	@author	peter9378
*	@date		2021.08.30
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

pair<int, int> arr[2000002];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		arr[i] = { a, 1 };
		arr[i + N] = { b, -1 };
	}

	sort(arr, arr + 2 * N);

	int temp = 0;
	int answer = 0;
	for (int i = 0; i < 2 * N; i++)
	{
		temp += arr[i].second;
		answer = max(answer, temp);
	}

	cout << answer;

	return 0;
}