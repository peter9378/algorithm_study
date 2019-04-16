/**
*	baekjoon online judge
*	No. 2748	피보나치 수 2
*	@author	peter9378
*	@date		2019.04.16
*/
#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100];

// main function
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// input data
	int n;
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[n];

	return 0;
}