/**
*	BOJ
*	No.2475	검증수
*	@author	peter9378
*	@date		2019.09.17
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// main
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[5];
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	cout << (arr[0] * arr[0] + arr[1] * arr[1] + arr[2] * arr[2] + arr[3] * arr[3] + arr[4] * arr[4]) % 10;

	return 0;
}