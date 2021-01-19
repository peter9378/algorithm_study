/**
*	BOJ
*	No.2670	연속부분최대곱
*	@author	peter9378
*	@date		2021.01.19
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

double arr[10001];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	double answer = -1;
	for (int i = 0; i < N; i++)
	{
		double temp = 1;
		for (int j = i; j < N; j++)
		{
			temp *= arr[j];
			answer = max(answer, temp);
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << answer;

	return 0;
}
