/**
*	BOJ
*	No.1309	동물원
*	@author	peter9378
*	@date		2019.08.16
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	arr[0] = 1;
	arr[1] = 3;
	for (int i = 2; i < 100001; i++)
		arr[i] = (2 * arr[i - 1] + arr[i - 2])%9901;

	int N;
	cin >> N;
	cout << arr[N];

	return 0;
}