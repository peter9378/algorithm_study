/**
*	BOJ
*	No.2903	중앙 이동 알고리즘
*	@author	peter9378
*	@date		2019.08.17
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[16];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	arr[0] = 2;
	arr[1] = 3;

	for (int i = 2; i < 16; i++)
		arr[i] = 2 * arr[i - 1] - 1;
	
	int N;
	cin >> N;
	cout << arr[N] * arr[N];

	return 0;
}